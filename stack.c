#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printInt(void* valor) {

    printf("%i", *(int*)valor);
}

void printChar(void* valor) {

    printf("%c", *(char*)valor);
}

void printString(void* valor) {

    printf("%s", (char*)valor);
}

void printFloat(void* valor) {

    printf("%f", *(float*)valor);
}

void printDouble(void* valor) {

    printf("%f", *(double*)valor);
}

Pilha* criarPilha() {

    Pilha* novaPilha = (Pilha*) malloc(sizeof(Pilha));

    if (novaPilha == NULL) {

        return NULL;
    }

    novaPilha->topo = NULL;
    novaPilha->tamanho = 0;
    return novaPilha;
}

No* criarNo(void* valor) {

    No* novoNo = (No*) malloc(sizeof(No));

    if (novoNo == NULL) {

        return NULL;
    }

    novoNo->valor = valor;
    novoNo->proximo = NULL;
    return novoNo;
}

int push(Pilha* pilha, void* valor) {

    if (pilha == NULL) {

        return FALHA;
    }

    No* novoTopo = criarNo(valor);

    if (novoTopo == NULL) {

        return FALHA;
    }

    novoTopo->proximo = pilha->topo;
    pilha->topo = novoTopo;
    pilha->tamanho++;
    return SUCESSO;
}

void* pop(Pilha* pilha) {

    if (pilha == NULL || pilha->topo == NULL) {

        return NULL;
    }

    void* valor = pilha->topo->valor;
    No* temp = pilha->topo;
    pilha->topo = pilha->topo->proximo;
    free(temp);
    return valor;
}

void* peek(Pilha* pilha) {

    if (pilha == NULL || pilha->topo == NULL) {

        return NULL;
    }

    void* valor = pilha->topo->valor;
    return valor;
}

bool isEmpty(Pilha* pilha) {

    return pilha->topo == NULL;
}

int size(Pilha* pilha) {

    if (pilha == NULL) {

        return 0;
    }

    return pilha->tamanho;
}

void imprimirPilha(Pilha* pilha, void (*printFunc)(void*)) {

    if (pilha == NULL) {

        printf("Pilha não existe.\n");
        return;
    }

    if (pilha->topo == NULL) {

        printf("Pilha vazia.\n");
        return;
    }

    No* atual = pilha->topo;

    while (atual != NULL) {

        printFunc(atual->valor);
        printf("\n");
        atual = atual->proximo;
    }

    printf("NULL\n");
}

void liberarPilha(Pilha* pilha) {

    if (pilha == NULL) {

        return;
    }

    No* atual = pilha->topo;
    No* temp;

    while (atual != NULL) {

        temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}