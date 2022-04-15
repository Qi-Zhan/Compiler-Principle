#include <stdio.h>
#include "ast/ast.h"
extern int yyparse();
extern FILE *yyin;
extern AST head;
int main(int argc, const char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <file>\n", argv[0]);
        return 0;
    }
    yyin = fopen(argv[1], "r");
    int result = yyparse();
    if(result == 0){
        printf("parse successfully!\n");
    }
    
    fclose(yyin);
    head.print(0);
    return 0;
}