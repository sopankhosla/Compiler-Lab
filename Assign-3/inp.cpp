#include<iostream>
#include<stdio.h>

using namespace std;

int main(int argc, char* argv[])
{

  string s,in;
  s = argv[1];
  in = argv[2];

cout<<"\n\
%{\n\
#include<stdio.h>\n\
%}\n\
%%\n\
(.)*"+s+"(.)* {fprintf(yyout, yytext); fprintf(yyout,\"\\n\");}\n\
(.|\\n) {}\n\
%%\n\
int yywrap()\n\
{\n\
  return 1;\n\
}\n\
int main()\n\
{\n\
  yyin = fopen(\""+in+"\", \"r\"); yyout = fopen(\"out6.txt\", \"w\");\n\
  yylex();\n\
  return 0;\n\
}";


}
