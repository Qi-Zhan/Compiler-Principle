#include "sem.h"

symbolTable::symbolTable(AST* node)
{
    this->head = node;
}

symbolTable::~symbolTable()
{
    
}

env::env(/* args */)
{
}

env::~env()
{
}
