#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "arquivo.c"
#include "grafo.c"

int menu();

int main()
{
    abrir_arquivo_grafo();
    ler_arquivo_grafo();

    // MENU DE INTERAÇÃO
    int opcao, temp1, temp2;
    do
    {
        opcao = menu();
        printf("%d", opcao);
        switch (opcao)
        {

        //
        case 1:
            system("cls");
            imprimir_grafo();
            system("pause > nul");
            break;

        // Imprimir todas as arestas adjacentes a uma aresta a, informada pelo usuário.
        case 2:
            system("cls");
            printf("\n [INFO] Digite a aresta: ");
            scanf("%d", &temp1);
            if (temp1 <= grafo.n_arestas && temp1 > 0)
            {
                aresta_adjacente_aresta(temp1);
            }
            else
            {
                printf("\n [ERROR] A aresta %d nao existe.\n\n", temp1);
            }
            system("pause > nul");
            break;

        // 3. Imprimir todos os vértices adjacentes a um vértice v, informado pelo usuário.
        case 3:
            system("cls");
            printf("\n [INFO] Digite o vertice: ");
            scanf("%d", &temp1);
            if (temp1 <= grafo.n_vertices && temp1 > 0)
            {
                vertices_adjacentes_v(temp1);
            }
            else
            {
                printf("\n [ERROR] O vertice %d nao existe.\n\n", temp1);
            }
            system("pause > nul");
            break;

        // Imprimir todas as arestas incidentes a um vértice v, informado pelo usuário.
        case 4:
            system("cls");
            printf("\n [INFO] Digite o vertice: ");
            scanf("%d", &temp1);
            if (temp1 <= grafo.n_vertices && temp1 > 0)
            {
                arestas_incidentes_v(temp1);
            }
            else
            {
                printf("\n [ERROR] O vertice %d nao existe.\n\n", temp1);
            }
            system("pause > nul");
            break;

        // Imprimir todos os vértices incidentes a uma aresta a, informada pelo usuário.
        case 5:
            system("cls");
            printf("\n [INFO] Digite a aresta: ");
            scanf("%d", &temp1);
            if (temp1 <= grafo.n_arestas && temp1 > 0)
            {
                vertices_incidentes_a(temp1);
            }
            else
            {
                printf("\n [ERROR] A aresta %d nao existe.\n\n", temp1);
            }
            system("pause > nul");
            break;

        // Imprimir o grau do vértice v, informado pelo usuário.
        case 6:
            system("cls");
            printf("\n [INFO] Digite o vertice: ");
            scanf("%d", &temp1);
            if (temp1 <= grafo.n_vertices && temp1 > 0)
            {
                temp2 = grau_v(temp1);
                printf("\n [INFO] O vertice %d possui grau %d.\n\n", temp1, temp2);
            }
            else
            {
                printf("\n [ERROR] O vertice %d nao existe.\n\n", temp1);
            }
            system("pause > nul");
            break;
        
        // Determinar se dois vértices são adjacentes.
        case 7:
            system("cls");
            printf("\n [INFO] Digite o vertice 1: ");
            scanf("%d", &temp1);
            printf("\n [INFO] Digite o vertice 2: ");
            scanf("%d", &temp2);
            if (temp1 <= grafo.n_vertices && temp1 > 0 && temp2 <= grafo.n_vertices && temp2 > 0)
            {
                v_adjacente_v(temp1, temp2);
            }
            else
            {
                printf("\n [ERROR] O/s vertices %d e/ou %d nao existem/existe.\n\n", temp1, temp2);
            }
            system("pause > nul");
            break;

        // Substituir o peso de uma aresta a, informada pelo usuário.
        case 8:
            system("cls");
            printf("\n [INFO] Digite a aresta: ");
            scanf("%d", &temp1);
            if (temp1 <= grafo.n_arestas && temp1 > 0)
            {
                printf("\n [INFO] Digite o novo peso: ");
                scanf("%d", &temp2);
                if (temp2 > 0)
                {
                    substituir_peso_a(temp1, temp2);
                    printf("\n [INFO] O peso da aresta %d foi substituido por %d.\n\n", temp1, temp2);
                }
                else
                {
                    printf("\n [ERROR] O peso deve ser positivo.\n\n");
                }
            }
            else
            {
                printf("\n [ERROR] A aresta %d nao existe.\n\n", temp1);
            }
            system("pause > nul");
            break;

        // Trocar dois vértices.
        case 9:
            system("cls");
            printf("\n [INFO] Digite o vertice 1: ");
            scanf("%d", &temp1);
            printf("\n [INFO] Digite o vertice 2: ");
            scanf("%d", &temp2);
            if (temp1 <= grafo.n_vertices && temp1 > 0 && temp2 <= grafo.n_vertices && temp2 > 0)
            {
                trocar_posicao_v(temp1, temp2);
                printf("\n [INFO] Os vertices de %d e %d e seus adjacentes foram trocados.\n\n", temp1, temp2);
            }
            else
            {
                printf("\n [ERROR] O/s vertices %d e/ou %d nao existem/existe.\n\n", temp1, temp2);
            }
            system("pause > nul");
            break;

        // Dijkstra
        case 10:
            system("cls");
            printf("\n [INFO] Digite o vertice de origem: ");
            scanf("%d", &temp1);
            if (temp1 <= grafo.n_vertices && temp1 > 0)
            {
                dijkstra(temp1);
            }
            else
            {
                printf("\n [ERROR] O vertice %d nao existe.\n\n", temp1);
            }
            system("pause > nul");
            break;

        // Busca em largura.
        case 11:
            system("cls");
            printf("\n [INFO] Digite o vertice de origem: ");
            scanf("%d", &temp1);
            if (temp1 <= grafo.n_vertices && temp1 > 0)
            {
                busca_em_largura(temp1);
            }
            else
            {
                printf("\n [ERROR] O vertice %d nao existe.\n\n", temp1);
            }
            break;            

        // Busca em profundidade
        case 12:
            system("cls");
            printf("\n [INFO] Digite o vertice: ");
            scanf("%d", &temp1);
            if (temp1 <= grafo.n_vertices && temp1 > 0)
            {
                busca_em_profundidade(temp1);
            }
            else
            {
                printf("\n [ERROR] O vertice %d nao existe.\n\n", temp1);
            }
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
        printf("\n [INFO] Menu:\n\n");
        printf(" [1] Imprimir o grafo\n");
        printf(" [2] Imprimir todas as arestas adjacentes a uma aresta a,\n");
        printf(" [3] Imprimir todos os vertices adjacentes a um vertice v\n");
        printf(" [4] Imprimir todas as arestas incidentes a um vertice v\n");
        printf(" [5] Imprimir todos os vertices incidentes a uma aresta a\n");
        printf(" [6] Imprimir o grau do vertice v\n");
        printf(" [7] Determinar se dois vertices sao adjacentes\n");
        printf(" [8] Substituir o peso de uma aresta a\n");
        printf(" [9] Trocar dois vertices\n");
        printf(" [10] [WIP] Algoritmo de Dijkstra\n");
        printf(" [11] [WIP] Busca em largura\n");
        printf(" [12] Busca em profundidade\n");
        printf(" [0] Sair\n");
        printf("\nOpcao: ");
        scanf("%d", &opcao_selecionada);
        system("cls");
    } while (!(opcao_selecionada >= 0 && opcao_selecionada <= 12));

    return opcao_selecionada;
}