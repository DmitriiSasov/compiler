%define parse.error verbose

%{

	#include <stdio.h>
	#include "tree_nodes.h"
	void yyerror(const char* message) {
		fprintf(stderr, message);
	}
	int yylex();
	int yyparse();
	extern FILE* yyin;
%}
//Секция объявлений
%union {
	int Int_v;
	float Float_v;
	double Double_v;
	char Char_v;
	char * String_v;
	char * Id;
	bool Bool_v;
}


/*
%type <> 
%type <> 
%type <> 
%type <> 
%type <> 
%type <> 
%type <> 
%type <> 
%type <> 
%type <> 
%type <> 
%type <> 
%type <> 
%type <> 
%type <> 
%type <> 
%type <> 
%type <> 
%type <> 
%type <> 
%type <> 
%type <> 
%type <> 
%type <> 
%type <> 
%type <> 
%type <> 
%type <> 
%type <> 
%type <> 
%type <> 
%type <> 
%type <> 
%type <> 
%type <> 
%type <> 
%type <> 
%type <> 
*/







%token NEW_LINE
%token <Id> ID
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
%token <Int_v> INT
%token <Float_v> FLOAT
%token <Double_v> DOUBLE
%token <String_v> STRING
%token <Char_v> CHAR
%token <Bool_v> BOOLEAN
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
| class
| method
| property semis
| property newLines
| program class
| program method
| program property semis
| program property newLines
| program newLines
| program semis
; 

class: modifiers optNewLines CLASS optNewLines ID optNewLines ':' optNewLines ID optNewLines '{' optNewLines classBody '}'
| modifiers optNewLines CLASS optNewLines ID optNewLines '{' optNewLines classBody '}'
;

classBody: semis
| newLines
| method
| property semis
| property newLines
| constructor
| initializer
| classBody method
| classBody property semis
| classBody property newLines
| classBody newLines
| classBody constructor
| classBody initializer
| classBody semis
;

property: modifiers optNewLines valDeclaration
| modifiers optNewLines varDeclaration
;

method: modifiers optNewLines funcDeclaration ';'
| modifiers optNewLines func
;

initializer: INIT optNewLines block
;


constructor: visibilityModifier optNewLines CONSTRUCTOR optNewLines '(' optNewLines optFormalParams optNewLines ')' optNewLines block
| visibilityModifier optNewLines CONSTRUCTOR optNewLines '(' optNewLines optFormalParams optNewLines ')'
| visibilityModifier optNewLines CONSTRUCTOR optNewLines '(' optNewLines optFormalParams optNewLines ')' optNewLines ':' optNewLines SUPER optNewLines '(' optNewLines optFactParams optNewLines ')'
| visibilityModifier optNewLines CONSTRUCTOR optNewLines '(' optNewLines optFormalParams optNewLines ')'  optNewLines ':' optNewLines THIS optNewLines '(' optNewLines optFactParams optNewLines ')' 
| visibilityModifier optNewLines CONSTRUCTOR optNewLines '(' optNewLines optFormalParams optNewLines ')'  optNewLines ':' optNewLines SUPER optNewLines '(' optNewLines optFactParams optNewLines ')' optNewLines block
| visibilityModifier optNewLines CONSTRUCTOR optNewLines '(' optNewLines optFormalParams optNewLines ')' optNewLines ':' optNewLines THIS optNewLines '(' optNewLines optFactParams optNewLines ')' optNewLines block
| CONSTRUCTOR optNewLines '(' optNewLines optFormalParams optNewLines ')' optNewLines block
| CONSTRUCTOR optNewLines '(' optNewLines optFormalParams optNewLines ')'
| CONSTRUCTOR optNewLines '(' optNewLines optFormalParams optNewLines ')' optNewLines ':' optNewLines SUPER optNewLines '(' optNewLines optFactParams optNewLines ')'
| CONSTRUCTOR optNewLines '(' optNewLines optFormalParams optNewLines ')'  optNewLines ':' optNewLines THIS optNewLines '(' optNewLines optFactParams optNewLines ')' 
| CONSTRUCTOR optNewLines '(' optNewLines optFormalParams optNewLines ')'  optNewLines ':' optNewLines SUPER optNewLines '(' optNewLines optFactParams optNewLines ')' optNewLines block
| CONSTRUCTOR optNewLines '(' optNewLines optFormalParams optNewLines ')' optNewLines ':' optNewLines THIS optNewLines '(' optNewLines optFactParams optNewLines ')' optNewLines block
;

optFormalParams: /*empty*/
| formalParams
;

formalParams: ID optNewLines ':' optNewLines type
| formalParams optNewLines ',' optNewLines ID optNewLines ':' optNewLines type
;

modifiers: OVERRIDE
| visibilityModifier
| inheritanceModifier
| ABSTRACT
| OVERRIDE optNewLines  visibilityModifier
| OVERRIDE optNewLines  inheritanceModifier
| OVERRIDE optNewLines  ABSTRACT
| visibilityModifier optNewLines  OVERRIDE
| visibilityModifier optNewLines  inheritanceModifier
| visibilityModifier optNewLines  ABSTRACT
| inheritanceModifier optNewLines  OVERRIDE
| inheritanceModifier optNewLines  visibilityModifier
| inheritanceModifier optNewLines  ABSTRACT
| ABSTRACT optNewLines  OVERRIDE
| ABSTRACT optNewLines  visibilityModifier
| ABSTRACT optNewLines  inheritanceModifier
| OVERRIDE optNewLines visibilityModifier optNewLines inheritanceModifier
| OVERRIDE optNewLines visibilityModifier optNewLines ABSTRACT
| OVERRIDE optNewLines inheritanceModifier optNewLines visibilityModifier
| OVERRIDE optNewLines inheritanceModifier optNewLines ABSTRACT
| OVERRIDE optNewLines ABSTRACT optNewLines visibilityModifier
| OVERRIDE optNewLines ABSTRACT optNewLines inheritanceModifier
| visibilityModifier optNewLines OVERRIDE optNewLines inheritanceModifier
| visibilityModifier optNewLines OVERRIDE optNewLines ABSTRACT
| visibilityModifier optNewLines inheritanceModifier optNewLines OVERRIDE
| visibilityModifier optNewLines inheritanceModifier optNewLines ABSTRACT
| visibilityModifier optNewLines ABSTRACT optNewLines inheritanceModifier
| visibilityModifier optNewLines ABSTRACT optNewLines OVERRIDE
| inheritanceModifier optNewLines OVERRIDE optNewLines visibilityModifier
| inheritanceModifier optNewLines OVERRIDE optNewLines ABSTRACT
| inheritanceModifier optNewLines visibilityModifier optNewLines ABSTRACT
| inheritanceModifier optNewLines visibilityModifier optNewLines OVERRIDE
| inheritanceModifier optNewLines ABSTRACT optNewLines visibilityModifier
| inheritanceModifier optNewLines ABSTRACT optNewLines OVERRIDE
| ABSTRACT optNewLines OVERRIDE optNewLines inheritanceModifier
| ABSTRACT optNewLines OVERRIDE optNewLines visibilityModifier
| ABSTRACT optNewLines visibilityModifier optNewLines OVERRIDE
| ABSTRACT optNewLines visibilityModifier optNewLines inheritanceModifier
| ABSTRACT optNewLines inheritanceModifier optNewLines OVERRIDE
| ABSTRACT optNewLines inheritanceModifier optNewLines visibilityModifier
| OVERRIDE optNewLines visibilityModifier optNewLines inheritanceModifier optNewLines ABSTRACT
| OVERRIDE optNewLines visibilityModifier optNewLines ABSTRACT optNewLines inheritanceModifier
| OVERRIDE optNewLines inheritanceModifier optNewLines visibilityModifier optNewLines ABSTRACT
| OVERRIDE optNewLines inheritanceModifier optNewLines ABSTRACT optNewLines visibilityModifier
| OVERRIDE optNewLines ABSTRACT optNewLines visibilityModifier optNewLines inheritanceModifier
| OVERRIDE optNewLines ABSTRACT optNewLines inheritanceModifier optNewLines visibilityModifier
| visibilityModifier optNewLines OVERRIDE optNewLines inheritanceModifier optNewLines ABSTRACT
| visibilityModifier optNewLines OVERRIDE optNewLines ABSTRACT optNewLines inheritanceModifier
| visibilityModifier optNewLines inheritanceModifier optNewLines OVERRIDE optNewLines ABSTRACT
| visibilityModifier optNewLines inheritanceModifier optNewLines ABSTRACT optNewLines OVERRIDE
| visibilityModifier optNewLines ABSTRACT optNewLines inheritanceModifier optNewLines OVERRIDE
| visibilityModifier optNewLines ABSTRACT optNewLines OVERRIDE optNewLines inheritanceModifier
| inheritanceModifier optNewLines OVERRIDE optNewLines visibilityModifier optNewLines ABSTRACT
| inheritanceModifier optNewLines OVERRIDE optNewLines ABSTRACT optNewLines visibilityModifier
| inheritanceModifier optNewLines visibilityModifier optNewLines ABSTRACT optNewLines OVERRIDE
| inheritanceModifier optNewLines visibilityModifier optNewLines OVERRIDE optNewLines ABSTRACT
| inheritanceModifier optNewLines ABSTRACT optNewLines visibilityModifier optNewLines OVERRIDE
| inheritanceModifier optNewLines ABSTRACT optNewLines OVERRIDE optNewLines visibilityModifier
| ABSTRACT optNewLines OVERRIDE optNewLines inheritanceModifier optNewLines visibilityModifier
| ABSTRACT optNewLines OVERRIDE optNewLines visibilityModifier optNewLines inheritanceModifier
| ABSTRACT optNewLines visibilityModifier optNewLines OVERRIDE optNewLines inheritanceModifier
| ABSTRACT optNewLines visibilityModifier optNewLines inheritanceModifier optNewLines OVERRIDE
| ABSTRACT optNewLines inheritanceModifier optNewLines OVERRIDE optNewLines visibilityModifier
| ABSTRACT optNewLines inheritanceModifier optNewLines visibilityModifier optNewLines OVERRIDE
;

visibilityModifier: PUBLIC
| PRIVATE
| INTERNAL
| PROTECTED
;


inheritanceModifier: FINAL
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
| property newLines
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
| ID '(' optNewLines optFactParams optNewLines ')'
| INT 
| FLOAT 
| STRING 
| CHAR 
| DOUBLE 
| BOOLEAN
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
| expr '.' ID 
| expr '.' ID '(' optNewLines optFactParams optNewLines ')'
| expr '[' expr ']'
| SUPER '.' ID
| SUPER '.' ID '(' optNewLines optFactParams optNewLines ')'
| expr RANGE expr
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
| newLines NEW_LINE 
;

semis: ';'
| semis ';'
;


%%
//Секция пользовательского кода


void main(int argc, char **argv ){
	yyin = fopen(argv[1], "r" );

    yyparse();
    return;
}



















