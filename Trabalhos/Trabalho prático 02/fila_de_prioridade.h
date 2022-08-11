#ifndef FILA_P_H_INCLUDED
#define FILA_P_H_INCLUDED

typedef struct palavra
{
    char palavra[30];
    int prioridade;
} s_palavra;

typedef struct fila
{
    s_palavra *palavras;
    int quantidade;
} s_fila;

s_fila *fila;
int tamanho_fila; // Tamanho do vetor a ser criado (usado função de criar fila)

s_fila *criar_fila();
int inserir_fila(s_fila *fila, s_palavra palavra);
void balancear_inserir(s_fila *fila, int quantidade);
int remover_fila(s_fila *fila, s_palavra *palavra_removida);
void balancear_remover(s_fila *fila, int quantidade);
int acessar_fila(s_fila *fila, s_palavra *palavra_acessada);
int fila_cheia(s_fila *fila);
int fila_vazia(s_fila *fila);
int liberar_fila(s_fila *fila);

#endif