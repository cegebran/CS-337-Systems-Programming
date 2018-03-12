#define NUM_DIGITS 10 // number of unique "digit" characters

typedef unsigned char byte; // may be useful for casting(s)

void init_histogram(int histo[]);  // set all the elements of the histogram to zero
void cons_histogram(const char string[], int histo[]);  // construct the histogram from string
void most_frequent(const int histo[], char* ret_val);  // set *ret_val to a least occuring digit character - hence returning it
void display_histogram(char* const histo);	// display the histogram sparsely
