# Linguagem de compiladores

Para entender como funciona a usabilidade da linguagem da Morgana consulte o passo a passo a seguir.

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
- int: aceita um número inteiro `int num << 7.3` 
- real: aceita um número real `real a << 10.0`
- texto: aceita uma letra minusculo ou maiusculo `var1 << "m"`
- texto: aceita uma string minusculo ou maiusculo `day << "dia"`

#### Declaração de variáveis
- com um caractere
```
real a
```
- mais de um caractere
```
real soma 
```
- misturando letras e números
```
real area1
```
- sequência de declarações de tipos distintos
```
int num << 7.3, day << "dia", var1 << "m"
```
#### Atribuição de valores
```
a << 5
b << 5
area << a * b
```

#### Operação de escrita
```
escreva("Olá Mundo!")
escreva(a)
escreva(5.0)
escreva(a + b)
```

#### Operação de leitura
```
real altura
escreva("Digite sua altura: ")
leia(altura)
```
#### Operação de leitura com comentário
```
escreva("") @@ escrevendo vazio na tela
```

#### Operações matemáticas
```
escreva("Soma: ")
escreva(5.0 + 10)

escreva("Subtração: ")
escreva(5.0 - 10)

escreva("Multiplicação: ")
escreva(5.0 * 10)

escreva("Divisão: ")
escreva(5.0 / 10)

escreva("Exponenciação: ")
escreva(5.0 ^ 10)

escreva("Radiciação: ")
escreva(raiz(4))

escreva("Módulo:")
escreva(|-10|)
```

#### Expressões matemáticas e precedência
##### Ordem de precedência
- 1°: Parênteses 
- 2°: Exponenciação
- 3°: Multiplicação e divisão tem mesmo grau de precedência
- 4°: Soma e subtração tem mesmo grau de precedência

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

   int vetIn[10]
   int i

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

    int n, i = 3, primeiroTermo = 0, segundoTermo = 1, proximoTermo
    leitura(n)  /* Numero inteiro N */
    
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