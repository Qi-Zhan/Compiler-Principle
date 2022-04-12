%{
#include "parse.tab.h"
#include <stdlib.h>
void yyerror (char *s);

%}
/* %option noyywrap */
%option caseless
%option yylineno
%%
"program"             {return PROGRAM;}
"procedure"            {return PROCEDURE;}
"function"              {return FUNCTION;}
"begin"               {return BEGIN;}
"end"                   {return END;}
"if"                    {return IF;}
"then"                   {return THEN;}
"else"                    {return ELSE;}
"case"                   {return CASE;}
"while"                     {return WHILE;}
"do"                       {return DO;}
"until"                     {return UNTIL;}
"repeat"                    {return REPEAT;}
"for"                       {return FOR;}
"to"                        {return TO;}
"goto"                      {return GOTO;}
"downto"                    {return DOWNTO;}
"const"                     {return CONST;}
"var"                        {return VAR;}
"array"                       {return ARRAY;}
"type"                          {return TYPE;}
"record"                        {return RECORD;}
"of"                            {return OF;}
"packed"                        {return PACKED;}
"and"                           {return AND;}
"or"                            {return OR;}
"not"                           {return NOT;}
"div"                           {return DIV;}
"mod"                           {return MOD;}
"integer"                       {return INTEGER;}
"real"                          {return REAL;}
"boolean"                       {return BOOLEAN;}
"char"                          {return CHAR;}
"true"                           {return TRUE;}
"false"                         {return FALSE;}

".."                            {return DOTDOT;}
"."                             {return DOT;}
":="                    {return ASSIGN;}
":"                     {return yytext[0];}
","                     {return yytext[0];}
";"                  {return DELIMITER;}
"+"                 {return yytext[0];}
"-"                 {return yytext[0];}
"*"                  {return yytext[0];}
"/"                 {return yytext[0];}
"^"                   {return yytext[0];}
"("                 {return yytext[0];}
")"                 {return yytext[0];}
"["                 {return yytext[0];}
"]"                 {return yytext[0];}
"="                     {return EQ;}
"<>"                    {return NEQ;}
"<"                     {return LT;}
">"                     {return GT;}
"<="                     {return LEQ;}
">="                     {return GEQ;}
\n                   {}
" "                 {}
[0-9]+                 {yylval.num = atoi(yytext); return number;}
[0-9]+\.[0-9]+          {yylval.num = atof(yytext); return number;}
[a-zA-Z][a-zA-Z0-9]*     {  for(int i=0;i<yyleng;i++) yylval.str[i] = yytext[i]; return ID;}
<<EOF>>                  { yyterminate();}
.                      {ECHO; yyerror (" unexpected character");}

%%
int yywrap (void){
    return 1;
}