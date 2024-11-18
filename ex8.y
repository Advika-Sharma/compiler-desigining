%{
#include<stdio.h>
#include<stdlib.h>
int yylex(void);
void yyerror(char *S);
%}
%token Z O
%%
S : S A {printf("accepted");}
| A
;
A : Z Z
| O O
;
%%
int main()
{
yyparser();
}
void yyerror(char *S)
{
printf("\n not accepted");
}



