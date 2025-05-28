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

void removerValor(Fila *fila, int valor) {
    No *atual = fila->inicio;
    No *anterior = NULL; 

    while (atual !=NULL) {
        if (atual->dado == valor){
            if (anterior == NULL) {
                fila->inicio = atual->proximo;
                if (fila->inicio == NULL) {
                    fila->fim = NULL;
                }
            } else{
                anterior->proximo = atual->proximo;
                if (atual== fila->fim) {
                    fila->fim = anterior;
                }
            }
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return;
}

int main() {
    Fila fila = {NULL, NULL};

    inserir_fim(&fila, 1);
    inserir_fim(&fila, 2);
    inserir_fim(&fila, 3);

    removerValor(&fila, 3);

    return 0;
}