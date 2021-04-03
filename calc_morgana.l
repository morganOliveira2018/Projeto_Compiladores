%option yylineno
%{
    
%}

TIPO "int"|"real"|"texto"

LETRA [a-zA-Z]+
NUM_INTEGER [0-9]+
NUM_REAL [0-9]+\.?[0-9]*
STRING \".*\"
RAIZ "raiz"

VARIAVEL {LETRA}({LETRA}|{NUM_REAL}|"-"|"_")*
COMENTARIO "@@".*
ATRIB "<<"

LEITURA "leia"
ESCREVER "escreva"

INICIO "Inicio"
FINAL "Fim do programa"

IGNORAR [\ \t\s]

INVALIDO .
%%

[:;,()] {
    return yytext[0];
}
[-+/|*^] {
  return *yytext;
}
[\n] {
    yylineno++;
}
{INICIO} {
    return INICIO;
}
{FINAL} {
    return FINAL;
}
{TIPO} {
    strcpy(yylval.texto, yytext);
    return TIPO;
}
{ATRIB} {
    return ATRIB;
}
{NUM_INTEGER} {
    yylval.integer = atoi(yytext);
    return NUM_INTEGER;
}
{NUM_REAL} {
    yylval.real = atof(yytext);
    return NUM_REAL;
}
{RAIZ} {
    return RAIZ;
}
{LEITURA} {
    return LEITURA;
}
{ESCREVER} {
    return ESCREVER;
}
{VARIAVEL} {
    strcpy(yylval.texto, yytext);
    return VARIAVEL;
}
{COMENTARIO} {
    return COMENTARIO;
}
{STRING} {
    strcpy(yylval.texto,yytext);
    return STRING;
}
{IGNORAR} {
    /* ignore */
}
{INVALIDO} {
    /* ignore */
}
%%