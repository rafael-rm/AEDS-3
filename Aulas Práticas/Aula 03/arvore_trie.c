#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define FALSE 0
#define TRUE 1
#define OPCOES 2
#define TAM 256 

// Arvore TRIE
struct trie
{
    int valor;
    struct trie *filho[TAM];
};

typedef struct trie s_trie;

// Funções
int menu();
s_trie *criar_trie();
void inserir(s_trie *raiz, char *palavra);
int buscar(s_trie *raiz, char *palavra);

int main()
{
    s_trie *raiz = NULL;
    int opcao, status;
    char temp_char[256]; 
    do
    {
        opcao = menu();
        printf("%d", opcao);
        switch (opcao)
        {
        case 1: // Inserir palavra TRIE
            system("cls");
            printf("Insira a palavra: ");
            setbuf(stdin, NULL);
            fgets(temp_char, 256, stdin);
            temp_char[strlen(temp_char) - 1] = '\0';
            raiz = criar_trie();
            inserir(raiz, temp_char);
            break;

        case 2: // Buscar palavra TRIE
            system("cls");
            printf("Insira a palavra que deseja buscar: ");
            setbuf(stdin, NULL);
            fgets(temp_char, 256, stdin);
            temp_char[strlen(temp_char) - 1] = '\0';
            status = buscar(raiz, temp_char);
            if (status == TRUE)
                printf("\nA palavra %s foi encontrada\n", temp_char);
            else
                printf("\nA palavra %s nao foi encontrada\n", temp_char);
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
        printf("\n [1] Inserir palavra na arvore\n");
        printf(" [2] Buscar palavra na arvore\n");
        printf(" [0] Sair\n");
        printf("\nOpcao: ");
        scanf("%d", &opcao_selecionada);
        system("cls");
    } while (!(opcao_selecionada >= 0 && opcao_selecionada <= OPCOES));

    return opcao_selecionada;
}

s_trie *criar_trie() // Cria a arvore TRIE
{
    s_trie *raiz = (s_trie *)malloc(sizeof(s_trie)); 
    if (raiz == NULL)
    {
        printf("\nErro ao alocar memoria!!\n");
        exit(1);
    }
    raiz->valor = '\0';
    for (int i = 0; i < TAM; i++) // Inicializa todos os filhos como NULL
        raiz->filho[i] = NULL; 
    return raiz;
}

void inserir(s_trie *raiz, char *palavra) // Insere palavra na arvore
{
    if (raiz == NULL) // Se a arvore estiver vazia
    {
        printf("\nErro ao inserir! (Tipo 1)\n");
        return;
    }
    if (strlen(palavra) == 0) // Se a palavra for vazia
    {
        printf("\nErro ao inserir! (Tipo 2)\n");
        return;
    }
    if (strlen(palavra) == 1) // Se a palavra for uma letra
    {
        if (raiz->filho[palavra[0] - 'a'] == NULL)
        {
            raiz->filho[palavra[0] - 'a'] = criar_trie();
            raiz->filho[palavra[0] - 'a']->valor = palavra[0];
        }
        else 
        {
            printf("\nErro ao inserir! (Tipo 3)\n");
            return;
        }
    }
    else // Se a palavra for maior que uma letra
    {
        if (raiz->filho[palavra[0] - 'a'] == NULL) // Se a primeira letra nao existir
        {
            raiz->filho[palavra[0] - 'a'] = criar_trie();
            raiz->filho[palavra[0] - 'a']->valor = palavra[0];
        }
        inserir(raiz->filho[palavra[0] - 'a'], palavra + 1); 
    }
}

int buscar(s_trie *raiz, char *palavra) // Retorna TRUE se a palavra existe e FALSE se nao existe
{
    if (raiz == NULL)
    {
        printf("\nErro ao buscar! (Tipo 1)\n");
        return FALSE;
    }
    if (strlen(palavra) == 0) // Se a palavra for vazia
    {
        printf("\nErro ao buscar! (Tipo 2)\n");
        return FALSE;
    }
    if (strlen(palavra) == 1) // Se a palavra for uma letra
    {
        if (raiz->filho[palavra[0] - 'a'] == NULL)
            return FALSE;
        else
            return TRUE;
    }
    else // Se a palavra for maior que uma letra
    {
        if (raiz->filho[palavra[0] - 'a'] == NULL) // Se a primeira letra nao existir
            return FALSE;
        else
            return buscar(raiz->filho[palavra[0] - 'a'], palavra + 1); 
    }
}
