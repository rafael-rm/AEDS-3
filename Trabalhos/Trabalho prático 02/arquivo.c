#include "arvore_avl_string.h"
#include "fila_de_prioridade.h"
#include "arquivo.h"
#include "logs.h"

void abrir_arquivo_texto() // Abre o texto original
{
    arquivo_texto = fopen(ARQUIVO_TEXTO, "r"); // Abre o arquivo de texto DEFAULT
    if (arquivo_texto == NULL)
    {
        printf("\n [ERROR] Erro ao abrir arquivo \"%s\", processo encerrado.\n\n", ARQUIVO_TEXTO);
        system("pause > nul");
        exit(1);
    }
}

void criar_arquivo_tratado() // Cria um arquivo com o texto original tratado
{
    arquivo_texto_tratado = fopen("texto-tratado.txt", "w+"); // Cria o arquivo de texto TRATADO
    if (arquivo_texto_tratado == NULL)
    {
        printf("\n [ERROR] Erro ao criar arquivo texto-tratado.txt, processo encerrado.\n\n");
        system("pause > nul");
        exit(1);
    }
}

void criar_arquivo_avl() // Cria um arquivo com todas as palavras inseridas na AVL (usado apenas para verificação manual)
{
    arquivo_avl = fopen("palavras-repeticoes.txt", "w+"); // Cria o arquivo com as palavras que haviam na arvore AVL e suas repeticoes
    if (arquivo_avl == NULL)
    {
        printf("\n [ERROR] Erro ao criar arquivo palavras-repeticoes.txt, processo encerrado.\n\n");
        exit(1);
    }
}

void tratar_arquivo() // Função para tratar o arquivo de texto original e inserir no novo arquivo tratado
{
    abrir_arquivo_texto();
    int caracteres_encontrados = 0;
    int caracteres_especiais = 0;
    int caracteres_brancos = 0;
    char c;

    // Contar o numero de caracteres do arquivo para alocar o espaço necessário em um vetor temporário
    for (c = getc(arquivo_texto); c != EOF; c = getc(arquivo_texto))
    {
        caracteres_encontrados++;
    }
    char *temp_texto = malloc(caracteres_encontrados * sizeof(char));

    logs_caracteres_encontrados(caracteres_encontrados, ARQUIVO_TEXTO);
    system("pause > nul");

    rewind(arquivo_texto); // Volta o ponteiro para o início do arquivo
    for (int i = 0; i < caracteres_encontrados; i++)
    {
        char temp_char = getc(arquivo_texto);
        if (temp_char == '.' || temp_char == ',' || temp_char == '!' || temp_char == '?' || temp_char == ';' || temp_char == ':' || temp_char == '-' || temp_char == '(' || temp_char == ')' || temp_char == '"' || temp_char == '\'' || temp_char == '/' || temp_char == '@' || temp_char == '#' || temp_char == '$' || temp_char == '%' || temp_char == '&' || temp_char == '*' || temp_char == '+' || temp_char == '=' || temp_char == '_' || temp_char == '<' || temp_char == '>' || temp_char == '[' || temp_char == ']')
        {
            temp_texto[i] = ' ';
            caracteres_especiais++; // _tête-à-tête_
        }
        else
        {
            temp_texto[i] = temp_char;
        }
    }

    criar_arquivo_tratado(); // Cria arquivo de texto tratado e insere caracter por caracter no arquivo através do vetor temporário.
    for (int i = 0; i < caracteres_encontrados; i++)
    {
        // Remover espaços duplicados e inserir os caracteres(palavras) no arquivo de texto tratado.
        char temp_char1 = temp_texto[i];
        char temp_char2 = temp_texto[i + 1];
        if (temp_char1 == ' ' && temp_char2 == ' ')
        {
            caracteres_brancos++;
        }
        else
        {
            temp_texto[i] = tolower(temp_texto[i]);      // Converte todos os caracteres para minúsculo.
            fputc(temp_texto[i], arquivo_texto_tratado); // Insere caracter por caracter no arquivo de texto tratado.
        }
    }

    int caracteres_final = caracteres_encontrados - caracteres_especiais - caracteres_brancos;
    logs_feedback_arquivo_tratado(caracteres_especiais, caracteres_brancos, caracteres_final, "texto-tratado.txt");
    free(temp_texto);
    fclose(arquivo_texto);
    system("pause > nul");
}

void ler_arquivo_tratado_inserir_avl() // Le o arquivo tratado e insere as palavras em uma arvore AVL
{
    rewind(arquivo_texto_tratado);
    int total_palavras = 0;
    for (char c = getc(arquivo_texto_tratado); c != EOF; c = getc(arquivo_texto_tratado))
    {
        if (c == ' ')
        {
            total_palavras++;
        }
    }
    logs_total_palavras(total_palavras, "texto-tratado.txt");
    system("pause > nul");
    rewind(arquivo_texto_tratado);
    char temp_palavra[30];
    for (int i = 0; i < total_palavras; i++)
    {
        fscanf(arquivo_texto_tratado, "%s", temp_palavra);
        logs_inserir_avl(temp_palavra); // Remover esta função melhora o tempo de execução do programa devido a quantidade de printf's executados
        raiz = inserir_elemento(raiz, temp_palavra);
    }
    free(temp_palavra);
    system("pause > nul");
}

void fechar_arquivo(FILE *arquivo) // Fechar qualquer arquivo
{
    fclose(arquivo);
}

void criar_arquivo_fila_atual(s_fila *fila) // Cria um arquivo com o vetor da fila de prioridade (usado para verificação manual)
{
    arquivo_fila_atual = fopen("fila-atual.txt", "w+");
    if (arquivo_fila_atual == NULL)
    {
        printf("\n [ERROR] Erro ao criar arquivo de texto-tratado.txt, processo encerrado.\n\n");
        system("pause > nul");
        exit(1);
    }

    s_palavra temp;
    for (int i = 0; i < fila->quantidade; i++) // Pecorre todo o vetor da fila de prioridade
    {
        temp = fila->palavras[i];
        fprintf(arquivo_fila_atual, "[%d] - %s (%d)\n", i, temp.palavra, temp.prioridade);
    }

    fechar_arquivo(arquivo_fila_atual);
}