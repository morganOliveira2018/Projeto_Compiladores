%{
    //Codigo C
    // https://stackoverflow.com/questions/22407730/bison-line-number-included-in-the-error-messages
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>
    #include <math.h>
    #include <ctype.h>
    #include<stdbool.h>
    extern int yylineno;
    
    int yylex();
    void yyerror(const char *str)
    {
        fprintf(stderr,"Error: %s\n Linha: %d\n", str, yylineno);
    }
    // Construção de uma struct para receber o nome e o valor para cada variavel do tipo real
    typedef struct vars {
		char name[50];
		float value;
		struct vars * prox;
	} VARS;
    
    // Adicionar nova variavel na lista
    VARS * ins(VARS *l, char n[]){
		VARS *new =(VARS*)malloc(sizeof(VARS));
		strcpy(new->name, n);
		new->prox = l;
		return new;
	}
    // Busca uma variável na lista de variáveis
	VARS *srch(VARS *l, char n[]){
		VARS *aux = l;
		while(aux != NULL){
			if(strcmp(n, aux->name)==0){
				return aux;
			}
			aux = aux->prox;
		}
		return aux;
	}
    // Verificar se o valor dado é real
    bool is_real(char test[]){
        int i = 0;
        int ponto = 0;
        do{
            if(isdigit(test[i])!=0 || test[i] == '.'){
                if(test[i]=='.')
                    ponto = ponto + 1;
                if(ponto>1)
                    return false;
                i=i+1;
            }
            else
                return false;
        }while(test[i]!='\0');
        
        return true;
    }

	VARS *rvar;
%}

%union {
    char texto[50];
    double real;
}

// Declaração dos tokens 
%token <real> NUM_REAL 
%token <texto> VARIAVEL
%token <texto> STRING
%token <texto> TIPO_REAL
%token INICIO
%token FINAL
%token RAIZ
%token ATRIB
%token LEITURA
%token ESCREVER
%token <texto> COMENTARIO

%type <real> expre valor
%type <texto> variacoes variacoes2

// Declaração de precedência dos operadores
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

var: TIPO_REAL variacoes {;}
    ;

variacoes: variacoes ',' variacoes2 {sprintf($$, "%s, %s", $1, $3); }
        | variacoes2 {sprintf($$, "%s", $1); }
        ;
variacoes2: VARIAVEL {            
            VARS * aux = srch(rvar, $1);
            if (aux == NULL){
                // Se ainda nao existe variavel com esse nome, se cria uma
                rvar = ins(rvar, $1);
                sprintf($$, "%s", $1);
            }
            else{
                // Se já existe variavel com esse no, informar mensagem de erro
                printf ("A variável '%s' já existe.\n", $1);
            }
        }
        | VARIAVEL ATRIB expre {
            VARS * aux = srch(rvar, $1);
            if (aux == NULL){
                // Se ainda nao existe variavel com esse nome, se cria uma
                rvar = ins(rvar, $1);
            
                VARS * aux2 = srch(rvar, $1);
                if (aux2 == NULL){
                    printf ("Variavel '%s' ainda nao declarada.\n", $1);
                }
                else {
                    // Atribuindo valor a variavel criada
                    aux2->value = $3;
                    sprintf($$, "%s << %f", $1, $3);
                }
            }
            else{
                // Se já existe variavel com esse no, informar mensagem de erro
                printf ("A variavel '%s' ja existe.\n", $1);
            }
        }
        ;

ini: INICIO cod FINAL {printf("PROGRAMA FINALIZADO!\n"); }
    ;

cod: cod input_output | 
    ;

input_output: 
    var 
    |
    ESCREVER '(' STRING ')' {
        printf("%s\n", $3);
    } |
    ESCREVER '(' expre ')' {
        printf("%.1f\n", $3);
    } |
    LEITURA '(' VARIAVEL ')' {
        VARS * aux = srch(rvar, $3);
        if (aux == NULL){
            // se nao existe variavel declarada
            printf ("Variavel '%s' ainda nao foi declarada\n", $3);
        }
        else {
            //se for variavel real
            //verificar se o valor corresponde ao tipo real
            char test[100];
            do{
                int i = 0;
                do{
                    test[i] = '\0';
                    i++;
                }while(test[i]!='\0');

                scanf("%s", &test);
                if( is_real(test)==false )
                    printf ("Valor '%s' deve ser real\n", $3);
                
            }while( is_real(test)==false );
            
            aux->value = atof(test);
            printf("Token de LEITURA: %.1f\n", aux->value);
        }
    } |
    VARIAVEL ATRIB expre {
        // atribuição de variavel
        VARS * aux = srch(rvar, $1);
        if (aux == NULL)
            // se nao existe variavel declarada, mensagem de erro
            printf ("Variável '%s' não foi declarada\n", $1);
        else {
            aux->value = $3;
            //printf("%.2f\n", $3);
        }
    }
    | COMENTARIO {
        printf("Comentario: %s\n", $1);
    }
    | expre {
        printf("Valor: %f\n", $1);
    }
    ;
    
expre: 
    RAIZ '(' expre ')' { 
        $$ = sqrt($3); 
        /* printf("Efetuando raiz(%f):\n", $3);*/
    }
    | expre '+' expre {
        $$ = $1 + $3;
        /* printf("%.1f + %.1f = %.1f\n", $1, $3, $$);*/
    }
    | expre '-' expre {
        $$ = $1 - $3;
        /* printf("%.1f - %.1f = %.1f\n", $1, $3, $$); */
    }
    | expre '*' expre {
        $$ = $1 * $3;
        /* printf("%.1f * %.1f = %.1f\n", $1, $3, $$); */
    }
    | expre '/' expre {
        $$ = $1 / $3;
        /* printf("%.1f / %.1f = %.1f\n", $1, $3, $$); */
    }
    | '|' expre '|' {
        $$ = fabs($2);
        /* printf("%.1f = %.1f\n", $2, $$); */
    }
    | '(' expre ')' {
        $$ = $2;
    } 
    | expre '^' expre {
        $$ = pow($1, $3);
        /* printf("%.1f ^ %.1f = %.1f\n", $1, $3, $$); */
    } 
    | '-' expre %prec UMINUS {
        $$ = -$2;
    }
    | valor { 
        $$ = $1; 
    }
    ;  
    valor: VARIAVEL {    
        VARS * aux = srch(rvar, $1);
        if (aux == NULL)
            printf ("Variável '%s' não foi declarada\n", $1);
        else {
            $$ = aux->value;
        }
    }
    | NUM_REAL {
        $$ = $1;
    }
    ;

%%

#include "lex.yy.c"

int main(){
    yyin=fopen("entrada_morg_semantico.txt", "r");
    // do { yyparse(); }
    // while (!feof(yyin));
    yyparse();
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