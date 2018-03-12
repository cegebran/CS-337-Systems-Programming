#include<stdlib.h>
#include<stdio.h>
#include "queue.h"

int main(int args, char* argv[])
{
	// initialize seperate data items
	int capacity = 0;
	int tail = 0;
	float* queue;

	// create new empy queue with 0 elements, tail = 0, and capacity = 1
	queue = create_empty(&capacity, &tail);

	printf("\n");

	// test to make sure test_empty works with a empty queue
	printf("Test to ensure testing the queue's empty test works with a empty queue");
	printf("\n");
	if(test_empty(&tail) == 1){
		printf("Yes the test passed");
		printf("\n");
	}else{
		printf("No the test failed");
		printf("\n");
	}

	printf("\n");

	printf("\n");

	printf("Adding 10 float elements to the array:");
	printf("\n");
	printf("\n");
	float k = 0.1;

	int i;
	for(i = 1; i < 11; ++i){	// add 10 values to the queue

		// create the value to be enterned into the queue
		float fi = (float)i;
		float total = fi + k;
		// add the element to the queue
		add(queue, &capacity, &tail, &total);

		//print capacity to screen to show the method for doubling the queue size works correctly
		printf("Element Value Added: ");
		printf("%f", total);
		printf("  Current Capacity: ");
		printf("%d", capacity);
		printf("  Number of Elements:  ");
		printf("%d", tail);
		printf("\n");
		printf("\n");


		// increment k by itself to put interseting float values into the queue
		k = k + k;
	}

	// Print the queue to the screen to show that the add method works correctly which also implements the method double queue size

	printf("Print the Queue to the screen from the queue array: ");
	printf("\n");
	for(i = 0; i < tail; ++i){
		printf("[");
		printf("%d", i);
		printf("]:  ");
		float val = queue[i];	// set the value to be printed as the next element in the queue
		printf("%f\n", val);
	}

	// Testing the remove function
	printf("\n");
	printf("Testing to ensure the remove/dequeue function works correctly");
	printf("\n");
	printf("Will dequeue one element from the array at a time and print the queue's contents to show it has been removed");
	printf("\n");
	int d;
	for(d = 0; d < tail; i++){

		float value = remove_deq(queue, &tail, &capacity);
		printf("The value dequeued: ");
		printf("%f\n",value);
		for(i = 0; i < tail; ++i){
			float val = queue[i];
			printf("%f\n", val);
		}

		printf("Number of Elements: ");
		printf("%d", tail);
		printf("  Capacity of the Queue: ");
		printf("%d", capacity);
		printf("\n");
		printf("\n");
	}

	return 0;
}
