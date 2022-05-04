%{
    #include<stdio.h>
    #include<math.h>
    #include <iostream>
    #include "ast.h"
    void yyerror(const char *s);
    extern int yylineno;
    extern FILE* yyin;
    extern char* yytext;
    extern int yylex(void);
    extern int yylineno;
    int AST::order = 0;
    AST *head =new AST("translation unit");
%}

%union {float numf; int numi ; char* str; AST *node; }
%start ssc
/* reserved words begin */
%token STRING_LITERAL SIZEOF
%token LE_OP GE_OP EQ_OP NE_OP AND_OP OR_OP

/* %token TYPE_NAME */
%token TYPEDEF EXTERN STATIC AUTO
%token CHAR INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOID
%token STRUCT UNION ENUM 

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN
/* reserved words end */

%token <str> IDENTIFIER
%token <numf> CONSTANTf
%token <numi> CONSTANTi
/* %type <num> expr */

/* immediate words type */
%type<node> external_declaration declaration function_definition declaration_specifiers type_specifier type_qualifier
%type<node> expression parameter_list compound_statement jump_statement selection_statement 
%type<node> iteration_statement statement statement_list expression_statement declaration_list
%type<node> expression_list
/* immediate words type */
%left ','
%left '='
%left OR_OP
%left AND_OP
%left EQ_OP NE_OP
%left GE_OP LE_OP '>' '<'
%left '+''-'
%left '*''/' '%'

%%
/* SSC无非是由一个个声明/定义构成的 */
ssc
        : external_declaration {head->insert($1);}
        | ssc external_declaration {head->insert($2);}
        ;

/* 定义又分为函数定义和其他(变量)定义 */
external_declaration 
        : function_definition {
                $$ = new AST("FunctionDecl"); 
                $$->child = $1->child; // para和compound statement 孩子
                $$->ID = $1->ID; $$->dtype = $1->dtype; // 函数名 返回类型
                }
        | declaration {
                $$ =new AST("VarDecl");$$->dtype = $1->dtype; 
                $$->ID = $1->ID;$$->child = $1->child; // expr 孩子
                $$->tokentype = $1->tokentype;
                $$->length = $1->length;
                // std::cout<<$$->child->size();  
                }
        ;

/* 指定类型 要声明列表 */ 
declaration
        : declaration_specifiers IDENTIFIER ';' {$$ = new AST("VarDecl"); $$->dtype = $1->tokentype;$$->ID = $2; }
        | declaration_specifiers IDENTIFIER '=' expression ';' {$$ = new AST("VarDecl"); $$->dtype = $1->tokentype;$$->ID = $2;$$->insert($4);}
        | declaration_specifiers IDENTIFIER '[' CONSTANTi ']'';'{$$ = new AST("VarDecl");$$->dtype = $1->tokentype+"*";$$->ID = $2;$$->length =  (int)($4);} 
        | declaration_specifiers IDENTIFIER '[' CONSTANTi ']' '=' '{' expression_list '}' ';'{$$ = new AST("VarDecl");$$->dtype = $1->tokentype+"*";$$->ID = $2;$$->length =  (int)($4);$$->child = $8->child;} 
        ;

declaration_specifiers
        : type_qualifier type_specifier {}
        | type_specifier {$$ = $1;}
        ;

/* identifier_list
        : IDENTIFIER
        | identifier_list ',' IDENTIFIER
        ; */

parameter_list
        : declaration_specifiers IDENTIFIER {$$ = new AST("ParmVarDecl"); AST* temp = new AST("ParmVarDecl");
                temp->ID = $2; temp->dtype = $1->tokentype; $$->insert(temp);}
        | parameter_list ',' declaration_specifiers IDENTIFIER {$$ = $1; AST* temp = new AST("ParmVarDecl");
                temp->ID = $4; temp->dtype = $3->tokentype; $$->insert(temp);}
        | declaration_specifiers IDENTIFIER'['']'{
                $$ = new AST("ParmVarDecl"); AST* temp = new AST("ParmVarDecl");
                temp->ID = $2; temp->dtype = $1->tokentype+"*"; $$->insert(temp);
        }
        | parameter_list ',' declaration_specifiers IDENTIFIER '[' ']'{
                $$ = $1; AST* temp = new AST("ParmVarDecl");
                temp->ID = $4; temp->dtype = $3->tokentype+"*"; $$->insert(temp);
        }
        ;        
/* todo: 初始化数组{} */

function_definition
        : declaration_specifiers IDENTIFIER '(' parameter_list ')' compound_statement {
                $$ = new AST("test"); $$->ID = $2; $$->dtype=$1->tokentype; // 同下
                $$->child = $4->child; $$->insert($6); 
                }
        | declaration_specifiers IDENTIFIER '(' ')' compound_statement {$$ = new AST("test"); $$->ID = $2; $$->dtype=$1->tokentype;$$->insert($5);}
        ;

compound_statement
        : '{' '}' {$$ = new AST("CompoundStmt"); }
        | '{' statement_list '}' {$$ = new AST("CompoundStmt"); $$->child = $2->child; }
        | '{' declaration_list '}' {$$ = new AST("CompoundStmt"); $$->child = $2->child;}
        | '{' declaration_list statement_list '}' {$$ = new AST("CompoundStmt"); $$->child = $2->child;$$->copy_child($3);}
        ;

declaration_list
        : declaration {$$ = new AST("test"); $$->insert($1);}
        | declaration_list  declaration {$$ = $1; $$->insert($2);}
        ;

statement_list
        : statement {$$ = new AST("test"); $$->insert($1);}
        | statement_list statement {$$ = $1; $$->insert($2);}
        ;       
/* 语句分为复合、表达式、选择、循环、跳转 */
statement
        : compound_statement {$$ = $1; }
        | expression_statement {$$ = $1; }
        | selection_statement {$$ = $1; }
        | iteration_statement {$$ = $1; }
        | jump_statement {$$ = $1; }
        ; 

expression_list
        : expression_list ',' expression {$$ = $1; $$->insert($3);}
        | expression {$$ = new AST("test"); $$->insert($1);}
        ;

expression_statement
        : ';' {$$ = new AST("NullStmt");}
        | expression ';' {$$ = $1;}
        ;

selection_statement
        : IF '(' expression ')' statement ELSE statement {$$ = new AST("IfStmt");$$->insert($3);$$->insert($5);$$->insert($7);}
        | IF '(' expression ')' statement {$$ = new AST("IfStmt");$$->insert($3);$$->insert($5);}
        | SWITCH '(' expression ')' statement {}
        ;

iteration_statement
        : WHILE '(' expression ')' statement {$$ = new AST("WhileStmt"); $$->insert($3);$$->insert($5);}
        | FOR '(' expression_statement expression_statement ')' statement {$$ = new AST("ForStmt");$$->insert( new AST("EmptyInit")) ;$$->insert($3);$$->insert($4);$$->insert($6);}
        | FOR '(' expression_statement expression_statement expression ')' statement {$$ = new AST("ForStmt");$$->insert($3);$$->insert($4);$$->insert($5);$$->insert($7);}
        ;

jump_statement
        : GOTO IDENTIFIER ';' {} 
        | CONTINUE ';' {$$ =  new AST("ContinueStmt");}
        | BREAK ';' {$$ = new AST("BreakStmt");}
        | RETURN ';' {$$ = new AST("ReturnStmt");}
        | RETURN expression ';' {$$ = new AST("ReturnStmt"); $$->insert($2); }
        ;

expression
        : expression '+' expression {$$ = new AST("BinaryOperator");$$->binaryop="+"; $$->insert($1);$$->insert($3);}
        | expression '-' expression {$$ = new AST("BinaryOperator");$$->binaryop="-"; $$->insert($1);$$->insert($3);}
        | expression '*' expression {$$ = new AST("BinaryOperator");$$->binaryop="*"; $$->insert($1);$$->insert($3);}
        | expression '/' expression {$$ = new AST("BinaryOperator");$$->binaryop="/"; $$->insert($1);$$->insert($3);}
        | expression AND_OP expression {$$ = new AST("BinaryOperator");$$->binaryop="&&"; $$->insert($1);$$->insert($3);}
        | expression OR_OP expression {$$ = new AST("BinaryOperator");$$->binaryop="||"; $$->insert($1);$$->insert($3);}
        | expression LE_OP expression  {$$ = new AST("BinaryOperator");$$->binaryop="<="; $$->insert($1);$$->insert($3);}     
        | expression NE_OP expression {$$ = new AST("BinaryOperator");$$->binaryop="!="; $$->insert($1);$$->insert($3);}
        | expression GE_OP expression {$$ = new AST("BinaryOperator");$$->binaryop=">="; $$->insert($1);$$->insert($3);}
        | expression EQ_OP expression   {$$ = new AST("BinaryOperator"); $$->binaryop="==";$$->insert($1);$$->insert($3);}    
        | expression '<' expression   {$$ = new AST("BinaryOperator"); $$->binaryop="<";$$->insert($1);$$->insert($3);}  
        | expression '>' expression   {$$ = new AST("BinaryOperator"); $$->binaryop=">";$$->insert($1);$$->insert($3);}         
        | expression '=' expression {$$ = new AST("BinaryOperator");$$->binaryop="="; $$->insert($1);$$->insert($3);}
        | IDENTIFIER '[' expression ']' {$$ = new AST("ArraySubscriptExpr");AST* temp = new AST("Identifier");temp->ID = $1;  $$->insert(temp);$$->insert($3); }
        | IDENTIFIER '(' expression_list ')' {$$ = new AST("CallExpr"); $$->ID = $1; $$->child = $3->child;}
        | IDENTIFIER '(' ')' {$$ = new AST("CallExpr"); $$->ID = $1;}
        | IDENTIFIER {$$ = new AST("Identifier"); $$->ID = $1; } 
        | CONSTANTf {$$ = new AST("Constant"); $$->dvalue = $1; $$->dtype = "float"; }
        | CONSTANTi {$$ = new AST("Constant"); $$->dvalue = $1; $$->dtype = "int";}
        | STRING_LITERAL {}
        | '(' expression ')' {$$ = $2;}
        /* | '(' expression ')' {$$ = new AST("ParenExpr"); $$->insert($2);} */
        ;
        /*  | unary_operator expression */



/* 类型修饰符 */
type_qualifier
        : CONST {$$ = new AST("const");}
        ;
/* 类型标识符 */    
type_specifier
        : VOID {$$ = new AST("void");}
        | CHAR {$$ = new AST("char");}
        | INT {$$ = new AST("int");}
        | FLOAT {$$ = new AST("float");}
        | DOUBLE {$$ = new AST("double");}
        /* | UNSIGNED {$$ = new AST("unsigned");}
        | SIGNED  {$$ = new AST("signed");} */
        /* | AUTO {$$ = new AST("auto");} */
        /* | struct_or_union_specifier
        | enum_specifier
        | TYPE_NAME */
        ;

unary_operator
        : '-'
        | '~'
        | '!'
        ;

%%




void yyerror(const char *s) {
    fprintf(stderr, "line %d: %s at %s\n",yylineno, s,yytext);
}