%%
^[a-zA-Z_][a-zA-Z0-9_]* {printf("Valid Identifier");}
.+ {printf("Invalid Identifier");}
%%
void main() {
printf("\nEnter Identifier: ");
yylex();
printf("\n");
}
int yywrap()
{
}
