// Implementar um programa que calcule o n�vel de legibilidade de um texto, por meio do �ndice de Coleman-Liau.

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *recebeTexto(void);
float analisaTexto(char *texto);
void imprimeAnaliseTexto(float resultado);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    char *texto = recebeTexto();
    float resultado = analisaTexto(texto);
    imprimeAnaliseTexto(resultado);

    // Liberar o espa�o alocado na mem�ria
    free(texto);

    return 0;
}

// Fun��o para receber o texto do usu�rio
char *recebeTexto(void)
{
    int tamanhoInicial = 10;
    int tamanhoAtual = tamanhoInicial;

    // Alocar uma quantidade incial de mem�ria para o texto
    char *texto = (char *)malloc(tamanhoInicial * sizeof(char));

    // Verificar se a aloca��o de mem�ria falhou
    if (texto == NULL)
    {
        printf("Falha na aloca��o de mem�ria.\n");
        exit(EXIT_FAILURE);
    }

    printf("Por favor, insira o texto para an�lise do grau de dificuldade (pressione ENTER para finalizar):\n");

    int indice = 0;
    char caractere;

    while (1)
    {
        caractere = getchar();

        // Verificar se � necess�rio alocar mais mem�ria
        if (indice == tamanhoAtual - 1)
        {
            tamanhoAtual *= 2;
            texto = (char *)realloc(texto, tamanhoAtual * sizeof(char));

            // Verificar se a realoca��o de mem�ria falhou
            if (texto == NULL)
            {
                printf("Falha na aloca��o de mem�ria.\n");
                exit(EXIT_FAILURE);
            }
        }

        // Verificar se Enter foi presseionado
        if (caractere == '\n')
        {
            break;
        }
        else
        {
            texto[indice++] = caractere;
        }
    }

    // Adicionar o caractere nulo no final para formar a string completa
    texto[indice] = '\0';

    return texto;
}

// Fun��o para analisar o texto e calcular o �ndice de Coleman-Liau
float analisaTexto(char *texto)
{
    char *palavras;

    // Separar o texto usando " " como delimitador
    palavras = strtok(texto, " ");

    int quantidadePalavras = 0;
    int quantidadeLetras = 0;
    int quantidadeSentencas = 0;

    while (palavras)
    {
        for (int i = 0, n = strlen(palavras); i < n; i++)
        {
            if (palavras[i] == '!' || palavras[i] == '?' || palavras[i] == '.')
            {
                // Verificar se o pr�ximo caractere � um espa�o em branco ou o final da string
                if (palavras[i + 1] == ' ' || palavras[i + 1] == '\0')
                {
                    quantidadeSentencas++;
                }
            }
            else if ((palavras[i] >= 'a' && palavras[i] <= 'z') || (palavras[i] >= 'A' && palavras[i] <= 'Z'))
            {
                quantidadeLetras++;
            }
        }

        quantidadePalavras++;
        palavras = strtok(NULL, " ");
    }

    // F�rmula de Coleman-Liau para definir o n�vel de legibilidade
    float mediaLetras = (float)quantidadeLetras / (float)quantidadePalavras * 100;
    float mediaSentencas = (float)quantidadeSentencas / (float)quantidadePalavras * 100;
    float indiceColemanLiau = 0.0588 * mediaLetras - 0.296 * mediaSentencas - 15.8;

    return indiceColemanLiau;
}

// Fun��o para imprimir o resultado da an�lise
void imprimeAnaliseTexto(float resultado)
{
    // Imprime no terminal o grau de legibilidade
    if (resultado < 1)
    {
        printf("N�vel de leitura: Menor que 1");
    }
    else if (resultado >= 16)
    {
        printf("N�vel de leitura: 16+");
    }
    else
    {
        printf("N�vel de leitura: %.0f", resultado);
    }
}