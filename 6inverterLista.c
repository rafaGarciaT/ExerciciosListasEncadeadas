#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *proximo;
} No;

typedef struct Fila {
    No *inicio;
    No *fim;
} Fila;

void inserir_fim(Fila *fila, int valor) {
    No *novoNo = (No*) malloc(sizeof(No));
    novoNo->dado = valor;
    novoNo->proximo = NULL;

    if (fila->fim == NULL) {
        fila->inicio = fila->fim = novoNo;
    } else {
        fila->fim->proximo = novoNo;
        fila->fim = novoNo;
    }
}

Fila inverterLista(Fila *fila) {
    Fila filaReversa = {NULL, NULL};
    No *atual = fila->inicio;

    while (atual !=NULL) {
        inserir_inicio(&filaReversa, atual->dado);
        atual = atual->proximo;
    }
    return filaReversa;
}

int main() {
    Fila fila = {NULL, NULL};

    inserir_fim(&fila, 1);
    inserir_fim(&fila, 2);
    inserir_fim(&fila, 3);

    Fila filaReversa = inverterLista(&fila);

    return 0;
}