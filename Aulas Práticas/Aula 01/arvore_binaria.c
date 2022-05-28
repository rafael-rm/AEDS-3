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
    int valor;
    struct node *esquerda;
    struct node *direita;
};

typedef struct node s_node;

int menu();
s_node *criar_arvore();
s_node *inserir_elemento(s_node *raiz, int valor);
void imprimir_pre_ordem(s_node *raiz);
void imprimir_in_ordem(s_node *raiz); 
void imprimir_pos_ordem(s_node *raiz);
void liberar_arvore(s_node *raiz);
int buscar_elemento(s_node *raiz, int valor);
int altura_arvore(s_node *raiz);
s_node *remover_elemento(s_node *raiz, int valor);

int main()
{
    s_node *raiz = criar_arvore();
    int opcao, temp, status;
    do
    {
        opcao = menu();
        printf("%d", opcao);
        switch (opcao)
        {

        // Inserir
        case 1:
            system("cls");
            printf("\nInsira o valor que deseja inserir na arvore: ");
            scanf("%d", &temp);
            raiz = inserir_elemento(raiz, temp);
            break;

        // Buscar elemento
        case 2:
            system("cls");
            printf("\nInsira o valor que deseja buscar na arvore: ");
            scanf("%d", &temp);
            status = buscar_elemento(raiz, temp);
            if (status == FALSE)
            {
                system("cls");
                printf("\nO valor nao foi encontrado na arvore.\n");
            }
            else if (status == TRUE)
            {
                system("cls");
                printf("\nO valor foi encontrado na arvore.\n");
            }
            system("pause > nul");
            break;

        // Remover 
        case 3:
            system("cls");
            printf("\nInsira o valor que deseja remover da arvore: ");
            scanf("%d", &temp);
            raiz = remover_elemento(raiz, temp);
            break;

        // Imprimir arvore pre ordem
        case 4:
            system("cls");
            printf("\nImprimindo arvore pre ordem...\n");
            imprimir_pre_ordem(raiz);
            system("pause > nul");
            break;

        // Imprimir arvore in ordem
        case 5:
            system("cls");
            printf("\nImprimindo arvore in ordem...\n");
            imprimir_in_ordem(raiz);
            system("pause > nul");
            break;

        // Imprimir arvore pos ordem
        case 6: 
            system("cls");
            printf("\nImprimindo arvore pos ordem...\n");
            imprimir_pos_ordem(raiz);
            system("pause > nul");
            break;

        // Altura da arvore
        case 7:
            system("cls");
            printf("\nA altura da arvore e: %d\n", altura_arvore(raiz));
            system("pause > nul");
            break;
        }

    } while ((opcao != 0));
    system("cls");
    liberar_arvore(raiz);
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

s_node *inserir_elemento(s_node *raiz, int valor)
{
    if (raiz == NULL) // se a raiz for nula, cria um novo nó
    {
        s_node *temp = (s_node *)malloc(sizeof(s_node)); // aloca um nó
        temp->valor = valor;
        temp->esquerda = NULL; // inicializa os ponteiros
        temp->direita = NULL;  // inicializa os ponteiros
        return temp;
    }
    else if (valor > raiz->valor) // se o valor for maior que o valor da raiz, insere na direita
    {
        raiz->direita = inserir_elemento(raiz->direita, valor);
    }
    else if (valor < raiz->valor) // se o valor for menor que o valor da raiz, insere na esquerda
    {
        raiz->esquerda = inserir_elemento(raiz->esquerda, valor);
    }
    return raiz;
}

int buscar_elemento(s_node *raiz, int valor)
{
    if (raiz == NULL) // se a raiz for nula, não encontrou
    {
        return FALSE;
    }
    else if (valor > raiz->valor) // se o valor for maior que o valor da raiz, busca na direita
    {
        return buscar_elemento(raiz->direita, valor);
    }
    else if (valor < raiz->valor) // se o valor for menor que o valor da raiz, busca na esquerda
    {
        return buscar_elemento(raiz->esquerda, valor);
    }
    else // se o valor for igual ao valor da raiz, encontrou
    {
        return TRUE;
    }
}

void imprimir_pre_ordem(s_node *raiz)
{
    if (raiz != NULL) // se a raiz for diferente de nula
    {
        printf("%d ", raiz->valor);         // imprime o valor
        imprimir_pre_ordem(raiz->esquerda); // imprime a esquerda
        imprimir_pre_ordem(raiz->direita);  // imprime a direita
    }
}

void imprimir_in_ordem(s_node *raiz)
{
    if (raiz != NULL) // se a raiz for diferente de nula
    {
        imprimir_in_ordem(raiz->esquerda); // imprime a esquerda
        printf("%d ", raiz->valor);        // imprime o valor
        imprimir_in_ordem(raiz->direita);  // imprime a direita
    }
}

void imprimir_pos_ordem(s_node *raiz)
{
    if (raiz != NULL) // se a raiz for diferente de nula
    {
        imprimir_pos_ordem(raiz->esquerda); // imprime a esquerda
        imprimir_pos_ordem(raiz->direita);  // imprime a direita
        printf("%d ", raiz->valor);         // imprime o valor
    }
}

void liberar_arvore(s_node *raiz)
{
    if (raiz != NULL)
    {
        liberar_arvore(raiz->esquerda); // libera a esquerda
        liberar_arvore(raiz->direita);  // libera a direita
        free(raiz);                     // libera a raiz
    }
}

int altura_arvore(s_node *raiz)
{
    if (raiz == NULL) // se a raiz for nula, retorna 0
    {
        return 0;
    }
    else // se a raiz não for nula, retorna 1 + a maior altura de suas subarvores
    {
        return 1 + fmax(altura_arvore(raiz->esquerda), altura_arvore(raiz->direita)); // retorna 1 + a maior altura de suas subarvores
    }
}

s_node *remover_elemento(s_node *raiz, int valor)
{
    if (raiz == NULL) // se a raiz for nula, não encontrou
    {
        return NULL;
    }
    else if (valor > raiz->valor) // se o valor for maior que o valor da raiz, busca na direita
    {
        raiz->direita = remover_elemento(raiz->direita, valor);
    }
    else if (valor < raiz->valor) // se o valor for menor que o valor da raiz, busca na esquerda
    {
        raiz->esquerda = remover_elemento(raiz->esquerda, valor);
    }
    else // se o valor for igual ao valor da raiz, encontrou
    {
        if (raiz->esquerda == NULL && raiz->direita == NULL) // se a raiz não tiver filhos
        {
            free(raiz); // libera a raiz
            raiz = NULL;
        }
        else if (raiz->esquerda == NULL) // se a raiz tiver apenas a direita
        {
            s_node *temp = raiz; // guarda a raiz
            raiz = raiz->direita; // a raiz passa a ser a direita
            free(temp);           // libera a raiz antiga
        }
        else if (raiz->direita == NULL) // se a raiz tiver apenas a esquerda
        {
            s_node *temp = raiz; // guarda a raiz
            raiz = raiz->esquerda; // a raiz passa a ser a esquerda
            free(temp);           // libera a raiz antiga
        }
        else // se a raiz tiver os dois filhos
        {
            s_node *temp = raiz->direita; // guarda a direita
            while (temp->esquerda != NULL) // percorre a direita até chegar no fim
            {
                temp = temp->esquerda; // percorre a direita
            }
            raiz->valor = temp->valor; // troca o valor da raiz com o valor da direita
            raiz->direita = remover_elemento(raiz->direita, temp->valor); // remove o valor da direita
        }
    }
    return raiz;
}