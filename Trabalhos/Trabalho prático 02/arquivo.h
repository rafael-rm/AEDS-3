#ifndef ARQUIVO_P_H_INCLUDED
#define ARQUIVO_P_H_INCLUDED

FILE *arquivo_texto;
FILE *arquivo_texto_tratado;
FILE *arquivo_avl;
FILE *arquivo_fila_atual;

#define ARQUIVO_TEXTO "texto.txt"

void abrir_arquivo_texto();
void criar_arquivo_tratado();
void tratar_arquivo();
void ler_arquivo_tratado_inserir_avl();
void fechar_arquivo(FILE *arquivo);
void criar_arquivo_fila_atual(s_fila *fila);

#endif