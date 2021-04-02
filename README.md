# Calculadora_Compiladores
Para entender como funciona a usabilidade da linguagem da Morgana consulte o passo a passo a seguir.

# Morgana Ribeiro -- 

Esta linguagem está sendo desenvolvida na disciplina de compiladores. A linguagem ainda não está completa, foi somente feita a construção da linguagem léxica e sintática.

#### Marcadores de início e fim do programa
```
Inicio
    @@ ...
Fim do programa
```

#### Comentários
```
@@ para comentar uma linha, adicione dois arrobas na frente da linha
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

#### Exemplo abaixo:
```
real a, b, c, B, H
real area1 << 5.5, result
int num << 7.3, day << "dia", var1 << "m"

Inicio

  escreva("Calculo da area do retângulo:")
  escreva("") @@ escrevendo vazio na tela

  escreva("Digite a base: ")
  leia(B)

  escreva("Digite a altura: ")
  leia(H)

  escreva("")
  escreva("A area do retangulo é: ")
  area << H * B
  escreva(area)

  escreva("Calculo de Bhaskara:")
  escreva("Digite o valor de a: ")
  leia(a)
  escreva("Digite o valor de b: ")
  leia(b)
  escreva("Digite o valor de c: ")
  leia(c)
  result << raiz(b^2-4*2*c)/2*a
  escreva(result)

Fim do programa
```
