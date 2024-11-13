%{
#include<stdio.h>
int v=0,c=0;
%}

%%
[ \t\n]+ ;
[aeiouAEIOU] {v++;}
[^aeiouAEIOU] {c++;}
%%

int main()
{
  printf("Enter the word:\n");
  yylex();
  printf("vowels :%d",v);
  printf("consonants :%d",c);
  
}
int yywrap()
{
 return 1;
}
