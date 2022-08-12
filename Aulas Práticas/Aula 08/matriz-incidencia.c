// Criar matriz de incidencia

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct grafo
{
    int **matriz;
    int vertices;
    int arestas;
} s_grafo;

int menu();
s_grafo *criar_grafo(int vertices, int aresta);
int inserir_elemento(s_grafo *grafo, int v1, int v2);
void imprimir_grafo(s_grafo *grafo);
int remover_elemento(s_grafo *grafo, int v1, int v2);

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

        // Criar matriz de incidencia
        case 1:
            system("cls");
            printf("Digite o numero de vertices: ");
            scanf("%d", &temp);
            printf("Digite o numero de arestas: ");
            scanf("%d", &temp2);
            grafo = criar_grafo(temp, temp2);
            system("pause > nul");
            break;

        // Inserir elemento
        case 2:
            system("cls");
            printf("Digite o vertice: ");
            scanf("%d", &temp);
            printf("Digite a aresta: ");
            scanf("%d", &temp2);

            status = inserir_elemento(grafo, temp, temp2);
            if (status == TRUE)
            {
                printf("Elemento inserido com sucesso!\n");
            }
            else
            {
                printf("Erro ao inserir elemento!\n");
            }
            system("pause > nul");
            break;

        // Remover elemento
        case 3:
            system("cls");
            printf("Digite o vertice: ");
            scanf("%d", &temp);
            printf("Digite a aresta: ");
            status = remover_elemento(grafo, temp, temp2);
            if (status == TRUE)
            {
                printf("Elemento removido com sucesso!\n");
            }
            else
            {
                printf("Erro ao remover elemento!\n");
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
        printf("\n [1] Criar a matriz de incidencia\n");
        printf(" [2] Inserir elemento\n");
        printf(" [3] Remover elemento\n");
        printf(" [4] Imprimir grafo\n");
        printf(" [0] Sair\n");
        printf("\nOpcao: ");
        scanf("%d", &opcao_selecionada);
        system("cls");
    } while (!(opcao_selecionada >= 0 && opcao_selecionada <= 4));

    return opcao_selecionada;
}

s_grafo *criar_grafo(int vertices, int arestas){
    s_grafo *grafo = (s_grafo *)malloc(sizeof(s_grafo));
    grafo->vertices = vertices;
    grafo->arestas = arestas;
    grafo->matriz = (int **)malloc(sizeof(int *) * vertices);
    for (int i = 0; i < vertices; i++)
    {
        grafo->matriz[i] = (int *)malloc(sizeof(int) * arestas);
    }
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < arestas; j++)
        {
            grafo->matriz[i][j] = 0;
        }
    }
    return grafo;
}

int inserir_elemento(s_grafo *grafo, int v1, int v2){
    if (v1 >= grafo->vertices || v2 >= grafo->vertices)
    {
        return FALSE;
    }
    grafo->matriz[v1][v2] = 1;
    return TRUE;
}

void imprimir_grafo(s_grafo *grafo)
{
    printf("\n  X  ");
    for(int i = 0; i < grafo->arestas; i++){
        printf("%d ", i);
    }    
    printf("\n\n");
    for (int i = 0; i < grafo->vertices; i++)
    {
        printf("  %d  ", i);
        for (int j = 0; j < grafo->arestas; j++)
        {
            printf("%d ", grafo->matriz[i][j]);
        }
        printf("\n");
    }
}

int remover_elemento(s_grafo *grafo, int v1, int v2)
{
    if (v1 >= grafo->vertices || v2 >= grafo->vertices)
    {
        return FALSE;
    }
    grafo->matriz[v1][v2] = 0;
    return TRUE;
}