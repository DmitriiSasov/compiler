TODO Операторы и геттеры, сеттеры для полей
%define parse.error verbose
%{
	Пролог
	#include "tree_nodes.h"
	#include <stdio.h>
	void yyerror(const char* message) {
		fprintf(stderr, message);
	}
	int yylex();
	int yyparse();
	extern FILE* yyin;
%}
//Секция объявлений
%union {
	
	
}


%token NEW_LINE
%token ID
%token CLASS
%token PUBLIC
%token PRIVATE
%token PROTECTED
%token FIELD
%token PARAM
%token SETPARAM
%token DELEGATE
%token INTERFACE
%token OBJECT
%token PROPERTY
%token DYNAMIC
%token ENUM
%token SEALED
%token SUSPEND
%token INNER
%token EXTERNAL
%token ACTUAL
%token ANNOTATION
%token GET
%token SET
%token RECEIVER
%token CONSTRUCTOR
%token BY
%token COMPANION
%token INIT
%token LATEINIT
%token VARARG
%token THIS
%token SUPER
%token INTERNAL
%token OVERRIDE
%token ABSTRACT
%token FUN
%token VAR
%token TYPEOF
%token IF
%token ELSE
%token WHERE
%token WHEN
%token DO
%token WHILE
%token FOR
%token BREAK
%token CONTINUE
%token AS
%token IN
%token OUT
%token DATA
%token RETURN
%token TAILREC
%token OPERATOR
%token INLINE
%token NOINLINE
%token CROSSINLINE
%token REIFIED
%token EXPECT
%token INFIX
%token OPEN
%token FINAL
%token CONST
%token FILE
%token INT
%token FLOAT
%token DOUBLE
%token STRING
%token CHAR
%token BOOLEAN
%token ASUM
%token ASUB
%token ADIV
%token AMUL
%token AMOD
%token OR
%token AND
%token EQ
%token AEQ
%token NEQ
%token NAEQ
%token LOEQ
%token MOEQ
%token TRUE
%token FALSE

%start program

//Operators
%left OR
%left AND
%left EQ AEQ NEQ NAEQ
%left '<' '>' LOEQ MOEQ
%nonassoc RANGE
%left '+' '-'
%left '/' '*' '%'
%right UMINUS
%right UPLUS
%right '!'
%left '.'
%nonassoc '(' ')'
%nonassoc '[' ']'
 
%%

program: semis
| newLines
| stmts
| semis stmts
| newLines stmts
;

class: classDeclaration block
| classDeclarationWithoutInheritance block
;

classDeclarationWithoutInheritance: inheritanceModifier visibilityModifier CLASS ID
| visibilityModifier inheritanceModifier CLASS ID
| inheritanceModifier CLASS ID
| visibilityModifier CLASS ID
| CLASS ID
;

classDeclaration: classDeclarationWithoutInheritance ':' ID
;

property: optVisibilityModifier valDeclaration
| optVisibilityModifier varDeclaration
| optVisibilityModifier inheritanceModifier valDeclaration
| optVisibilityModifier inheritanceModifier varDeclaration
| inheritanceModifier optVisibilityModifier valDeclaration
| inheritanceModifier optVisibilityModifier varDeclaration 
| memberModifier optVisibilityModifier inheritanceModifier valDeclaration
| optVisibilityModifier memberModifier inheritanceModifier valDeclaration
| optVisibilityModifier inheritanceModifier memberModifier valDeclaration
| memberModifier optVisibilityModifier inheritanceModifier varDeclaration
| optVisibilityModifier memberModifier inheritanceModifier varDeclaration
| optVisibilityModifier inheritanceModifier memberModifier varDeclaration
| memberModifier inheritanceModifier optVisibilityModifier valDeclaration
| inheritanceModifier memberModifier optVisibilityModifier valDeclaration
| inheritanceModifier optVisibilityModifier memberModifier valDeclaration
| memberModifier inheritanceModifier optVisibilityModifier varDeclaration
| inheritanceModifier memberModifier optVisibilityModifier varDeclaration
| inheritanceModifier optVisibilityModifier memberModifier varDeclaration
| memberModifier optVisibilityModifier varDeclaration
| optVisibilityModifier memberModifier varDeclaration
| memberModifier optVisibilityModifier valDeclaration
| optVisibilityModifier memberModifier valDeclaration
;

method: optVisibilityModifier funcDeclaration ';'
| optVisibilityModifier func
| optVisibilityModifier inheritanceModifier funcDeclaration ';'
| optVisibilityModifier inheritanceModifier func
| inheritanceModifier optVisibilityModifier funcDeclaration ';'
| inheritanceModifier optVisibilityModifier func 
| memberModifier optVisibilityModifier inheritanceModifier funcDeclaration ';'
| optVisibilityModifier memberModifier inheritanceModifier funcDeclaration ';'
| optVisibilityModifier inheritanceModifier memberModifier funcDeclaration ';'
| memberModifier optVisibilityModifier inheritanceModifier func
| optVisibilityModifier memberModifier inheritanceModifier func
| optVisibilityModifier inheritanceModifier memberModifier func
| memberModifier inheritanceModifier optVisibilityModifier funcDeclaration ';'
| inheritanceModifier memberModifier optVisibilityModifier funcDeclaration ';'
| inheritanceModifier optVisibilityModifier memberModifier funcDeclaration ';'
| memberModifier inheritanceModifier optVisibilityModifier func
| inheritanceModifier memberModifier optVisibilityModifier func
| inheritanceModifier optVisibilityModifier memberModifier func
| memberModifier optVisibilityModifier func
| optVisibilityModifier memberModifier func
| memberModifier optVisibilityModifier funcDeclaration ';'
| optVisibilityModifier memberModifier funcDeclaration ';'
;


initializer: INIT block
;


constructor: optVisibilityModifier CONSTRUCTOR '(' optFormalParams ')' block
| optVisibilityModifier CONSTRUCTOR '(' optFormalParams ')'
| optVisibilityModifier CONSTRUCTOR '(' optFormalParams ')' ':' SUPER '(' optFactParams ')'
| optVisibilityModifier CONSTRUCTOR '(' optFormalParams ')' ':' THIS '(' optFactParams ')' 
| optVisibilityModifier CONSTRUCTOR '(' optFormalParams ')' ':' SUPER '(' optFactParams ')' block
| optVisibilityModifier CONSTRUCTOR '(' optFormalParams ')' ':' THIS '(' optFactParams ')' block
;

optVisibilityModifier: /*empty*/
| visibilityModifier
;


optFormalParams: /*empty*/
| formalParams
;


formalParams: ID ':' type
| formalParams ',' ID ':' type
;


memberModifier: OVERRIDE
;


visibilityModifier: PUBLIC
| PRIVATE
| INTERNAL
| PROTECTED
;


inheritanceModifier: ABSTRACT
| FINAL
| OPEN
;


func : funcDeclaration block
| funcDeclaration '=' expr semis
| funcDeclaration '=' expr newLines
;


funcDeclaration: FUN ID '(' optFormalParams ')' ':' type
;


block : '{' optNewLines stmts optNewLines'}'
| '{' semis stmts '}'
| '{' semis '}'
| '{' optNewLines '}'
;


varDeclaration: VAR ID ':' type
| VAR ID ':' type '=' expr
| VAR '(' formalParams ')' '=' expr
;


valDeclaration: VAL ID ':' type
| VAL ID ':' type '=' expr
| VAR '(' formalParams ')' '=' expr
;

type: easyType
| templateType
;

templateType: ID '<' type_seq '>'
| ID '<' templateType '>'
;

type_seq: easyType
| type_seq ',' easyType
;

easyType: INT
| UNIT
| ID
| STRING
| CHAR
| FLOAT
| DOUBLE
;

stmts : stmt
| stmts stmt
;

stmt : property semis
| property newLines
| method semis
| method newLines
| class semis
| class newLines
| constructor semis
| constructor newLines
| init semis
| init newLines
| assignment semis
| assignment newLines
| whileLoop semis
| whileLoop newLines
| forLoop semis
| forLoop newLines
| doWhileLoop semis
| doWhileLoop newLines
| ifStmt semis
| ifStmt newLines
| expr newLines
| expr semis
| BREAK semis
| BREAK newLines
| CONTINUE semis
| CONTINUE newLines
| RETURN semis
| RETURN newLines
| RETURN expr newLines
| RETURN expr semis
;

expr: ID 
| THIS 
| expr '(' optFactParams ')'
| INT 
| FLOAT 
| STRING 
| CHAR 
| DOUBLE 
| BOOLEAN 
| TRUE 
| FALSE 
| '(' expr ')' 
| '!' expr 
| '+' expr %prec UPLUS
| '-' expr %prec UMINUS
| expr '+' expr 
| expr '-' expr 
| expr '*' expr 
| expr '/' expr 
| expr '%' expr 
| expr '<' expr 
| expr '>' expr 
| expr OR expr 
| expr AND expr 
| expr EQ expr 
| expr AEQ expr 
| expr NEQ expr 
| expr NAEQ expr
| expr LOEQ expr
| expr MOEQ expr
| expr '.' expr
| expr '[' expr ']'
| SUPER '.' expr
| expr RANGE expr
;

optFactParams: /*empty*/
| factParams
;

factParams: expr
| factParams ',' expr
;

assignment: expr '=' expr 
| expr ASUM expr 
| expr ASUB expr 
| expr ADIV expr 
| expr AMUL expr 
| expr AMOD expr
;

whileLoop: WHILE optNewLines '(' optNewLines expr optNewLines ')' optNewLines stmt optNewLines
| WHILE optNewLines '(' optNewLines expr optNewLines ')' optNewLines block optNewLines
| WHILE optNewLines '(' optNewLines expr optNewLines ')' optNewLines ';'
;

doWhileLoop: DO optNewLines stmt optNewLines WHILE '(' expr ')'
| DO optNewLines block optNewLines WHILE '(' expr ')'
;

forLoop: FOR optNewLines '(' optNewLines ID optNewLines ':' optNewLines type optNewLines IN optNewLines expr optNewLines ')' optNewLines stmt
| FOR optNewLines '(' optNewLines ID optNewLines ':' optNewLines type optNewLines IN optNewLines expr optNewLines ')' optNewLines block
| FOR optNewLines '(' optNewLines '(' optNewLines formalParams optNewLines ')' optNewLines IN optNewLines expr optNewLines ')' optNewLines stmt
| FOR optNewLines '(' optNewLines '(' optNewLines formalParams optNewLines ')' optNewLines IN optNewLines expr optNewLines ')' optNewLines block
;

ifStmt: IF optNewLines '(' optNewLines expr optNewLines ')' optNewLines stmt
| IF optNewLines '(' optNewLines expr optNewLines ')' optNewLines block
| IF optNewLines '(' optNewLines expr optNewLines ')' optNewLines semis
| IF optNewLines '(' optNewLines expr optNewLines ')' optNewLines stmt optNewLines ELSE optNewLines stmt
| IF optNewLines '(' optNewLines expr optNewLines ')' optNewLines block optNewLines ELSE optNewLines stmt
| IF optNewLines '(' optNewLines expr optNewLines ')' optNewLines semis optNewLines ELSE optNewLines stmt
| IF optNewLines '(' optNewLines expr optNewLines ')' optNewLines stmt optNewLines ELSE optNewLines block
| IF optNewLines '(' optNewLines expr optNewLines ')' optNewLines block optNewLines ELSE optNewLines block
| IF optNewLines '(' optNewLines expr optNewLines ')' optNewLines semis optNewLines ELSE optNewLines block
| IF optNewLines '(' optNewLines expr optNewLines ')' optNewLines stmt optNewLines ELSE optNewLines semis
| IF optNewLines '(' optNewLines expr optNewLines ')' optNewLines block optNewLines ELSE optNewLines semis
| IF optNewLines '(' optNewLines expr optNewLines ')' optNewLines semis optNewLines ELSE optNewLines semis
;


optNewLines: newLines
| /*empty*/
;

newLines: NEW_LINE
| newLines NEW_LINE
;

semis: ';'
| semis ';'
| semis newLines
;


%%
//Секция пользовательского кода


void main(int argc, char **argv ){
	yyin = fopen(argv[1], "r" );

    yyparse();
    return;
}



















