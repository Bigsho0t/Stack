#pragma once

#ifndef __stack_h__
#define __stack_h__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SUCESSO 0;
#define FALHA 1;

typedef struct No {

    void* valor;
    struct No* proximo;

} No;

typedef struct Pilha {

    No* topo;
    int tamanho;

} Pilha;

void printInt(void* valor);
void printChar(void* valor);
void printString(void* valor);
void printFloat(void* valor);
void printDouble(void* valor);
Pilha* criarPilha();
No* criarNo(void* valor);
int push(Pilha* pilha, void* valor);
void* pop(Pilha* pilha);
void* peek(Pilha* pilha);
bool isEmpty(Pilha* pilha);
int size(Pilha* pilha);
void imprimirPilha(Pilha* pilha, void (*printFunc)(void*));
void liberarPilha(Pilha* pilha);

#endif