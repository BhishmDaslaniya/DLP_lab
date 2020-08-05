%option noyywrap
%{
	#include<stdio.h>
%}
%%
charusat {printf("cspit");}
%%
int main()
{
	yylex();
	return 0;
}