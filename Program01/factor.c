#include <stdio.h>

int factor_power(int n, int d, int p);
int main(){

int num;

int acceptableEntry;
acceptableEntry = 1;


while(acceptableEntry  == 1){
	printf("%s", "Enter an integer (> 1): ");
	scanf("%d", &num);

	if(num < 2){
		acceptableEntry = 1;
	}

	if(num > 1){
		printf("%d", num);
		printf("%s", " = ");

		// The remaining amount of the number to divide up into factors
		int numRemaining;
		numRemaining = num;

		// The counting variable for d
		int count;
		count = 2;

		// variable to return the p value to
		int returned;
		returned = 0;

		// variable to keep track of number currently multiplied together
		int curNumber;
		curNumber = 1;

		// variable to check to ensure a multiplication sign is needed
		int multSign = 1;
		// set to 1 stating it is the first factor and a sign in front is not needed

		// while loop to loop until whole number is factored
		while(numRemaining > 0){

			int numCk;
			numCk = curNumber * count;

			if((num  % count) == 0 ){
				if((num % numCk) == 0){
					// only print the multiplication logo if a factor is going to follow and do not print one before a faotor is printed
					if(multSign != 1){
						printf("%s", " * ");
					}

					returned  = factor_power(num, count, returned);

					printf("%d", count);
					printf("%s", "^");
					printf("%d", returned);

					// variable to keep track of number to take off total to be factored
					int mult;
					mult = 1;

					// counting variable for for loop
					int k;
					for(k = 0; k < returned; k++){
						mult = mult * count;
					}

					curNumber = curNumber * mult;

					numRemaining =  num  - curNumber;
					multSign = 0;	// stating that a mult sign is needed for each factor following the first one
				}
			}
			count++;
		}
	printf("%s\n", " ");
	acceptableEntry = 0;
	}
}

return 0;
}


//factor_power function which takes two integer parameters (n,d) and return the unique
//non-negative integer (p) such that d raised to the p power divided n but d raised to
// the (p+1) power does not divid n
int factor_power(int n, int d, int p){

	p = 0;
	int divisor;
	divisor = d;

	while((n % divisor) == 0){
		p++;

		divisor = divisor * d;
	}


	return p;
}
