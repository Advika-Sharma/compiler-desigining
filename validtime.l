%{
#include<stdio.h>
int i=0, yr=0, valid=0;
%}

%%
24:00:00 {printf("%s It is an invalid time\n", yytext);}
([01][0-9]:[0-5][0-9]:[0-5][0-9]) {printf("%s It is a valid time\n", yytext);}
(20|21|22|23):[0-5][0-9]:[0-5][0-9] {printf("%s It is a valid time\n", yytext);}
. {printf("%s It is an invalid time\n", yytext);}  // Catch-all for invalid times
%%
void main()
{
    yyin = fopen("new", "r");
    yylex();
}

int yywrap()
{
    return 1;
}
