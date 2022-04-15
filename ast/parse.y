%{
    #include<stdio.h>
    #include<math.h>
    #include <iostream>
    #include "ast.h"
    void yyerror(char *s);
    extern int yylineno;
    extern FILE* yyin;
    extern char* yytext;
    extern int yylex(void);
    extern int yylineno;
    int AST::order = 0;
    AST head = AST("translation unit");
%}

%union {float numf; int numi ; char str[63]; AST *node; }
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
%type<node> expression
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
        : external_declaration {head.insert($1);}
        | ssc external_declaration {head.insert($2);}
        ;

/* 定义又分为函数定义和其他(变量)定义 */
external_declaration 
        : function_definition {$$ = new AST("FunctionDecl"); }
        | declaration {
                $$ =new AST("VarDecl");$$->dtype = $1->dtype; 
                $$->ID = $1->ID;$$->child = $1->child;
                // std::cout<<$$->child->size();  
                }
        ;

/* 指定类型 要声明列表 */ 
declaration
        : declaration_specifiers IDENTIFIER ';' {$$ = new AST("test"); $$->dtype = $1->tokentype;$$->ID = $2; }
        | declaration_specifiers IDENTIFIER '=' expression ';' {$$ = new AST("test"); $$->dtype = $1->tokentype;$$->ID = $2;$$->insert($4);}
        ;

declaration_specifiers
        : type_qualifier type_specifier {}
        | type_specifier {$$ = $1;}
        ;
/* 可以同时声明多个变量, int a, b ,c; */

/* 可以只声明，也可以同时初始化 */


/* 对象可以是ID, 也可以是数组 */

identifier_list
        : IDENTIFIER
        | identifier_list ',' IDENTIFIER
        ;

parameter_list
        : declaration_specifiers IDENTIFIER
        | parameter_list ',' declaration_specifiers IDENTIFIER
        ;        
/* todo: 初始化数组{} */

function_definition
        : declaration_specifiers IDENTIFIER '(' parameter_list ')' compound_statement {}
        | declaration_specifiers IDENTIFIER '(' ')' compound_statement {}
        ;

compound_statement
        : '{' '}'
        | '{' statement_list '}'
        | '{' declaration_list '}'
        | '{' declaration_list statement_list '}'
        ;
declaration_list
        : declaration
        | declaration_list  declaration
        ;

statement_list
        : statement
        | statement_list statement
        ;       
/* 语句分为复合、表达式、选择、循环、跳转 */
statement
        : compound_statement
        | expression_statement
        | selection_statement
        | iteration_statement
        | jump_statement
        ;

expression_list
        : expression_list ',' expression
        | expression
        ;

expression_statement
        : ';' {}
        | expression ';' {}
        ;

selection_statement
        : IF '(' expression ')' statement ELSE statement {}
        | IF '(' expression ')' statement {}
        | SWITCH '(' expression ')' statement {}
        ;

iteration_statement
        : WHILE '(' expression ')' statement
        | DO statement WHILE '(' expression ')' ';'
        | FOR '(' expression_statement expression_statement ')' statement
        | FOR '(' expression_statement expression_statement expression ')' statement
        ;

jump_statement
        : GOTO IDENTIFIER ';' 
        | CONTINUE ';'
        | BREAK ';'
        | RETURN ';'
        | RETURN expression ';'
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
        | expression '=' expression {$$ = new AST("BinaryOperator");$$->binaryop="+"; $$->insert($1);$$->insert($3);}
        | IDENTIFIER '[' expression ']' {}
        | IDENTIFIER '(' expression_list ')' {}
        | IDENTIFIER {$$ = new AST("Identifier"); $$->ID = $1;} 
        | CONSTANTf {$$ = new AST("Constant"); $$->dvaule = $1; $$->dtype = "float"; }
        | CONSTANTi {$$ = new AST("Constant"); $$->dvaule = $1; $$->dtype = "int";}
        | STRING_LITERAL {}
        | '(' expression ')' {$$ = new AST("ParenExpr"); $$->insert($2);}
        ;
        /*  | unary_operator expression */

/* assignment_expression
        :   */

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
        | UNSIGNED {$$ = new AST("unsigned");}
        | SIGNED  {$$ = new AST("signed");}
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




void yyerror(char *s) {
    fprintf(stderr, "line %d: %s at %s\n",yylineno, s,yytext);
}