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
    std::string tokentype; // 所有token都有的，标识这个token类别
    std::string dtype; // VarDecl  Function return
    std::string ID;
    std::string binaryop;
    float dvaule;
    int id;
    std::vector<AST*> *child;
    AST* parent;
    AST(std::string name);
    ~AST();
    void insert(AST* node);
    void print(int n);
    void copy_child(AST *node1, AST *node2);
};

#endif