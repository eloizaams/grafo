#pragma once

#include "grafo.h"

typedef struct{
    TChave chave;
}TElementoPilha;

typedef struct NodoPilha{
    TElementoPilha info;
    struct NodoPilha *prox;
}TNodoPilha;

typedef struct {
    TNodoPilha *topo;
    int tamanho;
}TPilha;

typedef TPilha *pilha;

pilha criaPilha();
void terminaPilha(pilha p);
int colocaPilha(pilha p, TElementoPilha e);
int retiraPilha(pilha p, TElementoPilha *e);
int pilhaVazia(pilha p);