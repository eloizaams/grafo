#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

pilha criaPilha(){
    pilha p = (TPilha*)malloc(sizeof(TPilha));
    if(p){
        p->topo = NULL;
        p->tamanho = 0;
    }
    return p;
}

void terminaPilha(pilha p){
    TNodoPilha *ptr;
    while(p->topo){
    ptr = p->topo;
    p->topo = p->topo->prox;
    free(ptr);
   }
   free(p);
}

int colocaPilha(pilha p, TElementoPilha e){
    TNodoPilha *ptr = (TNodoPilha*)malloc(sizeof(TNodoPilha));

    if(!ptr)
       return 0;

    ptr->info=e;
    ptr->prox=p->topo;
    p->topo=ptr;
    p->tamanho++;
    return 1;

}


int retiraPilha(pilha p, TElementoPilha *e){
    TNodoPilha *ptr;
    if(pilhaVazia(p))
        return 0;
    ptr=p->topo;
    p->topo=p->topo->prox;
    *e=ptr->info;
    free(ptr);
    p->tamanho--;
    return 1;
}

int pilhaVazia(pilha p){
    return p->tamanho == 0;
}