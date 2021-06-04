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

    /*typedef struct variavels {
		char name[name_size];
        int type; 
        char tv[string_size];
        int iv;
        double rv;
		struct variavels * prox;
	} VARIAVELS;*/

    // Construção de uma struct para receber o nome e o valor para cada variavel do tipo real
    typedef struct vars {
		char name[name_size];
		float v;
		struct vars * prox;
	} VARS;

    // Construção de uma struct para receber o nome e o valor para cada variavel do tipo inteiro
    typedef struct varsi {
		char name[name_size];
		int v;
		struct varsi * prox;
	} VARSI;

    // Construção de uma struct para receber o nome e o valor para cada variavel do tipo string
    typedef struct VARST {
		char name[name_size];
		char v[string_size];
		struct VARST * prox;
	} VARST;

    typedef struct varfunction {
        int nodetype;
		char name[name_size];
        double v;
		struct varfunction * prox;
	} Varfunction;

    /* Estrutura para funcao */
    typedef struct function {
        int nodetype;
		char name[name_size];
        struct varfunction *var;
        /* Ast *args; */
        /* Ast *v; */
		struct function * prox;
	} Function;

    typedef struct func {
        int nodetype;
        int type;
		char name[name_size];
        /* Ast *args; */
        /* Ast *v; */
	} Func;

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
        double v;
    }Realval;

    typedef struct textoval { /*Estrutura de um número*/
        int nodetype;
        char v[string_size];
    }Textoval;

    /*Estrutura de um nome de variável, nesse exemplo uma variável é um número no vetor var[26]*/
    typedef struct varval { 
        int nodetype;
        char var[name_size];
    }Varval;

    typedef struct listavar {
        char name[name_size];
        VARS *rvar; // real
        VARSI *ivar; // inteiro
        VARST *tvar; // texto
        /* Veci * ivec; */
        Function *function;
        struct listavar * prox;
    }Listavar;

    /*Estrutura de um desvio (if/else/while)*/
    typedef struct flow { 
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
    }Symasgn;    

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

    // Adicionar nova variável do tipo string na lista 
    VARST * inst(VARST *l, char n[]){
		VARST *new =(VARST*)malloc(sizeof(VARST));
		strcpy(new->name, n);
        strcpy(new->v, "");
		new->prox = l;
		return new;
	}

    // Adiciona nova variável na lista do tipo function
    // Function * insfunction(Function *l, Func *fun){
	// 	Function *aux =(Function*)malloc(sizeof(Function));
	// 	if(!aux) {
    //         printf("out of space in insfuntion()\n");
    //         exit(1);
    //     }
    //     aux->nodetype = fun->type;
    //     strcpy(aux->name, fun->name);
    //     aux->var = NULL;
    //     aux->args = fun->args;
    //     aux->v = fun->v;
	// 	aux->prox = l;
	// 	return aux;
	// }

    // Busca uma variável na lista de variáveis na Function
    // Function *srchfunction(Function *l, char n[]){
	// 	Function *aux = l;
    //     //printf("open srchfuntion\n");
	// 	while(aux != NULL){
	// 		if(strcmp(n,aux->name)==0){
	// 			return aux;
	// 		}
	// 		aux = aux->prox;
	// 	}
    //     //printf("function NULL\n");
	// 	return aux;
	// }

    /*Verificar se tem uma funcao na lista de funcoes*/
    // Function *srchfunctionall(Listavar *auxl, char n[]){
    //     Function *auxf;
    //     while(auxl != NULL){
    //         auxf = auxl->function;
    //         //printf("open srchfuntion\n");
    //         while(auxf != NULL){
    //             if(auxf->name)
    //                 //printf("auxf->name = %s\n", auxf->name);
    //             if(strcmp(n, auxf->name)==0){
    //                 return auxf;
    //             }
    //             auxf = auxf->prox;
    //         }
    //         auxl = auxl->prox;
    //     }
    //     //printf("function NULL\n");
	// 	return auxf;
	// }

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

	/* VARS *rvar = NULL;*/
    /* VARSI *ivar = NULL; */
    /* VARST *tvar = NULL; */

    /*Estrutura para um nó de funcao.*/
    /*typedef struct listvar {
    //   char name[name_size];
    //   /* Veci *ivec; vetor */
    //   Function *function;
    //   struct listavar *prox;} Listavar; 

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

    // Busca uma variável na lista de variáveis na funcao
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

    /*Função para criar um nó para salvar a funcao na lista de funcoes*/
    Ast * newfunction(int type, char n[], Ast *a, Ast *fun){
        Func *aux = (Func*)malloc(sizeof(Func));
        if(!aux){
            printf("out of space in newfuntion()");
            exit(1);
        }
        aux->nodetype = 'f';
        aux->type = type;
        strcpy(aux->name, n);
        /* aux->args = a;*/
        /*aux->v = fun;*/
        return (Ast*)aux;
    }

    /*Função para criar um nó para operador iterator*/
    Ast * newastiterate(int nodetype, Ast *l, Ast *r){ 
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

    /*Função que recupera o nome/referência de uma variável - inteiro, real e texto*/
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

    Listavar * lista = NULL;

    /* Verificar se a variavel existe na lista de variaveis */
    bool varexiste(Listavar *l, char v[]) {
        VARS* xr = (VARS*)malloc(sizeof(VARS));
        VARSI* xi = (VARSI*)malloc(sizeof(VARSI));
        VARST* xt = (VARST*)malloc(sizeof(VARST));
    /* if(!xr && !xi && !xt) 
        return false; // se tudo NULL, variavel nao existe
    else
        return true;  // se tudo for TRUE, variavel existe} */
    while(l!=NULL){
            xr = srch(l->rvar, v);
            if(l->ivar==NULL)
                xi = srchi(l->ivar, v);
            xt = srcht(l->tvar, v);
            //Veci* vi = srchveci(lista->ivec, v);

            if (xr) {
                printf("varexiste 1\n");
                return true; // se tudo NULL, var nao existe
            }
            if (xi) {
                printf("varexiste 2\n");
                return true; // se tudo NULL, var nao existe
            }
            if (xt) {
                printf("varexiste 3\n");
                return true; // se tudo NULL, var nao existe
            }
            break;
        }
        //printf("varexiste end 4\n");
        return false; // se tudo NULL, var nao existe
    }

    /*Função que executa operações a partir de um nó*/
    double eval(Ast *a) { 
        double v = 0;
        char v1[50];

        if(!a) {
            printf("internal error, null eval\n");
            return 0.0;
        }
        if(!a) {
            printf("internal error, null eval\n");
            return 0.0;
        }
        VARS * auxr = (VARS*)malloc(sizeof(VARS));
        if(!auxr) {
            printf("out of space (eval 'auxr')");
            exit(1);
        }
        VARSI * auxi = (VARSI*)malloc(sizeof(VARSI));
        if(!auxi) {
            printf("out of space (eval 'auxi')");
            exit(1);
        }
        VARST * auxt = (VARST*)malloc(sizeof(VARST));
        if(!auxt) {
            printf("out of space (eval 'auxt')");
            exit(1);
        }
        Function * auxf = (Function*)malloc(sizeof(Function));
        if(!auxf) {
            printf("out of space (eval 'auxf')");
            exit(1);
        }
        Listavar * auxl = (Listavar*)malloc(sizeof(Listavar));
        if(!auxl) {
            printf("out of space (eval 'auxl')");
            exit(1);
        }
        //printf("nodetype: %c\n", a->nodetype);
        switch(a->nodetype) {
            case 'k': v = ((Intval *)a)->v; break; 	/*Recupera um número inteiro*/
            case 'K': v = ((Realval *)a)->v; break; 	/*Recupera um número real*/
            case 'm': v = atof(((Textoval *)a)->v); break; 	/*Recupera um número real dentro de string*/
            case 'N':; /*  Verificar se foi realizado a declaracao da variavel corretamente */
                auxl = lista;
                if(auxl==NULL){
                    printf ("\nErro (case 'N') - Lista Null. Variavel '%s' nao foi declarada.\n", ((Varval*)a)->var);
                    v = 0.0;
                    break;
                }
                while(auxl!=NULL){
                    auxr = srch(auxl->rvar, ((Varval*)a)->var);
                if (auxr==NULL){
                        auxi = srchi(auxl->ivar, ((Varval*)a)->var);
                        if (!auxi){
                            auxt = srcht(auxl->tvar, ((Varval*)a)->var);
                            if (!auxt){
                                if(auxl->prox==NULL){
                                    printf ("Erro (case 'N') - Variavel '%s' nao foi declarada.\n", ((Varval*)a)->var);
                                    v = 0.0;
                                    break;
                                }
                            } else {
                                v = atof(auxt->v);
                                break;
                            }
                        } else {
                            v = (double)auxi->v;
                            break;
                        }
                    }
                    else{
                        v = auxr->v;
                        break;
                    }
                    auxl = auxl->prox;
                }
                //printf("case N end\n");
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
                } else
                    x->v = v;   /*Atribui à variável*/
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
                            /*
                            auxnt->nodetype = 'P';
                            auxnt->l = newtexto(auxn3->v);
                            auxnt->r = newast('P', NULL, NULL); // nova alteracao do escreva
                            eval(auxnt);
                            */
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
                        /*
                        auxni->nodetype = 'P';
                        auxni->l = newint(auxn2->v);
                        auxni->r = newast('P', NULL, NULL); // nova alteracao do escreva
                        eval(auxni);
                        */
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
                    /*
                    auxnr->nodetype = 'P';
                    auxnr->l = newreal(auxn->v);
                    auxnr->r = newast('P', NULL, NULL); // nova alteracao do escreva
                    eval(auxnr);
                    */
                    v = auxn->v;
                }
                break;
            }
            case 'P': 
                //printf("P1: %c\nP2: %c\n", a->nodetype, a->l->nodetype);
                if(a->l==NULL)
                    break;
                else
                    printf("", a->l->nodetype);
                if(a->l->nodetype == 'N'){
                    a->l->nodetype = 'n';
                    v = eval(a->l);
                    //printf("\nnodetype 'N'\n");
                } else {
                    v = eval(a->l);
                    if(a->l->nodetype != 'n' && a->l->nodetype != 'k' && a->l->nodetype != 'K' && a->l->nodetype != 'm')
                        printf("%.2f", v);
                }
                if(((Intval*)a->l)->nodetype == 'k')
                    printf ("%d", ((Intval*)a->l)->v);		/*Recupera um valor inteiro*/
                else if(((Realval*)a->l)->nodetype == 'K')
                    printf ("%.2f", ((Realval*)a->l)->v);		/*Recupera um valor real*/
                else if(((Textoval*)a->l)->nodetype == 'm')
                    printf ("%s", ((Textoval*)a->l)->v);		/*Recupera um valor texto*/
                if(a->r==NULL){
                    //printf("a->r null\n");
                    printf("\n");
                }else{
                    //printf("a->r ok\n");
                    v = eval(a->r);
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
            /* case 'a':; 
                if(a->l) { 
                   eval(a->l); 
                }
                break;
            */
            /* Case para adicionar uma funcao em uma lista de funcoes */
            case 'f':;
                //printf("func %s\n", ((Func*)a)->name);
                
                if(srchfunction(lista->function, ((Func*)a)->name)==NULL){
                    lista->function = insfunction(lista->function, ((Func*)a));
                } else
                    printf("\nErro (case 'B'): reescrita de funcao nao permitida\n");
                //printf("Function %s\n", ((Func*)a)->name);
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

            default: printf("internal error: bad node %c\n", a->nodetype);
        }
        return v;
    }


#line 960 "calc_morgana.tab.c"

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
    FUN = 282                      /* FUN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 890 "calc_morgana.y"

    char texto[50];
    double real;
    int inteiro;
    int fn;
    Ast *ast;

#line 1042 "calc_morgana.tab.c"

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
  YYSYMBOL_36_ = 36,                       /* '{'  */
  YYSYMBOL_37_ = 37,                       /* '}'  */
  YYSYMBOL_38_ = 38,                       /* ';'  */
  YYSYMBOL_39_ = 39,                       /* '?'  */
  YYSYMBOL_40_ = 40,                       /* ':'  */
  YYSYMBOL_41_ = 41,                       /* ','  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_begin = 43,                     /* begin  */
  YYSYMBOL_prog = 44,                      /* prog  */
  YYSYMBOL_stm = 45,                       /* stm  */
  YYSYMBOL_ternario = 46,                  /* ternario  */
  YYSYMBOL_stm2 = 47,                      /* stm2  */
  YYSYMBOL_outfunc = 48,                   /* outfunc  */
  YYSYMBOL_declmult = 49,                  /* declmult  */
  YYSYMBOL_declmult2 = 50,                 /* declmult2  */
  YYSYMBOL_declfunction = 51,              /* declfunction  */
  YYSYMBOL_escrever = 52,                  /* escrever  */
  YYSYMBOL_list = 53,                      /* list  */
  YYSYMBOL_var = 54,                       /* var  */
  YYSYMBOL_expre = 55,                     /* expre  */
  YYSYMBOL_valor = 56                      /* valor  */
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
#define YYFINAL  28
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   360

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  56
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  131

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   282


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
      32,    31,    28,    26,    41,    27,     2,    29,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    40,    38,
       2,    25,     2,    39,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    30,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,    37,     2,     2,     2,     2,
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
      33,    34,    35
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   935,   935,   939,   940,   944,   945,   946,   947,   948,
     949,   950,   951,   952,   953,   954,   955,   956,   957,   958,
     959,   963,   967,   968,   969,   980,   983,   984,   985,   986,
     987,   988,   992,   993,   994,   995,   999,  1003,  1004,  1005,
    1006,  1010,  1011,  1015,  1019,  1022,  1025,  1028,  1031,  1034,
    1037,  1040,  1043,  1046,  1052,  1053,  1054
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
  "'*'", "'/'", "'^'", "')'", "'('", "IFX", "NEG", "FUN", "'{'", "'}'",
  "';'", "'?'", "':'", "','", "$accept", "begin", "prog", "stm",
  "ternario", "stm2", "outfunc", "declmult", "declmult2", "declfunction",
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
      94,    41,    40,   280,   281,   282,   123,   125,    59,    63,
      58,    44
};
#endif

#define YYPACT_NINF (-104)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -14,   241,    13,  -104,  -104,    -2,    11,    12,    14,    20,
      -3,    10,    26,    18,    21,    27,  -104,    89,    89,   216,
    -104,  -104,  -104,     2,     3,  -104,   257,  -104,  -104,  -104,
    -104,   262,    31,    38,    43,    45,    64,    89,    89,    47,
      35,    89,    69,   271,  -104,  -104,   298,  -104,  -104,    70,
      72,    89,    89,    89,    89,    89,    89,   130,  -104,   330,
    -104,    89,    89,    71,    52,   306,   314,    89,    89,   322,
      48,    50,    54,   278,  -104,    61,    75,  -104,     4,     4,
     -19,   -19,   -19,     0,    63,   330,   330,   330,  -104,    73,
      74,    77,   330,   285,  -104,  -104,   271,  -104,   271,    89,
     104,  -104,  -104,   130,    83,   241,   241,    26,  -104,  -104,
     330,  -104,    82,   241,  -104,    44,    85,    87,  -104,   126,
     109,  -104,  -104,   241,  -104,    90,   156,   241,  -104,   186,
    -104
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,    55,    54,    56,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    19,     0,     0,     0,
       3,    16,    20,    10,    11,    12,     0,    53,     1,    17,
      18,     0,     0,    30,    28,    34,     0,     0,     0,     0,
       0,     0,     0,     0,    56,    52,     0,     2,     4,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     9,     8,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    39,     0,    37,    49,    26,    32,    51,    45,    46,
      47,    48,    50,    56,     0,    24,    31,    29,    35,     0,
       0,     0,    43,     0,    44,    14,     0,    13,     0,     0,
       0,    22,    23,     0,     0,     0,     0,     0,    40,    38,
      27,    33,     0,     0,    41,     0,     0,     0,    21,     0,
       5,    42,     7,     0,    36,     0,     0,     0,    15,     0,
       6
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -104,  -104,  -104,    -1,  -104,    24,  -104,  -104,  -104,  -104,
     -84,  -103,    25,   -16,  -104
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    19,   114,    21,    84,    22,    23,    24,    25,
      72,   115,    40,    26,    27
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      20,    45,    46,   116,     1,    51,    29,    30,   101,   102,
     119,    56,   108,    28,   109,    59,    33,    34,    48,    35,
     126,    65,    66,    31,   129,    69,    36,    73,    51,    37,
      32,    39,    54,    55,    56,    77,    78,    79,    80,    81,
      82,    85,    38,    49,    50,    86,    87,     3,     4,     5,
      41,    92,    93,    42,     6,     7,     8,     9,    10,    43,
      11,    12,    60,    61,    13,    14,    15,    16,    62,    64,
      63,    17,    67,    68,    70,    75,    18,    76,    88,    95,
      73,   120,    73,   110,    89,    97,    99,    85,     3,     4,
       5,    96,     3,     4,    44,     6,     7,     8,     9,    10,
     100,    11,    12,   103,   104,    13,    14,    15,    16,    13,
     105,   111,    17,   106,   121,   121,    17,    18,   121,   113,
     118,    18,   122,   123,   125,   121,   127,   112,   121,     3,
       4,     5,   117,     3,     4,    83,     6,     7,     8,     9,
      10,     0,    11,    12,     0,     0,    13,    14,    15,    16,
      13,     0,     0,    17,     0,     0,     0,    17,    18,     3,
       4,     5,    18,   124,     0,     0,     6,     7,     8,     9,
      10,     0,    11,    12,     0,     0,    13,    14,    15,    16,
       0,     0,     0,    17,     0,     0,     0,     0,    18,     3,
       4,     5,     0,   128,     0,     0,     6,     7,     8,     9,
      10,     0,    11,    12,     0,     0,    13,    14,    15,    16,
       0,     0,     0,    17,     0,     0,     0,     0,    18,     3,
       4,     5,     0,   130,     0,     0,     6,     7,     8,     9,
      10,     0,    11,    12,     0,    47,    13,    14,    15,    16,
       0,     0,     0,    17,     3,     4,     5,     0,    18,     0,
       0,     6,     7,     8,     9,    10,     0,    11,    12,     0,
       0,    13,    14,    15,    16,     3,     4,    44,    17,    58,
       0,     0,     0,    18,     3,     4,    44,     0,    71,     0,
       0,    51,    13,    52,    53,    54,    55,    56,     0,    17,
       0,    13,     0,     0,    18,     0,    57,     0,    17,     0,
       0,     0,    51,    18,    52,    53,    54,    55,    56,    51,
       0,    52,    53,    54,    55,    56,     0,     0,     0,    98,
       0,     0,    51,   107,    52,    53,    54,    55,    56,    74,
      51,     0,    52,    53,    54,    55,    56,    90,    51,     0,
      52,    53,    54,    55,    56,    91,    51,     0,    52,    53,
      54,    55,    56,    94,    51,     0,    52,    53,    54,    55,
      56
};

static const yytype_int16 yycheck[] =
{
       1,    17,    18,   106,    18,    24,     8,     9,     8,     9,
     113,    30,    96,     0,    98,    31,     5,     5,    19,     5,
     123,    37,    38,    25,   127,    41,     6,    43,    24,    32,
      32,     5,    28,    29,    30,    51,    52,    53,    54,    55,
      56,    57,    32,    41,    41,    61,    62,     3,     4,     5,
      32,    67,    68,    32,    10,    11,    12,    13,    14,    32,
      16,    17,    31,    25,    20,    21,    22,    23,    25,     5,
      25,    27,    25,    38,     5,     5,    32,     5,     7,    31,
      96,    37,    98,    99,    32,    31,    25,   103,     3,     4,
       5,    41,     3,     4,     5,    10,    11,    12,    13,    14,
      25,    16,    17,    40,    31,    20,    21,    22,    23,    20,
      36,     7,    27,    36,   115,   116,    27,    32,   119,    36,
      38,    32,    37,    36,    15,   126,    36,   103,   129,     3,
       4,     5,   107,     3,     4,     5,    10,    11,    12,    13,
      14,    -1,    16,    17,    -1,    -1,    20,    21,    22,    23,
      20,    -1,    -1,    27,    -1,    -1,    -1,    27,    32,     3,
       4,     5,    32,    37,    -1,    -1,    10,    11,    12,    13,
      14,    -1,    16,    17,    -1,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,    32,     3,
       4,     5,    -1,    37,    -1,    -1,    10,    11,    12,    13,
      14,    -1,    16,    17,    -1,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,    32,     3,
       4,     5,    -1,    37,    -1,    -1,    10,    11,    12,    13,
      14,    -1,    16,    17,    -1,    19,    20,    21,    22,    23,
      -1,    -1,    -1,    27,     3,     4,     5,    -1,    32,    -1,
      -1,    10,    11,    12,    13,    14,    -1,    16,    17,    -1,
      -1,    20,    21,    22,    23,     3,     4,     5,    27,     7,
      -1,    -1,    -1,    32,     3,     4,     5,    -1,     7,    -1,
      -1,    24,    20,    26,    27,    28,    29,    30,    -1,    27,
      -1,    20,    -1,    -1,    32,    -1,    39,    -1,    27,    -1,
      -1,    -1,    24,    32,    26,    27,    28,    29,    30,    24,
      -1,    26,    27,    28,    29,    30,    -1,    -1,    -1,    41,
      -1,    -1,    24,    38,    26,    27,    28,    29,    30,    31,
      24,    -1,    26,    27,    28,    29,    30,    31,    24,    -1,
      26,    27,    28,    29,    30,    31,    24,    -1,    26,    27,
      28,    29,    30,    31,    24,    -1,    26,    27,    28,    29,
      30
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    18,    43,     3,     4,     5,    10,    11,    12,    13,
      14,    16,    17,    20,    21,    22,    23,    27,    32,    44,
      45,    46,    48,    49,    50,    51,    55,    56,     0,     8,
       9,    25,    32,     5,     5,     5,     6,    32,    32,     5,
      54,    32,    32,    32,     5,    55,    55,    19,    45,    41,
      41,    24,    26,    27,    28,    29,    30,    39,     7,    55,
      31,    25,    25,    25,     5,    55,    55,    25,    38,    55,
       5,     7,    52,    55,    31,     5,     5,    55,    55,    55,
      55,    55,    55,     5,    47,    55,    55,    55,     7,    32,
      31,    31,    55,    55,    31,    31,    41,    31,    41,    25,
      25,     8,     9,    40,    31,    36,    36,    38,    52,    52,
      55,     7,    47,    36,    45,    53,    53,    54,    38,    53,
      37,    45,    37,    36,    37,    15,    53,    36,    37,    53,
      37
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    46,    47,    47,    47,    48,    49,    49,    49,    49,
      49,    49,    50,    50,    50,    50,    51,    52,    52,    52,
      52,    53,    53,    54,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    56,    56,    56
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     1,     2,     7,    11,     7,     3,     3,
       1,     1,     1,     4,     4,     9,     1,     2,     2,     1,
       1,     6,     2,     2,     1,     3,     3,     5,     2,     4,
       2,     4,     3,     5,     2,     4,     8,     1,     3,     1,
       3,     1,     2,     3,     4,     3,     3,     3,     3,     3,
       3,     3,     2,     1,     1,     1,     1
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
#line 935 "calc_morgana.y"
                         {eval(newast('z', NULL, NULL));}
#line 2197 "calc_morgana.tab.c"
    break;

  case 3: /* prog: stm  */
#line 939 "calc_morgana.y"
          {eval((yyvsp[0].ast));}
#line 2203 "calc_morgana.tab.c"
    break;

  case 4: /* prog: prog stm  */
#line 940 "calc_morgana.y"
                   {eval((yyvsp[0].ast));}
#line 2209 "calc_morgana.tab.c"
    break;

  case 5: /* stm: IF '(' expre ')' '{' list '}'  */
#line 944 "calc_morgana.y"
                                              {(yyval.ast) = newflow('I', (yyvsp[-4].ast), (yyvsp[-1].ast), NULL);}
#line 2215 "calc_morgana.tab.c"
    break;

  case 6: /* stm: IF '(' expre ')' '{' list '}' ELSE '{' list '}'  */
#line 945 "calc_morgana.y"
                                                      {(yyval.ast) = newflow('I', (yyvsp[-8].ast), (yyvsp[-5].ast), (yyvsp[-1].ast));}
#line 2221 "calc_morgana.tab.c"
    break;

  case 7: /* stm: WHILE '(' expre ')' '{' list '}'  */
#line 946 "calc_morgana.y"
                                       {(yyval.ast) = newflow('W', (yyvsp[-4].ast), (yyvsp[-1].ast), NULL);}
#line 2227 "calc_morgana.tab.c"
    break;

  case 8: /* stm: VARIAVEL '=' expre  */
#line 947 "calc_morgana.y"
                         {(yyval.ast) = newasgn((yyvsp[-2].texto), (yyvsp[0].ast));}
#line 2233 "calc_morgana.tab.c"
    break;

  case 9: /* stm: VARIAVEL '=' STRING  */
#line 948 "calc_morgana.y"
                          {(yyval.ast) = newasgn((yyvsp[-2].texto), newtexto((yyvsp[0].texto)));}
#line 2239 "calc_morgana.tab.c"
    break;

  case 10: /* stm: declmult  */
#line 949 "calc_morgana.y"
               { (yyval.ast) = (yyvsp[0].ast) ;}
#line 2245 "calc_morgana.tab.c"
    break;

  case 11: /* stm: declmult2  */
#line 950 "calc_morgana.y"
                { (yyval.ast) = (yyvsp[0].ast) ;}
#line 2251 "calc_morgana.tab.c"
    break;

  case 12: /* stm: declfunction  */
#line 951 "calc_morgana.y"
                   { (yyval.ast) = (yyvsp[0].ast); }
#line 2257 "calc_morgana.tab.c"
    break;

  case 13: /* stm: ESCREVER '(' escrever ')'  */
#line 952 "calc_morgana.y"
                                {(yyval.ast) = (yyvsp[-1].ast);}
#line 2263 "calc_morgana.tab.c"
    break;

  case 14: /* stm: LEITURA '(' VARIAVEL ')'  */
#line 953 "calc_morgana.y"
                               {(yyval.ast) = newast('c', newValorVal((yyvsp[-1].texto)), NULL);}
#line 2269 "calc_morgana.tab.c"
    break;

  case 15: /* stm: FOR var ';' expre ';' var '{' list '}'  */
#line 954 "calc_morgana.y"
                                             { (yyval.ast) = newflowfor('F', (yyvsp[-7].ast), (yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[-1].ast), NULL);}
#line 2275 "calc_morgana.tab.c"
    break;

  case 16: /* stm: ternario  */
#line 955 "calc_morgana.y"
               { (yyval.ast) = (yyvsp[0].ast); }
#line 2281 "calc_morgana.tab.c"
    break;

  case 17: /* stm: VARIAVEL PLUS  */
#line 956 "calc_morgana.y"
                               {(yyval.ast) = newasgn((yyvsp[-1].texto), newast('+',newValorVal((yyvsp[-1].texto)),newint(1)));}
#line 2287 "calc_morgana.tab.c"
    break;

  case 18: /* stm: VARIAVEL LESS  */
#line 957 "calc_morgana.y"
                               {(yyval.ast) = newasgn((yyvsp[-1].texto), newast('-',newValorVal((yyvsp[-1].texto)),newint(1)));}
#line 2293 "calc_morgana.tab.c"
    break;

  case 19: /* stm: COMENTARIO  */
#line 958 "calc_morgana.y"
                 {(yyval.ast) = newast('P', NULL, NULL);}
#line 2299 "calc_morgana.tab.c"
    break;

  case 20: /* stm: outfunc  */
#line 959 "calc_morgana.y"
              { (yyval.ast) = (yyvsp[0].ast); }
#line 2305 "calc_morgana.tab.c"
    break;

  case 21: /* ternario: expre '?' stm2 ':' stm2 ';'  */
#line 963 "calc_morgana.y"
                                      {(yyval.ast) = newflow('?', (yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[-1].ast));}
#line 2311 "calc_morgana.tab.c"
    break;

  case 22: /* stm2: VARIAVEL PLUS  */
#line 967 "calc_morgana.y"
                               {(yyval.ast) = newasgn((yyvsp[-1].texto), newast('+',newValorVal((yyvsp[-1].texto)),newint(1)));}
#line 2317 "calc_morgana.tab.c"
    break;

  case 23: /* stm2: VARIAVEL LESS  */
#line 968 "calc_morgana.y"
                               {(yyval.ast) = newasgn((yyvsp[-1].texto), newast('-',newValorVal((yyvsp[-1].texto)),newint(1)));}
#line 2323 "calc_morgana.tab.c"
    break;

  case 24: /* stm2: expre  */
#line 969 "calc_morgana.y"
            { (yyval.ast) = (yyvsp[0].ast) ;}
#line 2329 "calc_morgana.tab.c"
    break;

  case 25: /* outfunc: VARIAVEL '(' ')'  */
#line 980 "calc_morgana.y"
                                    {(yyval.ast) = newast('a', newtexto((yyvsp[-2].texto)), NULL);}
#line 2335 "calc_morgana.tab.c"
    break;

  case 26: /* declmult: declmult ',' VARIAVEL  */
#line 983 "calc_morgana.y"
                                 {(yyval.ast) = newvar((yyvsp[-2].ast)->nodetype, (yyvsp[0].texto), NULL, (yyvsp[-2].ast));}
#line 2341 "calc_morgana.tab.c"
    break;

  case 27: /* declmult: declmult ',' VARIAVEL '=' expre  */
#line 984 "calc_morgana.y"
                                      {(yyval.ast) = newvar((yyvsp[-4].ast)->nodetype, (yyvsp[-2].texto), (yyvsp[0].ast), (yyvsp[-4].ast));}
#line 2347 "calc_morgana.tab.c"
    break;

  case 28: /* declmult: TIPO_INT VARIAVEL  */
#line 985 "calc_morgana.y"
                        {(yyval.ast) = newvar((yyvsp[-1].inteiro), (yyvsp[0].texto), NULL, NULL);}
#line 2353 "calc_morgana.tab.c"
    break;

  case 29: /* declmult: TIPO_INT VARIAVEL '=' expre  */
#line 986 "calc_morgana.y"
                                  {(yyval.ast) = newvar((yyvsp[-3].inteiro), (yyvsp[-2].texto), (yyvsp[0].ast), NULL);}
#line 2359 "calc_morgana.tab.c"
    break;

  case 30: /* declmult: TIPO_REAL VARIAVEL  */
#line 987 "calc_morgana.y"
                         {(yyval.ast) = newvar((yyvsp[-1].inteiro), (yyvsp[0].texto), NULL, NULL);}
#line 2365 "calc_morgana.tab.c"
    break;

  case 31: /* declmult: TIPO_REAL VARIAVEL '=' expre  */
#line 988 "calc_morgana.y"
                                   {(yyval.ast) = newvar((yyvsp[-3].inteiro), (yyvsp[-2].texto), (yyvsp[0].ast), NULL);}
#line 2371 "calc_morgana.tab.c"
    break;

  case 32: /* declmult2: declmult2 ',' VARIAVEL  */
#line 992 "calc_morgana.y"
                                  {(yyval.ast) = newvar((yyvsp[-2].ast)->nodetype, (yyvsp[0].texto), NULL, (yyvsp[-2].ast));}
#line 2377 "calc_morgana.tab.c"
    break;

  case 33: /* declmult2: declmult2 ',' VARIAVEL '=' STRING  */
#line 993 "calc_morgana.y"
                                        {(yyval.ast) = newvar((yyvsp[-4].ast)->nodetype, (yyvsp[-2].texto), newtexto((yyvsp[0].texto)), (yyvsp[-4].ast));}
#line 2383 "calc_morgana.tab.c"
    break;

  case 34: /* declmult2: TIPO_TEXT VARIAVEL  */
#line 994 "calc_morgana.y"
                         {(yyval.ast) = newvar((yyvsp[-1].inteiro), (yyvsp[0].texto), NULL, NULL);}
#line 2389 "calc_morgana.tab.c"
    break;

  case 35: /* declmult2: TIPO_TEXT VARIAVEL '=' STRING  */
#line 995 "calc_morgana.y"
                                    {(yyval.ast) = newvar((yyvsp[-3].inteiro), (yyvsp[-2].texto), newtexto((yyvsp[0].texto)), NULL);}
#line 2395 "calc_morgana.tab.c"
    break;

  case 36: /* declfunction: VOID FUNC VARIAVEL '(' ')' '{' list '}'  */
#line 999 "calc_morgana.y"
                                                                { (yyval.ast) = newfunction((yyvsp[-7].inteiro), (yyvsp[-5].texto), NULL, (yyvsp[-1].ast));}
#line 2401 "calc_morgana.tab.c"
    break;

  case 37: /* escrever: expre  */
#line 1003 "calc_morgana.y"
                {(yyval.ast) = newast('P', (yyvsp[0].ast), NULL);}
#line 2407 "calc_morgana.tab.c"
    break;

  case 38: /* escrever: expre ',' escrever  */
#line 1004 "calc_morgana.y"
                         {(yyval.ast) = newast('P', (yyvsp[-2].ast), (yyvsp[0].ast));}
#line 2413 "calc_morgana.tab.c"
    break;

  case 39: /* escrever: STRING  */
#line 1005 "calc_morgana.y"
             {(yyval.ast) = newast('P', newtexto((yyvsp[0].texto)), NULL);}
#line 2419 "calc_morgana.tab.c"
    break;

  case 40: /* escrever: STRING ',' escrever  */
#line 1006 "calc_morgana.y"
                          {(yyval.ast) = newast('P', newtexto((yyvsp[-2].texto)), (yyvsp[0].ast));}
#line 2425 "calc_morgana.tab.c"
    break;

  case 41: /* list: stm  */
#line 1010 "calc_morgana.y"
          {(yyval.ast) = (yyvsp[0].ast);}
#line 2431 "calc_morgana.tab.c"
    break;

  case 42: /* list: list stm  */
#line 1011 "calc_morgana.y"
               { (yyval.ast) = newast('L', (yyvsp[-1].ast), (yyvsp[0].ast));}
#line 2437 "calc_morgana.tab.c"
    break;

  case 43: /* var: VARIAVEL '=' expre  */
#line 1015 "calc_morgana.y"
                         {(yyval.ast) = newasgn((yyvsp[-2].texto), (yyvsp[0].ast));}
#line 2443 "calc_morgana.tab.c"
    break;

  case 44: /* expre: RAIZ '(' expre ')'  */
#line 1019 "calc_morgana.y"
                          { 
        {(yyval.ast) = newast('R',(yyvsp[-1].ast),NULL);}
    }
#line 2451 "calc_morgana.tab.c"
    break;

  case 45: /* expre: expre '+' expre  */
#line 1022 "calc_morgana.y"
                      {
        (yyval.ast) = newast('+', (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 2459 "calc_morgana.tab.c"
    break;

  case 46: /* expre: expre '-' expre  */
#line 1025 "calc_morgana.y"
                      {
        (yyval.ast) = newast('-',(yyvsp[-2].ast),(yyvsp[0].ast));
    }
#line 2467 "calc_morgana.tab.c"
    break;

  case 47: /* expre: expre '*' expre  */
#line 1028 "calc_morgana.y"
                      {
        (yyval.ast) = newast('*',(yyvsp[-2].ast),(yyvsp[0].ast));
    }
#line 2475 "calc_morgana.tab.c"
    break;

  case 48: /* expre: expre '/' expre  */
#line 1031 "calc_morgana.y"
                      {
        (yyval.ast) = newast('/',(yyvsp[-2].ast),(yyvsp[0].ast));
    }
#line 2483 "calc_morgana.tab.c"
    break;

  case 49: /* expre: '(' expre ')'  */
#line 1034 "calc_morgana.y"
                    {
        (yyval.ast) = (yyvsp[-1].ast);
    }
#line 2491 "calc_morgana.tab.c"
    break;

  case 50: /* expre: expre '^' expre  */
#line 1037 "calc_morgana.y"
                      {
        (yyval.ast) = newast('^',(yyvsp[-2].ast),(yyvsp[0].ast));
    }
#line 2499 "calc_morgana.tab.c"
    break;

  case 51: /* expre: expre CMP expre  */
#line 1040 "calc_morgana.y"
                      { /* Testes condicionais */
        (yyval.ast) = newcmp((yyvsp[-1].fn),(yyvsp[-2].ast),(yyvsp[0].ast));
    }
#line 2507 "calc_morgana.tab.c"
    break;

  case 52: /* expre: '-' expre  */
#line 1043 "calc_morgana.y"
                          {
        (yyval.ast) = newast('M',(yyvsp[0].ast),NULL); 
    }
#line 2515 "calc_morgana.tab.c"
    break;

  case 53: /* expre: valor  */
#line 1046 "calc_morgana.y"
            { 
        (yyval.ast) = (yyvsp[0].ast); 
    }
#line 2523 "calc_morgana.tab.c"
    break;

  case 54: /* valor: NUM_INT  */
#line 1052 "calc_morgana.y"
               { (yyval.ast) = newint((yyvsp[0].inteiro));}
#line 2529 "calc_morgana.tab.c"
    break;

  case 55: /* valor: NUM_REAL  */
#line 1053 "calc_morgana.y"
               { (yyval.ast) = newreal((yyvsp[0].real));}
#line 2535 "calc_morgana.tab.c"
    break;

  case 56: /* valor: VARIAVEL  */
#line 1054 "calc_morgana.y"
               {           
        (yyval.ast) = newValorVal((yyvsp[0].texto));  /* Funcao da chamada newValorVal retorna um tipo Ast que dps e usado em eval */
    }
#line 2543 "calc_morgana.tab.c"
    break;


#line 2547 "calc_morgana.tab.c"

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

#line 1059 "calc_morgana.y"


#include "lex.yy.c"

int main(){
    yyin=fopen("entrada_function.txt", "r");
    
    yyparse();
    yylex();
    fclose(yyin);
    return 0;

}

int yywrap(){
    return 0;
}
