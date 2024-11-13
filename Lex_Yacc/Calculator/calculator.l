%{
#include "y.tab.h"
%}

%%
[0-9]+ {yylval = atoi(yytext); return NUMBER;}
[ \t] ;
"\n" {return '\n';}
"+"  {return '+';}
"-"  {return '-';}
"*"  {return '*';}
"/"  {return '/';}
"("  {return '(';}
")"  {return ')';}
%%

int yywrap(){
	return 1;
}