#include <stdio.h>
#include <stdlib.h>
#include "vetor_dinamico.h"

// Função para inicializar o vetor dinâmico
void iniciarVetorDinamico(VetorDinamico *vetor, int capacidade_inicial) {
    vetor->dados = (int*) malloc(capacidade_inicial * sizeof(int));  // Aloca memória inicial
    vetor->tamanho = 0;  // Nenhum elemento adicionado ainda
    vetor->capacidade = capacidade_inicial;  // Define a capacidade inicial
}

// Função para adicionar um elemento ao vetor dinâmico
void addVetorDinamico(VetorDinamico *vetor, int valor) {
    // Verifica se é necessário redimensionar (dobrar a capacidade)
    if (vetor->tamanho == vetor->capacidade) {
        vetor->capacidade *= 2;  // Dobra a capacidade
        vetor->dados = (int*) realloc(vetor->dados, vetor->capacidade * sizeof(int));  // Realoca memória
    }
    vetor->dados[vetor->tamanho] = valor;  // Adiciona o novo valor no vetor
    vetor->tamanho++;  // Incrementa o tamanho
}

// Função para liberar a memória alocada para o vetor dinâmico
void liberarVetorDinamico(VetorDinamico *vetor) {
    free(vetor->dados);  // Libera a memória
    vetor->dados = NULL;  // Define o ponteiro como nulo
    vetor->tamanho = 0;  // Reseta o tamanho
    vetor->capacidade = 0;  // Reseta a capacidade
}

// Função para imprimir o vetor dinâmico
void imprimirVetorDinamico(VetorDinamico *vetor) {
    for (int i = 0; i < vetor->tamanho; i++) {
        printf("%d ", vetor->dados[i]);
    }
    printf("\n");
}


