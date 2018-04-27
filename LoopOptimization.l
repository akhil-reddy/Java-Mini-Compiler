%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	struct istack{
		char* label;
		char* ivariable;
	};
	struct istack* istack=NULL;
	int n=0;
	void pushonstack(char*);
	void popstack(char*);
	char* processinduction(char*);
	char* processedtext=NULL;
	int incordec=-1;			// incordec = 1 for incr and 0 for decr
	int k=0;					// K is the k in i=i(+-)k
	int secondlabel=999;		// This label is for the forloop
	int tempvars=0;				// For temp variable
%}
%%
l[0-9]+[:]ifFalse(.)*														{pushonstack(yytext);fprintf(yyout,"%s",yytext);}
goto[ ]*l[0-9]+																{popstack(yytext);fprintf(yyout,"%s",yytext);}		
[a-zA-Z0-9]+[=][a-zA-Z0-9\.]+([+\-*%/][a-zA-Z0-9\.]+)+						{if(n){if(processedtext!=NULL){free(processedtext);processedtext=NULL;}fprintf(yyout,"%s",processinduction(yytext));} else{fprintf(yyout,"%s",yytext);}}
.																			{fprintf(yyout,"%s",yytext);}
%%
void pushonstack(char* yytext){
	char* text=strdup(yytext);
	int len=strlen(text);
	int i=0,flag=0,from=-1,to=-1,tolab=0,fromlab=0;;
	char* tobepushed;
	// Typical string :- l1:ifFalse i<10 goto l8
	for(;i<len;i++){
		if(text[i]==':'){
			i=i+8;
			flag=1;
			continue;
		}
		if(flag && text[i]>=65){
			if(from==-1){
				from=i;
				to=from+1;
			}
			else
				to++;
		}
		else if(flag && text[i]<65){
			break;
		}
		else tolab++;
	} 
	n++;
	if((n-1)==(sizeof(istack)/sizeof(struct istack)))
		istack=(struct istack*)realloc(istack,sizeof(struct istack)*n);
	istack[n-1].label=malloc(tolab-fromlab+1);
	strncpy(istack[n-1].label,yytext+fromlab,tolab-fromlab);
	istack[n-1].label[tolab-fromlab]='\0';
	istack[n-1].ivariable=malloc(to-from+1);
	strncpy(istack[n-1].ivariable,yytext+from,to-from);
	istack[n-1].ivariable[to-from]='\0';
	fprintf(yyout,"temp%d=%s\n",tempvars,istack[n-1].ivariable);
	tempvars++;
}
void popstack(char* yytext){
	//if(strcmp(yytext+5,istack[n-1].label)==0){
	//	n--;
	//}
}
int inductionrequired(char* yytext){
	int len=strlen(yytext);
	int i=0;
	int matched=0;
	int toplen=strlen(istack[n-1].ivariable);
	for(;i<(len-toplen)+1;i++){
		int j;
		for(j=0;j<toplen;j++){
			if(yytext[i+j]!=istack[n-1].ivariable[j])
				break;
		}
		if(j==toplen){
			return 1;
		}
	}
	return 0;
}
char* processinduction(char* yytext){
	// Do induction
	if(inductionrequired(yytext)){

		char* text=strdup(yytext);
		char* token=strtok(text,"*/=");
		if(strcmp(token,istack[n-1].ivariable)==0){
			// strpbrk will check if '-' is there in token
			if(strpbrk(yytext, "-") != 0){	// Minus i=i-k
				token=strtok(NULL,"-");
				token=strtok(NULL,"");
				printf("ivar = %s decremented by %d\n",istack[n-1].ivariable,atoi(token));
				incordec=0;
				k=atoi(token);
				tempvars--;
				fprintf(yyout,"ifFalse %s==temp%d goto l%d\n%s=%s+%d\nl%d:",istack[n-1].ivariable,tempvars,secondlabel,istack[n-1].ivariable,istack[n-1].ivariable,k,secondlabel);
				secondlabel++;
			}
			else{							// Plus i=i+k
				token=strtok(NULL,"+");
				token=strtok(NULL,"");
				printf("ivar = %s incremented by %d\n",istack[n-1].ivariable,atoi(token));
				incordec=1;
				k=atoi(token);
				tempvars--;
				fprintf(yyout,"ifFalse %s==temp%d goto l%d\n%s=%s-%d\nl%d:",istack[n-1].ivariable,tempvars,secondlabel,istack[n-1].ivariable,istack[n-1].ivariable,k,secondlabel);
				secondlabel++;
			}
			return yytext;
		}
		else{
			processedtext=realloc(processedtext,2*strlen(token)+2+10+1);	// 10 for incordec and 1 for the operator + or -
			strcat(processedtext,token);
			strcat(processedtext,"=");
			strcat(processedtext,token);
			if(incordec){
				strcat(processedtext,"+");
			}
			else{
				strcat(processedtext,"-");
			}
			token=strtok(NULL,"*/");
			if(token[0]<=57 && token[0]>=48){
				if(strpbrk(yytext, "*") != 0){
					k=k*atoi(token);
				}
				else{
					k=k/atoi(token);
				}
			}
			token=strtok(NULL,"");
			if(token[0]<=57 && token[0]>=48){
				if(strpbrk(yytext, "*") != 0){
					k=k*atoi(token);
				}
				else{
					k=k/atoi(token);
				}
			}
			char str[10];
			sprintf(str,"%d",k);
			strcat(processedtext,str);
			printf("%s\n",processedtext);
			return processedtext;
		}
	}
	else{
		return yytext;
	}
}
int main(int argc,char** argv){
	yyin = fopen("constantoptimized.txt","r");
	yyout = fopen("finaloptimized.txt","w");
	yylex();
	return 0;
}
int yywrap(){
	return 1;
}