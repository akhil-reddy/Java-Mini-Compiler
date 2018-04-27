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
extern YYSTYPE yylval;
