%{
#include "y.tab.h"
%}
%%
"if" {return IF;}
"(" { return LPAREN; }
")" { return RPAREN; }
"{" { return LF; }
"}" { return RF; }
[;] {return ';';}
[,]
"<" {return '<';}
">" {return '>';}

"=" {return '=';}
"+" {return '+';}
"-" {return '-';}
"==" {return EQ;}
"<=" {return LEQ;}
">=" {return GEQ;}

[ \t\n]*
[a-zA-Z]+ {return ALPHA;}
[0-9]+ {return NUM;}
# {return 0;}
.
%%