
%{
#include<stdio.h>
%}
%%
(.)*new(.)* {fprintf(yyout, yytext); fprintf(yyout,"\n");}
(.|\n) {}
%%
int yywrap()
{
  return 1;
}
int main()
{
  yyin = fopen("inp6.txt", "r"); yyout = fopen("out6.txt", "w");
  yylex();
  return 0;
}