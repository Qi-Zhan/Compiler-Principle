#ifndef SEM_H
#define SEM_H
#include <unordered_map>
#include "../ast/ast.h"
/*
每个env就是一个{}(compound stmt)
重要的是里面的define ref
*/
class env
{
public:
    env(env& par); // 先拷贝父亲的define
    env(); // 全局变量与函数
    env *parent;
    std::vector<env *> *child;
    std::unordered_map<std::string, AST *> define; //定义的
    std::unordered_map<std::string, AST *> ref; //使用的 先定义后使用
    void print_env(int n);
    int build_env(AST* node); // 从子节点建立语义
    ~env();
};
class symbolTable
{
public:
    AST *head;
    std::unordered_map<AST*, AST*> table; // 总table
    env *main_env;
    symbolTable(AST *node);
    int generate_symbolTable();
    void print_table();
    ~symbolTable();
};

class semanticAnalysis
{
public:
    symbolTable *table;

    semanticAnalysis(AST *node);
    ~semanticAnalysis();
    int type_inference();
};

#endif