%{
/*	Token numbers and Values
0 - Number
1 - if
2 - else
3 - import
4 - public
5 - class
6 - static 
7 - int
8 - int[]
9 - for
10 - break
11 - continue
12 - instanceof
13 - char
14 - char[]
15 - boolean
16 - boolean[]
17 - float
18 - float[]
19 - byte
20 - byte[]
21 - short
22 - short[]
23 - long
24 - long[]
25 - double
26 - double[]
27 - void
28 - void[]
29 - Semicolon
30 - String
31 - (
32 - )
33 - ==
34 - <
35 - >
36 - !=
37 - <=
38 - >=
39 - +
40 - -
41 - *
42 - /
43 - %
44 - &&
45 - ||
46 - ++
47 - --
48 - =
49 - +=
50 - -=
51 - *=
52 - /=
53 - &
54 - |
55 - ^
56 - ~
57 - ?
58 - <<
59 - >>
60 - >>>
61 - .
62 - ,
63 - [
64 - ]
65 - {
66 - }
67 - return
68 - true
69 - false
72 - this
73 - new
90 - variable or class
91 - function
92 - library
100 onwards - Identifiers
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "y.tab.h"
#include "JavaMiniCompiler.c"
int checktype(char* yytext);
#define STRINGL 30
#define OPENPAR 31
%}
%%
" "																		;
this|new 																{if(!flag){printf("(%d) ",genKeyword(yytext,"-"));return checktype(yytext);}}
public|static|break|continue|instanceof|return|true|false 			{if(!flag){printf("(%d) ",genKeyword(yytext,"-"));return checktype(yytext);}}
class|extends															{if(!flag){printf("(%d) ",genKeyword(yytext,"-"));typeflag=1;prevType=strdup("Class");prevDataType=strdup("-");return checktype(yytext);}}		//Add more like this
import																	{if(!flag){printf("(%d) ",genKeyword(yytext,"-"));prevType=strdup("Library");prevDataType=strdup("-");libFlag=1;return IMPORTS;}}
(int|char|boolean|float|byte|short|long|double|void|String)				{if(!flag){printf("(%d) ",genKeyword(yytext,"-"));typeflag=1;prevType=strdup("Variable");prevDataType=strdup(yytext);if(paramflag){addParam(yytext);}yylval.type=strdup(removeMidSpaces(yytext));return checktype(removeMidSpaces(yytext));}}
(int|char|boolean|float|byte|short|long|double|void|String)[ ]*"[]"		{if(!flag){printf("(%d) ",genKeyword(removeMidSpaces(yytext),"-"));typeflag=1;prevType=strdup("Variable");prevDataType=strdup(removeMidSpaces(yytext));if(paramflag){addParam(removeMidSpaces(yytext));}yylval.type=strdup(removeMidSpaces(yytext));return checktype(removeMidSpaces(yytext));}}
System\.out\.print(ln)?													{if(!flag){printf("(%d) ",genSpecialFunctions(yytext,"-"));return checktype(yytext);}}
["][^"]*["]																{if(!flag){printf("(%d) ",(STRINGL));yylval.stringval = strdup(yytext);return STRING;}}
\/\/.*\n																{if(!flag){printf("\n");}line_no++;}
\/\*																	{if(!flag){flag=1;}}
\*\/																	{flag=0;}
else|[a-zA-Z][a-zA-Z0-9]*[ ]*\(												{if(!flag && typeflag){printf("(%d) (%d) ",addEntry(yytext,prevType,prevDataType,1),OPENPAR);paramflag=1;typeflag=0;}else if(!flag){printf("(%d) (%d) ",addEntry(yytext,"otherID",prevDataType,1),OPENPAR);}if(!flag){yylval.identifier=removeMidSpaces(yytext);return checktype(yytext);}}		
[a-zA-Z][a-zA-Z0-9]*													{if(!flag && typeflag){printf("(%d) ",addEntry(yytext,prevType,prevDataType,0));typeflag=0;}else if(!flag){printf("(%d) ",addEntry(yytext,"otherID",prevDataType,1));}if(!flag){yylval.id = find_id(yytext); return IDENTIFIER;}}
[a-zA-Z.]*[.][*]?															{if(!flag && libFlag){printf("(%d) ",addEntry(yytext,prevType,prevDataType,2));libFlag=0;return HEADER;}else{printf("(%d) ",addEntry(yytext,"otherID",prevDataType,1));return HEADER;}}
[0-9]+																	{if(!flag){printf("(%d) ",hash(yytext));yylval.intval = atoi(yytext); return INT;}}
[0-9]+[.][0-9]+															{if(!flag){printf("(%d) ",hash(yytext));yylval.floatval = atof(yytext); return FLOATL;}}
"=="|"<"|">"|"!="|"<="|">="												{if(!flag){printf("(%d) ",hash(yytext));return checktype(yytext);}}
[+]|[-]|[*]|[%]|[/]														{if(!flag){printf("(%d) ",hash(yytext));return yytext[0];}}
"&&"|"||"																{if(!flag){printf("(%d) ",hash(yytext));return checktype(yytext);}}
\) 																		{if(!flag && paramflag==1){paramflag=0;n_param=0;printf("(%d) ",hash(yytext));return yytext[0];}else if(!flag){printf("(%d) ",hash(yytext));return yytext[0];}}
\+\+|\-\-																{if(!flag){printf("(%d) ",hash(yytext));return checktype(yytext);}}
\=|\+\=|\-\=|\*\=|\/\=													{if(!flag){printf("(%d) ",hash(yytext));return checktype(yytext);}}										
\&|\||\^|\~																{if(!flag){printf("(%d) ",hash(yytext));return yytext[0];}}
\?																		{if(!flag){printf("(%d) ",hash(yytext));return yytext[0];}}
\<\<|\>\>|\>\>\>														{if(!flag){printf("(%d) ",hash(yytext));return checktype(yytext);}}
\.|\(|\,|\{|\}|[;]|\[|\]												{if(!flag){printf("(%d) ",hash(yytext));if(strcmp(yytext,"{")==0){newScope();}if(strcmp(yytext,"}")==0){exitScope();}return yytext[0];}}
\n																		{if(!flag){printf("\n");}line_no++;}
\t   																	{if(!flag){printf("\t");}}
.																		{if(!flag){printf("[%s] ",(yytext));}}
%%

int checktype(char* yytext){
	if(strcmp(yytext,"public")==0) return PUBLIC;
	if(strcmp(yytext,"class")==0) return CLASS;
	if(strcmp(yytext,"static")==0) return STATIC;
	if(strcmp(yytext,"void")==0) return VOID;
	if(strcmp(yytext,"main(")==0) return MAIN;
	if(strcmp(yytext,"return")==0) return RET;
	if(strcmp(yytext,"System.out.println")==0) return SOPLN;
	if(strcmp(yytext,"System.out.print")==0) return SOP;
	if(strcmp(yytext,"if(")==0) return IFS;
	if(strcmp(yytext,"else")==0) return ELSEQ;
	if(strcmp(yytext,"for(")==0) return FORS;
	if(strcmp(yytext,"new")==0) return NEW;
	if(strcmp(yytext,"true")==0) return TRUE;
	if(strcmp(yytext,"false")==0) return FALSE;
	if(strcmp(yytext,"this")==0) return THIS;
	if(strcmp(yytext,"int")==0) return INT;
	if(strcmp(yytext,"int[]")==0) return INTA;
	if(strcmp(yytext,"boolean")==0) return BOOL;
	if(strcmp(yytext,"boolean[]")==0) return BOOLA;
	if(strcmp(yytext,"char")==0) return CHARL;
	if(strcmp(yytext,"string")==0) return STR;
	if(strcmp(yytext,"string[]")==0) return STRA;
	if(strcmp(yytext,"boolean")==0) return BOOL;
	if(strcmp(yytext,"boolean[]")==0) return BOOLA;
	if(strcmp(yytext,"float")==0) return FLOATL;
	if(strcmp(yytext,"float[]")==0) return FLOATLA;
	if(strcmp(yytext,"float")==0) return DOUBLE;
	if(strcmp(yytext,"float[]")==0) return DOUBLEA;
	if(strcmp(yytext,"&&")==0) return ANDAND;
	if(strcmp(yytext,"||")==0) return OROR;
	if(strcmp(yytext,"<")==0) return LESS;
	if(strcmp(yytext,"<=")==0) return LESSEQ;
	if(strcmp(yytext,">")==0) return GREAT;
	if(strcmp(yytext,">=")==0) return GREATEQ;
	if(strcmp(yytext,"++")==0) return PLUSPLUS;
	if(strcmp(yytext,"--")==0) return MINUSMINUS;
	if(strcmp(yytext,"=")==0) return yytext[0];
	if(strcmp(yytext,"+=")==0) return PLUSEQ;
	if(strcmp(yytext,"-=")==0) return MINUSEQ;
	if(strcmp(yytext,"*=")==0) return MULEQ;
	if(strcmp(yytext,"/=")==0) return DIVEQ;
	if(strcmp(yytext,"%=")==0) return MODEQ;
	return IDENTIFIER;
}
