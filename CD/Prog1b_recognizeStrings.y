%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void yyerror(char const*s);
%}
%start S
%%

S: A B ;
A: 'a'A'b' | ;
B: 'b'B'c' | ;
%%
int main(){
printf("Enter words\n");
yyparse();
printf("true\n");
return 0;
}
void yyerror(char const *s){
fprintf(stderr,"Invalid\n");
exit(0);
}