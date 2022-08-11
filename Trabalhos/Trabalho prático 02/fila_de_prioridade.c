#include "arvore_avl_string.h"
#include "fila_de_prioridade.h"
#include "arquivo.h"
#include "logs.h"

s_fila *criar_fila(){
    s_fila *fila = (s_fila *)malloc(sizeof(s_fila));
    tamanho_fila = tamanho_arvore(raiz); // Retorna o numero de palavras encontradas na arvore AVL(variavel global)
    fila->palavras = (s_palavra *)malloc(sizeof(s_palavra) * tamanho_fila); // Aloca memoria para a fila de palavras de acordo com o numero de palavras encontradas na AVL
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
    while (i > 0 && fila->palavras[i].prioridade > fila->palavras[(i - 1) / 2].prioridade) // Verifica se a prioridade da palavra atual é maior que a da palavra anterior
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
    while (2 * i + 1 < quantidade) // Enquanto o filho da esquerda existir
    {
        int maior = 2 * i + 1;
        if (2 * i + 2 < quantidade && fila->palavras[2 * i + 2].prioridade > fila->palavras[2 * i + 1].prioridade) // Se o filho da direita for maior que o da esquerda
        {
            maior = 2 * i + 2; // O filho da direita é o maior
        }
        if (fila->palavras[i].prioridade < fila->palavras[maior].prioridade) // Se a raiz for menor que o filho da direita ou esquerda
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
    return fila->quantidade == tamanho_fila;
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