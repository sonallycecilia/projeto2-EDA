#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

typedef struct Node {
    int valor;
    struct Node* proximo;
} Node;

typedef struct {
    Node* cabeca; // Ponteiro para o primeiro nó da lista
} ListaEncadeada;

void iniciarListaEncadeada(ListaEncadeada* lista);
void addListaEncadeada(ListaEncadeada* lista, int valor);
void imprimirListaEncadeada(ListaEncadeada* lista);
void liberarListaEncadeada(ListaEncadeada* lista);

#endif
