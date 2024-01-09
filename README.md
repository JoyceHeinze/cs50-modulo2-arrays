<h4 align="center"> 
	💻 CS50: “Introduction to Computer Science” - Módulo 2: Arrays 💻
</h4>

<p align="center">
 <a href="#sobre">Sobre</a> •
 <a href="#tecnologia">Tecnologia</a> • 
 <a href="#executar">Como executar</a> • 
 <a href="#exemplos">Exemplos</a> • 
 <a href="#autora">Autora</a> • 
 <a href="#termos">Termos de uso</a>
</p>

## <a name ="sobre"></a>📋 Sobre

📚 Este repositório contém os exercícios do módulo 2 do curso "Introduction to Computer Science" de Harvard, oferecido pela [Fundação Estudar](https://perfil.napratica.org.br/e).

🎯 O propósito destes exercícios é desenvolver habilidades em lógica de programação utilizando arrays. 

📌 **Exercício 1 - Legibilidade**: calcular o nível de legibilidade de um texto, por meio do índice de Coleman-Liau.

📌 **Exercício 2 - Cifra de César**: criptografar uma mensagem usando a cifra de César.

📌 **Exercício 3 - Cifra de Substituição (desafio)**: criptografar uma mensagem usando uma cifra de substituição.

📌 **Exercício/Desafio 4 - Scrabble**: determinar, entre duas palavras, qual vale mais.

##  <a name="tecnologia"></a>🛠 Tecnologia

A seguinte ferramenta foi usada para a realização dos exercícios e desafios: **[Linguagem de programação C](https://devdocs.io/c/)**
  
---

## 🚀 <a name="executar"></a>Como executar

**Para todos os arquivos com os exercícios:**

1. **Compile o programa usando um compilador C, por exemplo, GCC:**
    ```bash
    gcc nome_arquivo.c -o nome_executavel
    ```

    Certifique-se de substituir `nome_arquivo.c` pelo nome do seu arquivo-fonte e `nome_executavel` pelo nome que você deseja para o executável.

2. **Execute o programa:**
    ```bash
    ./nome_executavel
    ```
    Substitua `nome_executavel` pelo nome que você escolheu na etapa de compilação.

    Se você estiver usando o exemplo do "Exercício 1 - Legibilidade", pode ser algo como:
    ```bash
    ./legibilidade
    ```

## 🧪 <a name="exemplos"></a>Exemplos

### 📑 Exercício 1 - Legibilidade

**Entrada:**
```plaintext
Por favor, insira o texto para análise do grau de dificuldade (pressione ENTER para finalizar): Would you like them here or there? I would not like them here or there. I would not like them anywhere.
```

**Saída Esperada:**
```plaintext
Nível de leitura: 2
```

### 📑 Exercício 2 - Cifra de César

**Argumento em linha de comando: (Sem chave)**

```plaintext
 .\nome_executavel
```

**Saída Esperada:**
```plaintext
Não foi possível realizar a cripitografia, pois a chave não foi informada!
```

**Argumento em linha de comando (Com chave):**

```plaintext
 .\nome_executavel 1
```

**Entrada:**
```plaintext
Por favor, informe o texto para realizar a criptografia: Hello, world! (aBcD)
```

**Saída Esperada:**
```plaintext
Texto Simples: Hello, world! (aBcD)
Texto Cifrado: Ifmmp, xpsme! (bCdE)
```

### 📑 Exercício 3 - Cifra de Substituição (desafio)

**Argumento em linha de comando: (Sem chave)**

```plaintext
 .\nome_executavel
```

**Saída Esperada:**
```plaintext
Não foi possível realizar a cripitografia, pois a chave não foi informada!
```

**Argumento em linha de comando (Com chave):**

```plaintext
 .\nome_executavel VCHPRZGJNTLSKFBDQWAXEUYMOI
```

**Entrada:**
```plaintext
Por favor, insira o texto simples para a realização da criptografia: Hello, world! (aBcD) 
```

**Saída Esperada:**
```plaintext
Texto Simples: Hello, world! (aBcD)
Texto Cifrado: Jrssb, ybwsp! (vChP)
```

### 📑 Exercícios/Desafio 4 - Scrabble

**Entrada:**
```plaintext
Jogador 1 - insira a palavra para analise do valor: COMPUTER

Jogador 2 - insira a palavra para analise do valor: science
```

**Saída Esperada:**
```plaintext
Valor palavra do jogador 1 = 14  
Valor palavra do jogador 2 = 11  

A palavra do jogador 1 vale mais!
```

## <a name="autora"></a>👩‍💻 Autora

Feito com ❤️ por Joyce Heinze 👋🏽 [Entre em contato!](mailto:joyceheinze@ufrrj.br)

## <a name="termos"></a>📋 Termos de Uso

Este projeto é destinado apenas para fins de demonstração e aprendizado.
