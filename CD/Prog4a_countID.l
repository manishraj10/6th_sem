%{
#include <stdio.h>
#include <stdlib.h>
int identifiers, operators, keywords;
int arithmetic_operators, relational_operators, logical_operators, bitwise_operators;
%}

letters [a-zA-Z_]
digits  [0-9]

%%

"if"|"else"|"for"|"while"|"void"|"struct"|"int"|"return"  { keywords++; }
"&&"|"||"|"!"                                             { operators++; logical_operators++; }
">"|"<"|">="|"<="|"=="|"!="                               { operators++; relational_operators++; }
"&"|"|"|"<<"|">>"|"~"|"^"                                 { operators++; bitwise_operators++; }
"+"|"-"|"*"|"/"|"%"                                       { operators++; arithmetic_operators++; }
{letters}({letters}|{digits})*                            { identifiers++; }
.|[\t\n ]+                                                ;

%%
int yywrap() {
    return 1; // Return 1 to indicate end of input
}

int main() {
  yyin = fopen("input.c", "r");
  yylex();

  printf("Keywords: %d\n", keywords);
  printf("Operators: %d\n", operators);
  printf("\tarithmetic_operators: %d\n", arithmetic_operators);
  printf("\tbitwise_operators: %d\n", bitwise_operators);
  printf("\tlogical_operators: %d\n", logical_operators);
  printf("\trelational_operators: %d\n", relational_operators);
  printf("Identifiers: %d\n", identifiers);

  return 0;
}