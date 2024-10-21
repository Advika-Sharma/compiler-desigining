%{
#include <stdio.h>
#include <stdlib.h>
%}

%%
([0-2][0-9]|3[01])\/(0[1-9]|1[0-2])\/([0-9]{4}) { printf("Valid date: %s\n", yytext); }
[ \t\n]+                 { /* Ignore whitespace */ }
.                        { printf("Invalid input: %s\n", yytext); }

%%

int main(int argc, char **argv) {
printf("Enter date:");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
