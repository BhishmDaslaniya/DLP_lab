%{
	#include<stdio.h>
%}
%option noyywrap
%%
"/*"[^\n]+"*/" {printf(" ");}
"//"([a-z]|[0-9]|[A-Z]|" ")* {printf(" ");}
%%
int main(int argc, char **argv)
{
yyin=fopen(argv[1],"r");
yylex();
fclose(yyin);
printf("\n");
return 0;
} 