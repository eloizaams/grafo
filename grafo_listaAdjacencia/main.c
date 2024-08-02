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
    insere_aresta(g, 0, 5, 7);
    insere_aresta(g, 1, 2, 10);
    insere_aresta(g, 1, 4, 1);
    insere_aresta(g, 1, 5, 3);
    insere_aresta(g, 2, 3, 3);
    insere_aresta(g, 3, 5, 2);
    insere_aresta(g, 2, 5, 1);
    insere_aresta(g, 4, 5, 1);

    printf("\nElementos grafo lista adjacância\n");
    imprime_grafo(g);
    
    remove_aresta(g, 5, 4);
    printf("\nElementos grafo lista adjacância após remoção de aresta\n");
    imprime_grafo(g);

    remove_vertice(g, 2);
    printf("\nElementos grafo lista adjacância após remoção de vertice\n");
    imprime_grafo(g);

    printf("\n\n");
    return 0;
}
