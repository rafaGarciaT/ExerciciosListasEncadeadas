#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int elementos[100];
    int topo;
} Pilha;

void push(Pilha *pilha, int valor) {
    if (pilha->topo == 100-1) {
        printf("Pilha cheia\n");
        return;
    }

    pilha->elementos[++pilha->topo] = valor;
}

int pop(Pilha* pilha) {
    if (pilha->topo == -1) {
        printf("Pilha vazia\n");
        return -1;
    }

    return pilha->elementos[pilha->topo--];
}

bool esta_vazia(Pilha *pilha){
    return pilha->topo == -1;
}

int topo(Pilha *pilha) {
    if (esta_vazia(pilha) == true) {
        printf("Pilha vazia.\n");
        return -1; 
    } else {
        return pilha->elementos[pilha->topo];
    }
}

int main() {
    Pilha pilha = {.topo = -1};

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