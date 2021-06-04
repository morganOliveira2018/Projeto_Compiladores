%option yylineno
%{
    
%}

TIPO_REAL "real"

LETRA [a-zA-Z]+
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

{TIPO_REAL} {
    return TIPO_REAL;
}
[:;,()] {
    return yytext[0];
}
[-+/|*^] {
  return *yytext;
}
[\n] {
    /* CONTADOR PARA SALTO DE LINHAS */
    yylineno++;
}
{INICIO} {
    return INICIO;
}
{FINAL} {
    return FINAL;
}
{ATRIB} {
    return ATRIB;
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
    strcpy(yylval.texto, yytext);
    return COMENTARIO;
}

 /* O FOR É PARA PEGAR A STRING DENTRO DAS ASPAS */
{STRING} {
    for(int x=0; x<strlen(yytext); x++){
        yytext[x] = yytext[x+1];
    }
    yytext[strlen(yytext)-1] = '\0';
    strcpy(yylval.texto, yytext);
    return STRING;
}
{IGNORAR} {
    /* ignore */
}
{INVALIDO} {
    /* ignore */
}
%%