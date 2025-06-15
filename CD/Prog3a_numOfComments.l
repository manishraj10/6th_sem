%{
#include<stdio.h>
#include<stdlib.h>
int single=0,multi=0,multilines=0;
%}
%%

"//"[^\n]* {single++;}
"/*"[^*]*"*/" {
multi++;
for(int i=0;i<yyleng;i++){
if(yytext[i]=='\n')
multilines++;
}
}
%%
int yywrap(){
return 1;
}
int main(){
yyin=fopen("Inp.txt","r");
yyout=fopen("out.txt","w");
yylex();
printf("Single lines=%d\nMultiline comment=%d\nNumber of lines in the multiline comment=%d\n",single,multi,multilines);
return 1;
}


//CREATE A FILE CALLED Inp.txt
/*

int main(){
//This is a sinle line comment
printf("Welcome to RVCE\n");
/*This
Is a
Multi line
Comment
*/
int a,b;
}

*/