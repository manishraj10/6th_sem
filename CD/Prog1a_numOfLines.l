%{
#include<stdio.h>
int lines=1, spaces=0, words=0, characters=0;
%}
%%
[ ] {spaces++;}
[\t] {spaces=spaces+3;}
[\n] {lines++;}
[a-zA-Z]* {words++;characters=characters+yyleng;}
# {return 0;}
%%


int yywrap(){
return 1;
}


int main(){

printf("enter a para\n");
yylex();
printf("Number of lines =%d\nnumber of spaces =%d\nnumber of words =%d\nnumber of characters=%d\n",lines,spaces,words,characters);
}