#include "arvore_avl_string.h"
#include "fila_de_prioridade.h"
#include "arquivo.h"
#include "logs.h"

s_node *criar_arvore()
{
    return NULL;
}

int altura_arvore(s_node *raiz)
{
    if (raiz == NULL)
        return 0;
    else // Soma a altura das subarvores
    {
        int altura_esquerda = altura_arvore(raiz->esquerda); 
        int altura_direita = altura_arvore(raiz->direita); 
        if (altura_esquerda > altura_direita) // Se a altura da esquerda for maior que a da direita
            return altura_esquerda + 1;
        else // Se a altura da direita for maior que a da esquerda
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
        raiz->palavra = (char *)malloc(sizeof(char) * TAMANHO_PALAVRAS);
        strcpy(raiz->palavra, palavra);
        raiz->esquerda = NULL;
        raiz->direita = NULL;
        raiz->repeticao = 1; // Inserindo a primeira vez
        raiz = balancear_arvore(raiz);
        return raiz;
    }
    else
    {
        if (strcmp(palavra, raiz->palavra) < 0)
            raiz->esquerda = inserir_elemento(raiz->esquerda, palavra);
        else if (strcmp(palavra, raiz->palavra) > 0)
            raiz->direita = inserir_elemento(raiz->direita, palavra);
        else 
            raiz->repeticao++; // Se a palavra já existe, incrementa a repetição
        return raiz;
    }
}

int buscar_elemento(s_node *raiz, char *palavra)
{
    if (raiz == NULL)
        return FALSE;
    else
    {
        if (strcmp(palavra, raiz->palavra) < 0)
            return buscar_elemento(raiz->esquerda, palavra);
        else if (strcmp(palavra, raiz->palavra) > 0)
            return buscar_elemento(raiz->direita, palavra);
        else
            return TRUE;
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
        logs_imprimir_in_ordem(raiz->palavra, raiz->repeticao);
        imprimir_in_ordem(raiz->direita);
    }
}

int tamanho_arvore(s_node *raiz)
{
    if (raiz == NULL)
        return 0;
    else
    {
        int tamanho_esquerda = tamanho_arvore(raiz->esquerda);
        int tamanho_direita = tamanho_arvore(raiz->direita);
        return tamanho_esquerda + tamanho_direita + 1;
    }
}