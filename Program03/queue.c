#include<stdlib.h>
#include<stdio.h>
#include "queue.h"

// create an empty queue with an initial capacity of one
float* create_empty(int* capacity, int* tail)
{
	// initialize capacity to 1
	*capacity = 1;

	// initialize tail to 0
	*tail = 0;

	// create empty array with 1 index and alloce space on the stack
	return (float*)malloc(sizeof(float)*1);

}

// add (que) an item to the queue
void add(float* queue, int* capacity, int* tail, float* que)
{
	// adding the value to the queue array
	queue[*tail] = *que;

	// testing to see if after adding the element if the queue is full and needs to be doubled in size
	if(test_full(capacity, tail)){
		// calling the grow_twice funciton to double the size of the queue
		grow_twice(queue, capacity);
	}

	// increment the tail pointer to be set to add another element
	int prevTail = *tail;
	int tailNew = prevTail + 1;
	// set the tail pointer as the new value that was incremented
	*tail = tailNew;

}

// test to see if the queue is full  at capactiy
int test_full(int* capacity, int* tail)
{

	int cap;
	cap = *capacity - 1;

	int tailValue;
	tailValue = *tail;

	if(cap == tailValue){
		return 1;
	}else{
		return 0;
	}

}

// grow the capacity of the queue to twice its current capacity
void grow_twice(float* queue, int* capacity)
{

	int prevCapacity = *capacity;

	// create temp Queue to hold old element to be placed back in
	float prevQueue[*capacity];

	int i;
	for(i = 0; i < *capacity; ++i){
		prevQueue[i] = queue[i];
	}

	int capacityNew = prevCapacity * 2;
	queue = (float*)malloc(sizeof(float) * capacityNew);

	for(i = 0; i < *capacity; ++i){
		queue[i] = prevQueue[i];
	}

	*capacity = capacityNew;

}

// test to see if the queue is empty
int test_empty(int* tail)
{

	int tailVal = *tail;

	if(tailVal == 0){
		return 1;
	}else{
		return 0;
	}


}

// remove/return (deque) an item from the queue
float remove_deq(float* queue, int* tail, int* capacity)
{

	// check to ensure there is something to remove from the queue
	if(!(test_empty(tail))){

		int i;

		float value = queue[0];

		// shift entire array over
		for(i = 0; i < *tail; i++){
			queue[i] = queue[i + 1];
		}

		// decrement tail
		*tail = *tail - 1;

		// decrease queue size if less than half full (never can be less than half full)
		if(test_halfFull(capacity, tail)){
			shrink(queue, capacity);
		}

		// return the value that was dequeued
		return value;
	}else{
		return 0.0;
	}


}

// test to see if the queue is less than half full
int test_halfFull(int* capacity, int* tail)
{

	double testHalfValue;
	testHalfValue = (double)*capacity / 2; // check casting if not working

	double tailVal = (double)*tail;

	if(tailVal < testHalfValue){
		return 1;
	}else{
		return 0;
	}
}

// shrink the capacity of the queue to half its current capacity
void shrink(float* queue, int* capacity)
{
	int prevCapacity = *capacity;

	// create temp queue to hold old elements to be placed back in once queue is shinked
	float prevQueue[*capacity];

	int i;
	for(i = 0; i < *capacity; ++i){
		prevQueue[i] = queue[i];
	}

	int capacityNew = prevCapacity / 2;

	queue = (float*)malloc(sizeof(float) * capacityNew);

	for(i = 0; i < capacityNew; ++i){
		queue[i] = prevQueue[i];
	}

	*capacity = capacityNew;
}
