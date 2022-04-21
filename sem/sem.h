#ifndef SEM_H
#define SEM_H
#include <unordered_map>
#include "../ast/ast.h"
class symbolTable
{
public:
    AST *head;

    symbolTable(AST* node);
    void generate_symbolTable();
    ~symbolTable();
};

class env
{
public:
    env(/* args */);
    ~env();
};





#endif