#ifndef AST_H
#define AST_H
#include <string>
#include <iostream>
#include <vector>


class AST
{
private:
    static int order;

public:
    std::string tokentype; // 所有token都有的，标识这个token类别
    std::string dtype; // VarDecl  Function return
    // std::string paratype; //参数类型
    std::string ID;
    std::string binaryop;
    float dvalue;
    int id;
    std::vector<AST*> *child;
    AST* parent;
    AST(std::string name);
    ~AST();
    void insert(AST* node);
    void print(int n);
    void copy_child(AST *node);
    void reparent();
    AST *ref; // maybe use it
};

#endif