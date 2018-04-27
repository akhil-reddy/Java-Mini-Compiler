/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "JavaMiniParser.y"
	#include<stdio.h>
	#include<ctype.h>
	#include<string.h>
	#include<stdlib.h>
	/*#include "JavaMiniCompiler.c"*/
	/*extern struct SymbolTable *table;*/
	/*extern abc* table;*/
	/*extern int no_of_entries;*/
	extern FILE* yyin;
	extern FILE* yyout;
	int yylex();
	void addValue(int);
	int retrieve(char []);
	int find_id(char*);
	char* find_name(int);
	char st[100][10];
	int top=0;
	char i_[2]="0";
	char temp[2]="t";
	char temp2[3];
	int forflag=0;
	int ifflag = 0;
	int elf = 1;
	int label[20];
	int lnum=0;
	int ltop=0;
	char stp[20];
	int tp = 0;
	int start = 1;
#line 34 "JavaMiniParser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union{
	char* type;
	int intval;
	int id;
	char* identifier;
	float floatval;
	char* stringval;	
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 67 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define INT 257
#define IDENTIFIER 258
#define STRING 259
#define DOUBLE 260
#define FLOATL 261
#define TRUE 262
#define FALSE 263
#define THIS 264
#define HEADER 265
#define IMPORTS 266
#define PUBLIC 267
#define CLASS 268
#define STATIC 269
#define VOID 270
#define MAIN 271
#define RET 272
#define SOPLN 273
#define SOP 274
#define IFS 275
#define ELSEQ 276
#define FORS 277
#define NEW 278
#define INTA 279
#define BOOL 280
#define BOOLA 281
#define CHARL 282
#define STR 283
#define STRA 284
#define FLOATLA 285
#define DOUBLEA 286
#define ANDAND 287
#define OROR 288
#define LESS 289
#define LESSEQ 290
#define GREAT 291
#define GREATEQ 292
#define SEMI 293
#define PLUSPLUS 294
#define MINUSMINUS 295
#define PLUSEQ 296
#define MINUSEQ 297
#define MULEQ 298
#define DIVEQ 299
#define MODEQ 300
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    8,    9,   10,   12,   11,   11,   11,   11,   11,
   16,   16,   19,   19,   19,   19,   19,   19,   19,   19,
   19,   15,   15,   17,   17,   22,   14,   14,   14,    1,
    1,   20,   18,   18,   25,   23,   24,   21,   21,   26,
   27,   29,   30,   28,   28,   28,   28,   28,   28,   28,
   28,   28,   28,   31,   31,   32,   32,   32,   32,   32,
    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,
    5,    5,    5,    4,    4,    4,    4,    4,    4,    4,
    4,   33,   33,   33,    3,    3,    6,    6,    6,    6,
    6,    6,    6,   13,   13,   13,   13,   13,   13,   13,
   13,   13,   13,   13,   13,   13,   13,    7,    7,    7,
    7,    7,    7,    2,
};
static const YYINT yylen[] = {                            2,
    2,    3,    5,    1,    8,    2,    1,    2,    2,    1,
    1,    1,    2,    4,    6,    6,    6,    6,    8,    2,
    2,    3,    1,    2,    3,    8,    3,    4,    0,    4,
    5,    3,    5,    8,    3,    0,    0,   12,   11,    0,
    0,    0,    0,    4,    4,    4,    4,    2,    2,    2,
    2,    2,    1,    2,    1,    3,    3,    3,    3,    3,
    4,    3,    3,    3,    3,    3,    3,    6,    5,    4,
    2,    3,    1,    3,    3,    3,    3,    3,    1,    3,
    1,    2,    3,    0,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    3,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    1,    2,    0,  114,    0,
    0,   96,  106,  104,    0,   94,    0,    0,    0,    0,
    0,   95,   97,   98,  101,  102,  103,  105,  107,    0,
   10,    0,    0,    3,    4,    0,    0,    7,    0,   11,
   12,    0,    0,    0,    0,    0,   24,    0,    0,    0,
   87,   88,   89,   90,   91,   93,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   40,    0,   40,    0,    6,
   13,    0,    0,    8,    0,    9,   20,   21,    0,   25,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   71,    0,    0,   36,  108,  113,  109,  110,  111,  112,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  100,    0,    0,    0,    0,    0,    0,   32,    0,    0,
    0,   14,    0,    0,    0,    0,    0,    0,   72,    0,
    0,    0,   62,   63,   64,   65,   66,   92,   67,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   30,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   70,
   61,    0,    0,   33,   23,   41,   41,    0,   80,   74,
   75,   76,   77,   78,   31,    0,    0,    0,    0,   16,
   15,   18,   17,   69,    0,    0,    0,    0,    0,    0,
    0,    0,   27,    0,    0,    0,   82,   68,   22,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   28,    0,
    5,    0,   83,   37,   34,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   42,   48,   54,    0,   19,    0,
   26,    0,    0,    0,    0,    0,   56,   57,   58,   59,
   60,    0,   42,   35,   46,   47,   44,   45,   43,    0,
   39,   43,   38,
};
static const YYINT yydgoto[] = {                          2,
   32,   60,  116,  117,  186,   62,  106,    3,    6,   34,
  199,   36,   37,  153,  164,   38,   39,   40,   41,   42,
   43,   47,  132,  200,  215,  107,  189,  204,  242,  251,
  205,  206,  187,
};
static const YYINT yysindex[] = {                      -247,
 -241,    0, -239,  -27, -232,    0,    0, -221,    0,  -85,
  395,    0,    0,    0,  210,    0, -221,    1,    6,  151,
   83,    0,    0,    0,    0,    0,    0,    0,    0,  395,
    0,  395,  -48,    0,    0,  395, -221,    0,  395,    0,
    0,  395,  395,  403,  -49, -221,    0,   -7,  113,  121,
    0,    0,    0,    0,    0,    0, -223,  151,  151,  -40,
   14,   47,    0,    0,    0,    0,  -41,    0, -221,    0,
    0,  140,  -39,    0,  -38,    0,    0,    0, -255,    0,
  -34,   26,  -57,   30,   37,   52,   54,    5,   58,   59,
    0,  151, -221,    0,    0,    0,    0,    0,    0,    0,
  151,  151,  151,  151,  151,  -94,  151,  140,   40,   43,
    0,   12,    0,  -39,    0,   70,   51,    0,  -39,  177,
  177,    0,   55,   61,   65,   74,  151,   77,    0,   36,
   94,  454,    0,    0,    0,    0,    0,    0,    0,   82,
  151,   81,  104,  -39,  -39,  -39,  -39,  -39,    0,   92,
  403, -221,  111,  114,  395,  395,  395,  395,   63,    0,
    0,  132,  514,    0,    0,    0,    0,  151,    0,    0,
    0,    0,    0,    0,    0, -221,  177,   34,   39,    0,
    0,    0,    0,    0,  151,  132,  118,  395, -218,  101,
  112,  177,    0,  484,  484,  132,    0,    0,    0, -102,
 -221, -221,  -24,  134, -218,  119, -218,  395,    0,  514,
    0,  122,    0,    0,    0,  123,  126,  128,  129,  151,
  151,  151,  151,  151,    0,    0,    0,  152,    0,  395,
    0,  484, -218, -218, -218, -218,    0,    0,    0,    0,
    0,  484,    0,    0,    0,    0,    0,    0,    0,  484,
    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -64,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -240,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -33,
    0,  -11,    2,   20,   27,    0,   38,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   85,    0,  155,    0,    0,    0,    0,  154,
  154,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  158,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  154,    0,    0,    0,
    0,    0,    0,    0,    0,  158,    0,  -75,    0,    0,
    0,  154,    0,    0,    0,  158,    0,    0,    0,    0,
    0,    0,    0,    0,  162,  -26,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  163,  164,  165,  168,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  189,  409,    0,   -8,  486,  105,    0,    0,    0,    0,
  147,    0,   87, -119, -141, -107,    0,    0,    0,    0,
    0,  169,    0,   -2,    0,  148,   48,  -86,  -23,  -35,
    0,    0, -169,
};
#define YYTABLESIZE 800
static const YYINT yytable[] = {                         92,
  114,  154,    9,   92,   93,   93,   92,   92,   92,   92,
   92,   92,   73,   92,   55,  120,  197,   99,    1,   73,
  118,   73,  119,    4,  165,   92,  213,    5,   73,   73,
   99,    7,   73,   88,    9,    8,    9,   11,   87,    9,
   49,   81,   72,   87,   87,   50,   87,   73,   87,  108,
   92,   83,  211,  212,   94,  188,   88,  193,  111,   92,
   87,   88,   88,   89,   88,  121,   88,  122,   89,   89,
  123,   89,  209,   89,   92,  201,  202,  124,   88,   92,
   92,   73,   92,  105,   92,   89,  165,  165,  103,  101,
  244,  102,  125,  104,  126,  127,   92,  128,  141,  129,
  249,   46,  230,  119,  142,  143,  148,   69,  252,  149,
  150,  146,  144,  155,  145,   59,  147,  160,  226,  156,
  228,   85,   58,  157,  165,   81,   85,   85,  161,   85,
   79,   85,  158,  162,  165,  170,  171,  172,  173,  174,
  166,  168,  165,   81,  169,   59,  245,  246,  247,  248,
  175,  178,   58,   59,  179,  184,  194,   35,  198,  207,
   58,  195,   51,    9,   59,   52,   53,   54,   55,   56,
  208,   58,   59,  214,  225,  185,   70,  227,   71,   58,
  231,  233,   74,   59,  234,   76,  235,  236,   77,   78,
   58,   86,  243,   99,   29,   79,   86,   86,   84,   86,
   37,   86,   53,   51,   52,   49,  152,  152,   50,   66,
  139,  232,   80,   79,  190,  109,  253,  113,    9,  250,
  151,    0,    0,   92,   92,    0,   92,   92,   92,   92,
   92,   55,  111,    0,    0,    0,    0,  176,    0,    0,
    0,    0,    0,    0,   92,   73,   73,    0,   73,   73,
   73,   73,   73,   92,   92,   92,   92,   92,   92,   96,
   92,   92,    0,  152,    0,    0,   73,   55,   55,  218,
  219,  220,  221,  222,  223,  224,    0,  106,  152,    0,
    0,    0,   73,   73,  104,    0,    0,    0,   87,   87,
   87,   87,   87,   87,    0,   99,    0,    0,    0,    0,
    0,  180,  181,  182,  183,    0,   88,   88,   88,   88,
   88,   88,    0,   89,   89,   89,   89,   89,   89,    0,
    0,    0,    0,    0,   92,   92,   92,   92,   92,   92,
    0,    0,    0,   95,   96,   97,   98,   99,  100,   63,
    9,    0,   64,   65,   54,   55,   56,    0,    0,    0,
    0,    0,   16,    0,  229,    0,    0,    0,    0,    0,
   57,   22,   23,   24,   25,   26,   27,   28,   29,   51,
    9,   84,   52,   53,   54,   55,   56,   51,    9,   86,
   52,   53,   54,   55,   56,    0,    0,    0,   51,    9,
   57,   52,   53,   54,   55,   56,   51,    9,   57,   52,
   53,   54,   55,   56,    0,    0,    0,   51,    9,   57,
   52,   53,   54,   55,   56,    0,   10,   57,    0,   33,
    0,    0,    0,   45,    0,   48,    0,    0,   57,   67,
    0,    0,    0,   12,    9,    0,   13,   14,   33,    0,
   33,    0,    0,    0,   33,   75,   16,   33,    0,    0,
   33,   33,   45,    0,   82,   22,   23,   24,   25,   26,
   27,   28,   29,    0,    0,   89,   12,    9,    0,   13,
   14,    0,    0,    0,    0,    0,    0,  110,   44,   16,
    0,  115,    0,    0,    0,    0,    0,   82,   22,   23,
   24,   25,   26,   27,   28,   29,    0,    0,    0,    0,
    0,  131,    0,    0,    0,   61,   68,    0,    0,    0,
    0,    0,    0,    0,  138,    0,    0,   30,    0,   31,
    0,    0,  115,    0,    0,    0,    0,  115,   45,   45,
    0,    0,    0,    0,   85,   87,    0,    0,    0,    0,
   33,    0,    0,   90,   91,    0,    0,    0,    0,    0,
    0,    0,  115,  115,  115,  115,  115,  112,    0,   45,
  177,    0,    0,   33,   33,   33,   33,    0,    0,    0,
    0,   33,    0,    0,    0,    0,  163,  130,    0,    0,
    0,    0,    0,    0,  192,   45,  133,  134,  135,  136,
  137,    0,  140,  130,    0,    0,   33,  203,    0,    0,
   45,    0,   33,   33,    0,    0,  210,    0,    0,  216,
  217,    0,  159,  203,    0,  203,   33,    0,   33,    0,
    0,    0,    0,    0,    0,    0,  167,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   33,    0,
   33,  203,  203,  203,  203,    0,    0,    0,    0,    0,
   33,   12,    9,  191,   13,   14,    0,    0,   33,   12,
    9,   15,   13,   14,   16,    0,   17,   18,   19,   20,
  196,   21,   16,   22,   23,   24,   25,   26,   27,   28,
   29,   22,   23,   24,   25,   26,   27,   28,   29,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  237,  238,  239,  240,  241,
   12,    9,    0,   13,   14,    0,    0,    0,    0,    0,
    0,    0,    0,   16,    0,   17,   18,   19,   20,    0,
   21,    0,   22,   23,   24,   25,   26,   27,   28,   29,
   12,    9,    0,   13,   14,    0,    0,    0,    0,    0,
    0,    0,    0,   16,    0,   17,   18,   19,   20,    0,
   21,    0,   22,   23,   24,   25,   26,   27,   28,   29,
   12,    9,    0,   13,   14,    0,    0,    0,    0,    0,
    0,    0,    0,   16,    0,   17,   18,   19,   20,    0,
   21,    0,   22,   23,   24,   25,   26,   27,   28,   29,
};
static const YYINT yycheck[] = {                         33,
   40,  121,  258,   37,   46,   46,   40,   41,   42,   43,
   44,   45,   61,   47,   41,  271,  186,  258,  266,   61,
   59,   33,   61,  265,  132,   59,  196,  267,   40,   41,
  271,   59,   44,  257,  258,  268,  258,  123,   37,  258,
   40,   91,   91,   42,   43,   40,   45,   59,   47,   91,
   91,   59,  194,  195,   41,  163,   37,  177,   93,   93,
   59,   42,   43,   37,   45,   40,   47,  125,   42,   43,
   41,   45,  192,   47,   37,  294,  295,   41,   59,   42,
   43,   93,   45,   37,   47,   59,  194,  195,   42,   43,
  232,   45,   41,   47,   41,   91,   59,   40,   59,   41,
  242,   15,  210,   61,   93,  114,   37,   21,  250,   59,
  119,   42,   43,   59,   45,   33,   47,   41,  205,   59,
  207,   37,   40,   59,  232,   41,   42,   43,   93,   45,
   44,   47,   59,   40,  242,  144,  145,  146,  147,  148,
   59,   61,  250,   59,   41,   33,  233,  234,  235,  236,
   59,   41,   40,   33,   41,   93,  123,   11,   41,   59,
   40,  123,  257,  258,   33,  260,  261,  262,  263,  264,
   59,   40,   33,  276,   41,   44,   30,   59,   32,   40,
   59,   59,   36,   33,   59,   39,   59,   59,   42,   43,
   40,   37,   41,  258,   41,   41,   42,   43,   41,   45,
  276,   47,   41,   41,   41,   41,  120,  121,   41,   21,
  106,  214,   44,   59,  167,   68,  252,  257,  258,  243,
   44,   -1,   -1,  257,  258,   -1,  260,  261,  262,  263,
  264,  258,   93,   -1,   -1,   -1,   -1,  151,   -1,   -1,
   -1,   -1,   -1,   -1,  278,  257,  258,   -1,  260,  261,
  262,  263,  264,  287,  288,  289,  290,  291,  292,  258,
  294,  295,   -1,  177,   -1,   -1,  278,  294,  295,  294,
  295,  296,  297,  298,  299,  300,   -1,  258,  192,   -1,
   -1,   -1,  294,  295,  258,   -1,   -1,   -1,  287,  288,
  289,  290,  291,  292,   -1,  258,   -1,   -1,   -1,   -1,
   -1,  155,  156,  157,  158,   -1,  287,  288,  289,  290,
  291,  292,   -1,  287,  288,  289,  290,  291,  292,   -1,
   -1,   -1,   -1,   -1,  287,  288,  289,  290,  291,  292,
   -1,   -1,   -1,  287,  288,  289,  290,  291,  292,  257,
  258,   -1,  260,  261,  262,  263,  264,   -1,   -1,   -1,
   -1,   -1,  270,   -1,  208,   -1,   -1,   -1,   -1,   -1,
  278,  279,  280,  281,  282,  283,  284,  285,  286,  257,
  258,  259,  260,  261,  262,  263,  264,  257,  258,  259,
  260,  261,  262,  263,  264,   -1,   -1,   -1,  257,  258,
  278,  260,  261,  262,  263,  264,  257,  258,  278,  260,
  261,  262,  263,  264,   -1,   -1,   -1,  257,  258,  278,
  260,  261,  262,  263,  264,   -1,    8,  278,   -1,   11,
   -1,   -1,   -1,   15,   -1,   17,   -1,   -1,  278,   21,
   -1,   -1,   -1,  257,  258,   -1,  260,  261,   30,   -1,
   32,   -1,   -1,   -1,   36,   37,  270,   39,   -1,   -1,
   42,   43,   44,   -1,   46,  279,  280,  281,  282,  283,
  284,  285,  286,   -1,   -1,   57,  257,  258,   -1,  260,
  261,   -1,   -1,   -1,   -1,   -1,   -1,   69,  269,  270,
   -1,   73,   -1,   -1,   -1,   -1,   -1,   79,  279,  280,
  281,  282,  283,  284,  285,  286,   -1,   -1,   -1,   -1,
   -1,   93,   -1,   -1,   -1,   20,   21,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  106,   -1,   -1,  123,   -1,  125,
   -1,   -1,  114,   -1,   -1,   -1,   -1,  119,  120,  121,
   -1,   -1,   -1,   -1,   49,   50,   -1,   -1,   -1,   -1,
  132,   -1,   -1,   58,   59,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  144,  145,  146,  147,  148,   72,   -1,  151,
  152,   -1,   -1,  155,  156,  157,  158,   -1,   -1,   -1,
   -1,  163,   -1,   -1,   -1,   -1,  123,   92,   -1,   -1,
   -1,   -1,   -1,   -1,  176,  177,  101,  102,  103,  104,
  105,   -1,  107,  108,   -1,   -1,  188,  189,   -1,   -1,
  192,   -1,  194,  195,   -1,   -1,  123,   -1,   -1,  201,
  202,   -1,  127,  205,   -1,  207,  208,   -1,  210,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  141,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  230,   -1,
  232,  233,  234,  235,  236,   -1,   -1,   -1,   -1,   -1,
  242,  257,  258,  168,  260,  261,   -1,   -1,  250,  257,
  258,  267,  260,  261,  270,   -1,  272,  273,  274,  275,
  185,  277,  270,  279,  280,  281,  282,  283,  284,  285,
  286,  279,  280,  281,  282,  283,  284,  285,  286,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  220,  221,  222,  223,  224,
  257,  258,   -1,  260,  261,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  270,   -1,  272,  273,  274,  275,   -1,
  277,   -1,  279,  280,  281,  282,  283,  284,  285,  286,
  257,  258,   -1,  260,  261,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  270,   -1,  272,  273,  274,  275,   -1,
  277,   -1,  279,  280,  281,  282,  283,  284,  285,  286,
  257,  258,   -1,  260,  261,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  270,   -1,  272,  273,  274,  275,   -1,
  277,   -1,  279,  280,  281,  282,  283,  284,  285,  286,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 300
#define YYUNDFTOKEN 336
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,0,"'%'",0,0,"'('","')'","'*'","'+'","','","'-'","'.'","'/'",0,0,0,0,0,
0,0,0,0,0,0,"';'",0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"INT","IDENTIFIER","STRING","DOUBLE",
"FLOATL","TRUE","FALSE","THIS","HEADER","IMPORTS","PUBLIC","CLASS","STATIC",
"VOID","MAIN","RET","SOPLN","SOP","IFS","ELSEQ","FORS","NEW","INTA","BOOL",
"BOOLA","CHARL","STR","STRA","FLOATLA","DOUBLEA","ANDAND","OROR","LESS",
"LESSEQ","GREAT","GREATEQ","SEMI","PLUSPLUS","MINUSMINUS","PLUSEQ","MINUSEQ",
"MULEQ","DIVEQ","MODEQ",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : Start",
"Start : Header MainClass",
"Header : IMPORTS HEADER ';'",
"MainClass : PUBLIC CLASS Identifier '{' Statements",
"Statements : CompoundStatement",
"Main : PUBLIC STATIC Type MAIN Args ')' '{' StatementsWOMethod",
"CompoundStatement : '{' CompoundStatement",
"CompoundStatement : Statement",
"CompoundStatement : Main CompoundStatement",
"CompoundStatement : MethodDeclaration CompoundStatement",
"CompoundStatement : '}'",
"Statement : Ifelse",
"Statement : StatementOther",
"StatementOther : Assignment CompoundStatement",
"StatementOther : RET Identifier ';' '}'",
"StatementOther : SOPLN '(' Expression ')' ';' CompoundStatement",
"StatementOther : SOPLN '(' STRING ')' ';' CompoundStatement",
"StatementOther : SOP '(' Expression ')' ';' CompoundStatement",
"StatementOther : SOP '(' STRING ')' ';' CompoundStatement",
"StatementOther : Identifier '[' Expression ']' '=' Expression ';' CompoundStatement",
"StatementOther : VarDeclaration CompoundStatement",
"StatementOther : For CompoundStatement",
"StatementsWOMethod : '{' Statement CompoundStatement",
"StatementsWOMethod : Statement",
"MethodDeclaration : PUBLIC MethodExtend",
"MethodDeclaration : PUBLIC STATIC MethodExtend",
"MethodExtend : Type Identifier '(' Args ')' '{' StatementsWOMethod ';'",
"Args : Type Identifier Args",
"Args : ',' Type Identifier Args",
"Args :",
"Assignment : Identifier '=' AExpression ';'",
"Assignment : Type Identifier '=' AExpression ';'",
"VarDeclaration : Type Identifier ';'",
"Ifelse : IFS Expression ')' ifm1 StatementsWOMethod",
"Ifelse : IFS Expression ')' ifm1 '{' Statement ifm2 Else",
"Else : ELSEQ ifm2 StatementsWOMethod",
"ifm1 :",
"ifm2 :",
"For : FORS Expression form1 ';' Expression form2 ';' IncDec ')' form3 StatementsWOMethod form4",
"For : FORS Assignment form1 Expression ';' form2 IncDec ')' form3 StatementsWOMethod form4",
"form1 :",
"form2 :",
"form3 :",
"form4 :",
"IncDec : Identifier PLUSPLUS ';' IncDec",
"IncDec : Identifier MINUSMINUS ';' IncDec",
"IncDec : PLUSPLUS Identifier ';' IncDec",
"IncDec : MINUSMINUS Identifier ';' IncDec",
"IncDec : SAssignment IncDec",
"IncDec : Identifier PLUSPLUS",
"IncDec : Identifier MINUSMINUS",
"IncDec : PLUSPLUS Identifier",
"IncDec : MINUSMINUS Identifier",
"IncDec : SAssignment",
"SAssignment : SHORTHAND ';'",
"SAssignment : SHORTHAND",
"SHORTHAND : Identifier PLUSEQ Expression",
"SHORTHAND : Identifier MINUSEQ Expression",
"SHORTHAND : Identifier MULEQ Expression",
"SHORTHAND : Identifier DIVEQ Expression",
"SHORTHAND : Identifier MODEQ Expression",
"Expression : Identifier '[' Expression ']'",
"Expression : Symbol '+' Expression",
"Expression : Symbol '-' Expression",
"Expression : Symbol '*' Expression",
"Expression : Symbol '/' Expression",
"Expression : Symbol '%' Expression",
"Expression : Symbol Operators Symbol",
"Expression : Identifier '.' Identifier '(' ManyExpression ')'",
"Expression : NEW INT '[' Expression ']'",
"Expression : NEW Identifier '(' ')'",
"Expression : '!' Expression",
"Expression : '(' Expression ')'",
"Expression : Symbol",
"AExpression : ASymbol '+' AExpression",
"AExpression : ASymbol '-' AExpression",
"AExpression : ASymbol '*' AExpression",
"AExpression : ASymbol '/' AExpression",
"AExpression : ASymbol '%' AExpression",
"AExpression : Identifier",
"AExpression : '(' AExpression ')'",
"AExpression : INT",
"ManyExpression : Expression ManyExpression",
"ManyExpression : ',' Expression ManyExpression",
"ManyExpression :",
"ASymbol : INT",
"ASymbol : Identifier",
"Symbol : INT",
"Symbol : DOUBLE",
"Symbol : FLOATL",
"Symbol : TRUE",
"Symbol : FALSE",
"Symbol : Identifier",
"Symbol : THIS",
"Type : VOID",
"Type : INTA",
"Type : INT",
"Type : BOOL",
"Type : BOOLA",
"Type : Identifier",
"Type : Identifier '[' ']'",
"Type : CHARL",
"Type : STR",
"Type : STRA",
"Type : FLOATL",
"Type : FLOATLA",
"Type : DOUBLE",
"Type : DOUBLEA",
"Operators : ANDAND",
"Operators : LESS",
"Operators : LESSEQ",
"Operators : GREAT",
"Operators : GREATEQ",
"Operators : OROR",
"Identifier : IDENTIFIER",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 252 "JavaMiniParser.y"
int yyerror(char* s){
	printf ("Damn it is a %s\n", s);
	return 1;
}
int yywrap(){
	return 1;
}
int main(int argc,char* argv[]){
	yyin = fopen("input.txt","r");
	yyout = fopen("intermediatecode.txt","w");
	yyparse();
	return 0;
}


void push(char *s){
	strcpy(st[++top],s);
}


void icg(){
	strcpy(temp,"t");
	strcat(temp,i_);
	fprintf(yyout,"%s=%s%s%s\n",temp,st[top-2],st[top-1],st[top]);
	top-=2;
	strcpy(st[top],temp);
}

void icg_ax(){
	/*strcpy(temp2,"");
	strcat(temp2,st[top-2]);
	strcat(temp2,st[top]);
	strcat(temp2,st[top-1]);
	//printf("~~%s\n",temp2);*/
	strcpy(temp,"t");
	strcat(temp,i_);
	fprintf(yyout,"%s=%s%s%s\n",temp,st[top-2],st[top],st[top-1]);
	top-=2;
	strcpy(st[top],temp);
}

void icg_op(){
	//strcpy(temp,"t");
	//strcat(temp,i_);
	//printf("%s=%s%s%s\n",temp,st[top-2],st[top-1],st[top]);
	strcpy(temp2,"");
	strcat(temp2,st[top-2]);
	strcat(temp2,st[top-1]);
	strcat(temp2,st[top]);
	top-=2;
	strcpy(st[top],temp2);
}


void icg_single(){
	fprintf(yyout,"%s=%s%s%d\n",st[top-1],st[top-1],st[top],1);
	//printf("%s=%s\n",st[top-1],temp);
	top-=2;
	strcpy(st[top],temp);
}

void icg_eq(){
	//strcpy(temp,"t");
	//strcat(temp,i_);
	fprintf(yyout,"%s=%s\n",st[top-2],st[top]);
	top-=2;
	//strcpy(st[top],temp);
	//i_[0]++;
}

void icg_eqop(){
	strcpy(temp,"t");
	strcat(temp,i_);
	fprintf(yyout,"%s = %s\n",st[top-2],st[top]);
	top-=2;
	strcpy(st[top],temp);
	i_[0]++;
}

void icg_ax_eq(){
	//strcpy(temp,"t");
	//strcat(temp,i_);
	fprintf(yyout,"%s=%s\n",st[top],st[top-1]);
	top-=2;
	//strcpy(st[top],temp);
	//i_[0]++;
}


//LABELS

void lab1()
{
 lnum++;
 //strcpy(temp,"t");
 //strcat(temp,i_);
 //printf("%s = %s\n",temp,st[top]);
 fprintf(yyout,"ifFalse %s goto l%d\n",temp,lnum);
 i_[0]++;
 label[++ltop]=lnum;
}


void lab2()
{
int x;
lnum++;
x=label[ltop--];
fprintf(yyout,"goto l%d\n",lnum);
fprintf(yyout,"l%d:",x);
label[++ltop]=lnum;
}


void lab3()
{
int y;
y=label[ltop--];
fprintf(yyout,"l%d:",y);

}


void label1_for()
{
	lnum++;
	fprintf(yyout,"l%d:",lnum);
	label[++ltop]=lnum;
}

void label2_for()
{
    //strcpy(temp,"t");
    //strcat(temp,i_);
    //printf("%s = %s\n",temp,st[top]);
    lnum++;
    fprintf(yyout,"ifFalse %s goto l%d\n",st[top],lnum);
    i_[0]++;
    label[++ltop]=lnum;
    //lnum++;
    //printf("goto l%d\n",lnum);
    //label[++ltop]=lnum;
    //printf("l%d: \n",++lnum);
 }
void label3_for()
{
    int x;
    //x=label[ltop--];
    //printf("goto l%d \n",start);
    //printf("l%d:",x);
   
}

void label4_for()
{
    int x;
    x=label[ltop--];
    fprintf(yyout,"goto l%d \n",label[ltop]);
    x = label[ltop--];   
    fprintf(yyout,"l%d:",lnum);
}
























#line 799 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 48 "JavaMiniParser.y"
	{printf("Correct Syntax\n");}
break;
case 10:
#line 62 "JavaMiniParser.y"
	{	if(forflag > 0 && ifflag ==0){
		label4_for();forflag-=1;
	} 
	else{ 
		if(ifflag > 0 && forflag == 0){
			/*lab3();*/
			/*printf("end else/single if\n"); */
			if(!elf);
			else{ lab3(); elf = 0;}
			ifflag-=1;
			} 
		else{
			if(ifflag < forflag){
				lab3();
				/*printf("end else/single if\n");*/
				if(!elf);
				else {lab3(); elf = 0;}
				forflag -= ifflag;
				ifflag = ifflag - forflag - 1;
			}
			else{
				if(ifflag > forflag){
					label4_for();
					ifflag -= forflag;
					forflag = forflag - ifflag - 1;
				}
			}
		}
	}
       }
break;
case 30:
#line 123 "JavaMiniParser.y"
	{ addValue(yystack.l_mark[-1].intval); push(find_name(yystack.l_mark[-3].intval)); 
					   	if(ifflag>0 || forflag > 0){icg_ax_eq();}
					   	else{ push("="); tp = yystack.l_mark[-1].intval; sprintf(stp,"%d",tp); push(stp);  icg_eq();}
					   }
break;
case 31:
#line 127 "JavaMiniParser.y"
	{ addValue(yystack.l_mark[-1].intval); push(find_name(yystack.l_mark[-3].intval)); push("="); tp = yystack.l_mark[-1].intval; sprintf(stp,"%d",tp); push(stp);  icg_eq();}
break;
case 36:
#line 141 "JavaMiniParser.y"
	{lab1();ifflag = 1 + forflag;}
break;
case 37:
#line 144 "JavaMiniParser.y"
	{ifflag = 1 + forflag;elf=1;lab2();}
break;
case 40:
#line 151 "JavaMiniParser.y"
	{label1_for();forflag = 1 + ifflag;}
break;
case 41:
#line 154 "JavaMiniParser.y"
	{label2_for();}
break;
case 42:
#line 157 "JavaMiniParser.y"
	{label3_for();}
break;
case 43:
#line 160 "JavaMiniParser.y"
	{}
break;
case 44:
#line 165 "JavaMiniParser.y"
	{push(find_name(yystack.l_mark[-3].intval)); push("+"); icg_single();}
break;
case 45:
#line 166 "JavaMiniParser.y"
	{push(find_name(yystack.l_mark[-3].intval)); push("+"); icg_single();}
break;
case 46:
#line 167 "JavaMiniParser.y"
	{push(find_name(yystack.l_mark[-2].intval)); push("+"); icg_single();}
break;
case 47:
#line 168 "JavaMiniParser.y"
	{push(find_name(yystack.l_mark[-2].intval)); push("+"); icg_single();}
break;
case 49:
#line 170 "JavaMiniParser.y"
	{push(find_name(yystack.l_mark[-1].intval)); push("+"); icg_single();}
break;
case 50:
#line 171 "JavaMiniParser.y"
	{push(find_name(yystack.l_mark[-1].intval)); push("+"); icg_single();}
break;
case 51:
#line 172 "JavaMiniParser.y"
	{push(find_name(yystack.l_mark[0].intval)); push("+"); icg_single();}
break;
case 52:
#line 173 "JavaMiniParser.y"
	{push(find_name(yystack.l_mark[0].intval)); push("+"); icg_single();}
break;
case 56:
#line 179 "JavaMiniParser.y"
	{push(find_name(yystack.l_mark[-2].intval)); push("+"); push(yystack.l_mark[0].stringval); icg_eqop();}
break;
case 57:
#line 180 "JavaMiniParser.y"
	{push(find_name(yystack.l_mark[-2].intval)); push("-"); push(yystack.l_mark[0].stringval); icg_eqop();}
break;
case 58:
#line 181 "JavaMiniParser.y"
	{push(find_name(yystack.l_mark[-2].intval)); push("*"); push(yystack.l_mark[0].stringval); icg_eqop();}
break;
case 59:
#line 182 "JavaMiniParser.y"
	{push(find_name(yystack.l_mark[-2].intval)); push("/"); push(yystack.l_mark[0].stringval); icg_eqop();}
break;
case 60:
#line 183 "JavaMiniParser.y"
	{push(find_name(yystack.l_mark[-2].intval)); push("%"); push(yystack.l_mark[0].stringval); icg_eqop();}
break;
case 62:
#line 186 "JavaMiniParser.y"
	{push(yystack.l_mark[-2].stringval);push("+");push(yystack.l_mark[0].stringval);icg();}
break;
case 63:
#line 187 "JavaMiniParser.y"
	{push(yystack.l_mark[-2].stringval);push("-");push(yystack.l_mark[0].stringval);icg();}
break;
case 64:
#line 188 "JavaMiniParser.y"
	{push(yystack.l_mark[-2].stringval);push("*");push(yystack.l_mark[0].stringval);icg();}
break;
case 65:
#line 189 "JavaMiniParser.y"
	{push(yystack.l_mark[-2].stringval);push("/");push(yystack.l_mark[0].stringval);icg();}
break;
case 66:
#line 190 "JavaMiniParser.y"
	{push(yystack.l_mark[-2].stringval);push("%");push(yystack.l_mark[0].stringval);icg();}
break;
case 67:
#line 191 "JavaMiniParser.y"
	{push(yystack.l_mark[-2].stringval);push(yystack.l_mark[-1].stringval);push(yystack.l_mark[0].stringval);icg_op();}
break;
case 72:
#line 196 "JavaMiniParser.y"
	{yyval.stringval = yystack.l_mark[-1].stringval;}
break;
case 73:
#line 197 "JavaMiniParser.y"
	{yyval.stringval = yystack.l_mark[0].stringval;}
break;
case 74:
#line 200 "JavaMiniParser.y"
	{yyval.intval = yystack.l_mark[-2].intval + yystack.l_mark[0].intval ;   if(ifflag>0 || forflag > 0){push("+");icg_ax();}   else{;}    }
break;
case 75:
#line 201 "JavaMiniParser.y"
	{yyval.intval = yystack.l_mark[-2].intval - yystack.l_mark[0].intval ; if(ifflag>0 || forflag > 0){push("-");icg_ax();}   else{;}  }
break;
case 76:
#line 202 "JavaMiniParser.y"
	{yyval.intval = yystack.l_mark[-2].intval * yystack.l_mark[0].intval ; if(ifflag>0 || forflag > 0){push("*");icg_ax();}   else{;}  }
break;
case 77:
#line 203 "JavaMiniParser.y"
	{yyval.intval = yystack.l_mark[-2].intval / yystack.l_mark[0].intval ; if(ifflag>0 || forflag > 0){push("/");icg_ax();}   else{;}  }
break;
case 78:
#line 204 "JavaMiniParser.y"
	{yyval.intval = yystack.l_mark[-2].intval % yystack.l_mark[0].intval; if(ifflag>0 || forflag > 0){push("%");icg_ax();}   else{;}  }
break;
case 79:
#line 205 "JavaMiniParser.y"
	{yyval.intval = retrieve(find_name(yystack.l_mark[0].intval)); if(ifflag>0 || forflag > 0){push(find_name(yystack.l_mark[0].intval));}  }
break;
case 80:
#line 206 "JavaMiniParser.y"
	{yyval.intval= yystack.l_mark[-1].intval ;}
break;
case 81:
#line 207 "JavaMiniParser.y"
	{yyval.intval = yystack.l_mark[0].intval ;   if(ifflag>0 || forflag > 0){tp = yystack.l_mark[0].intval; sprintf(stp,"%d",tp);push(stp);}   }
break;
case 85:
#line 214 "JavaMiniParser.y"
	{yyval.intval = yystack.l_mark[0].intval ; if(ifflag>0 || forflag > 0){tp = yystack.l_mark[0].intval; sprintf(stp,"%d",tp);push(stp);} }
break;
case 86:
#line 215 "JavaMiniParser.y"
	{yyval.intval = retrieve(find_name(yystack.l_mark[0].intval)); if(ifflag>0 || forflag > 0){push(find_name(yystack.l_mark[0].intval));} }
break;
case 87:
#line 218 "JavaMiniParser.y"
	{tp = yystack.l_mark[0].intval; sprintf(stp,"%d",tp); yyval.stringval = stp;}
break;
case 88:
#line 219 "JavaMiniParser.y"
	{yyval.stringval = yystack.l_mark[0].stringval;}
break;
case 89:
#line 220 "JavaMiniParser.y"
	{yyval.stringval = yystack.l_mark[0].stringval;}
break;
case 90:
#line 221 "JavaMiniParser.y"
	{yyval.stringval = yystack.l_mark[0].stringval;}
break;
case 91:
#line 222 "JavaMiniParser.y"
	{yyval.stringval = yystack.l_mark[0].stringval;}
break;
case 92:
#line 223 "JavaMiniParser.y"
	{yyval.stringval = find_name(yystack.l_mark[0].intval);}
break;
case 93:
#line 224 "JavaMiniParser.y"
	{yyval.stringval = yystack.l_mark[0].stringval;}
break;
case 108:
#line 242 "JavaMiniParser.y"
	{yyval.stringval = "&&";}
break;
case 109:
#line 243 "JavaMiniParser.y"
	{yyval.stringval = "<";}
break;
case 110:
#line 244 "JavaMiniParser.y"
	{yyval.stringval = "<=";}
break;
case 111:
#line 245 "JavaMiniParser.y"
	{yyval.stringval = ">";}
break;
case 112:
#line 246 "JavaMiniParser.y"
	{yyval.stringval = ">=";}
break;
case 113:
#line 247 "JavaMiniParser.y"
	{yyval.stringval = "||";}
break;
case 114:
#line 249 "JavaMiniParser.y"
	{yyval.intval = yystack.l_mark[0].intval;}
break;
#line 1253 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
