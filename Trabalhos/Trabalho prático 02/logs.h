#ifndef LOGS_P_H_INCLUDED
#define LOGS_P_H_INCLUDED

FILE *arquivo_log;

void iniciar_logs();
void logs_inserir_avl(char palavra[]);
void logs_caracteres_encontrados(int caracteres_encontrados, char arquivo[]);
void logs_feedback_arquivo_tratado(int caracteres_especiais, int caracteres_brancos, int caracteres_final, char arquivo_texto_tratado[]);
void logs_total_palavras(int total_palavras, char arquivo_texto_tratado[]);
void logs_imprimir_in_ordem(char palavra[], int repeticoes);
void logs_removidos_avl(char palavra[], int repeticoes);
void logs_inserir_fila_p(char palavra[], int prioridade);
void logs_fila_acessada(s_palavra temp_palavra);
void logs_fila_removida(s_palavra temp_palavra);

#endif