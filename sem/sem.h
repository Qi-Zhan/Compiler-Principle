#ifndef SEM_H
#define SEM_H
#include <unordered_map>
#include "../ast/ast.h"
class symbolTable
{

public:
    symbolTable(AST* node);
    ~symbolTable();
};

class env
{
public:
    env(/* args */);
    ~env();
};





#endif