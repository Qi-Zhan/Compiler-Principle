#ifndef VIS_H
#define VIS_H
#include <iostream>
#include <fstream>
#include "../ast/ast.h"


class Visualize
{
private:
    AST *node;
    std::ofstream dst;
    void generateNode(AST *node);
    
public:
    Visualize(AST * root, const std::string path, std::ios_base::openmode mode = std::ios_base::trunc) : dst(path), node(root){};
    // Visualize(AST *root)
    // {
    //     this->node = root;
    //     std::ofstream dst("out.dot", std::ios::trunc);
    // }
    void generateDOT();
    ~Visualize(){
        dst.close();
    }
};

#endif