// Server C Program
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
// include for signals
#include <signal.h>
// include for sockets
#include <sys/socket.h>

typedef struct
{
	char* phrase;
	char* hint;
} pair;

// methods to use throughout server.c program
int fillPairArray(pair*[]);

const int SIZE = 1024;

void ctrlc();

int main(int args, char* argv[]){

	int totalElements = 0;
	pair* phPair[SIZE];

	int nullCt = 0;
	while(nullCt < SIZE){
		phPair[nullCt] = NULL;
		++nullCt;
	}

	totalElements = fillPairArray(phPair);

	int s, s2;
	struct sigaction news;
	struct sigaction olds;

	void ctrlc(){
		sigaction(SIGINT, &olds, NULL);
		// freeing the array of phrase/hint pairings
		int freeCt = 0;
		while(freeCt < totalElements){
			pair* currentPair = phPair[freeCt];
			//free(currentPair->phrase);
			//free(currentPair->hint);
			free(currentPair);
			currentPair = NULL;
			phPair[freeCt] = NULL;
			++freeCt;
		}
		close(s2);
		close(s);
		unlink("GameServer");
		//sigaction(SIGINT, &olds, NULL);	// restore on exit
	}

	news.sa_handler = ctrlc;
	news.sa_flags = 0;

	int signalRet = sigaction(SIGINT, &news, &olds);
	if(signalRet == -1){
		printf("\nsigaction() error\n");
		return -1;
	}

	struct sockaddr name = {AF_UNIX, "GameServer"};

	socklen_t namelens = sizeof(struct sockaddr) + 11;

	s = socket(AF_UNIX, SOCK_STREAM, 0);
	if(s == -1){
		printf("\nsocket() failed\n");
		return -1;
	}

	if( (bind(s, &name, namelens)) == -1){
		printf("\nbind() failed\n");
		return -1;
	}

	if( listen(s,1) == -1){
		printf("\nlisten() failed\n");
		return -1;
	}

	while(1){
	s2 = accept(s, NULL, NULL);
	if(s2 == -1){
		printf("\naccept() failed\n");
		return -1;
	}else{
		//send phrase and hint to the client
		int r;
		r = random() % totalElements;

		pair* pulled = phPair[r];
		char* toSend = "";
		char* pulledPhrase = pulled->phrase;
		char* pulledHint = pulled->hint;
		pulledPhrase = strcat(pulledPhrase, ":");
		pulledPhrase = strcat(pulledPhrase, pulledHint);
		int toSendLen = strlen(pulledPhrase);
		toSendLen = toSendLen - 1;	// to get rid of space /n at end of the string

		write(s2, pulledPhrase, toSendLen);
		close(s2);
	}
	}
	return 0;
}

// function to read text file of phrases and hints into the pair structure array
int fillPairArray(pair* pairArray[]){
	int total = 0;
	FILE* fin;
	fin = fopen("wordList.txt", "r");
	int arrayPairCt = 0;
	if(fin == NULL){	// error
		printf("\nError while trying to open the wordList.txt file\n");
		exit(1);
	}else{	// opened wordList.txt successfully
		const int MSIZE = 1025;	// size of a single line of 1 phrase and 1 hint to be read in
		char str[MSIZE];

		int i_tok = 0;
		char* tokenized_Elements[2];
		char* token;

		fgets(str, MSIZE, fin);
		while( !feof(fin) ){
			token = strtok(str, ":");
			while(token != NULL){
				tokenized_Elements[i_tok] = token;
				++i_tok;
				token = strtok(NULL, ":");
			}

			// creation of a new pair struct
			pair* new_pair;
			new_pair = (pair*)malloc(sizeof(pair));
			new_pair->phrase = strdup(tokenized_Elements[0]);
			new_pair->hint = strdup(tokenized_Elements[1]);
			pairArray[arrayPairCt] = new_pair;
			++arrayPairCt;
			fgets(str, MSIZE, fin);
			i_tok = 0;
			++total;
		}	//end of !feof while loop
		fclose(fin);
	}
	return total;
}
