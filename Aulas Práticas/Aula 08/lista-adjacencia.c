// Criar matriz por lista

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    int vertice;
    struct no *prox;
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

        // Inserir aresta
        case 2:
            system("cls");
            printf("Digite o vertice: ");
            scanf("%d", &temp);
            printf("Digite a aresta: ");
            scanf("%d", &temp2);
            inserir_aresta(temp, temp2);
            system("pause > nul");
            break;

        // Remover aresta
        case 3:
            system("cls");
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
    s_grafo grafo;
    grafo.n_vertices = n_vertices;
    grafo.n_arestas = 0;
    grafo.adj = (s_no **) malloc(n_vertices * sizeof(s_no *));
    for(int i = 0; i < n_vertices; i++){
        grafo.adj[i] = NULL;
    }
    return grafo;
}

void inserir_aresta(int v1, int v2){
    s_no *novo = (s_no *) malloc(sizeof(s_no));
    novo->vertice = v2;
    novo->prox = grafo.adj[v1];
    grafo.adj[v1] = novo;
    grafo.n_arestas++;
}

void imprimir_grafo(){
    for(int i = 0; i < grafo.n_vertices; i++){
        s_no *aux = grafo.adj[i];
        printf("%d: ", i);
        while(aux != NULL){
            printf("%d ", aux->vertice);
            aux = aux->prox;
        }
        printf("\n");
    }
}

s_grafo liberar_grafo(){
    for(int i = 0; i < grafo.n_vertices; i++){
        s_no *aux = grafo.adj[i];
        while(aux != NULL){
            s_no *aux2 = aux;
            aux = aux->prox;
            free(aux2);
        }
    }
    free(grafo.adj);
    return grafo;
}



