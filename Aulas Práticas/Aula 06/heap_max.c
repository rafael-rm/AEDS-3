/*
• Implemente as seguintes funções a cerca de uma fila de prioridade usando
Heap:

• Criação da fila de prioridade com heap máximo;
• Inserção de elementos;
• Remoção do elemento mais prioritário;
• Acesso ao elemento mais prioritário;
• Tamanho/ Cheia / Vazia;
• Liberar a fila de prioridade;
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define TAMANHO 10 // Tamanho da fila de prioridade
#define VAZIO 0
#define TRUE 1
#define FALSE 0

typedef struct palavra
{
    char palavra[30];
    int prioridade;
} s_palavra;

typedef struct fila
{
    s_palavra palavras[TAMANHO];
    int quantidade;
} s_fila;

s_fila *criar_fila();
int inserir_fila(s_fila *fila, s_palavra palavra);
void balancear_inserir(s_fila *fila, int quantidade);
int remover_fila(s_fila *fila, s_palavra *palavra_removida);
void balancear_remover(s_fila *fila, int quantidade);
int acessar_fila(s_fila *fila, s_palavra *palavra_acessada);
int tamanho_fila(s_fila *fila);
int menu();
int fila_cheia(s_fila *fila);
int fila_vazia(s_fila *fila);
int liberar_fila(s_fila *fila);

int main()
{
    s_fila *fila = criar_fila();
    int opcao, status;
    s_palavra temp_palavra;
    do
    {
        opcao = menu();
        printf("%d", opcao);
        switch (opcao)
        {

        // Inserir fila
        case 1:
            system("cls");
            printf("\nInsira a palavra que deseja inserir na fila de prioridade: ");
            scanf("%s", temp_palavra.palavra);
            printf("\nInsira a prioridade da palavra: ");
            scanf("%d", &temp_palavra.prioridade);
            status = inserir_fila(fila, temp_palavra);
            break;

        // Acessar fila
        case 2:
            system("cls");
            status = acessar_fila(fila, &temp_palavra);
            if (status == TRUE)
                printf("\nA palavra acessada e %s, sua prioridade e %d\n", temp_palavra.palavra, temp_palavra.prioridade);
            else
                printf("\nErro ao acessar fila!\n");
            system("pause > nul");
            break;

        // Remover fila
        case 3:
            system("cls");
            status = remover_fila(fila, &temp_palavra);
            if (status == TRUE)
            printf("A palavra %s foi removida, sua prioridade era %d\n", temp_palavra.palavra, temp_palavra.prioridade);
            else
                printf("Erro ao remover fila de prioridade\n");
            system("pause > nul");
            break;
        
        // Liberar fila de prioridade
        case 4:
            system("cls");
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
        printf("\n [1] Inserir elemento na fila de prioridade\n");
        printf(" [2] Buscar elemento na fila de prioridade\n");
        printf(" [3] Remover elemento da fila de prioridade\n");
        printf(" [4] Liberar fila de prioridade\n");
        printf(" [0] Sair\n");
        printf("\nOpcao: ");
        scanf("%d", &opcao_selecionada);
        system("cls");
    } while (!(opcao_selecionada >= 0 && opcao_selecionada <= 4));

    return opcao_selecionada;
}

s_fila *criar_fila(){
    s_fila *fila = (s_fila *)malloc(sizeof(s_fila));
    fila->quantidade = 0;
    return fila;
}

int inserir_fila(s_fila *fila, s_palavra palavra){
    if (fila_cheia(fila))
        return FALSE;
    fila->palavras[fila->quantidade] = palavra;
    fila->quantidade++;
    balancear_inserir(fila, fila->quantidade);
    return TRUE;
}

void balancear_inserir(s_fila *fila, int quantidade){
    int i = quantidade - 1;
    while (i > 0 && fila->palavras[i].prioridade > fila->palavras[(i - 1) / 2].prioridade)
    {
        s_palavra temp = fila->palavras[i];
        fila->palavras[i] = fila->palavras[(i - 1) / 2];
        fila->palavras[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

int remover_fila(s_fila *fila, s_palavra *palavra_removida){
    if (fila_vazia(fila))
        return FALSE;
    *palavra_removida = fila->palavras[0];
    fila->palavras[0] = fila->palavras[fila->quantidade - 1];
    fila->quantidade--;
    balancear_remover(fila, fila->quantidade);
    return TRUE;
}

void balancear_remover(s_fila *fila, int quantidade){
    int i = 0;
    while (2 * i + 1 < quantidade)
    {
        int maior = 2 * i + 1;
        if (2 * i + 2 < quantidade && fila->palavras[2 * i + 2].prioridade > fila->palavras[2 * i + 1].prioridade)
        {
            maior = 2 * i + 2;
        }
        if (fila->palavras[i].prioridade < fila->palavras[maior].prioridade)
        {
            s_palavra temp = fila->palavras[i];
            fila->palavras[i] = fila->palavras[maior];
            fila->palavras[maior] = temp;
            i = maior;
        }
        else
        {
            break;
        }
    }
}

int fila_vazia(s_fila *fila){
    return fila->quantidade == 0;
}

int fila_cheia(s_fila *fila){
    return fila->quantidade == TAMANHO;
}

int liberar_fila(s_fila *fila){
    free(fila);
    return TRUE;
}

int acessar_fila(s_fila *fila, s_palavra *palavra_acessada){
    if (fila_vazia(fila))
        return FALSE;
    *palavra_acessada = fila->palavras[0];
    return TRUE;
}

