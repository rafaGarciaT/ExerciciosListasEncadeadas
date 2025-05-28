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

int main() {
    Fila fila = {NULL, NULL};  
    inserir_fim(&fila, 10);  
    inserir_inicio(&fila, 5);  
    return 0;
}