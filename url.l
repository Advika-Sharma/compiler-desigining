%%
(https):\/\/[w]{3}(\.[a-z]{3,})(\.[a-z]{2,}) {printf("\nValid URL\n");}
.+ {printf("\nInvalid URL\n");}
%%
int main(){
printf("\nEnter URL\n");
yylex();
return 0;
}
int yywrap()
{
}
