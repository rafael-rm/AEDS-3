#include "arquivo.h"
#include "grafo.h"

void abrir_arquivo_grafo() // Abre o texto original
{
    arquivo_grafo = fopen(ARQUIVO_GRAFO, "r"); // Abre o arquivo de texto DEFAULT
    if (arquivo_grafo == NULL)
    {
        printf("\n [ERROR] Erro ao abrir arquivo \"%s\", processo encerrado.\n\n", ARQUIVO_GRAFO);
        system("pause > nul");
        exit(1);
    }
}

void ler_arquivo_grafo(){
    int n_vertices, n_arestas, v1, v2, peso;
    fscanf(arquivo_grafo, "%d %d", &n_vertices, &n_arestas);
    grafo = inicializa_grafo(n_vertices, n_arestas);
    for (int i = 1; i <= n_arestas; i++)
    {
        fscanf(arquivo_grafo, "%d %d %d", &v1, &v2, &peso);
        inserir_aresta(v1, v2, peso);
    }
    printf("\n [INFO] Grafo lido com sucesso.\n\n");
}

