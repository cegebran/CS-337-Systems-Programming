#include<stdlib.h>
#include<stdio.h>
#include "histo.h"

// set all elements of the histogram to zero
void init_histogram(int histo[])
{
	int i;
	for(i = 0; i < NUM_DIGITS; ++i){
		histo[i] = 0;
	}

}


// construct the histogram from string
void cons_histogram(const char string[], int histo[])
{
	int i;
	int equals = 0;
	for(i = 0; i < 255; ++i){
		char c = string[i];
		if(c == '='){		// the first non whole element in the array after inputed information
			equals = 1;
		}
		if((string[i] >= '0') && (string[i] <= '9') && (equals == 0)){
			int val_int;
			val_int = (byte)(c - '0');
			int val_in_cur = histo[val_int];
			int new_val_cur = val_in_cur + 1;
			histo[val_int] = new_val_cur;
		}

	}
}


// set *ret_val to a most occurring digit character - hence returning it
void most_frequent(const int histo[], char* ret_val)
{
	char mostFreq;
	int mostFreqVal = 0;
	//int valueAdded = 0;
	int i;
	for(i = 0; i < NUM_DIGITS; ++i){
		if(histo[i] > mostFreqVal){
			mostFreqVal = histo[i];
			mostFreq = (char)(i + '0');
			//valueAdded = 1;
		}
		//if((histo[i] == mostFreqVal) && (valueAdded == 1)){
		//	char newMostFreq = (char)(i + '0');
		//	mostFreq = (mostFreq + newMostFreq);
		//	printf("%c",mostFreq);
		//	mostFreqVal = histo[i];
		//}
	}
	*ret_val = mostFreq;
}


// display the histogram sparsely
void display_histogram(char* const histo)
{

	int i;
	char ret_val;
	int intHisto[NUM_DIGITS];
	for(i = 0; i < NUM_DIGITS; ++i){

		char* address = histo + (sizeof(int) * i);

		int cur_val_int;

		cur_val_int = *address;

		int cur_val = (byte)(cur_val_int -  '0');

		intHisto[i] = cur_val;

		if(cur_val_int >=  1){

			printf("%d", i);
			printf(" appeared ");
			printf("%d", cur_val_int);

			if(cur_val_int >= 2){
				printf(" times");
			}else{
				printf(" time");
			}
			printf("\n");
		}
	}
	printf("\n");
	most_frequent(intHisto, &ret_val);
	printf("%c", ret_val);
	printf(" occurred most often");
	printf("\n");
}
