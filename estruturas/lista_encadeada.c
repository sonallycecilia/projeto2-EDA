#include <stdlib.h>
#include <stdio.h>
#include "lista_encadeada.h"

// Função para inicializar a lista encadeada
void iniciarListaEncadeada(ListaEncadeada* lista) {
    lista->cabeca = NULL; // Inicializa a lista como vazia
}

// Função para adicionar um elemento à lista encadeada
void addListaEncadeada(ListaEncadeada* lista, int valor) {
    Node* novo_no = (Node*)malloc(sizeof(Node));
    novo_no->valor = valor;
    novo_no->proximo = lista->cabeca; // Insere no início
    lista->cabeca = novo_no;
}

// Função para imprimir a lista encadeada
void imprimirListaEncadeada(ListaEncadeada* lista) {
    Node* atual = lista->cabeca;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

// Função para liberar a memória alocada para a lista encadeada
void liberarListaEncadeada(ListaEncadeada* lista) {
    Node* atual = lista->cabeca;
    while (atual != NULL) {
        Node* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    lista->cabeca = NULL; // Define a cabeça como nula
}
