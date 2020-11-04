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

class : 


classDeclaration: visibilityModifier CLASS ID 
| CLASS ID

 
classBody: '{' 

visibilityModifier: PUBLIC
| PRIVATE
| INTERNAL
| PROTECTED
;




func : 


func_body : block
| '=' newLines expr
| '=' expr


block : '{' newLines stmts newLines '}'
| '{' stmts newLines '}'
| '{' newLines stmts '}'
| '{' stmts '}'

stmt : label semis
| declaration semis
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


!!! Придумать, что делать с подряд идущими ;;;


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


















