#include "JavaMiniCompiler.h"
char* concat(char* s1, char* s2){
	if(strcmp(s2,"Class")==0)	return s2;
	char* temp=malloc(sizeof(s1)+sizeof(s2)+1);
	strcat(temp,s1);
	strcat(temp,s2);

	return temp;
}
int checkTokenExists(char* token){
	int i=0;
	for(;i<no_of_entries;i++){
		if(strcmp(table[i].name,token)==0 && (table[i].scopeDepth < currScopeDepth)){
			return	table[i].id;
		}
	}	
	return 0;
}
void newScope(){
	currScopeDepth++;
}
void exitScope(){
	currScopeDepth--;
}
int hash(char* token){		// To add support for other functions/ constructs
	if(strcmp(token,"if")==0)			return 1;
	if(strcmp(token,"else")==0)			return 2;
	if(strcmp(token,"import")==0)		return 3;
	if(strcmp(token,"public")==0)		return 4;
	if(strcmp(token,"class")==0)		return 5;
	if(strcmp(token,"static")==0)		return 6;
	if(strcmp(token,"int")==0)			return 7;
	if(strcmp(token,"int[]")==0)		return 8;
	if(strcmp(token,"for")==0)			return 9;
	if(strcmp(token,"break")==0)		return 10;
	if(strcmp(token,"continue")==0)		return 11;
	if(strcmp(token,"instanceof")==0)	return 12;
	if(strcmp(token,"char")==0)			return 13;
	if(strcmp(token,"char[]")==0)		return 14;
	if(strcmp(token,"boolean")==0)		return 15;
	if(strcmp(token,"boolean[]")==0)	return 16;
	if(strcmp(token,"float")==0)		return 17;
	if(strcmp(token,"float[]")==0)		return 18;
	if(strcmp(token,"byte")==0)			return 19;
	if(strcmp(token,"byte[]")==0)		return 20;
	if(strcmp(token,"short")==0)		return 21;
	if(strcmp(token,"short[]")==0)		return 22;
	if(strcmp(token,"long")==0)			return 23;
	if(strcmp(token,"long[]")==0)		return 24;
	if(strcmp(token,"double")==0)		return 25;
	if(strcmp(token,"double[]")==0)		return 26;
	if(strcmp(token,"void")==0)			return 27;
	if(strcmp(token,"void[]")==0)		return 28;
	if(strcmp(token,";")==0)			return 29;
	if(strcmp(token,")")==0)			return 32;
	if(strcmp(token,"==")==0)			return 33;
	if(strcmp(token,"<")==0)			return 34;
	if(strcmp(token,">")==0)			return 35;
	if(strcmp(token,"!=")==0)			return 36;
	if(strcmp(token,"<=")==0)			return 37;
	if(strcmp(token,">=")==0)			return 38;
	if(strcmp(token,"+")==0)			return 39;
	if(strcmp(token,"-")==0)			return 40;
	if(strcmp(token,"*")==0)			return 41;
	if(strcmp(token,"/")==0)			return 42;
	if(strcmp(token,"%")==0)			return 43;
	if(strcmp(token,"&&")==0)			return 44;
	if(strcmp(token,"||")==0)			return 45;
	if(strcmp(token,"++")==0)			return 46;
	if(strcmp(token,"--")==0)			return 47;
	if(strcmp(token,"=")==0)			return 48;
	if(strcmp(token,"+=")==0)			return 49;
	if(strcmp(token,"-=")==0)			return 50;
	if(strcmp(token,"*=")==0)			return 51;
	if(strcmp(token,"/=")==0)			return 52;
	if(strcmp(token,"&")==0)			return 53;
	if(strcmp(token,"|")==0)			return 54;
	if(strcmp(token,"^")==0)			return 55;
	if(strcmp(token,"~")==0)			return 56;
	if(strcmp(token,"?")==0)			return 57;
	if(strcmp(token,"<<")==0)			return 58;
	if(strcmp(token,">>")==0)			return 59;
	if(strcmp(token,">>>")==0)			return 60;
	if(strcmp(token,".")==0)			return 61;
	if(strcmp(token,",")==0)			return 62;
	if(strcmp(token,"[")==0)			return 63;
	if(strcmp(token,"]")==0)			return 64;
	if(strcmp(token,"{")==0)			return 65;
	if(strcmp(token,"}")==0)			return 66;
	if(strcmp(token,"return")==0)		return 67;
	if(strcmp(token,"true")==0)			return 68;
	if(strcmp(token,"false")==0)		return 69;
	if(strcmp(token,"String")==0)		return 70;
	if(strcmp(token,"String[]")==0)		return 71;
	if(strcmp(token,"this")==0)			return 72;
	if(strcmp(token,"new")==0)			return 73;
	if(strcmp(token,"(")==0)			return 31;
	if(strcmp(token,"System.out.print")==0)		return 80;
	if(strcmp(token,"System.out.println")==0)	return 81;
	return 0;
}
int addEntry(char* token,char* type,char* datatype,int TableEntryFlag){
	if(token[strlen(token)-1]=='('){
		int i=0;
		for(i=0;i<strlen(token)-1;i++){
			if(token[i]==' ')	break;
		}
		char* temp=NULL;
		temp=malloc(i+1);
		strncpy(temp,token,i);
		if(hash(temp))
			return hash(temp);
	}
	// 0 for Variable, 1 for Function, 2 for Library
	if(TableEntryFlag==0){
		if(checkTokenExists(token)==0){
			no_of_entries++;
			if(no_of_entries){
				table=realloc(table,no_of_entries*sizeof(struct SymbolTable));
			}
			else{
				table = (struct SymbolTable*)malloc(no_of_entries*sizeof(struct SymbolTable));
			}
			table[no_of_entries-1].id=tablepointer;
			tablepointer++;
			table[no_of_entries-1].scopeDepth=currScopeDepth;
			table[no_of_entries-1].line_no=line_no;
			table[no_of_entries-1].name=malloc(strlen(token)+1);
			strcpy(table[no_of_entries-1].name,token);
			table[no_of_entries-1].name[strlen(token)]='\0';
			table[no_of_entries-1].datatype=malloc(strlen(datatype)+1);
			strcpy(table[no_of_entries-1].datatype,datatype);
			table[no_of_entries-1].datatype[strlen(datatype)]='\0';
			table[no_of_entries-1].type=type;
			table[no_of_entries-1].parameterlist=strdup("-");
		}
		
		return 90;
	}
	else if(TableEntryFlag==1){
		int i;
		for(i=0;i<strlen(token);i++){
			if(token[i]==' ' || token[i]=='('){
				no_of_entries++;
				if(no_of_entries){
					table=realloc(table,no_of_entries*sizeof(struct SymbolTable));
				}
				else{
					table = (struct SymbolTable*)malloc(no_of_entries*sizeof(struct SymbolTable));
				}
				table[no_of_entries-1].id=tablepointer;
				tablepointer++;
				table[no_of_entries-1].scopeDepth=currScopeDepth;
				buff = malloc(i+1);
				strncpy(buff,token,i);
				buff[i+1]='\0';
				table[no_of_entries-1].name=malloc(strlen(buff));
				strcpy(table[no_of_entries-1].name,buff);
				table[no_of_entries-1].datatype=malloc(strlen(datatype)+1);
				strcpy(table[no_of_entries-1].datatype,datatype);
				table[no_of_entries-1].line_no=line_no;
				table[no_of_entries-1].datatype[strlen(datatype)]='\0';
				table[no_of_entries-1].type=strdup("Function");
				table[no_of_entries-1].parameterlist=strdup("");
				int i=no_of_entries-1;
				//printf("ID : %d    Line : %d    Name : %s    Type : %s    Datatype : %s    parameterlist : %s    Value : -    scopeDepth : %d\n",table[i].id,table[i].line_no,table[i].name,table[i].type,table[i].datatype,table[i].parameterlist,table[i].scopeDepth);
				break;
			}
		}
		return 81;
	}
	else if(TableEntryFlag==2){
		if(checkTokenExists(token)==0){
			no_of_entries++;
			if(no_of_entries){
				table=realloc(table,no_of_entries*sizeof(struct SymbolTable));
			}
			else{
				table = (struct SymbolTable*)malloc(no_of_entries*sizeof(struct SymbolTable));
			}
			table[no_of_entries-1].id=tablepointer;
			tablepointer++;
			table[no_of_entries-1].scopeDepth=currScopeDepth;
			table[no_of_entries-1].name=malloc(strlen(token)+1);
			table[no_of_entries-1].line_no=line_no;
			strcpy(table[no_of_entries-1].name,token);
			table[no_of_entries-1].name[strlen(token)]='\0';
			table[no_of_entries-1].datatype=malloc(strlen(datatype)+1);
			strcpy(table[no_of_entries-1].datatype,datatype);
			table[no_of_entries-1].datatype[strlen(datatype)]='\0';
			table[no_of_entries-1].type=strdup("Library");
			table[no_of_entries-1].parameterlist=strdup("-");
			int i=no_of_entries-1;
			//printf("ID : %d    Line : %d    Name : %s    Type : %s    Datatype : %s    parameterlist : %s    Value : -    scopeDepth : %d\n",table[i].id,table[i].line_no,table[i].name,table[i].type,table[i].datatype,table[i].parameterlist,table[i].scopeDepth);
		}
		return 82;
	}
	return -1;
}
void addParam(char* type){
	int i;
	for(i=0;i<no_of_entries;i++){
		if(strcmp(table[i].name,buff)==0){
			char* temp = malloc(strlen(type)+1+strlen(table[i].parameterlist)+1);
			temp[0] = '\0';

			strcat(temp,table[i].parameterlist);
			n_param++;
			if(n_param>1)	strcat(temp,",");
			strcat(temp,type);
			table[i].parameterlist=realloc(table[i].parameterlist,strlen(temp));
			strcpy(table[i].parameterlist,temp);
		}
	}
}

int genKeyword(char* kw,char* type){
	if(checkTokenExists(kw)==0){
		no_of_entries++;
		if(no_of_entries){
			table=realloc(table,no_of_entries*sizeof(struct SymbolTable));
		}
		else{
			table = (struct SymbolTable*)malloc(no_of_entries*sizeof(struct SymbolTable));
		}
		table[no_of_entries-1].id=hash(kw);
		table[no_of_entries-1].name=malloc(strlen(kw)+1);
		strcpy(table[no_of_entries-1].name,kw);
		table[no_of_entries-1].name[strlen(kw)]='\0';
		table[no_of_entries-1].type=strdup("Keyword");
		table[no_of_entries-1].datatype=malloc(strlen(type)+1);
		strcpy(table[no_of_entries-1].datatype,type);
		table[no_of_entries-1].datatype[strlen(type)]='\0';
		table[no_of_entries-1].line_no=line_no;
		table[no_of_entries-1].parameterlist=strdup("-");
		table[no_of_entries-1].scopeDepth=0;
		int i=no_of_entries-1;
		//printf("ID : %d    Line : %d    Name : %s    Type : %s    Datatype : %s    parameterlist : %s    Value : -    scopeDepth : %d\n",table[i].id,table[i].line_no,table[i].name,table[i].type,table[i].datatype,table[i].parameterlist,table[i].scopeDepth);
		return table[no_of_entries-1].id;
	}
	else{
		return checkTokenExists(kw);
	}
}
int genSpecialFunctions(char* spFunc,char* type){
	if(checkTokenExists(spFunc)==0){
		no_of_entries++;
		if(no_of_entries){
			table=realloc(table,no_of_entries*sizeof(struct SymbolTable));
		}
		else{
			table = (struct SymbolTable*)malloc(no_of_entries*sizeof(struct SymbolTable));
		}
		table[no_of_entries-1].id=hash(spFunc);
		table[no_of_entries-1].name=malloc(strlen(spFunc)+1);
		strcpy(table[no_of_entries-1].name,spFunc);
		table[no_of_entries-1].name[strlen(spFunc)]='\0';
		table[no_of_entries-1].type=strdup("Special Function");
		table[no_of_entries-1].line_no=line_no;
		table[no_of_entries-1].datatype=malloc(strlen(type)+1);
		strcpy(table[no_of_entries-1].datatype,type);
		table[no_of_entries-1].datatype[strlen(type)]='\0';
		table[no_of_entries-1].scopeDepth=0;
		int i=no_of_entries-1;
		//printf("ID : %d    Line : %d    Name : %s    Type : %s    Datatype : %s    parameterlist : %s    Value : -    scopeDepth : %d\n",table[i].id,table[i].line_no,table[i].name,table[i].type,table[i].datatype,table[i].parameterlist,table[i].scopeDepth);
		return table[no_of_entries-1].id;
	}
	else{
		return checkTokenExists(spFunc);
	}
}
char* removeMidSpaces(char* yytext){
	int len = strlen(yytext);
	int i;
	for(i=0;i<len;i++){
		if(yytext[i]==' ')	break;
		if(i==(len-1))	return yytext;
	}
	int j;
	for(j=i;j<len;j++){
		if(yytext[j]!=' ')	break;
	}
	char* ret = malloc(i+(len-j-1));
	strncpy(ret,yytext,i);
	strncpy(ret+i,yytext+j,len-j-1);
	return ret;
}
void addValue(int value){
	table[no_of_entries-1].value = value;
	int i=no_of_entries-1;
	
	//printf("ID : %d    Line : %d    Name : %s    Type : %s    Datatype : %s    parameterlist : %s    Value : %d    scopeDepth : %d\n",table[i].id,table[i].line_no,table[i].name,table[i].type,table[i].datatype,table[i].parameterlist,table[i].value,table[i].scopeDepth);

}


int find_id(char* name){
	for(int i = 0; i<no_of_entries;i++){
		//printf("%d %d\n",table[i].id,p_id);
		if(strcmp(table[i].name,name) == 0){
			return table[i].id;
			//return table[i].name;
		}
	}
	return -1;
}

char* find_name(int id){
	for(int i = 0; i<no_of_entries;i++){
		//printf("%d %d\n",table[i].id,p_id);
		if(table[i].id == id){
			return table[i].name;
		}
	}
	char *null = strdup("NULL");
	return null;
}


int retrieve(char name[]){
	int i;
	for(i=0;i<no_of_entries;i++){
		if(strcmp(name,table[i].name)==0){
			return table[i].value;
		}
	}
	printf("retrieve error. \n");
	return -1;
}




