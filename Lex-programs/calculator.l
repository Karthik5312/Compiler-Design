%{
#include <stdio.h>
int num1=0, num2, result = 0;   
char operator;                     
%}

%%
[0-9]+  { 
            if(num1==0)
                num1 = atoi(yytext);  // Convert the first number from string to integer
            else num2 = atoi(yytext);  // Convert the second number from string to integer
        }
"+"     { operator = '+'; }
"-"     { operator = '-'; }
"*"     { operator = '*'; }
"/"	{ operator = '/'; }
\n      { /* Ignore newlines */ }
.       { /* Ignore other characters */ }
%%

int main() {
    printf("Enter an expression (e.g., 3 + 5 or 10 - 2):\n");
    yylex();  // Start scanning input

    if (operator == '+')
        result = num1 + num2;
    else if (operator == '-')
        result = num1 - num2;
    else if (operator == '*')
        result = num1 * num2;
    else if (operator == '/')
        result = num1 / num2;

    printf("Result: %d\n", result);
}

int yywrap(){
	return 1;
}


