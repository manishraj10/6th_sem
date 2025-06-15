%{
#include<stdio.h>
#include<stdlib.h>
int count=0;
void yyerror();
int yylex();
%}
%token IF ALPHA NUM GEQ LEQ EQ LPAREN RPAREN LF RF
%%
S:I;
I: IF A B {count++;};
A: LPAREN E RPAREN ;
E: ALPHA Z ALPHA| ALPHA Z NUM| ;
Z: '<'|'>'|GEQ|LEQ|EQ ;
B: ALPHA|ALPHA I|LF B RF| I|;
%%
int main(){
printf("enter an expression\n");
yyparse();
printf("Number of if loops are %d\n",count);
return 0;
}
void yyerror(){
printf("Invalid\n");
exit(0);
}