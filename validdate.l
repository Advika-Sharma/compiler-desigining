%{
#include<stdio.h>
%}
%%
[\n]
([0-2][1-9]|[1-3][0-1])-([0][0-9]|1[0-2])-([1-2][0-9][0-9][0-9]) {printf("valid date");}
.+ {printf("not valid date");}
%%
int main(){
yylex();
}
