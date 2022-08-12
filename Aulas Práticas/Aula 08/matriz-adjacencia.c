// Criar matriz de adjacência

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct grafo
{
    int **matriz;
    int vertices;
    int arestas;
    int tamanho;
} s_grafo;

int menu();
s_grafo *criar_grafo(int vertices);
int inserir_aresta(s_grafo *grafo, int v1, int v2);
void imprimir_grafo(s_grafo *grafo);
int remover_aresta(s_grafo *grafo, int v1, int v2);

s_grafo *grafo;

int main()
{
    int opcao, status, temp, temp2;
    do
    {
        opcao = menu();
        printf("%d", opcao);
        switch (opcao)
        {

        // Criar matriz de adjacência
        case 1:
            system("cls");
            printf("Digite o numero de vertices: ");
            scanf("%d", &temp);
            grafo = criar_grafo(temp);
            system("pause > nul");
            break;

        // Inserir aresta
        case 2:
            system("cls");
            printf("Digite o vertice 1: ");
            scanf("%d", &temp);
            printf("Digite o vertice 2: ");
            scanf("%d", &temp2);
            status = inserir_aresta(grafo, temp, temp2);
            if (status == TRUE)
            {
                printf("Aresta inserida com sucesso!\n");
            }
            else
            {
                printf("Erro ao inserir aresta!\n");
            }
            system("pause > nul");
            break;

        // Remover aresta
        case 3:
            system("cls");
            printf("Digite o vertice 1: ");
            scanf("%d", &temp);
            printf("Digite o vertice 2: ");
            scanf("%d", &temp2);
            status = remover_aresta(grafo, temp, temp2);
            if (status == TRUE)
            {
                printf("Aresta removida com sucesso!\n");
            }
            else
            {
                printf("Erro ao remover aresta!\n");
            }
            system("pause > nul");
            break;

        // Imprimir grafo
        case 4:
            system("cls");
            imprimir_grafo(grafo);
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
        printf("\n [1] Criar a matriz de adjacencia\n");
        printf(" [2] Inserir aresta\n");
        printf(" [3] Remover aresta\n");
        printf(" [4] Imprimir grafo\n");
        printf(" [0] Sair\n");
        printf("\nOpcao: ");
        scanf("%d", &opcao_selecionada);
        system("cls");
    } while (!(opcao_selecionada >= 0 && opcao_selecionada <= 4));

    return opcao_selecionada;
}

s_grafo *criar_grafo(int vertices)
{
    s_grafo *grafo = (s_grafo *)malloc(sizeof(s_grafo));
    grafo->vertices = vertices;
    grafo->arestas = 0;
    grafo->matriz = (int **)malloc(sizeof(int *) * vertices);
    grafo->tamanho = vertices;
    for (int i = 0; i < vertices; i++)
    {
        grafo->matriz[i] = (int *)malloc(sizeof(int) * vertices);
    }
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            grafo->matriz[i][j] = 0;
        }
    }
    return grafo;
}

int inserir_aresta(s_grafo *grafo, int v1, int v2){
    if (v1 < grafo->vertices && v2 < grafo->vertices)
    {
        grafo->matriz[v1][v2] = 1;
        grafo->matriz[v2][v1] = 1;
        grafo->arestas++;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void imprimir_grafo(s_grafo *grafo)
{
    printf("\n  X  ");
    for(int i = 0; i < grafo->tamanho; i++){
        printf("%d ", i);
    }    
    printf("\n\n");
    for (int i = 0; i < grafo->vertices; i++)
    {
        printf("  %d  ", i);
        for (int j = 0; j < grafo->vertices; j++)
        {
            printf("%d ", grafo->matriz[i][j]);
        }
        printf("\n");
    }
}

int remover_aresta(s_grafo *grafo, int v1, int v2)
{
    if (v1 < grafo->vertices && v2 < grafo->vertices)
    {
        grafo->matriz[v1][v2] = 0;
        grafo->matriz[v2][v1] = 0;
        grafo->arestas--;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}