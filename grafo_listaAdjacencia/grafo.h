#pragma once

#include <limits.h>
#include "lista.h"

#define MAX 10
#define INFINITO INT_MAX
#define MEMBRO 1
#define NAOMEMBRO 0

typedef int TChave;
typedef unsigned int TPeso;
typedef enum {espera,pronto,processado}TStatus;
typedef struct{
  TChave chave;
  /*demais componentes*/
}TElemento;

typedef struct {
  TElemento info;
  TStatus status;
  lista la;
}TVertice;



typedef struct {
  TVertice vertices[MAX];
  int nv;/*nmero de vértices*/
}TGrafo;

typedef TGrafo *grafo;

grafo cria_grafo();
void termina_grafo(grafo g);
int pesquisa_vertice(grafo, TChave);
int insere_vertice(grafo,TElemento);
int insere_aresta(grafo,TChave ,TChave,TPeso);
int remove_vertice(grafo,TChave);
int remove_aresta(grafo,TChave,TChave);
void imprime_grafo(grafo);

