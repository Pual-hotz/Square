/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 36 "parse.y"


#define YYDEBUG 1
#define YYERROR_VERBOSE 1

#include "square.h"
#include "node.h"
#include "../squ_vm/opcode.h"

#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include <assert.h>

extern FILE *yyin, *yyout;
extern int yyparse(parser_state*);
extern int yydebug;

#ifndef TRUE
# define TRUE 1
#else
# error TRUE must be 1
#endif
#ifndef FALSE
# define FALSE 0
#else
# error FALSE must be 0
#endif
#ifndef BOOL
# define BOOL int
#endif

/* State type in Lexcial */
typedef enum
{
  BEGIN,       /* start */
  INASSIGN,    /* assign */
  INCOMMENT,   /* comment */
  INNUM,       /* number */
  INID,        /* identifier */
  INSTR,       /* string */
  FINISH,      /* end */
}StateType;

#define MAXTOKENLEN 80
#define MAXFUNCNAME 50
#define MAXRESERVED 11

/* lexeme of identifier or reserved word */
char tokenString[MAXTOKENLEN+1];

#define BUFLEN 4096
int lineno = 0;

static char lineBuf[BUFLEN]; /* holds the current line */
static int linepos = 0; /* current position in LineBuf */
static int bufsize = 0; /* current size of buffer string */
static BOOL EOF_flag = FALSE; /* corrects ungetNextChar behavior on EOF */

#define YYLEX_DECL() yylex(YYSTYPE *yylval)

static char*
strdup_(const char *str)
{
    //Space for length plus nul
    char *new_str = malloc(strlen (str) + 1);  
    // No memory
    if (new_str == NULL)
        return NULL;
    //Copy the characters          
    strcpy(new_str, str);       
    //Return the new string               
    return new_str;                            
}


static char*
strndup_(const char *str, size_t chars)
{
    char* buffer;
    size_t n;

    buffer = (char *)malloc(chars + 1);
    if(buffer)
    {
        for (n = 0;((n < chars) && (str[n] != 0));n++)
        {
          buffer[n] = str[n];
        }
        buffer[n] = 0;
    }

    return buffer;
}

char * copyString(char * s)
{ int n;
  char * t;
  if (s==NULL) return NULL;
  n = strlen(s)+1;
  t = malloc(n);
  if (t==NULL)
    printf("Out of memory error at line %d\n",lineno);
  else strcpy(t,s);
  return t;
}



/*
   enum yytokentype {
     keyword_if = 258,
     keyword_else = 259,
     keyword_break = 260,
     keyword_return = 261,
     keyword_null = 262,
     keyword_true = 263,
     keyword_false = 264,
     keyword_import = 265,
     keyword_goto = 266,
     keyword_block = 267,
     op_add = 268,
     op_sub = 269,
     op_mul = 270,
     op_div = 271,
     op_mod = 272,
     op_eq = 273,
     op_neq = 274,
     op_lt = 275,
     op_le = 276,
     op_gt = 277,
     op_ge = 278,
     op_and = 279,
     op_or = 280,
     op_bar = 281,
     op_amper = 282,
     op_next = 283,
     op_assign = 284,
     op_lp = 285,
     op_rp = 286,
     op_flp = 287,
     op_frp = 288,
     ERROR = 289,
     ENDFILE = 290,
     lit_number = 291,
     lit_string = 292,
     lit_true = 293,
     lit_false = 294,
     lit_null = 295,
     identifier = 296,
     op_LOWEST = 297,
     op_HIGHEST = 298
   };
*/

#define TokenType YYTOKENTYPE

/* Type of an expr */
int expr_t;

typedef struct
{
  squ_int *vm_l;     /* A list to save the opcode */
  squ_int length;    /* Length of the list */
}List;

/* Init the list */
void 
Vm_List_Init(List* list)
{
  list->length = 0;
}

/* Add a opcode to the list */
void 
Vm_List_Append(List* list, squ_int opcode)
{
  list->vm_l[list->length] = opcode;
}

/* New a vm list */
List* vm_list;
/* Init the list of vm  */
/* Vm_List_Init(vm_list); */


/* Line 371 of yacc.c  */
#line 255 "parse.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parse.tab.h".  */
#ifndef YY_YY_PARSE_TAB_H_INCLUDED
# define YY_YY_PARSE_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     keyword_if = 258,
     keyword_else = 259,
     keyword_break = 260,
     keyword_return = 261,
     keyword_null = 262,
     keyword_true = 263,
     keyword_false = 264,
     keyword_import = 265,
     keyword_goto = 266,
     keyword_block = 267,
     keyword_func = 268,
     keyword_class = 269,
     op_add = 270,
     op_sub = 271,
     op_mul = 272,
     op_div = 273,
     op_mod = 274,
     op_eq = 275,
     op_neq = 276,
     op_lt = 277,
     op_le = 278,
     op_gt = 279,
     op_ge = 280,
     op_and = 281,
     op_or = 282,
     op_bar = 283,
     op_amper = 284,
     op_next = 285,
     op_assign = 286,
     op_lp = 287,
     op_rp = 288,
     op_flp = 289,
     op_frp = 290,
     ERROR = 291,
     ENDFILE = 292,
     lit_number = 293,
     lit_string = 294,
     lit_true = 295,
     lit_false = 296,
     lit_null = 297,
     identifier = 298,
     op_LOWEST = 299,
     op_HIGHEST = 300
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 227 "parse.y"

  node* nd;
  squ_id id;
  size_t int_val;
  char* string_val;
  double double_val;
  char char_val;


/* Line 387 of yacc.c  */
#line 353 "parse.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (parser_state *p);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_PARSE_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */
/* Line 390 of yacc.c  */
#line 275 "parse.y"


static int yylex(YYSTYPE *lval);
static void yyerror(parser_state* p, const char* s);
static int yywarp(void);
static void yywarnning(parser_state* p,const char* s);


/* Line 390 of yacc.c  */
#line 389 "parse.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  62
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   703

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNRULES -- Number of states.  */
#define YYNSTATES  213

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      57,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    55,    45,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    48,     2,    53,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    52,    56,
      54,     2,     2,     2,    49,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    50,     2,    51,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    46,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      47
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    11,    15,    18,    22,
      25,    28,    34,    38,    40,    42,    45,    47,    51,    55,
      59,    63,    67,    71,    75,    79,    83,    87,    91,    95,
      99,   102,   105,   108,   111,   115,   119,   121,   125,   129,
     133,   137,   141,   145,   149,   153,   157,   161,   165,   169,
     173,   176,   179,   182,   185,   189,   193,   195,   196,   206,
     208,   214,   215,   217,   219,   223,   224,   227,   229,   231,
     233,   237,   241,   244,   248,   252,   261,   263,   265,   267,
     269,   274,   281,   285,   287,   289,   293,   299,   306,   314,
     319,   323,   327,   329,   333,   334,   336,   341,   345,   347,
     350,   352,   356,   358,   360,   363,   364,   366,   368,   370
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      59,     0,    -1,    60,    -1,    61,    80,    -1,    -1,    62,
      -1,    61,    81,    62,    -1,     1,    62,    -1,    63,    31,
      64,    -1,     6,    68,    -1,    10,    43,    -1,    62,    30,
      62,    30,    62,    -1,    14,    43,    76,    -1,     5,    -1,
      64,    -1,    11,    70,    -1,    43,    -1,    64,    15,    64,
      -1,    64,    16,    64,    -1,    64,    17,    64,    -1,    64,
      18,    64,    -1,    64,    19,    64,    -1,    64,    28,    64,
      -1,    64,    29,    64,    -1,    64,    24,    64,    -1,    64,
      25,    64,    -1,    64,    22,    64,    -1,    64,    23,    64,
      -1,    64,    20,    64,    -1,    64,    21,    64,    -1,    15,
      64,    -1,    16,    64,    -1,    45,    64,    -1,    46,    64,
      -1,    64,    26,    64,    -1,    64,    27,    64,    -1,    73,
      -1,    65,    15,    65,    -1,    65,    16,    65,    -1,    65,
      17,    65,    -1,    65,    18,    65,    -1,    65,    19,    65,
      -1,    65,    28,    65,    -1,    65,    29,    65,    -1,    65,
      24,    65,    -1,    65,    25,    65,    -1,    65,    22,    65,
      -1,    65,    23,    65,    -1,    65,    20,    65,    -1,    65,
      21,    65,    -1,    15,    65,    -1,    16,    65,    -1,    45,
      65,    -1,    46,    65,    -1,    65,    26,    65,    -1,    65,
      27,    65,    -1,    72,    -1,    -1,    66,     4,     3,    32,
      65,    33,    34,    60,    35,    -1,    66,    -1,    66,     4,
      34,    60,    35,    -1,    -1,    69,    -1,    64,    -1,    69,
      48,    64,    -1,    -1,    49,    43,    -1,    38,    -1,    39,
      -1,    43,    -1,    32,    64,    33,    -1,    50,    69,    51,
      -1,    50,    51,    -1,    50,    75,    51,    -1,    50,    52,
      51,    -1,     3,    32,    65,    33,    34,    60,    35,    67,
      -1,     7,    -1,     8,    -1,     9,    -1,    71,    -1,    43,
      32,    68,    33,    -1,    72,    53,    43,    32,    68,    33,
      -1,    72,    53,    43,    -1,    71,    -1,    77,    -1,    12,
      43,    77,    -1,    43,    32,    68,    33,    76,    -1,    13,
      43,    32,    68,    33,    76,    -1,    73,    53,    43,    32,
      68,    33,    76,    -1,    73,    53,    43,    76,    -1,    39,
      52,    64,    -1,    43,    52,    64,    -1,    74,    -1,    75,
      48,    74,    -1,    -1,    77,    -1,    34,    78,    60,    35,
      -1,    34,    60,    35,    -1,    54,    -1,    79,    54,    -1,
      43,    -1,    79,    48,    43,    -1,    81,    -1,    82,    -1,
      81,    82,    -1,    -1,    55,    -1,    26,    -1,    56,    -1,
      57,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   357,   357,   363,   367,   370,   375,   380,   385,   389,
     393,   397,   401,   405,   409,   413,   416,   422,   430,   434,
     438,   442,   446,   450,   454,   458,   462,   466,   470,   474,
     478,   482,   486,   490,   494,   498,   502,   508,   512,   516,
     520,   524,   528,   532,   536,   540,   544,   548,   552,   556,
     560,   564,   568,   572,   576,   580,   584,   591,   594,   600,
     604,   611,   614,   620,   625,   632,   633,   636,   637,   638,
     642,   646,   650,   654,   658,   662,   666,   670,   674,   680,
     684,   688,   692,   698,   699,   703,   707,   711,   715,   719,
     725,   729,   735,   740,   748,   751,   757,   761,   767,   771,
     777,   782,   789,   792,   793,   794,   797,   798,   799,   800
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "keyword_if", "keyword_else",
  "keyword_break", "keyword_return", "keyword_null", "keyword_true",
  "keyword_false", "keyword_import", "keyword_goto", "keyword_block",
  "keyword_func", "keyword_class", "op_add", "op_sub", "op_mul", "op_div",
  "op_mod", "op_eq", "op_neq", "op_lt", "op_le", "op_gt", "op_ge",
  "op_and", "op_or", "op_bar", "op_amper", "op_next", "op_assign", "op_lp",
  "op_rp", "op_flp", "op_frp", "ERROR", "ENDFILE", "lit_number",
  "lit_string", "lit_true", "lit_false", "lit_null", "identifier",
  "op_LOWEST", "'!'", "'~'", "op_HIGHEST", "','", "'@'", "'['", "']'",
  "':'", "'.'", "'<'", "' '", "';'", "'\\n'", "$accept", "program",
  "stmt_seq", "stmts", "stmt", "var", "expr", "condition", "opt_elsif",
  "opt_else", "opt_args", "args", "grade", "primary0", "cond", "primary",
  "map", "map_args", "opt_block", "block", "bparam", "f_args", "opt_terms",
  "terms", "term", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    33,   126,   300,    44,    64,
      91,    93,    58,    46,    60,    32,    59,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    60,    61,    61,    61,    61,    62,    62,
      62,    62,    62,    62,    62,    62,    63,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    66,    66,    67,
      67,    68,    68,    69,    69,    70,    70,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    72,
      72,    72,    72,    73,    73,    73,    73,    73,    73,    73,
      74,    74,    75,    75,    76,    76,    77,    77,    78,    78,
      79,    79,    80,    81,    81,    81,    82,    82,    82,    82
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     3,     2,     3,     2,
       2,     5,     3,     1,     1,     2,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     2,     3,     3,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     2,     3,     3,     1,     0,     9,     1,
       5,     0,     1,     1,     3,     0,     2,     1,     1,     1,
       3,     3,     2,     3,     3,     8,     1,     1,     1,     1,
       4,     6,     3,     1,     1,     3,     5,     6,     7,     4,
       3,     3,     1,     3,     0,     1,     4,     3,     1,     2,
       1,     3,     1,     1,     2,     0,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    13,    61,    76,    77,    78,     0,    65,
       0,     0,     0,     0,     0,     0,     0,    67,    68,    69,
       0,     0,     0,     0,     2,   105,     5,     0,    14,    83,
      36,    84,     7,     0,    69,    63,     9,    62,    10,     0,
      15,     0,     0,    94,    30,    31,     0,    69,    98,     0,
       0,     0,    61,    32,    33,    68,    69,    72,     0,     0,
      92,     0,     1,   107,   106,   108,   109,     3,   102,   103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      69,     0,     0,     0,    79,    56,     0,    66,    85,    61,
      12,    95,    70,    97,     0,     0,    99,     0,     0,     0,
      74,    71,     0,    73,     6,   104,     0,     8,    17,    18,
      19,    20,    21,    28,    29,    26,    27,    24,    25,    34,
      35,    22,    23,    94,    50,    51,    61,    52,    53,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    64,     0,    96,   101,
      94,    90,    91,     0,     0,    93,     0,    61,    89,     0,
      37,    38,    39,    40,    41,    48,    49,    46,    47,    44,
      45,    54,    55,    42,    43,     0,    82,    94,    86,    11,
       0,    80,     0,    61,    87,    94,    57,     0,    88,    59,
      75,    81,     0,     0,     0,     0,     0,     0,    60,     0,
       0,     0,    58
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    23,    24,    25,    26,    27,    28,    93,   199,   200,
      36,    37,    40,    29,    95,    30,    60,    61,   100,    31,
      50,    51,    67,    68,    69
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -102
static const yytype_int16 yypact[] =
{
     210,   444,   -28,  -102,   122,  -102,  -102,  -102,    -2,     7,
      22,    23,    24,   122,   122,   122,   267,  -102,  -102,   -17,
     122,   122,   394,    84,  -102,   -20,    55,    57,   552,  -102,
      37,  -102,    55,   459,    59,   552,  -102,    47,  -102,    58,
    -102,    64,    67,    64,  -102,  -102,   495,   -10,  -102,    65,
     324,   -24,   122,  -102,  -102,    50,   -29,  -102,    52,   -35,
    -102,    -6,  -102,  -102,  -102,  -102,  -102,  -102,   379,  -102,
     444,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,    61,   459,   459,
      75,   459,   459,   514,  -102,    73,   122,  -102,  -102,   122,
    -102,  -102,  -102,  -102,    92,    85,  -102,    99,   122,   122,
    -102,  -102,     0,  -102,    55,  -102,   106,   552,    29,    29,
    -102,  -102,  -102,   645,   645,    10,    10,    10,    10,   656,
     621,   595,   567,    -1,  -102,  -102,   122,  -102,  -102,   459,
     459,   459,   459,   459,   459,   459,   459,   459,   459,   459,
     459,   459,   459,   459,   105,    97,   552,   108,  -102,  -102,
      64,   552,   552,    50,    90,  -102,   444,   122,  -102,   110,
      45,    45,  -102,  -102,  -102,   667,   667,    35,    35,    35,
      35,   678,   633,   608,   581,   324,   114,    64,  -102,   106,
     117,  -102,   118,   122,  -102,    64,  -102,   119,  -102,   151,
    -102,  -102,     6,   125,   324,   459,   123,   533,  -102,   128,
     324,   131,  -102
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -102,  -102,   -16,  -102,    19,  -102,    -3,    56,  -102,  -102,
     -44,   141,  -102,   -31,  -102,  -102,    63,  -102,  -101,   -36,
    -102,  -102,  -102,  -102,   102
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -101
static const yytype_int16 yytable[] =
{
      49,    35,    94,    52,    33,    98,    63,   101,   107,   203,
      44,    45,    46,    96,   -16,    52,   111,    53,    54,    35,
      32,   -16,    52,   109,   105,    72,    73,    74,    75,    76,
     106,   167,   168,    16,   104,    64,    65,    66,  -100,   163,
     204,    38,   112,   164,  -100,   113,    74,    75,    76,    35,
     139,   140,   141,   142,   143,   157,    39,    94,    94,   188,
      94,    94,   141,   142,   143,    41,    42,    43,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,    62,    70,   194,   114,    71,   116,
      87,    52,   169,   156,   198,    96,    35,   101,    16,    99,
     103,    97,   108,   110,   133,   161,   162,   136,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,   190,   101,     2,   155,   158,   159,     5,
       6,     7,   160,    35,    10,    11,   166,    13,    14,   185,
     186,   187,   109,   191,   134,   135,   193,   137,   138,   197,
     195,   101,   201,   196,    15,   202,    16,   205,   208,   101,
      17,    18,   210,    59,    35,    34,   212,    20,    21,   192,
     115,     0,    22,     0,    94,   165,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   189,     0,     0,   206,     0,
      35,     0,     0,     0,   211,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
      -4,     1,     0,     2,     0,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    -4,     0,     0,     0,
       0,     0,    15,     0,    16,     0,     0,     0,    17,    18,
       0,     0,     0,    19,     0,    20,    21,     0,     0,     0,
      22,   207,     0,     0,     0,    -4,    -4,    -4,     1,     0,
       2,     0,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    -4,     0,     0,     0,     0,     0,    15,
       0,    16,    -4,     0,     0,    17,    18,     0,     0,     0,
      47,     0,    20,    21,     0,     0,     0,    22,     0,     0,
       0,    48,    -4,    -4,    -4,     1,     0,     2,     0,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      -4,     0,     0,     0,     0,     0,    15,     0,    16,    -4,
       0,     0,    17,    18,     0,     0,     0,    19,     0,    20,
      21,     0,     0,     0,    22,     0,     0,     0,     0,    -4,
      -4,    -4,     2,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,     0,     2,     0,     0,
       0,     5,     6,     7,     0,    63,    10,    11,     0,    13,
      14,    15,     0,    16,     0,     0,     0,    17,    18,     0,
       0,     0,    19,     0,    20,    21,    15,     0,    16,    22,
       0,     0,    17,    55,    64,    65,    66,    56,     0,    20,
      21,     0,     0,     0,    22,    57,    58,     2,     0,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,     0,     2,     0,     0,     0,     5,     6,     7,     0,
       0,     0,     0,     0,    88,    89,    15,     0,    16,     0,
       0,     0,    17,    18,     0,     0,     0,    19,     0,    20,
      21,    15,     0,     0,    22,     0,     0,    17,    18,     0,
       0,     0,    90,     0,    91,    92,     0,     0,     0,    22,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,     0,     0,     0,   102,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,     0,     0,     0,   154,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,     0,     0,     0,   209,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
      72,    73,    74,    75,    76,  -101,  -101,    79,    80,    81,
      82,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,   139,   140,   141,   142,   143,  -101,  -101,   146,
     147,   148,   149,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-102)))

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-101)))

static const yytype_int16 yycheck[] =
{
      16,     4,    33,    32,    32,    41,    26,    43,    52,     3,
      13,    14,    15,    48,    31,    32,    51,    20,    21,    22,
       1,    31,    32,    52,    48,    15,    16,    17,    18,    19,
      54,    32,   133,    34,    50,    55,    56,    57,    48,    39,
      34,    43,    48,    43,    54,    51,    17,    18,    19,    52,
      15,    16,    17,    18,    19,    99,    49,    88,    89,   160,
      91,    92,    17,    18,    19,    43,    43,    43,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,     0,    30,   187,    68,    31,    70,
      53,    32,   136,    96,   195,    48,    99,   133,    34,    32,
      35,    43,    52,    51,    43,   108,   109,    32,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   167,   160,     3,    53,    35,    43,     7,
       8,     9,    33,   136,    12,    13,    30,    15,    16,    34,
      43,    33,    52,    33,    88,    89,    32,    91,    92,   193,
      33,   187,    33,    35,    32,     4,    34,    32,    35,   195,
      38,    39,    34,    22,   167,    43,    35,    45,    46,   185,
      68,    -1,    50,    -1,   205,   112,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   166,    -1,    -1,   204,    -1,
     193,    -1,    -1,    -1,   210,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
       0,     1,    -1,     3,    -1,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    34,    -1,    -1,    -1,    38,    39,
      -1,    -1,    -1,    43,    -1,    45,    46,    -1,    -1,    -1,
      50,   205,    -1,    -1,    -1,    55,    56,    57,     1,    -1,
       3,    -1,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,    32,
      -1,    34,    35,    -1,    -1,    38,    39,    -1,    -1,    -1,
      43,    -1,    45,    46,    -1,    -1,    -1,    50,    -1,    -1,
      -1,    54,    55,    56,    57,     1,    -1,     3,    -1,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    -1,    -1,    -1,    -1,    -1,    32,    -1,    34,    35,
      -1,    -1,    38,    39,    -1,    -1,    -1,    43,    -1,    45,
      46,    -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,    55,
      56,    57,     3,    -1,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,     3,    -1,    -1,
      -1,     7,     8,     9,    -1,    26,    12,    13,    -1,    15,
      16,    32,    -1,    34,    -1,    -1,    -1,    38,    39,    -1,
      -1,    -1,    43,    -1,    45,    46,    32,    -1,    34,    50,
      -1,    -1,    38,    39,    55,    56,    57,    43,    -1,    45,
      46,    -1,    -1,    -1,    50,    51,    52,     3,    -1,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,     3,    -1,    -1,    -1,     7,     8,     9,    -1,
      -1,    -1,    -1,    -1,    15,    16,    32,    -1,    34,    -1,
      -1,    -1,    38,    39,    -1,    -1,    -1,    43,    -1,    45,
      46,    32,    -1,    -1,    50,    -1,    -1,    38,    39,    -1,
      -1,    -1,    43,    -1,    45,    46,    -1,    -1,    -1,    50,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    -1,    -1,    33,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    -1,    -1,    33,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    -1,    -1,    33,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    32,    34,    38,    39,    43,
      45,    46,    50,    59,    60,    61,    62,    63,    64,    71,
      73,    77,    62,    32,    43,    64,    68,    69,    43,    49,
      70,    43,    43,    43,    64,    64,    64,    43,    54,    60,
      78,    79,    32,    64,    64,    39,    43,    51,    52,    69,
      74,    75,     0,    26,    55,    56,    57,    80,    81,    82,
      30,    31,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    53,    15,    16,
      43,    45,    46,    65,    71,    72,    48,    43,    77,    32,
      76,    77,    33,    35,    60,    48,    54,    68,    52,    52,
      51,    51,    48,    51,    62,    82,    62,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    43,    65,    65,    32,    65,    65,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    33,    53,    64,    68,    35,    43,
      33,    64,    64,    39,    43,    74,    30,    32,    76,    68,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    34,    43,    33,    76,    62,
      68,    33,    60,    32,    76,    33,    35,    68,    76,    66,
      67,    33,     4,     3,    34,    32,    60,    65,    35,    33,
      34,    60,    35
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      yyerror (p, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, p); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, parser_state *p)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, p)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    parser_state *p;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (p);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, parser_state *p)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, p)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    parser_state *p;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, p);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule, parser_state *p)
#else
static void
yy_reduce_print (yyvsp, yyrule, p)
    YYSTYPE *yyvsp;
    int yyrule;
    parser_state *p;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       , p);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule, p); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, parser_state *p)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, p)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    parser_state *p;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (p);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (parser_state *p)
#else
int
yyparse (p)
    parser_state *p;
#endif
#endif
{
/* The lookahead symbol.  */
int yychar;


#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
static YYSTYPE yyval_default;
# define YY_INITIAL_VALUE(Value) = Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 358 "parse.y"
    { 
                      p->lval = (yyvsp[(1) - (1)].nd);  
                    }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 367 "parse.y"
    {
                      (yyval.nd) = node_array_new();
                    }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 371 "parse.y"
    {
                      (yyval.nd) = node_array_new();
                      node_array_add((yyval.nd), (yyvsp[(1) - (1)].nd));
                    }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 376 "parse.y"
    {
                      (yyval.nd) = (yyvsp[(1) - (3)].nd);
                      node_array_add((yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 381 "parse.y"
    {
                    }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 386 "parse.y"
    {
                      (yyval.nd) = node_let_new((yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 390 "parse.y"
    {
                      (yyval.nd) = node_return_new((yyvsp[(2) - (2)].nd));
                    }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 394 "parse.y"
    {
                      (yyval.nd) = node_import_new((yyvsp[(2) - (2)].id));
                    }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 398 "parse.y"
    {

                  }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 402 "parse.y"
    {

                  }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 406 "parse.y"
    {
                      (yyval.nd) = node_break_new();
                    }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 410 "parse.y"
    {
                      (yyval.nd) = (yyvsp[(1) - (1)].nd);
                    }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 417 "parse.y"
    {
                        //$$ = node_ident_new((squ_id)copyString(tokenString));
                    }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 423 "parse.y"
    {
                      (yyval.nd) = node_op_new("+", (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                      switch((yyval.nd) -> type)
                      {

                      }
                    }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 431 "parse.y"
    {
                      (yyval.nd) = node_op_new("-", (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 435 "parse.y"
    {
                      (yyval.nd) = node_op_new("*", (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 439 "parse.y"
    {
                      (yyval.nd) = node_op_new("/", (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 443 "parse.y"
    {
                      (yyval.nd) = node_op_new("%", (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 447 "parse.y"
    {
                      (yyval.nd) = node_op_new("|", (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 451 "parse.y"
    {
                      (yyval.nd) = node_op_new("&", (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 455 "parse.y"
    {
                      (yyval.nd) = node_op_new(">", (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 459 "parse.y"
    {
                      (yyval.nd) = node_op_new(">=", (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 463 "parse.y"
    {
                      (yyval.nd) = node_op_new("<", (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 467 "parse.y"
    {
                      (yyval.nd) = node_op_new("<=", (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 471 "parse.y"
    {
                      (yyval.nd) = node_op_new("==", (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 475 "parse.y"
    {
                      (yyval.nd) = node_op_new("!=", (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 479 "parse.y"
    {
                      (yyval.nd) = node_value_new((yyvsp[(2) - (2)].nd));
                    }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 483 "parse.y"
    {
                      (yyval.nd) = node_value_new((yyvsp[(2) - (2)].nd));
                    }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 487 "parse.y"
    {
                      (yyval.nd) = node_op_new("!", NULL, (yyvsp[(2) - (2)].nd));
                    }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 491 "parse.y"
    {
                      (yyval.nd) = node_op_new("~", NULL, (yyvsp[(2) - (2)].nd));
                    }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 495 "parse.y"
    {
                      (yyval.nd) = node_op_new("&&", (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 499 "parse.y"
    {
                      (yyval.nd) = node_op_new("||", (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 503 "parse.y"
    {
                      (yyval.nd) = (yyvsp[(1) - (1)].nd);
                    }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 509 "parse.y"
    {
                      (yyval.nd) = node_op_new("+", (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 513 "parse.y"
    {
                      (yyval.nd) = node_op_new("-", (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 517 "parse.y"
    {
                      (yyval.nd) = node_op_new("*", (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 521 "parse.y"
    {
                      (yyval.nd) = node_op_new("/", (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 525 "parse.y"
    {
                      (yyval.nd) = node_op_new("%", (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 529 "parse.y"
    {
                      (yyval.nd) = node_op_new("|", (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 533 "parse.y"
    {
                      (yyval.nd) = node_op_new("&", (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 537 "parse.y"
    {
                      (yyval.nd) = node_op_new(">", (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 541 "parse.y"
    {
                      (yyval.nd) = node_op_new(">=", (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 545 "parse.y"
    {
                      (yyval.nd) = node_op_new("<", (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 549 "parse.y"
    {
                      (yyval.nd) = node_op_new("<=", (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 553 "parse.y"
    {
                      (yyval.nd) = node_op_new("==", (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 557 "parse.y"
    {
                      (yyval.nd) = node_op_new("!=", (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 561 "parse.y"
    {
                      (yyval.nd) = node_value_new((yyvsp[(2) - (2)].nd));
                    }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 565 "parse.y"
    {
                      (yyval.nd) = node_value_new((yyvsp[(2) - (2)].nd));
                    }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 569 "parse.y"
    {
                      (yyval.nd) = node_op_new("!", NULL, (yyvsp[(2) - (2)].nd));
                    }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 573 "parse.y"
    {
                      (yyval.nd) = node_op_new("~", NULL, (yyvsp[(2) - (2)].nd));
                    }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 577 "parse.y"
    {
                      (yyval.nd) = node_op_new("&&", (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 581 "parse.y"
    {
                      (yyval.nd) = node_op_new("||", (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 585 "parse.y"
    {
                      (yyval.nd) = (yyvsp[(1) - (1)].nd);
                    }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 591 "parse.y"
    {
                      (yyval.nd) = NULL;
                    }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 595 "parse.y"
    {
                      (yyval.nd) = node_if_new((yyvsp[(5) - (9)].nd), (yyvsp[(8) - (9)].nd), NULL);
                    }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 601 "parse.y"
    {
                      (yyval.nd) = NULL;
                    }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 605 "parse.y"
    {
                      (yyval.nd) = (yyvsp[(4) - (5)].nd);
                    }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 611 "parse.y"
    {
                      (yyval.nd) = node_array_new();
                    }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 615 "parse.y"
    {
                      (yyval.nd) = (yyvsp[(1) - (1)].nd);
                    }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 621 "parse.y"
    {
                      (yyval.nd) = node_array_new();
                      node_array_add((yyval.nd), (yyvsp[(1) - (1)].nd));
                    }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 626 "parse.y"
    {
                      (yyval.nd) = (yyvsp[(1) - (3)].nd);
                      node_array_add((yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 639 "parse.y"
    {
                      (yyval.nd) = node_ident_new((yyvsp[(1) - (1)].id));
                    }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 643 "parse.y"
    {
                       (yyval.nd) = (yyvsp[(2) - (3)].nd);
                    }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 647 "parse.y"
    {
                      (yyval.nd) = node_array_of((yyvsp[(2) - (3)].nd));
                    }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 651 "parse.y"
    {
                      (yyval.nd) = node_array_of(NULL);
                    }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 655 "parse.y"
    {
                      (yyval.nd) = node_map_of((yyvsp[(2) - (3)].nd));
                    }
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 659 "parse.y"
    {
                      (yyval.nd) = node_map_of(NULL);
                    }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 663 "parse.y"
    {
                      (yyval.nd) = node_if_new((yyvsp[(3) - (8)].nd), (yyvsp[(6) - (8)].nd), (yyvsp[(8) - (8)].nd));
                    }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 667 "parse.y"
    {
                      (yyval.nd) = node_null();
                    }
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 671 "parse.y"
    {
                      (yyval.nd) = node_true();
                    }
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 675 "parse.y"
    {
                      (yyval.nd) = node_false();
                    }
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 681 "parse.y"
    {
                       (yyval.nd) = (yyvsp[(1) - (1)].nd);
                    }
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 685 "parse.y"
    {
                      (yyval.nd) = node_call_new(NULL, node_ident_new((yyvsp[(1) - (4)].id)), (yyvsp[(3) - (4)].nd), NULL);
                    }
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 689 "parse.y"
    {
                      (yyval.nd) = node_call_new(NULL, node_ident_new((yyvsp[(3) - (6)].id)), (yyvsp[(5) - (6)].nd), NULL);
                    }
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 693 "parse.y"
    {
                      (yyval.nd) = node_call_new((yyvsp[(1) - (3)].nd), node_ident_new((yyvsp[(3) - (3)].id)), NULL, NULL);
                    }
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 700 "parse.y"
    {
                      (yyval.nd) = node_call_new(NULL, NULL, NULL, (yyvsp[(1) - (1)].nd));
                    }
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 704 "parse.y"
    {
                      (yyval.nd) = node_call_new(NULL, node_ident_new((yyvsp[(2) - (3)].id)), NULL, (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 708 "parse.y"
    {
                      (yyval.nd) = node_call_new(NULL, node_ident_new((yyvsp[(1) - (5)].id)), (yyvsp[(3) - (5)].nd), (yyvsp[(5) - (5)].nd));
                    }
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 712 "parse.y"
    {

                    }
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 716 "parse.y"
    {
                      (yyval.nd) = node_call_new((yyvsp[(1) - (7)].nd), node_ident_new((yyvsp[(3) - (7)].id)), (yyvsp[(5) - (7)].nd), (yyvsp[(7) - (7)].nd));
                    }
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 720 "parse.y"
    {
                      (yyval.nd) = node_call_new((yyvsp[(1) - (4)].nd), node_ident_new((yyvsp[(3) - (4)].id)), NULL, (yyvsp[(4) - (4)].nd));
                    }
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 726 "parse.y"
    {
                      (yyval.nd) = node_pair_new((yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 730 "parse.y"
    {
                      (yyval.nd) = node_pair_new(node_ident_new((yyvsp[(1) - (3)].id)), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 736 "parse.y"
    {
                      (yyval.nd) = node_map_new();
                      node_array_add((yyval.nd), (yyvsp[(1) - (1)].nd));
                    }
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 741 "parse.y"
    {
                      (yyval.nd) = (yyvsp[(1) - (3)].nd);
                      node_array_add((yyval.nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 748 "parse.y"
    {
                      (yyval.nd) = NULL;
                    }
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 752 "parse.y"
    {
                       (yyval.nd) = (yyvsp[(1) - (1)].nd);
                    }
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 758 "parse.y"
    {
                      (yyval.nd) = node_block_new((yyvsp[(2) - (4)].nd), (yyvsp[(3) - (4)].nd));
                    }
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 762 "parse.y"
    {
                      (yyval.nd) = node_block_new(NULL, (yyvsp[(2) - (3)].nd));
                    }
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 768 "parse.y"
    {
                      (yyval.nd) = NULL;
                    }
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 772 "parse.y"
    {
                      (yyval.nd) = (yyvsp[(1) - (2)].nd);
                    }
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 778 "parse.y"
    {
                      (yyval.nd) = node_array_new();
                      node_array_add((yyval.nd), node_ident_new((yyvsp[(1) - (1)].id)));
                    }
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 783 "parse.y"
    {
                      (yyval.nd) = (yyvsp[(1) - (3)].nd);
                      node_array_add((yyval.nd), node_ident_new((yyvsp[(3) - (3)].id)));
                    }
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 793 "parse.y"
    {yyerrok;}
    break;


/* Line 1792 of yacc.c  */
#line 2650 "parse.tab.c"
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (p, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (p, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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
		      yytoken, &yylval, p);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp, p);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (p, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, p);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, p);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 802 "parse.y"

//#define yylval  (*((YYSTYPE*)(p->lval)))
#include "parse.tab.h"

static void
yyerror(parser_state *p, const char *s)
{
  p->nerr++;
  if (p->file_name)
  {
    fprintf(stderr, "%s[Error]:%d:%s\n", p->file_name, p->lineno, s);
  }
  else 
  {
    fprintf(stderr, "%s\n", s);
  }
  exit(1);
}

static void
yywarnning(parser_state* p,const char* s)
{
  if(p->file_name)
  {
    printf("%s[Warnning]:%d:%s\n",p ->file_name,p->lineno,s);
  }
  else
  {
    printf("[Warnning]:%s",s);
  }
}

static int
yywarp(void){
  return 1;
}

static int
getNextChar(void)
{ 
  if(!(linepos < bufsize))
  { 
    lineno++;
    if(fgets(lineBuf,BUFLEN-1,yyin))
    { 
      bufsize = strlen(lineBuf);
      linepos = 0;
      return lineBuf[linepos++];
    }
    else
    { 
      EOF_flag = TRUE;
      return EOF;
    }
  }
  else
    return lineBuf[linepos++];
}


static void 
ungetNextChar(void)
{ 
  if (!EOF_flag)
  {
    linepos--;
  }
}

void
catToken(int c,int tokenStringIndex)
{
  if(tokenStringIndex < MAXTOKENLEN - 1)
  {
    tokenString[++tokenStringIndex] = c;
  }
  else
  {
    
  }
}

/* lookup table of reserved words */
static struct
    { 
      char* str;
      int tok;
    } reservedWords[MAXRESERVED]
   = {{"if",keyword_if},{"else",keyword_else},{"null",keyword_null},
      {"import",keyword_import},{"false",keyword_false},{"true",keyword_false},
      {"break",keyword_break},{"return",keyword_return},{"goto",keyword_goto},
      {"block",keyword_block},{"func",keyword_func},{"class",keyword_class}
    };

/* look for existing keyword*/
/* linear search */
/* TODO: use binary search */
static int 
reservedLookup(squ_string s)
{ 
  int i;
  for (i = 0;i<MAXRESERVED;i++){
    if (!strcmp(s,reservedWords[i].str))
      return reservedWords[i].tok;
    else
      return identifier;
  }
}


BOOL 
isChar(int c)
{
    if((c >=35 &&c <= 126)||(c == ' ')||(c =='!')) 
      return TRUE;
    else
      return FALSE;
}

static squ_int
string_escape(char* s, size_t len)
{
  char* t = s;
  char* tend = t + len;
  char* p = s;

  while (t < tend) {
    switch (*t) {
    case '\\':
      t++;
      if (t == tend) break;
      switch (*t) {
      case 'n':
        *p++ = '\n'; break;
      case 'r':
        *p++ = '\r'; break;
      case 't':
        *p++ = '\t'; break;
      case 'e':
        *p++ = 033; break;
      case '0':
        *p++ = '\0'; break;
      case 'x':
        {
          unsigned char c = 0;
          char* xend = t+3;

          t++;
          while (t < tend && t < xend) {
            switch (*t) {
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
              c *= 16;
              c += *t - '0';
              break;
            case 'a': case 'b': case 'c':
            case 'd': case 'e': case 'f':
              c *= 16;
              c += *t - 'a' + 10;
              break;
            default:
              xend = t;
              break;
            }
            t++;
          }
          *p++ = (char)c;
          t--;
        }
        break;
      default:
        *p++ = *t; break;
      }
      t++;
      break;
    default:
      *p++ = *t++;
      break;
    }
  }
  return (squ_int)(p - s);
}


TokenType getToken(YYSTYPE* yylval){
  int result;
  int c;
  int tokenStringIndex = 0;
  StateType state = BEGIN;
  BOOL save;
  int yyleng = 0;
  while(state != FINISH)
  {
    c = getNextChar();
    save = TRUE;
    switch(state)
    {
      case BEGIN:
        if(isdigit(c))
        { 
          state = INNUM;
        }
        else if(isalpha(c) || c == '_')
        {
          state = INID;
        }
        else if(c == ':')
        {
          state = INASSIGN;
        }
        else if((c == ' ') || (c == '\t'))
        {
           save = FALSE;
        }
        else if((c == '\n') || (c == '\r'))
        {
          save = FALSE;
        }
        else if(c == '#')
        { 
          save = FALSE;
          state = INCOMMENT;
        }
        else if((c == '\"') || (c == '\''))
        {
          state = INSTR;
        }
        else
        {
          state = FINISH;
          switch(c)
          {
            case '==':
              result = op_eq;
            break;
            case '!=':
              result = op_neq;
            break;
            case '<':
              result = op_lt;
            break;
            case '<=':
              result = op_le;
            break;
            case '>':
              result = op_gt;
            break;
            case '>=':
              result = op_ge;
            break;
            case '+':
              result = op_add;
            break;
            case '-':
              result = op_sub;
            break;
            case '*':
              result = op_mul;
            break;
            case '/':
              result = op_div;
            break;
            case '%':
              result = op_mod;
            break;
            case '&&':
              result = op_and;
            break;
            case '||':
              result = op_or;
            break;
            case '&':
              result = op_amper;
            break;
            case '|':
              result = op_bar;
            break;
            case '->':
              result = op_next;
            break;
            case '(':
              result = op_lp;
            break;
            case ')':
              result = op_rp;
            break;
            case '{':
              result = op_flp;
            break;
            case '}':
              result = op_frp;
            break;
          }
        }
      break;
      case INCOMMENT:
        save = FALSE;
        if(c == EOF)
        { 
          state = FINISH;
          result = ENDFILE;
        }
        else if(c == '#') 
        {
          state = BEGIN;
        }
      break;
      case INASSIGN:
        state = FINISH;
        if(c == '=')
        {
          result = op_assign;
        }
        else
        {
          ungetNextChar();
          save = FALSE;
          result = ERROR;
        }
      break;
      case INNUM:
        if(!isdigit(c))
        {
          ungetNextChar();
          save = FALSE;
          state = FINISH;
          result = lit_number;
          yylval -> nd = node_int_new(atoi(tokenString));
        }
      break;
      case INID:
        if(!isalpha(c) || (c != '_'))
        {
          int i;
          ungetNextChar();
          save = FALSE;
          state = FINISH;
          result = identifier;
        }
      break;
      case INSTR:
        if((c == '"') || (c == '\''))
        {
          state = FINISH;
          save = FALSE;
          squ_string s = strndup_(tokenString,yyleng + 1);
          if(s[0] == '\'' || s[0] == '\"')
          {
            int i;
            for(i = 0; i < yyleng + 1;i++)
            {
              s[i] = s[i + 1];
            }
          }
          yylval -> nd = node_string_new(s);
          result = lit_string;
        }
        else
        {
          catToken(c,tokenStringIndex);
          yyleng++;
        }
      break;
      case FINISH:
      default:
        printf("Lexical Error: State : %d\n",state);
        state = FINISH;
        result = ERROR;
      break;
    }
    if((save) && (tokenStringIndex <= MAXTOKENLEN))
      tokenString[tokenStringIndex++] = (char)c;
    if(state == FINISH)
    { 
      tokenString[tokenStringIndex] = '\0';
      if(result == identifier)
        result = reservedLookup(tokenString);
    }
  }
  return result;
}


static int
yylex(YYSTYPE *yylval)
{
  return getToken(yylval);
}

squ_value
set_squ_ptr_value(void *p)
{
  squ_value v;

  v.t = SQU_VALUE_PTR;
  v.v.p = p;
  return v;
}

squ_value
set_squ_bool_value(int b)
{
  squ_value v;

  v.t = SQU_VALUE_BOOL;
  v.v.b = b ? TRUE : FALSE;
  return v;
}

squ_value
set_squ_int_value(squ_int i)
{
  squ_value v;

  v.t = SQU_VALUE_INT;
  v.v.i = i;
  return v;
}

squ_value
set_squ_double_value(squ_double d)
{
  squ_value v;

  v.t = SQU_VALUE_DOUBLE;
  v.v.d = d;
  return v;
}

void*
get_squ_value_ptr(squ_value v)
{
  assert(v.t == SQU_VALUE_PTR);
  return v.v.p;
}

squ_bool
get_squ_value_bool(squ_value v)
{
  assert(v.t == SQU_VALUE_BOOL);
  return v.v.i ? TRUE : FALSE;
}

long
get_squ_value_int(squ_value v)
{
  assert(v.t == SQU_VALUE_INT);
  return v.v.i;
}

double
get_squ_value_double(squ_value v)
{
  assert(v.t == SQU_VALUE_DOUBLE);
  return v.v.d;
}


squ_value* node_expr(squ_ctx*, node*);

squ_value*
node_expr_stmt(squ_ctx* ctx, node* np)
{
  int i;
  node_array* arr = np->value.v.p;
  squ_value* v = NULL;
  for (i = 0; i < arr->len; i++) {
    if (ctx->exc != NULL) {
      return NULL;
    }
    
    v = node_expr(ctx, arr->data[i]);
  }
  return v;
}

squ_value*
node_expr(squ_ctx* ctx, node* np)
{
  if (ctx->exc != NULL) {
    return NULL;
  }

  if (np == NULL) {
    return NULL;
  }

  switch (np->type) 
  {
  case NODE_IF:
    {
      node_if* nif = np->value.v.p;
      squ_value* v = node_expr(ctx, nif->cond);
      if (ctx->exc != NULL) {
        return NULL;
      }
      if (v->t == SQU_VALUE_NULL || v->v.p == NULL ||
          (v->t == SQU_VALUE_STRING && *v->v.s == 0)) {
        if (nif->opt_else != NULL)
          node_expr_stmt(ctx, nif->opt_else);
      } else {
        node_expr_stmt(ctx, nif->stmt_seq);
      }
    }
    break;
  case NODE_OP:
    {
      node_op* nop = np->value.v.p;
      squ_value* lhs = node_expr(ctx, nop->lhs);
      if (ctx->exc != NULL) 
        return NULL;
      if (*nop->op == '+' && *(nop->op+1) == '\0') {
        squ_value* rhs = node_expr(ctx, nop->rhs);
        if (ctx->exc != NULL) return NULL;
        if (lhs->t == SQU_VALUE_STRING && rhs->t == SQU_VALUE_STRING) {
          squ_value* new = malloc(sizeof(squ_value));
          char *p = malloc(strlen(lhs->v.s) + strlen(rhs->v.s) + 1);
          strcpy(p, lhs->v.s);
          strcat(p, rhs->v.s);
          new->t = SQU_VALUE_STRING;
          new->v.s = p;
          return new;
        } else if (lhs->t == SQU_VALUE_DOUBLE && rhs->t == SQU_VALUE_DOUBLE) {
          squ_value* new = malloc(sizeof(squ_value));
          new->t = SQU_VALUE_DOUBLE;
          new->v.d = lhs->v.d + rhs->v.d;
          return new;
        }
      }
      if (*nop->op == '-' && *(nop->op+1) == '\0') {
        squ_value* rhs = node_expr(ctx, nop->rhs);
        if (ctx->exc != NULL) 
          return NULL;
        if (lhs->t == SQU_VALUE_DOUBLE && rhs->t == SQU_VALUE_DOUBLE) {
          squ_value* new = malloc(sizeof(squ_value));
          new->t = SQU_VALUE_DOUBLE;
          new->v.d = lhs->v.d - rhs->v.d;
          return new;
        }
      }
      if (*nop->op == '*' && *(nop->op+1) == '\0') {
        squ_value* rhs = node_expr(ctx, nop->rhs);
        if (ctx->exc != NULL) 
          return NULL;
        if (lhs->t == SQU_VALUE_DOUBLE && rhs->t == SQU_VALUE_DOUBLE) {
          squ_value* new = malloc(sizeof(squ_value));
          new->t = SQU_VALUE_DOUBLE;
          new->v.d = lhs->v.d * rhs->v.d;
          return new;
        }
      }
      if (*nop->op == '/' && *(nop->op+1) == '\0') {
        squ_value* rhs = node_expr(ctx, nop->rhs);
        if (ctx->exc != NULL) 
          return NULL;
        if (lhs->t == SQU_VALUE_DOUBLE && rhs->t == SQU_VALUE_DOUBLE) {
          squ_value* new = malloc(sizeof(squ_value));
          new->t = SQU_VALUE_DOUBLE;
          
          new->v.d = lhs->v.d / rhs->v.d;
          return new;
        }
      }
      if (*nop->op == '<') {
        squ_value* rhs = node_expr(ctx, nop->rhs);
        if (ctx->exc != NULL) 
          return NULL;
        if (lhs->t == SQU_VALUE_DOUBLE && rhs->t == SQU_VALUE_DOUBLE) {
          squ_value* new = malloc(sizeof(squ_value));
          new->t = SQU_VALUE_BOOL;
          if (*(nop->op+1) == '=')
            new->v.b = lhs->v.d <= rhs->v.d;
          else
            new->v.b = lhs->v.d < rhs->v.d;
          return new;
        }
      }
      if (*nop->op == '>') {
        squ_value* rhs = node_expr(ctx, nop->rhs);
        if (ctx->exc != NULL) 
          return NULL;
        if (lhs->t == SQU_VALUE_DOUBLE && rhs->t == SQU_VALUE_DOUBLE) {
          squ_value* new = malloc(sizeof(squ_value));
          new->t = SQU_VALUE_BOOL;
          if (*(nop->op+1) == '=')
            new->v.b = lhs->v.d >= rhs->v.d;
          else
            new->v.b = lhs->v.d > rhs->v.d;
          return new;
        }
      }
      if (*nop->op == '=' && (*(nop->op+1)) == '=') {
        squ_value* rhs = node_expr(ctx, nop->rhs);
        if (ctx->exc != NULL) return NULL;
        if (lhs->t == SQU_VALUE_DOUBLE && rhs->t == SQU_VALUE_DOUBLE) {
          squ_value* new = malloc(sizeof(squ_value));
          new->t = SQU_VALUE_BOOL;
          new->v.b = lhs->v.d == rhs->v.d;
          return new;
        }
      }
      if (*nop->op == '!' && (*(nop->op+1)) == '=') {
        squ_value* rhs = node_expr(ctx, nop->rhs);
        if (ctx->exc != NULL) return NULL;
        if (lhs->t == SQU_VALUE_DOUBLE && rhs->t == SQU_VALUE_DOUBLE) {
          squ_value* new = malloc(sizeof(squ_value));
          new->t = SQU_VALUE_BOOL;
          new->v.b = lhs->v.d != rhs->v.d;
          return new;
        }
      }
      
      squ_raise(ctx, "invalid operator");
    }
    break;
  case NODE_CALL:
    {
      
      node_call* ncall = np->value.v.p;
      if (ncall->ident != NULL) {
        khint_t k = kh_get(value, ctx->env, (char*) ncall->ident->value.v.id);
        if (k != kh_end(ctx->env)) {
          squ_value* v = kh_value(ctx->env, k);
          if (v->t == SQU_VALUE_CFUNC) {
            node_array* arr0 = ncall->args->value.v.p;
            squ_array* arr1 = squ_array_new();
            int i;
            for (i = 0; i < arr0->len; i++)
              squ_array_add(arr1, node_expr(ctx, arr0->data[i]));
            ((squ_cfunc) v->v.p)(ctx, arr1);
          }
        } 
        else 
        {
          squ_raise(ctx, "function not found!");
        }
      } else {
        node_block* nblk = ncall->blk->value.v.p;
        node_expr_stmt(ctx, nblk->stmt_seq);
        if (ctx->exc != NULL) {
          squ_value* arg = ctx->exc->arg;
          free(ctx->exc);
          ctx->exc = NULL;
          return arg;
        }
      }
    }
    break;
  case NODE_RETURN:
    {
      node_return* nreturn = np->value.v.p;
      ctx->exc = malloc(sizeof(squ_error));
      ctx->exc->arg = node_expr(ctx, nreturn->rv);
      return NULL;
    }
    break;
  case NODE_VALUE:
    return &np->value;
    break;
  default:
    break;
  }
  return NULL;
}

squ_value*
squ_cputs(squ_ctx* ctx, FILE* out, squ_array* args) {
  int i;
  for (i = 0; i < args->len; i++) {
    squ_value* v;
    if (i != 0)
      fprintf(out, ", ");
    v = args->data[i];
    if (v != NULL) {
      switch (v->t) {
      case SQU_VALUE_DOUBLE:
        fprintf(out, "%f", v->v.d);
        break;
      case SQU_VALUE_STRING:
        fprintf(out, "'%s'", v->v.s);
        break;
      case SQU_VALUE_NULL:
        fprintf(out, "null");
        break;
      case SQU_VALUE_BOOL:
        fprintf(out, v->v.b ? "true" : "false");
        break;
      case SQU_VALUE_ERROR:
        fprintf(out, "%s", v->v.s);
        break;
      case SQU_VALUE_CFUNC:
        fprintf(out,"<%p>",v->v.p);
        break;
      default:
        fprintf(out, "<%p>\n", v->v.p);
        fprintf(out, "%s", v->v.s);
        break;
      }
    } 
    else 
    {
      fprintf(out, "null");
    }
  }
  fprintf(out, "\n");
  return NULL;
}

squ_value*
squ_puts(squ_ctx* ctx, squ_array* args) {
  return squ_cputs(ctx, stdout, args);
}

int
squ_run(parser_state* p)
{
  int r;
  khiter_t k;

  static squ_value vputs;
  k = kh_put(value, p->ctx.env, "puts", &r);
  vputs.t = SQU_VALUE_CFUNC;
  vputs.v.p = squ_puts;
  kh_value(p->ctx.env, k) = &vputs;

  node_expr_stmt(&p->ctx, (node*)p->lval);
  if (p->ctx.exc != NULL) 
  {
    squ_array* arr = squ_array_new();
    squ_array_add(arr, p->ctx.exc->arg);
    squ_cputs(&p->ctx, stderr, arr);
    p->ctx.exc = NULL;
  }
  return 0;
}

void
squ_raise(squ_ctx* ctx, const char* msg) {
  ctx->exc = malloc(sizeof(squ_error));
  ctx->exc->arg = malloc(sizeof(squ_value));
  ctx->exc->arg->v.s = strdup(msg);
}