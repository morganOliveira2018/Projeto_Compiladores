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

%}

%union{
    char texto[50];
    int inteiro;
    double real;
    Ast *a;
}

//DECLARAÇÃO DE TOKENS
%token <inteiro> TIPO TIPO_TEXTO VOID
%token <inteiro> INTEIRO
%token <real> REAL
%token <texto> TEXTO
%token <texto> TYPE RETURN
%token ENTRADA
%token SAIDA
%token INICIO
%token FINAL
%token IF ELSE FOR WHILE
%token <texto> VAR
%token <texto> COMENTARIO
//TOKENS DE ARITMETICA
%token RAIZ COS SIN
//TOKENS DE LOGICA
//%token MAIOR MENOR MEI MAI II DIF OR AND
%token <texto> PLUS LESS

//DECLARAÇÃO DE TIPO DE NÃO-TERMINAIS
%type <a> declvartexto
%type <a> exp declvar atrib list saida incdec args arg //valorvec declvecmult
%type <a> logica
%type <a> arit
%type <a> valor decl declfunction outfunc
%type <a> iterator inicio varvar

//DECLARAÇÃO DE PRECEDÊNCIA
//%precedence ITERATOR
%left OR AND
%left MAIOR MENOR MEI MAI II DIF
%right '='
%nonassoc NEG
%left '+' '-'
%left '*' '/' '%'
%right '^'
//%precedence NEG
//%left PLUS1 LESS1
%right PLUS2 LESS2
%left ')'
%right '('

%nonassoc FUN FUN2 ITERATOR
%nonassoc VARP IFX 

%start prog
%%

prog: inicio cod FINAL {eval(newast('z', NULL, NULL));}
    ;
inicio: INICIO {eval(newast('y', NULL, NULL));}
    ;
cod: cod exp {eval($2);}
    | exp {eval($1);}
    ;
atrib: VAR '=' logica {$$ = newasgn($1, $3);}
    | TIPO VAR '=' logica {$$ = newvar($1, $2, $4, NULL);}
    ;
decl: declvar {$$ = $1;}
    | declfunction {$$ = $1;}
    ;
declfunction: TIPO VAR '(' args ')' '{' list '}' %prec FUN {$$ = newfunction($1, $2, $4, $7);}
    | TIPO VAR '(' ')' '{' list '}' %prec FUN {$$ = newfunction($1, $2, NULL, $6);}
    | VOID VAR '(' args ')' '{' list '}' {$$ = newfunction($1, $2, $4, $7);}
    | VOID VAR '(' ')' '{' list '}' %prec FUN {$$ = newfunction($1, $2, NULL, $6);}
    ;
declvar: declvar ',' VAR {$$ = newvar($1->nodetype, $3, NULL, $1);}
    | declvar ',' VAR '=' logica {$$ = newvar($1->nodetype, $3, $5, $1);}
    | TIPO VAR '=' logica %prec LESS2 {$$ = newvar($1, $2, $4, NULL);}
    | TIPO VAR %prec LESS2 {$$ = newvar($1, $2, NULL, NULL);}
    ;
declvartexto: declvartexto ',' VAR {$$ = newvar($1->nodetype, $3, NULL, $1);}
    | declvartexto ',' VAR '=' TEXTO {$$ = newvar($1->nodetype, $3, newtexto($5), $1);}
    | TIPO_TEXTO VAR '=' TEXTO {$$ = newvar($1, $2, newtexto($4), NULL);}
    | TIPO_TEXTO VAR {$$ = newvar($1, $2, NULL, NULL);}
    ;

    // [1, 2, 3]
    // n1(v, 1, (2, 3) )
    // n2(v, 2, 3)
/*
valorvec: logica ',' valorvec {$$ = newast('l', $1, $3);}
    | logica {$$ = newast('l', $1, NULL);}
    ;
declvecmult: TIPO VAR '['']' '=' '[' valorvec ']' {$$ = newvec('V', $2, $7, NULL);}
    | TIPO VAR '['']' {$$ = newvec('V', $2, NULL, NULL);}
    | declvecmult ',' VAR '['']' {$$ = newvec($1->nodetype, $3, NULL, $1);}
    | declvecmult ',' VAR '['']' '=' '[' logica ']' {$$ = newvec($1->nodetype, $3, $8, $1);}
    ;
//*/
//varvar: VAR '(' arg ')' %prec FUN {$$ = newast('a', newtexto($1), $3);}
    //| logica {$$ = $1;}
    ;

exp: decl {$$ = $1;}
    | declvartexto {$$ = $1;}
    //| declvecmult {$$ = $1;}
    //| SAIDA VAR '[' logica ']' {$$ = newast('v', newtexto($2), $4);}
    //| VAR '=' VAR '(' arg ')' %prec FUN {$$ = newasgn($1, newast('a', newtexto($3), $5));}
    | VAR '=' logica %prec VARP {$$ = newasgn($1, $3);}
    //| VAR '=' varvar %prec VARP {$$ = newasgn($1, $3);}
    | VAR '=' TEXTO {$$ = newasgn($1, newtexto($3));} 
    //| TIPO VAR '=' TEXTO {$$ = newvar($1, $2, newtexto($4), NULL);}
    | VAR ENTRADA {$$ = newast('c', newValorVal($1), NULL);}
    | IF logica '{' list '}' %prec IFX {$$ = newflow('I', $2, $4, NULL);}
	| IF logica '{' list '}' ELSE '{' list '}' {$$ = newflow('I', $2, $4, $8);}
	| WHILE logica '{' list '}' {$$ = newflow('W', $2, $4, NULL);}
    | FOR atrib ';' logica ';' arit '{' list '}' {$$ = newflowfor('F', $2, $4, $6, $8, NULL);}
    | COMENTARIO {$$ = newast('P', NULL, newtexto($1));}
    //| logica {$$ = newast('P', $1, NULL);}
    | iterator {$$ = $1;}
    | SAIDA saida %prec FUN {$$ = $2;}
    //| SAIDA outfunc {$$ = $2;}
    | SAIDA ';' { $$ = newast('P', NULL, NULL);} 
    | TYPE '(' VAR ')' {$$ = newast('T', newtexto($3), NULL);}
    | incdec {$$ = $1;}
    | outfunc {$$ = $1;}
    | RETURN logica {$$ = newast('j', $2, NULL);}
    ;
outfunc: VAR '(' arg ')' %prec FUN {$$ = newast('a', newtexto($1), $3);}
    | VAR '(' ')' %prec FUN2 {$$ = newast('a', newtexto($1), NULL);}
    ; 
iterator: logica '?' exp ':' exp %prec ITERATOR {$$ = newflow('?', $1, $3, $5);}
    ;
//*
args: TIPO VAR {$$ = newast('l', newvar($1, $2, NULL, NULL), NULL);}
    | TIPO VAR ',' args {$$ = newast('l', newvar($1, $2, NULL, NULL), $4);}
    //| %empty {$$ = NULL;}
    ;
arg: valor {$$ = newast('l', $1, NULL);}
    | valor ',' arg {$$ = newast('l', $1, $3);}
    //| %empty {$$ = NULL;}
    ;
//*/
    // >> 'autor: ', nome , 'valor: ' , x
    // SAIDA saida( texto , saida( logica, saida( texto, saida( logica, NULL ) ) ) )
saida: logica {$$ = newast('P', $1, NULL);}
    | logica ',' saida { $$ = newast('P', $1, $3);}
    | TEXTO {$$ = newast('P', newtexto($1), NULL);}
    | TEXTO ',' saida {$$ = newast('P', newtexto($1), $3);}
    | incdec {$$ = newast('P', $1, NULL);}
    | incdec ',' saida { $$ = newast('P', $1, $3);}
    //| VAR '(' arg ')' %prec FUN {$$ = newast('P', newast('a', newtexto($1), $3), NULL);}
    ;
incdec: VAR PLUS %prec PLUS2 {$$ = newasgn($1, newast('+',newValorVal($1),newint(1)));}
    | VAR LESS %prec LESS2 {$$ = newasgn($1, newast('-',newValorVal($1),newint(1)));}
    //| PLUS VAR %prec PLUS1 {$$ = newast('l', newValorVal($2), newasgn($2, newast('+', newValorVal($2), newint(1))));}
    //| LESS VAR %prec LESS1 {$$ = newast('l', newValorVal($2), newasgn($2, newast('-', newValorVal($2), newint(1))));}
    ;
list: exp {$$ = $1;}
    | list exp { $$ = newast('L', $1, $2);}
    ;
logica: logica OR logica {$$ = newcmp(7,$1,$3);}
    | logica AND logica {$$ = newcmp(8,$1,$3);}
    | logica MAIOR logica {$$ = newcmp(1,$1,$3);}
    | logica MENOR logica {$$ = newcmp(2,$1,$3);}
    | logica DIF logica {$$ = newcmp(3,$1,$3);}
    | logica II logica {$$ = newcmp(4,$1,$3);}
    | logica MAI logica {$$ = newcmp(5,$1,$3);}
    | logica MEI logica {$$ = newcmp(6,$1,$3);}
    | arit {$$ = $1;}
    ;
arit: SIN '(' arit ')' {$$ = newast('S',$3,NULL);}
    | COS '(' arit ')' {$$ = newast('C',$3,NULL);}
    | RAIZ '(' arit ')' {$$ = newast('R',$3,NULL);}
    | '-' arit %prec NEG {$$ = newast('M', $2, NULL);}
    | '|' arit '|' {$$ = newast('A',$2,NULL);}
    | arit '+' arit {$$ = newast('+',$1,$3);}
    | arit '-' arit %prec NEG {$$ = newast('-',$1,$3);}
    | arit '*' arit {$$ = newast('*',$1,$3);}
    | arit '/' arit {$$ = newast('/',$1,$3);}
    | arit '%' arit {$$ = newast('%',$1,$3);}
    | arit '^' arit {$$ = newast('^',$1,$3);}
    | '(' logica ')' {$$ = $2;}
    | valor {$$ = $1;}
    ;

valor: INTEIRO {$$ = newint($1);}    // codigo 'k'
    | REAL {$$ = newreal($1);}      // codigo 'K'
    //| '-' REAL {$$ = newast('M', newreal($2), NULL);}      // codigo 'K'
    //| TEXTO {$$ = newtexto($1);}    // codigo 'm'
    //| incdec {$$ = $1;}
    //| VAR {$$ = newValorVal($1);}   // codigo 'N'
    //| VAR '(' arg ')' {$$ = newast('a', newtexto($1), $3);}
    //| VAR '(' ')' %prec FUN2 {$$ = newast('a', newtexto($1), NULL);}
    | VAR varvar {
        if($2==NULL) $$ = newValorVal($1);
        else $$ = newast('a', newtexto($1), $2->r);
    }
    ;
varvar: {$$ = NULL;}
    | '(' arg ')' {$$ = newast('j', NULL, $2);}
    | '(' ')' {$$ = newast('j', NULL, NULL);}
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