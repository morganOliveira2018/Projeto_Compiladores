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

    // Adicionar nova variavel do tipo real na lista
    VARS * ins(VARS *l, char n[]){
		VARS *new =(VARS*)malloc(sizeof(VARS));
		strcpy(new->name, n);
		new->prox = l;
		return new;
	}
    
    // Busca uma variável do tipo real na lista de variáveis
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

    // Construção de uma struct para receber o nome e o valor para cada variavel do tipo string
    typedef struct varts {
		char name[50];
		char value[100];
		struct varts * prox;
	} VARTS;

    // Adicionar nova variável do tipo string na lista 
    VARTS * inst(VARTS *l, char n[]){
		VARTS *new =(VARTS*)malloc(sizeof(VARTS));
		strcpy(new->name, n);
        strcpy(new->value, "");
		new->prox = l;
		return new;
	}

    // Busca uma nova variável do tipo string na lista de variáveis
    VARTS *srcht(VARTS *l, char n[]){
		VARTS *aux = l;
		while(aux != NULL){
			if(strcmp(n,aux->name)==0){
				return aux;
			}
			aux = aux->prox;
		}
		return aux;
	}

    // Construção de uma struct para receber o nome e o valor para cada variavel do tipo inteiro
    typedef struct varsi {
		char name[50];
		int value;
		struct varsi * prox;
	} VARSI;

    // Adicionar nova variavel inteiro na lista de variáveis inteiro
    VARSI * insi(VARSI *l, char n[]){
		VARSI *new =(VARSI*)malloc(sizeof(VARSI));
		strcpy(new->name, n);
		new->prox = l;
		return new;
	}

    // Busca uma variável inteiro na lista de variáveis inteiro
	VARSI *srchi(VARSI *l, char n[]){
		VARSI *aux = l;
		while(aux != NULL){
			if(strcmp(n, aux->name)==0){
				return aux;
			}
			aux = aux->prox;
		}
		return aux;
	}

    // Verificar se o valor dado é inteiro
    bool is_int(char test[]){
        int i = 0;
        int ponto = 0;
        do{
            if(isdigit(test[i])!=0){
                i=i+1;
            }
            else
                return false;
        }while(test[i]!='\0');
        
        return true;
    }

    VARS *rvar;
    VARSI *ivar;
    VARTS *tvar;
%}

%union {
    char texto[50];
    double real;
    int inteiro;
}

// Declaração dos tokens 
%token <real> NUM_REAL 
%token <inteiro> NUM_INT
%token <texto> VARIAVEL
%token <texto> STRING
%token <texto> LOGICO
%token <texto> TIPO_REAL TIPO_INT TIPO_TEXT
%token INICIO
%token FINAL
%token RAIZ
%token ATRIB
%token LEITURA
%token ESCREVER
%token <texto> COMENTARIO

%type <real> expre valor logico
%type <texto> variacoes variacoes2 variacoesi variacoesi2 variacoet variacoet1

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

var: TIPO_REAL variacoes 
    { printf("Declara %s: %s\n", $1, $2);} // declaração de Real 
    | TIPO_INT variacoesi 
    { printf("Declara %s: %s\n", $1, $2); } // declaração de Inteiro
    | TIPO_TEXT variacoet 
    {printf("Declara %s: %s\n", $1, $2);} // declaração de String
    ;

// Declaração de varias variaveis do tipo real
variacoes: variacoes ',' variacoes2 { 
          sprintf($$, "%s, %s", $1, $3); 
        }
        | variacoes2 { sprintf($$, "%s", $1); } 
        ;

// Variacoes para o tipo real
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

// declaração de varias variaveis do tipo int
variacoesi: variacoesi ',' variacoesi2 
        {
          sprintf($$, "%s, %s", $1, $3); 
        }
        | variacoesi2 {sprintf($$, "%s", $1); }
        ;

// Atribuicao para um tipo inteiro ou sucessoes de inteiros     
variacoesi2: VARIAVEL {            
            VARSI * aux = srchi(ivar, $1);
            if (aux == NULL){
                // Se ainda nao existe variavel com esse nome, se cria uma
                ivar = insi(ivar, $1);
                sprintf($$, "%s", $1);
            }
            else{
                // Se já existe variavel com esse no, informar mensagem de erro
                printf ("A variável '%s' já existe.\n", $1);
            }
        }
        | VARIAVEL ATRIB expre {
            VARSI * aux = srchi(ivar, $1);
            if (aux == NULL){
                // Se ainda nao existe variavel com esse nome, se cria uma
                ivar = insi(ivar, $1);
            
                VARSI * aux2 = srchi(ivar, $1);
                if (aux2 == NULL){
                    printf ("Variavel '%s' ainda nao declarada.\n", $1);
                }
                else {
                    // Atribuindo valor a variavel criada
                    aux2->value = $3;
                    sprintf($$, "%s << %d", $1, $3);
                }
            }
            else{
                // Se já existe variavel com esse no, informar mensagem de erro
                printf ("A variavel '%s' ja existe.\n", $1);
            }
        }
        ;


//  declaração de varias variaveis do tipo string
variacoet: variacoet ',' variacoet1 { 
            sprintf($$, "%s, %s", $1, $3);
        } 
        | variacoet1 { sprintf($$, "%s", $1); }
        ;

// Atribuicoes do tipo String ou sucessoes de atribuicoes do tipo string
variacoet1: VARIAVEL {            
            VARTS * aux = srcht(tvar, $1);
                if (aux == NULL){
                // Se ainda nao existe variavel com esse nome, se cria uma
                tvar = inst(tvar, $1);
                sprintf($$, "%s", $1);
            }else{
                // Se já existe variavel com esse no, informar mensagem de erro
                printf ("A variável '%s' já existe.\n", $1);
            }
        }
        | VARIAVEL ATRIB STRING {
            // Atribuição da variavel do tipo TEXTO
            VARTS * aux = srcht(tvar, $1);
            if (aux == NULL){
                // Se ainda nao existe variavel com esse nome, se cria uma
                tvar = inst(tvar, $1);
            
               VARTS * aux2 = srcht(tvar, $1);
                if(aux2 == NULL){
                printf("Variavel '%s' ainda nao declarada.\n", $1);
                }
                else{
                //Atribuindo valor a variavel criada
                sprintf(aux2->value, "%s", $3);
                sprintf($$, "%s << %s", $1, $3);
                }
            }
            else{
                // Se já existe variavel com esse no, informar mensagem de erro
                printf ("A variavel '%s' ja existe.\n", $1);
            }
        } 
        ;

ini: INICIO cod FINAL { printf("PROGRAMA FINALIZADO COM SUCESSO!\n"); }
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
            // se nao existe variavel declarada real
            VARSI * aux2 = srchi(ivar, $3);
            if (aux2 == NULL){
                // se nao existe variavel declarada inteiro
                printf ("Variavel '%s' ainda nao foi declarada\n", $3);
            } else {
                //se for variavel inteira
                //verificar se o valor corresponde ao tipo inteiro
                char test[100];
                do{
                    int i = 0;
                    do{
                        test[i] = '\0';
                        i++;
                    }while(test[i]!='\0');

                    scanf("%s", &test);
                    if( is_int(test)==false )
                        printf ("Valor '%s' deve ser inteiro\n", $3);
                }while( is_int(test)==false );
                
                aux2->value = atoi(test);
                printf("Valor do token de LEITURA: %d\n", aux2->value);
                printf("leia(%s)\n",$3);
            }
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
            printf("Valor do token de LEITURA: %f\n", aux->value);
            printf("leia(%s)\n",$3);
            //sprintf($$, "%s << %f", $1, $3);
        }
    } |
    VARIAVEL ATRIB expre {
        // atribuição de variavel
        VARS * aux = srch(rvar, $1);
        if (aux == NULL){
            // se nao existe variavel declarada real
            VARSI * aux2 = srchi(ivar, $1);
            if (aux2 == NULL)
                // se nao existe variavel declarada inteiro, mensagem de erro
                printf ("Variável '%s' não foi declarada\n", $1);
            else {
                aux2->value = $3;
            }
        } else {
            aux->value = $3;
            //printf("%.2f\n", aux->value);
            //sprintf($$, "%s << %f", $1, $3); -> input_output has not
        }
    }
    | COMENTARIO {
        printf("Comentario: %s\n", $1);
    }
    | expre {
        printf("Valor: %f\n", $1);
    }
    | logico {
        printf("Logico: %f\n", $1);
    }
    ;
    

// Expressoes aritmeticas
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
        if (aux == NULL) {
            VARSI * aux2 = srchi(ivar, $1);
            if (aux2 == NULL)
                printf ("Variável '%s' não foi declarada\n", $1);
            else {
                $$ = aux2->value;
            }
        } else {
            $$ = aux->value;
        }
    }
    | NUM_REAL {
        $$ = $1;
    }
    | NUM_INT {
        $$ = $1;
    }
    ;

logico: '(' logico ')' {$$=$2;}
    | logico LOGICO logico {
        if(strcmp($2, "==")==0)
            if($1 == $3)
                $$ = 1;
            else
                $$ = 0;
        if(strcmp($2, "!=")==0)
            if($1 != $3)
                $$ = 1;
            else
                $$ = 0;
        if(strcmp($2, "<")==0)
            if($1 < $3)
                $$ = 1;
            else
                $$ = 0;
        if(strcmp($2, "<=")==0)
            if($1 <= $3)
                $$ = 1;
            else
                $$ = 0;
        if(strcmp($2, ">")==0)
            if($1 > $3)
                $$ = 1;
            else
                $$ = 0;
        if(strcmp($2, ">=")==0)
            if($1 >= $3)
                $$ = 1;
            else
                $$ = 0;
        if(strcmp($2, "||")==0)
            if($1 || $3)
                $$ = 1;
            else
                $$ = 0;
        if(strcmp($2, "&&")==0)
            if($1 && $3)
                $$ = 1;
            else
                $$ = 0;

    }
    | expre {$$=$1;}
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

}

int yywrap(){
    return 0;
}