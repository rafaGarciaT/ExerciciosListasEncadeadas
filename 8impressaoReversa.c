#include <stdio.h>

typedef struct No {
    int dado;
    struct No *proximo;
} No;

typedef struct Fila {
    No *inicio;
    No *fim;
} Fila;

void inserir_inicio(Fila *fila, int valor) {
    No *novoNo = (No*) malloc(sizeof(No));
    novoNo->dado = valor;
    novoNo->proximo = NULL;
    
    if (fila->inicio == NULL) {
        fila->inicio = fila->fim = novoNo;
    } else {
        novoNo->proximo = fila->inicio;
        fila->inicio = novoNo;
        if (fila->fim == NULL) {
            fila->fim = novoNo;
        }
    }
}

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

void impressaoReversa(Fila *fila) {
    Fila filaReversa = {NULL, NULL};
    No *atual = fila->inicio;
    while (atual !=NULL) {
        inserir_inicio(&filaReversa, atual->dado);
        atual = atual->proximo;
    }

    atual = filaReversa.inicio;
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
    return;
}

int main() {
    Fila fila = {NULL, NULL};

    inserir_fim(&fila, 1);
    inserir_fim(&fila, 2);
    inserir_fim(&fila, 3);

    printf("%d", buscaElemento(&fila, 3));

    return 0;
}