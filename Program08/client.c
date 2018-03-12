// Client C Program
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <dirent.h>
#include <signal.h>

void playGame(char[], int);

int main(int args, char* argv[])
{
	int s2;
	int s;
	struct sockaddr name = {AF_UNIX, "GameServer"};	// same in server

	socklen_t namelenC = sizeof(struct sockaddr) + 11;

	s2 = socket(AF_UNIX, SOCK_STREAM, 0);
	if(s2 == -1){
		printf("\nsocket() failed\n");
		return -1;
	}

	if( (connect(s2, &name, namelenC)) == -1){
		printf("\nconnect() error\n");
		return -1;
	}

	char buff[100];
	int size = 0;
	size =  read(s2, buff, 100);
	close(s2);
	playGame(buff, size);
	return 0;
}

void playGame(char bufferIn[], int size){
	// Play the Game
	// get the read in buffer to the phrase and hint char* to play game with the send pairing
	int lengthCheckCt = 0;
	int lengthCheckDone = 1;
	char characterCheck;
	while(lengthCheckDone > 0){
		characterCheck = bufferIn[lengthCheckCt];
		if(characterCheck == ':'){
			lengthCheckDone = 0;
		}
		++lengthCheckCt;
	}

	int phraseLen = lengthCheckCt - 1;
	char phraseA[phraseLen];

	int toPhraseACt = 0;
	while(toPhraseACt < phraseLen){
		phraseA[toPhraseACt] = bufferIn[toPhraseACt];
		toPhraseACt++;
	}


	printf("\n");
	printf("Hint: ");
	int hintPrintCt = phraseLen + 1;
	while(hintPrintCt < size){
		printf("%c", bufferIn[hintPrintCt]);
		++hintPrintCt;
	}

	printf("\n");

	printf("\nCommon Phrase\n");
	printf("-------------");
	printf("\n");

	int initialCounter = 0;
	while(initialCounter < phraseLen){
		if(phraseA[initialCounter] == ' '){
			printf(" ");
		}else{
			printf("?");
		}
		++initialCounter;
	}

	printf("\n");

	char solvedPhrase[phraseLen];
	int solvedPhraseCt = 0;
	while(solvedPhraseCt < phraseLen){
		if(phraseA[solvedPhraseCt] == ' '){
			solvedPhrase[solvedPhraseCt] = ' ';
		}else{
			solvedPhrase[solvedPhraseCt] = '?';
		}
		solvedPhraseCt++;
	}

	int solved = 0;	// solved is set to 0 until phrase is solved which then it will be set to 1
	char userInput;
	while(solved < 1){

		int reads = 0;
		int correctInput = 0;
		while(correctInput < 1){
			reads = 0;
			printf("\nEnter a single character guess : ");
			userInput = getchar();
			if(userInput != '\n'){
				while(getchar() != '\n'){
					reads++;
				}
				if(reads == 0){
					correctInput = 1;
				}
			}
		}// closing off of while loop until the correct input of 1 character has been entered

		// userInput is the guessed character at this point
		int checkMatchCt = 0;
		while(checkMatchCt < phraseLen){
			if(phraseA[checkMatchCt] == userInput){
				solvedPhrase[checkMatchCt] = userInput;
			}
			checkMatchCt++;
		}

		printf("Common Phrase\n");
		printf("--------------\n");

		int printNewCt = 0;
		while(printNewCt < phraseLen){
			printf("%c", solvedPhrase[printNewCt]);
			printNewCt++;
		}
		printf("\n");

		int compCheck = 0;
		int checkCompCt = 0;
		while(checkCompCt < phraseLen){
			if(solvedPhrase[checkCompCt] == '?'){
				compCheck = 1;
			}
			checkCompCt++;
		}

		if(compCheck == 0){
			solved = 1;
		}
	}	// closeing off of while loop until phrase solved and solved is set to 1
}
