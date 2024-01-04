// Implementar um programa que criptografe uma mensagem usando cifra de substituição

#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

// Protótipos
int validarQuantidadeArgumentos(int argc);
int validarTamanhoChave(const int TAMANHO_CHAVE);
int validarCaracteresAlfabeticos(char *argv[], const int TAMANHO_CHAVE);
void criarMapeamentoChave(const int QUANTIDADE_CARACTERES_ALFABETO, char **chaveMapeamentoMinusculas, char **chaveMapeamentoMaiusculas);
int verificarRepeticaoCaracteres(char *argv[], const int TAMANHO_CHAVE, char *chaveMapeamentoMinusculas, char *chaveMapeamentoMaiusculas);
char *solicitarTextoSimples(void);
char *aplicarCifraSubstituicao(char *argv[], const int TAMANHO_CHAVE, char *textoSimples);
void exibirTextos(char *textoSimples, char *textoCriptografado);

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Portuguese");

    // Verifica se a quantidade de argumentos é válida
    int validacaoQuantidadeArgumentos = validarQuantidadeArgumentos(argc);
    if (validacaoQuantidadeArgumentos == 1)
    {
        return 1;
    }

    // Obtem e valida o tamanho da chave fornecida como argumento
    const int TAMANHO_CHAVE = strlen(argv[1]);

    int validacaoTamanhoArgumento = validarTamanhoChave(TAMANHO_CHAVE);
    if (validacaoTamanhoArgumento == 1)
    {
        return 1;
    }

    // Valida se todos os caracteres na chave são alfabéticos
    int validacaoValorAgumento = validarCaracteresAlfabeticos(argv, TAMANHO_CHAVE);
    if (validacaoValorAgumento == 1)
    {
        return 1;
    }

    // Cria mapeamento de caracteres para minúsculas e maiúsculas
    const int QUANTIDADE_CARACTERES_ALFABETO = 26;

    char *chaveMapeamentoMinusculas;
    char *chaveMapeamentoMaiusculas;

    criarMapeamentoChave(QUANTIDADE_CARACTERES_ALFABETO, &chaveMapeamentoMinusculas, &chaveMapeamentoMaiusculas);

    // Verifica se há repetição de caracteres na chave
    int verificacaoRepeticaoArgumento = verificarRepeticaoCaracteres(argv, TAMANHO_CHAVE, chaveMapeamentoMinusculas, chaveMapeamentoMaiusculas);
    if (verificacaoRepeticaoArgumento == 1)
    {
        return 1;
    }

    // Obtem o texto simples do usuário
    char *textoSimples = solicitarTextoSimples();

    // Criptografa o texto simples
    char *textoCriptografado = aplicarCifraSubstituicao(argv, TAMANHO_CHAVE, textoSimples);

    // Exibe o texto original e cifrado
    exibirTextos(textoSimples, textoCriptografado);

    // Libera memória alocada dinamicamente
    free(textoSimples);
    free(textoCriptografado);

    return 0;
}

int validarQuantidadeArgumentos(int argc)
{
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

    return 0;
}

int validarTamanhoChave(const int TAMANHO_CHAVE)
{
    const int TAMANHO_ESPERADO = 26;

    if (TAMANHO_CHAVE != TAMANHO_ESPERADO)
    {
        printf("\nNão foi possivel criar a cifra, pois foi fonercida uma chave com %d caracter(es), sendo que o tamanho esperado é de %d caracteres!\n\n", TAMANHO_CHAVE, TAMANHO_ESPERADO);
        return 1;
    }

    return 0;
}

int validarCaracteresAlfabeticos(char *argv[], const int TAMANHO_CHAVE)
{
    bool ehLetra = true;

    for (int i = 0; i < TAMANHO_CHAVE; i++)
    {
        if (!(argv[1][i] >= 'a' && argv[1][i] <= 'z') && !(argv[1][i] >= 'A' && argv[1][i] <= 'Z'))
        {
            printf("\nNão foi possível criar a cifra, pois na chave informada: %c não é um caractere alfabético!", argv[1][i]);
            ehLetra = false;
        }
    }

    if (ehLetra == false)
    {
        printf("\n\n");
        return 1;
    }

    return 0;
}

void criarMapeamentoChave(const int QUANTIDADE_CARACTERES_ALFABETO, char **chaveMapeamentoMinusculas, char **chaveMapeamentoMaiusculas)
{
    *chaveMapeamentoMinusculas = (char *)malloc(((QUANTIDADE_CARACTERES_ALFABETO) + 1) * sizeof(char));
    *chaveMapeamentoMaiusculas = (char *)malloc(((QUANTIDADE_CARACTERES_ALFABETO) + 1) * sizeof(char));

    if (*chaveMapeamentoMinusculas == NULL || *chaveMapeamentoMaiusculas == NULL)
    {
        printf("falha ao alocar memória");
        free(chaveMapeamentoMinusculas);
        free(chaveMapeamentoMaiusculas);
        exit(EXIT_FAILURE);
    }

    // Preenche mapeamentos com caracteres alfabéticos
    for (int i = 0, n = QUANTIDADE_CARACTERES_ALFABETO; i < n; i++)
    {
        (*chaveMapeamentoMinusculas)[i] = 'a' + i;
        (*chaveMapeamentoMaiusculas)[i] = 'A' + i;
    }

    // Adiciona terminador nulo
    (*chaveMapeamentoMinusculas)[QUANTIDADE_CARACTERES_ALFABETO] = '\0';
    (*chaveMapeamentoMaiusculas)[QUANTIDADE_CARACTERES_ALFABETO] = '\0';
}

int verificarRepeticaoCaracteres(char *argv[], const int TAMANHO_CHAVE, char *chaveMapeamentoMinusculas, char *chaveMapeamentoMaiusculas)
{
    bool caractereRepetido = false;

    for (int i = 0; i < TAMANHO_CHAVE; i++)
    {
        for (int j = 0; j < TAMANHO_CHAVE; j++)
        {
            // Verifica se há repetição de caracteres
            if ((argv[1][i] == chaveMapeamentoMinusculas[j]) || (argv[1][i] == chaveMapeamentoMaiusculas[j]))
            {
                chaveMapeamentoMinusculas[j] = '0';
                chaveMapeamentoMaiusculas[j] = '0';
                caractereRepetido = false;
                break;
            }
            else
            {
                caractereRepetido = true;
            }
        }
    }

    free(chaveMapeamentoMinusculas);
    free(chaveMapeamentoMaiusculas);

    if (caractereRepetido == true)
    {
        printf("\nNão foi possível realizar a cifra, pois há repetição de caracteres na chave!\n\n");
        return 1;
    }

    return 0;
}

char *solicitarTextoSimples(void)
{
    int tamanhoInicial = 10;
    int tamanhoAtual = tamanhoInicial;

    char *textoSimples = (char *)malloc(tamanhoInicial * sizeof(char));

    if (textoSimples == NULL)
    {
        printf("Falha na alocação de memória");
        exit(EXIT_FAILURE);
    }

    char caractere;
    int indice = 0;
    bool ehTexto = true;

    printf("Por favor, insira o texto simples para a realização da criptografia: ");

    while (ehTexto)
    {
        caractere = getchar();

        if (indice == tamanhoAtual - 1)
        {
            tamanhoAtual *= 2;
            textoSimples = (char *)realloc(textoSimples, tamanhoAtual * sizeof(char));

            if (textoSimples == NULL)
            {
                printf("Falha na alocação de memória");
                free(textoSimples);
                exit(EXIT_FAILURE);
            }
        }

        if (caractere == '\n')
        {
            ehTexto = false;
        }
        else
        {
            textoSimples[indice++] = caractere;
        }
    }

    textoSimples[indice] = '\0';

    return textoSimples;
}

char *aplicarCifraSubstituicao(char *argv[], const int TAMANHO_CHAVE, char *textoSimples)
{
    int tamanhoTextoSimples = strlen(textoSimples);

    char *chaveSubstituicao = (char *)malloc(strlen((argv[1]) + 1) * sizeof(char));
    if (chaveSubstituicao == NULL)
    {
        printf("Falha na alocação de memória");
        free(textoSimples);
        exit(EXIT_FAILURE);
    }

    // Copia a chave fornecida para a chave de substituição
    strcpy(chaveSubstituicao, argv[1]);

    char *textoCriptografado = (char *)malloc(((tamanhoTextoSimples) + 1) * sizeof(char));
    if (textoCriptografado == NULL)
    {
        printf("Falha na alocação de memória");
        free(textoSimples);
        free(chaveSubstituicao);
        exit(EXIT_FAILURE);
    }

    // Ajusta a chave de substituição para caracteres alfabéticos de 'a' até 'z'
    for (int i = 0; i < TAMANHO_CHAVE; i++)
    {
        if ((chaveSubstituicao[i] >= 'a' && chaveSubstituicao[i] <= 'z') || (chaveSubstituicao[i] >= 'A' && chaveSubstituicao[i] <= 'Z'))
        {
            chaveSubstituicao[i] = 'a' + i;
        }
    }

    int contador = 0;

    // Criptografa o texto simples
    for (int i = 0; i < tamanhoTextoSimples; i++)
    {
        if (!(textoSimples[i] >= 'a' && textoSimples[i] <= 'z') && !(textoSimples[i] >= 'A' && textoSimples[i] <= 'Z'))
        {
            textoCriptografado[i] = textoSimples[i];
        }
        else
        {
            for (int j = 0; j < TAMANHO_CHAVE; j++)
            {
                if (textoSimples[i] == tolower(chaveSubstituicao[j]))
                {
                    textoCriptografado[i] = tolower(argv[1][j]);
                }

                if (textoSimples[i] == toupper(chaveSubstituicao[j]))
                {
                    textoCriptografado[i] = toupper(argv[1][j]);
                }
            }
        }
        contador++;
    }

    textoCriptografado[contador] = '\0';

    free(chaveSubstituicao);

    return textoCriptografado;
}

void exibirTextos(char *textoSimples, char *textoCriptografado)
{
    printf("\nTexto Simples: %s", textoSimples);
    printf("\nTexto Cifrado: %s\n\n", textoCriptografado);
}
