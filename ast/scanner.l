%{
#include "parse.tab.h"
#include <stdlib.h>
void yyerror (char *s);
%}
%%
"program"             {return PROGRAM;}
"begin"               {return BEGIN;}
":="                    {return ASSIGN;}
":"                     {return yytext[0];}
";"                  {return DELIMITER;}
"+"                 {return yytext[0];}
"-"                 {return yytext[0];}
"*"                  {return yytext[0];}
"/"                 {return yytext[0];}
"^"                   {return yytext[0];}
"("                 {return yytext[0];}
")"                 {return yytext[0];}
"="                     {return yytext[0];}
\n                   {}
" "                 {}
[0-9]+                 {yylval.num = atoi(yytext); return number;}
[0-9]+\.[0-9]+          {yylval.num = atof(yytext); return number;}
[a-zA-Z][a-zA-Z0-9]*     {  for(int i=0;i<yyleng;i++) yylval.str[i] = yytext[i]; return ID;}
<<EOF>>                  {return terminate;}
.                      {ECHO; yyerror (" unexpected character");}

%%
int yywrap (void){
    return 1;
}