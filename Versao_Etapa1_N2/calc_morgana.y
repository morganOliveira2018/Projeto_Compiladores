%{
    //Codigo C
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

    typedef struct variavels {
		char name[50];
        int type; // string se 0, int se 1, double se 2
        char tv[100];
        int iv;
        double rv;
		struct variavels * prox;
	} VARIAVELS;

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

	VARS *rvar = NULL;
    VARSI *ivar = NULL;
    VARTS *tvar = NULL;

    /* O nodetype serve para indicar o tipo de nó que está na árvore. Isso serve para a função eval entender o que realizar naquele no */
    typedef struct ast { /*Estrutura de um nó*/
        int nodetype;
        struct ast *l; /*Esquerda*/
        struct ast *r; /*Direita*/
    }Ast; 

    typedef struct intval { /*Estrutura de um número*/
        int nodetype;
        int v;
    }Intval;

    typedef struct realval { /* Estrutura de um número */
        int nodetype;
        double value;
    }Realval;

    typedef struct textoval { /*Estrutura de um número*/
        int nodetype;
        char v[100];
    }Textoval;

    typedef struct varval { /*Estrutura de um nome de variável, nesse exemplo uma variável é um número no vetor var[26]*/
        int nodetype;
        char var[30];
    }Varval;

    typedef struct flow { /*Estrutura de um desvio (if/else/while)*/
	    int nodetype;
	    Ast *cond;		/*condição*/
	    Ast *tl;		/*then, ou seja, verdade*/
	    Ast *el;		/*else*/
    }Flow;

    /*Estrutura para um nó de atribuição. Para atrubuir o valor de v em s*/
    typedef struct symasgn { 
        int nodetype;
        int s;
        Ast *v;
    }Symasgn;

    /*Função para criar um nó*/
    Ast * newast(int nodetype, Ast *l, Ast *r){ 

	    Ast *a = (Ast*) malloc(sizeof(Ast));
	    if(!a) {
		    printf("out of space");
		    exit(0);
	}
	    a->nodetype = nodetype;
	    a->l = l;
	    a->r = r;
	    return a;
    }

    /* Função de que cria um número inteiro (folha)*/
    Ast * newint(int d) {	
        Intval *a = (Intval*) malloc(sizeof(Intval));
        if(!a) {
            printf("out of space");
            exit(0);
        }
        a->nodetype = 'k';
        a->v = d;
        return (Ast*)a;
    }


    /*Função de que cria um número real (folha)*/
    Ast * newreal(double d) {		
        Realval *a = (Realval*) malloc(sizeof(Realval));
        if(!a) {
            printf("out of space");
            exit(0);
        }
        a->nodetype = 'K';
        a->value = d;
        return (Ast*)a;
    }

    /*Função de que cria um novo texto (folha)*/
    Ast * newtexto(char d[]) {			
        Textoval *a = (Textoval*) malloc(sizeof(Textoval));
        if(!a) {
            printf("out of space");
            exit(0);
        }
        a->nodetype = 'm';
        strcpy(a->v, d);
        return (Ast*)a;
    }

    /*Função que cria um nó de if/else/while*/
    Ast * newflow(int nodetype, Ast *cond, Ast *tl, Ast *el){ 
        Flow *a = (Flow*)malloc(sizeof(Flow));
        if(!a) {
            printf("out of space");
        exit(0);
        }
        a->nodetype = nodetype;
        a->cond = cond;
        a->tl = tl;
        a->el = el;
        return (Ast *)a;
    }

    /*Função que cria um nó para testes lógicos*/
    Ast * newcmp(int cmptype, Ast *l, Ast *r){
        Ast *a = (Ast*)malloc(sizeof(Ast));
        if(!a) {
            printf("out of space");
        exit(0);
        }
        a->nodetype = '0' + cmptype; /*Para pegar o tipe de teste, definido no arquivo.l e utilizar na função eval()*/
        a->l = l;
        a->r = r;
        return a;
    }

    /* Funcão que cria um nó para inteiro ou real ou texto */
    Ast * newvar(int t, char s[], Ast *v){
        Symasgn *a = (Symasgn*)malloc(sizeof(Symasgn));
        if(!a) {
            printf("out of space");
            exit(0);
        }
        a->nodetype = t; /*tipo i, r ou t, conforme arquivo .l*/
        strcpy(a->s, s); /*Símbolo/variável*/
        a->v = v; /*Valor*/
        return (Ast *)a;
    }

    /*Função para um nó de atribuição*/
    Ast * newasgn(int s, Ast *v) { 
        Symasgn *a = (Symasgn*)malloc(sizeof(Symasgn));
        if(!a) {
            printf("out of space");
        exit(0);
        }
        a->nodetype = '=';
        a->s = s; /*Símbolo/variável*/
        a->v = v; /*Valor*/
        return (Ast *)a;
    }

    /*Função que recupera o nome/referência de uma variável, neste caso o número*/
    Ast * newValorVal(char s[]) { 
        
        Varval *a = (Varval*) malloc(sizeof(Varval));
        if(!a) {
            printf("out of space");
            exit(0);
        }
        a->nodetype = 'N';
        strcpy(a->var, s);
        return (Ast*)a;
        
    }

    /*Função que executa operações a partir de um nó*/
    double eval(Ast *a) { 
        double v;
        if(!a) {
            printf("internal error, null eval\n");
            return 0.0;
        }
        switch(a->nodetype) {
            case 'k': v = ((Intval *)a)->v; break; 	/*Recupera um número inteiro*/
            case 'K': v = ((Realval *)a)->v; break; 	/*Recupera um número real*/
            case 'm': v = atof(((Textoval *)a)->v); break; 	/*Recupera um número real dentro de string*/
            case 'N':;
                VARS * aux = (VARS*)malloc(sizeof(VARS));
                aux = srch(rvar, ((Varval*)a)->var);
                if (!aux){
                    VARSI * aux2 = srchi(ivar, ((Varval*)a)->var);
                    if (!aux2){
                        printf ("306 - Variavel '%s' nao foi declarada.\n", ((Varval*)a)->var);
                    }
                    else{
                        v = (double)aux2->v;
                    }
                }
                else{
                    v = aux->v;
                }
                break;
            case '+': v = eval(a->l) + eval(a->r); break;	/*Operações "árv esq   +   árv dir"*/
            case '-': v = eval(a->l) - eval(a->r); break;	/*Operações de subtração */
            case '*': v = eval(a->l) * eval(a->r); break;	/*Operações de multiplicação */
            case '/': v = eval(a->l) / eval(a->r); break; /*Operação de divisão */
            case 'R': v = sqrt(eval(a->l)); break;				/*Operações RAIZ*/
            case 'M': v = -eval(a->l); break;				/*Operações, número negativo*/
            case '|': v = fabs(eval(a->l)); break;          /*Operações de módulo*/

            case '1': v = (eval(a->l) > eval(a->r))? 1 : 0; break;	/* Operações lógicas. "árv esq   >   árv dir"  Se verdade 1, falso 0 */
            case '2': v = (eval(a->l) < eval(a->r))? 1 : 0; break;
            case '3': v = (eval(a->l) != eval(a->r))? 1 : 0; break;
            case '4': v = (eval(a->l) == eval(a->r))? 1 : 0; break;
            case '5': v = (eval(a->l) >= eval(a->r))? 1 : 0; break;
            case '6': v = (eval(a->l) <= eval(a->r))? 1 : 0; break;
            case '7': v = (eval(a->l) || eval(a->r))? 1 : 0; break;
            case '8': v = (eval(a->l) && eval(a->r))? 1 : 0; break;
            
            case '=':;
                v = eval(((Symasgn *)a)->v); /*Recupera o valor*/
                
                VARS * x = (VARS*)malloc(sizeof(VARS));
                if(!x) {
                    printf("out of space");
                    exit(0);
                }
                char name1[30];
                strcpy(name1, ((Symasgn *)a)->s); /*Recupera o símbolo/variável*/
                x = srch(rvar, name1);
                if(!x){
                    VARSI * xi = (VARSI*)malloc(sizeof(VARSI));
                    if(!xi) {
                        printf("out of space");
                        exit(0);
                    }
                    xi = srchi(ivar, name1);
                    if(!xi){
                        printf("Erro de var nao declarada\n");
                    } else
                        xi->v = (int)v; /*Atribui à variável*/
                } else
                    x->v = v;   /*Atribui à variável*/
                break;
            /*CASO IF*/
            case 'I': 
                if (eval(((Flow *)a)->cond) != 0) {	/*executa a condição / teste*/
                    if (((Flow *)a)->tl)		/*Se existir árvore*/
                        v = eval(((Flow *)a)->tl); /*Verdade*/
                    else
                        v = 0.0;
                } else {
                    if( ((Flow *)a)->el) {
                        v = eval(((Flow *)a)->el); /*Falso*/
                    } else
                        v = 0.0;
                    }
                break;
            /*CASO WHILE*/
            case 'W':
                v = 0.0;
                if( ((Flow *)a)->tl) {
                    while( eval(((Flow *)a)->cond) != 0){
                        v = eval(((Flow *)a)->tl);
                        }
                }
            break;
                
            case 'L': eval(a->l); v = eval(a->r); break; /*Lista de operções em um bloco IF/ELSE/WHILE. Assim o analisador não se perde entre os blocos*/
            
            case 'P': v = eval(a->l);		/*Recupera um valor*/
                printf ("%.2f\n",v);    /*Função que imprime um valor*/
                break;

            case 'i':;
                char namei[30];
                strcpy(namei, ((Symasgn *)a)->s);   /*Recupera e copia o símbolo/variável*/
                ivar = insi(ivar, namei);
                VARSI * xi = (VARSI*)malloc(sizeof(VARSI));
                if(!xi) {
                    printf("out of space");
                    exit(0);
                }
                xi = srchi(ivar, namei);
                if(((Symasgn *)a)->v)
                    xi->v = (int)eval(((Symasgn *)a)->v); /*Atribui à variável*/
                printf("teste %d\n", xi->v);
                break;
            case 'r':;
                char namer[30];
                strcpy(namer, ((Symasgn *)a)->s);   /*Recupera e copia o símbolo/variável*/
                rvar = ins(rvar, namer);
                VARS * xr = (VARS*)malloc(sizeof(VARS));
                if(!xr) {
                    printf("out of space");
                    exit(0);
                }
                xr = srch(rvar, namer);
                if(((Symasgn *)a)->v)
                    xr->v = eval(((Symasgn *)a)->v);
                break;
            case 't':;
                char namet[30];
                strcpy(namet, ((Symasgn *)a)->s);   /*Recupera e copia o símbolo/variável*/
                tvar = inst(tvar, namet);
                VARTS * xt = (VARTS*)malloc(sizeof(VARTS));
                if(!xt) {
                    printf("out of space");
                    exit(0);
                }
                xt = srcht(tvar, namet);
                if(((Textoval*)a)->v)
                    strcpy(xt->v, ((Textoval*)a)->v);
                break;

            default: printf("internal error: bad node %c\n", a->nodetype);
        }
        return v;
    }

%}

%union {
    char texto[50];
    double real;
    int inteiro;
    int fn;
    Ast *ast;
}

// Declaração dos tokens - Nos terminais 
%token <real> NUM_REAL 
%token <inteiro> NUM_INT
%token <texto> VARIAVEL
%token <texto> STRING
%token <texto> TIPO_REAL TIPO_INT TIPO_TEXT 
%token IF ELSE WHILE FOR 
%token INICIO
%token FINAL
%token RAIZ
%token LEITURA
%token ESCREVER
%token <texto> COMENTARIO
%token <fn> CMP

// Declaração dos nos não-terminais
%type <ast> begin var ini expre valor cod list

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
begin: var begin { printf("PROGRAMA INICIADO!");} 
     | ini 
     ;

var:  VARIAVEL '=' expre {$$ = newasgn($1, $3);}
    | VARIAVEL '=' STRING {
        Textoval * tv = (Textoval*)malloc(sizeof(Textoval));
        strcpy(tv->v, $3);
        $$ = newasgn($1, (Ast*)tv);
    }
    | TIPO_TEXT VARIAVEL {$$ = newvar($1, $2, NULL);} 
    | TIPO_REAL VARIAVEL '=' expre {$$ = newvar($1, $2, $4);} // declaracao do real e atrib
    | TIPO_INT VARIAVEL '=' expre {$$ = newvar($1, $2, $4);} // declaracao de int e atrib
    | TIPO_TEXT VARIAVEL '=' STRING { // declaracao de String e a atribuicao
        Textoval * tv = (Textoval*)malloc(sizeof(Textoval));
        strcpy(tv->v, $4);
        $$ = newvar($1, $2, (Ast*)tv);
    }
    | ESCREVER '(' STRING ')' {} 
    | ESCREVER '(' expre ')' {}
    | LEITURA '(' VARIAVEL ')' {}
    | IF '(' expre ')' '{' list '}'  {$$ = newflow('I', $3, $6, NULL);}
    | IF '(' expre ')' '{' list '}' ELSE '{' list '}' {$$ = newflow('I', $3, $6, $10);} 
    | WHILE '(' expre ')' '{' list '}' {$$ = newflow('W', $3, $6, NULL);}
    | FOR { printf("FOR\n");}
    | COMENTARIO { printf("Comentario: %s\n", $1); }
    ;

ini: INICIO cod FINAL {eval($2); printf("PROGRAMA FINALIZADO!\n"); }
    ;

cod: cod expre {eval($2);}
    | {;}
    ;

list: expre {$$ = $1;}
    | list expre { $$ = newast('L', $1, $2);}
    ;
    
expre: 
    RAIZ '(' expre ')' { 
        {$$ = newast('R',$3,NULL);}
        /* $$ = sqrt($3); */
        /* printf("Efetuando raiz(%f):\n", $3);*/
    }
    | expre '+' expre {
        $$ = newast('+', $1, $3);
        /* $$ = $1 + $3;*/
        /* printf("%.1f + %.1f = %.1f\n", $1, $3, $$);*/
    }
    | expre '-' expre {
        $$ = newast('-',$1,$3);
        /* $$ = $1 - $3; */
        /* printf("%.1f - %.1f = %.1f\n", $1, $3, $$); */
    }
    | expre '*' expre {
        $$ = newast('*',$1,$3);
        /* $$ = $1 * $3; */
        /* printf("%.1f * %.1f = %.1f\n", $1, $3, $$); */
    }
    | expre '/' expre {
        $$ = newast('/',$1,$3);
        /* $$ = $1 / $3; */
        /* printf("%.1f / %.1f = %.1f\n", $1, $3, $$); */
    }
    | '|' expre '|' {
        $$ = newast('|',$2,NULL);
        /* $$ = fabs($2); */
        /* printf("%.1f = %.1f\n", $2, $$); */
    }
    | '(' expre ')' {
        $$ = $2;
    } 
    | expre '^' expre {
        $$ = newast('^',$1,$3);
        /* $$ = pow($1, $3); */
        /* printf("%.1f ^ %.1f = %.1f\n", $1, $3, $$); */
    } 
    | '-' expre %prec UMINUS {
        $$ = newast('M',$2,NULL);
        /* $$ = -$2;*/

    }
    | expre CMP expre { /* Testes condicionais */
        $$ = newcmp($2,$1,$3);
    }		
    | valor { 
        $$ = $1; 
    }
    ;     
    
valor: NUM_INT { $$ = newint($1);} 
    | NUM_REAL { $$ = newreal($1);} 
    | VARIAVEL {           
        $$ = newValorVal($1);  /* Funcao da chamada newValorVal retorna um tipo Ast que dps e usado em eval */
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

}

int yywrap(){
    return 0;
}