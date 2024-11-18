%{
#include <stdio.h>
#include <stdlib.h>
%}

%token A B

extern int yylex();  // Declaration for yylex
void yyerror(const char *s);  // Declaration for yyerror

%%
stmt: S
;
S: A S B
  | /* empty */
;
%%
int main() {
    printf("Enter a string: \n");
    yyparse();
    printf("Valid\n");
    exit(0);
}

void yyerror(const char *s) {
    printf("Invalid: %s\n", s);
    exit(1);
}

