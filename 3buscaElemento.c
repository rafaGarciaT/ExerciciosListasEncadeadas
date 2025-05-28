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

int buscaElemento(Fila *fila, int valor) {
    int resposta = 0;
    No *atual = fila->inicio;
    while (atual !=NULL) {
        if (atual->dado == valor){
            resposta = 1;
        }
        atual = atual->proximo;
    }
    return resposta;
}

int main() {
    Fila fila = {NULL, NULL};

    inserir_fim(&fila, 1);
    inserir_fim(&fila, 2);
    inserir_fim(&fila, 3);

    printf("%d", buscaElemento(&fila, 3));

    return 0;
}