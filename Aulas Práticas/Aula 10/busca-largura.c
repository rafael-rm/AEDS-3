#include <stdio.h>
#include <stdlib.h>

#define R 0
#define S 1
#define T 2
#define U 3
#define V 4
#define W 5
#define X 6
#define Y 7

typedef struct grafo
{
    int nro_vertices;
    int grau_max;
    int **arestas;
    float **pesos;
    int *grau;
} s_grafo;

s_grafo *criar_grafo(int nro_vert, int grau_max);
void liberar_grafo(s_grafo *g);
int inserir_aresta(s_grafo *g, int orig, int dest, int digrafo);
void imprimir_grafo(s_grafo *g);
void busca_largura(s_grafo *g, int ini, int *visitado);

int main()
{

    s_grafo *g = criar_grafo(10, 3);

    inserir_aresta(g, U, Y, 1);
    inserir_aresta(g, U, X, 1);
    inserir_aresta(g, U, T, 1);
    inserir_aresta(g, Y, X, 1);
    inserir_aresta(g, T, X, 1);
    inserir_aresta(g, T, W, 1);
    inserir_aresta(g, X, W, 1);
    inserir_aresta(g, W, S, 1);
    inserir_aresta(g, S, R, 1);
    inserir_aresta(g, R, V, 1);

    int visitados[10];

    busca_largura(g, U, visitados);

    for (int i = 0; i < 10; i++)
    {
        char nome[8] = {'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y'};

        printf("Valores visitados: %c\n", nome[visitados[i]]);
    }

    imprimir_grafo(g);

    liberar_grafo(g);

    return 0;
}

s_grafo *criar_grafo(int nro_vert, int grau_max)
{
    s_grafo *g = (s_grafo *)malloc(sizeof(s_grafo));
    if (g)
    {
        g->nro_vertices = nro_vert;
        g->grau_max = grau_max;
        g->grau = (int *)calloc(nro_vert, sizeof(int));
        g->arestas = (int **)malloc(nro_vert * sizeof(int *));
        for (int i = 0; i < nro_vert; i++)
        {
            g->arestas[i] = (int *)malloc(grau_max * sizeof(int));
            for (int j = 0; j < grau_max; j++)
                g->arestas[i][j] = -1;
        }
    }
    return g;
}

void liberar_grafo(s_grafo *g)
{
    if (g)
    {
        int i;
        for (i = 0; i < g->nro_vertices; i++)
            free(g->arestas[i]);
        free(g->arestas);

        free(g->grau);
        free(g);
    }
}

int inserir_aresta(s_grafo *g, int orig, int dest, int digrafo)
{
    if (!g)
        return 0;
    if (orig < 0 || orig >= g->nro_vertices)
        return 0;
    if (dest < 0 || dest >= g->nro_vertices)
        return 0;

    g->arestas[orig][g->grau[orig]] = dest;
    g->grau[orig]++;

    if (digrafo == 1)
        inserir_aresta(g, dest, orig, 0);

    return 1;
}

void imprimir_grafo(s_grafo *g)
{
    printf("Arestas:\n");
    char nome[8] = {'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y'};

    for (int i = 0; i < g->nro_vertices; i++)
    {
        for (int j = 0; j < g->grau[i]; j++)
        {
            if (g->arestas[i][j] != -1)
                printf("%c -> %c\n", nome[i], nome[g->arestas[i][j]]);
        }
    }
}

void busca_largura(s_grafo *g, int ini, int *visitado)
{
    int i, vert, NV, cont = 1, *fila, IF = 0, FF = 0;
    for (i = 0; i < g->nro_vertices; i++)
        visitado[i] = 0;

    NV = g->nro_vertices;
    fila = (int *)malloc(NV * sizeof(int));
    FF++;
    fila[FF] = ini;
    visitado[ini] = cont;
    while (IF != FF)
    {
        IF = (IF + 1) % NV;
        vert = fila[IF];
        cont++;

        for (i = 0; i < g->grau[vert]; i++)
        {
            if (!visitado[g->arestas[vert][i]])
            {
                FF = (FF + 1) % NV;
                fila[FF] = g->arestas[vert][i];
                visitado[g->arestas[vert][i]] = cont;
            }
        }
    }
    free(fila);
}