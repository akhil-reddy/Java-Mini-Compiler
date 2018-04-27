%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	#include "JavaMiniCompiler.c"
	char* constantfolding(char*);
	char* constantpropogation(char*);
	char* addname(char*);
	char* addvalue(char*);
	char* retrievevalue(char*);
	char* result;
	struct variables{
		char* name;
		char* value;
	};
	int fold=1;
	struct variables* variables=NULL;
	int nvar=0;
	void addtostack(char*);
	void checkfold(char*);
	struct labelstack{
		char* label;
	};
	int nlstack=0;
	struct labelstack* stack;
	char* rchr=NULL;
%}
%%
[a-zA-Z0-9]+[=][a-zA-Z]+													{char* token=strtok(yytext,"=");fprintf(yyout,"%s=",addname(token));token=strtok(NULL,"=");if(fold){fprintf(yyout,"%s",addvalue(retrievevalue(token)));}else{fprintf(yyout,"%s",token);}}
[a-zA-Z0-9]+[=][0-9]+(\.)?[0-9]*											{char* token=strtok(yytext,"=");fprintf(yyout,"%s=",addname(token));token=strtok(NULL,"=");fprintf(yyout,"%s",addvalue(token));}
[a-zA-Z0-9]+[=][0-9\.]+([+\-*%/][0-9\.]+)+									{char* token=strtok(yytext,"=");fprintf(yyout,"%s=",addname(token));token=strtok(NULL,"=");if(fold){fprintf(yyout,"%s",addvalue(constantfolding(token)));}else{fprintf(yyout,"%s",token);}}
[a-zA-Z0-9]+[=][a-zA-Z0-9\.]+([+\-*%/][a-zA-Z0-9\.]+)+						{char* token=strtok(yytext,"=");fprintf(yyout,"%s=",addname(token));token=strtok(NULL,"=");if(fold){fprintf(yyout,"%s",addvalue(constantpropogation(token)));}else{fprintf(yyout,"%s",token);}}
ifFalse(.)*																	{fprintf(yyout,"%s",yytext);addtostack(yytext);}
l[0-9]+																		{fprintf(yyout,"%s",yytext);checkfold(yytext);}
.																			{fprintf(yyout,"%s",yytext);}
%%
void addtostack(char* yytext){
	char* temp=strrchr(yytext,' ');
	stack=realloc(stack,(++nlstack)*sizeof(struct labelstack));
	stack[nlstack-1].label=strdup(temp+1);
	fold=0;
}
void checkfold(char* yytext){
	if(nlstack){
		if(strpbrk(yytext,stack[nlstack-1].label) != 0){
			fold=1;
		}
	}
}
char* retrievevalue(char* name){
	printf("%s %d\n",name,fold);
	int i=0;
	for(;i<nvar;i++){
		if(strcmp(name,variables[i].name)==0){
			return variables[i].value;
		}
	}
	char* temp=strdup("Variable doesn't exist");
	return temp;
}
char* addname(char* name){
	variables=realloc(variables,(nvar+1)*sizeof(struct variables));
	variables[nvar].name=strdup(name);
	return name;
}
char* addvalue(char* value){
	variables[nvar].value=strdup(value);
	printf("%s = %s\n",variables[nvar].name,variables[nvar].value);
	nvar++;
	return value;
}
int valuei(char* text,int i,int j){
	int res=0;
	int pow=1;
	for(;j>i;j--){
		res+=(text[j-1]-'0')*pow;
		pow*=10;
	}
	return res;
}
char* itoa(int numi,char* result){
	int tempnumi=numi;
	int n=1;
	while((tempnumi=(tempnumi/10))!=0){
		n++;
	}
	tempnumi=numi;
	int i;
	free(result);
	result=malloc(n+1);
	for(i=n-1;i>=0;i--){
		result[i]='0'+tempnumi%10;
		tempnumi/=10;
	}
	result[n]='\0';
	return result;
}
float valuef(char text[],int i,int j){
	char* temptext=malloc(j-i+1);
	temptext[j-i]='\0';
	text+=i;
	strncpy(temptext,text,(j-i));
	char* token=strtok(temptext,".");
	if(strlen(token)==strlen(text)){		// If an integer
		return valuei(text,i,j);
	}
	float res=0;
	int pow=1;
	// Left side of .
	int k=strlen(token)-1;
	for(;k>=0;k--){
		res+=(token[k]-'0')*pow;
		pow*=10;
	}
	// Right side of .
	token=strtok(NULL,".");
	pow=10;
	i=0;
	for(;i<strlen(token);i++){
		float temp=(float)(token[i]-'0')/pow;
		res+=temp;
		pow*=10;
	}
	return res;
}
char* ftoa(float numf,char* result){
	int tempnumi=numf;
	int n=1;
	while((tempnumi=(tempnumi/10))!=0){
		n++;
	}
	tempnumi=numf;
	int i;
	free(result);
	result=malloc(n+1);
	for(i=n-1;i>=0;i--){
		result[i]='0'+tempnumi%10;
		tempnumi/=10;
	}
	result[n]='\0';
	return result;
}
char* constantfolding(char* yytext){
	char* text=strdup(yytext);
	char* token;
	result=NULL;
	text=strtok(text,".");
	if(strlen(text)==strlen(yytext)){
		text=strdup(yytext);
		int i=1;
		while(text[i]<=57 && text[i]>=48){
			i++;
		}
		int numi=valuei(text,0,i);
		for(;text[i];){
			char opr=text[i];
			int k=i+1;
			while(text[k]<=57 && text[k]>=48){
				k++;
			}
			if(opr=='+')	numi+=valuei(text,i+1,k);
			if(opr=='-')	numi-=valuei(text,i+1,k);
			if(opr=='*')	numi*=valuei(text,i+1,k);
			if(opr=='/')	numi/=valuei(text,i+1,k);
			if(opr=='%')	numi%=valuei(text,i+1,k);
			i+=k;
		}

		result=itoa(numi,result);
	}
	else{
		text=strdup(yytext);
		int i=1;
		while(text[i]==46 || (text[i]<=57 && text[i]>=48)){
			i++;
		}
		float numf=valuef(text,0,i);
		for(;text[i];){
			char opr=text[i];
			int k=i+1;
			while(text[k]==46 || (text[k]<=57 && text[k]>=48)){
				k++;
			}
			if(opr=='+')	numf+=valuef(text,i+1,k);
			if(opr=='-')	numf-=valuef(text,i+1,k);
			if(opr=='*')	numf*=valuef(text,i+1,k);
			if(opr=='/')	numf/=valuef(text,i+1,k);
			i+=k;
		}
		result=ftoa(numf,result);
	}
	return result;
}
char* constantpropogation(char* yytext){
	char* propogated=NULL;
	int plen=0;
	int len=strlen(yytext);
	int i;
	char* temp=NULL;
	int tlen=0;
	short flag=1;
	for(i=0;i<len;i++){
		if(yytext[i]=='+' || yytext[i]=='-' || yytext[i]=='*' || yytext[i]=='/' || yytext[i]=='%'){
			if(temp!=NULL){			
				temp=strdup(retrievevalue(temp));
				propogated=realloc(propogated,plen+strlen(temp));
				plen=plen+strlen(temp);
				strcat(propogated,temp);
				free(temp);
				temp=NULL;
				tlen=0;
			}
			propogated=realloc(propogated,++plen);
			propogated[plen-1]=yytext[i];
			flag=1;
			continue;
		}
		else if(flag && yytext[i]<=57 && yytext[i]>=48){
			propogated=realloc(propogated,++plen);
			propogated[plen-1]=yytext[i];
			continue;
		}
		flag=0;
		temp=realloc(temp,++tlen);
		temp[tlen-1]=yytext[i];
		temp[tlen]='\0';
	}
	if(temp!=NULL){				
		temp=strdup(retrievevalue(temp));
		propogated=realloc(propogated,plen+strlen(temp));
		plen=plen+strlen(temp);
		strcat(propogated,temp);
		free(temp);
		temp=NULL;
		tlen=0;
	}
	return constantfolding(propogated);
}
int main(int argc,char** argv){
	yyin = fopen("intermediatecode.txt","r");
	yyout = fopen("constantoptimized.txt","w");
	yylex();
	return 0;
}
int yywrap(){
	return 1;
}