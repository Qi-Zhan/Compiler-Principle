#include <string>
#include <iostream>

class AST
{
public:
    std::string name;
    int id;
    // AST 
    AST(std::string name);
    ~AST();
    void print();
};

AST::AST(std::string name)
{
    this->name = name;
}

AST::~AST()
{
}

void AST::print(){

}
