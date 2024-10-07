/*ref: https://www.geeksforgeeks.org/introduction-and-array-implementation-of-queue/ (adapted)*/

// C program for array implementation of queue
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// Count Globals
int insertionsQDA;
int removalsQDA;
int countEmptyQDA;
size_t memoryAllocatedQDA;

// A structure to represent a queue
typedef struct Queue {
	int front, rear, size;
	unsigned capacity;
	int* array;
}Queue;

// function to create a queue
// of given capacity.
// It initializes size of queue as 0
void doubleQueue(Queue * queue){
    int size = queue->capacity;
    queue->capacity *= 2;
    queue->array = realloc(queue->array, queue->capacity * sizeof(int));
    if(queue->array == NULL){
        printf("Error realloccating memory");
    }

    if(queue->front > queue->rear){
        for (int i = 0; i < queue->front; i++)
        {
            queue->array[i+size] = queue->array[i];
        }
        queue->rear = queue->rear + size;
    }

    memoryAllocatedQDA += queue->capacity * sizeof(int);
} 

struct Queue* createQueue(unsigned capacity)
{
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->capacity = capacity;
	queue->front = queue->size = 0;

    memoryAllocatedQDA += sizeof(Queue);

	// This is important, see the enqueue
	queue->rear = capacity - 1;
	queue->array = (int*) malloc(queue->capacity * sizeof(int));

    memoryAllocatedQDA += queue->capacity * sizeof(int);

	return queue;
}

// Queue is full when size becomes
// equal to the capacity
int isFull(struct Queue* queue)
{
	return (queue->size == queue->capacity);
}

// Queue is empty when size is 0
int isEmpty(struct Queue* queue)
{
	return (queue->size == 0);
}

// Function to add an item to the queue.
// It changes rear and size
void enqueue(struct Queue* queue, int item)
{
	if (isFull(queue)){
        doubleQueue(queue);
    }
	queue->rear = (queue->rear + 1)% queue->capacity;
	queue->array[queue->rear] = item;
	queue->size = queue->size + 1;

    insertionsQDA++;
	//printf("%d enqueued to queue\n", item);
}

// Function to remove an item from queue.
// It changes front and size
int dequeue(struct Queue* queue)
{
	if (isEmpty(queue)){

        countEmptyQDA++;
		return INT_MIN;
    }
        
	int item = queue->array[queue->front];
	queue->front = (queue->front + 1)% queue->capacity;
	queue->size = queue->size - 1;

    removalsQDA++;
	return item;
}

// Function to get front of queue
int front(struct Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	return queue->array[queue->front];
}

// Function to get rear of queue
int rear(struct Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	return queue->array[queue->rear];
}

#ifndef MAIN_OVERRIDDEN
// Driver program to test above functions./
int main()
{
	struct Queue* queue = createQueue(1);

	enqueue(queue, 10);
	enqueue(queue, 20);
	enqueue(queue, 30);
	enqueue(queue, 40);

	printf("%d dequeued from queue\n\n",dequeue(queue));

	printf("Front item is %d\n", front(queue));
	printf("Rear item is %d\n", rear(queue));

	return 0;
}
#endif
 