/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30704

/* Bison version string.  */
#define YYBISON_VERSION "3.7.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "calc_morgana.y"

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

    #define name_size 50
    #define string_size 1000

    // Construção de uma struct para receber o nome e o valor para cada variavel do tipo real
    typedef struct vars {
		char name[name_size];
		float v;
        float *vet;
		struct vars * prox;
	} VARS;

    // Adicionar nova variavel do tipo real na lista
    VARS * ins(VARS *l, char n[]){
		VARS *new =(VARS*)malloc(sizeof(VARS));
		strcpy(new->name, n);
		new->prox = l;
		return new;
	}

    VARS * ins_a(VARS *l, char n[], int tamanho){
		VARS *new =(VARS*)malloc(sizeof(VARS));
		strcpy(new->name, n);
        new->vet = (float*)malloc(tamanho * sizeof(float));
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
    typedef struct VARST {
		char name[name_size];
		char v[string_size];
        char **vet;
		struct VARST * prox;
	} VARST;

    // Adicionar nova variável do tipo string na lista 
    VARST * inst(VARST *l, char n[]){
		VARST *new =(VARST*)malloc(sizeof(VARST));
		strcpy(new->name, n);
        strcpy(new->v, "");
		new->prox = l;
		return new;
	}

    VARST * inst_a(VARST *l, char n[], int tamanho){
		VARST *new =(VARST*)malloc(sizeof(VARST));
		strcpy(new->name, n);
        new->vet = (char**)malloc(tamanho * sizeof(char));
		new->prox = l;
		return new;
	}

    // Busca uma nova variável do tipo string na lista de variáveis
    VARST *srcht(VARST *l, char n[]){
		VARST *aux = l;
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
		char name[name_size];
		int v;
        int *vet;
		struct varsi * prox;
	} VARSI;

    // Adicionar nova variavel inteiro na lista de variáveis inteiro
    VARSI * insi(VARSI *l, char n[]){
		VARSI *new =(VARSI*)malloc(sizeof(VARSI));
		strcpy(new->name, n);
		new->prox = l;
		return new;
	}

    // Insercao de inteiros no array
    VARSI * insi_a(VARSI *l, char n[], int tamanho){
		VARSI *new =(VARSI*)malloc(sizeof(VARSI));
		strcpy(new->name, n);
        new->vet = (int*)malloc(tamanho * sizeof(int));
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
    VARST *tvar = NULL;

    /* O nodetype serve para indicar o tipo de nó que está na árvore. Isso serve para a função eval entender o que realizar naquele no */
    typedef struct ast { /*Estrutura de um nó*/
        int nodetype;
        struct ast *l; /*Esquerda*/
        struct ast *r; /*Direita*/
    }Ast; 

    typedef struct intval { /*Estrutura de uma variavel inteira*/
        int nodetype;
        int v;
    }Intval;

    typedef struct realval { /* Estrutura de uma variavel real */
        int nodetype;
        double v;
    }Realval;

    typedef struct textoval { /*Estrutura de uma variavel texto*/
        int nodetype;
        char v[string_size];
    }Textoval;

    typedef struct varval { /*Estrutura de um nome de variável, nesse exemplo uma variável é um número no vetor var[26]*/
        int nodetype;
        char var[name_size];
        int size;
        Ast * n;
        Ast * pos; /* posicao no vetor */
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
        char s[name_size];
        Ast *v;
        Ast *n;
        Ast * pos; /* posicao para atribuir um valor novo nela no array */
    }Symasgn;

    typedef struct function {
        int nodetype;
        int type;
		char name[name_size];
        Ast *v;
        struct function * prox;
	} Function;

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

    /*Estrutura de um fluxo para o FOR*/
    typedef struct flowfor{ 
        int nodetype;
        Ast* v1;
        Ast* v2;
        Ast* v3;
    }Flowfor;

    /*Função que cria um nó de FOR*/
    Ast * newflowfor(int nodetype, Ast *b1, Ast *b2, Ast *b3, Ast *tl, Ast *el){ 
        Flow *a = (Flow*)malloc(sizeof(Flow));
        if(!a) {
            printf("out of space");
            exit(0);
        }
        Flowfor *b = (Flowfor*)malloc(sizeof(Flowfor));
        if(!b) {
            printf("out of space");
            exit(0);
        }
        b->nodetype = 'F';
        b->v1 = b1;
        b->v2 = b2;
        b->v3 = b3;
        a->nodetype = nodetype;
        a->cond = (Ast*)b;
        a->tl = tl;
        a->el = el;
        return (Ast *)a;
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
        a->v = d;
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

    /*Função de que cria uma nova variável array*/
    Ast * newarray(int nodetype, char nome[], int tam, Ast* n) {
        Varval *a = (Varval*) malloc(sizeof(Varval) * tam);
        if(!a) {
            printf("out of space");
            exit(0);
        }
        a->nodetype = nodetype;
        strcpy(a->var,nome);
        a->size = tam;
        a->n = n;
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

    /* Funcão que cria um nó para a variavel do tipo inteiro ou real ou texto e atribui o valor */
    Ast * newvar(int t, char s[], Ast *v, Ast *n){
        Symasgn *a = (Symasgn*)malloc(sizeof(Symasgn));
        if(!a) {
            printf("out of space");
            exit(0);
        }
        a->nodetype = t; /*tipo i, r ou t, conforme arquivo .l*/
        strcpy(a->s, s); /*Símbolo/variável*/
        a->v = v; /*Valor*/
        a->n = n; /*proxima declaração*/
        return (Ast *)a;
    }

    /*Função para um nó de atribuição*/
    Ast * newasgn(char s[], Ast *v) { 
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

     /*Função para um nó de atribuição em um array*/
    Ast * newasgn_a(char s[], Ast *v, Ast * pos) { 
        Symasgn *a = (Symasgn*)malloc(sizeof(Symasgn));
        if(!a) {
            printf("out of space");
        exit(0);
        }
        a->nodetype = 'D';
        strcpy(a->s, s); /*Símbolo/variável*/
        a->v = v; /*Valor*/
        a->pos = pos;
        return (Ast *)a;
    }

    /*Função que recupera o nome/referência de uma variável*/
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

    /*Função que recupera o nome/referência de um array */
    Ast * newValorVal_a(char s[], Ast * i) { 
        Varval *a = (Varval*) malloc(sizeof(Varval));
        if(!a) {
            printf("out of space");
            exit(0);
        }
        a->nodetype = 'E';
        strcpy(a->var, s);
        a->pos = i;
        return (Ast*)a;
        
    }

    /*Função para criar um nó para salvar a funcao na lista de funcoes*/
    Ast * newfunction(int type, char n[], Ast *fun){
        Function *aux = (Function*)malloc(sizeof(Function));
        if(!aux){
            printf("out of space in newfuntion()");
            exit(1);
        }
        aux->nodetype = 'f';
        aux->type = type;
        strcpy(aux->name, n);
        aux->v = fun;
        return (Ast*)aux;
    }

    /* Verificar se a variavel existe na lista de variaveis */
    bool varexiste(char v[]) {
        VARS* xr = srch(rvar, v);
        VARSI* xi = srchi(ivar, v);
        VARST* xt = srcht(tvar, v);

    if(!xr && !xi && !xt) 
        return false; // se tudo NULL, variavel nao existe
    else
        return true;  // se tudo for TRUE, variavel existe
    }

    Function * listFunction = NULL;

    // Busca uma função por nome na lista de funções
    Function *srchfunction(Function *l, char n[]){
		Function *aux = l;
        //printf("open srchfuntion\n");
		while(aux != NULL){
			if(strcmp(n,aux->name)==0){
				return aux;
			}
			aux = aux->prox;
		}
        //printf("function NULL\n");
		return aux;
	}

    /*Função que executa operações a partir de um nó*/
    double eval(Ast *a) { 
        double v;
        char v1[50];
        int pos;
        Function *auxFunction; //armazena o resultado da busca na lista de funções

        if(!a) {
            printf("internal error, null eval\n");
            return 0.0;
        }
        //printf("nodetype: %c\n", a->nodetype);
        switch(a->nodetype) {
            case 'k': v = ((Intval *)a)->v; break; 	/*Recupera um número inteiro*/
            case 'K': v = ((Realval *)a)->v; break; 	/*Recupera um número real*/
            case 'm': v = atof(((Textoval *)a)->v); break; 	/*Recupera um número real dentro de string*/
            case 'N':; /*  Verificar se foi realizado a declaracao da variavel corretamente */
                VARS * aux = (VARS*)malloc(sizeof(VARS));
                aux = srch(rvar, ((Varval*)a)->var);
                if (!aux){
                    VARSI * aux2 = (VARSI*)malloc(sizeof(VARSI));
                    aux2 = srchi(ivar, ((Varval*)a)->var);
                    if (!aux2){
                        VARST * aux3 = (VARST*)malloc(sizeof(VARST));
                        if(!aux3){
                                printf("out of space");
                                exit(0);
                            }
                        aux3 = srcht(tvar, ((Varval*)a)->var);
                        if (!aux3){
                            printf ("Erro 'sem valor'. Variavel '%s' nao foi declarada.\n", ((Varval*)a)->var);
                            v = 0.0;
                        }
                        else{
                            v = atof(aux3->v);
                        }
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
            case '?': (eval(((Flow *)a)->cond)) != 0 ? eval(((Flow *)a)->tl) : eval(((Flow *)a)->el); break; /* Case para operador iterator */
            
            /* Atribuicao */
            case '=':;
                v = eval(((Symasgn *)a)->v); /*Recupera o valor*/
                
                VARS * x = (VARS*)malloc(sizeof(VARS));
                if(!x) {
                    printf("out of space");
                    exit(0);
                }
                x = srch(rvar, ((Symasgn *)a)->s);
                if(!x){
                    VARSI * xi = (VARSI*)malloc(sizeof(VARSI));
                    if(!xi) {
                        printf("out of space");
                        exit(0);
                    }
                    xi = srchi(ivar, ((Symasgn *)a)->s);
                    if(!xi){
                        printf("Erro 'atribuir valor'. Var '%s' nao declarada.\n", ((Symasgn *)a)->s);
                    } else
                        xi->v = (int)v; /*Atribui à variável*/
                } else {
                    x->v = v;   /*Atribui à variável*/
                }
                break;

            /* caso if ou if/else */
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

            /* caso while */
            case 'W':
                v = 0.0;
                if( ((Flow *)a)->tl) {
                    while( eval(((Flow *)a)->cond) != 0){
                        v = eval(((Flow *)a)->tl);
                        }
                }
            break;

            // leitura das variaveis: int, real e texto
            case 'c':; 
                //v = eval(((Symasgn *)a)->v); /*Recupera o valor*/
                VARS * xcr = (VARS*)malloc(sizeof(VARS));
                if(!xcr) {
                    printf("out of space");
                    exit(0);
                }
                xcr = srch(rvar, ((Varval *)a->l)->var);
                if(xcr){
                    scanf("%f", &xcr->v);
                } else {
                    VARSI * xci = (VARSI*)malloc(sizeof(VARSI));
                    if(!xci) {
                        printf("out of space");
                        exit(0);
                    }
                    xci = srchi(ivar, ((Varval *)a->l)->var);
                    if(xci){
                        scanf("%d", &xci->v);
                    } else {
                        VARST * xct = (VARST*)malloc(sizeof(VARST));
                        if(!xct) {
                            printf("out of space");
                            exit(0);
                        }
                        xct = srcht(tvar, ((Varval *)a->l)->var);
                        if(xct){
                            scanf("%s", &xct->v);
                        } else {
                            printf("Variavel inválida!\n");
                        }
                    }
                }
                break;
            
            case 'L': eval(a->l); v = eval(a->r); break; /*Lista de operções em um bloco IF/ELSE/WHILE. Assim o analisador não se perde entre os blocos*/
            case 'n': 
            { /* printar os tipos de variaveis corretamente na saída */
                VARS * auxn = (VARS*)malloc(sizeof(VARS));
                auxn = srch(rvar, ((Varval*)a)->var);
                if (!auxn){
                    VARSI * auxn2 = srchi(ivar, ((Varval*)a)->var);
                    if (!auxn2){
                        VARST * auxn3 = srcht(tvar, ((Varval*)a)->var);
                        if (!auxn3){
                            printf ("359 - Variavel '%s' nao foi declarada.\n", ((Varval*)a)->var);
                            v = 0.0;
                        }
                        else{
                            Ast * auxnt = (Ast*)malloc(sizeof(Ast));
                            if(!auxnt){
                                printf("out of space");
                                exit(0);
                            }
                            printf("%s", auxn3->v);
                            v = atof(auxn3->v);
                        }
                    }
                    else{
                        Ast * auxni = (Ast*)malloc(sizeof(Ast));
                        if(!auxni){
                            printf("out of space");
                            exit(0);
                        }
                        printf("%d", auxn2->v);
                        v = (double)auxn2->v;
                    }
                }
                else{
                    Ast * auxnr = (Ast*)malloc(sizeof(Ast));
                    if(!auxnr){
                        printf("out of space");
                        exit(0);
                    }
                    printf("%.2f", auxn->v);
                    v = auxn->v;
                }
                break;
            }
            /* O case P é um comando de print geral, mas ele não trabalha pesado,
            *  o case 'n' ajuda quando precisar imprimir variaveis
            */
            case 'P': 
                //printf("P1: %c\nP2: %c\n", a->nodetype, a->l->nodetype);
                if(a->l==NULL)
                    break;
                /* printf("node %c\n", a->l->nodetype);*/
                if (a->l->nodetype == 'E') {
                    a->l->nodetype = 'H';
                    v = eval(a->l);
                }
                else if(a->l->nodetype == 'N'){
                    a->l->nodetype = 'n';
                    v = eval(a->l);
                    //printf("\nnodetype 'N'\n");
                } else {
                    v = eval(a->l);
                    if(a->l->nodetype != 'n' && a->l->nodetype != 'k' && a->l->nodetype != 'K' && a->l->nodetype != 'm' && a->l->nodetype != 'H')
                        printf("%.2f", v);
                }
                if(((Intval*)a->l)->nodetype == 'k') {
                    printf ("%d", ((Intval*)a->l)->v);		/*Recupera um valor inteiro*/
                }
                else if(((Realval*)a->l)->nodetype == 'K') {
                    printf ("%.2f", ((Realval*)a->l)->v);		/*Recupera um valor real*/
                }
                else if(((Textoval*)a->l)->nodetype == 'm') {
                    if(strcmp(((Textoval*)a->l)->v, "\\n")==0)
                        printf("\n");
                    else
                        printf ("%s", ((Textoval*)a->l)->v);		/*Recupera um valor texto*/
                }
                if(a->r==NULL){
                    /* printf("\n");*/ 
                    /* printf("Quebra linha entra variaveis"); */
                }else{
                    v = eval(a->r);
                    /* printf("\n");*/
                }
                break; 
            /* caso para a opcao FOR */
            case 'F':
                v = 0.0;
                if( ((Flow *)a)->tl ) {
                    for(eval(((Flowfor*)((Flow *)a)->cond)->v1); 
                        eval(((Flowfor*)((Flow *)a)->cond)->v2); 
                        eval(((Flowfor*)((Flow *)a)->cond)->v3)
                        ){
                            v =  eval(((Flow *)a)->tl);
                    }
                }
                break;
            // declaracao da variavel inteira
            case 'i':;
                if(((Symasgn *)a)->n)
                    eval(((Symasgn *)a)->n);

                if(!varexiste(((Symasgn *)a)->s)){
                    ivar = insi(ivar, ((Symasgn *)a)->s);
                    VARSI * xi = (VARSI*)malloc(sizeof(VARSI));
                    if(!xi) {
                        printf("out of space");
                        exit(0);
                    }
                    xi = srchi(ivar, ((Symasgn *)a)->s);
                    if(((Symasgn *)a)->v)
                        xi->v = (int)eval(((Symasgn *)a)->v); /*Atribui à variável*/
                }else{
                    printf("Erro de redeclaracao: variavel '%s' ja existe.\n",((Symasgn *)a)->s);
                }
                break;
            // declaracao da variavel real
            case 'r':;
                if(((Symasgn *)a)->n)
                    eval(((Symasgn *)a)->n);

                if(!varexiste(((Symasgn *)a)->s)){
                    rvar = ins(rvar, ((Symasgn *)a)->s);
                    VARS * xr = (VARS*)malloc(sizeof(VARS));
                    if(!xr) {
                        printf("out of space");
                        exit(0);
                    }
                    xr = srch(rvar, ((Symasgn *)a)->s);
                    if(((Symasgn *)a)->v)
                        xr->v = eval(((Symasgn *)a)->v);
                }else
                    printf("Erro de redeclaracao: variavel '%s' ja existe.\n",((Symasgn *)a)->s);
                break;
            // declara a variavel texto
            case 't':;
                if(((Symasgn *)a)->n)
                    eval(((Symasgn *)a)->n);

                if(!varexiste(((Symasgn *)a)->s)){
                    tvar = inst(tvar, ((Symasgn *)a)->s);
                    VARST * xt = (VARST*)malloc(sizeof(VARST));
                    if(!xt) {
                        printf("out of space");
                        exit(0);
                    }
                    xt = srcht(tvar, ((Symasgn *)a)->s);
                    if((((Symasgn *)a)->v))
                        strcpy(xt->v, ((Textoval*)((Symasgn*)a)->v)->v);
                }else
                    printf("Erro de redeclaracao: variavel '%s' ja existe.\n",((Symasgn *)a)->s);
                break;
            /* Case referente a execucao da funcao */    
            case 'a':;
                auxFunction = srchfunction(listFunction, ((Textoval*)a->l)->v);
                if(auxFunction != NULL) {
                   eval(auxFunction->v);
                }
                else {
                    printf("\nErro (case 'a'): chamada de funcao errada\n");
                }
                break;
            /* Case para adicionar uma funcao em uma lista de funcoes */
            case 'f':;
                if(srchfunction(listFunction, ((Function*)a)->name) == NULL) {
                    ((Function*)a)->prox = listFunction; //faz o elemento atual apontar o inicio da lista
                    listFunction = (Function*)a; // faz o elemento atual ser o inicio da lista
                }else{
                    printf("\nErro (case 'f'): reescrita de funcao nao permitada.\n");
                    printf("Function %s\n", ((Function*)a)->name);
                }
                break;
            case 'z':;
                printf("Fim do programa\n");
                free(ivar);
                ivar = NULL;
                free(rvar);
                rvar = NULL;
                free(tvar);
                tvar = NULL;
                exit(0);
                break;
            case 'A':; //inserir uma array de inteiros
                if(((Varval*)a)->n)
                    eval(((Varval*)a)->n);

                if(!varexiste(((Varval*)a)->var)){
                    ivar = insi_a(ivar,((Varval*)a)->var,((Varval*)a)->size);
                }else{
                    printf("Erro de redeclaracao: variavel '%s' ja existe.\n",((Symasgn *)a)->s);
                }
                break;
            case 'B':; //inserir uma array de real
                if(((Varval*)a)->n)
                    eval(((Varval*)a)->n);

                if(!varexiste(((Varval*)a)->var)){
                    rvar  = ins_a(rvar,((Varval*)a)->var,((Varval*)a)->size);
                }else{
                    printf("Erro de redeclaracao: variavel '%s' ja existe.\n",((Symasgn *)a)->s);
                }
                break;
            case 'C':; //inserir uma array de texto
                if(((Varval*)a)->n)
                    eval(((Varval*)a)->n);

                if(!varexiste(((Varval*)a)->var)){
                    tvar = inst_a(tvar,((Varval*)a)->var,((Varval*)a)->size);
                }else{
                    printf("Erro de redeclaracao: variavel '%s' ja existe.\n",((Symasgn *)a)->s);
                }
                break;
            case 'D':; //atribuir em um array 
                v = eval(((Symasgn *)a)->v);  //valor que sera atriuido no array
                pos = (int)eval(((Symasgn *)a)->pos);
                VARS * vx = srch(rvar, ((Symasgn *)a)->s);
                VARSI * vxi = srchi(ivar, ((Symasgn *)a)->s);
                VARST * vxt = srcht(tvar, ((Symasgn *)a)->s);

                if(vx != NULL){
                    vx->vet[pos] = v; /*Atribui à variável*/
                } else if (vxi != NULL) {
                    vxi->vet[pos] = (int)v; /*Atribui à variável*/
                } else if (vxt != NULL) {
                    VARST * auxVxt = srcht(tvar, ((Textoval*)((Symasgn*)a)->v)->v);
                    if (auxVxt != NULL) {
                        vxt->vet[pos] = auxVxt->v;
                    }
                    else {
                        vxt->vet[pos] = ((Textoval*)((Symasgn*)a)->v)->v; /*Atribui à variável*/
                    }
                } else {
                    printf("Erro 'atribuir valor'. Var '%s' nao declarada.\n", ((Symasgn *)a)->s);
                }
                break;
            case 'E':; /*  Verificar se foi realizado a declaracao da variavel corretamente */
                pos = (int)eval(((Varval *)a)->pos);
                VARS * evx = srch(rvar, ((Varval *)a)->var);
                VARSI * evxi = srchi(ivar, ((Varval *)a)->var);
                VARST * evxt = srcht(tvar, ((Varval *)a)->var);

                if(evx != NULL){
                    v = evx->vet[pos];
                } else if (evxi != NULL) {
                    v = evxi->vet[pos];
                } else if (evxt != NULL) {
                    v = atof(evxt->vet[pos]);
                }

                break;

            // leitura das variaveis: int, real e texto de um array array
            case 'G':; 
                VARSI * posvxi = srchi(ivar, ((Varval *)a->r)->var);
                if(posvxi != NULL){
                   pos = posvxi->v;
                }
    
                VARS * apvx = srch(rvar, ((Varval *)a->l)->var);
                VARSI * apvxi = srchi(ivar, ((Varval *)a->l)->var);
                VARST * apvxt = srcht(tvar, ((Varval *)a->l)->var);

                if(apvx != NULL){
                    scanf("%f", &apvx->vet[pos]); 
                } else if (apvxi != NULL) {
                    scanf("%d", &apvxi->vet[pos]);
                } else if (apvxt != NULL) {
                    scanf("%s", &apvxt->vet[pos]);
                }
                break;
            case 'H':; /*  imprimir array */
                pos = (int)eval(((Varval *)a)->pos);
                VARS * pvx = srch(rvar, ((Varval *)a)->var);
                VARSI * pvxi = srchi(ivar, ((Varval *)a)->var);
                VARST * pvxt = srcht(tvar, ((Varval *)a)->var);

                if(pvx != NULL){
                    v = pvx->vet[pos];
                    printf("%.2f\n", pvx->vet[pos]); 
                } else if (pvxi != NULL) {
                    v = pvxi->vet[pos];
                    printf("%d\n", pvxi->vet[pos]);
                } else if (pvxt != NULL) {
                    v = 0.0;
                    printf("%s\n", pvxt->vet[pos]);
                } 

                break;

            default: printf("internal error: bad node %c\n", a->nodetype);
        }
        return v;
    }


#line 972 "calc_morgana.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUM_REAL = 258,                /* NUM_REAL  */
    NUM_INT = 259,                 /* NUM_INT  */
    VARIAVEL = 260,                /* VARIAVEL  */
    FUNC = 261,                    /* FUNC  */
    STRING = 262,                  /* STRING  */
    PLUS = 263,                    /* PLUS  */
    LESS = 264,                    /* LESS  */
    TIPO_REAL = 265,               /* TIPO_REAL  */
    TIPO_INT = 266,                /* TIPO_INT  */
    TIPO_TEXT = 267,               /* TIPO_TEXT  */
    VOID = 268,                    /* VOID  */
    IF = 269,                      /* IF  */
    ELSE = 270,                    /* ELSE  */
    WHILE = 271,                   /* WHILE  */
    FOR = 272,                     /* FOR  */
    INICIO = 273,                  /* INICIO  */
    FINAL = 274,                   /* FINAL  */
    RAIZ = 275,                    /* RAIZ  */
    LEITURA = 276,                 /* LEITURA  */
    ESCREVER = 277,                /* ESCREVER  */
    COMENTARIO = 278,              /* COMENTARIO  */
    CMP = 279,                     /* CMP  */
    IFX = 280,                     /* IFX  */
    NEG = 281,                     /* NEG  */
    FUN = 282,                     /* FUN  */
    VET = 283                      /* VET  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 902 "calc_morgana.y"

    char texto[50];
    double real;
    int inteiro;
    int fn;
    Ast *ast;

#line 1055 "calc_morgana.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);


/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUM_REAL = 3,                   /* NUM_REAL  */
  YYSYMBOL_NUM_INT = 4,                    /* NUM_INT  */
  YYSYMBOL_VARIAVEL = 5,                   /* VARIAVEL  */
  YYSYMBOL_FUNC = 6,                       /* FUNC  */
  YYSYMBOL_STRING = 7,                     /* STRING  */
  YYSYMBOL_PLUS = 8,                       /* PLUS  */
  YYSYMBOL_LESS = 9,                       /* LESS  */
  YYSYMBOL_TIPO_REAL = 10,                 /* TIPO_REAL  */
  YYSYMBOL_TIPO_INT = 11,                  /* TIPO_INT  */
  YYSYMBOL_TIPO_TEXT = 12,                 /* TIPO_TEXT  */
  YYSYMBOL_VOID = 13,                      /* VOID  */
  YYSYMBOL_IF = 14,                        /* IF  */
  YYSYMBOL_ELSE = 15,                      /* ELSE  */
  YYSYMBOL_WHILE = 16,                     /* WHILE  */
  YYSYMBOL_FOR = 17,                       /* FOR  */
  YYSYMBOL_INICIO = 18,                    /* INICIO  */
  YYSYMBOL_FINAL = 19,                     /* FINAL  */
  YYSYMBOL_RAIZ = 20,                      /* RAIZ  */
  YYSYMBOL_LEITURA = 21,                   /* LEITURA  */
  YYSYMBOL_ESCREVER = 22,                  /* ESCREVER  */
  YYSYMBOL_COMENTARIO = 23,                /* COMENTARIO  */
  YYSYMBOL_CMP = 24,                       /* CMP  */
  YYSYMBOL_25_ = 25,                       /* '='  */
  YYSYMBOL_26_ = 26,                       /* '+'  */
  YYSYMBOL_27_ = 27,                       /* '-'  */
  YYSYMBOL_28_ = 28,                       /* '*'  */
  YYSYMBOL_29_ = 29,                       /* '/'  */
  YYSYMBOL_30_ = 30,                       /* '^'  */
  YYSYMBOL_31_ = 31,                       /* ')'  */
  YYSYMBOL_32_ = 32,                       /* '('  */
  YYSYMBOL_IFX = 33,                       /* IFX  */
  YYSYMBOL_NEG = 34,                       /* NEG  */
  YYSYMBOL_FUN = 35,                       /* FUN  */
  YYSYMBOL_VET = 36,                       /* VET  */
  YYSYMBOL_37_ = 37,                       /* '{'  */
  YYSYMBOL_38_ = 38,                       /* '}'  */
  YYSYMBOL_39_ = 39,                       /* '['  */
  YYSYMBOL_40_ = 40,                       /* ']'  */
  YYSYMBOL_41_ = 41,                       /* ';'  */
  YYSYMBOL_42_ = 42,                       /* '?'  */
  YYSYMBOL_43_ = 43,                       /* ':'  */
  YYSYMBOL_44_ = 44,                       /* ','  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_begin = 46,                     /* begin  */
  YYSYMBOL_prog = 47,                      /* prog  */
  YYSYMBOL_stm = 48,                       /* stm  */
  YYSYMBOL_ternario = 49,                  /* ternario  */
  YYSYMBOL_stm2 = 50,                      /* stm2  */
  YYSYMBOL_function = 51,                  /* function  */
  YYSYMBOL_declmult = 52,                  /* declmult  */
  YYSYMBOL_declmult2 = 53,                 /* declmult2  */
  YYSYMBOL_escrever = 54,                  /* escrever  */
  YYSYMBOL_list = 55,                      /* list  */
  YYSYMBOL_var = 56,                       /* var  */
  YYSYMBOL_expre = 57,                     /* expre  */
  YYSYMBOL_valor = 58                      /* valor  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  27
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   353

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  169

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   283


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      32,    31,    28,    26,    44,    27,     2,    29,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    43,    41,
       2,    25,     2,    42,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    39,     2,    40,    30,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      33,    34,    35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   949,   949,   953,   954,   958,   959,   960,   961,   962,
     963,   964,   965,   966,   967,   968,   969,   970,   971,   972,
     973,   974,   975,   976,   977,   981,   985,   986,   987,   989,
     990,   994,   999,  1004,  1009,  1010,  1011,  1012,  1013,  1014,
    1018,  1019,  1020,  1021,  1022,  1023,  1027,  1028,  1029,  1030,
    1034,  1035,  1039,  1043,  1046,  1049,  1052,  1055,  1058,  1061,
    1064,  1067,  1070,  1076,  1077,  1078,  1079,  1080
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUM_REAL", "NUM_INT",
  "VARIAVEL", "FUNC", "STRING", "PLUS", "LESS", "TIPO_REAL", "TIPO_INT",
  "TIPO_TEXT", "VOID", "IF", "ELSE", "WHILE", "FOR", "INICIO", "FINAL",
  "RAIZ", "LEITURA", "ESCREVER", "COMENTARIO", "CMP", "'='", "'+'", "'-'",
  "'*'", "'/'", "'^'", "')'", "'('", "IFX", "NEG", "FUN", "VET", "'{'",
  "'}'", "'['", "']'", "';'", "'?'", "':'", "','", "$accept", "begin",
  "prog", "stm", "ternario", "stm2", "function", "declmult", "declmult2",
  "escrever", "list", "var", "expre", "valor", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,    61,    43,    45,    42,    47,
      94,    41,    40,   280,   281,   282,   283,   123,   125,    91,
      93,    59,    63,    58,    44
};
#endif

#define YYPACT_NINF (-121)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -9,   261,    17,  -121,  -121,    22,    20,    47,    60,    39,
      44,    58,    69,    78,    81,    82,  -121,   150,   150,   236,
    -121,  -121,  -121,    41,    48,   277,  -121,  -121,  -121,  -121,
       0,    93,     8,   -10,    -6,     3,   120,   150,   150,   129,
     150,   142,   116,   122,  -121,   111,  -121,  -121,   166,   167,
     150,   150,   150,   150,   150,   150,   291,  -121,   102,  -121,
     134,   135,   150,   172,   150,   179,   178,   187,   162,   305,
     314,   170,   159,   322,   -23,   158,   173,    53,    67,  -121,
      49,    50,  -121,   177,   177,    40,    40,    40,     2,   169,
     102,   188,   190,   102,   181,   102,   184,  -121,   185,   199,
     194,   195,   150,   150,  -121,  -121,    90,   116,  -121,   116,
     196,   197,   150,   230,   228,   238,  -121,  -121,   291,   282,
     150,  -121,  -121,  -121,   208,   261,   261,   102,   298,   203,
     211,  -121,  -121,  -121,  -121,   102,   214,  -121,   220,   221,
    -121,   102,   102,   261,  -121,    46,    95,   261,   239,   245,
    -121,  -121,  -121,   146,   246,  -121,  -121,   248,  -121,  -121,
    -121,   232,   243,   261,   261,   176,   206,  -121,  -121
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,    64,    63,    65,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    23,     0,     0,     0,
       3,    20,    24,    13,    14,     0,    62,     1,    21,    22,
       0,     0,     0,    36,    34,    43,     0,     0,     0,     0,
       0,     0,     0,    65,    61,     0,     2,     4,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     9,     8,    30,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,     0,    46,     0,    58,
      31,    40,    60,    54,    55,    56,    57,    59,    65,     0,
      28,    66,    67,    37,     0,    35,     0,    44,     0,     0,
       0,     0,     0,     0,    53,    16,     0,     0,    15,     0,
       0,     0,     0,     0,     0,     0,    26,    27,     0,     0,
       0,    39,    38,    45,     0,     0,     0,    52,     0,     0,
       0,    49,    47,    66,    67,    32,     0,    42,     0,     0,
      12,    10,    11,     0,    50,     0,     0,     0,     0,     0,
      33,    41,    25,     0,     5,    51,     7,     0,    17,    18,
      29,     0,     0,     0,     0,     0,     0,     6,    19
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -121,  -121,  -121,    -1,  -121,   149,  -121,  -121,  -121,   -54,
    -120,  -121,   -16,  -121
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    19,   144,    21,    89,    22,    23,    24,    76,
     145,    72,    25,    26
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      20,    44,    45,     3,     4,    43,   146,    57,   105,     1,
     116,   117,    60,    61,    58,    62,   106,    27,    47,    64,
      13,    69,    70,   153,    73,    33,    77,    17,    66,    63,
      28,    29,    18,    65,    82,    83,    84,    85,    86,    87,
      90,    78,    67,   165,   166,    36,    93,    30,    95,     3,
       4,     5,    34,   131,    31,   132,     6,     7,     8,     9,
      10,    32,    11,    12,    50,    35,    13,    14,    15,    16,
      55,   110,   111,    17,   112,   114,    37,    50,    18,    51,
      52,    53,    54,    55,   154,    48,   127,   128,   113,   115,
      38,    77,    49,    77,   129,   130,   135,   109,     3,     4,
       5,    39,    90,   141,   142,     6,     7,     8,     9,    10,
      40,    11,    12,    41,    42,    13,    14,    15,    16,     3,
       4,    43,    17,    75,    59,    68,    50,    18,    51,    52,
      53,    54,    55,   156,    71,    50,    13,    51,    52,    53,
      54,    55,    79,    17,   155,   155,   157,    74,    18,     3,
       4,     5,   155,     3,     4,    43,     6,     7,     8,     9,
      10,    78,    11,    12,   155,   155,    13,    14,    15,    16,
      13,    80,    81,    17,    91,    92,    94,    17,    18,     3,
       4,     5,    18,    96,   160,    97,     6,     7,     8,     9,
      10,    98,    11,    12,    99,   102,    13,    14,    15,    16,
     103,    50,   107,    17,   108,    53,    54,    55,    18,     3,
       4,     5,   118,   119,   167,   120,     6,     7,     8,     9,
      10,   121,    11,    12,   122,   123,    13,    14,    15,    16,
     124,   125,   126,    17,   136,   137,   133,   134,    18,     3,
       4,     5,   138,   148,   168,   143,     6,     7,     8,     9,
      10,   149,    11,    12,   150,    46,    13,    14,    15,    16,
     151,   161,   152,    17,     3,     4,     5,   139,    18,   163,
     158,     6,     7,     8,     9,    10,   159,    11,    12,   162,
     164,    13,    14,    15,    16,     3,     4,    43,    17,   140,
       0,     0,     0,    18,     3,     4,    88,     0,     0,     0,
       0,    50,    13,    51,    52,    53,    54,    55,     0,    17,
       0,    13,     0,     0,    18,     0,     0,     0,    17,    56,
       0,     0,    50,    18,    51,    52,    53,    54,    55,    50,
       0,    51,    52,    53,    54,    55,   100,     0,    50,   147,
      51,    52,    53,    54,    55,   101,    50,     0,    51,    52,
      53,    54,    55,   104
};

static const yytype_int16 yycheck[] =
{
       1,    17,    18,     3,     4,     5,   126,     7,    31,    18,
       8,     9,     4,     5,    30,    25,    39,     0,    19,    25,
      20,    37,    38,   143,    40,     5,    42,    27,    25,    39,
       8,     9,    32,    39,    50,    51,    52,    53,    54,    55,
      56,    39,    39,   163,   164,     6,    62,    25,    64,     3,
       4,     5,     5,   107,    32,   109,    10,    11,    12,    13,
      14,    39,    16,    17,    24,     5,    20,    21,    22,    23,
      30,     4,     5,    27,    25,    25,    32,    24,    32,    26,
      27,    28,    29,    30,    38,    44,   102,   103,    39,    39,
      32,   107,    44,   109,     4,     5,   112,    44,     3,     4,
       5,    32,   118,   119,   120,    10,    11,    12,    13,    14,
      32,    16,    17,    32,    32,    20,    21,    22,    23,     3,
       4,     5,    27,     7,    31,     5,    24,    32,    26,    27,
      28,    29,    30,    38,     5,    24,    20,    26,    27,    28,
      29,    30,    31,    27,   145,   146,   147,     5,    32,     3,
       4,     5,   153,     3,     4,     5,    10,    11,    12,    13,
      14,    39,    16,    17,   165,   166,    20,    21,    22,    23,
      20,     5,     5,    27,    40,    40,     4,    27,    32,     3,
       4,     5,    32,     4,    38,     7,    10,    11,    12,    13,
      14,     4,    16,    17,    32,    25,    20,    21,    22,    23,
      41,    24,    44,    27,    31,    28,    29,    30,    32,     3,
       4,     5,    43,    25,    38,    25,    10,    11,    12,    13,
      14,    40,    16,    17,    40,    40,    20,    21,    22,    23,
      31,    37,    37,    27,     4,     7,    40,    40,    32,     3,
       4,     5,     4,    40,    38,    37,    10,    11,    12,    13,
      14,    40,    16,    17,    40,    19,    20,    21,    22,    23,
      40,    15,    41,    27,     3,     4,     5,   118,    32,    37,
      31,    10,    11,    12,    13,    14,    31,    16,    17,    31,
      37,    20,    21,    22,    23,     3,     4,     5,    27,     7,
      -1,    -1,    -1,    32,     3,     4,     5,    -1,    -1,    -1,
      -1,    24,    20,    26,    27,    28,    29,    30,    -1,    27,
      -1,    20,    -1,    -1,    32,    -1,    -1,    -1,    27,    42,
      -1,    -1,    24,    32,    26,    27,    28,    29,    30,    24,
      -1,    26,    27,    28,    29,    30,    31,    -1,    24,    41,
      26,    27,    28,    29,    30,    31,    24,    -1,    26,    27,
      28,    29,    30,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    18,    46,     3,     4,     5,    10,    11,    12,    13,
      14,    16,    17,    20,    21,    22,    23,    27,    32,    47,
      48,    49,    51,    52,    53,    57,    58,     0,     8,     9,
      25,    32,    39,     5,     5,     5,     6,    32,    32,    32,
      32,    32,    32,     5,    57,    57,    19,    48,    44,    44,
      24,    26,    27,    28,    29,    30,    42,     7,    57,    31,
       4,     5,    25,    39,    25,    39,    25,    39,     5,    57,
      57,     5,    56,    57,     5,     7,    54,    57,    39,    31,
       5,     5,    57,    57,    57,    57,    57,    57,     5,    50,
      57,    40,    40,    57,     4,    57,     4,     7,     4,    32,
      31,    31,    25,    41,    31,    31,    39,    44,    31,    44,
       4,     5,    25,    39,    25,    39,     8,     9,    43,    25,
      25,    40,    40,    40,    31,    37,    37,    57,    57,     4,
       5,    54,    54,    40,    40,    57,     4,     7,     4,    50,
       7,    57,    57,    37,    48,    55,    55,    41,    40,    40,
      40,    40,    41,    55,    38,    48,    38,    48,    31,    31,
      38,    15,    31,    37,    37,    55,    55,    38,    38
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    49,    50,    50,    50,    51,
      51,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      53,    53,    53,    53,    53,    53,    54,    54,    54,    54,
      55,    55,    56,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    58,    58,    58,    58,    58
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     1,     2,     7,    11,     7,     3,     3,
       6,     6,     6,     1,     1,     4,     4,     7,     7,    11,
       1,     2,     2,     1,     1,     6,     2,     2,     1,     8,
       3,     3,     5,     6,     2,     4,     2,     4,     5,     5,
       3,     6,     5,     2,     4,     5,     1,     3,     1,     3,
       1,     2,     3,     4,     3,     3,     3,     3,     3,     3,
       3,     2,     1,     1,     1,     1,     4,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* begin: INICIO prog FINAL  */
#line 949 "calc_morgana.y"
                         {eval(newast('z', NULL, NULL));}
#line 2222 "calc_morgana.tab.c"
    break;

  case 3: /* prog: stm  */
#line 953 "calc_morgana.y"
          {eval((yyvsp[0].ast));}
#line 2228 "calc_morgana.tab.c"
    break;

  case 4: /* prog: prog stm  */
#line 954 "calc_morgana.y"
                   {eval((yyvsp[0].ast));}
#line 2234 "calc_morgana.tab.c"
    break;

  case 5: /* stm: IF '(' expre ')' '{' list '}'  */
#line 958 "calc_morgana.y"
                                              {(yyval.ast) = newflow('I', (yyvsp[-4].ast), (yyvsp[-1].ast), NULL);}
#line 2240 "calc_morgana.tab.c"
    break;

  case 6: /* stm: IF '(' expre ')' '{' list '}' ELSE '{' list '}'  */
#line 959 "calc_morgana.y"
                                                      {(yyval.ast) = newflow('I', (yyvsp[-8].ast), (yyvsp[-5].ast), (yyvsp[-1].ast));}
#line 2246 "calc_morgana.tab.c"
    break;

  case 7: /* stm: WHILE '(' expre ')' '{' list '}'  */
#line 960 "calc_morgana.y"
                                       {(yyval.ast) = newflow('W', (yyvsp[-4].ast), (yyvsp[-1].ast), NULL);}
#line 2252 "calc_morgana.tab.c"
    break;

  case 8: /* stm: VARIAVEL '=' expre  */
#line 961 "calc_morgana.y"
                         {(yyval.ast) = newasgn((yyvsp[-2].texto), (yyvsp[0].ast));}
#line 2258 "calc_morgana.tab.c"
    break;

  case 9: /* stm: VARIAVEL '=' STRING  */
#line 962 "calc_morgana.y"
                          {(yyval.ast) = newasgn((yyvsp[-2].texto), newtexto((yyvsp[0].texto)));}
#line 2264 "calc_morgana.tab.c"
    break;

  case 10: /* stm: VARIAVEL '[' NUM_INT ']' '=' expre  */
#line 963 "calc_morgana.y"
                                       {(yyval.ast) = newasgn_a((yyvsp[-5].texto), (yyvsp[0].ast), newint((yyvsp[-3].inteiro)));}
#line 2270 "calc_morgana.tab.c"
    break;

  case 11: /* stm: VARIAVEL '[' VARIAVEL ']' '=' expre  */
#line 964 "calc_morgana.y"
                                        {(yyval.ast) = newasgn_a((yyvsp[-5].texto), (yyvsp[0].ast), newValorVal((yyvsp[-3].texto)));}
#line 2276 "calc_morgana.tab.c"
    break;

  case 12: /* stm: VARIAVEL '[' NUM_INT ']' '=' STRING  */
#line 965 "calc_morgana.y"
                                        {(yyval.ast) = newasgn_a((yyvsp[-5].texto), newtexto((yyvsp[0].texto)), newint((yyvsp[-3].inteiro)));}
#line 2282 "calc_morgana.tab.c"
    break;

  case 13: /* stm: declmult  */
#line 966 "calc_morgana.y"
               { (yyval.ast) = (yyvsp[0].ast) ;}
#line 2288 "calc_morgana.tab.c"
    break;

  case 14: /* stm: declmult2  */
#line 967 "calc_morgana.y"
                { (yyval.ast) = (yyvsp[0].ast) ;}
#line 2294 "calc_morgana.tab.c"
    break;

  case 15: /* stm: ESCREVER '(' escrever ')'  */
#line 968 "calc_morgana.y"
                                {(yyval.ast) = (yyvsp[-1].ast);}
#line 2300 "calc_morgana.tab.c"
    break;

  case 16: /* stm: LEITURA '(' VARIAVEL ')'  */
#line 969 "calc_morgana.y"
                               {(yyval.ast) = newast('c', newValorVal((yyvsp[-1].texto)), NULL);}
#line 2306 "calc_morgana.tab.c"
    break;

  case 17: /* stm: LEITURA '(' VARIAVEL '[' NUM_INT ']' ')'  */
#line 970 "calc_morgana.y"
                                               {(yyval.ast) = newast('G', newValorVal((yyvsp[-4].texto)), newint((yyvsp[-2].inteiro)));}
#line 2312 "calc_morgana.tab.c"
    break;

  case 18: /* stm: LEITURA '(' VARIAVEL '[' VARIAVEL ']' ')'  */
#line 971 "calc_morgana.y"
                                                {(yyval.ast) = newast('G', newValorVal((yyvsp[-4].texto)), newValorVal((yyvsp[-2].texto)));}
#line 2318 "calc_morgana.tab.c"
    break;

  case 19: /* stm: FOR '(' var ';' expre ';' stm ')' '{' list '}'  */
#line 972 "calc_morgana.y"
                                                     { (yyval.ast) = newflowfor('F', (yyvsp[-8].ast), (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-1].ast), NULL);}
#line 2324 "calc_morgana.tab.c"
    break;

  case 20: /* stm: ternario  */
#line 973 "calc_morgana.y"
               { (yyval.ast) = (yyvsp[0].ast); }
#line 2330 "calc_morgana.tab.c"
    break;

  case 21: /* stm: VARIAVEL PLUS  */
#line 974 "calc_morgana.y"
                               {(yyval.ast) = newasgn((yyvsp[-1].texto), newast('+',newValorVal((yyvsp[-1].texto)),newint(1)));}
#line 2336 "calc_morgana.tab.c"
    break;

  case 22: /* stm: VARIAVEL LESS  */
#line 975 "calc_morgana.y"
                               {(yyval.ast) = newasgn((yyvsp[-1].texto), newast('-',newValorVal((yyvsp[-1].texto)),newint(1)));}
#line 2342 "calc_morgana.tab.c"
    break;

  case 23: /* stm: COMENTARIO  */
#line 976 "calc_morgana.y"
                 {(yyval.ast) = newast('P', NULL, NULL);}
#line 2348 "calc_morgana.tab.c"
    break;

  case 24: /* stm: function  */
#line 977 "calc_morgana.y"
               { (yyval.ast) = (yyvsp[0].ast) ;}
#line 2354 "calc_morgana.tab.c"
    break;

  case 25: /* ternario: expre '?' stm2 ':' stm2 ';'  */
#line 981 "calc_morgana.y"
                                      {(yyval.ast) = newflow('?', (yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[-1].ast));}
#line 2360 "calc_morgana.tab.c"
    break;

  case 26: /* stm2: VARIAVEL PLUS  */
#line 985 "calc_morgana.y"
                               {(yyval.ast) = newasgn((yyvsp[-1].texto), newast('+',newValorVal((yyvsp[-1].texto)),newint(1)));}
#line 2366 "calc_morgana.tab.c"
    break;

  case 27: /* stm2: VARIAVEL LESS  */
#line 986 "calc_morgana.y"
                               {(yyval.ast) = newasgn((yyvsp[-1].texto), newast('-',newValorVal((yyvsp[-1].texto)),newint(1)));}
#line 2372 "calc_morgana.tab.c"
    break;

  case 28: /* stm2: expre  */
#line 987 "calc_morgana.y"
            { (yyval.ast) = (yyvsp[0].ast) ;}
#line 2378 "calc_morgana.tab.c"
    break;

  case 29: /* function: VOID FUNC VARIAVEL '(' ')' '{' list '}'  */
#line 989 "calc_morgana.y"
                                                            {(yyval.ast) = newfunction((yyvsp[-7].inteiro), (yyvsp[-5].texto), (yyvsp[-1].ast));}
#line 2384 "calc_morgana.tab.c"
    break;

  case 30: /* function: VARIAVEL '(' ')'  */
#line 990 "calc_morgana.y"
                                 {(yyval.ast) = newast('a', newtexto((yyvsp[-2].texto)), NULL);}
#line 2390 "calc_morgana.tab.c"
    break;

  case 31: /* declmult: declmult ',' VARIAVEL  */
#line 994 "calc_morgana.y"
                                 {
        if ((yyvsp[-2].ast)->nodetype=='A') (yyval.ast) = newvar('i', (yyvsp[0].texto), NULL, (yyvsp[-2].ast));
        else if ((yyvsp[-2].ast)->nodetype=='B') (yyval.ast) = newvar('r', (yyvsp[0].texto), NULL, (yyvsp[-2].ast));
        else (yyval.ast) = newvar((yyvsp[-2].ast)->nodetype, (yyvsp[0].texto), NULL, (yyvsp[-2].ast));
    }
#line 2400 "calc_morgana.tab.c"
    break;

  case 32: /* declmult: declmult ',' VARIAVEL '=' expre  */
#line 999 "calc_morgana.y"
                                      {
        if ((yyvsp[-4].ast)->nodetype=='A') (yyval.ast) = newvar('i', (yyvsp[-2].texto), (yyvsp[0].ast), (yyvsp[-4].ast));
        else if ((yyvsp[-4].ast)->nodetype=='B') (yyval.ast) = newvar('r', (yyvsp[-2].texto), (yyvsp[0].ast), (yyvsp[-4].ast));
        else (yyval.ast) = newvar((yyvsp[-4].ast)->nodetype, (yyvsp[-2].texto), (yyvsp[0].ast), (yyvsp[-4].ast));
    }
#line 2410 "calc_morgana.tab.c"
    break;

  case 33: /* declmult: declmult ',' VARIAVEL '[' NUM_INT ']'  */
#line 1004 "calc_morgana.y"
                                            {
        if ((yyvsp[-5].ast)->nodetype=='i') (yyval.ast) = newarray('A', (yyvsp[-3].texto), (yyvsp[-1].inteiro), (yyvsp[-5].ast));
        else if ((yyvsp[-5].ast)->nodetype=='r') (yyval.ast) = newarray('B', (yyvsp[-3].texto), (yyvsp[-1].inteiro), (yyvsp[-5].ast));
        else (yyval.ast) = newarray((yyvsp[-5].ast)->nodetype, (yyvsp[-3].texto), (yyvsp[-1].inteiro), (yyvsp[-5].ast));
    }
#line 2420 "calc_morgana.tab.c"
    break;

  case 34: /* declmult: TIPO_INT VARIAVEL  */
#line 1009 "calc_morgana.y"
                        {(yyval.ast) = newvar((yyvsp[-1].inteiro), (yyvsp[0].texto), NULL, NULL);}
#line 2426 "calc_morgana.tab.c"
    break;

  case 35: /* declmult: TIPO_INT VARIAVEL '=' expre  */
#line 1010 "calc_morgana.y"
                                  {(yyval.ast) = newvar((yyvsp[-3].inteiro), (yyvsp[-2].texto), (yyvsp[0].ast), NULL);}
#line 2432 "calc_morgana.tab.c"
    break;

  case 36: /* declmult: TIPO_REAL VARIAVEL  */
#line 1011 "calc_morgana.y"
                         {(yyval.ast) = newvar((yyvsp[-1].inteiro), (yyvsp[0].texto), NULL, NULL);}
#line 2438 "calc_morgana.tab.c"
    break;

  case 37: /* declmult: TIPO_REAL VARIAVEL '=' expre  */
#line 1012 "calc_morgana.y"
                                   {(yyval.ast) = newvar((yyvsp[-3].inteiro), (yyvsp[-2].texto), (yyvsp[0].ast), NULL);}
#line 2444 "calc_morgana.tab.c"
    break;

  case 38: /* declmult: TIPO_INT VARIAVEL '[' NUM_INT ']'  */
#line 1013 "calc_morgana.y"
                                        { (yyval.ast) = newarray('A', (yyvsp[-3].texto), (yyvsp[-1].inteiro), NULL);}
#line 2450 "calc_morgana.tab.c"
    break;

  case 39: /* declmult: TIPO_REAL VARIAVEL '[' NUM_INT ']'  */
#line 1014 "calc_morgana.y"
                                         { (yyval.ast) = newarray('B', (yyvsp[-3].texto), (yyvsp[-1].inteiro), NULL);}
#line 2456 "calc_morgana.tab.c"
    break;

  case 40: /* declmult2: declmult2 ',' VARIAVEL  */
#line 1018 "calc_morgana.y"
                                  {(yyval.ast) = newvar('t', (yyvsp[0].texto), NULL, (yyvsp[-2].ast));}
#line 2462 "calc_morgana.tab.c"
    break;

  case 41: /* declmult2: declmult2 ',' VARIAVEL '[' NUM_INT ']'  */
#line 1019 "calc_morgana.y"
                                             { (yyval.ast) = newarray('C', (yyvsp[-3].texto), (yyvsp[-1].inteiro), (yyvsp[-5].ast));}
#line 2468 "calc_morgana.tab.c"
    break;

  case 42: /* declmult2: declmult2 ',' VARIAVEL '=' STRING  */
#line 1020 "calc_morgana.y"
                                        {(yyval.ast) = newvar('t', (yyvsp[-2].texto), newtexto((yyvsp[0].texto)), (yyvsp[-4].ast));}
#line 2474 "calc_morgana.tab.c"
    break;

  case 43: /* declmult2: TIPO_TEXT VARIAVEL  */
#line 1021 "calc_morgana.y"
                         {(yyval.ast) = newvar((yyvsp[-1].inteiro), (yyvsp[0].texto), NULL, NULL);}
#line 2480 "calc_morgana.tab.c"
    break;

  case 44: /* declmult2: TIPO_TEXT VARIAVEL '=' STRING  */
#line 1022 "calc_morgana.y"
                                    {(yyval.ast) = newvar((yyvsp[-3].inteiro), (yyvsp[-2].texto), newtexto((yyvsp[0].texto)), NULL);}
#line 2486 "calc_morgana.tab.c"
    break;

  case 45: /* declmult2: TIPO_TEXT VARIAVEL '[' NUM_INT ']'  */
#line 1023 "calc_morgana.y"
                                         { (yyval.ast) = newarray('C',(yyvsp[-3].texto), (yyvsp[-1].inteiro), NULL);}
#line 2492 "calc_morgana.tab.c"
    break;

  case 46: /* escrever: expre  */
#line 1027 "calc_morgana.y"
                {(yyval.ast) = newast('P', (yyvsp[0].ast), NULL);}
#line 2498 "calc_morgana.tab.c"
    break;

  case 47: /* escrever: expre ',' escrever  */
#line 1028 "calc_morgana.y"
                         {(yyval.ast) = newast('P', (yyvsp[-2].ast), (yyvsp[0].ast));}
#line 2504 "calc_morgana.tab.c"
    break;

  case 48: /* escrever: STRING  */
#line 1029 "calc_morgana.y"
             {(yyval.ast) = newast('P', newtexto((yyvsp[0].texto)), NULL);}
#line 2510 "calc_morgana.tab.c"
    break;

  case 49: /* escrever: STRING ',' escrever  */
#line 1030 "calc_morgana.y"
                          {(yyval.ast) = newast('P', newtexto((yyvsp[-2].texto)), (yyvsp[0].ast));}
#line 2516 "calc_morgana.tab.c"
    break;

  case 50: /* list: stm  */
#line 1034 "calc_morgana.y"
          {(yyval.ast) = (yyvsp[0].ast);}
#line 2522 "calc_morgana.tab.c"
    break;

  case 51: /* list: list stm  */
#line 1035 "calc_morgana.y"
               { (yyval.ast) = newast('L', (yyvsp[-1].ast), (yyvsp[0].ast));}
#line 2528 "calc_morgana.tab.c"
    break;

  case 52: /* var: VARIAVEL '=' expre  */
#line 1039 "calc_morgana.y"
                         {(yyval.ast) = newasgn((yyvsp[-2].texto), (yyvsp[0].ast));}
#line 2534 "calc_morgana.tab.c"
    break;

  case 53: /* expre: RAIZ '(' expre ')'  */
#line 1043 "calc_morgana.y"
                          { 
        {(yyval.ast) = newast('R',(yyvsp[-1].ast),NULL);}
    }
#line 2542 "calc_morgana.tab.c"
    break;

  case 54: /* expre: expre '+' expre  */
#line 1046 "calc_morgana.y"
                      {
        (yyval.ast) = newast('+', (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 2550 "calc_morgana.tab.c"
    break;

  case 55: /* expre: expre '-' expre  */
#line 1049 "calc_morgana.y"
                      {
        (yyval.ast) = newast('-',(yyvsp[-2].ast),(yyvsp[0].ast));
    }
#line 2558 "calc_morgana.tab.c"
    break;

  case 56: /* expre: expre '*' expre  */
#line 1052 "calc_morgana.y"
                      {
        (yyval.ast) = newast('*',(yyvsp[-2].ast),(yyvsp[0].ast));
    }
#line 2566 "calc_morgana.tab.c"
    break;

  case 57: /* expre: expre '/' expre  */
#line 1055 "calc_morgana.y"
                      {
        (yyval.ast) = newast('/',(yyvsp[-2].ast),(yyvsp[0].ast));
    }
#line 2574 "calc_morgana.tab.c"
    break;

  case 58: /* expre: '(' expre ')'  */
#line 1058 "calc_morgana.y"
                    {
        (yyval.ast) = (yyvsp[-1].ast);
    }
#line 2582 "calc_morgana.tab.c"
    break;

  case 59: /* expre: expre '^' expre  */
#line 1061 "calc_morgana.y"
                      {
        (yyval.ast) = newast('^',(yyvsp[-2].ast),(yyvsp[0].ast));
    }
#line 2590 "calc_morgana.tab.c"
    break;

  case 60: /* expre: expre CMP expre  */
#line 1064 "calc_morgana.y"
                      { /* Testes condicionais */
        (yyval.ast) = newcmp((yyvsp[-1].fn),(yyvsp[-2].ast),(yyvsp[0].ast));
    }
#line 2598 "calc_morgana.tab.c"
    break;

  case 61: /* expre: '-' expre  */
#line 1067 "calc_morgana.y"
                          {
        (yyval.ast) = newast('M',(yyvsp[0].ast),NULL); 
    }
#line 2606 "calc_morgana.tab.c"
    break;

  case 62: /* expre: valor  */
#line 1070 "calc_morgana.y"
            { 
        (yyval.ast) = (yyvsp[0].ast); 
    }
#line 2614 "calc_morgana.tab.c"
    break;

  case 63: /* valor: NUM_INT  */
#line 1076 "calc_morgana.y"
               { (yyval.ast) = newint((yyvsp[0].inteiro));}
#line 2620 "calc_morgana.tab.c"
    break;

  case 64: /* valor: NUM_REAL  */
#line 1077 "calc_morgana.y"
               { (yyval.ast) = newreal((yyvsp[0].real));}
#line 2626 "calc_morgana.tab.c"
    break;

  case 65: /* valor: VARIAVEL  */
#line 1078 "calc_morgana.y"
                         { (yyval.ast) = newValorVal((yyvsp[0].texto)); }
#line 2632 "calc_morgana.tab.c"
    break;

  case 66: /* valor: VARIAVEL '[' NUM_INT ']'  */
#line 1079 "calc_morgana.y"
                               {(yyval.ast) = newValorVal_a((yyvsp[-3].texto), newint((yyvsp[-1].inteiro)));}
#line 2638 "calc_morgana.tab.c"
    break;

  case 67: /* valor: VARIAVEL '[' VARIAVEL ']'  */
#line 1080 "calc_morgana.y"
                                {(yyval.ast) = newValorVal_a((yyvsp[-3].texto), newValorVal((yyvsp[-1].texto)));}
#line 2644 "calc_morgana.tab.c"
    break;


#line 2648 "calc_morgana.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1083 "calc_morgana.y"


#include "lex.yy.c"

int main(){
    yyin=fopen("Fibonacci_Facil_URI.txt", "r");
    
    yyparse();
    yylex();
    fclose(yyin);
    return 0;

}

int yywrap(){
    return 0;
}
