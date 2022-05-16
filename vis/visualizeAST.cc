#include"vis.h"
using namespace std;
void Visualize::generateDOT()
{
    dst << "digraph{\n";
    dst << "fontname=\" Helvetica, Arial, sans-serif\""<<endl;
    dst << "node[fontname = \"Helvetica,Arial,sans-serif\"]"<<endl;
    dst << "edge[fontname = \"Helvetica,Arial,sans-serif\"]"<<endl;
    dst << "node [style=filled];"<<endl;
    generateNode(node);
    dst << "}"<<endl;
}
void Visualize::generateNode(AST *node)
{
    
    for (int i = 0; i < node->child->size(); i++)
    {
        generateNode(node->child->at(i));
    }
    dst << "n" << node->id << "[label=\"";
    if (node->tokentype == "VarDecl" || node->tokentype == "ParmVarDecl")
    {
        dst << "VarDecl ";
        if (node->length > 0) // 数组
        {
            dst << node->ID << " : " << node->dtype.substr(0,node->dtype.size()-1)<<"["<<node->length<<"]";
        }
        else{
            dst << node->ID << " : " << node->dtype;
        }
    }
    else if (node->tokentype == "BinaryOperator")
    {
        dst << node->binaryop;
    }
    else if (node->tokentype == "Identifier")
    {
        dst << node->ID;
    }
    else if (node->tokentype == "Constant")
    {
        if(node->dtype=="int"){
            dst << (int)node->dvalue;
        }else{
            dst << node->dvalue;
        }
    }
    else if (node->tokentype == "FunctionDecl")
    {
        dst << "FunctionDecl: " << node->ID;
    }
    else if (node->tokentype == "CallExpr")
    {
        dst << "Call";
    }
    else if (node->tokentype == "ArraySubscriptExpr")
    {
        dst << "ArraySubscript";
    }
    else {
        dst << node->tokentype;
    }
    dst << "\"";
    if (node->tokentype=="translation unit")
    {
        dst << "color=\" 0.002 0.999 0.999 \"];" << endl;
    }else if(node->tokentype=="Constant"){
        dst << "color=\" 0.201 0.753 1.000 \"];" << endl;
    }else if(node->tokentype.substr(node->tokentype.size()-4,4)=="Stmt"){
        dst << "color=\" 0.499 0.386 1.000 \"];" << endl;
    }
    else if (node->tokentype.substr(node->tokentype.size() - 4, 4) == "Decl")
    {
        dst << "color=\" 0.578 0.289 1.000 \"];" << endl;
    }
    else{
        dst << "color=\" 0.650 0.200 1.000 \"];" << endl;
    }

    
    for (int i = 0; i < node->child->size(); i++)
    {
        dst << "n" << node->id << " -> "
            << "n" << node->child->at(i)->id << " ;";
    }
}