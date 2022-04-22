#include "sem.h"
semanticAnalysis::semanticAnalysis(AST* node){
    this->table = new symbolTable(node);
    
}
semanticAnalysis::~semanticAnalysis(){

}
int semanticAnalysis::type_inference(){
    return 0;
}

symbolTable::symbolTable(AST* node)
{
    this->head = node;
    this->main_env = new env();
}

symbolTable::~symbolTable()
{
    
}
int symbolTable::generate_symbolTable(){

    return 0;
}

void symbolTable::print_table(){
    
}

env::env()
{
    this->parent = nullptr;
    this->child = new std::vector<env *>;
}
env::env(env &par )
{
    this->parent = &par;
    this->define = par.define;
    this->child = new std::vector<env *>;
}

int env::build_env(AST* node){
    if (node->tokentype == "translation unit"){
        
    }
    else if (node->tokentype == "VarDecl" || node->tokentype == "ParmVarDecl")
    {
        std::cout << " " << node->dtype << " " << node->ID;
    }
    // else if (this->tokentype == "BinaryOperator")
    // {
    //     std::cout << " " << this->binaryop;
    // }
    // else if (this->tokentype == "Identifier")
    // {
    //     std::cout << " " << this->ID;
    // }
    // else if (this->tokentype == "Constant")
    // {
    //     printf(" %s %g", this->dtype.c_str(), this->dvalue);
    // }
    // else if (this->tokentype == "FunctionDecl")
    // {
    //     printf(" %s return %s", this->ID.c_str(), this->dtype.c_str());
    // }
    // else if (this->tokentype == "CallExpr")
    // {
    //     printf(" %s", this->ID.c_str());
    // }
}

void env::print_env(int n){
    for(auto kv:this->define){
        for (int i = 0; i < n; i++)
        {
            printf(" ");
        }
        std::cout << kv.first <<" define by "<<kv.second<< std::endl;
    }
    for(auto kv:this->ref){
        for (int i = 0; i < n; i++)
        {
            printf(" ");
        }
        std::cout << kv.first << " ref to " << kv.second << std::endl;
    }
    for (int i = 0; i < this->child->size(); i++){
        child->at(i)->print_env(n + 1);
    }
}

env::~env()
{
}
