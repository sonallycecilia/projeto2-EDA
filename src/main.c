#include <stdio.h>
#include <stdlib.h>
#include "../estruturas/lista_encadeada.h"
#include "../estruturas/vetor_dinamico.h"

int* lerArquivo(const char *filePath) {
    int *array = malloc(2000000 * sizeof(int));

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

int main() {
    const char *caminhoArquivo = "C:\\Users\\sonal\\Documents\\vs projects\\projeto2-EDA\\src\\inserir_remover.txt"; // Caminho do arquivo a ser lido

    VetorDinamico vetor;
    ListaEncadeada lista;

    int *inserir_remover = lerArquivo(caminhoArquivo);
    
    free(inserir_remover); // Libera a memória alocada
    return 0;
}
