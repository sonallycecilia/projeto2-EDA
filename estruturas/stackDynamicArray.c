#include <stdlib.h>
#include <stdio.h>
#include <limits.h> //INT MIN
#include "../estruturas/stackDynamicArray.h"

#define DEFAULT_SIZE 1

// Count Globals
int insertionsSDA;
int removalsSDA;
int countEmptyStackSDA;
size_t memoryAllocatedSDA;

// Stack operations
void initStack(StackDynArr **stack){
    (*stack) = (StackDynArr *) malloc(sizeof(StackDynArr));
    (*stack)->top = -1;
    (*stack)->capacity = DEFAULT_SIZE;
    (*stack)->data = (int*) malloc((*stack)->capacity * sizeof(int));

    if((*stack)->data == NULL){
        printf("Error allocating memory\n");
    } 
}

void doubleStack(StackDynArr *stack){
    int newCapacity = stack->capacity * 2;
    int *newData = realloc(stack->data, newCapacity * sizeof(int));
    if (newData == NULL) {
        printf("Error reallocating memory!\n");
    } else {
        stack->capacity = newCapacity;
        stack->data = newData;
    }
    printf("Capacity: %d\n", stack->capacity);
    memoryAllocatedSDA += stack->capacity * sizeof(int);
}

void push(StackDynArr *stack, int data){
    if(isFull(stack)){
        doubleStack(stack); // Stack Overflow don't exist! 
    } 
    stack->data[++(stack->top)] = data;
    insertionsSDA++;
}

int pop(StackDynArr *stack){
    if(isEmpty(stack)){
        printf("Stack Underflow\n");
    } else {
        removalsSDA++;
        return stack->data[(stack->top)--];
    }
}

int isEmpty(StackDynArr *stack){
    if(stack->top == -1){
        countEmptyStackSDA++;
    } 
    return stack->top == -1 ;
}

int isFull(StackDynArr *stack){
    return (stack->top) + 1 == stack->capacity; 
}

int size(StackDynArr *stack){
    return stack->top + 1;
}

void printStack(StackDynArr *stack){
    if(isEmpty(stack)){
        printf("Empty Stack");
    } else {
        printf("Stack :");
        for(int i = 0; i <stack->top + 1; i++){
            printf("%d ", stack->data[i]);
        }
        printf("\n");
    }
}

// Driver Test
#ifndef MAIN_OVERRIDDEN
    int main() {
        StackDynArr *stack;
        initStack(&stack);
        for (int i = 0; i < 10; i++) {
            push(stack, i);
            printf("capacity: %d\n",stack->capacity);
        }
        printStack(stack);
        int size = stack->top+1;
        for (int i = 0; i < size - 1; i++){
            printf("pop: %d\n", pop(stack));
        }
        printStack(stack);
        
        return 0;
    }

#endif

