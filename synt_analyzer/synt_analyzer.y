%{
	Пролог
	#include "tree_nodes.h"
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





//Operators
%right '=' ASUM ASUB ADIV AMUL AMOD
%left OR
%left AND
%left EQ AEQ NEQ NAEQ
%left '<' '>' LOEQ MOEQ
%left '+' '-'
%left '/' '*' '%'
%left UMINUS


%nonassoc ')'

 
%%

program : semis
| class
| func
| program semis
| program class 
| program func 
| EOF
| program EOF

class : classDeclaration classBody
| classDeclarationWithoutConstructors classBody
;

classDeclarationWithoutConstructors: inheritanceModifier visibilityModifier CLASS ID
| visibilityModifier inheritanceModifier CLASS ID
| inheritanceModifier CLASS ID
| visibilityModifier CLASS ID
| CLASS ID
;

classDeclaration : classDeclarationWithoutConstructors '(' optParamsList ')'
| classDeclarationWithoutConstructors constructor '(' optParamsList ')'
| classDeclarationWithoutConstructors visibilityModifier constructor '(' optParamsList ')'
| classDeclarationWithoutConstructors '(' optParamsList ')' ':' ID '(' optParamsList ')'
| classDeclarationWithoutConstructors constructor '(' optFormalParams ')' ':' ID '(' optFactParams ')'
| classDeclarationWithoutConstructors visibilityModifier constructor '(' optFormalParams ')' ':' ID '(' optFactParams ')'
;
 
classBody: '{' classMembersList '}'

classMembersList: /* empty */
| classMembersList property
| classMembersList method
| classMembersList initializer
| classMembersList constructor
| property
| method
| initializer
| constructor
;

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
;


initializer: INIT block
;


memberModifier: override
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
| funcDeclaration '=' expr
;


funcDeclaration: FUN ID '(' optFormalParams ')'
| FUN ID '(' optFormalParams ')' ':' type
;


block : '{' newLines stmts newLines '}'
| '{' stmts newLines '}'
| '{' newLines stmts '}'
| '{' stmts '}'
;


varDeclaration: var ID '=' expr


valDeclaration: val ID '=' expr


type: INT
| UNIT
| ID
| 
;


stmt : label semis
| varDeclaration semis
| valDeclaration semis
| assignment semis
| whileLoop semis
| forLoop semis
| doWhileLoop semis
| ifStmt semis
| expr semis




stmts : stmt
| stmts stmt
;

semis:

semi:



%%
//Секция пользовательского кода
struct NSemi* createSemi()
{
	return (struct NSemi*) malloc(sizeof(struct NSemi));
}

struct NSemisList* addToSemisList(struct NSemisList* list, struct NSemi* semi)
{
	list->last->next = semi;
	list->last = semi;
}


















