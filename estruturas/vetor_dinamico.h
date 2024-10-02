#ifndef VETOR_DINAMICO_H
#define VETOR_DINAMICO_H

// Definição da estrutura do vetor dinâmico
typedef struct {
    int *dados;     // Ponteiro para os dados do vetor
    int tamanho;    // Quantidade de elementos no vetor
    int capacidade; // Capacidade total do vetor
} VetorDinamico;

// Declaração das funções
void iniciarVetorDinamico(VetorDinamico *vetor, int capacidade_inicial);
void addVetorDinamico(VetorDinamico *vetor, int valor);
void liberarVetorDinamico(VetorDinamico *vetor);
void imprimirVetorDinamico(VetorDinamico *vetor);

#endif
