#include "arvore_avl_string.h"
#include "fila_de_prioridade.h"
#include "arquivo.h"
#include "logs.h"

void iniciar_logs()
{
    arquivo_log = fopen("registros.log", "w+"); // Cria um arquivo vazio para escrita (apaga o anterior)
    if (arquivo_log == NULL)                    // Erro no arquivo ou arquivo não encontrado
    {
        printf("\n [ERROR] Erro ao criar arquivo de log, processo encerrado.\n\n");
        system("pause > nul");
        exit(1);
    }

    // Biblioteca time.h (http://linguagemc.com.br/exibindo-data-e-hora-com-time-h/)
    struct tm *tempo;
    time_t segundos;
    time(&segundos);
    tempo = localtime(&segundos);

    printf("\n [LOG] Inicio do processo de geracao de logs.\n");
    fprintf(arquivo_log, "[%d/%d/%d - %d:%d:%d] - Arquivo de logs criado.\n", tempo->tm_mday, tempo->tm_mon + 1, tempo->tm_year + 1900, tempo->tm_hour, tempo->tm_min, tempo->tm_sec);
}

void logs_inserir_avl(char palavra[])
{
    struct tm *tempo;
    time_t segundos;
    time(&segundos);
    tempo = localtime(&segundos);

    printf(" [INFO] Palavra '%s' inserida na arvore AVL.\n", palavra);
    fprintf(arquivo_log, "[%d/%d/%d - %d:%d:%d] - \"%s\" inserida na arvore AVL.\n", tempo->tm_mday, tempo->tm_mon + 1, tempo->tm_year + 1900, tempo->tm_hour, tempo->tm_min, tempo->tm_sec, palavra);
}

void logs_caracteres_encontrados(int caracteres_encontrados, char arquivo[]){
    struct tm *tempo;
    time_t segundos;
    time(&segundos);
    tempo = localtime(&segundos);

    printf(" [INFO] Caracteres encontrados no arquivo \"%s\": %d.\n", arquivo, caracteres_encontrados);
    fprintf(arquivo_log, "[%d/%d/%d - %d:%d:%d] - %d caracteres encontrados no arquivo \"%s\".\n", tempo->tm_mday, tempo->tm_mon + 1, tempo->tm_year + 1900, tempo->tm_hour, tempo->tm_min, tempo->tm_sec, caracteres_encontrados, arquivo);
}

void logs_feedback_arquivo_tratado(int caracteres_especiais, int caracteres_brancos, int caracteres_final, char arquivo_texto_tratado[]){
    struct tm *tempo;
    time_t segundos;
    time(&segundos);
    tempo = localtime(&segundos);

    printf(" [INFO] Arquivo \"%s\" criado.\n", arquivo_texto_tratado);
    fprintf(arquivo_log, "[%d/%d/%d - %d:%d:%d] - Arquivo \"%s\" tratado.\n", tempo->tm_mday, tempo->tm_mon + 1, tempo->tm_year + 1900, tempo->tm_hour, tempo->tm_min, tempo->tm_sec, arquivo_texto_tratado);
    printf(" [INFO] Caracteres especiais removidos: %d\n", caracteres_especiais);
    fprintf(arquivo_log, "[%d/%d/%d - %d:%d:%d] - %d caracteres especiais removidos.\n", tempo->tm_mday, tempo->tm_mon + 1, tempo->tm_year + 1900, tempo->tm_hour, tempo->tm_min, tempo->tm_sec, caracteres_especiais);
    printf(" [INFO] Caracteres brancos removidos: %d\n", caracteres_brancos);
    fprintf(arquivo_log, "[%d/%d/%d - %d:%d:%d] - %d caracteres brancos removidos.\n", tempo->tm_mday, tempo->tm_mon + 1, tempo->tm_year + 1900, tempo->tm_hour, tempo->tm_min, tempo->tm_sec, caracteres_brancos);
    printf(" [INFO] Total de caracteres tratados inseridos no arquivo \"%s\": %d\n", arquivo_texto_tratado, caracteres_final);
    fprintf(arquivo_log, "[%d/%d/%d - %d:%d:%d] - Total de caracteres tratados inseridos no arquivo \"%s\": %d.\n", tempo->tm_mday, tempo->tm_mon + 1, tempo->tm_year + 1900, tempo->tm_hour, tempo->tm_min, tempo->tm_sec, arquivo_texto_tratado, caracteres_final);
}

void logs_total_palavras(int total_palavras, char arquivo_texto_tratado[]){
    struct tm *tempo;
    time_t segundos;
    time(&segundos);
    tempo = localtime(&segundos);

    printf(" [INFO] Total de palavras encontradas no arquivo \"%s\": %d.\n", arquivo_texto_tratado, total_palavras);
    fprintf(arquivo_log, "[%d/%d/%d - %d:%d:%d] - Total de palavras encontradas no arquivo \"%s\": %d.\n", tempo->tm_mday, tempo->tm_mon + 1, tempo->tm_year + 1900, tempo->tm_hour, tempo->tm_min, tempo->tm_sec, "texto-tratado.txt", total_palavras);
}

void logs_imprimir_in_ordem(char palavra[], int repeticoes){
    struct tm *tempo;
    time_t segundos;
    time(&segundos);
    tempo = localtime(&segundos);

    printf(" [IMPRIMIR] Palavra '%s' encontrada %d vezes.\n", palavra, repeticoes);
    fprintf(arquivo_log, "[%d/%d/%d - %d:%d:%d] - Palavra '%s' encontrada %d vezes.\n", tempo->tm_mday, tempo->tm_mon + 1, tempo->tm_year + 1900, tempo->tm_hour, tempo->tm_min, tempo->tm_sec, palavra, repeticoes);
}

void logs_removidos_avl(char palavra[], int repeticoes)
{
    struct tm *tempo;
    time_t segundos;
    time(&segundos);
    tempo = localtime(&segundos);

    printf(" [INFO] Palavra '%s' removida da arvore AVL - Repeticoes: %d\n", palavra, repeticoes);
    fprintf(arquivo_log, "[%d/%d/%d - %d:%d:%d] - Palavra '%s' removida da arvore AVL - Repetições: %d.\n", tempo->tm_mday, tempo->tm_mon + 1, tempo->tm_year + 1900, tempo->tm_hour, tempo->tm_min, tempo->tm_sec, palavra, repeticoes);
}

void logs_inserir_fila_p(char palavra[], int prioridade)
{
    struct tm *tempo;
    time_t segundos;
    time(&segundos);
    tempo = localtime(&segundos);

    printf(" [INFO] Palavra '%s' inserida na fila de prioridade - Prioridade: %d\n", palavra, prioridade);
    fprintf(arquivo_log, "[%d/%d/%d - %d:%d:%d] - Palavra '%s' inserida na fila de prioridade - Prioridade: %d.\n", tempo->tm_mday, tempo->tm_mon + 1, tempo->tm_year + 1900, tempo->tm_hour, tempo->tm_min, tempo->tm_sec, palavra, prioridade);
}

void logs_fila_acessada(s_palavra temp_palavra)
{
    struct tm *tempo;
    time_t segundos;
    time(&segundos);
    tempo = localtime(&segundos);

    printf(" [INFO] Palavra '%s' acessada na fila de prioridade - Prioridade: %d\n", temp_palavra.palavra, temp_palavra.prioridade);
    fprintf(arquivo_log, "[%d/%d/%d - %d:%d:%d] - Palavra '%s' acessada na fila de prioridade - Prioridade: %d.\n", tempo->tm_mday, tempo->tm_mon + 1, tempo->tm_year + 1900, tempo->tm_hour, tempo->tm_min, tempo->tm_sec, temp_palavra.palavra, temp_palavra.prioridade);
}

void logs_fila_removida(s_palavra temp_palavra){
    struct tm *tempo;
    time_t segundos;
    time(&segundos);
    tempo = localtime(&segundos);

    printf(" [INFO] Palavra '%s' removida da fila de prioridade - Prioridade: %d\n", temp_palavra.palavra, temp_palavra.prioridade);
    fprintf(arquivo_log, "[%d/%d/%d - %d:%d:%d] - Palavra '%s' removida da fila de prioridade - Prioridade: %d.\n", tempo->tm_mday, tempo->tm_mon + 1, tempo->tm_year + 1900, tempo->tm_hour, tempo->tm_min, tempo->tm_sec, temp_palavra.palavra, temp_palavra.prioridade);
}