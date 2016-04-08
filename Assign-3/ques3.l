%{
 #include <math.h>
%}

DIGIT    [0-9]
ID       [A-Za-z_][a-zA-Z0-9_]*

%%
"+"|"-"|div|mod|"/"   printf( "Arithmetic operator: %s\n", yytext );
"&"|"^"|"~"	printf( "Boolean Operators: %s\n" , yytext );
{DIGIT}+    {
             printf( "An integer: %s\n", yytext );
            }

{DIGIT}+"."{DIGIT}*        {
             printf( "A float: %s\n", yytext);
             }

if|then|begin|end|and|array|do|downto|case|const|else|end|file|for|function|goto|procedure|repeat|record|type|var|while|with|to        {
             printf( "A keyword: %s\n", yytext );
             }

{ID}        printf( "An identifier: %s\n", yytext );


"<"|">"|"<="|">="|"=="	printf( "Relational Operators: %s\n" , yytext );

[\n]+    printf( "New line: %s\n", yytext );
"{"[\^{$\;$}}\n]*"}"          printf( "Comment: %s\n", yytext );


%%

int yywrap()
{
  return 1;
}

int main()
{
	 yylex();

}
