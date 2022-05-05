#include "sem.h"
std::unordered_map<std::string, int> str_to_int{{"int", 0}, {"float", 1}, {"double", 2}};
std::unordered_map<int ,std::string > int_to_str{{0 ,"int"}, {1, "float"}, {2, "double"}};
std::set<std::string> arith = {"+", "-", "*", "/","="};
int max(int a, int b) { return a > b ? a : b; };
semanticAnalysis::semanticAnalysis(AST *node)
{
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
    this->main_env->build_env(this->head); // 生成scope
    return 0;
}

void symbolTable::print_table(){
    
}

env::env()
{
    this->parent = nullptr;
    this->child = new std::vector<env *>;
}
env::env(env* par ) 
{
    this->parent = par;
    this->child = new std::vector<env *>;
    par->child->push_back(this);
}

int check_redef(std::unordered_map<std::string, AST *> map, std::string key)
{
    auto iter = map.find(key);
    if (iter != map.end())
    {
        printf("Redefinition of %s\n", key.c_str());
    }
    return 0;
}

int env::build_env(AST* node){
    std::string token = node->tokentype;
    if (token == "ParmVarDecl" || token == "VarDecl"){
        for (int i = 0; i < node->child->size(); i++)
        {
            build_env(node->child->at(i));
        }
        check_redef(define, node->ID);
        define.insert({node->ID, node});
        node->ref = node; // 定义的ref是自己
    }
    else if (token == "FunctionDecl"){
        define.insert({node->ID, node});
        env *new_env = new env(this);
        for (int i = 0; i < node->child->size(); i++)
        {
            new_env->build_env(node->child->at(i));
        }
    }
    else if (token == "CompoundStmt"){
        env *new_env = new env(this);
        for (int i = 0; i < node->child->size(); i++){
            new_env->build_env(node->child->at(i));
        }
    }
    else if (token == "Identifier" || token == "CallExpr")
    { // find define or false
        if (token == "CallExpr"){
            for (int i = 0; i < node->child->size(); i++)
                build_env(node->child->at(i));
        }
        env *temp = this;
        while (temp){
            if (temp->define.find(node->ID)!= temp->define.end()){
                this->ref.insert({node->ID, temp->define[node->ID]});
                node->dtype = temp->define[node->ID]->dtype; // given type
                node->ref = temp->define[node->ID]; // 指向声明的AST* node
                return 0;
            }
            else{
                temp = temp->parent;
            }
        }
        printf("Using undefined identifier %s \n", node->ID.c_str());
        return 1;
    }
    else if (token == "ArraySubscriptExpr"){
        for (int i = 0; i < node->child->size(); i++)
            build_env(node->child->at(i));
        AST *ch = node->child->at(0);
        node->dtype = ch->dtype.substr(0,ch->dtype.length()-1);
    }

    else{
        for (int i = 0; i < node->child->size(); i++)
        {
            build_env(node->child->at(i));
        }
        if (token == "BinaryOperator")
        // check = left identifier todo
        {
            if (arith.count(node->binaryop))
            {
                node->dtype = int_to_str[max(str_to_int[node->child->at(0)->dtype], str_to_int[node->child->at(1)->dtype])];
            }else{
                node->dtype = "int";
            }
        }
    }
    return 0;
}


void env::print_env(int n){
    for(auto kv:this->define){
        for (int i = 0; i < n; i++)
        {
            printf("  ");
        }
        std::cout << kv.first << " define by " << kv.second << " " << kv.second->dtype << std::endl;
    }
    for(auto kv:this->ref){
        for (int i = 0; i < n; i++)
        {
            printf(" ");
        }
        std::cout << kv.first << " ref to " << kv.second <<" "<< kv.second->dtype<< std::endl;
    }
    for (int i = 0; i < this->child->size(); i++){
        child->at(i)->print_env(n + 1);
    }
}

env::~env()
{
}
