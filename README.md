# Calculadora_Compiladores
Para entender como funciona a usabilidade da linguagem da Morgana consulte o passo a passo a seguir. Esta linguagem foi desenvolvida na disciplina de compiladores. A linguagem está completa, feita a construção da linguagem léxica, sintática e semântica.

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

#### Exemplo URI Online Judge | 1172 | Substituição em Vetor I abaixo:
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
