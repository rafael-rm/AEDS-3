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
s_node *rotacao_esquerda(s_node *raiz);
s_node *rotacao_direita(s_node *raiz);
s_node *rotacao_dupla_esquerda(s_node *raiz);
s_node *rotacao_dupla_direita(s_node *raiz);
s_node *balancear_arvore(s_node *raiz);

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
            raiz = balancear_arvore(raiz);
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
                printf("\nO valor %d nao foi encontrado na arvore.\n", temp);
            }
            else if (status == TRUE)
            {
                system("cls");
                printf("\nO valor %d foi encontrado na arvore.\n", temp);
            }
            system("pause > nul");
            break;

        // Remover
        case 3:
            system("cls");
            printf("\nInsira o valor que deseja remover da arvore: ");
            scanf("%d", &temp);
            raiz = remover_elemento(raiz, temp);
            raiz = balancear_arvore(raiz);
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
    if (raiz == NULL)
    {
        raiz = (s_node *)malloc(sizeof(s_node));
        raiz->valor = valor;
        raiz->esquerda = NULL;
        raiz->direita = NULL;
    }
    else if (valor < raiz->valor)
    {
        raiz->esquerda = inserir_elemento(raiz->esquerda, valor);
    }
    else if (valor > raiz->valor)
    {
        raiz->direita = inserir_elemento(raiz->direita, valor);
    }
    else
    {
        printf("\nO valor %d ja existe na arvore.\n", valor);
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

s_node *remover_elemento(s_node *raiz, int valor){
    if (raiz == NULL)
    {
        return raiz;
    }
    else if (valor < raiz->valor)
    {
        raiz->esquerda = remover_elemento(raiz->esquerda, valor);
    }
    else if (valor > raiz->valor)
    {
        raiz->direita = remover_elemento(raiz->direita, valor);
    }
    else
    {
        if (raiz->esquerda == NULL && raiz->direita == NULL)
        {
            free(raiz);
            raiz = NULL;
        }
        else if (raiz->esquerda == NULL)
        {
            s_node *aux = raiz;
            raiz = raiz->direita;
            free(aux);
        }
        else if (raiz->direita == NULL)
        {
            s_node *aux = raiz;
            raiz = raiz->esquerda;
            free(aux);
        }
        else
        {
            s_node *aux = raiz->direita;
            while (aux->esquerda != NULL)
            {
                aux = aux->esquerda;
            }
            raiz->valor = aux->valor;
            raiz->direita = remover_elemento(raiz->direita, aux->valor);
        }
    }
    return raiz;
}

s_node *rotacao_direita(s_node *raiz)
{
    s_node *temp = raiz->esquerda;
    raiz->esquerda = temp->direita;
    temp->direita = raiz;
    return temp;
}

s_node *rotacao_direita_dupla(s_node *raiz)
{
    raiz->esquerda = rotacao_esquerda(raiz->esquerda);
    return rotacao_direita(raiz);
}

s_node *rotacao_esquerda(s_node *raiz)
{
    s_node *temp = raiz->direita;
    raiz->direita = temp->esquerda;
    temp->esquerda = raiz;
    return temp;
}

s_node *rotacao_esquerda_dupla(s_node *raiz)
{
    raiz->direita = rotacao_direita(raiz->direita);
    return rotacao_esquerda(raiz);
}

s_node *balancear_arvore(s_node *raiz)
{
    if (raiz == NULL)
    {
        return raiz;
    }
    else if (altura_arvore(raiz->esquerda) - altura_arvore(raiz->direita) > 1)
    {
        if (altura_arvore(raiz->esquerda->esquerda) >= altura_arvore(raiz->esquerda->direita))
        {
            raiz = rotacao_direita(raiz);
        }
        else
        {
            raiz = rotacao_direita_dupla(raiz);
        }
    }
    else if (altura_arvore(raiz->direita) - altura_arvore(raiz->esquerda) > 1)
    {
        if (altura_arvore(raiz->direita->direita) >= altura_arvore(raiz->direita->esquerda))
        {
            raiz = rotacao_esquerda(raiz);
        }
        else
        {
            raiz = rotacao_esquerda_dupla(raiz);
        }
    }
    raiz->esquerda = balancear_arvore(raiz->esquerda);
    raiz->direita = balancear_arvore(raiz->direita);
    return raiz;
}

