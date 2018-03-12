#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

// contact struct
typedef struct
{
	char* name;
	int cell;
	char* email;
} contact;

// 4 methods to implement
void create_Binary_File(contact*[]);
void array_Free(contact*[]);
void print_report();
void read_Create(contact*[]);

const int SIZE = 1024;

int main(int args, char* argv[])
{
	contact* contacts[SIZE];
	read_Create(contacts);
	create_Binary_File(contacts);
	print_report();
	array_Free(contacts);
	return 0;
}

void read_Create(contact* contact_Array[])
{
	FILE* fin;
	fin = fopen("contactDir.txt", "r");
	int arrayContactCount = 0;
	if(fin == NULL)
	{
		printf("\ncontactDir.txt could not be opened\n");
		exit(1);
	}else{
		const int MSIZE = 1025;
		char str[MSIZE];

		fgets(str, MSIZE, fin);

		int i_tok = 0;
		char* tokenized_Elements[3];
		char* token;
		int phone = 0;
		while( !feof(fin) )
		{
			token = strtok(str, "$");
			while(token != NULL){
				tokenized_Elements[i_tok] = token;
				++i_tok;
				token = strtok(NULL, "$");
			}

			contact* new_Contact;
			new_Contact = (contact*)malloc(sizeof(contact));
			new_Contact->name = strdup(tokenized_Elements[0]);
			phone = atoi(tokenized_Elements[1]);
			new_Contact->cell = phone;
			new_Contact->email = strdup(tokenized_Elements[2]);
			contact_Array[arrayContactCount] = new_Contact;
			++arrayContactCount;
			fgets(str, MSIZE, fin);
			i_tok = 0;
			phone = 0;
		}
		fclose(fin);
	}
}

void create_Binary_File(contact* contact_Array[]){

	FILE* binaryOut;
	binaryOut = fopen("binaryFile.txt", "w");
	if(binaryOut == NULL){
		printf("\nBinaryFile.txt could not be opened\n");
		exit(1);
	}else{

		int index = 0;

		// Variables
		contact* currentContact = NULL;
		char* contactName = NULL;
		int contactCell = 0;
		char* contactEmail = NULL;
		int nameSize = 0;
		int emailSize = 0;
		int nameSizeArray[1];
		int emailSizeArray[1];
		int cellArray[1];
		char name[50];
		char email[50];

		while(contact_Array[index] != NULL){

			currentContact = contact_Array[index];
			contactName = currentContact->name;
			contactCell = currentContact->cell;
			contactEmail = currentContact->email;

			nameSize = strlen(contactName);
			emailSize = strlen(contactEmail);

			nameSizeArray[0] =  nameSize;
			cellArray[0] = contactCell;
			emailSizeArray[0] = emailSize;

			strcpy(name, contactName);
			strcpy(email, contactEmail);

			// size of name
			if( fwrite(nameSizeArray, sizeof(int), 1,  binaryOut) == 0){
				printf("\nCould not write an integer to binaryOut.txt\n");
				exit(1);
			}

			// name
			if( fwrite(name, sizeof(char), nameSizeArray[0], binaryOut) == 0){
				printf("\nCould not write the name to binaryOut.txt\n");
				exit(1);
			}
			// cell number
			if( fwrite(cellArray, sizeof(int), 1, binaryOut) == 0){
				printf("\nCould not write the cell phone number binaryOut.txt\n");
				exit(1);
			}

			// size of email
			if( fwrite(emailSizeArray, sizeof(int), 1, binaryOut) == 0){
				printf("\nCould not write an integer to binaryOut.txt\n");
				exit(1);
			}

			// email
			if( fwrite(email, sizeof(char), emailSizeArray[0], binaryOut) == 0){
				printf("\nCould not write the email to binaryOut.txt\n");
				exit(1);
			}
			++index;
		}
		fclose(binaryOut);
	}

}

void print_report(){

	printf("\n                             ADDRESS BOOK                    \n");
	printf("----------------------------------------------------------------------\n");
	printf("NAME                     CELL NUMBER                  EMAIL          \n");

	FILE* inFile;

	inFile = fopen("binaryFile.txt", "r");
	if(inFile == NULL){
		printf("\ninFile.txt could not be opened\n");
		exit(1);
	}else{
		int nameSize[1];
		int emailSizeArray[1];
		int cellArray[1];
		char name[100];
		char email[100];

		int numNameCellSpace = 25;

		while(fread(nameSize, sizeof(int), 1, inFile) != 0){

			if( fread(name, sizeof(char), nameSize[0], inFile) == 0){
				printf("\nCould not read the name from binaryFile.txt\n");
				exit(1);
			}


			if( fread(cellArray, sizeof(int), 1, inFile) == 0){
				printf("\nCould not read the cell number from binaryFile.txt\n");
				exit(1);
			}

			if( fread(emailSizeArray, sizeof(int), 1, inFile) == 0){
				printf("\nCould not read the size of the email from binaryFile.txt\n");
				exit(1);
			}

			if( fread(email, sizeof(char), emailSizeArray[0], inFile) == 0){
				printf("\nCould not read the email from binaryFile.txt\n");
				exit(1);
			}

			numNameCellSpace = numNameCellSpace - nameSize[0];

			int i = 0;
			while(i < nameSize[0]){
				printf("%c", name[i]);
				++i;
			}

			int z = 0;
			while(z < numNameCellSpace){
				printf(" ");
				++z;
			}

			printf("%d", cellArray[0]);

			printf("                      ");
			int k = 0;
			while(k < emailSizeArray[0]){
				printf("%c", email[k]);
				++k;
			}
			numNameCellSpace = 25;
		} // while loop close
		fclose(inFile);
	}

}

void array_Free(contact* contact_Array[]){

	int counter = 0;
	while(contact_Array[counter] != NULL){
		contact* arrayContact = contact_Array[counter];	//retrieving contact pointer from array of contact pointers

		// free name and email first before freeing the contact inself to not lose pointers
		free(arrayContact->name);
		free(arrayContact->email);
		free(arrayContact);
		arrayContact = NULL;
		contact_Array[counter] = NULL;
		++counter;
	}

}
