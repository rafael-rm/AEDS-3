#include "arquivo.h"
#include "grafo.h"

s_grafo inicializa_grafo(int n_vertices, int n_arestas)
{
    s_grafo grafo;
    id_count = 0;
    grafo.adj = (s_no **)malloc(n_vertices * sizeof(s_no *)); // Aloca memória para o vetor de ponteiros de nós
    grafo.n_vertices = n_vertices;
    grafo.n_arestas = n_arestas;
    for (int i = 1; i <= n_vertices; i++)
    {
        grafo.adj[i] = NULL; // Inicializa todos os ponteiros de nós como NULL
    }
    return grafo;
}

void inserir_aresta(int v1, int v2, int peso)
{
    s_no *novo = (s_no *)malloc(sizeof(s_no));           // Aloca memória para o novo nó
    novo->aresta = (s_aresta *)malloc(sizeof(s_aresta)); // Aloca memória para a aresta
    novo->vertice = v2;
    id_count++;
    novo->aresta->id = id_count;
    novo->aresta->peso = peso;
    novo->aresta->prox = grafo.adj[v1];
    grafo.adj[v1] = novo;
    grafo.n_arestas++;
}

void imprimir_grafo()
{
    printf("\n [INFO] Imprimindo os vertices adjacentes:\n");
    for (int i = 1; i <= grafo.n_vertices; i++)
    {
        printf("\n [INFO] Vertice %d:", i);
        s_no *aux = grafo.adj[i];
        while (aux != NULL)
        {
            printf(" %d", aux->vertice);
            aux = aux->aresta->prox;
        }
    }

    printf("\n\n\n\n [INFO] Imprimindo as arestas incidentes aos vertices:\n");
    for (int i = 1; i <= grafo.n_vertices; i++)
    {
        printf("\n [INFO] Vertice %d:", i);
        s_no *aux = grafo.adj[i];
        while (aux != NULL)
        {
            printf(" %d", aux->aresta->id);
            aux = aux->aresta->prox;
        }
    }

    printf("\n\n\n\n [INFO] Imprimindo visualmente\n");
    // Percorrer todos os nós e imprimir os adjacentes
    for (int i = 1; i <= grafo.n_vertices; i++)
    {
        s_no *aux = grafo.adj[i];
        while (aux != NULL)
        {
            printf("\n [INFO] v%d ---> v%d  (aresta: id %d, peso %d)", i, aux->vertice, aux->aresta->id, aux->aresta->peso);
            aux = aux->aresta->prox;
        }
    }
}

void imprimir_arestas_grafo() // id e peso
{
    printf("\n [INFO] Imprimindo arestas:\n");
    for (int i = 1; i <= grafo.n_vertices; i++)
    {
        printf("\n [INFO] Vertice %d:", i);
        s_no *aux = grafo.adj[i];
        while (aux != NULL)
        {
            printf(" %d", aux->aresta->id);
            aux = aux->aresta->prox;
        }
    }
    printf("\n");
}

void aresta_adjacente_aresta(int id)
{
    // Procurar a aresta id e imprimir/salvar os vertices adjacente
    int v1, v2;
    for (int i = 1; i <= grafo.n_vertices; i++)
    {
        s_no *aux = grafo.adj[i];
        while (aux != NULL)
        {
            if (aux->aresta->id == id)
            {
                printf("\n [INFO] A aresta informada liga os vertices (%d) - (%d) e possui peso (%d).", i, aux->vertice, aux->aresta->peso);
                v1 = i;
                v2 = aux->vertice;
                break;
            }
            aux = aux->aresta->prox;
        }
    }

    // Procurar outra aresta que ligue os vertices v1 e v2
    int contador_arestas_adjacentes = 0;
    for (int i = 1; i <= grafo.n_vertices; i++)
    {
        s_no *aux = grafo.adj[i];
        while (aux != NULL)
        {
            if (i == v1 && aux->vertice == v2 && aux->aresta->id != id)
            {
                printf("\n\n [INFO] A aresta adjacente de ID %d encontrada, ela possui peso %d.", aux->aresta->id, aux->aresta->peso);
                contador_arestas_adjacentes++;
            }
            aux = aux->aresta->prox;
        }
    }
    if (contador_arestas_adjacentes == 0)
    {
        printf("\n [INFO] Nao existe aresta adjacente a aresta %d", id);
    }
}

void vertices_adjacentes_v(int v) // Imprime todos os verticies adjacentes ao vertice v
{
    s_no *aux = grafo.adj[v]; // Recebe o vertice v
    if (aux == NULL)
    {
        printf("\n [ERROR] O vertice %d nao possui arestas adjacentes.\n\n", v);
    }
    else
    {
        while (aux != NULL)
        {
            printf("Vertice %d -> Vertice %d, Peso: %d\n", v, aux->vertice, aux->aresta->peso);
            aux = aux->aresta->prox; // Ponteiro para o proximo vertice adjacente
        }
    }
}

void vertices_incidentes_a(int id)
{
    for (int i = 1; i <= grafo.n_vertices; i++)
    {
        s_no *aux = grafo.adj[i];
        while (aux != NULL)
        {
            if (aux->aresta->id == id)
            {
                printf("\n [INFO] Aresta %d: Vertice %d -> Vertice %d, Peso: %d\n", id, i, aux->vertice, aux->aresta->peso);
            }
            aux = aux->aresta->prox; // Pula para o proximo no
        }
    }
}

void arestas_incidentes_v(int v)
{
    // Ver quais arestas sao incidentes ao vertice v
    s_no *aux = grafo.adj[v];
    if (aux == NULL)
    {
        printf("\n [ERROR] O vertice %d nao possui arestas adjacentes.\n\n", v);
    }
    else
    {
        while (aux != NULL)
        {
            printf("\n [INFO] O vertice %d possui a aresta de ID %d como incidente. [%d -> %d (peso %d)]", v, aux->aresta->id, v, aux->vertice, aux->aresta->peso);
            aux = aux->aresta->prox; // Ponteiro para o proximo vertice adjacente
        }
    }
}

// Grau do vertice (contar quantas arestas chegam no vertice)
int grau_v(int v)
{
    int contador = 0;
    s_no *aux = grafo.adj[v];
    if (aux == NULL)
    {
        printf("\n [ERROR] O vertice %d nao possui arestas adjacentes.\n\n", v);
    }
    else
    {
        while (aux != NULL)
        {
            contador++;
            aux = aux->aresta->prox; // Ponteiro para o proximo vertice adjacente
        }
    }
    return contador;
}

void v_adjacente_v(int v1, int v2)
{
    s_no *aux = grafo.adj[v1];
    while (aux != NULL)
    {
        if (aux->vertice == v2)
        {
            printf("\n [INFO] Os vertices %d e %d sao adjacentes.\n", v1, v2);
            return;
        }
        aux = aux->aresta->prox;
    }
    printf("\n [INFO] Os vertices %d e %d nao sao adjacentes.\n", v1, v2);
}

void substituir_peso_a(int id, int peso)
{
    for (int i = 1; i <= grafo.n_vertices; i++)
    {
        s_no *aux = grafo.adj[i];
        while (aux != NULL)
        {
            if (aux->aresta->id == id)
            {
                aux->aresta->peso = peso;
                return;
            }
            aux = aux->aresta->prox;
        }
    }
}

// Trocar a posição de dois vertices e seus adjacentes
void trocar_posicao_v(int v1, int v2)
{
    // Trocar o vertice v1 pelo vertice v2
    s_no *aux = grafo.adj[v1];     // Recebe o vertice v1
    grafo.adj[v1] = grafo.adj[v2]; // Substitui o vertice v1 pelo vertice v2
    grafo.adj[v2] = aux;           // Substitui o vertice v2 pelo vertice v1
    // Trocar os adjacentes do vertice v1
    aux = grafo.adj[v1];
    while (aux != NULL)
    {
        if (aux->vertice == v2)
        {
            aux->vertice = v1; // Troca o vertice adjacente do vertice v1 pelo vertice v2
        }
        aux = aux->aresta->prox;
    }
    // Trocar os adjacentes do vertice v2
    aux = grafo.adj[v2];
    while (aux != NULL)
    {
        if (aux->vertice == v1)
        {
            aux->vertice = v2; // Troca o vertice adjacente do vertice v2 pelo vertice v1
        }
        aux = aux->aresta->prox;
    }
}

void busca_em_profundidade(int v)
{
    grafo.tempo_total = 0;
    for (int i = 1; i <= grafo.n_vertices; i++)
    {
        grafo.adj[i]->cor = BRANCO; // Coloca todos os vertices na cor branca
    }
    printf("\n [INFO] Busca em profundidade em andamento...");
    busca_em_profundidade_recursiva(v);
    printf("\n [INFO] Busca em profundidade finalizada.");
}

void busca_em_profundidade_recursiva(int v)
{
    grafo.adj[v]->cor = CINZA; // Coloca o vertice v na cor cinza
    grafo.tempo_total++;
    grafo.adj[v]->tempo_entrada = grafo.tempo_total;
    printf("\n [INFO] Tempo: %d, Visitando o vertice %d.", grafo.adj[v]->tempo_entrada, v);
    s_no *aux = grafo.adj[v];
    while (aux != NULL)
    {
        if (grafo.adj[aux->vertice]->cor == BRANCO) // Verifica se o vertice adjacente ao vertice v é branco
        {
            busca_em_profundidade_recursiva(aux->vertice); // Chama a função recursiva para o vertice adjacente ao vertice v
        }
        aux = aux->aresta->prox;
    }
    grafo.adj[v]->cor = PRETO; // Coloca o vertice v na cor preto
    grafo.tempo_total++;
    grafo.adj[v]->tempo_saida = grafo.tempo_total;
    printf("\n [INFO] Tempo: %d, Finalizando o vertice %d.", grafo.adj[v]->tempo_saida, v);
}

s_fila *cria_fila()
{
    s_fila *temp;
    temp = (s_fila *)calloc(1, sizeof(s_fila));
    temp->comeco = 0;
    temp->final = 0;
    return temp;
}

void insere_fila(s_fila *fila, int v)
{
    fila->final++;
    fila->vertices[fila->final] = v;
}

int remove_fila(s_fila *fila)
{
    int v = fila->vertices[fila->comeco];
    fila->comeco++;
    return v;
}

void busca_em_largura(int v)
{
    grafo.tempo_total = 0;
    for (int i = 1; i <= grafo.n_vertices; i++)
    {
        grafo.adj[i]->cor = BRANCO; // Coloca tzzodos os vertices na cor branca
    }
    printf("\n [INFO] Busca em largura em andamento...");
    fila = cria_fila();
    insere_fila(fila, v);
    grafo.adj[v]->cor = CINZA; // Coloca o vertice v na cor cinza
    grafo.tempo_total++;
    grafo.adj[v]->tempo_entrada = grafo.tempo_total;
    printf("\n [INFO] Tempo: %d, Visitando o vertice %d.", grafo.adj[v]->tempo_entrada, v);
    while (fila->comeco != fila->final)
    {
        int v = remove_fila(fila);
        s_no *aux = grafo.adj[v];
        while (aux != NULL)
        {
            printf("\n [TESTE] Entrou aqui? (1)");
            if (grafo.adj[aux->vertice]->cor == BRANCO) // Verifica se o vertice adjacente ao vertice v é branco
            {
                printf("\n [TESTE] Entrou aqui? (2)");

                insere_fila(fila, aux->vertice);      // Chama a função recursiva para o vertice adjacente ao vertice v
                grafo.adj[aux->vertice]->cor = CINZA; // Coloca o vertice adjacente ao vertice v na cor cinza
                grafo.tempo_total++;
                grafo.adj[aux->vertice]->tempo_entrada = grafo.tempo_total;
                printf("\n [INFO] Tempo: %d, Visitando o vertice %d.", grafo.adj[aux->vertice]->tempo_entrada, aux->vertice);

                printf("\n [TESTE] Entrou aqui? (3)");
            }
            printf("\n [TESTE] Entrou aqui? (4)");
            aux = aux->aresta->prox;
        }
        grafo.adj[v]->cor = PRETO; // Coloca o vertice v na cor preto
        grafo.tempo_total++;
        grafo.adj[v]->tempo_saida = grafo.tempo_total;
        printf("\n [INFO] Tempo: %d, Finalizando o vertice %d.", grafo.adj[v]->tempo_saida, v);
    }
    printf("\n [INFO] Busca em largura finalizada.");
}

void dijkstra(int v)
{
    for (int i = 1; i <= grafo.n_vertices; i++)
    {
        grafo.adj[i]->distancia = INFINITO; // Coloca todos os vertices na distancia infinita
        grafo.adj[i]->antecessor = -1;      // Coloca todos os vertices sem antecessor
    }
    printf("\n [INFO] Dijkstra em andamento...");
    dijkstra_recursiva(v);
    printf("\n [INFO] Dijkstra finalizado.");
}

void dijkstra_recursiva(int v){
    grafo.adj[v]->distancia = 0; // Coloca o vertice v na distancia 0
    s_no *aux = grafo.adj[v];
    while (aux != NULL)
    {
        if (grafo.adj[aux->vertice]->distancia > grafo.adj[v]->distancia + aux->aresta->peso)
        {
            grafo.adj[aux->vertice]->distancia = grafo.adj[v]->distancia + aux->aresta->peso;
            grafo.adj[aux->vertice]->antecessor = v;
            printf("\n [INFO] Distancia do vertice %d para o vertice %d: %d.", v, aux->vertice, grafo.adj[aux->vertice]->distancia);
        }
        aux = aux->aresta->prox;
    }
    aux = grafo.adj[v];

    while (aux != NULL)
    {
        if (grafo.adj[aux->vertice]->cor == BRANCO) // Verifica se o vertice adjacente ao vertice v é branco
        {
            dijkstra_recursiva(aux->vertice); // Chama a função recursiva para o vertice adjacente ao vertice v
        }
        aux = aux->aresta->prox;
    }
}