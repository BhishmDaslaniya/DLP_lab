%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
int yyerror(char *s);
%}

%token A B NL

%%
stmt: S NL {printf("valid string\n");
             exit(0);}
;
S: A S B | A B
;
%%

int yyerror(char *msg)
{
printf("invalid string\n");
exit(0);
}

int main()
{
printf("enter the string\n");
yyparse();
}