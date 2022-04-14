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
%}

%union {int num; char str[63]; }
%start ssc
/* reserved words begin */
%token CONSTANT STRING_LITERAL SIZEOF
%token LE_OP GE_OP EQ_OP NE_OP AND_OP OR_OP

/* %token TYPE_NAME */
%token TYPEDEF EXTERN STATIC AUTO
%token CHAR INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOID
%token STRUCT UNION ENUM 

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN
/* reserved words end */

%token <str> IDENTIFIER
%token <num> number
/* %type <num> expr */
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
        : external_declaration {}
        | ssc external_declaration {}
        ;

/* 定义又分为函数定义和其他(变量)定义 */
external_declaration 
        : function_definition {std::cout<<"function"<<std::endl; AST("1232");}
        | declaration {}
        ;

/* 指定类型 要声明列表 */ 
declaration
        : declaration_specifiers identifier_list ';' {}
        | declaration_specifiers identifier_list '=' expression ';' {}
	    /* | declaration_specifiers ';' {} */
        ;

declaration_specifiers
        : type_qualifier type_specifier
        | type_specifier
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
        : expression '+' expression 
        | expression '-' expression
        | expression '*' expression
        | expression '/' expression
        | expression AND_OP expression
        | expression OR_OP expression
        | expression LE_OP expression       
        | expression NE_OP expression
        | expression GE_OP expression
        | expression EQ_OP expression             
        | expression '=' expression
        | IDENTIFIER '[' expression ']' {}
        | IDENTIFIER '(' expression_list ')' {}
        | IDENTIFIER {} 
        | CONSTANT {;}
        | STRING_LITERAL {}
        | '(' expression ')' {}
        ;
        /*  | unary_operator expression */

/* assignment_expression
        :   */

/* 类型修饰符 */
type_qualifier
        : CONST
        ;
/* 类型标识符 */    
type_specifier
        : VOID
        | CHAR
        | INT
        | FLOAT
        | DOUBLE
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