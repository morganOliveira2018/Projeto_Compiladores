%option yylineno
%{
    //codigo em C
%}

/* TIPOS DE CARACTERES BÁSICOS */
NUMERO [0-9]
LETRA [a-zA-Z]

/* TIPOS PRIMITIVOS */
INTEIRO {NUMERO}+
REAL {NUMERO}*"."{NUMERO}+
TEXTO \"[^\"]*\"|\'[^']*\'
TYPE "type"

/* TIPOS DE VARIAVEIS */
/*TIPO "inteiro"|"real"|"texto" /**/

/* TOKENS DE ENTRADA E SAIDA DE INFORMAÇÕES */
ENTRADA "<<"
SAIDA ">>"

/* TOKENS DE INICIO E FIM DE PROGRAMA */
INICIO "in"
FINAL "ni"

/* CONDICIONAL E REPETIÇÃO */
IF "inif"
ELSE "infi"
FOR "infor"
WHILE "inwhile"

/* ARITMETICA "+"|"-"|"/"|"*"|"^" */

SIN "sin"
COS "cos"
RAIZ "raiz"
PLUS "++"
LESS "--"

/* LOGICA {MENOR}|{MAIOR}|{MEI}|{MAI}|{II}|{DIF} */
MAIOR ">"
MENOR "<"
IGUAL "="
MAI {MAIOR}{IGUAL}
MEI {MENOR}{IGUAL}
II {IGUAL}{IGUAL}
DIF "!"{IGUAL}
OR "||"
AND "&&"

/* PADRÃO PARA NOME DE VARIAVEIS */
VAR {LETRA}({LETRA}|{NUMERO}|"_")*

/* TOKEN PARA COMENTÁRIO */
COMENTARIO "#".*

/* IGNORAR ESPAÇO, TAB */
IGNORAR [\ \t\s]

/* NÃO ACEITAR QUALQUER VALOR DIFERENTE DO QUE ESTIVER ACIMA NESTE CODIGO */
INVALIDO .
%%
"inteiro" {
    yylval.inteiro = 'i';
    return TIPO;
}
"real" {
    yylval.inteiro = 'r';
    return TIPO;
}
"void" {
    yylval.inteiro = 'v';
    return VOID;
}
"texto" {
    yylval.inteiro = 't';
    return TIPO_TEXTO;
}
"inout" {
    strcpy(yylval.texto, yytext);
    return RETURN;
}
{TYPE} {
    strcpy(yylval.texto, yytext);
    return TYPE;
}
{PLUS} {
    return PLUS;
}
{LESS} {
    return LESS;
}
"+"|"-"|"/"|"*"|"^"|"|"|"%" {
  return *yytext;
}

[=:;,(){}\[\]?] {
    return yytext[0];
}
{RAIZ} {
    return RAIZ;
}
{COS} {
    return COS;
}
{SIN} {
    return SIN;
}
{MENOR} {
    return MENOR;
}
{MAIOR} {
    return MAIOR;
}
{MEI} {
    return MEI;
}
{MAI} {
    return MAI;
}
{II} {
    return II;
}
{DIF} {
    return DIF;
}
{OR} {
    return OR;
}
{AND} {
    return AND;
}
{ENTRADA} {
    return ENTRADA;
}
{SAIDA} {
    return SAIDA;
}
{INICIO} {
    return INICIO;
}
{FINAL} {
    return FINAL;
}
{INTEIRO} {
    yylval.inteiro = atoi(yytext);
    return INTEIRO;
}
{REAL} {
    yylval.real = atof(yytext);
    return REAL;
}
{TEXTO} {
    for(int x=0; x<strlen(yytext); x++){
        yytext[x] = yytext[x+1];
    }
    yytext[strlen(yytext)-1] = '\0';
    strcpy(yylval.texto, yytext);
    return TEXTO;
}
{IF} {
    return IF;
}
{ELSE} {
    return ELSE;
}
{FOR} {
    return FOR;
}
{WHILE} {
    return WHILE;
}
{VAR} {
    strcpy(yylval.texto, yytext);
    return VAR;
}
{COMENTARIO} {
    strcpy(yylval.texto, yytext);
    return COMENTARIO;
}
[\n] {
    /* CONTADOR PARA SALTO DE LINHAS */
    yylineno++;
}
{IGNORAR} {
  /* ignore */
}
{INVALIDO} {
  /* ignore */
}

%%
