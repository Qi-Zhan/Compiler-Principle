#include <stdio.h>
#include "ast/ast.h"
#include "sem/sem.h"
#include "gen/gen.h"

extern int yyparse();
extern FILE *yyin;
extern AST* head;
int main(int argc, const char *argv[])
{
    if (argc != 2){
        printf("Usage: %s <file>\n", argv[0]);
        return 0;
    }
    yyin = fopen(argv[1], "r");
    // printf("begin parse\n");
    int result = yyparse();
    if(result == 0){
        printf("parse successfully!\n");
    }
    fclose(yyin);
    head->reparent(); // remake parent
    head->print(0); // print AST
    printf("Generating Symbol Table...\n");
    auto semantic = new semanticAnalysis(head);
    if (semantic->table->generate_symbolTable() == 0)
    {
        // semantic->table->main_env->print_env(0);
        printf("Pass Semantic Checking!\n");
    }
    printf("New AST!\n");
    head->print(0); // print AST
    printf("Generating IR...\n");
    auto CodeGen = new codeGen();
    CodeGen->generate(head);
    CodeGen->print();
    printf("Generating Objective Code...\n");
    CodeGen->generate_o();
    return 0;
}