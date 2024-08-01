#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

lista criaLista(){
    lista l = malloc(sizeof(TLista));
    if(l){
        l->inicio = NULL;
        l->fim = NULL;
        l->tamanho = 0;
    }
    return l;
}

void terminaLista(lista l){
    TNodo *p;
    while(l->inicio){
        p = l->inicio;
        l->inicio = l->inicio->prox;
        free(p);
    }
    free(l);
}

int insereOrdenado(lista l, TElementoLista e){
    TNodo *p, *pAnt, *pAux;
    pAux = (TNodo*)malloc(sizeof(TNodo));
    if(!pAux)
        return 0;
    pAux->info = e;
    if(listaVazia(l)){
        l->inicio = pAux;
        l->fim = pAux;
        pAux->prox=NULL;
        l->tamanho++;
        return 1;
    }

    p = l->inicio;
    while(p && p->info.chave < e.chave) {
        pAnt = p;
        p = p->prox;
    }

    //verificando se é para inserir no início
    if(p == l->inicio){
        pAux->prox = l->inicio;
        l->inicio = pAux;
    }
    else    
        //verificando se é para inserir no final
        if(p == NULL){
            l->fim->prox = pAux;
            l->fim = pAux;
            pAux->prox = NULL;
        }
        else{
            pAux->prox = p;
            pAnt->prox = pAux;
        }
    l->tamanho++;
    return 1;
}

int retiraInicio(lista l, TElementoLista *e){
    TNodo *p;
    if(listaVazia(l))
        return 0;
    p = l->inicio;
    l->inicio = l->inicio->prox;
    l->tamanho--;
    *e = p->info;
    free(p);
    return 1;
}

int listaVazia(lista l){
    return l->tamanho == 0;
}
