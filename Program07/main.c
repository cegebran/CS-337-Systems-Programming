#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
int main(int args, char* argv[])
{
	printf("\nWelcome to myShell\n");
	size_t size = 100;
	char buf[100] = "";
	char tempBuf[100];
	char* argv1[20];
	int cnt = 0;
	int compareVal;

	// forking variables to be used for each loop of different command line inputs by the user
	pid_t childpid;	// child's pid
	int status;	// child's exit status
	int execvpReturn;

	// Opening and reading multi file variables
	FILE* fin;
	char buffer[1025];
	char tBuffer[1025];
	int clearCT;
	int parseCt;

	do{
	getcwd(buf, size);
	printf(buf);
	printf(" ? ");
	fgets(buf, 100, stdin);
	strcpy(tempBuf, buf);
	printf("\n");

	argv1[0] = strtok(tempBuf, " \t\n");
	cnt = 1;
	while((argv1[cnt] = strtok(NULL, " \n\n")) != NULL){
		cnt++;
	}
	if(strcmp(argv1[0], "exit") != 0){

		compareVal = strcmp(argv1[0], "multi");

		if(compareVal == 0){
			// multi instead of singe command
			// clear the buffer array for a new multi set

			clearCT = 0;
			while(clearCT < 1025){
				buffer[clearCT] = '\0';
				++clearCT;
			}

			fin = fopen(argv1[1], "r");
			if(fin == NULL){
				printf("\ncound not open the file\n");
				exit(1);
			}else{
				parseCt = 0;
				while( !feof(fin) ){
					if((fgets(buffer, 1025, fin)) != NULL){	//reading characters from the txt file
						printf("%s", getcwd(buf, size));
						printf(" ? ");
						printf("%s", buffer);
						strcpy(tBuffer, buffer);

						argv1[0] = strtok(tBuffer, " \t\n");
						parseCt = 1;
						while((argv1[parseCt] = strtok(NULL, " \n\n")) != NULL){
							parseCt++;
						}
						childpid = fork();

						if( childpid >= 0){
							if(childpid == 0){
								execvpReturn = execvp(argv1[0], argv1);
								if(execvpReturn == -1){
									perror(argv1[0]);
									exit(errno);
								}
							}else{
								wait(&status);
							}
						}else{
							perror("The fork() failed");
							exit(0);
						}
					}
					printf("\n");
				}
			}
			fclose(fin);

		}else{
			// fork a child process
			childpid = fork();	// create the child process that will not return

			if( childpid >= 0){	// successful fork
				if(childpid == 0){	// fork() returns 0 to the child process
					execvpReturn = execvp(argv1[0], argv1);
					if(execvpReturn == -1){
						perror(argv1[0]);
						exit(errno);
					}
				}else{	// fork() returns new pid to the parent process
					wait(&status);
				}

			}else{	// fork faliure
				perror("The fork() failed");
				exit(0);
			}
		}
	}
	}while (strcmp(argv1[0], "exit") != 0);
	printf("\nmyShell out\n");

	printf("\n");
	return 0;
}
