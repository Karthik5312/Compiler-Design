%{
#include <stdio.h>
#include <stdlib.h>
%}

%token NUMBER

%%
C:E'\n' {printf("Result: %d\n", $1);};
C:C E'\n' {printf("Result: %d\n", $2);};	
E:E'+'E {$$=$1+$3;};
E:E'-'E {$$=$1-$3;};
E:E'*'E {$$=$1*$3;};
E:E'/'E {$$=$1/$3;};
E:'('E')' {$$=$2;};
E:NUMBER {$$=$1;};
%%

int main(){
	printf("Enter the expression:\n");
	yyparse();
	return 0;
}

void yyerror(){}
