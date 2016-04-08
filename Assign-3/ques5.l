%{
%}
digit [0-9]
digits {digit}+
charr [A-Za-z_]
space [ ]
d [dD]
o [oO]
u [uU]
b [bB]
l [lL]
e [eE]
p [pP]
r [rR]
c [cC]
i [iI]
s [sS]
n [nN]
W [ \t]*
%%
{d}{o}{u}{b}{l}{e}{W}{p}{r}{e}{c}{i}{s}{i}{o}{n} { 
fprintf(yyout, yytext[0]=='d'? "real" : "REAL"); 
}
^"     "[^ 0]   fprintf(yyout,yytext);
[0-9]+{W}{d}{W}[+-]?{W}[0-9]+     |
[0-9]+{W}"."{W}{d}{W}[+-]?{W}[0-9]+     |
[0-9]+{W}"."{W}[0-9]+     |
"."{W}[0-9]+{W}{d}{W}[+-]?{W}[0-9]+    {
						int ynum=0;
						bool dot=false;
						for(char *p=yytext; *p != 0; p++)
							{
						 	   long long znum = 0;
							   if(!dot)
							   {
								for(int i=0; *p!='\0'; p++)
								{
									if((*p == 'd' || *p == 'D') || *p=='.') break;
									ynum *=10;
									ynum += (int)(((char)*p) - '0');
									
								}
							   }
							   if(*p=='.')
							   {
								dot=true;	
								//fprintf(yyout,"%c",*p);
								p++;
								for(int i=0; *p!='\0'; p++)
								{
									if((*p == 'd' || *p == 'D')) break;
									if(i==9)
									{
										p++;
										if(*p<='9' && *p >= '5') znum++;
										p--;
									}
									i++;
									if(i>=10) continue;
									
									znum *=10LL;
									znum += (long long)(((char)*p) - '0');
									
								}
								if(znum==1000000000LL){  ynum++; znum=0; }
								fprintf(yyout,"%d.",ynum);
								fprintf(yyout,"%lld",znum);
							        if(*p=='\0') break;	
							   }
							if (*p == 'd' || *p == 'D')
								{
									*p+= 'e'- 'd';
								}	
							fprintf(yyout,"%c",*p);
							}
					}

%%

int yywrap()
{
  return 1;
}

int main()
{
  yyin = fopen("inp5.txt","r");
  yyout = fopen("out5.txt","w");
  
  yylex();
  return 0;
}
