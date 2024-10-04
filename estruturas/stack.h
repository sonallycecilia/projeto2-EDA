#ifndef STACK_H
#define STACK_H

// Define the structure for a node of the linked list
typedef struct node
{
    int data;
    struct node *next;
} Node;

Node* createNode(int data);

#endif
