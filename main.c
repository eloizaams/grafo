#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main()
{
    grafo g = cria_grafo();
    TElemento e;
    int i;
    for (i = 0; i <= 5; i++){
        e.chave = i;
        insere_vertice (g,e);
    }
    insere_aresta(g, 1, 2, 10);
    insere_aresta(g, 1, 4, 1);
    insere_aresta(g, 1, 5, 3);
    insere_aresta(g, 2, 3, 3);
    insere_aresta(g, 3, 5, 2);
    insere_aresta(g, 2, 5, 1);
    insere_aresta(g, 4, 5, 1);

    int distancia = dijkstra(g, 1, 2);
    printf ("\nCusto total = %d\n", distancia);
    return 0;
}
