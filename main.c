#include "stack.h"

int main() {

    Pilha* pilha = criarPilha();

    push(pilha, "Davi");
    push(pilha, "Arthur Fudido");
    push(pilha, "Amorzinho");

    imprimirPilha(pilha, printString);
    liberarPilha(pilha);

    return 0;
}