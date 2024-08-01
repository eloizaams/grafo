#pragma once

#include "grafo.h"

typedef int TChaveLista;
typedef struct{
    TPeso chave;
    TChaveLista ch1, ch2;
}TElementoLista;

typedef struct Nodo{
    TElementoLista info;
    struct Nodo *prox;
}TNodo;

typedef struct{
    TNodo *inicio, *fim;
    int tamanho;
}TLista;

typedef TLista *lista;

lista criaLista();
void terminaLista(lista l);
int insereOrdenado(lista l, TElementoLista e);
int retiraInicio(lista l, TElementoLista *e);
int listaVazia(lista l);



