#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "arvore_avl_string.c"
#include "fila_de_prioridade.c"
#include "arquivo.c"
#include "logs.c"

int menu();
s_node *remover_avl_inserir_fila_p(s_node *raiz);

int main()
{
    iniciar_logs();
    tratar_arquivo();
    raiz = criar_arvore();
    ler_arquivo_tratado_inserir_avl();
    imprimir_in_ordem(raiz);
    system("pause > nul");
    fila = criar_fila();
    raiz = remover_avl_inserir_fila_p(raiz);
    system("pause > nul");

    s_palavra temp_palavra;
    int opcao, status;
    do
    {
        opcao = menu();
        printf("%d", opcao);
        switch (opcao)
        {

        // Acessar fila
        case 1:
            system("cls");
            status = acessar_fila(fila, &temp_palavra);
            if (status == TRUE)
            {
                logs_fila_acessada(temp_palavra);
            }
            else
            {
                printf("\nErro ao acessar fila!\n");
            }
            system("pause > nul");
            break;

        // Remover fila
        case 2:
            system("cls");
            status = remover_fila(fila, &temp_palavra);
            if (status == TRUE)
            {
                logs_fila_removida(temp_palavra);
            }
            else
            {
                printf("Erro ao remover fila de prioridade\n");
            }
            system("pause > nul");
            break;

        // Tamanho da fila
        case 3:
            system("cls");
            printf("Tamanho atual da fila: %d\n", fila->quantidade);
            status = acessar_fila(fila, &temp_palavra);
            printf("Proxima palavra a ser removida: \"%s\" - (%d)\n", temp_palavra.palavra, temp_palavra.prioridade);
            system("pause > nul");
            break;

        // Criar arquivo do vetor atual da fila de prioridade
        case 4:
            system("cls");
            criar_arquivo_fila_atual(fila);
            printf("Arquivo criado com sucesso!\n");
            system("pause > nul");
            break;
        }

    } while ((opcao != 0));
    system("cls");
    fclose(arquivo_log);
    liberar_fila(fila);
    printf("Programa finalizado com sucesso!");
    return 0;
}

int menu()
{
    int opcao_selecionada;
    do
    {
        system("cls");
        printf("\n [1] Acessar primeiro elemento da fila.\n");
        printf(" [2] Remover primeiro elemento da fila.\n");
        printf(" [3] Tamanho da fila.\n");
        printf(" [4] Criar arquivo da fila de prioridade atual.\n");
        printf(" [0] Sair\n");
        printf("\nOpcao: ");
        scanf("%d", &opcao_selecionada);
        system("cls");
    } while (!(opcao_selecionada >= 0 && opcao_selecionada <= 4));

    return opcao_selecionada;
}

s_node *remover_avl_inserir_fila_p(s_node *raiz) // Remove todos elementos da arvore AVL e insere na fila de prioridade max-heap
{
    // Esta função tem como base a função de apagar a arvore AVL, resolvendo 2 problemas de uma só vez.
    if (raiz != NULL)
    {
        remover_avl_inserir_fila_p(raiz->esquerda);
        remover_avl_inserir_fila_p(raiz->direita);

        fprintf(arquivo_avl, "%s %d\n", raiz->palavra, raiz->repeticao);

        s_palavra temp_palavra;
        strcpy(temp_palavra.palavra, raiz->palavra);
        temp_palavra.prioridade = raiz->repeticao;

        inserir_fila(fila, temp_palavra);

        logs_removidos_avl(raiz->palavra, raiz->repeticao);
        logs_inserir_fila_p(raiz->palavra, raiz->repeticao);

        free(raiz->palavra);
        free(raiz);
    }
    return NULL;
}
