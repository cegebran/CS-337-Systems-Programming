// driver
#include <iostream>
#include "dynQueue.h"

using namespace std;

int main()
{
	cout << endl;
	// Values to add to the queue throughout the driver
	int val1 = 1;
	int val2 = 2;
	int val3 = 3;
	int val4 = 4;
	int val5 = 5;
	int val6 = 6;
	int val7 = 7;
	int val8 = 8;
	int val9 = 9;

	cout << "The - in an array index denotes that the index does not contain a value at that location" << endl << endl;
	// constructor to create an integer queue
	dynQueue<int> queue1;

	// empty Queue
	cout << "The Queue is now empty" << endl;
	cout << "The current state of the Queue's data";
	cout << endl;
	cout << "Capacity: " << queue1.get_cap() << endl;
	cout << "Tail Ptr: " << queue1.get_tail() << endl;
	cout << "Print Queue: " << queue1 << endl << endl;

	// attempting to dequeue an item from the empty queue and this will result in nothing happening
	// and the current state of the Queue will not change when compared to what was printed about
	queue1 -= queue1;
	cout << "Attempting to remove 1 element from  the Queue to make the total elements in the Queue = 0" << endl;
	cout << "The current state of the Queue's data" << endl;
	cout << "Capacity: " <<  queue1.get_cap() << endl;
	cout << "Tail Ptr: " << queue1.get_tail() << endl;
	cout << "Print Queue: " << queue1 << endl << endl;

	// add a single element to the Queue so the array will have an item in the first index of the array
	queue1 += val9;
	cout << "Adding 1 element (value = 9) to the Queue to make the total elements in the Queue = 1" << endl;
	cout << "The current state of the Queue's data" << endl;
	cout << "Capacity: " <<  queue1.get_cap() << endl;
	cout << "Tail Ptr: " << queue1.get_tail() << endl;
	cout << "Print Queue: " << queue1 << endl << endl;

	// add another single element to the Queue so that queue will have 2 elements in it
	queue1 += val7;
	cout << "Adding 1 element (value = 7) to the Queue to make the total elements in the Queue = 2" << endl;
	cout << "The current state of the Queue's data" << endl;
	cout << "Capacity: " <<  queue1.get_cap() << endl;
	cout << "Tail Ptr: " << queue1.get_tail() << endl;
	cout << "Print Queue: " << queue1 << endl << endl;

	// add another single element to the Queue so that the queue will have 3 elements in it
	queue1 += val4;
	cout << "Adding 1 element (value = 4) to the Queue to make the total elements in the Queue = 3" << endl;
	cout << "The current state of the Queue's data" << endl;
	cout << "Capacity: " <<  queue1.get_cap() << endl;
	cout << "Tail Ptr: " << queue1.get_tail() << endl;
	cout << "Print Queue: " << queue1 << endl << endl;


	// add another single element to the Queue so that the queue will have 4 elements in it
	queue1 += val2;
	cout << "Adding 1 element (value = 2) to the Queue to make the total elements in the Queue = 4" << endl;
	cout << "The current state of the Queue's data" << endl;
	cout << "Capacity: " <<  queue1.get_cap() << endl;
	cout << "Tail Ptr: " << queue1.get_tail() << endl;
	cout << "Print Queue: " << queue1 << endl << endl;

	// remove 1 element from the queue and need to decrease the capacity after the removal of the elemet
	// due to the queue being less than half full after the dequeue
	queue1 -= queue1;
	cout << "Removing 1 element from  the Queue to make the total elements in the Queue = 3 and with the removal force the queue to shrink" << endl;
	cout << "The current state of the Queue's data" << endl;
	cout << "Capacity: " <<  queue1.get_cap() << endl;
	cout << "Tail Ptr: " << queue1.get_tail() << endl;
	cout << "Print Queue: " << queue1 << endl << endl;

	// remove 1 element from the queue and DO NOT need to decrease the capacity after the removal of the elemet
	// due to the queue being half full
	queue1 -= queue1;
	cout << "Removing 1 element from  the Queue to make the total elements in the Queue = 2 and with the removal no shrinking is necessary" << endl;
	cout << "The current state of the Queue's data" << endl;
	cout << "Capacity: " <<  queue1.get_cap() << endl;
	cout << "Tail Ptr: " << queue1.get_tail() << endl;
	cout << "Print Queue: " << queue1 << endl << endl;

	// remove 1 element from the queue and need to decrease the capacity after the removal of the elemet
	// due to the queue being less than half full
	queue1 -= queue1;
	cout << "Removing 1 element from  the Queue to make the total elements in the Queue = 1 and with the removal shrinking is necessary" << endl;
	cout << "The current state of the Queue's data" << endl;
	cout << "Capacity: " <<  queue1.get_cap() << endl;
	cout << "Tail Ptr: " << queue1.get_tail() << endl;
	cout << "Print Queue: " << queue1 << endl << endl;

	// remove 1 element from the queue and need to decrease the capacity after the removal of the elemet
	// due to the queue being half full (queue is now empty and the capacity should be back to default value of 1
	queue1 -= queue1;
	cout << "Removing 1 element from  the Queue to make the total elements in the Queue = 0 and with the removal shrinking is necessary" << endl;
	cout << "The current state of the Queue's data" << endl;
	cout << "Capacity: " <<  queue1.get_cap() << endl;
	cout << "Tail Ptr: " << queue1.get_tail() << endl;
	cout << "Print Queue: " << queue1 << endl << endl;

	return 0;
}
