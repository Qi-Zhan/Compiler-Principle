#include <iostream>
#include <stdio.h>
extern int yyparse();
extern FILE *yyin;
int main(int argc, const char *argv[])
{
    /* yyparse(); */
    if (argc != 2)
    {
        printf("Usage: %s <file>\n", argv[0]);
        return 0;
    }
    yyin = fopen(argv[1], "r");
    int result = yyparse();
    printf("result: %d\n", result);
    fclose(yyin);
    return 0;
}