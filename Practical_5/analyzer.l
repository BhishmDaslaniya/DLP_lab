%{
	
%}
invalidID [0-9]+\.?([0-9]*)?([eE][-+]?[0-9]+)?[A-Za-z_]+
invalidSTRING1 \"[^\n\"]*[\n]?[^\n\"]*\"?
invalidSTRINGTEST \"[^\n\"]*[\n]?
invalidSTRING2 \'[^\n\']*[\n]?
literalString1 \"([^\\\"\n]|\\.)*(\\\n)?([^\\\"\n]|\\.)*\"
literalString2 \'([^\\\'\n]|\\.)*\'
literalNumber ([0-9]*)?\.?([0-9]*)?([eE][-+]?[0-9]+)?
separator [\[{};,()\]]
identifier [a-zA-Z][a-zA-Z0-9]*
MultilineComm "/*"([^*]|\*+[^*/])*\*+"/"
SinglellineComm \/\/(.*)
operator [+-/=*%]|->|&&|\|\||\!|\<=|\>=|\<|\==|\>|\+\+|\-\-|\!\=|\<\<|\>\>|&|\||\~|\^|\?\:|\+\=|\-\=|\*\=|\/\=|\%\=
keyword string|auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while
%%
#.* {printf("\n\t%s is a preprocessor directive",yytext);}
{invalidID} {printf("\n\t%s\t\t ------> ERROR in indentifier...", yytext);}
{keyword} {printf("\n\t%s ------> KEYWORD",yytext);}
{SinglellineComm} {printf("\n");}
{MultilineComm} {}
{separator}   {printf("\n\t%s ------> SEPARATOR",yytext);}
{operator}   {printf("\n\t%s ------> OPERATOR",yytext);}
{identifier}([0-9]*)? {printf("\n\t%s ------> IDENTIFIER",yytext);}
{literalString1} {printf("\n\t%s ------> LITERAL STRING",yytext);}
{literalString2} {printf("\n\t%s ------> LITERAL STRING",yytext);}
{invalidSTRINGTEST} {printf("\n\t\t%s\t\t ------> ERROR in string...", yytext);}
{invalidSTRING2} {printf("\n\t\t%s\t\t ------> ERROR in string...", yytext);}
{literalNumber} {printf("\n\t%s ------> LITERAL NUM",yytext);}
%%
int main(int argc, char **argv)
{
	FILE *file;
	if (argv[1] != NULL) {
	printf("\n%s is the file name.\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n",argv[1]);
		file=fopen(argv[1],"r");
	}else{
		printf("please give the file name...");
		return 0;
	}
	
	if(!file)
	{
		printf("could not open the file");
		exit(0);
	}
	yyin=file;
	yylex();
	printf("\n");
	return(0);
}
int yywrap(){
	return(1);
}