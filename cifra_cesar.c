// Implementar um programa que criptografe mensagens usando a cifra de César

#include <locale.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Protótipos
int validarArgumentos(int argc, char *argv[]);
char *receberTextoSimples();
char *definirIndicesCaracteresMinusculos(const int QUANTIDADE_CARACTERES, char *textoSimples);
char *definirIndicesCaracteresMaisculos(const int QUANTIDADE_CARACTERES, char *textoSimples, char *caracteresMinusculos);
char *cifrarTexto(char *textoSimples, const int CHAVE, const int QUANTIDADE_CARACTERES, char *caracteresMinusculos, char *caracteresMaiusculos);
void exibirTextos(char *textoSimples, char *textoCrifrado);

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Portuguese");

    const int CHAVE = atoi(argv[1]);
    const int QUANTIDADE_CARACTERES = 26 + 1;

    int validacaoArgumentos = validarArgumentos(argc, argv);
    if (validacaoArgumentos == 1)
    {
        return 1;
    }

    char *textoSimples = receberTextoSimples();
    char *caracteresMinusculos = definirIndicesCaracteresMinusculos(QUANTIDADE_CARACTERES, textoSimples);
    char *caracteresMaiusculos = definirIndicesCaracteresMaisculos(QUANTIDADE_CARACTERES, textoSimples, caracteresMinusculos);
    char *textoCifrado = cifrarTexto(textoSimples, CHAVE, QUANTIDADE_CARACTERES, caracteresMinusculos, caracteresMaiusculos);
    exibirTextos(textoSimples, textoCifrado);

    free(textoSimples);
    free(caracteresMinusculos);
    free(caracteresMaiusculos);
    free(textoCifrado);

    return 0;
}

int validarArgumentos(int argc, char *argv[])
{
    // Verificar se o usuário inseriu o quantitativo adequado
    if (argc == 1)
    {
        printf("\nNão foi possível realizar a cripitografia, pois a chave não foi informada!\n\n");
        return 1;
    }
    else if (argc > 2)
    {
        printf("\nNão foi possível fazer a criptografia, pois foram informadas %d chaves!\n\n", (argc - 1));
        return 1;
    }

    // Verificar se o argumento fornecido é um inteiro positivo
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!(argv[1][i] > '0' && argv[1][i] <= '9'))
        {
            printf("\nNão foi possível fazer a criptografia, pois a chave '%s' não é válida!\n\n", argv[1]);
            return 1;
        }
    }

    return 0;
}

char *receberTextoSimples()
{
    int tamanhoInicial = 10;
    int tamanhoAtual = tamanhoInicial;

    // Alocar uma quantidade inicial de memória para o texto
    char *texto = (char *)malloc(tamanhoInicial * sizeof(char));
    if (texto == NULL)
    {
        printf("Falha na alocação de memória");
        exit(EXIT_FAILURE);
    }

    printf("\nPor favor, informe o texto para realizar a criptografia: ");

    bool ehTexto = true;
    int indice = 0;
    char caractere;

    while (ehTexto)
    {
        caractere = getchar();

        if (indice == tamanhoAtual - 1)
        {
            // Alocar mais memória
            tamanhoAtual *= 2;
            texto = (char *)realloc(texto, tamanhoAtual * sizeof(char));
            if (texto == NULL)
            {
                printf("Falha na alocação de memória");
                free(texto);
                exit(EXIT_FAILURE);
            }
        }

        if (caractere == '\n')
        {
            ehTexto = false;
        }
        else
        {
            texto[indice++] = caractere;
        }
    }

    texto[indice] = '\0';

    return texto;
}

char *definirIndicesCaracteresMinusculos(const int QUANTIDADE_CARACTERES, char *textoSimples)
{
    // Alocar memória para os 26 caracteres alfabéticos minúsculos da tabela ASCII e para NULL
    char *caracteresMinusculos = (char *)malloc(QUANTIDADE_CARACTERES * sizeof(char));
    if (caracteresMinusculos == NULL)
    {
        printf("Falha na alocação de memória");
        free(textoSimples);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < QUANTIDADE_CARACTERES; i++)
    {
        caracteresMinusculos[i] = 'a' + i;

        if (i == 26)
        {
            caracteresMinusculos[i] = '\0';
        }
    }

    return caracteresMinusculos;
}

char *definirIndicesCaracteresMaisculos(const int QUANTIDADE_CARACTERES, char *textoSimples, char *caracteresMinusculos)
{
    // Alocar memória para os 26 caracteres alfabéticos maiúsculos da tabela ASCII e para NULL
    char *caracteresMaiusculos = (char *)malloc(QUANTIDADE_CARACTERES * sizeof(char));
    if (caracteresMaiusculos == NULL)
    {
        printf("Falha na alocação de memória");
        free(textoSimples);
        free(caracteresMinusculos);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < QUANTIDADE_CARACTERES; i++)
    {
        caracteresMaiusculos[i] = 'A' + i;
        if (i == 26)
        {
            caracteresMaiusculos[i] = '\0';
        }
    }

    return caracteresMaiusculos;
}

char *cifrarTexto(char *textoSimples, const int CHAVE, const int QUANTIDADE_CARACTERES, char *caracteresMinusculos, char *caracteresMaiusculos)
{
    char *textoCifrado = (char *)malloc(strlen(textoSimples) * sizeof(char));
    if (textoCifrado == NULL)
    {
        printf("Falha na alocação de memória");
        free(textoSimples);
        free(caracteresMinusculos);
        free(caracteresMaiusculos);
        exit(EXIT_FAILURE);
    }

    // Copiar textoSimples para a variável textoCifrado, para alterá-la sem modificar a original
    strcpy(textoCifrado, textoSimples);

    for (int i = 0, n = strlen(textoCifrado); i < n; i++)
    {
        for (int j = 0; j < QUANTIDADE_CARACTERES; j++)
        {
            int cifra = (j + CHAVE) % 26;
            int cifraAlternativa = (j + CHAVE + 1) % 26;

            if (caracteresMinusculos[j] == textoCifrado[i])
            {
                textoCifrado[i] = caracteresMinusculos[cifra];

                if (textoCifrado[i] == textoSimples[i])
                {
                    textoCifrado[i] = caracteresMinusculos[cifraAlternativa];
                }
                break;
            }

            if (caracteresMaiusculos[j] == textoCifrado[i])
            {
                textoCifrado[i] = caracteresMaiusculos[cifra];

                if (textoCifrado[i] == textoSimples[i])
                {
                    textoCifrado[i] = caracteresMaiusculos[cifraAlternativa];
                }
                break;
            }
        }
    }

    return textoCifrado;
}

void exibirTextos(char *textoSimples, char *textoCifrado)
{
    printf("\nTexto Simples: %s\n", textoSimples);
    printf("Texto Cifrado: %s\n\n", textoCifrado);
}