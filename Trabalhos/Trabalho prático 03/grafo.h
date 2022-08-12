#ifndef GRAFO_P_H_INCLUDED
#define GRAFO_P_H_INCLUDED

#define BRANCO 0
#define CINZA 1
#define PRETO 2
#define INFINITO 9999999
#define MAX 100

typedef struct no
{
    int vertice;
    int cor;
    int distancia;
    int tempo_entrada;
    int tempo_saida;
    int antecessor;
    struct aresta *aresta;
} s_no;

typedef struct aresta
{
    int id;          // ID da aresta
    int peso;        // Peso da aresta
    struct no *prox; // Ponteiro para o no que está conectado (v2)
} s_aresta;

typedef struct grafo
{
    s_no **adj;
    int n_vertices;
    int n_arestas;
    int tempo_total;
} s_grafo;

typedef struct fila
{
    int comeco;
    int final;
    int vertices[MAX];
} s_fila;

s_grafo grafo;
s_fila *fila;
int id_count;

s_grafo inicializa_grafo(int n_vertices, int n_arestas);
void inserir_aresta(int v1, int v2, int peso);
void imprimir_grafo();
void vertices_adjacentes_v(int v);
void vertices_incidentes_a(int id);
void arestas_incidentes_v(int v);
int grau_v(int v);
void v_adjacente_v(int v1, int v2);
void trocar_posicao_v(int v1, int v2);
void busca_em_profundidade(int v);
void busca_em_profundidade_recursiva(int v);
s_fila *criar_fila();
void busca_em_largura(int v);
int remove_fila(s_fila *fila);
void insere_fila(s_fila *fila, int v);
void dijkstra(int v);
void dijkstra_recursivo(int v);

s_grafo grafo;

#endif