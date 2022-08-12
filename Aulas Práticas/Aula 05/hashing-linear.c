/*
• Crie uma TAD para representar uma Tabela Hash. Use Endereçamento
Aberto com Hash Linear para efetuar o tratamento de colisões;
• a) Crie uma função para criar uma Tabela Hash; 
• b) Crie uma função para efetuar inserção de elementos na Tabela Hash; 
• c) Crie uma função para efetuar busca de elementos na Tabela Hash; 
• d) Crie uma função para liberar a Tabela Hash; 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAMANHO 7 // Tamanho da tabela hash (precisa ser primo)
#define VAZIO 0
#define TRUE 1
#define FALSE 0

int *criar_tabela_hash(int tamanho);
int inserir_tabela_hash(int tabela[], int tamanho, int valor);
int buscar_tabela_hash(int tabela[], int tamanho, int valor);
int liberar_tabela_hash(int tabela[]);
int menu();

int main()
{
    int *tabela = criar_tabela_hash(TAMANHO);
    int opcao, temp_int, status;
    do
    {
        opcao = menu();
        printf("%d", opcao);
        switch (opcao)
        {

        // Inserir
        case 1:
            system("cls");
            printf("\nInsira o valor que deseja inserir na tabela hash: ");
            scanf("%d", &temp_int);
            status = inserir_tabela_hash(tabela, TAMANHO, temp_int);
            if (status == TRUE)
                printf("Valor inserido com sucesso!\n");
            else
                printf("Erro ao inserir valor!\n");
            system("pause > nul");
            break;

        // Buscar elemento
        case 2:
            system("cls");
            printf("\nInsira o valor que deseja buscar na tabela hash: ");
            scanf("%d", &temp_int);
            status = buscar_tabela_hash(tabela, TAMANHO, temp_int);
            if (status == TRUE)
                printf("Valor encontrado!\n");
            else
                printf("Erro ao buscar valor!\n");
            system("pause > nul");
            break;

        // Liberar
        case 3:
            system("cls");
            printf("\nLiberando tabela hash...\n");
            status = liberar_tabela_hash(tabela);
            if (status == TRUE)
                printf("Tabela hash liberada com sucesso!\n");
            else
                printf("Erro ao liberar tabela hash!\n");
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
        printf("\n [1] Inserir elemento na tabela hash\n");
        printf(" [2] Buscar elemento na tabela hash\n");
        printf(" [3] Liberar tabela hash\n");
        printf(" [0] Sair\n");
        printf("\nOpcao: ");
        scanf("%d", &opcao_selecionada);
        system("cls");
    } while (!(opcao_selecionada >= 0 && opcao_selecionada <= 3));

    return opcao_selecionada;
}

int *criar_tabela_hash(int tamanho)
{
    int *tabela = (int *)malloc(tamanho * sizeof(int));
    for (int i = 0; i < tamanho; i++)
    {
        tabela[i] = VAZIO;
    }
    return tabela;
}

int inserir_tabela_hash(int tabela[], int tamanho, int valor)
{
    int posicao = valor % tamanho; // Posição da tabela hash
    if (tabela[posicao] == VAZIO)
    {
        tabela[posicao] = valor;
        printf("Inserido com sucesso na posicao %d\n", posicao);
        return TRUE;
    }
    else
    {
        printf("Colisao na posicao %d\n", posicao);
        for (int i = 1; i < tamanho; i++)
        {
            posicao = (posicao + i) % tamanho; // Hash Linear
            printf("Tentando na posicao %d\n", posicao);
            if (tabela[posicao] == VAZIO)
            {
                tabela[posicao] = valor;
                printf("Inserido com sucesso na posicao %d\n", posicao);
                return TRUE;
            }
        }
    }
    return FALSE;
}

int buscar_tabela_hash(int tabela[], int tamanho, int valor)
{
    int posicao = valor % tamanho; // Posição da tabela hash
    if (tabela[posicao] == valor)
    {
        printf("Encontrado na posicao %d\n", posicao);
        return TRUE;
    }
    else
    {
        printf("Nao encontrado na posicao %d\n", posicao);
        for (int i = 1; i < tamanho; i++)
        {
            posicao = (posicao + i) % tamanho; // Hash Linear
            printf("Tentando na posicao %d\n", posicao);
            if (tabela[posicao] == valor)
            {
                printf("Encontrado na posicao %d\n", posicao);
                return TRUE;
            }
        }
    }
    return FALSE;
}

int liberar_tabela_hash(int tabela[])
{
    free(tabela);
    return TRUE;
}