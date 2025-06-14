%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
int yylex(void);
%}

%token NUM
%left '+' '-'
%left '*' '/'

%%
S : expr { printf("Result = %d\n", $1); }
;

expr : expr '+' expr { $$ = $1 + $3; }
     | expr '-' expr { $$ = $1 - $3; }
     | expr '*' expr { $$ = $1 * $3; }
     | expr '/' expr { if ($3 == 0) { yyerror("Division by zero!"); } else { $$ = $1 / $3; } }
     | '(' expr ')'  { $$ = $2; }
     | NUM           { $$ = $1; }
     | '-' NUM       { $$ = -$2; }
;
%%

int main() {
    printf("Enter an expression:\n");
    yyparse();
    printf("Valid Expression.\n");
    return 0;
}

void yyerror(const char *s) {
    printf("Invalid Expression: %s\n", s);
    exit(1);
}