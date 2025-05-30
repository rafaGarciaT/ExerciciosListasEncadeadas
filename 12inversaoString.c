#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *proximo;
} No;

typedef struct {
    No *topo;
} Pilha;

void push(Pilha *pilha, int valor) {
    No* novoNo = (No*) malloc(sizeof(No));
    novoNo->dado = valor;
    novoNo->proximo = pilha->topo;
    pilha->topo = novoNo;
}

int pop(Pilha* pilha) {
    No* noRemover = pilha->topo;
    int valor = noRemover->dado;
    pilha->topo = noRemover->proximo;
    free(noRemover);
    return valor;
}

bool esta_vazia(Pilha *pilha){
    return pilha->topo == NULL;
}

int topo(Pilha *pilha) {
    if (esta_vazia(pilha)) {
        printf("Pilha vazia.\n");
        return -1;
    } else {
        return pilha->topo->dado;
    }
}

void inversaoString(char* str) {
    Pilha pilha = {NULL};
    for (int i = 0; str[i] != '\0'; i++) {
        push(&pilha, str[i]);
    }
    for (int i = 0; !esta_vazia(&pilha); i++) {
        str[i] = pop(&pilha);
    }
}

int main() {
    Pilha pilha = {NULL};

    push(&pilha, 1);
    push(&pilha, 2);
    push(&pilha, 3);

    pop(&pilha);
    
    if (esta_vazia(&pilha) == false) {
        printf("Não vazia\n");
    } else {
        printf("Vazia\n");
    }
    
    printf("%d\n", topo(&pilha));
    
    pop(&pilha);
    pop(&pilha);
    
    if (esta_vazia(&pilha) == false) {
        printf("Não vazia\n");
    } else {
        printf("Vazia\n");
    }
    
    return 0;
}