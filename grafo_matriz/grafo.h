#pragma once

#include <limits.h>
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
}TVertice;

typedef struct{
  int conectado;
  TPeso peso;
 }TAresta;


typedef struct {
  TVertice vertices[MAX];
  TAresta arestas[MAX][MAX];
  int nv;/*nmero de vértices*/
}TGrafo;

typedef TGrafo *grafo;

grafo cria_grafo();
void termina_grafo(grafo g);
int pesquisa_vertice(grafo, TChave);
int insere_vertice(grafo,TElemento);
int insere_aresta(grafo,TChave ,TChave,TPeso);
int remove_vertive(grafo,TChave);
int remove_aresta(grafo,TChave,TChave);
void imprime_grafo(grafo);
int dijkstra(grafo g, TChave origem, TChave destino);
int agmPrim(grafo g, TChave origem);
int dfs(grafo g, TChave origem); //busca em profundiade
int bfs(grafo g, TChave origem); //busco em amplitude
int dfs_nr(grafo g, TChave origem); //busca em profundiade - não recursiva
