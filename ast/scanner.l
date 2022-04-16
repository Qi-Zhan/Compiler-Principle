%{
#include "ast.h"
#include "parse.tab.h"
#include <stdlib.h>
void yyerror (const char *s);

%}
/* %option noyywrap */
%option caseless
%option yylineno
%%

"break"               {return BREAK;}
"case"                   {return CASE;}
"char"                      {return CHAR;}
"const"                     {return CONST;}
"continue"                  {return CONTINUE;}
"do"                       {return DO;}
"double"		        { return DOUBLE; }
"default"                   {return DEFAULT;}
"else"                    {return ELSE;}
"enum"                      {return ENUM;}
"float"			            { return FLOAT; }
"for"                       {return FOR;}
"if"                    {return IF;}
"int"                       {return INT;}
"return"                    {return RETURN;}
"extern"                    {return EXTERN;}
"sizeof"		        { return SIZEOF; }
"static"		        {  return STATIC; }
"struct"		        {  return STRUCT ; }
"switch"		        {   return SWITCH ; }
"union"                     {return UNION;}
"goto"                        {return GOTO;}
"typedef"                          {return TYPEDEF;}
"void"                              {return VOID;}
"while"                     {return WHILE;}


"&&"			{   return  AND_OP ; }
"||"			{   return OR_OP ; }
"<="			{   return LE_OP ; }
">="			{   return GE_OP ; }
"=="			{   return EQ_OP ; }
"!="			{   return NE_OP ; }
","                     {return yytext[0]; }
";"                  {return yytext[0];}
"+"                 {return yytext[0];}
"-"                 {return yytext[0];}
"*"                  {return yytext[0];}
"/"                 {return yytext[0];}
"^"                   {return yytext[0];}
"("                 {return yytext[0];}
")"                 {return yytext[0];}
"["                 {return yytext[0];}
"]"                 {return yytext[0];}
"{"                 { return yytext[0];}
"}"                 {return yytext[0];}
"="                     {return yytext[0];}
"<"                     {return yytext[0];}
">"                     {return yytext[0];}
"!"                     {return yytext[0];}
"~"                     {return yytext[0];}
[0-9]+                 {yylval.numi = atoi(yytext); return CONSTANTi;}
[0-9]+\.[0-9]+          {yylval.numf = atof(yytext); return CONSTANTf;}
[a-zA-Z][a-zA-Z0-9]*     {  //for(int i=0;i<yyleng;i++) yylval.str[i] = yytext[i]; 
                            yylval.str = new char[strlen(yytext)]; // 不然会出大问题
                            strcpy(yylval.str, yytext); // yylval.str = yytext;
                            return IDENTIFIER;}
<<EOF>>                  { yyterminate();}
\n                   {}
" "                 {}
.                      {ECHO; yyerror (" unexpected character");}

%%
int yywrap (void){
    return 1;
}