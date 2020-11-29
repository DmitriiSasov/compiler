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
	int Int;
	float Float;
	double Double;
	char Char;
	char* String;
	
	char* Id;
	struct NWhile* While;
	struct NExpr* Expr;
	struct NSemi* Semi;
	struct NSemisList* Semis;
	char NewLine;
	
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
| class
| method
| stmt
| program semis
| program newLines
| program class 
| program method
| program stmt
;

class: classDeclaration classBody
| classDeclarationWithoutInheritance classBody
;

classDeclarationWithoutInheritance: inheritanceModifier visibilityModifier CLASS ID
| visibilityModifier inheritanceModifier CLASS ID
| inheritanceModifier CLASS ID
| visibilityModifier CLASS ID
| CLASS ID
;

classDeclaration: classDeclarationWithoutInheritance ':' ID
;
 
classBody: '{' classMembersList '}'
;

classMembersList: /* empty */
| classMembersList stmt
| classMembersList method
| classMembersList initializer
| classMembersList constructor
| method
| initializer
| constructor
| stmt
;

/*
property: valDeclaration
| varDeclaration
| visibilityModifier inheritanceModifier valDeclaration
| visibilityModifier inheritanceModifier varDeclaration
| inheritanceModifier visibilityModifier valDeclaration
| inheritanceModifier visibilityModifier varDeclaration 
| visibilityModifier varDeclaration
| visibilityModifier valDeclaration
| inheritanceModifier valDeclaration
| inheritanceModifier varDeclaration
| memberModifier valDeclaration
| memberModifier varDeclaration
| memberModifier visibilityModifier inheritanceModifier valDeclaration
| visibilityModifier memberModifier inheritanceModifier valDeclaration
| visibilityModifier inheritanceModifier memberModifier valDeclaration
| memberModifier visibilityModifier inheritanceModifier varDeclaration
| visibilityModifier memberModifier inheritanceModifier varDeclaration
| visibilityModifier inheritanceModifier memberModifier varDeclaration
| memberModifier inheritanceModifier visibilityModifier valDeclaration
| inheritanceModifier memberModifier visibilityModifier valDeclaration
| inheritanceModifier visibilityModifier memberModifier valDeclaration
| memberModifier inheritanceModifier visibilityModifier varDeclaration
| inheritanceModifier memberModifier visibilityModifier varDeclaration
| inheritanceModifier visibilityModifier memberModifier varDeclaration
| memberModifier visibilityModifier varDeclaration
| visibilityModifier memberModifier varDeclaration
| memberModifier visibilityModifier valDeclaration
| visibilityModifier memberModifier valDeclaration
| memberModifier inheritanceModifier varDeclaration
| inheritanceModifier memberModifier varDeclaration
| memberModifier inheritanceModifier valDeclaration
| inheritanceModifier memberModifier valDeclaration
;*/

property: valDeclaration
| varDeclaration
| visibilityModifier inheritanceModifier valDeclaration
| visibilityModifier inheritanceModifier varDeclaration
| inheritanceModifier visibilityModifier valDeclaration
| inheritanceModifier visibilityModifier varDeclaration 
| visibilityModifier varDeclaration
| visibilityModifier valDeclaration
| inheritanceModifier valDeclaration
| inheritanceModifier varDeclaration
| memberModifier valDeclaration
| memberModifier varDeclaration
| memberModifier visibilityModifier inheritanceModifier valDeclaration
| visibilityModifier memberModifier inheritanceModifier valDeclaration
| visibilityModifier inheritanceModifier memberModifier valDeclaration
| memberModifier visibilityModifier inheritanceModifier varDeclaration
| visibilityModifier memberModifier inheritanceModifier varDeclaration
| visibilityModifier inheritanceModifier memberModifier varDeclaration
| memberModifier inheritanceModifier visibilityModifier valDeclaration
| inheritanceModifier memberModifier visibilityModifier valDeclaration
| inheritanceModifier visibilityModifier memberModifier valDeclaration
| memberModifier inheritanceModifier visibilityModifier varDeclaration
| inheritanceModifier memberModifier visibilityModifier varDeclaration
| inheritanceModifier visibilityModifier memberModifier varDeclaration
| memberModifier visibilityModifier varDeclaration
| visibilityModifier memberModifier varDeclaration
| memberModifier visibilityModifier valDeclaration
| visibilityModifier memberModifier valDeclaration
| memberModifier inheritanceModifier varDeclaration
| inheritanceModifier memberModifier varDeclaration
| memberModifier inheritanceModifier valDeclaration
| inheritanceModifier memberModifier valDeclaration
;

/*
method: funcDeclaration ';'
| func
| visibilityModifier inheritanceModifier funcDeclaration ';'
| visibilityModifier inheritanceModifier func
| inheritanceModifier visibilityModifier funcDeclaration ';'
| inheritanceModifier visibilityModifier func 
| visibilityModifier func
| visibilityModifier funcDeclaration ';'
| inheritanceModifier funcDeclaration ';'
| inheritanceModifier func
| memberModifier funcDeclaration ';'
| memberModifier func
| memberModifier visibilityModifier inheritanceModifier funcDeclaration ';'
| visibilityModifier memberModifier inheritanceModifier funcDeclaration ';'
| visibilityModifier inheritanceModifier memberModifier funcDeclaration ';'
| memberModifier visibilityModifier inheritanceModifier func
| visibilityModifier memberModifier inheritanceModifier func
| visibilityModifier inheritanceModifier memberModifier func
| memberModifier inheritanceModifier visibilityModifier funcDeclaration ';'
| inheritanceModifier memberModifier visibilityModifier funcDeclaration ';'
| inheritanceModifier visibilityModifier memberModifier funcDeclaration ';'
| memberModifier inheritanceModifier visibilityModifier func
| inheritanceModifier memberModifier visibilityModifier func
| inheritanceModifier visibilityModifier memberModifier func
| memberModifier visibilityModifier func
| visibilityModifier memberModifier func
| memberModifier visibilityModifier funcDeclaration ';'
| visibilityModifier memberModifier funcDeclaration ';'
| memberModifier inheritanceModifier func
| inheritanceModifier memberModifier func
| memberModifier inheritanceModifier funcDeclaration ';'
| inheritanceModifier memberModifier funcDeclaration ';'
;*/

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

stmt : varDeclaration semis
| varDeclaration newLines
| valDeclaration semis
| valDeclaration newLines
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

whileLoop:

;

doWhileLoop: DO stmt WHILE '(' expr ')'

;

forLoop:

;

ifStmt:

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

/*
struct NSemi* createSemi()
{
	return (struct NSemi*) malloc(sizeof(struct NSemi));
}

struct NSemisList* addToSemisList(struct NSemisList* list, struct NSemi* semi)
{
	list->last->next = semi;
	list->last = semi;
}
*/


















