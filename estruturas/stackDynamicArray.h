#ifndef VETOR_DINAMICO_H
#define VETOR_DINAMICO_H

// Definição da estrutura do vetor dinâmico
typedef struct {
    int top;        // Índice do elemento no topo da pilha
    int capacity;   // Capacidade total do vetor
    int *data;     // Ponteiro para os dados do vetor
} StackDynArr;  

// Declaração das funções

void initStack(StackDynArr **);
void doubleStack(StackDynArr *);
void push(StackDynArr*, int );
int pop(StackDynArr *);
int isEmpty(StackDynArr *);
int isFull(StackDynArr *);
int size(StackDynArr *);
void printStack(StackDynArr *);


#endif
