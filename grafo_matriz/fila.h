#pragma once

#include "grafo.h"

typedef struct{
    TChave chave;
}TElementoFila;

typedef struct NodoFila{
    TElementoFila info;
    struct NodoFila *prox;
}TNodoFila;

typedef struct {
    TNodoFila *inicio, *fim;
    int tamanho;
}TFila;

typedef TFila *fila;

fila criaFila();
void terminaFila(fila f);
int colocaFila(fila f, TElementoFila e);
int retiraFila(fila f, TElementoFila *e);
int filaVazia(fila f);