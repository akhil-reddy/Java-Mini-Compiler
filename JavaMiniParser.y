%{
	#include<stdio.h>
	#include<ctype.h>
	#include<string.h>
	#include<stdlib.h>
	//#include "JavaMiniCompiler.c"
	//extern struct SymbolTable *table;
	//extern abc* table;
	//extern int no_of_entries;
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
%}
%start Start
%expect 1
%union{
	char* type;
	int intval;
	int id;
	char* identifier;
	float floatval;
	char* stringval;	
};
%type <intval> INT Assignment Identifier IDENTIFIER ASymbol
%type <intval> AExpression
%type <stringval> STRING Expression Symbol DOUBLE FLOATL TRUE FALSE THIS Operators
%token STRING IDENTIFIER HEADER IMPORTS PUBLIC CLASS STATIC VOID MAIN RET SOPLN SOP IFS ELSEQ FORS NEW INT TRUE FALSE THIS INTA BOOL BOOLA CHARL STR STRA FLOATL FLOATLA DOUBLE DOUBLEA ANDAND OROR LESS LESSEQ GREAT GREATEQ SEMI PLUSPLUS MINUSMINUS PLUSEQ MINUSEQ MULEQ DIVEQ MODEQ

%%
Start: Header MainClass {printf("Correct Syntax\n");};

Header: IMPORTS HEADER ';'	;

MainClass: PUBLIC CLASS Identifier '{' Statements 	;

Statements: CompoundStatement ;

Main:PUBLIC STATIC Type  MAIN  Args ')' '{' StatementsWOMethod  	;

CompoundStatement: '{' CompoundStatement
| Statement
| Main CompoundStatement
| MethodDeclaration CompoundStatement
| '}' {	if(forflag > 0 && ifflag ==0){
		label4_for();forflag-=1;
	} 
	else{ 
		if(ifflag > 0 && forflag == 0){
			//lab3();
			//printf("end else/single if\n"); 
			if(!elf);
			else{ lab3(); elf = 0;}
			ifflag-=1;
			} 
		else{
			if(ifflag < forflag){
				lab3();
				//printf("end else/single if\n");
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
;

Statement: Ifelse 
| StatementOther ;

StatementOther: Assignment CompoundStatement 
| RET Identifier ';' '}'
| SOPLN '(' Expression ')' ';' CompoundStatement
| SOPLN '(' STRING ')' ';' CompoundStatement
| SOP '(' Expression ')' ';' CompoundStatement
| SOP '(' STRING ')' ';' CompoundStatement
| Identifier '[' Expression ']' '=' Expression ';' CompoundStatement
| VarDeclaration CompoundStatement
| For CompoundStatement
;

StatementsWOMethod: '{' Statement CompoundStatement 
| Statement
;

MethodDeclaration: PUBLIC MethodExtend
| PUBLIC STATIC MethodExtend
;

MethodExtend: Type Identifier '(' Args ')' '{' StatementsWOMethod ';'  	;

Args: Type Identifier Args
| ',' Type Identifier Args
|
;

Assignment: Identifier '=' AExpression ';' { addValue($3); push(find_name($1)); 
					   	if(ifflag>0 || forflag > 0){icg_ax_eq();}
					   	else{ push("="); tp = $3; sprintf(stp,"%d",tp); push(stp);  icg_eq();}
					   }
| Type Identifier '=' AExpression ';' { addValue($4); push(find_name($2)); push("="); tp = $4; sprintf(stp,"%d",tp); push(stp);  icg_eq();}   
;



VarDeclaration: Type Identifier ';'  ;

Ifelse: IFS Expression ')' ifm1 StatementsWOMethod
| IFS Expression ')' ifm1 '{' Statement ifm2 Else
;

Else: ELSEQ ifm2 StatementsWOMethod 
;

ifm1:	{lab1();ifflag = 1 + forflag;}
   ;

ifm2:	{ifflag = 1 + forflag;elf=1;lab2();}//ifflag = 1 + forflag;elf = 1;
   ;

For: FORS Expression form1 ';' Expression form2 ';' IncDec ')' form3 StatementsWOMethod form4 
| FORS Assignment form1 Expression ';' form2 IncDec ')' form3 StatementsWOMethod form4
;

form1: {label1_for();forflag = 1 + ifflag;}
     ;

form2: {label2_for();}
     ;

form3: {label3_for();}
     ;
      
form4: {}//label4_for();}
     ;  



IncDec: Identifier PLUSPLUS ';' IncDec {push(find_name($1)); push("+"); icg_single();}
| Identifier MINUSMINUS ';' IncDec {push(find_name($1)); push("+"); icg_single();}
| PLUSPLUS Identifier ';' IncDec {push(find_name($2)); push("+"); icg_single();}
| MINUSMINUS Identifier  ';' IncDec {push(find_name($2)); push("+"); icg_single();}
| SAssignment IncDec //{tp = $1; sprintf(stp,"%d",tp); push(stp); push("+"); icg_single();}
| Identifier PLUSPLUS {push(find_name($1)); push("+"); icg_single();}
| Identifier MINUSMINUS {push(find_name($1)); push("+"); icg_single();}
| PLUSPLUS Identifier {push(find_name($2)); push("+"); icg_single();}
| MINUSMINUS Identifier {push(find_name($2)); push("+"); icg_single();}
| SAssignment 
;
SAssignment: SHORTHAND ';' 
| SHORTHAND 
;
SHORTHAND: Identifier PLUSEQ Expression {push(find_name($1)); push("+"); push($3); icg_eqop();}
| Identifier MINUSEQ Expression {push(find_name($1)); push("-"); push($3); icg_eqop();}
| Identifier MULEQ Expression {push(find_name($1)); push("*"); push($3); icg_eqop();}
| Identifier DIVEQ Expression {push(find_name($1)); push("/"); push($3); icg_eqop();}
| Identifier MODEQ Expression {push(find_name($1)); push("%"); push($3); icg_eqop();}
;
Expression: Identifier '[' Expression ']' 
| Symbol '+' Expression {push($1);push("+");push($3);icg();}
| Symbol '-' Expression {push($1);push("-");push($3);icg();}
| Symbol '*' Expression {push($1);push("*");push($3);icg();}
| Symbol '/' Expression {push($1);push("/");push($3);icg();}
| Symbol '%' Expression {push($1);push("%");push($3);icg();}
| Symbol Operators Symbol {push($1);push($2);push($3);icg_op();}
| Identifier '.' Identifier '(' ManyExpression ')' 
| NEW INT '[' Expression ']' 
| NEW Identifier '(' ')' 
| '!' Expression 
| '(' Expression ')'	{$$ = $2;}
| Symbol {$$ = $1;}
;

AExpression: ASymbol '+' AExpression {$$ = $1 + $3 ;   if(ifflag>0 || forflag > 0){push("+");icg_ax();}   else{;}    }
| ASymbol '-' AExpression {$$ = $1 - $3 ; if(ifflag>0 || forflag > 0){push("-");icg_ax();}   else{;}  }
| ASymbol '*' AExpression {$$ = $1 * $3 ; if(ifflag>0 || forflag > 0){push("*");icg_ax();}   else{;}  }
| ASymbol '/' AExpression {$$ = $1 / $3 ; if(ifflag>0 || forflag > 0){push("/");icg_ax();}   else{;}  }
| ASymbol '%' AExpression {$$ = $1 % $3; if(ifflag>0 || forflag > 0){push("%");icg_ax();}   else{;}  }
| Identifier  {$$ = retrieve(find_name($1)); if(ifflag>0 || forflag > 0){push(find_name($1));}  }
| '(' AExpression ')'	{$$= $2 ;}
| INT {$$ = $1 ;   if(ifflag>0 || forflag > 0){tp = $1; sprintf(stp,"%d",tp);push(stp);}   }
;

ManyExpression: Expression ManyExpression
| ',' Expression ManyExpression
|
;
ASymbol: INT  {$$ = $1 ; if(ifflag>0 || forflag > 0){tp = $1; sprintf(stp,"%d",tp);push(stp);} }
| Identifier {$$ = retrieve(find_name($1)); if(ifflag>0 || forflag > 0){push(find_name($1));} }
;

Symbol: INT {tp = $1; sprintf(stp,"%d",tp); $$ = stp;}
| DOUBLE {$$ = $1;}
| FLOATL {$$ = $1;}
| TRUE {$$ = $1;}
| FALSE {$$ = $1;}
| Identifier {$$ = find_name($1);}
| THIS  {$$ = $1;}
;

Type: VOID
| INTA 
| INT
| BOOL 
| BOOLA
| Identifier 
| Identifier '[' ']'
| CHARL
| STR 
| STRA	
| FLOATL
| FLOATLA
| DOUBLE 
| DOUBLEA 	;

Operators: ANDAND {$$ = "&&";}
| LESS {$$ = "<";}
| LESSEQ {$$ = "<=";}
| GREAT {$$ = ">";}
| GREATEQ {$$ = ">=";}
| OROR {$$ = "||";}	;

Identifier: IDENTIFIER {$$ = $1;}	;

%%
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
























