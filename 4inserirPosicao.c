#include <stdio.h>

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

void inserirPosicao(Fila *fila, int valor, int posicao) {
    No *novoNo = (No*) malloc(sizeof(No));
    novoNo->dado = valor;
    novoNo->proximo = NULL;

    if (posicao <=1 || fila->inicio == NULL) {
        novoNo->proximo = fila->inicio;
        fila->inicio = novoNo;
        if (fila->fim == NULL) {
            fila->fim = novoNo;
        }
        return;
    }

    No *atual = fila->inicio;
    No *anterior = NULL; 
    int cont = 1;

    while (cont < posicao && atual != NULL) {
        cont++;
        anterior = atual;
        atual = atual->proximo;
    }
    
    if (atual == NULL || atual->proximo == NULL) {
        fila->fim->proximo = novoNo;
        fila->fim = novoNo;
    } else {
        novoNo->proximo = atual->proximo;
        atual->proximo = novoNo;
    }
}

int main() {
    Fila fila = {NULL, NULL};

    inserir_fim(&fila, 1);
    inserir_fim(&fila, 2);
    inserir_fim(&fila, 3);

    inserirPosicao(&fila, 10, 4);

    return 0;
}