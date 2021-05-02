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

#line 210 "calc_morgana.tab.c"

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
    STRING = 261,                  /* STRING  */
    LOGICO = 262,                  /* LOGICO  */
    TIPO_REAL = 263,               /* TIPO_REAL  */
    TIPO_INT = 264,                /* TIPO_INT  */
    TIPO_TEXT = 265,               /* TIPO_TEXT  */
    INICIO = 266,                  /* INICIO  */
    FINAL = 267,                   /* FINAL  */
    RAIZ = 268,                    /* RAIZ  */
    ATRIB = 269,                   /* ATRIB  */
    LEITURA = 270,                 /* LEITURA  */
    ESCREVER = 271,                /* ESCREVER  */
    COMENTARIO = 272,              /* COMENTARIO  */
    UMINUS = 273                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 140 "calc_morgana.y"

    char texto[50];
    double real;
    int inteiro;

#line 281 "calc_morgana.tab.c"

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
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_LOGICO = 7,                     /* LOGICO  */
  YYSYMBOL_TIPO_REAL = 8,                  /* TIPO_REAL  */
  YYSYMBOL_TIPO_INT = 9,                   /* TIPO_INT  */
  YYSYMBOL_TIPO_TEXT = 10,                 /* TIPO_TEXT  */
  YYSYMBOL_INICIO = 11,                    /* INICIO  */
  YYSYMBOL_FINAL = 12,                     /* FINAL  */
  YYSYMBOL_RAIZ = 13,                      /* RAIZ  */
  YYSYMBOL_ATRIB = 14,                     /* ATRIB  */
  YYSYMBOL_LEITURA = 15,                   /* LEITURA  */
  YYSYMBOL_ESCREVER = 16,                  /* ESCREVER  */
  YYSYMBOL_COMENTARIO = 17,                /* COMENTARIO  */
  YYSYMBOL_18_ = 18,                       /* '+'  */
  YYSYMBOL_19_ = 19,                       /* '-'  */
  YYSYMBOL_20_ = 20,                       /* '*'  */
  YYSYMBOL_21_ = 21,                       /* '/'  */
  YYSYMBOL_22_ = 22,                       /* '^'  */
  YYSYMBOL_23_ = 23,                       /* ')'  */
  YYSYMBOL_24_ = 24,                       /* '('  */
  YYSYMBOL_25_ = 25,                       /* '|'  */
  YYSYMBOL_UMINUS = 26,                    /* UMINUS  */
  YYSYMBOL_27_ = 27,                       /* ','  */
  YYSYMBOL_YYACCEPT = 28,                  /* $accept  */
  YYSYMBOL_begin = 29,                     /* begin  */
  YYSYMBOL_var = 30,                       /* var  */
  YYSYMBOL_variacoes = 31,                 /* variacoes  */
  YYSYMBOL_variacoes2 = 32,                /* variacoes2  */
  YYSYMBOL_variacoesi = 33,                /* variacoesi  */
  YYSYMBOL_variacoesi2 = 34,               /* variacoesi2  */
  YYSYMBOL_variacoet = 35,                 /* variacoet  */
  YYSYMBOL_variacoet1 = 36,                /* variacoet1  */
  YYSYMBOL_ini = 37,                       /* ini  */
  YYSYMBOL_cod = 38,                       /* cod  */
  YYSYMBOL_input_output = 39,              /* input_output  */
  YYSYMBOL_expre = 40,                     /* expre  */
  YYSYMBOL_valor = 41,                     /* valor  */
  YYSYMBOL_logico = 42                     /* logico  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   124

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  28
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  45
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  84

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   273


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
      24,    23,    20,    18,    27,    19,     2,    21,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    22,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    25,     2,     2,     2,     2,     2,
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
      15,    16,    17,    26
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   178,   178,   178,   181,   183,   185,   190,   193,   197,
     209,   233,   237,   241,   253,   278,   281,   285,   296,   320,
     323,   323,   327,   329,   332,   335,   387,   405,   408,   411,
     419,   423,   427,   431,   435,   439,   443,   446,   450,   453,
     457,   470,   473,   478,   479,   522
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
  "VARIAVEL", "STRING", "LOGICO", "TIPO_REAL", "TIPO_INT", "TIPO_TEXT",
  "INICIO", "FINAL", "RAIZ", "ATRIB", "LEITURA", "ESCREVER", "COMENTARIO",
  "'+'", "'-'", "'*'", "'/'", "'^'", "')'", "'('", "'|'", "UMINUS", "','",
  "$accept", "begin", "var", "variacoes", "variacoes2", "variacoesi",
  "variacoesi2", "variacoet", "variacoet1", "ini", "cod", "input_output",
  "expre", "valor", "logico", YY_NULLPTR
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
     265,   266,   267,   268,   269,   270,   271,   272,    43,    45,
      42,    47,    94,    41,    40,   124,   273,    44
};
#endif

#define YYPACT_NINF (-35)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-46)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      26,     6,     7,    12,   -35,    18,    26,   -35,     8,    -7,
     -35,    13,    -6,   -35,    14,     5,   -35,    41,   -35,   -35,
      58,     6,    58,     7,    42,    12,   -35,   -35,    33,   -35,
      28,    31,    35,   -35,    58,    65,    58,   -35,   -35,    73,
     -35,    57,   -35,    58,    96,   -35,    96,   -35,   -35,   -35,
      58,    58,    62,     0,   -35,    78,     3,    54,    58,    58,
      58,    58,    58,    65,    78,    96,    84,    63,    64,    90,
     -35,   -35,   -35,   -13,   -13,    59,    59,    59,    96,    57,
     -35,   -35,   -35,   -35
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,    21,     0,     0,     3,     9,     4,
       8,    13,     5,    12,    17,     6,    16,     0,     1,     2,
       0,     0,     0,     0,     0,     0,    41,    42,    40,    19,
       0,     0,     0,    27,     0,     0,     0,    22,    20,    28,
      39,    29,    40,     0,    10,     7,    14,    11,    18,    15,
       0,     0,     0,     0,    38,    45,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     0,     0,     0,     0,
      36,    43,    35,    31,    32,    33,    34,    37,    45,    44,
      30,    25,    23,    24
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -35,    79,    71,   -35,    98,   -35,    97,   -35,    99,   -35,
     -35,   -35,   -20,   -35,   -34
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     9,    10,    12,    13,    15,    16,     7,
      17,    38,    39,    40,    41
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      44,    56,    46,    26,    27,    42,    68,    60,    61,    62,
      63,     8,    11,    30,    54,    55,    57,    14,    18,    34,
      21,    23,    20,    64,    43,    36,    71,    22,    24,    79,
      65,    66,    25,    69,     1,     2,     3,     4,    73,    74,
      75,    76,    77,    78,    26,    27,    28,    50,    48,     1,
       2,     3,    51,    29,    30,    52,    31,    32,    33,    53,
      34,    26,    27,    42,    63,    35,    36,    67,    26,    27,
      42,    30,    58,    59,    60,    61,    62,    34,    30,    72,
     -45,    62,    43,    36,    34,    19,    81,    82,    37,    35,
      36,    58,    59,    60,    61,    62,    58,    59,    60,    61,
      62,    70,    58,    59,    60,    61,    62,    80,    58,    59,
      60,    61,    62,    83,    58,    59,    60,    61,    62,    45,
      47,     0,     0,     0,    49
};

static const yytype_int8 yycheck[] =
{
      20,    35,    22,     3,     4,     5,     6,    20,    21,    22,
       7,     5,     5,    13,    34,    35,    36,     5,     0,    19,
      27,    27,    14,    43,    24,    25,    23,    14,    14,    63,
      50,    51,    27,    53,     8,     9,    10,    11,    58,    59,
      60,    61,    62,    63,     3,     4,     5,    14,     6,     8,
       9,    10,    24,    12,    13,    24,    15,    16,    17,    24,
      19,     3,     4,     5,     7,    24,    25,     5,     3,     4,
       5,    13,    18,    19,    20,    21,    22,    19,    13,    25,
       7,    22,    24,    25,    19,     6,    23,    23,    17,    24,
      25,    18,    19,    20,    21,    22,    18,    19,    20,    21,
      22,    23,    18,    19,    20,    21,    22,    23,    18,    19,
      20,    21,    22,    23,    18,    19,    20,    21,    22,    21,
      23,    -1,    -1,    -1,    25
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,     9,    10,    11,    29,    30,    37,     5,    31,
      32,     5,    33,    34,     5,    35,    36,    38,     0,    29,
      14,    27,    14,    27,    14,    27,     3,     4,     5,    12,
      13,    15,    16,    17,    19,    24,    25,    30,    39,    40,
      41,    42,     5,    24,    40,    32,    40,    34,     6,    36,
      14,    24,    24,    24,    40,    40,    42,    40,    18,    19,
      20,    21,    22,     7,    40,    40,    40,     5,     6,    40,
      23,    23,    25,    40,    40,    40,    40,    40,    40,    42,
      23,    23,    23,    23
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    28,    29,    29,    30,    30,    30,    31,    31,    32,
      32,    33,    33,    34,    34,    35,    35,    36,    36,    37,
      38,    38,    39,    39,    39,    39,    39,    39,    39,    39,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      41,    41,    41,    42,    42,    42
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     2,     2,     2,     3,     1,     1,
       3,     3,     1,     1,     3,     3,     1,     1,     3,     3,
       2,     0,     1,     4,     4,     4,     3,     1,     1,     1,
       4,     3,     3,     3,     3,     3,     3,     3,     2,     1,
       1,     1,     1,     3,     3,     1
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
  case 4: /* var: TIPO_REAL variacoes  */
#line 182 "calc_morgana.y"
    { printf("Declara %s: %s\n", (yyvsp[-1].texto), (yyvsp[0].texto));}
#line 1352 "calc_morgana.tab.c"
    break;

  case 5: /* var: TIPO_INT variacoesi  */
#line 184 "calc_morgana.y"
    { printf("Declara %s: %s\n", (yyvsp[-1].texto), (yyvsp[0].texto)); }
#line 1358 "calc_morgana.tab.c"
    break;

  case 6: /* var: TIPO_TEXT variacoet  */
#line 186 "calc_morgana.y"
    {printf("Declara %s: %s\n", (yyvsp[-1].texto), (yyvsp[0].texto));}
#line 1364 "calc_morgana.tab.c"
    break;

  case 7: /* variacoes: variacoes ',' variacoes2  */
#line 190 "calc_morgana.y"
                                    { 
          sprintf((yyval.texto), "%s, %s", (yyvsp[-2].texto), (yyvsp[0].texto)); 
        }
#line 1372 "calc_morgana.tab.c"
    break;

  case 8: /* variacoes: variacoes2  */
#line 193 "calc_morgana.y"
                     { sprintf((yyval.texto), "%s", (yyvsp[0].texto)); }
#line 1378 "calc_morgana.tab.c"
    break;

  case 9: /* variacoes2: VARIAVEL  */
#line 197 "calc_morgana.y"
                     {            
            VARS * aux = srch(rvar, (yyvsp[0].texto));
            if (aux == NULL){
                // Se ainda nao existe variavel com esse nome, se cria uma
                rvar = ins(rvar, (yyvsp[0].texto));
                sprintf((yyval.texto), "%s", (yyvsp[0].texto));
            }
            else{
                // Se já existe variavel com esse no, informar mensagem de erro
                printf ("A variável '%s' já existe.\n", (yyvsp[0].texto));
            }
        }
#line 1395 "calc_morgana.tab.c"
    break;

  case 10: /* variacoes2: VARIAVEL ATRIB expre  */
#line 209 "calc_morgana.y"
                               {
            VARS * aux = srch(rvar, (yyvsp[-2].texto));
            if (aux == NULL){
                // Se ainda nao existe variavel com esse nome, se cria uma
                rvar = ins(rvar, (yyvsp[-2].texto));
            
                VARS * aux2 = srch(rvar, (yyvsp[-2].texto));
                if (aux2 == NULL){
                    printf ("Variavel '%s' ainda nao declarada.\n", (yyvsp[-2].texto));
                }
                else {
                    // Atribuindo valor a variavel criada
                    aux2->value = (yyvsp[0].real);
                    sprintf((yyval.texto), "%s << %f", (yyvsp[-2].texto), (yyvsp[0].real));
                }
            }
            else{
                // Se já existe variavel com esse no, informar mensagem de erro
                printf ("A variavel '%s' ja existe.\n", (yyvsp[-2].texto));
            }
        }
#line 1421 "calc_morgana.tab.c"
    break;

  case 11: /* variacoesi: variacoesi ',' variacoesi2  */
#line 234 "calc_morgana.y"
        {
          sprintf((yyval.texto), "%s, %s", (yyvsp[-2].texto), (yyvsp[0].texto)); 
        }
#line 1429 "calc_morgana.tab.c"
    break;

  case 12: /* variacoesi: variacoesi2  */
#line 237 "calc_morgana.y"
                      {sprintf((yyval.texto), "%s", (yyvsp[0].texto)); }
#line 1435 "calc_morgana.tab.c"
    break;

  case 13: /* variacoesi2: VARIAVEL  */
#line 241 "calc_morgana.y"
                      {            
            VARSI * aux = srchi(ivar, (yyvsp[0].texto));
            if (aux == NULL){
                // Se ainda nao existe variavel com esse nome, se cria uma
                ivar = insi(ivar, (yyvsp[0].texto));
                sprintf((yyval.texto), "%s", (yyvsp[0].texto));
            }
            else{
                // Se já existe variavel com esse no, informar mensagem de erro
                printf ("A variável '%s' já existe.\n", (yyvsp[0].texto));
            }
        }
#line 1452 "calc_morgana.tab.c"
    break;

  case 14: /* variacoesi2: VARIAVEL ATRIB expre  */
#line 253 "calc_morgana.y"
                               {
            VARSI * aux = srchi(ivar, (yyvsp[-2].texto));
            if (aux == NULL){
                // Se ainda nao existe variavel com esse nome, se cria uma
                ivar = insi(ivar, (yyvsp[-2].texto));
            
                VARSI * aux2 = srchi(ivar, (yyvsp[-2].texto));
                if (aux2 == NULL){
                    printf ("Variavel '%s' ainda nao declarada.\n", (yyvsp[-2].texto));
                }
                else {
                    // Atribuindo valor a variavel criada
                    aux2->value = (yyvsp[0].real);
                    sprintf((yyval.texto), "%s << %d", (yyvsp[-2].texto), (yyvsp[0].real));
                }
            }
            else{
                // Se já existe variavel com esse no, informar mensagem de erro
                printf ("A variavel '%s' ja existe.\n", (yyvsp[-2].texto));
            }
        }
#line 1478 "calc_morgana.tab.c"
    break;

  case 15: /* variacoet: variacoet ',' variacoet1  */
#line 278 "calc_morgana.y"
                                    { 
            sprintf((yyval.texto), "%s, %s", (yyvsp[-2].texto), (yyvsp[0].texto));
        }
#line 1486 "calc_morgana.tab.c"
    break;

  case 16: /* variacoet: variacoet1  */
#line 281 "calc_morgana.y"
                     { sprintf((yyval.texto), "%s", (yyvsp[0].texto)); }
#line 1492 "calc_morgana.tab.c"
    break;

  case 17: /* variacoet1: VARIAVEL  */
#line 285 "calc_morgana.y"
                     {            
            VARTS * aux = srcht(tvar, (yyvsp[0].texto));
                if (aux == NULL){
                // Se ainda nao existe variavel com esse nome, se cria uma
                tvar = inst(tvar, (yyvsp[0].texto));
                sprintf((yyval.texto), "%s", (yyvsp[0].texto));
            }else{
                // Se já existe variavel com esse no, informar mensagem de erro
                printf ("A variável '%s' já existe.\n", (yyvsp[0].texto));
            }
        }
#line 1508 "calc_morgana.tab.c"
    break;

  case 18: /* variacoet1: VARIAVEL ATRIB STRING  */
#line 296 "calc_morgana.y"
                                {
            // Atribuição da variavel do tipo TEXTO
            VARTS * aux = srcht(tvar, (yyvsp[-2].texto));
            if (aux == NULL){
                // Se ainda nao existe variavel com esse nome, se cria uma
                tvar = inst(tvar, (yyvsp[-2].texto));
            
               VARTS * aux2 = srcht(tvar, (yyvsp[-2].texto));
                if(aux2 == NULL){
                printf("Variavel '%s' ainda nao declarada.\n", (yyvsp[-2].texto));
                }
                else{
                //Atribuindo valor a variavel criada
                sprintf(aux2->value, "%s", (yyvsp[0].texto));
                sprintf((yyval.texto), "%s << %s", (yyvsp[-2].texto), (yyvsp[0].texto));
                }
            }
            else{
                // Se já existe variavel com esse no, informar mensagem de erro
                printf ("A variavel '%s' ja existe.\n", (yyvsp[-2].texto));
            }
        }
#line 1535 "calc_morgana.tab.c"
    break;

  case 19: /* ini: INICIO cod FINAL  */
#line 320 "calc_morgana.y"
                      { printf("PROGRAMA FINALIZADO COM SUCESSO!\n"); }
#line 1541 "calc_morgana.tab.c"
    break;

  case 23: /* input_output: ESCREVER '(' STRING ')'  */
#line 329 "calc_morgana.y"
                            {
        printf("%s\n", (yyvsp[-1].texto));
    }
#line 1549 "calc_morgana.tab.c"
    break;

  case 24: /* input_output: ESCREVER '(' expre ')'  */
#line 332 "calc_morgana.y"
                           {
        printf("%.1f\n", (yyvsp[-1].real));
    }
#line 1557 "calc_morgana.tab.c"
    break;

  case 25: /* input_output: LEITURA '(' VARIAVEL ')'  */
#line 335 "calc_morgana.y"
                             {
        VARS * aux = srch(rvar, (yyvsp[-1].texto));
        if (aux == NULL){
            // se nao existe variavel declarada real
            VARSI * aux2 = srchi(ivar, (yyvsp[-1].texto));
            if (aux2 == NULL){
                // se nao existe variavel declarada inteiro
                printf ("Variavel '%s' ainda nao foi declarada\n", (yyvsp[-1].texto));
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
                        printf ("Valor '%s' deve ser inteiro\n", (yyvsp[-1].texto));
                }while( is_int(test)==false );
                
                aux2->value = atoi(test);
                printf("Valor do token de LEITURA: %d\n", aux2->value);
                printf("leia(%s)\n",(yyvsp[-1].texto));
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
                    printf ("Valor '%s' deve ser real\n", (yyvsp[-1].texto));
                
            }while( is_real(test)==false );
            
            aux->value = atof(test);
            printf("Valor do token de LEITURA: %f\n", aux->value);
            printf("leia(%s)\n",(yyvsp[-1].texto));
            //sprintf($$, "%s << %f", $1, $3);
        }
    }
#line 1614 "calc_morgana.tab.c"
    break;

  case 26: /* input_output: VARIAVEL ATRIB expre  */
#line 387 "calc_morgana.y"
                         {
        // atribuição de variavel
        VARS * aux = srch(rvar, (yyvsp[-2].texto));
        if (aux == NULL){
            // se nao existe variavel declarada real
            VARSI * aux2 = srchi(ivar, (yyvsp[-2].texto));
            if (aux2 == NULL)
                // se nao existe variavel declarada inteiro, mensagem de erro
                printf ("Variável '%s' não foi declarada\n", (yyvsp[-2].texto));
            else {
                aux2->value = (yyvsp[0].real);
            }
        } else {
            aux->value = (yyvsp[0].real);
            //printf("%.2f\n", aux->value);
            //sprintf($$, "%s << %f", $1, $3); -> input_output has not
        }
    }
#line 1637 "calc_morgana.tab.c"
    break;

  case 27: /* input_output: COMENTARIO  */
#line 405 "calc_morgana.y"
                 {
        printf("Comentario: %s\n", (yyvsp[0].texto));
    }
#line 1645 "calc_morgana.tab.c"
    break;

  case 28: /* input_output: expre  */
#line 408 "calc_morgana.y"
            {
        printf("Valor: %f\n", (yyvsp[0].real));
    }
#line 1653 "calc_morgana.tab.c"
    break;

  case 29: /* input_output: logico  */
#line 411 "calc_morgana.y"
             {
        printf("Logico: %f\n", (yyvsp[0].real));
    }
#line 1661 "calc_morgana.tab.c"
    break;

  case 30: /* expre: RAIZ '(' expre ')'  */
#line 419 "calc_morgana.y"
                       { 
        (yyval.real) = sqrt((yyvsp[-1].real)); 
        /* printf("Efetuando raiz(%f):\n", $3);*/
    }
#line 1670 "calc_morgana.tab.c"
    break;

  case 31: /* expre: expre '+' expre  */
#line 423 "calc_morgana.y"
                      {
        (yyval.real) = (yyvsp[-2].real) + (yyvsp[0].real);
        /* printf("%.1f + %.1f = %.1f\n", $1, $3, $$);*/
    }
#line 1679 "calc_morgana.tab.c"
    break;

  case 32: /* expre: expre '-' expre  */
#line 427 "calc_morgana.y"
                      {
        (yyval.real) = (yyvsp[-2].real) - (yyvsp[0].real);
        /* printf("%.1f - %.1f = %.1f\n", $1, $3, $$); */
    }
#line 1688 "calc_morgana.tab.c"
    break;

  case 33: /* expre: expre '*' expre  */
#line 431 "calc_morgana.y"
                      {
        (yyval.real) = (yyvsp[-2].real) * (yyvsp[0].real);
        /* printf("%.1f * %.1f = %.1f\n", $1, $3, $$); */
    }
#line 1697 "calc_morgana.tab.c"
    break;

  case 34: /* expre: expre '/' expre  */
#line 435 "calc_morgana.y"
                      {
        (yyval.real) = (yyvsp[-2].real) / (yyvsp[0].real);
        /* printf("%.1f / %.1f = %.1f\n", $1, $3, $$); */
    }
#line 1706 "calc_morgana.tab.c"
    break;

  case 35: /* expre: '|' expre '|'  */
#line 439 "calc_morgana.y"
                    {
        (yyval.real) = fabs((yyvsp[-1].real));
        /* printf("%.1f = %.1f\n", $2, $$); */
    }
#line 1715 "calc_morgana.tab.c"
    break;

  case 36: /* expre: '(' expre ')'  */
#line 443 "calc_morgana.y"
                    {
        (yyval.real) = (yyvsp[-1].real);
    }
#line 1723 "calc_morgana.tab.c"
    break;

  case 37: /* expre: expre '^' expre  */
#line 446 "calc_morgana.y"
                      {
        (yyval.real) = pow((yyvsp[-2].real), (yyvsp[0].real));
        /* printf("%.1f ^ %.1f = %.1f\n", $1, $3, $$); */
    }
#line 1732 "calc_morgana.tab.c"
    break;

  case 38: /* expre: '-' expre  */
#line 450 "calc_morgana.y"
                             {
        (yyval.real) = -(yyvsp[0].real);
    }
#line 1740 "calc_morgana.tab.c"
    break;

  case 39: /* expre: valor  */
#line 453 "calc_morgana.y"
            { 
        (yyval.real) = (yyvsp[0].real); 
    }
#line 1748 "calc_morgana.tab.c"
    break;

  case 40: /* valor: VARIAVEL  */
#line 457 "calc_morgana.y"
                    {    
        VARS * aux = srch(rvar, (yyvsp[0].texto));
        if (aux == NULL) {
            VARSI * aux2 = srchi(ivar, (yyvsp[0].texto));
            if (aux2 == NULL)
                printf ("Variável '%s' não foi declarada\n", (yyvsp[0].texto));
            else {
                (yyval.real) = aux2->value;
            }
        } else {
            (yyval.real) = aux->value;
        }
    }
#line 1766 "calc_morgana.tab.c"
    break;

  case 41: /* valor: NUM_REAL  */
#line 470 "calc_morgana.y"
               {
        (yyval.real) = (yyvsp[0].real);
    }
#line 1774 "calc_morgana.tab.c"
    break;

  case 42: /* valor: NUM_INT  */
#line 473 "calc_morgana.y"
              {
        (yyval.real) = (yyvsp[0].inteiro);
    }
#line 1782 "calc_morgana.tab.c"
    break;

  case 43: /* logico: '(' logico ')'  */
#line 478 "calc_morgana.y"
                       {(yyval.real)=(yyvsp[-1].real);}
#line 1788 "calc_morgana.tab.c"
    break;

  case 44: /* logico: logico LOGICO logico  */
#line 479 "calc_morgana.y"
                           {
        if(strcmp((yyvsp[-1].texto), "==")==0)
            if((yyvsp[-2].real) == (yyvsp[0].real))
                (yyval.real) = 1;
            else
                (yyval.real) = 0;
        if(strcmp((yyvsp[-1].texto), "!=")==0)
            if((yyvsp[-2].real) != (yyvsp[0].real))
                (yyval.real) = 1;
            else
                (yyval.real) = 0;
        if(strcmp((yyvsp[-1].texto), "<")==0)
            if((yyvsp[-2].real) < (yyvsp[0].real))
                (yyval.real) = 1;
            else
                (yyval.real) = 0;
        if(strcmp((yyvsp[-1].texto), "<=")==0)
            if((yyvsp[-2].real) <= (yyvsp[0].real))
                (yyval.real) = 1;
            else
                (yyval.real) = 0;
        if(strcmp((yyvsp[-1].texto), ">")==0)
            if((yyvsp[-2].real) > (yyvsp[0].real))
                (yyval.real) = 1;
            else
                (yyval.real) = 0;
        if(strcmp((yyvsp[-1].texto), ">=")==0)
            if((yyvsp[-2].real) >= (yyvsp[0].real))
                (yyval.real) = 1;
            else
                (yyval.real) = 0;
        if(strcmp((yyvsp[-1].texto), "||")==0)
            if((yyvsp[-2].real) || (yyvsp[0].real))
                (yyval.real) = 1;
            else
                (yyval.real) = 0;
        if(strcmp((yyvsp[-1].texto), "&&")==0)
            if((yyvsp[-2].real) && (yyvsp[0].real))
                (yyval.real) = 1;
            else
                (yyval.real) = 0;

    }
#line 1836 "calc_morgana.tab.c"
    break;

  case 45: /* logico: expre  */
#line 522 "calc_morgana.y"
            {(yyval.real)=(yyvsp[0].real);}
#line 1842 "calc_morgana.tab.c"
    break;


#line 1846 "calc_morgana.tab.c"

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

#line 525 "calc_morgana.y"


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
