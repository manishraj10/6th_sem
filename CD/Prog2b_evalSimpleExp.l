%{
#include "y.tab.h"
extern YYSTYPE yylval;
%}

%%
[0-9]+        { yylval = atoi(yytext); return NUM; }   // Numbers
[+\-*/]       { return yytext[0]; }                    // Operators
[ \t]         { /* Ignore spaces and tabs */ }         // Whitespace
\n            { return 0; }                            // End of input
.             { return yytext[0]; }                    // Any other character
%%