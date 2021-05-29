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
#line 1 ".\\calc_exemplo_function.y"

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

    #define name_size 30
    #define string_size 1000

    typedef struct variavels {
		char name[name_size];
        int type; // string se 0, int se 1, double se 2
        char tv[string_size];
        int iv;
        double rv;
		struct variavels * prox;
	} VARIAVELS;

    typedef struct ast { /*Estrutura de um nó*/
        int nodetype;
        struct ast *l; /*Esquerda*/
        struct ast *r; /*Direita*/
    }Ast; 

    typedef struct vars {
		char name[name_size];
        double v;
		struct vars * prox;
	} VARS;

    typedef struct varsi {
		char name[name_size];
        int v;
		struct varsi * prox;
	} VARSI;

    typedef struct varst {
		char name[name_size];
		char v[string_size];
		struct varst * prox;
	} VARST;
    // estrutura de vetor
    typedef struct veci {
		char name[name_size];
        int v;
        struct veci * in;
		struct veci * prox;
	} Veci;

    typedef struct varfunction {
        int nodetype;
		char name[name_size];
        double v;
		struct varfunction * prox;
	} Varfunction;

    // struct funtion
    typedef struct function {
        int nodetype;
		char name[name_size];
        struct varfunction *var;
        Ast *args;
        Ast *v;
		struct function * prox;
	} Function;
    
    typedef struct func {
        int nodetype;
        int type;
		char name[name_size];
        Ast *args;
        Ast *v;
	} Func;

    typedef struct symasgn { /*Estrutura para um nó de atribuição. Para atrubuir o valor de v em s*/
        int nodetype;
        char s[name_size];
        Ast *v;
        Ast *n;
    }Symasgn;

    typedef struct flow { /*Estrutura de um desvio (if/else/while)*/
        int nodetype;
        Ast *cond;		/*condição*/
        Ast *tl;		/*then, ou seja, verdade*/
        Ast *el;		/*else*/
    }Flow;

    typedef struct flowfor{
        int nodetype;
        Ast* v1;
        Ast* v2;
        Ast* v3;
    }Flowfor;

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
        char v[string_size];
    }Textoval;

    typedef struct varval { /*Estrutura de um nome de variável, nesse exemplo uma variável é um número no vetor var[26]*/
        int nodetype;
        char var[name_size];
    }Varval;

    typedef struct listavar {
        char name[name_size];
        VARSI *ivar;
        VARS *rvar;
        VARST *tvar;
        Veci * ivec;
        Function *function;
        struct listavar * prox;
    } Listavar;

    //add nova variável na lista
	VARS * ins(VARS *l, char n[]){
		//printf("ins begin\n");
        VARS *aux =(VARS*)malloc(sizeof(VARS));
		if(!aux) {
            printf("out of space 'ins()'\n");
            exit(0);
        }
        strcpy(aux->name, n);
		aux->prox = l;
        //printf("ins end\n");
		return aux;
	}

    //busca uma variável na lista de variáveis
	VARS *srch(VARS *aux, char n[]){
		//printf("srch begin\n");
        int i = 1;
        //printf("srch real 0: %s\n", n);
		while(aux != NULL){
            //printf("srch real %d: %s\n", i++, aux->name);
			if(strcmp(n, aux->name)==0){
                //printf("return %s\n", aux->name);
				return aux;
			}
			aux = aux->prox;
		}
        //printf("srch end\n");
		return aux;
	}
    
    VARS *srchall(Listavar *l, char n[]){
		//printf("srch begin\n");
        //int i = 1;
        //printf("srch real %d: %s\n", i++, aux->name);
		VARS * aux;
        while(l != NULL){
            aux = l->rvar;
            while(aux != NULL){
                if(strcmp(n, aux->name)==0){
                    return aux;
                }
                aux = aux->prox;
            }
            l = l->prox;
        }
        //printf("srch end\n");
		return aux;
	}

    VARSI * insi(VARSI *l, char n[]){
		VARSI *aux =(VARSI*)malloc(sizeof(VARSI));
		if(!aux) {
            printf("out of space");
            exit(0);
        }
        strcpy(aux->name, n);
		aux->prox = l;
		return aux;
	}

    //busca uma variável na lista de variáveis
	VARSI *srchi(VARSI *aux, char n[]){
        //printf("srchi begin\n");
		while(aux!=NULL){
            //printf("inteiro %s\n", aux->name);
			if(strcmp(n, aux->name)==0) 
                break;
			else
                aux = aux->prox;
		}
        //printf("srchi end\n");
		return aux;
	}

    VARSI *srchiall(Listavar *l, char n[]){
        //printf("srchi begin\n");
		VARSI * aux;
        while(l!=NULL){
            aux = l->ivar;
            while(aux!=NULL){
                //printf("inteiro %s\n", aux->name);
                if(strcmp(n, aux->name)==0) 
                    break;
                else
                    aux = aux->prox;
            }
            l = l->prox;
        }
        //printf("srchi end\n");
		return aux;
	}

    //add nova variável na lista
    VARST * inst(VARST *l, char n[]){
		VARST *aux =(VARST*)malloc(sizeof(VARST));
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
    VARST *srcht(VARST *aux, char n[]){
		//printf("srcht begin\n");
		while(aux!=NULL){
			if(strcmp(n, aux->name)==0){
				return aux;
			}
			aux = aux->prox;
		}
        //printf("srcht end\n");
		return aux;
	}

    //add novo vetor na lista de vetores
	Veci * insveci(Veci *l, char n[]){
		Veci *aux =(Veci*)malloc(sizeof(Veci));
		if(!aux) {
            printf("out of space");
            exit(0);
        }
        strcpy(aux->name, n);
        aux->in = (Veci*)NULL;
		aux->prox = l;
		return aux;
	}

    //busca uma variável na lista de vetores
	Veci *srchveci(Veci *l, char n[]){
		Veci *aux = l;
		while(aux != NULL){
			if(strcmp(n, aux->name)==0){
				return aux;
			}
			aux = aux->prox;
		}
		return aux;
	}

    //busca uma variável na lista de vetores
	Veci *srchvecip(Veci *l, int n){
		Veci *aux = l;
		for(int x = 0; x < n; x++){
			aux = aux->in;
            if (!aux)
                return aux;
		}
		return aux;
	}

    //add nova variável na lista
    Function * insfunction(Function *l, Func *fun){
		Function *aux =(Function*)malloc(sizeof(Function));
		if(!aux) {
            printf("out of space in insfuntion()\n");
            exit(1);
        }
        aux->nodetype = fun->type;
        strcpy(aux->name, fun->name);
        aux->var = NULL;
        aux->args = fun->args;
        aux->v = fun->v;
		aux->prox = l;
		return aux;
	}
	
    //busca uma variável na lista de variáveis
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

    Function *srchfunctionall(Listavar *auxl, char n[]){
        Function *auxf;
        while(auxl != NULL){
            auxf = auxl->function;
            //printf("open srchfuntion\n");
            while(auxf != NULL){
                if(auxf->name)
                    //printf("auxf->name = %s\n", auxf->name);
                if(strcmp(n, auxf->name)==0){
                    return auxf;
                }
                auxf = auxf->prox;
            }
            auxl = auxl->prox;
        }
        //printf("function NULL\n");
		return auxf;
	}

    Ast * newfunction(int type, char n[], Ast *a, Ast *fun){
        Func *aux = (Func*)malloc(sizeof(Func));
        if(!aux){
            printf("out of space in newfuntion()");
            exit(1);
        }
        aux->nodetype = 'B';
        aux->type = type;
        strcpy(aux->name, n);
        aux->args = a;
        aux->v = fun;
        return (Ast*)aux;
    }

    // VERIFICAR SE DADO VALOR É REAL
    bool isreal(char test[]){
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

    /*O nodetype serve para indicar o tipo de nó que está na árvore. Isso serve para a função eval() entender o que realizar naquele nó*/
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

    // função pra declarar variavel e atribuir
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

    // função pra declarar variavel e atribuir
    Ast * newvec(int t, char s[], Ast *v, Ast *n){
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

    Ast * newflowfor(int nodetype, Ast *b1, Ast *b2, Ast *b3, Ast *tl, Ast *el){ /*Função que cria um nó de FOR*/
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

    Listavar * lista = NULL;

    bool varexiste(Listavar * l, char v[]) {
        //printf("varexiste begin\n");
        VARS* xr = (VARS*)malloc(sizeof(VARS));
        VARSI* xi = (VARSI*)malloc(sizeof(VARSI));
        VARST* xt = (VARST*)malloc(sizeof(VARST));
        while(l!=NULL){
            xr = srch(l->rvar, v);
            if(l->ivar==NULL)
                xi = srchi(l->ivar, v);
            xt = srcht(l->tvar, v);
            //Veci* vi = srchveci(lista->ivec, v);

            if (xr) {
                //printf("varexiste end 1\n");
                return true; // se tudo NULL, var nao existe
            }
            if (xi) {
                //printf("varexiste end 2\n");
                return true; // se tudo NULL, var nao existe
            }
            if (xt) {
                //printf("varexiste end 3\n");
                return true; // se tudo NULL, var nao existe
            }
            break;
        }
        //printf("varexiste end 4\n");
        return false; // se tudo NULL, var nao existe
    }

    void printvec(Veci *a){
        int i = 0;
        while(a){
            printf("%s[%d] = %d\n", a->name, i, a->v);
            i++;
            a = a->in;
        }
    }
    void printvecp(Veci *a, int x){
        //printf("1 printvecp\n");
        int i = 0;
        char name[name_size];
        strcpy(name, a->name);
        //printf("2 printvecp\n");
        bool teste = true;
        while(teste){
            //printf("4 printvecp\n");
            if(a->in)
                a = a->in;
            else {
                //printf("5 printvecp\n");
                teste = false;
            }
        }
        //printf("3 printvecp\n");
        if(teste)
            printf("%s[%d] = %d\n", name, i, a->v);
        else
            printf("\nErro (printvecp()): posicao fora do vetor\n");
    }

    void * printValorVar(Listavar *auxl, char var[]){
        //printf("VAR %s\n", var);
        VARS * auxr;
        VARSI * auxi;
        VARST * auxt;
        if(auxl==NULL)
            printf ("\nErro (printValorVar()) - lista de variaveis nula. Variavel nao declarada.\n", var);
        while(auxl!=NULL){
            auxr = srch(auxl->rvar, var);
            if (auxr){
                printf("%f", auxr->v);
                break;
            } else {
                auxi = srchi(auxl->ivar, var);
                if (auxi){
                    printf("%d", auxi->v);
                    break;
                } else {
                    auxt = srcht(auxl->tvar, var);
                    if (auxt){
                        printf("%s", auxt->v);
                        break;
                    }
                    else{
                        if(auxl->prox==NULL)
                            printf ("\nErro (printValorVar()) - Variavel '%s' nao foi declarada.\n", var);
                    }
                }
            }
            auxl = auxl->prox;
        }
    }

    double eval(Ast *a) { /*Função que executa operações a partir de um nó*/
        double v = 0;
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

        //printf("\na->type: %c\n", a->nodetype);
        switch(a->nodetype) {
            case 'k': v = ((Intval *)a)->v; break; 	/*Recupera um número inteiro*/
            case 'K': v = ((Realval *)a)->v; break; 	/*Recupera um número real*/
            case 'm': v = atof(((Textoval *)a)->v); break; 	/*Recupera um número real dentro de string*/
            case 'N':;
                //printf("case N begin\n");
                auxl = lista;
                if(auxl==NULL){
                    printf ("\nErro (case 'N') - Lista Null. Variavel '%s' nao foi declarada.\n", ((Varval*)a)->var);
                    v = 0.0;
                    break;
                }
                //int i = 1;
//                printf("case N begin while\n");
                while(auxl!=NULL){
                    //printf("case 'N' %d\n", i++);
                    auxr = srch(auxl->rvar, ((Varval*)a)->var);
                    //if(auxr)
                        //printf("var okay\n");
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
            case '-': v = eval(a->l) - eval(a->r); break;	/*Operações*/
            case '*': v = eval(a->l) * eval(a->r); break;	/*Operações*/
            case '/': v = eval(a->l) / eval(a->r); break; /*Operações*/
            case '%':; 
                double v1 = eval(a->l);
                double v2 = eval(a->r);
                v = v1/v2;
                int aa = (int)v;
                v = (v - aa)*v2;
                break; /*Operações*/
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
            case '?': 
                if (eval(((Flow *)a)->cond) != 0) {	/*executa a condição / teste*/
                    if (((Flow *)a)->tl)		/*Se existir árvore*/
                        v = eval(((Flow *)a)->tl); /*Verdade*/
                    else
                        v = 0.0;
                } else {
                    if( ((Flow *)a)->el ) {
                        v = eval(((Flow *)a)->el); /*Falso*/
                    } else
                        v = 0.0;
                    }
                break; 
            
            case '=':;
                //printf("case '=' begin\n");
                v = eval(((Symasgn *)a)->v); /*Recupera o valor*/
                auxl = lista;
                if(auxl == NULL){
                    printf("\nErro de var nao declarada\n");
                    v = 0.0;
                    break;
                }
                //printf("case = begin while\n");
                while(auxl!=NULL){
                    auxr = srch(auxl->rvar, ((Symasgn *)a)->s);
                    if(!auxr){
                        auxi = srchi(auxl->ivar, ((Symasgn *)a)->s);
                        if(!auxi){
                            auxt = srcht(auxl->tvar, ((Symasgn *)a)->s);
                            if(!auxt){
                                if(auxl->prox == NULL){
                                    printf("\nErro de var nao declarada\n");
                                    v = 0.0;
                                    break;
                                }
                            } else{
                                strcpy(auxt->v, ((Textoval*)((Symasgn *)a)->v)->v); /*Atribui à variável*/
                                break;
                            }
                        } else{
                            auxi->v = (int)v; /*Atribui à variável*/
                            break;
                        }
                    } else{
                        auxr->v = v;   /*Atribui à variável*/
                        break;
                    }
                    auxl = auxl->prox;
                }
                //printf("case '=' end\n");
                break;
            /*CASO IF*/
            case 'I': 
                if (eval(((Flow *)a)->cond) != 0) {	/*executa a condição / teste*/
                    if (((Flow *)a)->tl)		/*Se existir árvore*/
                        v = eval(((Flow *)a)->tl); /*Verdade*/
                    else
                        v = 0.0;
                } else {
                    if( ((Flow *)a)->el ) {
                        v = eval(((Flow *)a)->el); /*Falso*/
                    } else
                        v = 0.0;
                    }
                break;
            /*CASO WHILE*/
            case 'W':
                v = 0.0;
                if( ((Flow *)a)->tl ) {
                    while( eval(((Flow *)a)->cond) != 0){
                        v = eval(((Flow *)a)->tl);
                        }
                }
            break;
            /*CASO FOR*/
            case 'F':
                v = 0.0;
                /*
                if( ((Flow *)a)->tl ) {
                    for(eval(((Flowfor*)((Flow *)a)->cond)->v1); 
                        eval(((Flowfor*)((Flow *)a)->cond)->v2); 
                        eval(((Flowfor*)((Flow *)a)->cond)->v3)
                        ){
                            v =  eval(((Flow *)a)->tl);
                    }
                }//*/
                if( ((Flow *)a)->tl ){
                    char name[name_size];
                    if(((Symasgn*)((Flowfor*)((Flow *)a)->cond)->v1)->s){
                        strcpy(name, ((Symasgn*)((Flowfor*)((Flow *)a)->cond)->v1)->s);
                    }
                    if(((Flowfor*)((Flow *)a)->cond)->v1)
                        v = eval(((Flowfor*)((Flow *)a)->cond)->v1);
                    
                    auxl = lista;
                    while(auxl!=NULL){
                        auxr = srch(auxl->rvar, name);
                        if(auxr){
                            for(auxr->v; 
                                eval(((Flowfor*)((Flow *)a)->cond)->v2); 
                                auxr->v += eval(((Flowfor*)((Flow *)a)->cond)->v3)
                                ){
                                    v =  eval(((Flow *)a)->tl);
                            }
                        } else {
                            auxi = srchi(auxl->ivar, name);
                            if(auxi){
                                for(auxi->v; 
                                    eval(((Flowfor*)((Flow *)a)->cond)->v2); 
                                    auxi->v += eval(((Flowfor*)((Flow *)a)->cond)->v3)
                                    ){
                                        v =  eval(((Flow *)a)->tl);
                                }
                            } else {
                                if(auxl->prox == NULL)
                                    printf("\nErro no FOR: variavel nao numerica\n");
                                else
                                    auxl = auxl->prox;
                            }
                        }
                    }
                }
            break;
            // multiplas linhas de códigos em IF/ELSE/WHILE/FOR
            case 'L': eval(a->l); v = eval(a->r); break; /*Lista de operções em um bloco IF/ELSE/WHILE. Assim o analisador não se perde entre os blocos*/
            case 'l': v = eval(a->l); eval(a->r); break;
            case 'j': v = eval(a->l); return v; break;
            // print na tela
            case 'P':;
                //printf("P1\n");
                if(!a->l) {
                    if(!a->r)
                        printf("\n");
                    break;
                }
                //printf("P - %c\n", a->l->nodetype);
                if(a->l->nodetype == 'N') {
                    //a->l->nodetype = 'n';
                    //if(!lista)
                        //printf("lista null\n");
                    printValorVar(lista, ((Varval*)a->l)->var);
                    //printf("nodetype 'NN'\n");
                }
                else if(((Intval*)a->l)->nodetype == 'k')
                    printf ("%d", ((Intval*)a->l)->v);		/*Recupera um valor inteiro*/
                else if(((Realval*)a->l)->nodetype == 'K')
                    printf ("%.2f", ((Realval*)a->l)->v);		/*Recupera um valor real*/
                else if(((Textoval*)a->l)->nodetype == 'm') {
                    printf ("%s", ((Textoval*)a->l)->v);		/*Recupera um valor texto*/
                } else {
                    //printf("not 'NN'\n");
                    v = eval(a->l);
                    printf("%.2f", v);
                }
                    //printf("P5\n");
                    if(!a->r)
                        printf("\n");
                    else{
                        eval(a->r);
                    }
                    //printf("P7\n");
                    break;  /*Função que imprime um valor*/
            
            // declarar variavel inteiro
            case 'i':;
                if(((Symasgn *)a)->n)
                    eval(((Symasgn *)a)->n);
                if(!varexiste(lista, ((Symasgn *)a)->s)){
                    VARSI *ivar = insi(lista->ivar, ((Symasgn *)a)->s);
                    if(((Symasgn *)a)->v)
                        ivar->v = (int)eval(((Symasgn *)a)->v); /*Atribui à variável*/
                }else
                    printf("\nErro (case 'i'): variavel '%s' ja existe.\n", ((Symasgn *)a)->s);
                break;
            // declarar variavel real
            case 'r':;
                //printf("real begin\n");
                if(((Symasgn *)a)->n)
                    eval(((Symasgn *)a)->n);
                //printf("real 2: %d\n", varexiste(lista, ((Symasgn *)a)->s));
                if(!varexiste(lista, ((Symasgn *)a)->s)){
                    //printf("real 3\n");
                    
                    //printf("real 4 \n");
                    //printf("real 4.5 rvar->name = %s\n", rvar->name);
                    if(((Symasgn *)a)->v)
                        v = eval(((Symasgn *)a)->v);
                    
                    lista->rvar = ins(lista->rvar, ((Symasgn *)a)->s);
                    //printf("real 5\n");
                    lista->rvar->v = v;
                    //printf("real 6\n");
                }else
                    printf("\nErro (case 'r'): variavel '%s' ja existe.\n", ((Symasgn *)a)->s);
                //srch(lista->rvar, ((Symasgn *)a)->s)
                //printf("R real %s = %f\n", lista->rvar->name, lista->rvar->v);
                //printf("real end\n");
                break;
            // declarar variavel texto
            case 't':;
                if(((Symasgn *)a)->n)
                    eval(((Symasgn *)a)->n);
                if(!varexiste(lista, ((Symasgn *)a)->s)){
                    VARST *tvar = inst(lista->tvar, ((Symasgn *)a)->s);
                    if((((Symasgn *)a)->v))
                        strcpy(tvar->v, ((Textoval*)((Symasgn*)a)->v)->v);
                }else
                    printf("\nErro (case 't'): variavel '%s' ja existe.\n", ((Symasgn *)a)->s);
                break;
            
            // leitura das variaveis: int, real e texto
            case 'c':; 
                //v = eval(((Symasgn *)a)->v); /*Recupera o valor*/
                auxl = lista;
                while(auxl != NULL){
                    auxr = srch(auxl->rvar, ((Varval *)a->l)->var);
                    if(auxr){
                        scanf("%f", &auxr->v);
                    } else {
                        auxi = srchi(auxl->ivar, ((Varval *)a->l)->var);
                        if(auxi){
                            scanf("%d", &auxi->v);
                        } else {
                            auxt = srcht(auxl->tvar, ((Varval *)a->l)->var);
                            if(auxt){
                                scanf("%s", &auxt->v);
                            } else {
                                if(auxl->prox == NULL)
                                    printf("\nErro(<<): Variavel invalida!\n");
                                else
                                    auxl = auxl->prox;
                            }
                        }
                    }
                }
                break;
            case 'T':;
                // função TYPE(var)
                auxl = lista;
                while(auxl != NULL){
                    auxr = srch(auxl->rvar, ((Textoval *)a->l)->v);
                    if(auxr){
                        printf("Type(%s): real\n", ((Textoval *)a->l)->v);
                        break;
                    } else {
                        auxi = srchi(auxl->ivar, ((Textoval *)a->l)->v);
                        if(auxi){
                            printf("Type(%s): inteiro\n", ((Textoval *)a->l)->v);
                            break;
                        } else {
                            auxt = srcht(auxl->tvar, ((Textoval *)a->l)->v);
                            if(auxt){
                                printf("Type(%s): texto\n", ((Textoval *)a->l)->v);
                                break;
                            } else {
                                if(auxl->prox == NULL) {
                                    printf("\nErro(type): Variavel invalida!\n");
                                    break;
                                } else
                                    auxl = auxl->prox;
                            }
                        }
                    }
                }
                break;
            
            case 'V':;
                
                break;

            case 'B':;
                //printf("func %s\n", ((Func*)a)->name);
                
                if(srchfunction(lista->function, ((Func*)a)->name)==NULL){
                    lista->function = insfunction(lista->function, ((Func*)a));
                } else
                    printf("\nErro (case 'B'): reescrita de funcao nao permitida\n");
                //printf("tion %s\n", ((Func*)a)->name);
                break;
            
            case 'a':;
                auxl = lista;
                while(auxl != NULL){
                    auxf = srchfunctionall(auxl, ((Textoval*)a->l)->v);
                    //printf("auxf->name = %s\n", auxf->name);
                    if(auxf==NULL){
                        if(auxl->prox == NULL)
                            printf("\nErro (case 'a'): funcao nao declarada\n");
                        auxl = auxl->prox;
                        //printf("case 'a'\n");
                    } else {
                        //printf("function yes\n");
                        
                        Listavar * auxz = (Listavar*)malloc(sizeof(Listavar));
                        strcpy(auxz->name, auxf->name);
                        auxz->ivar = NULL;
                        auxz->rvar = NULL;
                        auxz->tvar = NULL;
                        auxz->ivec = NULL;
                        auxz->function = NULL;
                        auxz->prox = lista;
                        lista = auxz;
                        //printf("hum 22\n");
                        //strcpy(lista->name, auxf->name);
                        
                        //VARSI * i1 = ivar;
                        //VARS *r1 = rvar;
                        //VARST *t1 = tvar;

                        // verifica e executa as declarações e atribuições de ARGUMENTOS da função
                        if(auxf->args!=NULL && a->r!=NULL) {
                            Ast *b = auxf->args;
                            Ast *c = a->r;
                            while(c){
                                //printf("begin c\n");
                                eval(newvar(b->l->nodetype, ((Symasgn*)b->l)->s, c->l, NULL));
                                //eval(newast('P', newValorVal(((Symasgn*)b->l)->s), NULL));
                                if (b->r!=NULL && c->r!=NULL){
                                    b = b->r;
                                    c = c->r;
                                } else if(b->r==NULL && c->r==NULL){
                                    // fim de argumentos
                                    break;
                                } else {
                                    printf("\nErro (case 'a'): arg insuficientes ou excedente\n");
                                }
                            }
                            //printf("end c\n");
                        } else if(auxf->args==NULL && a->r==NULL) {
                            // função sem argumentos ok
                        } else {
                            printf("\nErro (case 'a'): chamada de funcao errada\n");
                            break;
                        }
                        // fim do bloco de ARGUMENTOS da função
                        //*/
                        // chama bloco de codigos dentro da função
                        //printf("hum 99\n");
                        if(auxf->v)
                            v = eval(auxf->v);
                        
                        // fim do bloco de codigos dentro da função
                        //printf("hum 7799\n");
                        auxl = lista;
                        lista = lista->prox;
                        free(auxl);
                        auxl = NULL;
                        break;
                    // excluindo as variaveis após o final da função
                    /*
                    {
                        VARSI * i2 = ivar;
                        VARS *r2 = rvar;
                        VARST *t2 = tvar;
                        VARSI * i3 = NULL;
                        VARS *r3 = NULL;
                        VARST *t3 = NULL;
                        if(i1!=NULL){
                            while(strcmp(i2->name, i1->name)!=0){
                                if(strcmp(i2->name, i1->name)==0){
                                    ivar = i2;
                                } else {
                                    i3 = i2;
                                    i2 = i2->prox;
                                    free(i3);
                                    i3 = NULL;
                                }
                            }
                        } else {
                            while(i2!=NULL){
                                i3 = i2;
                                i2 = i2->prox;
                                free(i3);
                                i3 = NULL;
                            }
                        }
                        if(i1!=NULL){
                            while(strcmp(i2->name, i1->name)!=0){
                                if(r1!=NULL){
                                    if(strcmp(r2->name, r1->name)==0){
                                        rvar = r2;
                                    } else {
                                        r3 = r2;
                                        r2 = r2->prox;
                                        free(r3);
                                        r3 = NULL;
                                    }
                                }
                            }
                        } else {
                            while(r2!=NULL){
                                r3 = r2;
                                r2 = r2->prox;
                                free(r3);
                                r3 = NULL;
                            }
                        }
                        if(i1!=NULL){
                            while(strcmp(i2->name, i1->name)!=0){
                                if(t1!=NULL){
                                    if(strcmp(t2->name, t1->name)==0){
                                        tvar = t2;
                                    } else {
                                        t3 = t2;
                                        t2 = t2->prox;
                                        free(t3);
                                        t3 = NULL;
                                    }
                                }
                            }
                        } else {
                            while(t2!=NULL){
                                t3 = t2;
                                t2 = t2->prox;
                                free(t3);
                                t3 = NULL;
                            }
                        }
                    }
                    //*/
                    // FIM da exclusão da variaveis internas da função
                    }
                } // end while
                break;

            case 'y':;
                lista = NULL;
                Listavar * g = (Listavar*)malloc(sizeof(Listavar));
                if(!g)
                    exit(1);
                strcpy(g->name, "main");
                g->rvar = NULL;
                g->ivar = NULL;
                g->tvar = NULL;
                g->ivec = NULL;
                g->function = NULL;
                g->prox = NULL;
                lista = g;
                break;

            case 'z':;
                printf("\n-> Fim do programa! <-\n\n");
                free(lista);
                lista = NULL;
                exit(0);
                break;

            default: printf("internal error: bad node %c\n", a->nodetype);
        }
        return v;
    }


#line 1241 "calc_exemplo_function.tab.c"

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
    TIPO = 258,                    /* TIPO  */
    TIPO_TEXTO = 259,              /* TIPO_TEXTO  */
    VOID = 260,                    /* VOID  */
    INTEIRO = 261,                 /* INTEIRO  */
    REAL = 262,                    /* REAL  */
    TEXTO = 263,                   /* TEXTO  */
    TYPE = 264,                    /* TYPE  */
    RETURN = 265,                  /* RETURN  */
    ENTRADA = 266,                 /* ENTRADA  */
    SAIDA = 267,                   /* SAIDA  */
    INICIO = 268,                  /* INICIO  */
    FINAL = 269,                   /* FINAL  */
    IF = 270,                      /* IF  */
    ELSE = 271,                    /* ELSE  */
    FOR = 272,                     /* FOR  */
    WHILE = 273,                   /* WHILE  */
    VAR = 274,                     /* VAR  */
    COMENTARIO = 275,              /* COMENTARIO  */
    RAIZ = 276,                    /* RAIZ  */
    COS = 277,                     /* COS  */
    SIN = 278,                     /* SIN  */
    PLUS = 279,                    /* PLUS  */
    LESS = 280,                    /* LESS  */
    OR = 281,                      /* OR  */
    AND = 282,                     /* AND  */
    MAIOR = 283,                   /* MAIOR  */
    MENOR = 284,                   /* MENOR  */
    MEI = 285,                     /* MEI  */
    MAI = 286,                     /* MAI  */
    II = 287,                      /* II  */
    DIF = 288,                     /* DIF  */
    NEG = 289,                     /* NEG  */
    PLUS2 = 290,                   /* PLUS2  */
    LESS2 = 291,                   /* LESS2  */
    FUN = 292,                     /* FUN  */
    FUN2 = 293,                    /* FUN2  */
    ITERATOR = 294,                /* ITERATOR  */
    VARP = 295,                    /* VARP  */
    IFX = 296                      /* IFX  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 1171 ".\\calc_exemplo_function.y"

    char texto[50];
    int inteiro;
    double real;
    Ast *a;

#line 1336 "calc_exemplo_function.tab.c"

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
  YYSYMBOL_TIPO = 3,                       /* TIPO  */
  YYSYMBOL_TIPO_TEXTO = 4,                 /* TIPO_TEXTO  */
  YYSYMBOL_VOID = 5,                       /* VOID  */
  YYSYMBOL_INTEIRO = 6,                    /* INTEIRO  */
  YYSYMBOL_REAL = 7,                       /* REAL  */
  YYSYMBOL_TEXTO = 8,                      /* TEXTO  */
  YYSYMBOL_TYPE = 9,                       /* TYPE  */
  YYSYMBOL_RETURN = 10,                    /* RETURN  */
  YYSYMBOL_ENTRADA = 11,                   /* ENTRADA  */
  YYSYMBOL_SAIDA = 12,                     /* SAIDA  */
  YYSYMBOL_INICIO = 13,                    /* INICIO  */
  YYSYMBOL_FINAL = 14,                     /* FINAL  */
  YYSYMBOL_IF = 15,                        /* IF  */
  YYSYMBOL_ELSE = 16,                      /* ELSE  */
  YYSYMBOL_FOR = 17,                       /* FOR  */
  YYSYMBOL_WHILE = 18,                     /* WHILE  */
  YYSYMBOL_VAR = 19,                       /* VAR  */
  YYSYMBOL_COMENTARIO = 20,                /* COMENTARIO  */
  YYSYMBOL_RAIZ = 21,                      /* RAIZ  */
  YYSYMBOL_COS = 22,                       /* COS  */
  YYSYMBOL_SIN = 23,                       /* SIN  */
  YYSYMBOL_PLUS = 24,                      /* PLUS  */
  YYSYMBOL_LESS = 25,                      /* LESS  */
  YYSYMBOL_OR = 26,                        /* OR  */
  YYSYMBOL_AND = 27,                       /* AND  */
  YYSYMBOL_MAIOR = 28,                     /* MAIOR  */
  YYSYMBOL_MENOR = 29,                     /* MENOR  */
  YYSYMBOL_MEI = 30,                       /* MEI  */
  YYSYMBOL_MAI = 31,                       /* MAI  */
  YYSYMBOL_II = 32,                        /* II  */
  YYSYMBOL_DIF = 33,                       /* DIF  */
  YYSYMBOL_34_ = 34,                       /* '='  */
  YYSYMBOL_NEG = 35,                       /* NEG  */
  YYSYMBOL_36_ = 36,                       /* '+'  */
  YYSYMBOL_37_ = 37,                       /* '-'  */
  YYSYMBOL_38_ = 38,                       /* '*'  */
  YYSYMBOL_39_ = 39,                       /* '/'  */
  YYSYMBOL_40_ = 40,                       /* '%'  */
  YYSYMBOL_41_ = 41,                       /* '^'  */
  YYSYMBOL_PLUS2 = 42,                     /* PLUS2  */
  YYSYMBOL_LESS2 = 43,                     /* LESS2  */
  YYSYMBOL_44_ = 44,                       /* ')'  */
  YYSYMBOL_45_ = 45,                       /* '('  */
  YYSYMBOL_FUN = 46,                       /* FUN  */
  YYSYMBOL_FUN2 = 47,                      /* FUN2  */
  YYSYMBOL_ITERATOR = 48,                  /* ITERATOR  */
  YYSYMBOL_VARP = 49,                      /* VARP  */
  YYSYMBOL_IFX = 50,                       /* IFX  */
  YYSYMBOL_51_ = 51,                       /* '{'  */
  YYSYMBOL_52_ = 52,                       /* '}'  */
  YYSYMBOL_53_ = 53,                       /* ','  */
  YYSYMBOL_54_ = 54,                       /* ';'  */
  YYSYMBOL_55_ = 55,                       /* '?'  */
  YYSYMBOL_56_ = 56,                       /* ':'  */
  YYSYMBOL_57_ = 57,                       /* '|'  */
  YYSYMBOL_YYACCEPT = 58,                  /* $accept  */
  YYSYMBOL_prog = 59,                      /* prog  */
  YYSYMBOL_inicio = 60,                    /* inicio  */
  YYSYMBOL_cod = 61,                       /* cod  */
  YYSYMBOL_atrib = 62,                     /* atrib  */
  YYSYMBOL_decl = 63,                      /* decl  */
  YYSYMBOL_declfunction = 64,              /* declfunction  */
  YYSYMBOL_declvar = 65,                   /* declvar  */
  YYSYMBOL_declvartexto = 66,              /* declvartexto  */
  YYSYMBOL_exp = 67,                       /* exp  */
  YYSYMBOL_outfunc = 68,                   /* outfunc  */
  YYSYMBOL_iterator = 69,                  /* iterator  */
  YYSYMBOL_args = 70,                      /* args  */
  YYSYMBOL_arg = 71,                       /* arg  */
  YYSYMBOL_saida = 72,                     /* saida  */
  YYSYMBOL_incdec = 73,                    /* incdec  */
  YYSYMBOL_list = 74,                      /* list  */
  YYSYMBOL_logica = 75,                    /* logica  */
  YYSYMBOL_arit = 76,                      /* arit  */
  YYSYMBOL_valor = 77,                     /* valor  */
  YYSYMBOL_varvar = 78                     /* varvar  */
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   650

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  187

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


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
       2,     2,     2,     2,     2,     2,     2,    40,     2,     2,
      45,    44,    38,    36,    53,    37,     2,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    56,    54,
       2,    34,     2,    55,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    41,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,    57,    52,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    35,
      42,    43,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,  1226,  1226,  1228,  1230,  1231,  1233,  1234,  1236,  1237,
    1239,  1240,  1241,  1242,  1244,  1245,  1246,  1247,  1249,  1250,
    1251,  1252,  1272,  1273,  1277,  1279,  1281,  1282,  1283,  1284,
    1285,  1286,  1288,  1289,  1291,  1292,  1293,  1294,  1295,  1297,
    1298,  1300,  1303,  1304,  1307,  1308,  1314,  1315,  1316,  1317,
    1318,  1319,  1322,  1323,  1327,  1328,  1330,  1331,  1332,  1333,
    1334,  1335,  1336,  1337,  1338,  1340,  1341,  1342,  1343,  1344,
    1345,  1346,  1347,  1348,  1349,  1350,  1351,  1352,  1355,  1356,
    1363,  1368,  1369,  1370
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
  "\"end of file\"", "error", "\"invalid token\"", "TIPO", "TIPO_TEXTO",
  "VOID", "INTEIRO", "REAL", "TEXTO", "TYPE", "RETURN", "ENTRADA", "SAIDA",
  "INICIO", "FINAL", "IF", "ELSE", "FOR", "WHILE", "VAR", "COMENTARIO",
  "RAIZ", "COS", "SIN", "PLUS", "LESS", "OR", "AND", "MAIOR", "MENOR",
  "MEI", "MAI", "II", "DIF", "'='", "NEG", "'+'", "'-'", "'*'", "'/'",
  "'%'", "'^'", "PLUS2", "LESS2", "')'", "'('", "FUN", "FUN2", "ITERATOR",
  "VARP", "IFX", "'{'", "'}'", "','", "';'", "'?'", "':'", "'|'",
  "$accept", "prog", "inicio", "cod", "atrib", "decl", "declfunction",
  "declvar", "declvartexto", "exp", "outfunc", "iterator", "args", "arg",
  "saida", "incdec", "list", "logica", "arit", "valor", "varvar", YY_NULLPTR
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
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,    61,   289,    43,    45,    42,    47,
      37,    94,   290,   291,    41,    40,   292,   293,   294,   295,
     296,   123,   125,    44,    59,    63,    58,   124
};
#endif

#define YYPACT_NINF (-86)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-84)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      15,   -86,    18,   439,   -86,     4,    16,    23,   -86,   -86,
      -1,   504,   458,   504,    10,   504,     9,   -86,     0,    12,
      28,   504,   504,   504,   105,   -86,   -86,    -6,    22,   -86,
     -86,   -86,   -86,   503,   202,   -86,     3,    43,    36,    34,
      38,   617,    35,    31,   -86,   -86,    40,   558,   572,    65,
      55,    41,   586,   -86,   -86,   -86,   464,     5,   -86,   504,
     504,   504,   202,   598,   189,   -86,   -86,    87,    88,   504,
     504,   504,   504,   504,   504,   504,   504,   439,   504,   504,
     504,   504,   504,   504,   504,     2,   108,     6,    69,     8,
     483,   483,   483,   439,    84,   504,   504,   439,   -86,   617,
     524,    77,    85,    93,   319,   332,   -86,   -86,   109,   111,
     392,   392,   -86,   -86,   -86,   -86,   -86,   -86,    83,    62,
     202,   106,   106,   106,   106,   617,   127,    98,   115,   -86,
     110,   116,   -86,   -86,   119,   -86,   -86,   -86,   -86,   179,
     504,   617,   125,   200,   542,    19,   -86,   -86,   -86,   504,
     156,   439,   113,   439,   117,   439,   118,   -86,   154,   -86,
     617,   504,   -86,   -86,   617,   -86,   -86,   168,   244,   439,
     265,   439,   121,   254,   -86,   -86,   309,   -86,   330,   439,
     439,   -86,   -86,   374,   395,   -86,   -86
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     3,     0,     0,     1,     0,     0,     0,    78,    79,
       0,     0,     0,     0,     0,     0,    81,    31,     0,     0,
       0,     0,     0,     0,     0,    22,     9,     8,    23,     5,
      37,    32,    36,     0,    64,    77,    17,    21,     0,     0,
      81,    38,    48,    81,    34,    33,    50,    46,     0,     0,
       0,     0,     0,    26,    52,    53,     0,     0,    80,     0,
       0,     0,    68,     0,     0,     2,     4,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    25,    24,
      40,     0,    44,     0,     0,     0,    76,    69,    14,    18,
      56,    57,    58,    59,    63,    62,    61,    60,     0,    70,
      71,    72,    73,    74,    75,    16,     0,     0,     0,    20,
       0,     0,    35,    83,     0,    49,    51,    47,    54,     0,
       0,     6,     0,     0,    39,     0,    67,    66,    65,     0,
       0,     0,    42,     0,     0,     0,     0,    82,    27,    55,
       7,     0,    29,    45,    15,    19,    41,     0,     0,     0,
       0,     0,     0,     0,    43,    11,     0,    13,     0,     0,
       0,    10,    12,     0,     0,    28,    30
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,    -3,
     -86,   -86,   -85,   -73,   -60,     7,   -75,    -5,   -20,   -53,
     -86
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    24,    51,    25,    26,    27,    28,   138,
      30,    31,   128,   101,    45,    32,   139,    33,    34,    35,
      58
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      29,    62,   131,    64,   102,   126,    41,    47,    48,   126,
      52,     8,     9,    49,     8,     9,   134,    63,     4,    46,
      53,    66,   143,    36,    40,     8,     9,    40,     1,    50,
     135,   136,   137,    54,    55,    37,   102,    84,    40,   103,
     104,   105,    38,    56,    39,    59,   127,    67,    85,   100,
     130,    99,   133,    88,    57,    54,    55,    60,   119,   120,
     121,   122,   123,   124,   110,   111,   112,   113,   114,   115,
     116,   117,   163,    61,   118,    68,    89,    86,   168,   125,
     170,    87,   174,    89,    94,    47,    47,    47,    90,    95,
     141,   142,   102,    91,   176,    96,   178,    46,    46,    46,
      80,    81,    82,    83,   183,   184,   108,   109,     5,     6,
       7,     8,     9,   132,    10,    11,   129,    12,   140,    65,
      13,   144,    14,    15,    16,    17,    18,    19,    20,    78,
      79,    80,    81,    82,    83,   160,   159,   146,   145,   151,
     159,   173,    21,   149,   164,   150,   152,    83,   166,   153,
      22,    69,    70,    71,    72,    73,    74,    75,    76,   154,
     156,   155,    23,   157,   165,   159,   167,   159,   169,   171,
     172,   126,   179,   159,     0,   159,     0,     0,     0,   161,
     159,   159,     5,     6,     7,     8,     9,     0,    10,    11,
       0,    12,     0,     0,    13,     0,    14,    15,    16,    17,
      18,    19,    20,     5,     6,     7,     8,     9,     0,    10,
      11,     0,    12,     0,     0,    13,    21,    14,    15,    16,
      17,    18,    19,    20,    22,    78,    79,    80,    81,    82,
      83,   158,     0,     0,     0,     0,    23,    21,    78,    79,
      80,    81,    82,    83,     0,    22,   107,     5,     6,     7,
       8,     9,   162,    10,    11,     0,    12,    23,     0,    13,
       0,    14,    15,    16,    17,    18,    19,    20,     5,     6,
       7,     8,     9,     0,    10,    11,     0,    12,     0,     0,
      13,    21,    14,    15,    16,    17,    18,    19,    20,    22,
      78,    79,    80,    81,    82,    83,   175,     0,     0,     0,
       0,    23,    21,     0,     0,   180,     0,     0,     0,     0,
      22,     0,     5,     6,     7,     8,     9,   177,    10,    11,
       0,    12,    23,     0,    13,     0,    14,    15,    16,    17,
      18,    19,    20,     5,     6,     7,     8,     9,     0,    10,
      11,     0,    12,     0,     0,    13,    21,    14,    15,    16,
      17,    18,    19,    20,    22,    78,    79,    80,    81,    82,
      83,   181,     0,   147,     0,     0,    23,    21,    78,    79,
      80,    81,    82,    83,     0,    22,   148,     5,     6,     7,
       8,     9,   182,    10,    11,     0,    12,    23,     0,    13,
       0,    14,    15,    16,    17,    18,    19,    20,     5,     6,
       7,     8,     9,     0,    10,    11,     0,    12,     0,     0,
      13,    21,    14,    15,    16,    17,    18,    19,    20,    22,
      71,    72,    73,    74,    75,    76,   185,     0,     0,     0,
       0,    23,    21,     0,     0,     0,     0,     0,     0,     0,
      22,     0,     5,     6,     7,     8,     9,   186,    10,    11,
       0,    12,    23,     0,    13,     0,    14,    15,    16,    17,
      18,    19,    20,     0,     8,     9,    42,     0,     0,     0,
       8,     9,    98,     0,     0,     0,    21,    43,     0,    18,
      19,    20,     0,    40,    22,    18,    19,    20,     0,     8,
       9,    42,     0,     0,     0,    21,    23,     0,     0,     0,
       0,    21,    43,    22,    18,    19,    20,     0,     0,    22,
       8,     9,    44,     0,     0,    23,     0,     0,     0,     0,
      21,    23,     0,    40,     0,    18,    19,    20,    22,    69,
      70,    71,    72,    73,    74,    75,    76,     0,     0,     0,
      23,    21,     0,     0,     0,     0,     0,     0,     0,    22,
     -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,    77,     0,
     -83,    23,   -83,   -83,   -83,   -83,     0,     0,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,     0,     0,   -82,   -83,
     -82,   -82,   -82,   -82,    69,    70,    71,    72,    73,    74,
      75,    76,     0,     0,     0,     0,     0,   -82,    69,    70,
      71,    72,    73,    74,    75,    76,     0,     0,     0,     0,
       0,    92,    69,    70,    71,    72,    73,    74,    75,    76,
       0,     0,     0,    93,    69,    70,    71,    72,    73,    74,
      75,    76,     0,     0,     0,     0,     0,    97,     0,     0,
       0,     0,   106,    69,    70,    71,    72,    73,    74,    75,
      76
};

static const yytype_int16 yycheck[] =
{
       3,    21,    87,    23,    57,     3,    11,    12,    13,     3,
      15,     6,     7,     3,     6,     7,    89,    22,     0,    12,
      11,    24,    97,    19,    19,     6,     7,    19,    13,    19,
      90,    91,    92,    24,    25,    19,    89,    34,    19,    59,
      60,    61,    19,    34,    45,    45,    44,    53,    45,    44,
      44,    56,    44,    19,    45,    24,    25,    45,    78,    79,
      80,    81,    82,    83,    69,    70,    71,    72,    73,    74,
      75,    76,   145,    45,    77,    53,    45,    34,   153,    84,
     155,    45,   167,    45,    19,    90,    91,    92,    53,    34,
      95,    96,   145,    53,   169,    54,   171,    90,    91,    92,
      38,    39,    40,    41,   179,   180,    19,    19,     3,     4,
       5,     6,     7,    44,     9,    10,     8,    12,    34,    14,
      15,    44,    17,    18,    19,    20,    21,    22,    23,    36,
      37,    38,    39,    40,    41,   140,   139,    44,    53,    56,
     143,   161,    37,    34,   149,    34,    19,    41,   151,    51,
      45,    26,    27,    28,    29,    30,    31,    32,    33,    44,
      44,    51,    57,    44,     8,   168,    53,   170,    51,    51,
      16,     3,    51,   176,    -1,   178,    -1,    -1,    -1,    54,
     183,   184,     3,     4,     5,     6,     7,    -1,     9,    10,
      -1,    12,    -1,    -1,    15,    -1,    17,    18,    19,    20,
      21,    22,    23,     3,     4,     5,     6,     7,    -1,     9,
      10,    -1,    12,    -1,    -1,    15,    37,    17,    18,    19,
      20,    21,    22,    23,    45,    36,    37,    38,    39,    40,
      41,    52,    -1,    -1,    -1,    -1,    57,    37,    36,    37,
      38,    39,    40,    41,    -1,    45,    57,     3,     4,     5,
       6,     7,    52,     9,    10,    -1,    12,    57,    -1,    15,
      -1,    17,    18,    19,    20,    21,    22,    23,     3,     4,
       5,     6,     7,    -1,     9,    10,    -1,    12,    -1,    -1,
      15,    37,    17,    18,    19,    20,    21,    22,    23,    45,
      36,    37,    38,    39,    40,    41,    52,    -1,    -1,    -1,
      -1,    57,    37,    -1,    -1,    51,    -1,    -1,    -1,    -1,
      45,    -1,     3,     4,     5,     6,     7,    52,     9,    10,
      -1,    12,    57,    -1,    15,    -1,    17,    18,    19,    20,
      21,    22,    23,     3,     4,     5,     6,     7,    -1,     9,
      10,    -1,    12,    -1,    -1,    15,    37,    17,    18,    19,
      20,    21,    22,    23,    45,    36,    37,    38,    39,    40,
      41,    52,    -1,    44,    -1,    -1,    57,    37,    36,    37,
      38,    39,    40,    41,    -1,    45,    44,     3,     4,     5,
       6,     7,    52,     9,    10,    -1,    12,    57,    -1,    15,
      -1,    17,    18,    19,    20,    21,    22,    23,     3,     4,
       5,     6,     7,    -1,     9,    10,    -1,    12,    -1,    -1,
      15,    37,    17,    18,    19,    20,    21,    22,    23,    45,
      28,    29,    30,    31,    32,    33,    52,    -1,    -1,    -1,
      -1,    57,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    -1,     3,     4,     5,     6,     7,    52,     9,    10,
      -1,    12,    57,    -1,    15,    -1,    17,    18,    19,    20,
      21,    22,    23,    -1,     6,     7,     8,    -1,    -1,    -1,
       6,     7,     8,    -1,    -1,    -1,    37,    19,    -1,    21,
      22,    23,    -1,    19,    45,    21,    22,    23,    -1,     6,
       7,     8,    -1,    -1,    -1,    37,    57,    -1,    -1,    -1,
      -1,    37,    19,    45,    21,    22,    23,    -1,    -1,    45,
       6,     7,    54,    -1,    -1,    57,    -1,    -1,    -1,    -1,
      37,    57,    -1,    19,    -1,    21,    22,    23,    45,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      57,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      26,    27,    28,    29,    30,    31,    32,    33,    55,    -1,
      36,    57,    38,    39,    40,    41,    -1,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    -1,    36,    55,
      38,    39,    40,    41,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,    55,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      -1,    53,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    51,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,
      -1,    -1,    44,    26,    27,    28,    29,    30,    31,    32,
      33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    13,    59,    60,     0,     3,     4,     5,     6,     7,
       9,    10,    12,    15,    17,    18,    19,    20,    21,    22,
      23,    37,    45,    57,    61,    63,    64,    65,    66,    67,
      68,    69,    73,    75,    76,    77,    19,    19,    19,    45,
      19,    75,     8,    19,    54,    72,    73,    75,    75,     3,
      19,    62,    75,    11,    24,    25,    34,    45,    78,    45,
      45,    45,    76,    75,    76,    14,    67,    53,    53,    26,
      27,    28,    29,    30,    31,    32,    33,    55,    36,    37,
      38,    39,    40,    41,    34,    45,    34,    45,    19,    45,
      53,    53,    53,    51,    19,    34,    54,    51,     8,    75,
      44,    71,    77,    76,    76,    76,    44,    57,    19,    19,
      75,    75,    75,    75,    75,    75,    75,    75,    67,    76,
      76,    76,    76,    76,    76,    75,     3,    44,    70,     8,
      44,    70,    44,    44,    71,    72,    72,    72,    67,    74,
      34,    75,    75,    74,    44,    53,    44,    44,    44,    34,
      34,    56,    19,    51,    44,    51,    44,    44,    52,    67,
      75,    54,    52,    71,    75,     8,    67,    53,    74,    51,
      74,    51,    16,    76,    70,    52,    74,    52,    74,    51,
      51,    52,    52,    74,    74,    52,    52
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    59,    60,    61,    61,    62,    62,    63,    63,
      64,    64,    64,    64,    65,    65,    65,    65,    66,    66,
      66,    66,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    68,
      68,    69,    70,    70,    71,    71,    72,    72,    72,    72,
      72,    72,    73,    73,    74,    74,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    77,    77,
      77,    78,    78,    78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     1,     2,     1,     3,     4,     1,     1,
       8,     7,     8,     7,     3,     5,     4,     2,     3,     5,
       4,     2,     1,     1,     3,     3,     2,     5,     9,     5,
       9,     1,     1,     2,     2,     4,     1,     1,     2,     4,
       3,     5,     2,     4,     1,     3,     1,     3,     1,     3,
       1,     3,     2,     2,     1,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     4,     4,     4,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       2,     0,     3,     2
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
  case 2: /* prog: inicio cod FINAL  */
#line 1226 ".\\calc_exemplo_function.y"
                       {eval(newast('z', NULL, NULL));}
#line 2601 "calc_exemplo_function.tab.c"
    break;

  case 3: /* inicio: INICIO  */
#line 1228 ".\\calc_exemplo_function.y"
               {eval(newast('y', NULL, NULL));}
#line 2607 "calc_exemplo_function.tab.c"
    break;

  case 4: /* cod: cod exp  */
#line 1230 ".\\calc_exemplo_function.y"
             {eval((yyvsp[0].a));}
#line 2613 "calc_exemplo_function.tab.c"
    break;

  case 5: /* cod: exp  */
#line 1231 ".\\calc_exemplo_function.y"
          {eval((yyvsp[0].a));}
#line 2619 "calc_exemplo_function.tab.c"
    break;

  case 6: /* atrib: VAR '=' logica  */
#line 1233 ".\\calc_exemplo_function.y"
                      {(yyval.a) = newasgn((yyvsp[-2].texto), (yyvsp[0].a));}
#line 2625 "calc_exemplo_function.tab.c"
    break;

  case 7: /* atrib: TIPO VAR '=' logica  */
#line 1234 ".\\calc_exemplo_function.y"
                          {(yyval.a) = newvar((yyvsp[-3].inteiro), (yyvsp[-2].texto), (yyvsp[0].a), NULL);}
#line 2631 "calc_exemplo_function.tab.c"
    break;

  case 8: /* decl: declvar  */
#line 1236 ".\\calc_exemplo_function.y"
              {(yyval.a) = (yyvsp[0].a);}
#line 2637 "calc_exemplo_function.tab.c"
    break;

  case 9: /* decl: declfunction  */
#line 1237 ".\\calc_exemplo_function.y"
                   {(yyval.a) = (yyvsp[0].a);}
#line 2643 "calc_exemplo_function.tab.c"
    break;

  case 10: /* declfunction: TIPO VAR '(' args ')' '{' list '}'  */
#line 1239 ".\\calc_exemplo_function.y"
                                                           {(yyval.a) = newfunction((yyvsp[-7].inteiro), (yyvsp[-6].texto), (yyvsp[-4].a), (yyvsp[-1].a));}
#line 2649 "calc_exemplo_function.tab.c"
    break;

  case 11: /* declfunction: TIPO VAR '(' ')' '{' list '}'  */
#line 1240 ".\\calc_exemplo_function.y"
                                              {(yyval.a) = newfunction((yyvsp[-6].inteiro), (yyvsp[-5].texto), NULL, (yyvsp[-1].a));}
#line 2655 "calc_exemplo_function.tab.c"
    break;

  case 12: /* declfunction: VOID VAR '(' args ')' '{' list '}'  */
#line 1241 ".\\calc_exemplo_function.y"
                                         {(yyval.a) = newfunction((yyvsp[-7].inteiro), (yyvsp[-6].texto), (yyvsp[-4].a), (yyvsp[-1].a));}
#line 2661 "calc_exemplo_function.tab.c"
    break;

  case 13: /* declfunction: VOID VAR '(' ')' '{' list '}'  */
#line 1242 ".\\calc_exemplo_function.y"
                                              {(yyval.a) = newfunction((yyvsp[-6].inteiro), (yyvsp[-5].texto), NULL, (yyvsp[-1].a));}
#line 2667 "calc_exemplo_function.tab.c"
    break;

  case 14: /* declvar: declvar ',' VAR  */
#line 1244 ".\\calc_exemplo_function.y"
                         {(yyval.a) = newvar((yyvsp[-2].a)->nodetype, (yyvsp[0].texto), NULL, (yyvsp[-2].a));}
#line 2673 "calc_exemplo_function.tab.c"
    break;

  case 15: /* declvar: declvar ',' VAR '=' logica  */
#line 1245 ".\\calc_exemplo_function.y"
                                 {(yyval.a) = newvar((yyvsp[-4].a)->nodetype, (yyvsp[-2].texto), (yyvsp[0].a), (yyvsp[-4].a));}
#line 2679 "calc_exemplo_function.tab.c"
    break;

  case 16: /* declvar: TIPO VAR '=' logica  */
#line 1246 ".\\calc_exemplo_function.y"
                                      {(yyval.a) = newvar((yyvsp[-3].inteiro), (yyvsp[-2].texto), (yyvsp[0].a), NULL);}
#line 2685 "calc_exemplo_function.tab.c"
    break;

  case 17: /* declvar: TIPO VAR  */
#line 1247 ".\\calc_exemplo_function.y"
                           {(yyval.a) = newvar((yyvsp[-1].inteiro), (yyvsp[0].texto), NULL, NULL);}
#line 2691 "calc_exemplo_function.tab.c"
    break;

  case 18: /* declvartexto: declvartexto ',' VAR  */
#line 1249 ".\\calc_exemplo_function.y"
                                   {(yyval.a) = newvar((yyvsp[-2].a)->nodetype, (yyvsp[0].texto), NULL, (yyvsp[-2].a));}
#line 2697 "calc_exemplo_function.tab.c"
    break;

  case 19: /* declvartexto: declvartexto ',' VAR '=' TEXTO  */
#line 1250 ".\\calc_exemplo_function.y"
                                     {(yyval.a) = newvar((yyvsp[-4].a)->nodetype, (yyvsp[-2].texto), newtexto((yyvsp[0].texto)), (yyvsp[-4].a));}
#line 2703 "calc_exemplo_function.tab.c"
    break;

  case 20: /* declvartexto: TIPO_TEXTO VAR '=' TEXTO  */
#line 1251 ".\\calc_exemplo_function.y"
                               {(yyval.a) = newvar((yyvsp[-3].inteiro), (yyvsp[-2].texto), newtexto((yyvsp[0].texto)), NULL);}
#line 2709 "calc_exemplo_function.tab.c"
    break;

  case 21: /* declvartexto: TIPO_TEXTO VAR  */
#line 1252 ".\\calc_exemplo_function.y"
                     {(yyval.a) = newvar((yyvsp[-1].inteiro), (yyvsp[0].texto), NULL, NULL);}
#line 2715 "calc_exemplo_function.tab.c"
    break;

  case 22: /* exp: decl  */
#line 1272 ".\\calc_exemplo_function.y"
          {(yyval.a) = (yyvsp[0].a);}
#line 2721 "calc_exemplo_function.tab.c"
    break;

  case 23: /* exp: declvartexto  */
#line 1273 ".\\calc_exemplo_function.y"
                   {(yyval.a) = (yyvsp[0].a);}
#line 2727 "calc_exemplo_function.tab.c"
    break;

  case 24: /* exp: VAR '=' logica  */
#line 1277 ".\\calc_exemplo_function.y"
                                {(yyval.a) = newasgn((yyvsp[-2].texto), (yyvsp[0].a));}
#line 2733 "calc_exemplo_function.tab.c"
    break;

  case 25: /* exp: VAR '=' TEXTO  */
#line 1279 ".\\calc_exemplo_function.y"
                    {(yyval.a) = newasgn((yyvsp[-2].texto), newtexto((yyvsp[0].texto)));}
#line 2739 "calc_exemplo_function.tab.c"
    break;

  case 26: /* exp: VAR ENTRADA  */
#line 1281 ".\\calc_exemplo_function.y"
                  {(yyval.a) = newast('c', newValorVal((yyvsp[-1].texto)), NULL);}
#line 2745 "calc_exemplo_function.tab.c"
    break;

  case 27: /* exp: IF logica '{' list '}'  */
#line 1282 ".\\calc_exemplo_function.y"
                                       {(yyval.a) = newflow('I', (yyvsp[-3].a), (yyvsp[-1].a), NULL);}
#line 2751 "calc_exemplo_function.tab.c"
    break;

  case 28: /* exp: IF logica '{' list '}' ELSE '{' list '}'  */
#line 1283 ".\\calc_exemplo_function.y"
                                                   {(yyval.a) = newflow('I', (yyvsp[-7].a), (yyvsp[-5].a), (yyvsp[-1].a));}
#line 2757 "calc_exemplo_function.tab.c"
    break;

  case 29: /* exp: WHILE logica '{' list '}'  */
#line 1284 ".\\calc_exemplo_function.y"
                                    {(yyval.a) = newflow('W', (yyvsp[-3].a), (yyvsp[-1].a), NULL);}
#line 2763 "calc_exemplo_function.tab.c"
    break;

  case 30: /* exp: FOR atrib ';' logica ';' arit '{' list '}'  */
#line 1285 ".\\calc_exemplo_function.y"
                                                 {(yyval.a) = newflowfor('F', (yyvsp[-7].a), (yyvsp[-5].a), (yyvsp[-3].a), (yyvsp[-1].a), NULL);}
#line 2769 "calc_exemplo_function.tab.c"
    break;

  case 31: /* exp: COMENTARIO  */
#line 1286 ".\\calc_exemplo_function.y"
                 {(yyval.a) = newast('P', NULL, newtexto((yyvsp[0].texto)));}
#line 2775 "calc_exemplo_function.tab.c"
    break;

  case 32: /* exp: iterator  */
#line 1288 ".\\calc_exemplo_function.y"
               {(yyval.a) = (yyvsp[0].a);}
#line 2781 "calc_exemplo_function.tab.c"
    break;

  case 33: /* exp: SAIDA saida  */
#line 1289 ".\\calc_exemplo_function.y"
                            {(yyval.a) = (yyvsp[0].a);}
#line 2787 "calc_exemplo_function.tab.c"
    break;

  case 34: /* exp: SAIDA ';'  */
#line 1291 ".\\calc_exemplo_function.y"
                { (yyval.a) = newast('P', NULL, NULL);}
#line 2793 "calc_exemplo_function.tab.c"
    break;

  case 35: /* exp: TYPE '(' VAR ')'  */
#line 1292 ".\\calc_exemplo_function.y"
                       {(yyval.a) = newast('T', newtexto((yyvsp[-1].texto)), NULL);}
#line 2799 "calc_exemplo_function.tab.c"
    break;

  case 36: /* exp: incdec  */
#line 1293 ".\\calc_exemplo_function.y"
             {(yyval.a) = (yyvsp[0].a);}
#line 2805 "calc_exemplo_function.tab.c"
    break;

  case 37: /* exp: outfunc  */
#line 1294 ".\\calc_exemplo_function.y"
              {(yyval.a) = (yyvsp[0].a);}
#line 2811 "calc_exemplo_function.tab.c"
    break;

  case 38: /* exp: RETURN logica  */
#line 1295 ".\\calc_exemplo_function.y"
                    {(yyval.a) = newast('j', (yyvsp[0].a), NULL);}
#line 2817 "calc_exemplo_function.tab.c"
    break;

  case 39: /* outfunc: VAR '(' arg ')'  */
#line 1297 ".\\calc_exemplo_function.y"
                                   {(yyval.a) = newast('a', newtexto((yyvsp[-3].texto)), (yyvsp[-1].a));}
#line 2823 "calc_exemplo_function.tab.c"
    break;

  case 40: /* outfunc: VAR '(' ')'  */
#line 1298 ".\\calc_exemplo_function.y"
                             {(yyval.a) = newast('a', newtexto((yyvsp[-2].texto)), NULL);}
#line 2829 "calc_exemplo_function.tab.c"
    break;

  case 41: /* iterator: logica '?' exp ':' exp  */
#line 1300 ".\\calc_exemplo_function.y"
                                                {(yyval.a) = newflow('?', (yyvsp[-4].a), (yyvsp[-2].a), (yyvsp[0].a));}
#line 2835 "calc_exemplo_function.tab.c"
    break;

  case 42: /* args: TIPO VAR  */
#line 1303 ".\\calc_exemplo_function.y"
               {(yyval.a) = newast('l', newvar((yyvsp[-1].inteiro), (yyvsp[0].texto), NULL, NULL), NULL);}
#line 2841 "calc_exemplo_function.tab.c"
    break;

  case 43: /* args: TIPO VAR ',' args  */
#line 1304 ".\\calc_exemplo_function.y"
                        {(yyval.a) = newast('l', newvar((yyvsp[-3].inteiro), (yyvsp[-2].texto), NULL, NULL), (yyvsp[0].a));}
#line 2847 "calc_exemplo_function.tab.c"
    break;

  case 44: /* arg: valor  */
#line 1307 ".\\calc_exemplo_function.y"
           {(yyval.a) = newast('l', (yyvsp[0].a), NULL);}
#line 2853 "calc_exemplo_function.tab.c"
    break;

  case 45: /* arg: valor ',' arg  */
#line 1308 ".\\calc_exemplo_function.y"
                    {(yyval.a) = newast('l', (yyvsp[-2].a), (yyvsp[0].a));}
#line 2859 "calc_exemplo_function.tab.c"
    break;

  case 46: /* saida: logica  */
#line 1314 ".\\calc_exemplo_function.y"
              {(yyval.a) = newast('P', (yyvsp[0].a), NULL);}
#line 2865 "calc_exemplo_function.tab.c"
    break;

  case 47: /* saida: logica ',' saida  */
#line 1315 ".\\calc_exemplo_function.y"
                       { (yyval.a) = newast('P', (yyvsp[-2].a), (yyvsp[0].a));}
#line 2871 "calc_exemplo_function.tab.c"
    break;

  case 48: /* saida: TEXTO  */
#line 1316 ".\\calc_exemplo_function.y"
            {(yyval.a) = newast('P', newtexto((yyvsp[0].texto)), NULL);}
#line 2877 "calc_exemplo_function.tab.c"
    break;

  case 49: /* saida: TEXTO ',' saida  */
#line 1317 ".\\calc_exemplo_function.y"
                      {(yyval.a) = newast('P', newtexto((yyvsp[-2].texto)), (yyvsp[0].a));}
#line 2883 "calc_exemplo_function.tab.c"
    break;

  case 50: /* saida: incdec  */
#line 1318 ".\\calc_exemplo_function.y"
             {(yyval.a) = newast('P', (yyvsp[0].a), NULL);}
#line 2889 "calc_exemplo_function.tab.c"
    break;

  case 51: /* saida: incdec ',' saida  */
#line 1319 ".\\calc_exemplo_function.y"
                       { (yyval.a) = newast('P', (yyvsp[-2].a), (yyvsp[0].a));}
#line 2895 "calc_exemplo_function.tab.c"
    break;

  case 52: /* incdec: VAR PLUS  */
#line 1322 ".\\calc_exemplo_function.y"
                             {(yyval.a) = newasgn((yyvsp[-1].texto), newast('+',newValorVal((yyvsp[-1].texto)),newint(1)));}
#line 2901 "calc_exemplo_function.tab.c"
    break;

  case 53: /* incdec: VAR LESS  */
#line 1323 ".\\calc_exemplo_function.y"
                           {(yyval.a) = newasgn((yyvsp[-1].texto), newast('-',newValorVal((yyvsp[-1].texto)),newint(1)));}
#line 2907 "calc_exemplo_function.tab.c"
    break;

  case 54: /* list: exp  */
#line 1327 ".\\calc_exemplo_function.y"
          {(yyval.a) = (yyvsp[0].a);}
#line 2913 "calc_exemplo_function.tab.c"
    break;

  case 55: /* list: list exp  */
#line 1328 ".\\calc_exemplo_function.y"
               { (yyval.a) = newast('L', (yyvsp[-1].a), (yyvsp[0].a));}
#line 2919 "calc_exemplo_function.tab.c"
    break;

  case 56: /* logica: logica OR logica  */
#line 1330 ".\\calc_exemplo_function.y"
                         {(yyval.a) = newcmp(7,(yyvsp[-2].a),(yyvsp[0].a));}
#line 2925 "calc_exemplo_function.tab.c"
    break;

  case 57: /* logica: logica AND logica  */
#line 1331 ".\\calc_exemplo_function.y"
                        {(yyval.a) = newcmp(8,(yyvsp[-2].a),(yyvsp[0].a));}
#line 2931 "calc_exemplo_function.tab.c"
    break;

  case 58: /* logica: logica MAIOR logica  */
#line 1332 ".\\calc_exemplo_function.y"
                          {(yyval.a) = newcmp(1,(yyvsp[-2].a),(yyvsp[0].a));}
#line 2937 "calc_exemplo_function.tab.c"
    break;

  case 59: /* logica: logica MENOR logica  */
#line 1333 ".\\calc_exemplo_function.y"
                          {(yyval.a) = newcmp(2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 2943 "calc_exemplo_function.tab.c"
    break;

  case 60: /* logica: logica DIF logica  */
#line 1334 ".\\calc_exemplo_function.y"
                        {(yyval.a) = newcmp(3,(yyvsp[-2].a),(yyvsp[0].a));}
#line 2949 "calc_exemplo_function.tab.c"
    break;

  case 61: /* logica: logica II logica  */
#line 1335 ".\\calc_exemplo_function.y"
                       {(yyval.a) = newcmp(4,(yyvsp[-2].a),(yyvsp[0].a));}
#line 2955 "calc_exemplo_function.tab.c"
    break;

  case 62: /* logica: logica MAI logica  */
#line 1336 ".\\calc_exemplo_function.y"
                        {(yyval.a) = newcmp(5,(yyvsp[-2].a),(yyvsp[0].a));}
#line 2961 "calc_exemplo_function.tab.c"
    break;

  case 63: /* logica: logica MEI logica  */
#line 1337 ".\\calc_exemplo_function.y"
                        {(yyval.a) = newcmp(6,(yyvsp[-2].a),(yyvsp[0].a));}
#line 2967 "calc_exemplo_function.tab.c"
    break;

  case 64: /* logica: arit  */
#line 1338 ".\\calc_exemplo_function.y"
           {(yyval.a) = (yyvsp[0].a);}
#line 2973 "calc_exemplo_function.tab.c"
    break;

  case 65: /* arit: SIN '(' arit ')'  */
#line 1340 ".\\calc_exemplo_function.y"
                       {(yyval.a) = newast('S',(yyvsp[-1].a),NULL);}
#line 2979 "calc_exemplo_function.tab.c"
    break;

  case 66: /* arit: COS '(' arit ')'  */
#line 1341 ".\\calc_exemplo_function.y"
                       {(yyval.a) = newast('C',(yyvsp[-1].a),NULL);}
#line 2985 "calc_exemplo_function.tab.c"
    break;

  case 67: /* arit: RAIZ '(' arit ')'  */
#line 1342 ".\\calc_exemplo_function.y"
                        {(yyval.a) = newast('R',(yyvsp[-1].a),NULL);}
#line 2991 "calc_exemplo_function.tab.c"
    break;

  case 68: /* arit: '-' arit  */
#line 1343 ".\\calc_exemplo_function.y"
                         {(yyval.a) = newast('M', (yyvsp[0].a), NULL);}
#line 2997 "calc_exemplo_function.tab.c"
    break;

  case 69: /* arit: '|' arit '|'  */
#line 1344 ".\\calc_exemplo_function.y"
                   {(yyval.a) = newast('A',(yyvsp[-1].a),NULL);}
#line 3003 "calc_exemplo_function.tab.c"
    break;

  case 70: /* arit: arit '+' arit  */
#line 1345 ".\\calc_exemplo_function.y"
                    {(yyval.a) = newast('+',(yyvsp[-2].a),(yyvsp[0].a));}
#line 3009 "calc_exemplo_function.tab.c"
    break;

  case 71: /* arit: arit '-' arit  */
#line 1346 ".\\calc_exemplo_function.y"
                              {(yyval.a) = newast('-',(yyvsp[-2].a),(yyvsp[0].a));}
#line 3015 "calc_exemplo_function.tab.c"
    break;

  case 72: /* arit: arit '*' arit  */
#line 1347 ".\\calc_exemplo_function.y"
                    {(yyval.a) = newast('*',(yyvsp[-2].a),(yyvsp[0].a));}
#line 3021 "calc_exemplo_function.tab.c"
    break;

  case 73: /* arit: arit '/' arit  */
#line 1348 ".\\calc_exemplo_function.y"
                    {(yyval.a) = newast('/',(yyvsp[-2].a),(yyvsp[0].a));}
#line 3027 "calc_exemplo_function.tab.c"
    break;

  case 74: /* arit: arit '%' arit  */
#line 1349 ".\\calc_exemplo_function.y"
                    {(yyval.a) = newast('%',(yyvsp[-2].a),(yyvsp[0].a));}
#line 3033 "calc_exemplo_function.tab.c"
    break;

  case 75: /* arit: arit '^' arit  */
#line 1350 ".\\calc_exemplo_function.y"
                    {(yyval.a) = newast('^',(yyvsp[-2].a),(yyvsp[0].a));}
#line 3039 "calc_exemplo_function.tab.c"
    break;

  case 76: /* arit: '(' logica ')'  */
#line 1351 ".\\calc_exemplo_function.y"
                     {(yyval.a) = (yyvsp[-1].a);}
#line 3045 "calc_exemplo_function.tab.c"
    break;

  case 77: /* arit: valor  */
#line 1352 ".\\calc_exemplo_function.y"
            {(yyval.a) = (yyvsp[0].a);}
#line 3051 "calc_exemplo_function.tab.c"
    break;

  case 78: /* valor: INTEIRO  */
#line 1355 ".\\calc_exemplo_function.y"
               {(yyval.a) = newint((yyvsp[0].inteiro));}
#line 3057 "calc_exemplo_function.tab.c"
    break;

  case 79: /* valor: REAL  */
#line 1356 ".\\calc_exemplo_function.y"
           {(yyval.a) = newreal((yyvsp[0].real));}
#line 3063 "calc_exemplo_function.tab.c"
    break;

  case 80: /* valor: VAR varvar  */
#line 1363 ".\\calc_exemplo_function.y"
                 {
        if((yyvsp[0].a)==NULL) (yyval.a) = newValorVal((yyvsp[-1].texto));
        else (yyval.a) = newast('a', newtexto((yyvsp[-1].texto)), (yyvsp[0].a)->r);
    }
#line 3072 "calc_exemplo_function.tab.c"
    break;

  case 81: /* varvar: %empty  */
#line 1368 ".\\calc_exemplo_function.y"
        {(yyval.a) = NULL;}
#line 3078 "calc_exemplo_function.tab.c"
    break;

  case 82: /* varvar: '(' arg ')'  */
#line 1369 ".\\calc_exemplo_function.y"
                  {(yyval.a) = newast('j', NULL, (yyvsp[-1].a));}
#line 3084 "calc_exemplo_function.tab.c"
    break;

  case 83: /* varvar: '(' ')'  */
#line 1370 ".\\calc_exemplo_function.y"
              {(yyval.a) = newast('j', NULL, NULL);}
#line 3090 "calc_exemplo_function.tab.c"
    break;


#line 3094 "calc_exemplo_function.tab.c"

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

#line 1372 ".\\calc_exemplo_function.y"


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
