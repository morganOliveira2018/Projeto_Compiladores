%{
    //Codigo C
    // https://stackoverflow.com/questions/18049349/1-of-has-no-declared-type/18049801
    // https://stackoverflow.com/questions/22407730/bison-line-number-included-in-the-error-messages
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>
    extern int yylineno;
    
    int yylex();
    void yyerror(const char *str)
    {
        fprintf(stderr,"Error: %s\n Linha: %d\n", str, yylineno);
    }

%}

%union {
    char texto[50];
    double real;
    int integer;
}

%token <real> NUM_REAL "real"
%token <integer> NUM_INTEGER
%token <texto> VARIAVEL
%token <texto> STRING
%token <texto> TIPO
%token INICIO
%token FINAL
%token RAIZ
%token ATRIB
%token LEITURA
%token ESCREVER
%token COMENTARIO
%type <real> expre valor
%type <texto> variavel variacoes

%left '+' '-'
%left '*' '/' 
%right '^'
%left ')'
%right '('

// O '|' e 'UNIMUS' não tem associatividade, ou seja, left ou right e estão na mais alta precedência
// O %nonassoc define a ordem de precedência do mais BAIXO para o mais ALTO
%nonassoc '|' UMINUS


//%Iniciando as regras do analisador sintático
%%
begin: var begin | ini
     ;

var: TIPO variacoes {printf("DECLARACAO: %s %s\n", $1, $2); }
    ;

variacoes: VARIAVEL ',' variacoes {sprintf($$, "%s, %s", $1, $3); }
        | VARIAVEL {sprintf($$, "%s", $1); }
        | VARIAVEL ATRIB variavel ',' variacoes {sprintf($$, "%s << %s, %s", $1, $3, $5); }
        | VARIAVEL ATRIB variavel {sprintf($$, "%s << %s", $1, $3); }
        ;
variavel: STRING  {sprintf($$, "%s", $1); }
        | NUM_INTEGER  {sprintf($$, "%d", $1); }
        | NUM_REAL {sprintf($$, "%f", $1); }
        ;

ini: INICIO cod FINAL  
    ;

cod: cod input_output | 
    ;

input_output:  
    ESCREVER '(' STRING ')' {
        printf("Funcionou o escrever("") no codigo\n");
    } |
    ESCREVER '(' expre ')' {
        printf("Calculei uma expressao aritmetica!");
    } |
    LEITURA '(' VARIAVEL ')' {
        printf("Token de LEITURA\n");
    } |
    VARIAVEL ATRIB expre {
        printf("%.2f\n", $3);
    }
    | COMENTARIO {
        printf("Comentario!\n");
    }
    ;
expre:    
    RAIZ '(' expre ')' { 
        $$ = sqrt($3); 
        printf("Efetuando raiz(%f):\n", $3);
    }
    | expre '+' expre {
        $$ = $1 + $3;
        printf("Calculo da Soma: %.1f + %.1f = %.1f\n", $1, $3, $$);
    }
    | expre '-' expre {
        $$ = $1 - $3;
        printf("Calculo da Subtracao: %.1f - %.1f = %.1f\n", $1, $3, $$);
    }
    | expre '*' expre {
        $$ = $1 * $3;
        printf("Calculo do Produto: %.1f * %.1f = %.1f\n", $1, $3, $$);
    }
    | expre '/' expre {
        $$ = $1 / $3;
        printf("Calculo da Divisao: %.1f / %.1f = %.1f\n", $1, $3, $$);
    }
    | '|' expre '|' {
        $$ = fabs($2);
        printf("Calculo do modulo: %f = %f\n", $2, $$);
    }
    | '(' expre ')' {
        $$ = $2;
    } 
    | expre '^' expre {
        $$ = pow($1, $3);
        printf("Calculo de Exponenciacao: %.1f ^ %.1f = %.1f\n", $1, $3, $$);
    } 
    | '-' expre %prec UMINUS {
        $$ = -$2;
    }
    | valor { 
        $$ = $1; 
    }
    | VARIAVEL {}
    ;  
    valor: NUM_INTEGER { 
        $$ = $1; 
    }
    | NUM_REAL {
        $$ = $1;
    }
    ;

%%

#include "lex.yy.c"

int main(){

    yyin=fopen("entrada_morg.txt", "r");
    do { yyparse(); }
    while (!feof(yyin));
    //yyparse();
    yylex();
    fclose(yyin);
    
    return 0;

    /* Testando os TOKENS di arquivo.l usado pelo flex */
    // int token;
    // while((token = yylex()) != 0){
    //     printf("Token %d (%s)\n", token, yytext);
    // }
    /* Teste de debug do arquivo.y usado pelo Bison */
    // #if YYDEBUG         
    //     yydebug = 1;     
    // #endif

}

int yywrap(){
    return 0;
}