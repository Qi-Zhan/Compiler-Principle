%{
    #include<stdio.h>
    #include<math.h>
    void print(double res);
    void yyerror(char *s);
%}

%union {int num;}
%start program
/* reserved words begin */
%token PROGRAM PROCEDURE FUNCTION
%token BEGIN END IF THEN ELSE CASE WHILE DO UNTIL REPEAR FOR TO GOTO DOWNTO
%token CONST VAR ARRAY TYPE RECORD OF PACKED
%token AND OR NOT DIV MOD
/* reserved words end */

/* middle words begin */

/* middle words end */


%token <num> number
%token enter terminate 
%type <num> expr
%left '+''-'
%left '*''/'
%right '^'

%%
program : PROGRAM {printf("program %s \n", $2);}
statement: line statement
        | enter statement
        | terminate {return 0;}
        | line

line    : expr enter {print($1);}

expr    : expr '+' expr {$$ = $1+$3;}
        | expr '-' expr {$$ = $1-$3;}
        | expr '*' expr {$$ = $1*$3;}
        | expr '/' expr {$$ = $1/$3;}
        | expr '^' expr {$$ = pow($1,$3);}
        | '-' expr %prec '*' {$$ = -$2;}
        | '(' expr ')' {$$ = $2;}
        | number {$$ = $1;}
 
%%

int main(int argc, const char *argv[]) {
    yyparse();
    return 0;
}

void print(double res){
    printf("%g\n", res);
}

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}