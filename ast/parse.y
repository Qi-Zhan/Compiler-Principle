%{
    #include<stdio.h>
    #include<math.h>
    void print(double res);
    void yyerror(char *s);
    extern int yylineno;
    extern FILE* yyin;
    extern char* yytext;
    extern int yylineno;
%}

%union {int num; char str[63]; }
%start program
/* reserved words begin */
%token PROGRAM PROCEDURE FUNCTION
%token BEGIN END IF THEN ELSE CASE WHILE DO UNTIL REPEAT FOR TO GOTO DOWNTO
%token CONST VAR ARRAY TYPE RECORD OF PACKED
%token AND OR NOT DIV MOD
%token INTEGER REAL BOOLEAN CHAR TRUE FALSE
/* reserved words end */

/* reserved symbol begin */
%token ASSIGN DELIMITER NEQ DOTDOT DOT LT LEQ GEQ GT EQ
/* reserved symbol end */

/* middle words begin */

/* middle words end */

%token <str> ID
%token <num> number
/* %type <num> expr */
%left '+''-'
%left '*''/'
%right '^'

%%
program : PROGRAM ID DELIMITER const_decs type_decs var_decs function_decs execute DOT {printf("get all program\n");};
const_decs  : 
            | CONST eq_statements  {printf("get const_decs\n");}
            ;
eq_statements : IDs EQ expr DELIMITER 
                | IDs EQ expr DELIMITER eq_statements
                |
;



IDs : ID  coID  {printf("get IDs\n");}
;
coID : | ',' ID coID;

type_decs    : 
            | TYPE

;

var_decs    : 
            | VAR var_statements
;

var_statements : IDs ':' type DELIMITER 
                | IDs ':' type DELIMITER var_statements
                |

type : standard_type | ARRAY'[' number DOTDOT number ']' OF standard_type ;
standard_type : REAL | BOOLEAN | INTEGER  ;

function_decs    : 
                 | FUNCTION 
;
execute     : compoundstatment
;

compoundstatment: BEGIN END | BEGIN statementlist END 
;


statementlist           : statement DELIMITER
                        |  statement DELIMITER statementlist
                        ;

statement               : variable ASSIGN expr
                        /* | ProcedureStatement */
                        | compoundstatment
                        | IF expr THEN statement ELSE statement
                        | IF expr THEN statementlist // test
                        | WHILE expr DO statement
                        |
                        ;

variable                : ID {}
                        | ID '[' expr ']' {}
                        ;
statements      :  
                | statement DELIMITER statements   
;


/* judge:   */

expr    : expr '+' expr {}
        | expr '-' expr {}
        | expr '*' expr {}
        | expr '/' expr {}
        | expr '^' expr {}
        | '-' expr %prec '*' {}
        | '(' expr ')' {}
        | number {}
        | FALSE {}
        | TRUE {}
        | ID {}
        |  LT expr
        | expr GT expr
        | expr EQ expr
        | expr NEQ expr
        | expr LEQ expr
        | expr GEQ expr
;
%%

int main(int argc, const char *argv[]) {
    /* yyparse(); */
    if(argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 0;
    }
    yyin = fopen(argv[1], "r");
    int result = yyparse();
    printf("result: %d\n",result);
    fclose(yyin);
    return 0;
}

void print(double res){
    printf("%g\n", res);
}

void yyerror(char *s) {
    fprintf(stderr, "line %d: %s at %s\n",yylineno, s,yytext);
}