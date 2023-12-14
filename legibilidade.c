// Implementar um programa que calcule o nível de legibilidade de um texto, por meio do índice de Coleman-Liau.

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

    // Liberar o espaço alocado na memória
    free(texto);

    return 0;
}

// Função para receber o texto do usuário
char *recebeTexto(void)
{
    int tamanhoInicial = 10;
    int tamanhoAtual = tamanhoInicial;

    // Alocar uma quantidade incial de memória para o texto
    char *texto = (char *)malloc(tamanhoInicial * sizeof(char));

    // Verificar se a alocação de memória falhou
    if (texto == NULL)
    {
        printf("Falha na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }

    printf("Por favor, insira o texto para análise do grau de dificuldade (pressione ENTER para finalizar):\n");

    int indice = 0;
    char caractere;

    while (1)
    {
        caractere = getchar();

        // Verificar se é necessário alocar mais memória
        if (indice == tamanhoAtual - 1)
        {
            tamanhoAtual *= 2;
            texto = (char *)realloc(texto, tamanhoAtual * sizeof(char));

            // Verificar se a realocação de memória falhou
            if (texto == NULL)
            {
                printf("Falha na alocação de memória.\n");
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

// Função para analisar o texto e calcular o índice de Coleman-Liau
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
                // Verificar se o próximo caractere é um espaço em branco ou o final da string
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

    // Fórmula de Coleman-Liau para definir o nível de legibilidade
    float mediaLetras = (float)quantidadeLetras / (float)quantidadePalavras * 100;
    float mediaSentencas = (float)quantidadeSentencas / (float)quantidadePalavras * 100;
    float indiceColemanLiau = 0.0588 * mediaLetras - 0.296 * mediaSentencas - 15.8;

    return indiceColemanLiau;
}

// Função para imprimir o resultado da análise
void imprimeAnaliseTexto(float resultado)
{
    // Imprime no terminal o grau de legibilidade
    if (resultado < 1)
    {
        printf("Nível de leitura: Menor que 1");
    }
    else if (resultado >= 16)
    {
        printf("Nível de leitura: 16+");
    }
    else
    {
        printf("Nível de leitura: %.0f", resultado);
    }
}