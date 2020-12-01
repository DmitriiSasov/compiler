%define parse.error verbose

%{

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
%token VAL
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

class: classDeclaration optNewLines block
| classDeclarationWithoutInheritance optNewLines block
;

classDeclarationWithoutInheritance: inheritanceModifier optNewLines optVisibilityModifier optNewLines CLASS optNewLines ID
| optVisibilityModifier optNewLines inheritanceModifier optNewLines CLASS optNewLines ID
| CLASS optNewLines ID
;

classDeclaration: classDeclarationWithoutInheritance optNewLines ':' optNewLines ID
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


initializer: INIT optNewLines block
;


constructor: optVisibilityModifier optNewLines CONSTRUCTOR optNewLines '(' optNewLines optFormalParams optNewLines ')' optNewLines block
| optVisibilityModifier optNewLines CONSTRUCTOR optNewLines '(' optNewLines optFormalParams optNewLines ')'
| optVisibilityModifier optNewLines CONSTRUCTOR optNewLines '(' optNewLines optFormalParams optNewLines ')' optNewLines ':' optNewLines SUPER optNewLines '(' optNewLines optFactParams optNewLines ')'
| optVisibilityModifier optNewLines CONSTRUCTOR optNewLines '(' optNewLines optFormalParams optNewLines ')'  optNewLines ':' optNewLines THIS optNewLines '(' optNewLines optFactParams optNewLines ')' 
| optVisibilityModifier optNewLines CONSTRUCTOR optNewLines '(' optNewLines optFormalParams optNewLines ')'  optNewLines ':' optNewLines SUPER optNewLines '(' optNewLines optFactParams optNewLines ')' optNewLines block
| optVisibilityModifier optNewLines CONSTRUCTOR optNewLines '(' optNewLines optFormalParams optNewLines ')' optNewLines ':' optNewLines THIS optNewLines '(' optNewLines optFactParams optNewLines ')' optNewLines block
;

optVisibilityModifier: /*empty*/
| visibilityModifier
;


optFormalParams: /*empty*/
| formalParams
;


formalParams: ID optNewLines ':' optNewLines type
| formalParams optNewLines ',' optNewLines ID optNewLines ':' optNewLines type
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


func : funcDeclaration optNewLines block
| funcDeclaration optNewLines '=' optNewLines expr
;


funcDeclaration: FUN optNewLines ID optNewLines '(' optNewLines optFormalParams optNewLines ')' optNewLines ':' optNewLines type
;


block : '{' optNewLines stmts optNewLines'}'
| '{' semis stmts '}'
| '{' semis '}'
| '{' optNewLines '}'
;


varDeclaration: VAR optNewLines ID optNewLines ':' optNewLines type
| VAR optNewLines ID optNewLines ':' optNewLines type optNewLines '=' optNewLines expr
| VAR optNewLines ID optNewLines '(' optNewLines formalParams optNewLines ')' optNewLines '=' optNewLines expr
;


valDeclaration: VAL optNewLines ID optNewLines ':' optNewLines type 
| VAL optNewLines ID optNewLines ':' optNewLines type optNewLines '=' optNewLines expr
| VAL optNewLines ID optNewLines '(' optNewLines formalParams optNewLines ')' optNewLines '=' optNewLines expr
;

type: ID
| templateType
;

templateType: ID optNewLines '<' optNewLines type_seq optNewLines '>'
| ID optNewLines '<' optNewLines templateType optNewLines '>'
;

type_seq: ID
| type_seq optNewLines ',' optNewLines ID
;

stmts : stmt
| stmts stmt
;

stmt : property semis
| property NEW_LINE
| method semis
| method NEW_LINE
| class semis
| class NEW_LINE
| constructor semis
| constructor NEW_LINE
| initializer semis
| initializer NEW_LINE
| assignment semis
| assignment NEW_LINE
| whileLoop semis
| whileLoop NEW_LINE
| forLoop semis
| forLoop NEW_LINE
| doWhileLoop semis
| doWhileLoop NEW_LINE
| ifStmt semis
| ifStmt NEW_LINE
//| expr NEW_LINE
| expr semis
| BREAK semis
| BREAK NEW_LINE
| CONTINUE semis
| CONTINUE NEW_LINE
| RETURN semis
| RETURN NEW_LINE
| RETURN expr NEW_LINE
| RETURN expr semis
;

expr: ID 
| THIS 
| expr optNewLines '(' optNewLines optFactParams optNewLines ')'
| INT 
| FLOAT 
| STRING 
| CHAR 
| DOUBLE 
| BOOLEAN 
| TRUE 
| FALSE 
| '(' optNewLines expr optNewLines ')' 
| '!' optNewLines expr 
| '+' optNewLines expr %prec UPLUS
| '-' optNewLines expr %prec UMINUS
| expr '+' optNewLines expr 
| expr '-' optNewLines expr 
| expr '*' optNewLines expr 
| expr '/' optNewLines expr 
| expr '%' optNewLines expr 
| expr '<' optNewLines expr 
| expr '>' optNewLines expr 
| expr OR optNewLines expr 
| expr AND optNewLines expr 
| expr EQ optNewLines expr 
| expr AEQ optNewLines expr 
| expr NEQ optNewLines expr 
| expr NAEQ optNewLines expr
| expr LOEQ optNewLines expr
| expr MOEQ optNewLines expr
| expr '.' optNewLines expr
| expr '[' optNewLines expr optNewLines ']'
| SUPER '.' optNewLines expr
| expr RANGE optNewLines expr
;

optFactParams: /*empty*/
| factParams
;

factParams: expr
| factParams optNewLines ',' optNewLines expr
;

assignment: expr '=' optNewLines expr 
| expr ASUM optNewLines expr 
| expr ASUB optNewLines expr 
| expr ADIV optNewLines expr 
| expr AMUL optNewLines expr 
| expr AMOD optNewLines expr
;

whileLoop: WHILE optNewLines '(' optNewLines expr optNewLines ')' optNewLines stmt
| WHILE optNewLines '(' optNewLines expr optNewLines ')' optNewLines block
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


optNewLines: /*empty*/
| newLines
;

newLines: NEW_LINE
| NEW_LINE newLines
;

semis: ';'
| semis ';'
//| semis newLines
;


%%
//Секция пользовательского кода


void main(int argc, char **argv ){
	yyin = fopen(argv[1], "r" );

    yyparse();
    return;
}



















