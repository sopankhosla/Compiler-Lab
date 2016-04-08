%{
#include<stdio.h>
%}
digit [0-9]
charr [A-Za-z_]
space [ ]
%%
[ \t\n]* {fprintf(yyout," ");}
[.]* {fprintf(yyout,"%s", yytext);}
%%

int yywrap()
{
  return 1;
}

int main()
{
  yyin = fopen("inp4.txt","r");
  yyout = fopen("out4.txt","w");

  yylex();
  return 0;
}
