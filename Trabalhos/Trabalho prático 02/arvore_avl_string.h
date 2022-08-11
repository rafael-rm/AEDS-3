#ifndef ARVORE_AVL_STRING_H_INCLUDED
#define ARVORE_AVL_STRING_H_INCLUDED

#define FALSE 0
#define TRUE 1
#define TAMANHO_PALAVRAS 30

struct node
{
    char *palavra;
    int repeticao;
    struct node *esquerda;
    struct node *direita;
};

typedef struct node s_node;

s_node *raiz;

s_node *criar_arvore();
s_node *inserir_elemento(s_node *raiz, char palavra[]);
s_node *rotacao_esquerda(s_node *raiz);
s_node *rotacao_direita(s_node *raiz);
s_node *rotacao_dupla_esquerda(s_node *raiz);
s_node *rotacao_dupla_direita(s_node *raiz);
s_node *balancear_arvore(s_node *raiz);
int buscar_elemento(s_node *raiz, char palavra[]);
s_node *menor_elemento(s_node *raiz);
int altura_arvore(s_node *raiz);
int fator_balanceamento(s_node *raiz);
void imprimir_in_ordem(s_node *raiz);
int tamanho_arvore(s_node *raiz);

#endif