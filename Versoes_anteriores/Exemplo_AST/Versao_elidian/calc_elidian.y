%{
    //codigo C
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>
    #include <ctype.h>
    #include <stdbool.h>

    extern int yylineno;
    int yylex();
    void yyerror(char *s){ printf("\nERROR (%s) na linha %d\n", s, yylineno); }

    
    typedef struct variavels {
		char name[50];
        int type; // string se 0, int se 1, double se 2
        char tv[100];
        int iv;
        double rv;
		struct variavels * prox;
	} VARIAVELS;

    typedef struct varis {
		char name[30];
        int v;
		struct varis * prox;
	} VARIS;

    typedef struct vars {
		char name[30];
        double v;
		struct vars * prox;
	} VARS;

    typedef struct varts {
		char name[30];
		char v[100];
		struct varts * prox;
	} VARTS;

    //add nova variável na lista
	VARS * ins(VARS *l, char n[]){
		VARS *aux =(VARS*)malloc(sizeof(VARS));
		if(!aux) {
            printf("out of space");
            exit(0);
        }
        strcpy(aux->name, n);
		aux->prox = l;
		return aux;
	}

    VARIS * insi(VARIS *l, char n[]){
		VARIS *aux =(VARIS*)malloc(sizeof(VARIS));
		if(!aux) {
            printf("out of space");
            exit(0);
        }
        strcpy(aux->name, n);
		aux->prox = l;
		return aux;
	}

    //add nova variável na lista
    VARTS * inst(VARTS *l, char n[]){
		VARTS *aux =(VARTS*)malloc(sizeof(VARTS));
		if(!aux) {
            printf("out of space");
            exit(0);
        }
        strcpy(aux->name, n);
        strcpy(aux->v, "");
		aux->prox = l;
		return aux;
	}

    //busca uma variável na lista de variáveis
	VARIS *srchi(VARIS *l, char n[]){
		VARIS *aux = l;
		while(aux != NULL){
			if(strcmp(n, aux->name)==0) 
                break;
			else
                aux = aux->prox;
		}
		return aux;
	}

    //busca uma variável na lista de variáveis
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
	
    //busca uma variável na lista de variáveis
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

    // VERIFICAR SE DADO VALOR É REAL
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

    VARIS *ivar = NULL;
	VARS *rvar = NULL;
    VARTS *tvar = NULL;

    /*O nodetype serve para indicar o tipo de nó que está na árvore. Isso serve para a função eval() entender o que realizar naquele nó*/

    typedef struct ast { /*Estrutura de um nó*/
        int nodetype;
        struct ast *l; /*Esquerda*/
        struct ast *r; /*Direita*/
    }Ast; 

    typedef struct intval { /*Estrutura de um número*/
        int nodetype;
        int v;
    }Intval;

    typedef struct realval { /*Estrutura de um número*/
        int nodetype;
        double v;
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

    typedef struct symasgn { /*Estrutura para um nó de atribuição. Para atrubuir o valor de v em s*/
        int nodetype;
        char s[30];
        Ast *v;
    }Symasgn;

    //double var[26]; /*Variáveis*/
    //int aux;

    Ast * newast(int nodetype, Ast *l, Ast *r){ /*Função para criar um nó*/

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
    
    Ast * newint(int d) {			/*Função de que cria um número (folha)*/
        Intval *a = (Intval*) malloc(sizeof(Intval));
        if(!a) {
            printf("out of space");
            exit(0);
        }
        a->nodetype = 'k';
        a->v = d;
        return (Ast*)a;
    }

    Ast * newreal(double d) {			/*Função de que cria um número (folha)*/
        Realval *a = (Realval*) malloc(sizeof(Realval));
        if(!a) {
            printf("out of space");
            exit(0);
        }
        a->nodetype = 'K';
        a->v = d;
        return (Ast*)a;
    }

    Ast * newtexto(char d[]) {			/*Função de que cria um número (folha)*/
        Textoval *a = (Textoval*) malloc(sizeof(Textoval));
        if(!a) {
            printf("out of space");
            exit(0);
        }
        a->nodetype = 'm';
        strcpy(a->v, d);
        return (Ast*)a;
    }

    Ast * newflow(int nodetype, Ast *cond, Ast *tl, Ast *el){ /*Função que cria um nó de if/else/while*/
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

    Ast * newcmp(int cmptype, Ast *l, Ast *r){ /*Função que cria um nó para testes lógicos*/
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

    Ast * newasgn(char s[], Ast *v) { /*Função para um nó de atribuição*/
        Symasgn *a = (Symasgn*)malloc(sizeof(Symasgn));
        if(!a) {
            printf("out of space");
            exit(0);
        }
        a->nodetype = '=';
        strcpy(a->s, s); /*Símbolo/variável*/
        a->v = v; /*Valor*/
        return (Ast *)a;
    }

    Ast * newValorVal(char s[]) { /*Função que recupera o nome/referência de uma variável, neste caso o número*/
        
        Varval *a = (Varval*) malloc(sizeof(Varval));
        if(!a) {
            printf("out of space");
            exit(0);
        }
        a->nodetype = 'N';
        strcpy(a->var, s);
        return (Ast*)a;
        
    }

    double eval(Ast *a) { /*Função que executa operações a partir de um nó*/
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
                    VARIS * aux2 = srchi(ivar, ((Varval*)a)->var);
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
            case '-': v = eval(a->l) - eval(a->r); break;	/*Operações*/
            case '*': v = eval(a->l) * eval(a->r); break;	/*Operações*/
            case '/': v = eval(a->l) / eval(a->r); break; /*Operações*/
            case 'S': v = sin(eval(a->l)); break;				/*Operações SIN*/
            case 'C': v = cos(eval(a->l)); break;				/*Operações COS*/
            case 'R': v = sqrt(eval(a->l)); break;				/*Operações RAIZ*/
            case 'M': v = -eval(a->l); break;				/*Operações, número negativo*/
            case 'A': v = fabs(eval(a->l)); break;

            case '1': v = (eval(a->l) > eval(a->r))? 1 : 0; break;	/*Operações lógicas. "árv esq   >   árv dir"  Se verdade 1, falso 0*/
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
                    VARIS * xi = (VARIS*)malloc(sizeof(VARIS));
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
                    printf ("%.2f\n",v); break;  /*Função que imprime um valor*/

            case 'i':;
                char namei[30];
                strcpy(namei, ((Symasgn *)a)->s);   /*Recupera e copia o símbolo/variável*/
                ivar = insi(ivar, namei);
                VARIS * xi = (VARIS*)malloc(sizeof(VARIS));
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

%union{
    char texto[50];
    int inteiro;
    double real;
    Ast *a;
}

//DECLARAÇÃO DE TOKENS
%token <inteiro> TIPO
%token <texto> TIPO_REAL
%token <texto> TIPO_TEXTO
%token <inteiro> INTEIRO
%token <real> REAL
%token <texto> TEXTO
%token ENTRADA
%token SAIDA
%token INICIO
%token FINAL
%token IF ELSE FOR WHILE
%token <texto> VAR
%token OPV
%token <texto> COMENTARIO
//TOKENS DE ARITMETICA
%token RAIZ COS SIN REST
//TOKENS DE LOGICA
%token MAIOR MENOR MEI MAI II DIF OR AND

//DECLARAÇÃO DE TIPO DE NÃO-TERMINAIS
%type <a> exp arit valor logica arit1 arit2 arit3 L1 L2 list

//DECLARAÇÃO DE PRECEDÊNCIA
%right '='
%left '+' '-'
%left '*' '/'
%right '^'
%left ')'
%right '('

%nonassoc '|' IMUNUS VAR

%start prog
%%

prog: INICIO cod FINAL {printf("\nPROGRAMA FINALIZADO\n\n");}
    ;
cod: cod exp {eval($2);}
    | 
    ;
exp: VAR '=' arit {$$ = newasgn($1, $3);}
    | VAR '=' TEXTO {
        Textoval * tv = (Textoval*)malloc(sizeof(Textoval));
        strcpy(tv->v, $3);
        $$ = newasgn($1, (Ast*)tv);
    }
    | TIPO VAR {$$ = newvar($1, $2, NULL);}
    | TIPO VAR '=' arit {$$ = newvar($1, $2, $4);}
    | TIPO VAR '=' TEXTO {
        Textoval * tv = (Textoval*)malloc(sizeof(Textoval));
        strcpy(tv->v, $4);
        $$ = newvar($1, $2, (Ast*)tv);
    }
    | VAR ENTRADA {}
    | ':' arit {$$ = $2;}
    | ':' logica {$$ = $2;}
    | IF '(' logica ')' '{' list '}'  {$$ = newflow('I', $3, $6, NULL);}
	| IF '(' logica ')' '{' list '}' ELSE '{' list '}' {$$ = newflow('I', $3, $6, $10);}
	| WHILE '(' logica ')' '{' list '}' {$$ = newflow('W', $3, $6, NULL);}
    | FOR { printf("FOR\n");}
    | COMENTARIO {
        printf("COMENTARIO: %s\n", $1);
    }
    | SAIDA arit { $$ = newast('P', $2,NULL);}
    | SAIDA logica { $$ = newast('P', $2,NULL);}
    | SAIDA TEXTO {
        Textoval * tv = (Textoval*)malloc(sizeof(Textoval));
        strcpy(tv->v, $2);
        $$ = newast('P', (Ast*)tv,NULL);
    }
    ;

list: exp{$$ = $1;}
    | list exp { $$ = newast('L', $1, $2);}
    ;
arit: SIN '(' arit ')' {$$ = newast('S',$3,NULL);}
    | COS '(' arit ')' {$$ = newast('C',$3,NULL);}
    | RAIZ '(' arit ')' {$$ = newast('R',$3,NULL);}
    | '-' arit %prec IMUNUS {$$ = newast('M',$2,NULL);}
    | '|' arit '|' {$$ = newast('A',$2,NULL);}
    | arit '+' arit1 {$$ = newast('+',$1,$3);}
    | arit '-' arit1 {$$ = newast('-',$1,$3);}
    | arit1
    ;
arit1: arit1 '*' arit2 {$$ = newast('*',$1,$3);}
    | arit1 '/' arit2 {$$ = newast('/',$1,$3);}
    | arit1 REST arit2 {$$ = newast('%',$1,$3);}
    | arit2
    ;
arit2: arit3 '^' arit2 {$$ = newast('^',$1,$3);}
    | arit3
    ;
arit3: '(' arit ')' {$$ = $2;}
    | valor {$$ = $1;}
    ;
valor: INTEIRO {$$ = newint($1);}
    | REAL {$$ = newreal($1);}
    | VAR {$$ = newValorVal($1);}
    ;
logica: L1 MAIOR L2 {$$ = newcmp(1,$1,$3);}
    | L1 MENOR L2 {$$ = newcmp(2,$1,$3);}
    | L1 DIF L2 {$$ = newcmp(3,$1,$3);}
    | L1 II L2 {$$ = newcmp(4,$1,$3);}
    | L1 MAI L2 {$$ = newcmp(5,$1,$3);}
    | L1 MEI L2 {$$ = newcmp(6,$1,$3);}
    | L1 OR L2 {$$ = newcmp(7,$1,$3);}
    | L1 AND L2 {$$ = newcmp(8,$1,$3);}
    ;
L1: L2 {$$=$1; }
    ;
L2: '(' logica ')' {$$=$2;}
    | arit {$$=$1;}
    ;
%%

#include "lex.yy.c"

int main(){
   
    yyin=fopen("calc_exemplo.txt", "r");
    yyparse();    
    fclose(yyin);

    return 0;
}

int yywrap(){
    return 0;
}
