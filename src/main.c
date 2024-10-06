#define MAIN_OVERRIDDEN
#define INICIAL_INSERTIONS 1000000
#define TOTAL_INSERTIONS 2000000
#define PUSH 1
#define POP 0

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "../estruturas/stackLinkedList.c"
//#include "../estruturas/stackDynamicArray.c"
#include "../estruturas/queueLinkedList.c"



// 1 para inserir e 0 para remover.
int* lerArquivo(const char *filePath) {
    int *array = malloc(TOTAL_INSERTIONS * sizeof(int));

    FILE *file = fopen(filePath, "r"); 
    if (file == NULL) {
        perror("Erro ao abrir o arquivo"); 
        return NULL;
    }

    int value;
    int i = 0;
    while (fscanf(file, "%d", &value) != EOF) { 
        array[i] = value;
        i++;
    }
    fclose(file);
    return array;
}

/*
int testStackLinkedList() {
    // Declaring runtime vars
    clock_t start, end;
    double timeUsed;

    // Reading the txt "inserir_remover"
    int *array;
    array = lerArquivo("inserir_remover.txt");

    // Inicializing the Stack
    Node *stack = NULL; // head
    for(int i = 0; i < INICIAL_INSERTIONS; i++ ){
        push(&stack, 2);
    } // Medir a memória consumida após essas inserções inicias tanto na Lista encadeada quanto no Vetor dinâmico
    
    // 2_000_000 pop n/or push
    start = clock();
    for(int i = 0; i < TOTAL_INSERTIONS; i++){
        switch (array[i]){
            case PUSH:
                push(&stack, i);
                break;

            case POP:
                pop(&stack);
                break;

            default:
                printf("An error occurred while reading the file");
                break;
        }
    }
    end = clock();
    timeUsed = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Execution Time: %f seconds\nEmpty Stack: %d\nInsertionsSll: %d\nRemovalsSll: %d\nSize: %d\nTotalInsertionsSll: %d\nMemory Allocated: %d Mb\nSizeOf: %d %d %d", timeUsed, countEmptyStackSll, insertionsSll, removalsSll, size(&stack), insertionsSll+removalsSll, memoryAllocatedSll/(1024*1024), sizeof(Node), sizeof(int*), sizeof(Node*));
}
*/

/*
void testStackDynamicArray() {
    // Declaring runtime vars
    clock_t start, end;
    double timeUsed;

    // Reading the txt "inserir_remover"
    int *array;
    array = lerArquivo("inserir_remover.txt");

    // Inicializing the Stack
    StackDynArr *stack;
    initStack(&stack);
    for (int i = 0; i < INICIAL_INSERTIONS; i++) {
        push(stack, 2);
    }
    // Medir a memória consumida após essas inserções inicias tanto na Lista encadeada quanto no Vetor dinâmico
    // 2_000_000 pop n/or push
    start = clock();
    for(int i = 0; i < TOTAL_INSERTIONS; i++){
        switch (array[i]){
            case PUSH:
                push(stack, i);
                break;

            case POP:
                pop(stack);
                break;

            default:
                printf("An error occurred while reading the file");
                break;
        }
    }
    end = clock();
    timeUsed = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Execution Time: %f seconds\nEmpty Stack: %d\nInsertionsSDA: %d\nRemovalsSDA: %d\nSize: %d\nTotalInsertionsSDA: %d\nMemory Allocated: %d Mb\nSizeOf stuct: %d\nCapacity: %d", timeUsed, countEmptyStackSDA, insertionsSDA, removalsSDA, size(stack), insertionsSDA+removalsSDA, memoryAllocatedSDA/(1024*1024), sizeof(StackDynArr), stack->capacity);
}
*/

void testQueueLinkedList() {
    // Declaring runtime vars
    clock_t start, end;
    double timeUsed;

    // Reading the txt "inserir_remover"
    int *array;
    array = lerArquivo("inserir_remover.txt");

    // Inicializing the queue
    Queue *queue = createQueue();
    for (int i = 0; i < INICIAL_INSERTIONS; i++) {
        enqueue(queue, 2);
    }

    // Medir a memória consumida após essas inserções inicias tanto na Lista encadeada quanto no Vetor dinâmico
    // 2_000_000 pop n/or push
    start = clock();
    for(int i = 0; i < TOTAL_INSERTIONS; i++){
        switch (array[i]){
            case PUSH:
                enqueue(queue, i);
                break;

            case POP:
                dequeue(queue);
                break;

            default:
                printf("An error occurred while reading the file");
                break;
        }
    }
    end = clock();  
    timeUsed = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Execution Time: %f seconds\nEmpty queue: %d\nInsertionsQLL: %d\nRemovalsQLL: %d\nTotalInsertionsQLL: %d\nMemory Allocated: %d Mb\nSizeOf stuct: %d\nCapacity: %d", timeUsed, countEmptyQLL, insertionsQLL, removalsQLL, insertionsQLL+removalsQLL, memoryAllocatedQLL/(1024*1024), sizeof(queue));
}


int main(){
    //testStackLinkedList();
    //testStackDynamicArray();
    testQueueLinkedList();
    return 0;
}
