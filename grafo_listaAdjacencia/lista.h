#pragma once

typedef int TChave;
typedef unsigned int TPeso;
typedef struct{
    TPeso peso;
    TChave chave;
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
int retiraElemento(lista l, TChave ch, TElementoLista *e);
int listaVazia(lista l);
int tamanhoLista(lista l);
void imprimeLista(lista l);



