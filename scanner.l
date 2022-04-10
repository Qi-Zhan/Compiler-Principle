%{
#include "parse.tab.h"
#include <stdlib.h>
void yyerror (char *s);
%}

%%
"program"             {return PROGRAM;}
"begin"               {return BEGIN;}

"+"|"-"|"*"|"/"|"^"|"("|")" | "=" | ":"       {return yytext[0];}

\n                    {return enter;}
[0-9]+                 {yylval.num = atoi(yytext); return number;}
[0-9]+\.[0-9]+          {yylval.num = atof(yytext); return number;}
[a-zA-Z_][a-zA-Z0-9]+   { return yytext;}
<<EOF>>                  {return terminate;}
.                      {ECHO; yyerror (" unexpected character");}

%%
int yywrap (void){
    return 1;
}