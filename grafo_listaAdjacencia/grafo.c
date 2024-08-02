#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"


grafo cria_grafo()
{
  grafo g;
  int i;
  g = (grafo)malloc(sizeof(TGrafo));
  if (g)
  {
    g->nv = 0;
    for (i = 0; i < MAX; i++)
    {
      g->vertices[i].la = NULL;
    }
  }
  return g;
}

void termina_grafo(grafo g)
{
  int i;

  for (i = 0; i < MAX; i++)
  {
    terminaLista(g->vertices[i].la);
  }

  free(g);
}

/*retorna - 1 se não encontrar */
int pesquisa_vertice(grafo g, TChave ch)
{
  int i;
  for (i = 0; i < g->nv; i++)
    if (g->vertices[i].info.chave == ch)
      return i;
  return -1;
}

int insere_vertice(grafo g, TElemento e)
{
  if (g->nv == MAX)
    return 0;

  if (pesquisa_vertice(g, e.chave) != -1)
    return 0;

  g->vertices[g->nv].info = e;
  g->vertices[g->nv].status = espera;
  g->vertices[g->nv].la = criaLista();
  g->nv++;
  return 1;
}

int insere_aresta(grafo g, TChave ch1, TChave ch2, TPeso p)
{
  int posicao1, posicao2;
  TElementoLista e1, e2;
  posicao1 = pesquisa_vertice(g, ch1);
  if (posicao1 == -1)
    return 0;
  e1.peso = p;
  e1.chave = ch1;

  posicao2 = pesquisa_vertice(g, ch2);
  e2.peso = p;
  e2.chave = ch2;

  if (posicao2 == -1)
    return 0;
  insereOrdenado(g->vertices[posicao1].la, e2);
  insereOrdenado(g->vertices[posicao2].la, e1);
      
  return 1;
}

int remove_vertice(grafo g, TChave ch){
  TVertice aux;
  TElementoLista e;
  int i, 
      p = pesquisa_vertice(g, ch);
  if (p == -1)
    return 0;
  
  //remove o vertice e transfere o último vertice do vetor para a posição do removido
  aux = g->vertices[p];
  terminaLista(aux.la);
  g->vertices[p] = g->vertices[g->nv - 1];
  g->nv--;

  //remove as arestas ligadas ao vértice removido
  for(i = 0; i < g->nv; i++){
    retiraElemento(g->vertices[i].la, ch, &e);
  }
  return 1;
}

int remove_aresta(grafo g, TChave ch1, TChave ch2)
{
  TElementoLista e;
  int p1, p2;
  p1 = pesquisa_vertice(g, ch1);
  if (p1 == -1)
    return 0;
  p2 = pesquisa_vertice(g, ch2);
  if (p2 == -1)
    return 0;
  
  retiraElemento(g->vertices[p1].la, ch2, &e);
  retiraElemento(g->vertices[p2].la, ch1, &e);
  
  return 1;
}

void imprime_grafo(grafo g)
{
  int i;
  for (i = 0; i < g->nv; i++){
     printf("\nArestas do vértice %d: ", g->vertices[i].info.chave);
     imprimeLista(g->vertices[i].la);
  }   
       
}
