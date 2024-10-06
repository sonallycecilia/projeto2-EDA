/*ref: https://www.geeksforgeeks.org/stack-using-linked-list-in-c/ (adapted)*/
#include "stackLinkedList.h"
// C program to implement a stack using linked list
#include <stdio.h>
#include <stdlib.h>

//  ________LINKED LIST UTILITY FUNCITON____________

// Count globals
int insertionsSll = 0;
int removalsSll = 0;
int countEmptyStackSll = 0;
size_t memoryAllocatedSll = 0;

// linked list utility function
Node* createNode(int data) {
    // allocating memory
    Node* newNode = (Node*)malloc(sizeof(Node));

    // if memory allocation is failed
    if (newNode == NULL){
        return NULL;
    }
        
    // putting data in the Node
    newNode->data = data;
    newNode->next = NULL;

    memoryAllocatedSll += sizeof(Node);
    return newNode;
}

// fuction to insert data before the head Node
int insertBeforeHead(Node** head, int data) {
    // creating new Node
    Node* newNode = createNode(data);
    // if malloc fail, return error code
    if (!newNode)
        return -1;

    // if the linked list is empty
    if (*head == NULL) {
        *head = newNode;

		insertionsSll++; // This is gonna be incremented once here
        return 0;
    }

    newNode->next = *head;
    *head = newNode;

	insertionsSll++;
    return 0;
}

// deleting head Node
int deleteHead(Node** head) {
    // no need to check for empty stack as it is already
    // being checked in the caller function
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);

	removalsSll++;
    return 0;
}

// _________STACK IMPLEMENTATION STARTS HERE_________

// Function to check if the stack is empty or not
int isEmpty(Node** stack) { return *stack == NULL; }

// Function to push elements to the stack
void push(Node** stack, int data) {
    // inserting the data at the beginning of the linked
    // list stack
    // if the insertion function returns the non - zero
    // value, it is the case of stack overflow
    if (insertBeforeHead(stack, data)) {
        printf("Stack Overflow!\n");
    }
}

// Function to pop an element from  the stack
int pop(Node** stack) {
    // checking underflow condition
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
		countEmptyStackSll++;
        return -1;
    }

    // deleting the head.
    deleteHead(stack);
}

// Function to return the topmost element of the stack
int peek(Node** stack) {
    // check for empty stack
    if (!isEmpty(stack))
        return (*stack)->data;
    else
        return -1;
}

// Function to print the Stack
void printStack(Node** stack) {
    Node* temp = *stack;
    while (temp != NULL) {
        printf("%d-> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int size(Node** stack) {
	int size = 0;
	Node* temp = *stack;
	while (temp != NULL){
		size++;
		temp = temp -> next;
	}
	return size;
}

// driver code
#ifndef MAIN_OVERRIDDEN
int main() {
    // Initialize a new stack top pointer
    Node *stack = NULL;

    // Push elements into the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);

    // Print the stack
    printf("Stack: ");
    printStack(&stack);
    // Pop elements from the stack
    pop(&stack);
    pop(&stack);
    // Print the stack after deletion of elements
    printf("\nStack: ");
    printStack(&stack);
	printf("\nSize: %d", size(&stack));

    return 0;
}
#endif