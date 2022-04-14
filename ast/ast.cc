#include "ast.h"
AST::AST(std::string name)
{
    this->name = name;
    this->id = AST::order++;
    this->parent = NULL;
    // std::cout << "order==" << this->id << std::endl;
}

AST::~AST()
{
}

void AST::print()
{
    printf("-%s\n", this->name.c_str());
    // std::cout << this->name << std::endl;
    for (int i = 0; i < this->child.size(); i++)
    {
        this->child[i].print();
    }
}

void AST::insert(AST node)
{
    this->child.push_back(node);
    node.parent = this;
}