#include <string>
#include <iostream>
#include <vector>
#ifndef AST_H
#define AST_H
class AST
{
private:
    static int order;

public:
    std::string name;
    int id;
    std::vector<AST> child;
    AST* parent;
    AST(std::string name);
    ~AST();
    void insert(AST node);
    void print();
};


#endif