#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define FALSE 0
#define TRUE 1

struct node
{
    char *palavra;
    int repeticao;
    struct node *esquerda;
    struct node *direita;
};

typedef struct node s_node;

int menu();
s_node *criar_arvore();
s_node *inserir_elemento(s_node *raiz, char palavra[]);
//s_node *remover_elemento(s_node *raiz, char palavra[]);
s_node *rotacao_esquerda(s_node *raiz);
s_node *rotacao_direita(s_node *raiz);
s_node *rotacao_dupla_esquerda(s_node *raiz);
s_node *rotacao_dupla_direita(s_node *raiz);
s_node *balancear_arvore(s_node *raiz);
int buscar_elemento(s_node *raiz, char palavra[]);
int altura_arvore(s_node *raiz);
int fator_balanceamento(s_node *raiz);
void imprimir_in_ordem(s_node *raiz);
//void imprimir_pre_ordem(s_node *raiz);
//void imprimir_pos_ordem(s_node *raiz);

int main()
{
    s_node *raiz = criar_arvore();
    int opcao, temp_int;
    char temp_char[30];
    do
    {
        opcao = menu();
        printf("%d", opcao);
        switch (opcao)
        {

        // Inserir
        case 1:
            system("cls");
            printf("\nInsira a palavra que deseja inserir na arvore: ");
            setbuf(stdin, NULL);
            gets(temp_char);
            raiz = inserir_elemento(raiz, temp_char);
            raiz = balancear_arvore(raiz);
            break;

        // Buscar elemento
        case 2:
            system("cls");
            printf("\nInsira a palavra que deseja buscar na arvore: ");
            setbuf(stdin, NULL);
            gets(temp_char);
            temp_int = buscar_elemento(raiz, temp_char);
            if (temp_int == TRUE)
                printf("\nA palavra foi encontrada!");
            else
                printf("\nA palavra nao foi encontrada!");
            system("pause > nul");
            break;

        // Remover
        case 3:
            system("cls");
            printf("\nInsira a palavra que deseja remover da arvore: ");
            setbuf(stdin, NULL);
            gets(temp_char);
            //raiz = remover_elemento(raiz, temp_char);
            break;

        // Imprimir arvore pre ordem
        case 4:
            system("cls");
            printf("\nImprimindo arvore in ordem...\n");
            imprimir_in_ordem(raiz);
            system("pause > nul");
            break;
        }

    } while ((opcao != 0));
    system("cls");
    // liberar_arvore(raiz);
    return 0;
}

int menu()
{
    int opcao_selecionada;
    do
    {
        system("cls");
        printf("\n [1] Inserir elemento na arvore\n");
        printf(" [2] Buscar elemento na arvore\n");
        printf(" [3] Remover elemento na arvore\n");
        printf(" [4] Imprimir arvore (pre ordem)\n");
        printf(" [5] Imprimir arvore (in ordem)\n");
        printf(" [6] Imprimir arvore (pos ordem)\n");
        printf(" [7] Altura da arvore\n");
        printf(" [0] Sair\n");
        printf("\nOpcao: ");
        scanf("%d", &opcao_selecionada);
        system("cls");
    } while (!(opcao_selecionada >= 0 && opcao_selecionada <= 7));

    return opcao_selecionada;
}

s_node *criar_arvore()
{
    return NULL;
}

int altura_arvore(s_node *raiz)
{
    if (raiz == NULL)
        return 0;
    else
    {
        int altura_esquerda = altura_arvore(raiz->esquerda);
        int altura_direita = altura_arvore(raiz->direita);
        if (altura_esquerda > altura_direita)
            return altura_esquerda + 1;
        else
            return altura_direita + 1;
    }
}

int fator_balanceamento(s_node *raiz)
{
    if (raiz == NULL)
        return 0;
    else
    {
        int fator_esquerda = fator_balanceamento(raiz->esquerda);
        int fator_direita = fator_balanceamento(raiz->direita);
        return fator_esquerda - fator_direita;
    }
}

s_node *balancear_arvore(s_node *raiz)
{
    if (raiz == NULL)
        return NULL;
    else
    {
        raiz->esquerda = balancear_arvore(raiz->esquerda);
        raiz->direita = balancear_arvore(raiz->direita);
        int balanceamento = fator_balanceamento(raiz);
        if (balanceamento > 1)
        {
            if (balanceamento > 2)
            {
                if (balanceamento > 0)
                    raiz = rotacao_esquerda(raiz);
                else
                    raiz = rotacao_dupla_esquerda(raiz);
            }
            else
                raiz = rotacao_esquerda(raiz);
        }
        else if (balanceamento < -1)
        {
            if (balanceamento < -2)
            {
                if (balanceamento < 0)
                    raiz = rotacao_direita(raiz);
                else
                    raiz = rotacao_dupla_direita(raiz);
            }
            else
                raiz = rotacao_direita(raiz);
        }
        return raiz;
    }
}

s_node *inserir_elemento(s_node *raiz, char *palavra)
{
    if (raiz == NULL)
    {
        raiz = (s_node *)malloc(sizeof(s_node));
        raiz->palavra = (char *)malloc(sizeof(char) * 30);
        strcpy(raiz->palavra, palavra);
        raiz->esquerda = NULL;
        raiz->direita = NULL;
        return raiz;
    }
    else
    {
        if (strcmp(palavra, raiz->palavra) < 0)
            raiz->esquerda = inserir_elemento(raiz->esquerda, palavra);
        else if (strcmp(palavra, raiz->palavra) > 0)
            raiz->direita = inserir_elemento(raiz->direita, palavra);
        else
            raiz->repeticao++;
        return raiz;
    }
}

int buscar_elemento(s_node *raiz, char *palavra)
{
    if (raiz == NULL)
        return 0;
    else
    {
        if (strcmp(palavra, raiz->palavra) < 0)
            return buscar_elemento(raiz->esquerda, palavra);
        else if (strcmp(palavra, raiz->palavra) > 0)
            return buscar_elemento(raiz->direita, palavra);
        else
            return 1;
    }
}

s_node *rotacao_direita(s_node *raiz)
{
    s_node *aux = raiz->esquerda;
    raiz->esquerda = aux->direita;
    aux->direita = raiz;
    return aux;
}

s_node *rotacao_dupla_direita(s_node *raiz)
{
    raiz->direita = rotacao_esquerda(raiz->direita);
    return rotacao_direita(raiz);
}

s_node *rotacao_esquerda(s_node *raiz)
{
    s_node *aux = raiz->direita;
    raiz->direita = aux->esquerda;
    aux->esquerda = raiz;
    return aux;
}

s_node *rotacao_dupla_esquerda(s_node *raiz)
{
    raiz->esquerda = rotacao_direita(raiz->esquerda);
    return rotacao_esquerda(raiz);
}

void imprimir_in_ordem(s_node *raiz)
{
    if (raiz != NULL)
    {
        imprimir_in_ordem(raiz->esquerda);
        printf("%s\n", raiz->palavra);
        imprimir_in_ordem(raiz->direita);
    }
    return raiz;
}
