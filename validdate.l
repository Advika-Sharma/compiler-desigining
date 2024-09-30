%%
([0-9][0-9])-([0-9][0-9])-([1-2][0-9][0-9][0-9]) {printf("valid date");}
.+ {printf("not valid date");}
%%
int main()
{printf("\n enter date:");
yylex();
printf("\n");
return 0;
}
int yywrap()
{
}
