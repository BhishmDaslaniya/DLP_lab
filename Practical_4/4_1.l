%{
	#include<stdio.h>
%}
digit [0-9]+
%option noyywrap
%%
{digit} {printf("%s\n",yytext);}
.|\n;
%%
int main()
{
	yylex();
	return 0;
} 