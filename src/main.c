#define MAIN_OVERRIDDEN

#define INICIAL_INSERTIONS 1000000
#define TOTAL_INSERTIONS 2000000
#define PUSH 1
#define POP 0

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../estruturas/stack.c"



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

#include <stdio.h>
#include <time.h>

int main() {
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

    printf("Execution Time: %f seconds\nEmpty Stack: %d\nInsertions: %d\nRemovals: %d\nSize: %d\nTotalInsertions: %d", timeUsed, countEmptyStack, insertions, removals, size(&stack), insertions+removals);

    return 0;
}
