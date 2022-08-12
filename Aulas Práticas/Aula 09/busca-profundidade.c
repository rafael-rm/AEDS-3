// Criar matriz por lista

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BRANCO 0
#define CINZA 1
#define PRETO 2

typedef struct no {
    int vertice;
    struct no *prox;
    int tempo_entrada;
    int tempo_saida;
    int cor;
} s_no;

typedef struct grafo{
    s_no **adj;
    int n_vertices;
    int n_arestas;
} s_grafo;

s_grafo grafo;

s_grafo inicializa_grafo(int n_vertices);
void inserir_aresta(int v1, int v2);
void imprimir_grafo();
s_grafo liberar_grafo();
int menu();

int main()
{
    int opcao, status, temp, temp2;
    do
    {
        opcao = menu();
        printf("%d", opcao);
        switch (opcao)
        {

        // Criar lista de adjacência
        case 1:
            system("cls");
            printf("Digite o numero de vertices: ");
            scanf("%d", &temp);
            grafo = inicializa_grafo(temp);
            system("pause > nul");
            break;

        // Inserir aresta
        case 2:
            system("cls");
            printf("Digite o vertice 1: ");
            scanf("%d", &temp);
            printf("Digite o vertice 2: ");
            scanf("%d", &temp2);
            inserir_aresta(temp, temp2);
            system("pause > nul");
            break;

        // DFS
        case 3:
            system("cls");
            printf("Digite o vertice de origem: ");
            scanf("%d", &temp);
            temp2= dfs_visita(grafo, temp);
            printf("Tempo de execucao: %d", temp2);
            system("pause > nul");
            break;

        // Imprimir grafo
        case 4:
            system("cls");
            imprimir_grafo();
            system("pause > nul");
            break;
        }

    } while ((opcao != 0));
    system("cls");
    return 0;
}

int menu()
{
    int opcao_selecionada;
    do
    {
        system("cls");
        printf("\n [1] Criar a lista de adjacencia\n");
        printf(" [2] Inserir aresta/vertice\n");
        printf(" [3] XXXXXX\n");
        printf(" [4] Imprimir grafo\n");
        printf(" [0] Sair\n");
        printf("\nOpcao: ");
        scanf("%d", &opcao_selecionada);
        system("cls");
    } while (!(opcao_selecionada >= 0 && opcao_selecionada <= 4));

    return opcao_selecionada;
}

s_grafo inicializa_grafo(int n_vertices){
    int i;
    s_grafo grafo;
    grafo.n_vertices = n_vertices;
    grafo.n_arestas = 0;
    grafo.adj = (s_no **)malloc(n_vertices * sizeof(s_no *));
    for (i = 0; i < n_vertices; i++)
    {
        grafo.adj[i] = NULL;
    }
    return grafo;
}

void inserir_aresta(int v1, int v2){
    s_no *no = (s_no *)malloc(sizeof(s_no));
    no->vertice = v2;
    no->prox = grafo.adj[v1];
    no->tempo_entrada = 0;
    no->tempo_saida = 0;
    grafo.adj[v1] = no;
    grafo.n_arestas++;
}

void imprimir_grafo(){
    int i;
    s_no *no;
    for (i = 0; i < grafo.n_vertices; i++)
    {
        no = grafo.adj[i];
        printf("%d: ", i);
        while (no != NULL)
        {
            printf("%d ", no->vertice);
            no = no->prox;
        }
        printf("\n");
    }
}

s_grafo liberar_grafo(){
    int i;
    s_no *no, *aux;
    for (i = 0; i < grafo.n_vertices; i++)
    {
        no = grafo.adj[i];
        while (no != NULL)
        {
            aux = no;
            no = no->prox;
            free(aux);
        }
    }
    free(grafo.adj);
    return grafo;
}

void dfs(s_grafo grafo, int v, int *tempo){
    s_no *no = grafo.adj[v];
    no->tempo_entrada = *tempo;
    no->cor = CINZA;
    while (no != NULL)
    {
        if (grafo.adj[no->vertice]->cor == BRANCO)
        {
            dfs(grafo, no->vertice, tempo);
        }
        no = no->prox;
    }
    grafo.adj[v]->tempo_saida = *tempo;
    grafo.adj[v]->cor = PRETO;
    *tempo = *tempo + 1;
}

int dfs_visita(s_grafo grafo, int v){
    int tempo = 0;
    int i;
    for (i = 0; i < grafo.n_vertices; i++)
    {
        grafo.adj[i]->cor = BRANCO;
    }
    dfs(grafo, v, &tempo);
    return tempo;
}
