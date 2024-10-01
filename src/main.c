#include <stdio.h>
#include "../estruturas/vetor_dinamico.h"

int main() {
    VetorDinamico vetor;

    // Inicializa o vetor dinâmico com capacidade inicial de 4
    inicializar(&vetor, 4);

    // Adiciona alguns valores ao vetor dinâmico
    adicionar(&vetor, 1);
    adicionar(&vetor, 2);
    adicionar(&vetor, 3);
    adicionar(&vetor, 4);
    adicionar(&vetor, 5);  // Aqui o vetor será redimensionado para o dobro da capacidade

    // Imprime o conteúdo do vetor
    printf("Vetor Dinamico: ");
    imprimir(&vetor);

    // Libera a memória usada pelo vetor dinâmico
    liberar(&vetor);

    return 0;
}
