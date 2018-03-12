#include <stdlib.h>
#include <stdio.h>

#include <fcntl.h>
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

// methods
int create(char*, char*);
void createRecursive(char*, char*);
void explode(char*, char*);

int main(int args, char* argv[])
{

	char* argumentMode = NULL;
	char* argumentPath = NULL;
	char* argumentFile = NULL;
	if(args == 4){
		// argument assignment
		argumentMode = argv[1];
		argumentPath = argv[2];
		argumentFile = argv[3];
	}else{
		printf("No arguments added or not added correctly\n");
		exit(1);
	}

	char mode[3];
	strcpy(mode, argumentMode);

	char c[2];
	strcpy(c, "-c");

	char cr[3];
	strcpy(cr, "-cr");

	char e[2];
	strcpy(e, "-e");

	if(strcmp(mode, c)  == 0){
		create(argumentPath, argumentFile);
	}

	if(strcmp(mode, cr) == 0){
		createRecursive(argumentPath, argumentFile);
	}

	if(strcmp(mode, e) == 0){
		explode(argumentPath, argumentFile);
	}



return 0;
}

int create(char* path, char* file){

	printf("\narchiving %s", path);

	const int BIG_BUFFER_SIZE = 1024 * 16;
	char big_buffer[BIG_BUFFER_SIZE];
	int i;
	for(i = 0; i < BIG_BUFFER_SIZE; ++i){
		big_buffer[i] = i % 256;
	}

	// 644 to read and write
	mode_t filem = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

	int filep = open(file, O_WRONLY | O_CREAT, filem);

	if(filep == -1){
		printf("\nUnable to open %s\n", file);
	}else{

		size_t sizeFile = 0;

		struct stat buffer;
		if(stat(filep, &buffer) != 0){
			sizeFile = 0;
		}else{
			sizeFile = buffer.st_size;
		}

		int nameLength = strlen(path);

		char name[50];

		strcpy(name, path);

		big_buffer[0] = nameLength;

		int i = 0;
		while(i < nameLength){
			big_buffer[i+1] = name[i];
			i++;
		}

		big_buffer[nameLength + 2] = filem;

		big_buffer[nameLength + 3] = sizeFile;

		chmod("raw", filem);

		const int BLOCK_SIZE = 1024;
		size_t total_bytes_out = 0;
		size_t bytes_out;

		while(total_bytes_out < nameLength + 3 + sizeFile){
			bytes_out = write(filep, big_buffer + total_bytes_out, BLOCK_SIZE);
			total_bytes_out += bytes_out;
		}

		close(filep);
		printf("\nDone - %s", file);
		printf(" has been created\n");
	}

	return 2;
}

void createRecursive(char* path, char* file){
	while(create(path, file) == 2){
		printf("\narchiving %s", path);
		break;
	}

	printf("\nDone - %s", file);
	printf(" has been created\n");
}

void explode(char* path, char* file){

	const int BIG_BUFFER_SIZE = 1024 * 16;
	char big_buffer[BIG_BUFFER_SIZE];

	mode_t filem = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

	int filep = open(file, O_WRONLY | O_CREAT, filem);

	if(filep == -1){
		printf("\nraw file could not be opened\n");
		exit(1);
	}else{

		chmod(file, filem);

		const int BLOCK_SIZE = 1024;

		size_t total_bytes_in = 0;
		size_t bytes_in;

		//struct stat buffer;

		//if(S_IFREG(buffer.st_mode)){
		while(total_bytes_in < BIG_BUFFER_SIZE){
			bytes_in = read(filep, big_buffer + total_bytes_in, BLOCK_SIZE);
			total_bytes_in += bytes_in;
		}

		close(filep);
		printf("\nexploding to ");
		printf("%s", path);
		printf(" \n");
		printf("Done - %s", file);
		printf(" has been exploeded\n");
	}

}
