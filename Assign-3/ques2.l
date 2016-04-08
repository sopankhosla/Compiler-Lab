%{
	#include <iostream>
	#include <map>
	using namespace std;

	#define LT 256
	#define LE 257
	#define EQ 258
	#define NE 259
	#define GT 260
	#define GE 261
	#define RELOP 262
	#define ID 263
	#define NUMBER 264
	#define IF 265
	#define THEN 266
	#define ELSE 267
	#define PID 268
	#define PNUM 269
	#define WHILE 270
	int yylval;
	int install_id();
	int install_num();
	map<string , bool > idTable;
	map<string , bool > numTable;

%}
/* regular definitions */
delim	[ \t\n]
ws	    {delim}+
letter	[A-Za-z]
digit	[0-9]
id 		{letter}({letter}|{digit}|_)*
number  {digit}+(\.{digit}+)?(E[+\-]?{digit}+)?
%%

{ws}		{/* no action and no return */}
if 			{return(IF);}
then 		{return(THEN);}
else 		{return(ELSE);}
while		{return(WHILE);}
pid 		{return (PID);}
pnum 		{return (PNUM);}
{id}		{yylval = install_id(); return(ID);}
{number}	{yylval = install_num(); return(NUMBER);}
"<" 		{yylval = LT; return(RELOP);}
"<=" 		{yylval = LE; return(RELOP);}
"==" 		{yylval = EQ; return(RELOP);} // changed 
"!=" 		{yylval = NE; return(RELOP);} // changed
">" 		{yylval = GT; return(RELOP);}
">=" 		{yylval = GE; return(RELOP);}

%%
