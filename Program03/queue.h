// Create an empty queue with an initial capacity of one
float* create_empty(int* capactiy, int* tail);

// add (que) an item to the queue
void add(float* queue, int* capacity, int* tail, float* que);

// Test to see if the queue is full - at capactiy
int test_full(int* capacity, int* tail);

// Grow the capacity of the queue to twice its current capacity
void grow_twice(float* queue, int* capacity);

// Test to see if the queue is empty
int test_empty(int* tail);

// Remove / return (deque) an item from the queue
float remove_deq(float* queue, int* tail, int* capacity);

// test to see if the queue is less than half full
int test_halfFull(int* capacity, int* tail);

// shirnk the capacity of the queue in half its current capacity
void shrink(float* queue, int* capacity);
