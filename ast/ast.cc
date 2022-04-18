#include "ast.h"
AST::AST(std::string name)
{
    this->tokentype = name;
    this->id = AST::order++;
    this->parent = NULL;
    this->child = new std::vector<AST *>;
}

AST::~AST()
{
}

void AST::print(int n)
{
    // printf("|");
    for (int i = 0; i < n; i++)
    {
        printf("  ");
    }
    printf("-%s", this->tokentype.c_str());
    if (this->tokentype == "VarDecl" || this->tokentype == "ParmVarDecl")
    {
        std::cout << " "<< this->dtype<<" "<<this->ID;
    }
    else if (this->tokentype == "BinaryOperator")
    {
        std::cout << " " << this->binaryop;
    }
    else if (this->tokentype == "Identifier")
    {
        std::cout << " " << this->ID;
    }
    else if (this->tokentype == "Constant")
    {
        printf(" %s %g",this->dtype.c_str(), this->dvalue);
    }
    else if (this->tokentype == "FunctionDecl")
    {
        printf(" %s return %s",this->ID.c_str(), this->dtype.c_str());
    }
    else if (this->tokentype == "CallExpr")
    {
        printf(" %s", this->ID.c_str());
    }
    printf("\n");
    for (int i = 0; i < this->child->size(); i++)
    {
        this->child->at(i)->print(n+1);
    }
}

void AST::insert(AST* node)
{
    // node->print(3);
    this->child->push_back(node);
    node->parent = this;
}

void AST::copy_child(AST* node){
    for (int i = 0; i < node->child->size(); i++)
    {
        this->child->push_back(node->child->at(i));
        node->child->at(i)->parent = this;
    }
}