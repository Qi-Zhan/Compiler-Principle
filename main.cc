#include <stdio.h>
#include "ast/ast.h"
#include "sem/sem.h"
#include "gen/gen.h"

extern int yyparse();
extern FILE *yyin;
extern AST* head;
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
    head->reparent(); // remake parent
    head->print(0); // print AST
    printf("Generating Symbol Table...\n");
    auto SymbolTable = new symbolTable(head);

    printf("Pass Semantic Checking!\n");
    printf("Generating Code...\n");
    auto CodeGen = new codeGen();
    CodeGen->generate(head);
    CodeGen->print();
    CodeGen->generate_o();
    return 0;
}