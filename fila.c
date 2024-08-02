#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

fila criaFila(){
    fila f = (TFila*)malloc(sizeof(TFila));
    if(f){
        f->inicio = NULL;
        f->fim = NULL;
        f->tamanho = 0;
    }
    return f;
}

void terminaFila(fila f){
   TNodoFila *ptr;
   while(f->inicio){
    ptr = f->inicio;
    f->inicio = f->inicio->prox;
    free(ptr);
   }
   free(f);
}

int colocaFila(fila f, TElementoFila e){
    TNodoFila *ptr;
    ptr = (TNodoFila*)malloc(sizeof(TNodoFila));
    if (!ptr)
        return 0;
    ptr->info = e;
    ptr->prox = NULL;
    if (f->inicio == NULL)
        f->inicio = ptr;
    else
        f->fim->prox = ptr;
   
    f->fim = ptr;
    f->tamanho++;
    return 1;

}

int retiraFila(fila f, TElementoFila *e){
    TNodoFila *ptr;
    if(filaVazia(f))
        return 0;
    ptr = f->inicio;
    f->inicio = f->inicio->prox;
    *e = ptr->info;
    f->tamanho--;
    free (ptr);
    return 1;

}

int filaVazia(fila f){
    return f->tamanho == 0;
}