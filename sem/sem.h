#ifndef SEM_H
#define SEM_H
#include <unordered_map>
#include <set>
#include "../ast/ast.h"
class env
{
public:
    env(env* par); 
    env(); // 全局变量与函数
    env *parent;
    std::vector<env *> *child;
    std::unordered_map<std::string, AST *> define; //定义的
    std::unordered_map<std::string, AST *> ref; //使用的 先定义后使用
    void print_env(int n);
    int build_env(AST* node); // 从该节点建立语义
    ~env();
};
class symbolTable
{
public:
    AST *head;
    // std::unordered_map<AST*, AST*> table; // 总table
    env *main_env;
    symbolTable(AST *node);
    int generate_symbolTable();
    void print_table();
    ~symbolTable();
};

class semanticAnalysis
{
private:
    int optControlFlow(AST *node);
    int constantFold(AST *node);

public:
    symbolTable *table;
    semanticAnalysis(AST *node);
    ~semanticAnalysis();
    int opt(AST *node);
    
};

#endif