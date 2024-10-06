


// Node structure representing a single node in the linked
// list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Structure to implement queue operations using a linked
// list
typedef struct Queue {

    // Pointer to the front and the rear of the linked list
    Node *front, *rear;
} Queue;

// Function to create a new node
Node* createNode(int new_data);

// Function to create a queue
Queue* createQueue();

// Function to check if the queue is empty
int isEmpty(Queue* q);

// Function to add an element to the queue
void enqueue(Queue* q, int new_data);

// Function to remove an element from the queue
void dequeue(Queue* q);

// Function to get the front element of the queue
int getFront(Queue* q);

// Function to get the rear element of the queue
int getRear(Queue* q);

int size(Queue *q);