// Determinar, entre duas palavras, qual vale mais.

#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// Protótipos
char *definirAlfabeto(char LETRA_ALFABETO[26 + 1]);
void solicitarPalavras(const int QUANTIDADE_PALAVRAS, const int TAMANHO_MAXIMO, char palavras[2][TAMANHO_MAXIMO]);
void definirValorPalavras(const int QUANTIDADE_PALAVRAS, const int TAMANHO_MAXIMO, char palavras[2][TAMANHO_MAXIMO], char *letrasAlfabeto, int valorTotalPalavras[2]);
void exibirValorPalavras(int valorTotalPalavras[2]);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    const int QUANTIDADE_PALAVRAS = 2;
    char alfabeto[26 + 1];
    char *letrasAlfabeto = definirAlfabeto(alfabeto);

    const int TAMANHO_MAXIMO = 100;

    char palavras[2][TAMANHO_MAXIMO];
    solicitarPalavras(QUANTIDADE_PALAVRAS, TAMANHO_MAXIMO, palavras);

    int valorTotalPalavras[] = {0, 0};

    definirValorPalavras(QUANTIDADE_PALAVRAS, TAMANHO_MAXIMO, palavras, letrasAlfabeto, valorTotalPalavras);

    exibirValorPalavras(valorTotalPalavras);

    return 0;
}

char *definirAlfabeto(char alfabeto[26 + 1])
{
    const int TAMANHO_ALFABETO = 26;

    for (int i = 0; i < TAMANHO_ALFABETO; i++)
    {
        alfabeto[i] = 'a' + i;
    }

    alfabeto[TAMANHO_ALFABETO] = '\0';

    return alfabeto;
}

void solicitarPalavras(const int QUANTIDADE_PALAVRAS, const int TAMANHO_MAXIMO, char palavras[2][TAMANHO_MAXIMO])
{
    for (int i = 0; i < QUANTIDADE_PALAVRAS; i++)
    {
        char entradaUsuario[TAMANHO_MAXIMO];

        do
        {
            printf("\nJogador %d - insira a palavra para analise do valor: ", i + 1);

            fgets(entradaUsuario, sizeof(entradaUsuario), stdin);

        } while (sscanf(entradaUsuario, "%s", palavras[i]) != 1);
    }
}

void definirValorPalavras(const int QUANTIDADE_PALAVRAS, const int TAMANHO_MAXIMO, char palavras[2][TAMANHO_MAXIMO], char *letrasAlfabeto, int valorTotalPalavras[2])
{
    const int VALOR_LETRA_ALFABETO[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    for (int i = 0; i < QUANTIDADE_PALAVRAS; i++)
    {
        for (int j = 0; j < strlen(palavras[i]); j++)
        {
            if (palavras[i][j] == '!' || palavras[i][j] == '?' || palavras[i][j] == ',' || palavras[i][j] == '.')
            {
                continue;
            }
            for (int k = 0; k < strlen(letrasAlfabeto); k++)
            {
                if (palavras[i][j] == letrasAlfabeto[k] || palavras[i][j] == toupper(letrasAlfabeto[k]))
                {
                    valorTotalPalavras[i] += VALOR_LETRA_ALFABETO[k];
                    break;
                }
            }
        }
    }
}

void exibirValorPalavras(int valorTotalPalavras[2])
{
    printf("\n\nValor palavra do jogador 1 = %d\n", valorTotalPalavras[0]);
    printf("Valor palavra do jogador 2 = %d\n\n", valorTotalPalavras[1]);

    if (valorTotalPalavras[0] > valorTotalPalavras[1])
    {
        printf("A palavra do jogador 1 vale mais!\n\n");
    }
    else if (valorTotalPalavras[0] < valorTotalPalavras[1])
    {
        printf("A palavra do jogador 2 vale mais!\n\n");
    }
    else
    {
        printf("As duas palavras têm o mesmo valor!\n\n");
    }
}
