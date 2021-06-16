# Linguagem de compiladores

Para entender como funciona a usabilidade da linguagem da Morgana consulte o passo a passo a seguir. Esta linguagem foi desenvolvida na disciplina de compiladores. A linguagem está completa, feita a construção da linguagem léxica, sintática e semântica.

## Instalação e configuração do ambiente Windows

Baixe a pasta win_flex_bison-2.5.24 no [Drive](https://drive.google.com/drive/folders/1iF_qLn7y_w6hLrR_wdNnitkrA_Ob3dxy?usp=sharing) para instalar duas ferrementas usadas: 
1. Flex 
2. Bison

Para conferir corretamente se as extensões flex e bison foram reconhecidas como variaveis de ambiente, basta abrir o cmd:

Obs: o caminho inserido no PATH da variavel de ambiente pode ser: C:\win_flex_bison-2.5.24
```bash
> flex --version
flex 2.6.4 
```
```bash
> bison --version
bison (GNU Bison) 3.7.4
Written by Robert Corbett and Richard Stallman.

Copyright (C) 2020 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

## Uso da linguagem

#### Marcadores de início e fim do programa
```
Inicio
  @@ ...
  /* ... */
Fim do programa
```

#### Comentário de linha única
```
  @@ para comentar uma linha, adicione dois arrobas na frente da linha
```
#### Comentário de múltiplas linhas
```
  /* ... */
```
#### Tipos
- int: aceita um número inteiro `int num = 7` 
- float: aceita um número real `float a = 10.0`
- string: aceita uma letra minusculo ou maiusculo `var1 = "m"`
- string: aceita uma string minusculo ou maiusculo `nome = "morgana"`

#### Declaração de variáveis
- com um caractere
```
float a
```
- mais de um caractere
```
float soma 
```
- misturando letras e números
```
float area1
```
- sequência de declarações do tipo inteiro
```
int num = 8, num2 = 10, num3 = 20
```
- sequência de declarações do tipo real
```
float a = 10.0, b = 10.5, c = 30.5, area = a * b * c
```
- sequência de declarações do tipo texto
```
string nome = "morgana", nome2 = "marcos"
```
- declarações do tipo vetor para variavel inteira, float e string
```
int vetIn[10]
float vetFn[10]
string vetS[5]
```

#### Atribuição de valores
```
a = 5
b = 5
c = 10
area = a * b * c
```

#### Operação de escrita
```
escreva("Olá Mundo!")
escreva("O valor de a: ", a, "\n")
escreva("O valor de b: ", b, "\n")
escreva("Soma de a + b", a + b, "\n")
escreva("O vet3[0] = ", vet3[0], "\n")
escreva("O vet3[1] = ", vet3[1], "\n")
escreva("O vet3[2] = ", vet3[2], "\n")
```

#### Operação de leitura
```
float altura
escreva("Digite sua altura: ")
leia(altura)
```
#### Operação de leitura com comentário
```
escreva("") @@ escrevendo vazio na tela
escreva("") /* ... */
```
#### Operação de comentário em bloco
```
/* escreva("") 
   escreva("")  
*/
```

#### Operações matemáticas
```
escreva("Soma: ")
escreva(5.0 + 10.0)

escreva("Subtração: ")
escreva(5.0 - 10.0)

escreva("Multiplicação: ")
escreva(5.0 * 10.0)

escreva("Divisão: ")
escreva(5.0 / 10.0)

escreva("Exponenciação: ")
escreva(5.0 ^ 10.0)

escreva("Radiciação: ")
escreva(raiz(4))

escreva("Módulo:")
escreva(|-10|)
```
#### Operação somente de IF 
```
IF (n==2) { 
    escreva(primeiroTermo," ", segundoTermo, "\n") 
}
```
#### Operação de If e Else
```
IF (n==2) { 
      escreva(primeiroTermo," ", segundoTermo, "\n") 
} ELSE {
      escreva(primeiroTermo," ", segundoTermo, " ") 
}
```
#### Operação de If, While e Else
```
int a, b
leitura(a)
leitura(b)

IF(a > b){ 
    WHILE(a*a>b){  
      a-- 
      escreva("A", "\n")
    }
  }ELSE{
    escreva("B")
  }
```
#### Operação do operador ternario 
```
  int num = 5 
  num > 0 ? num++ : num-- ; 
  escreva("ternario:", num, "\n")
```
#### Operação do FOR
```
  int x 
  
  FOR (x = 1; x <= 10; x++) {  
    escreva(x, "\n")
  }
```
#### Operação do FOR com leitura
```
  int vetIn[10]
  int i

  FOR (i = 0; i < 10; i++) {
       leitura(vetIn[i])
  }
```
#### Operação do FOR com IF e atribuicao de novos elementos no vetor
```
  FOR (i = 0; i < 10; i++) {
       IF (vetIn[i] <= 0) {
          vetIn[i] = 1 
       }
  }
```
#### Operação do FOR com escrita de cada elemento em seu respectiva posição
```
  FOR (i = 0; i < 10; i++) {
       escreva("X [", i, "] = ", vetIn[i])
  }
```
#### Operação de atribuição nas posições do vetor
```
  int vet1[2]
  int k = 1, l = 2
  string vet4[5]
  string nome = "morgana", nome2 = "morg", nome3 = "morgan"

  vet4[1] = nome
  vet4[2] = nome2
  vet4[3] = nome3
  vet1[0] = k 
  vet1[1] = l
```
#### Operação de escrita de cada posição do vetor
```
  escreva("O k = ", k, "O l = ", l) @@ int
  escreva("\n", vet4[1], vet4[2], vet4[3]) @@ string 
  escreva(vet1[0]) @@ int
  escreva(vet1[1]) @@ int
```
#### Estrutura de uma função sem parametros e a chamada da função
```
    void function teste() {
      escreva("=========================")
      int m = 3, n = 5, soma = m + n
      escreva("A soma de m e n: ", soma) 
    }
   
    teste() @@ chamada da funcao acima
```

#### Expressões matemáticas e precedência
##### Ordem de precedência
- 1°: Parênteses 
- 2°: Exponenciação
- 3°: Multiplicação e divisão tem mesmo grau de precedência
- 4°: Soma e subtração tem mesmo grau de precedência
- 5º: Expressões lógicas

```
escreva(((a / b) + (a * b) - 1))
```
#### Exemplo URI Online Judge - [Substituição em Vetor I](https://www.urionlinejudge.com.br/judge/pt/problems/view/1172) abaixo:
- Faça um programa que leia um vetor X[10]. Substitua a seguir, todos os valores nulos e negativos do vetor X por 1. Em seguida mostre o vetor X.
#### Entrada:
- A entrada contém 10 valores inteiros, podendo ser positivos ou negativos.
#### Saída:
- Para cada posição do vetor, escreva "X[i] = x", onde i é a posição do vetor e x é o valor armazenado naquela posição.

```
Inicio

   int vetIn[10], i

   escreva("=======================================","\n", "| Substituicao em Vetor I - URI - 1172|", "\n")        
   escreva("=======================================","\n")
   escreva("Determine os elementos que compoe o vetor:","\n")
   FOR (i = 0; i < 10; i++) {
       leitura(vetIn[i])
   }

   FOR (i = 0; i < 10; i++) {
       IF (vetIn[i] <= 0) {
          vetIn[i] = 1 
       }
   }

   FOR (i = 0; i < 10; i++) {
       escreva("X [", i, "] = ", vetIn[i])
   }
    

Fim do programa
```

#### Exemplo URI Online Judge - [Fibonacci Fácil](https://www.urionlinejudge.com.br/judge/pt/problems/view/1151) abaixo:
- A seguinte sequência de números 0 1 1 2 3 5 8 13 21... é conhecida como série de Fibonacci. Nessa sequência, cada número, depois dos 2 primeiros, é igual à soma dos 2 anteriores. Escreva um algoritmo que leia um inteiro N (N < 46) e mostre os N primeiros números dessa série.
#### Entrada:
- O arquivo de entrada contém um valor inteiro N (0 < N < 46).
#### Saída:
- Os valores devem ser mostrados na mesma linha, separados por um espaço em branco. Não deve haver espaço após o último valor.

```
Inicio

    escreva("===============================","\n", "| Fibonnaci Facil - URI - 1151|", "\n")        
    escreva("===============================","\n")        
    int n, i = 3, primeiroTermo = 0, segundoTermo = 1, proximoTermo
    escreva("Escreva um valor inteiro para N", "\n")
    leitura(n)  /* Numero inteiro */ 
    
    IF (n==0) {
        escreva("Fib(0) = ", n, "\n")
    }
    IF (n==1) {
        escreva("Fib(1) = ", primeiroTermo, "\n")
    } ELSE {
        IF (n==2) { 
            escreva(primeiroTermo," ", segundoTermo, "\n") 
        }ELSE {
            escreva(primeiroTermo," ", segundoTermo, " ") 
        } WHILE (i<=n){ 
            proximoTermo = primeiroTermo + segundoTermo 
            primeiroTermo = segundoTermo
            segundoTermo = proximoTermo
        IF (i==n) {
            escreva(proximoTermo, "\n")
        } ELSE {
            escreva(proximoTermo, " ")
        }
          i++
        }
    }

Fim do programa

```

## Contato
- [Linkedin](www.linkedin.com/in/morgana-ribeiro-dev)
- [Instagram](https://www.instagram.com/morgana_ribeir0/)