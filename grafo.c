#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "lista.h"

grafo cria_grafo(){
  grafo g;
  int l,c;
  g = (grafo)malloc(sizeof(TGrafo));
  if(g){
    g->nv = 0;
    for(l=0;l<MAX;l++)
      for(c=0;c<MAX;c++)
        g->arestas[l][c].conectado = 0;
  }
  return g;
}

void termina_grafo(grafo g){
  free(g);
}

/*retorna - 1 se não encontrar */
int pesquisa_vertice(grafo g, TChave ch){
  int i;
  for(i=0;i<g->nv;i++)
    if(g->vertices[i].info.chave ==ch)
      return i;
  return -1;
}
int insere_vertice(grafo g,TElemento e){
  if(g->nv == MAX)
    return 0;

  if(pesquisa_vertice(g,e.chave)!=-1)
    return 0;

  g->vertices[g->nv].info = e;
  g->vertices[g->nv].status = espera;
  g->nv++;
  return 1;
}

int insere_aresta(grafo g,TChave ch1 ,TChave ch2,TPeso p){
   int posicao1, posicao2;
   posicao1 = pesquisa_vertice(g,ch1);
   if(posicao1==-1)
     return 0;
   posicao2 = pesquisa_vertice(g,ch2);
   if(posicao2==-1)
     return 0;
   g->arestas[posicao1][posicao2].conectado = 1;
   g->arestas[posicao1][posicao2].peso = p;
   g->arestas[posicao2][posicao1].conectado = 1;
   g->arestas[posicao2][posicao1].peso = p;
   return 1;
}

int remove_vertive(grafo g,TChave ch){
  int i, p= pesquisa_vertice(g,ch);
  if(p==-1)
    return 0;
  /*copiando a última linha para a linha a ser revodida*/
  for(i=0;i<g->nv;i++)
    g->arestas[p][i]= g->arestas[g->nv-1][i];

  for(i=0;i<g->nv;i++)
    g->arestas[i][p]= g->arestas[i][g->nv-1];
  /*removendo o vertice*/
  g->vertices[p] = g->vertices[g->nv-1]   ;
  g->nv--;
  return 1;
}

int remove_aresta(grafo g,TChave ch1,TChave ch2){
   int p1,p2;
   p1 = pesquisa_vertice(g,ch1);
   if(p1==-1)
     return 0;
   p2 = pesquisa_vertice(g,ch2);
   if(p2==-1)
     return 0;
   g->arestas[p1][p2].conectado =0;
   g->arestas[p2][p1].conectado =0;
   return 1;
}

void imprime_grafo(grafo g){
  int l,c;
  for(l=0;l<g->nv;l++)
    for(c=0;c<g->nv;c++)
      if(g->arestas[l][c].conectado)
        printf("\n%d......%d",
        g->vertices[l].info.chave,g->vertices[c].info.chave);
}


int dijkstra(grafo g, TChave origem, TChave destino){
  int vCusto[MAX], vPertence[MAX], vPath[MAX], i, k, s, t, corrente, custo, menorCusto;
  s = pesquisa_vertice(g, origem);
  if (s == -1)
    return -1;
  t = pesquisa_vertice(g, destino);
  if (t == -1)
    return -1;
  for (i = 0; i <g->nv; i++){
    vCusto[i] = INFINITO;
    vPertence[i] = NAOMEMBRO;
  }
  vCusto[s] = 0;
  vPertence[s] = MEMBRO;
  corrente = s;
  k = corrente;

  while (corrente != t){
    //atualizando o vetor de custo e path com os adjacentes não membros ao vértice corrente
    for (i = 0; i < g->nv; i++){
      if (g->arestas[corrente][i].conectado && vPertence[i] != MEMBRO){
        custo = vCusto[corrente] + g->arestas[corrente][i].peso;
        if (custo < vCusto[i]){
          vCusto[i] = custo;
          vPath[i] = corrente;
        }
      }
    }
    //encontrando o menor custo do vetor de custos não membros do caminho mais curto
    menorCusto = INFINITO;
    for (i = 0; i < g->nv; i++){
      if(vPertence[i] == NAOMEMBRO && vCusto[i] < menorCusto){
        menorCusto = vCusto[i];
        k = i;
      }
    }
    corrente = k;
    vPertence[k] = MEMBRO;
  }
  printf("\nCaminho mais curto\n");
  printf("%d", corrente );
  while (corrente != s){
     if (corrente != s)
      printf("<-");
    corrente =vPath[corrente];
    printf("%d", corrente );
   
  }
  printf("\n");
  return vCusto[t];
}
void insereAdjacentes(grafo g, lista li, int linha){
  int c;
  TElementoLista e;
  //verificando os adjacentes ao vértice corrente ainda não processados
  for(c = 0; c < g->nv; c++){
    if(g->vertices[c].status != processado && g->arestas[linha][c].conectado == 1){
      e.ch1 = g->vertices[linha].info.chave;
      e.ch2 = g->vertices[c].info.chave;
      e.chave = g->arestas[linha][c].peso;
      insereOrdenado(li,e);
    } 
  }
}

int agmPrim(grafo g, TChave origem){
    int i, linha, cont=1, posicao;
    lista li = criaLista();
    TElementoLista elemento;


    linha = pesquisa_vertice(g, origem);
    if(linha == -1)
      return 0;

    //mudando o status de cada vértice
    for(i=0; i<g->nv; i++){
      g->vertices[i].status = espera;
    }

    g->vertices[linha].status = processado;
    printf("%d\n", g->nv);
    insereAdjacentes(g, li, linha);
    while(cont < g->nv && !listaVazia(li)){
      retiraInicio(li, &elemento);
      posicao = pesquisa_vertice(g, elemento.ch2);
      if(g->vertices[posicao].status != processado){
        g->vertices[posicao].status = processado;
        insereAdjacentes(g, li, posicao);
        printf("%d---->%d\n", elemento.ch1, elemento.ch2);
        cont++;
      }
    }
    terminaLista(li);
    return 1;
}