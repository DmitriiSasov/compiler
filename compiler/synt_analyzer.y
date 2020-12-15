%define parse.error verbose

%{

	#include <stdio.h>
	#include "create_tree.h"
	void yyerror(const char* message) {
		fprintf(stderr, message);
	}
	int yylex();
	int yyparse();
	extern FILE* yyin;
	
	struct programS * root;
	
	
%}
//Секция объявлений
%union {
	int Int_v;
	float Float_v;
	double Double_v;
	char Char_v;
	char * IdOrString;
	bool Bool_v;
	
	enum visibilityMod visibilityModU;
	enum inheritanceMod inheritanceModU;
	
	struct modifiersS * modifiersU;
	struct exprS * exprU;
	struct factParamsList * factParamsListU;
	struct stmtS * stmtU;
	struct stmtList * stmtListU;
	struct ifStmtS * ifStmtU;
	struct forLoopS * forLoopU;
	struct whileLoopS * whileLoopU;
	struct assignmentS * assignmentU;
	struct propertyS * propertyU;
	struct varOrValDeclS * varOrValDeclU;
	struct typeS * typeU;
	struct templateTypeS * templateTypeU;
	struct typesList * typesListU;
	struct formalParamS * formalParamU;
	struct formalParamsList * formalParamsListU;
	struct funcDeclS * funcDeclU;
	struct funcS * funcU;
	struct constructorS * constructorU;
	struct methodS * methodU;
	struct initializerS * initializerU;
	struct classS * classU;
	struct classBodyElementS * classBodyElementU;
	struct classBodyS * classBodyU;
	struct programElementS * programElementU;
	struct programS * programU;
}

%type <programU> program
%type <classU> class
%type <classBodyU> classBody
%type <propertyU> property
%type <methodU> method
%type <initializerU> initializer
%type <constructorU> constructor
%type <formalParamsListU> optFormalParams
%type <formalParamsListU> formalParams
%type <modifiersU> modifiers
%type <visibilityModU> visibilityModifier
%type <inheritanceModU> inheritanceModifier
%type <funcU> func
%type <funcDeclU> funcDeclaration
%type <stmtListU> block
%type <varOrValDeclU> varDeclaration
%type <varOrValDeclU> valDeclaration
%type <typeU> type
%type <templateTypeU> templateType
%type <typesListU> type_seq
%type <stmtListU> stmts
%type <stmtU> stmt
%type <exprU> expr
%type <factParamsListU> optFactParams
%type <factParamsListU> factParams
%type <assignmentU> assignment
%type <whileLoopU> whileLoop
%type <whileLoopU> doWhileLoop
%type <forLoopU> forLoop
%type <ifStmtU> ifStmt

%token NEW_LINE
%token <IdOrString> ID
%token <IdOrString> STR
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
%token <Char_v> CHR
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


program: semis	{root = createProgram(); puts("program created");}
| newLines {root = createProgram(); puts("program created");}
| class	{root = createProgram($1);puts("program created");}
| method	{root = createProgram($1);puts("program created");}
| valDeclaration semis	{root = createProgram(createProperty($1));puts("program created");}
| varDeclaration semis	{root = createProgram(createProperty($1));puts("program created");}
| visibilityModifier valDeclaration semis	{root = createProgram(createProperty(createModifiers(0, 0, $1, None), $2));puts("program created");}
| visibilityModifier varDeclaration semis	{root = createProgram(createProperty(createModifiers(0, 0, $1, None), $2));puts("program created");}
| valDeclaration newLines	{root = createProgram(createProperty($1));puts("program created");}
| varDeclaration newLines	{root = createProgram(createProperty($1));puts("program created");}
| visibilityModifier valDeclaration newLines	{root = createProgram(createProperty(createModifiers(0, 0, $1, None), $2));puts("program created");}
| visibilityModifier varDeclaration newLines	{root = createProgram(createProperty(createModifiers(0, 0, $1, None), $2));puts("program created");}
| program class	{root = addToProgram(root, $2);puts("class added to prog");}
| program method	{root = addToProgram(root, $2);puts("meth added to prog");}
| program valDeclaration semis	{root = addToProgram(root, createProperty($2));puts("prop added to prog");}
| program varDeclaration semis	{root = addToProgram(root, createProperty($2));puts("prop added to prog");}
| program visibilityModifier valDeclaration semis	{root = addToProgram(root, createProperty(createModifiers(0, 0, $2, None), $3));puts("prop added to prog");}
| program visibilityModifier varDeclaration semis	{root = addToProgram(root, createProperty(createModifiers(0, 0, $2, None), $3));puts("prop added to prog");}
| program valDeclaration newLines	{root = addToProgram(root, createProperty($2));puts("prop added to prog");}
| program varDeclaration newLines	{root = addToProgram(root, createProperty($2));puts("prop added to prog");}
| program visibilityModifier valDeclaration newLines	{root = addToProgram(root, createProperty(createModifiers(0, 0, $2, None), $3));puts("prop added to prog");}
| program visibilityModifier varDeclaration newLines	{root = addToProgram(root, createProperty(createModifiers(0, 0, $2, None), $3));puts("prop added to prog");}
| program semis {root = root;}
| program newLines {root = root;}
; 

class: modifiers CLASS ID ':' ID  '{' classBody '}'	{$$ = createClass($1, $3, $5, $7);puts("class created");}
| modifiers CLASS ID '{' classBody '}'	{$$ = createClass($1, $3, $5); puts("class created");}
| CLASS ID ':' ID '{' classBody '}'	{$$ = createClass($2, $4, $6); puts("class created");}
| CLASS ID '{' classBody '}'	{$$ = createClass($2, $4); puts("class created");}
| modifiers CLASS ID ':' ID '{' '}'	{$$ = createClass($1, $3, $5, createClassBody()); puts("class created");}
| modifiers CLASS  ID  '{' '}'	{$$ = createClass($1, $3, createClassBody()); puts("class created");}
| CLASS  ID  ':'  ID '{' '}'	{$$ = createClass($2, $4, createClassBody()); puts("class created");}
| CLASS ID '{' '}'	{$$ = createClass($2, createClassBody()); puts("class created");}
;

classBody: semis 	{$$ = createClassBody(); puts("class body created");}
| newLines 	{$$ = createClassBody(); puts("class body created");}
| method	{$$ = createClassBody($1);  puts("class body created");}
| property semis	{$$ = createClassBody($1);  puts("class body created");}
| property newLines	{$$ = createClassBody($1);  puts("class body created");}
| constructor	{$$ = createClassBody($1);  puts("class body created");}
| initializer	{$$ = createClassBody($1);  puts("class body created");}
| classBody method	{$$ = addToClassBody($1, $2);  puts("meth added to class body");}
| classBody property semis	{$$ = addToClassBody($1, $2); puts("prop added to class body");}
| classBody property newLines	{$$ = addToClassBody($1, $2); puts("prop added to class body");}
| classBody constructor	{$$ = addToClassBody($1, $2); puts("constr added to class body");}
| classBody initializer	{$$ = addToClassBody($1, $2); puts("init added to class body");}
| classBody semis	{$$ = $1; puts("semis added to class body");}
| classBody newLines	{$$ = $1; puts("newLines added to class body");}
;

property: modifiers valDeclaration	{$$ = createProperty($1, $2); puts("prop created");}
| modifiers varDeclaration	{$$ = createProperty($1, $2); puts("prop created");}
| valDeclaration	{$$ = createProperty($1); puts("prop created");}
| varDeclaration	{$$ = createProperty($1); puts("prop created");}
;

method: modifiers funcDeclaration semis	{$$ = createMethod($1, $2); puts("meth created");}
| modifiers funcDeclaration newLines	{$$ = createMethod($1, $2); puts("meth created");}
| modifiers func	{$$ = createMethod($1, $2); puts("meth created");}
| funcDeclaration semis	{$$ = createMethod($1); puts("meth created");}
| funcDeclaration newLines	{$$ = createMethod($1); puts("meth created");}
| func	{$$ = createMethod($1); puts("meth created");}
;

initializer: INIT block	{$$ = createInit($2); puts("init created");}
;

 
constructor: visibilityModifier CONSTRUCTOR '(' optFormalParams ')' block	{$$ = createConstructor($1, $4, $6); puts("constr created");}
| visibilityModifier CONSTRUCTOR '(' optFormalParams ')'	{$$ = createConstructor($1, $4); puts("constr created");}
| visibilityModifier CONSTRUCTOR '(' optFormalParams ')' ':' SUPER '(' optFactParams ')'	{$$ = createConstructor($1, $4, "super", $9); puts("constr created");}
| visibilityModifier CONSTRUCTOR '(' optFormalParams ')'  ':' THIS '(' optFactParams ')' 	{$$ = createConstructor($1, $4, "this", $9); puts("constr created");}
| visibilityModifier CONSTRUCTOR '(' optFormalParams ')'  ':' SUPER '(' optFactParams ')' block	{$$ = createConstructor($1, $4, "super", $9, $11); puts("constr created");}
| visibilityModifier CONSTRUCTOR '(' optFormalParams ')' ':' THIS '(' optFactParams ')' block	{$$ = createConstructor($1, $4, "this", $9, $11); puts("constr created");}
| CONSTRUCTOR '(' optFormalParams ')' block 	{$$ = createConstructor($3, $5); puts("constr created");}
| CONSTRUCTOR '(' optFormalParams ')' 	{$$ = createConstructor($3); puts("constr created");}
| CONSTRUCTOR '(' optFormalParams ')' ':' SUPER '(' optFactParams ')'	{$$ = createConstructor($3, "super", $8); puts("constr created");}
| CONSTRUCTOR '(' optFormalParams ')'  ':' THIS '(' optFactParams ')' 	{$$ = createConstructor($3, "this", $8); puts("constr created");}
| CONSTRUCTOR '(' optFormalParams ')'  ':' SUPER '(' optFactParams ')' block	{$$ = createConstructor($3, "super", $8, $10); puts("constr created");}
| CONSTRUCTOR '(' optFormalParams ')' ':' THIS '(' optFactParams ')' block	{$$ = createConstructor($3, "this", $8, $10); puts("constr created");}
;

optFormalParams: /*empty*/	{$$ = 0; puts("opt formal params created");}
| formalParams	{$$ = $1; puts("opt formal params created");}
;

formalParams: ID ':' type	{$$ = createFormalParamsList($1, $3); puts("formal params created");}
| formalParams ',' ID ':' type	{$$ = addToFormalParamsList($1, $3, $5); puts("formal params created");}
;

modifiers: OVERRIDE	{$$ = createModifiers(0, 1, Unknown, None); puts("mods created");}
| visibilityModifier	{$$ = createModifiers(0, 0, $1, None); puts("mods created");}
| inheritanceModifier	{$$ = createModifiers(0, 0, Unknown, $1); puts("mods created");}
| ABSTRACT	{$$ = createModifiers(1, 0, Unknown, None); puts("mods created");}
| OVERRIDE visibilityModifier	{$$ = createModifiers(0, 1, $2, None); puts("mods created");}
| OVERRIDE inheritanceModifier	{$$ = createModifiers(0, 1, Unknown, $2); puts("mods created");}
| OVERRIDE ABSTRACT	{$$ = createModifiers(1, 1, Unknown, None); puts("mods created");}
| visibilityModifier OVERRIDE	{$$ = createModifiers(0, 1, $1, None); puts("mods created"); }
| visibilityModifier inheritanceModifier	{$$ = createModifiers(0, 0, $1, $2); puts("mods created");}
| visibilityModifier ABSTRACT	{$$ = createModifiers(1, 0, $1, None); puts("mods created"); }
| inheritanceModifier OVERRIDE	{$$ = createModifiers(0, 1, Unknown, $1); puts("mods created");}
| inheritanceModifier visibilityModifier	{$$ = createModifiers(0, 0, $2, $1); puts("mods created");}
| inheritanceModifier ABSTRACT 	{$$ = createModifiers(1, 0, Unknown, $1); puts("mods created");}
| ABSTRACT OVERRIDE	{$$ = createModifiers(1, 1, Unknown, None); puts("mods created");}
| ABSTRACT visibilityModifier 	{$$ = createModifiers(1, 0, $2, None); puts("mods created");}
| ABSTRACT inheritanceModifier	{$$ = createModifiers(1, 0, Unknown, $2); puts("mods created");}
| OVERRIDE visibilityModifier inheritanceModifier	{$$ = createModifiers(0, 1, $2, $3); puts("mods created");}
| OVERRIDE visibilityModifier ABSTRACT	{$$ = createModifiers(1, 1, $2, None); puts("mods created");}
| OVERRIDE inheritanceModifier visibilityModifier	{$$ = createModifiers(0, 1, $3, $2); puts("mods created");}
| OVERRIDE inheritanceModifier ABSTRACT	{$$ = createModifiers(1, 1, Unknown, $2); puts("mods created");}
| OVERRIDE ABSTRACT visibilityModifier	{$$ = createModifiers(1, 1, $3, None); puts("mods created");}
| OVERRIDE ABSTRACT inheritanceModifier	{$$ = createModifiers(1, 1, Unknown, $3); puts("mods created");}
| visibilityModifier OVERRIDE inheritanceModifier	{$$ = createModifiers(0, 1, $1, $3); puts("mods created");}
| visibilityModifier OVERRIDE ABSTRACT	{$$ = createModifiers(1, 1, $1, None); puts("mods created");}
| visibilityModifier inheritanceModifier OVERRIDE 	{$$ = createModifiers(0, 1, $1, $2); puts("mods created");}
| visibilityModifier inheritanceModifier ABSTRACT	{$$ = createModifiers(1, 0, $1, $2); puts("mods created");}
| visibilityModifier ABSTRACT inheritanceModifier	{$$ = createModifiers(1, 0, $1, $3); puts("mods created");}
| visibilityModifier ABSTRACT OVERRIDE	{$$ = createModifiers(1, 1, $1, None); puts("mods created");}
| inheritanceModifier OVERRIDE visibilityModifier 	{$$ = createModifiers(0, 1, $3, $1); puts("mods created");}
| inheritanceModifier OVERRIDE ABSTRACT	{$$ = createModifiers(1, 1, Unknown, $1); puts("mods created");}
| inheritanceModifier visibilityModifier ABSTRACT	{$$ = createModifiers(1, 0, $2, $1); puts("mods created");}
| inheritanceModifier visibilityModifier OVERRIDE	{$$ = createModifiers(0, 1, $2, $1); puts("mods created");}
| inheritanceModifier ABSTRACT visibilityModifier 	{$$ = createModifiers(1, 0, $3, $1); puts("mods created");}
| inheritanceModifier ABSTRACT OVERRIDE	{$$ = createModifiers(1, 1, Unknown, $1); puts("mods created");}
| ABSTRACT OVERRIDE inheritanceModifier	{$$ = createModifiers(1, 1, Unknown, $3); puts("mods created");}
| ABSTRACT OVERRIDE visibilityModifier	{$$ = createModifiers(1, 1, $3, None); puts("mods created");}
| ABSTRACT visibilityModifier OVERRIDE	{$$ = createModifiers(1, 1, $2, None); puts("mods created");}
| ABSTRACT visibilityModifier inheritanceModifier	{$$ = createModifiers(1, 0, $2, $3); puts("mods created");}
| ABSTRACT inheritanceModifier OVERRIDE	{$$ = createModifiers(1, 1, Unknown, $2); puts("mods created");}
| ABSTRACT inheritanceModifier visibilityModifier	{$$ = createModifiers(1, 0, $3, $2); puts("mods created");}
| OVERRIDE visibilityModifier inheritanceModifier ABSTRACT	{$$ = createModifiers(1, 1, $2, $3); puts("mods created");}
| OVERRIDE visibilityModifier ABSTRACT inheritanceModifier	{$$ = createModifiers(1, 1, $2, $4); puts("mods created");}
| OVERRIDE inheritanceModifier visibilityModifier ABSTRACT	{$$ = createModifiers(1, 1, $3, $2); puts("mods created");}
| OVERRIDE inheritanceModifier ABSTRACT visibilityModifier	{$$ = createModifiers(1, 1, $4, $2); puts("mods created");}
| OVERRIDE ABSTRACT visibilityModifier inheritanceModifier	{$$ = createModifiers(1, 1, $3, $4); puts("mods created");}
| OVERRIDE ABSTRACT inheritanceModifier visibilityModifier	{$$ = createModifiers(1, 1, $4, $3); puts("mods created");}
| visibilityModifier OVERRIDE inheritanceModifier ABSTRACT	{$$ = createModifiers(1, 1, $1, $3); puts("mods created");}
| visibilityModifier OVERRIDE ABSTRACT inheritanceModifier	{$$ = createModifiers(1, 1, $1, $4); puts("mods created");}
| visibilityModifier inheritanceModifier OVERRIDE ABSTRACT	{$$ = createModifiers(1, 1, $1, $2); puts("mods created");}
| visibilityModifier inheritanceModifier ABSTRACT OVERRIDE	{$$ = createModifiers(1, 1, $1, $2); puts("mods created");}
| visibilityModifier ABSTRACT inheritanceModifier OVERRIDE	{$$ = createModifiers(1, 1, $1, $3); puts("mods created");}
| visibilityModifier ABSTRACT OVERRIDE inheritanceModifier	{$$ = createModifiers(1, 1, $1, $4); puts("mods created");}
| inheritanceModifier OVERRIDE visibilityModifier ABSTRACT	{$$ = createModifiers(1, 1, $3, $1); puts("mods created");}
| inheritanceModifier OVERRIDE ABSTRACT visibilityModifier	{$$ = createModifiers(1, 1, $4, $1); puts("mods created");}
| inheritanceModifier visibilityModifier ABSTRACT OVERRIDE
	{$$ = createModifiers(1, 1, $2, $1); puts("mods created");}
| inheritanceModifier visibilityModifier OVERRIDE ABSTRACT
	{$$ = createModifiers(1, 1, $2, $1); puts("mods created");}
| inheritanceModifier ABSTRACT visibilityModifier OVERRIDE
	{$$ = createModifiers(1, 1, $3, $1); puts("mods created");}
| inheritanceModifier ABSTRACT OVERRIDE visibilityModifier
	{$$ = createModifiers(1, 1, $4, $1); puts("mods created");}
| ABSTRACT OVERRIDE inheritanceModifier visibilityModifier
	{$$ = createModifiers(1, 1, $4, $3); puts("mods created");}
| ABSTRACT OVERRIDE visibilityModifier inheritanceModifier
	{$$ = createModifiers(1, 1, $3, $4); puts("mods created");}
| ABSTRACT visibilityModifier OVERRIDE inheritanceModifier	{$$ = createModifiers(1, 1, $2, $4); puts("mods created");}
| ABSTRACT visibilityModifier inheritanceModifier OVERRIDE	{$$ = createModifiers(1, 1, $2, $3); puts("mods created");}
| ABSTRACT inheritanceModifier OVERRIDE visibilityModifier
	{$$ = createModifiers(1, 1, $4, $2); puts("mods created");}
| ABSTRACT inheritanceModifier visibilityModifier OVERRIDE
	{$$ = createModifiers(1, 1, $3, $2); puts("mods created");}
;

visibilityModifier: PUBLIC	{$$ = Public;}
| PRIVATE	{$$ = Private;}
| INTERNAL	{$$ = Internal;}
| PROTECTED	{$$ = Protected;}
;


inheritanceModifier: FINAL {$$ = Final;}
| OPEN {$$ = Open;}
;

func : funcDeclaration block	{$$ = createFunc($1, $2); puts("func created");}
| funcDeclaration '=' expr	{$$ = createFunc($1, $3); puts("func created");}
;


funcDeclaration: FUN ID '(' optFormalParams ')' ':' type	{$$ = createFuncDecl($2, $4, $7);  puts("func decl created");}
;


block : optNewLines '{' semis stmts '}'	{$$ = $4;  puts("block created");}
| optNewLines '{' semis '}'	{$$ = 0;  puts("block created");}
| optNewLines '{' stmts '}'	{$$ = $3;  puts("block created");}
| optNewLines '{' newLines stmts '}'	{$$ = $4;  puts("block created");}
| optNewLines '{' newLines '}'	{$$ = 0;  puts("block created");}
| optNewLines '{' '}'	{$$ = 0;  puts("block created");}
;


varDeclaration: VAR ID ':' type	{$$ = createVarOrValDecl($2, $4, 0); puts("var created");}
| VAR ID ':' type '=' expr	{$$ = createVarOrValDecl($2, $4, $6, 0); puts("var created");}
| VAR '(' formalParams ')' '=' expr	{$$ = createVarOrValDecl($3, $6, 0); puts("var created"); }
;


valDeclaration: VAL ID ':' type	{$$ = createVarOrValDecl($2, $4, 1); puts("val created"); }
| VAL ID ':' type '=' expr	{$$ = createVarOrValDecl($2, $4, $6, 1); puts("val created"); }
| VAL '(' formalParams ')' '=' expr	{$$ = createVarOrValDecl($3, $6, 1); puts("val created"); }
;

type: ID	{$$ = createType($1); puts("type created"); }
| templateType	{$$ = createType($1); puts("type created"); }
;

templateType: ID '<' type_seq '>'	{$$ = createTemplateType($1, $3); puts("template type created"); }
;

type_seq: ID	{$$ = createTypesList($1); puts("type seq created"); }
| templateType	{$$ = createTypesList($1); puts("type seq created"); }
| type_seq ',' ID	{$$ = addToTypesList($1, $3);  puts("type seq created"); }
| type_seq ',' templateType	{$$ = addToTypesList($1, $3);  puts("type seq created"); }
;

stmts : stmt	{$$ = createStmtList($1);  puts("stmts created"); }
| stmts stmt	{$$ = addToStmtList($1, $2);  puts("stmts created"); }
;

stmt : valDeclaration semis	{$$ = createStmt($1, VarOrVal);  puts("stmt created"); }
| varDeclaration semis	{$$ = createStmt($1, VarOrVal);  puts("stmt created"); }
| assignment semis	{$$ = createStmt($1, Assignment);  puts("stmt created"); }
| whileLoop {$$ = createStmt($1, WhileLoop);  puts("stmt created"); }
| doWhileLoop semis	{$$ = createStmt($1, DoWhileLoop);  puts("stmt created"); }
| forLoop {$$ = createStmt($1, ForLoop);  puts("stmt created"); }
| ifStmt {$$ = createStmt($1, IfStmt);  puts("stmt created"); }
| expr semis	{$$ = createStmt($1, Expr);  puts("stmt created"); }
| BREAK semis	{$$ = createStmt(Break);  puts("stmt created"); }
| CONTINUE semis	{$$ = createStmt(Continue);  puts("stmt created"); }
| RETURN semis	{$$ = createStmt(Return);  puts("stmt created"); }
| RETURN expr semis	{$$ = createStmt($2, ReturnValue);  puts("stmt created"); }
| valDeclaration newLines	{$$ = createStmt($1, VarOrVal);  puts("stmt created"); }
| varDeclaration newLines	{$$ = createStmt($1, VarOrVal);  puts("stmt created"); }
| assignment newLines	{$$ = createStmt($1, Assignment);  puts("stmt created"); }
| doWhileLoop newLines	{$$ = createStmt($1, DoWhileLoop);  puts("stmt created"); }
| expr newLines	{$$ = createStmt($1, Expr);  puts("stmt created"); }
| BREAK newLines	{$$ = createStmt(Break);  puts("stmt created"); }
| CONTINUE newLines	{$$ = createStmt(Continue);  puts("stmt created"); }
| RETURN newLines	{$$ = createStmt(Return);  puts("stmt created"); }
| RETURN expr newLines	{$$ = createStmt($2, ReturnValue);  puts("stmt created"); }

;

expr: STR 	{$$ = createExpr($1, String);  puts("expr created"); }
| ID	{$$ = createExpr($1, Identificator);  puts("expr created"); }
| THIS 	{$$ = createExpr(0, This);  puts("expr created"); }
| ID '(' optFactParams ')'	{$$ = createExpr($1, $3, MethodCall);  puts("expr created"); }
| INT 	{$$ = createExpr($1, Int);  puts("expr created"); }
| FLOAT 	{$$ = createExpr($1, Float);  puts("expr created"); }
| CHR 	{$$ = createExpr($1, Char);  puts("expr created"); }
| DOUBLE 	{$$ = createExpr($1, Double);  puts("expr created"); }
| BOOLEAN	{$$ = createExpr($1, Boolean);  puts("expr created"); }
| '(' expr ')' 	{$$ = createExpr($2, ExprInBrackets);  puts("expr created"); }
| '!' expr 	{$$ = createExpr($2, LogicalNot);}
| '+' expr %prec UPLUS	{$$ = createExpr($2, UnaryPlusExpr);  puts("expr created"); }
| '-' expr %prec UMINUS	{$$ = createExpr($2, UnaryMinusExpr);  puts("expr created"); }
| expr '+' expr 	{$$ = createExpr($1, $3, Sum);  puts("expr created"); }
| expr '-' expr 	{$$ = createExpr($1, $3, Sub);  puts("expr created"); }
| expr '*' expr 	{$$ = createExpr($1, $3, Mul);  puts("expr created"); }
| expr '/' expr 	{$$ = createExpr($1, $3, Div);  puts("expr created"); }
| expr '%' expr 	{$$ = createExpr($1, $3, Mod);  puts("expr created"); }
| expr '<' expr 	{$$ = createExpr($1, $3, Less);  puts("expr created"); }
| expr '>' expr 	{$$ = createExpr($1, $3, More);  puts("expr created"); }
| expr OR expr 	{$$ = createExpr($1, $3, Or);  puts("expr created"); }
| expr AND expr 	{$$ = createExpr($1, $3, And);  puts("expr created"); }
| expr EQ expr 	{$$ = createExpr($1, $3, Eq);  puts("expr created"); }
| expr AEQ expr 	{$$ = createExpr($1, $3, Aeq);}
| expr NEQ expr 	{$$ = createExpr($1, $3, Neq);  puts("expr created"); }
| expr NAEQ expr	{$$ = createExpr($1, $3, Naeq);  puts("expr created"); }
| expr LOEQ expr	{$$ = createExpr($1, $3, Loeq);  puts("expr created"); }
| expr MOEQ expr	{$$ = createExpr($1, $3, Moeq);  puts("expr created"); }
| expr '.' ID 	{$$ = createExpr($1, $3, FieldCalcExpr);  puts("expr created"); }
| expr '.' ID '(' optFactParams ')'	{$$ = createExpr($1, $3, $5, MethodCalcExpr);  puts("expr created"); }
| expr '[' expr ']'	{$$ = createExpr($1, $3, ArrayElementCall);  puts("expr created"); } 
| SUPER '.' ID	{$$ = createExpr(0, $3, ParentFieldCall);  puts("expr created"); }
| SUPER '.' ID '(' optFactParams ')'	{$$ = createExpr(0, $3, $5, ParentMethodCall);  puts("expr created"); }
| expr RANGE expr	{$$ = createExpr($1, $3, Range);  puts("expr created"); }
;

optFactParams: /*empty*/	{$$ = 0;   puts("opt fact params created"); }
| factParams	{$$ = $1;   puts("opt fact params created"); }
;

factParams: expr	{$$ = createFactParamsList($1);   puts("fact params created"); }
| factParams ',' expr	{$$ = addToFactParamsList($1, $3);   puts("fact params created"); }
;

assignment: expr '=' expr	{$$ = createAssignment($1, $3, Assign); puts("assignment created"); }
| expr ASUM expr 	{$$ = createAssignment($1, $3, Asum); puts("assignment created"); }
| expr ASUB expr 	{$$ = createAssignment($1, $3, Asub); puts("assignment created"); }
| expr ADIV expr 	{$$ = createAssignment($1, $3, Adiv); puts("assignment created"); }
| expr AMUL expr 	{$$ = createAssignment($1, $3, Amul); puts("assignment created"); }
| expr AMOD expr	{$$ = createAssignment($1, $3, Amod); puts("assignment created"); }
;

whileLoop: WHILE '(' expr ')' stmt	{$$ = createWhileLoop($3, $5, 0); puts("whileLoop created"); }
| WHILE '(' expr ')' block semis	{$$ = createWhileLoop($3, $5, 0); puts("whileLoop created"); }
| WHILE '(' expr ')' semis	{$$ = createWhileLoop($3, 0); puts("whileLoop created"); }
| WHILE '(' expr ')' block newLines	{$$ = createWhileLoop($3, $5, 0); puts("whileLoop created"); }
| WHILE '(' expr ')' newLines	{$$ = createWhileLoop($3, 0); puts("whileLoop created"); }
;

doWhileLoop: DO expr WHILE '(' expr ')'	{$$ = createWhileLoop($5, $2, 1); puts("doWhileLoop created"); }
| DO block WHILE '(' expr ')'	{$$ = createWhileLoop($5, $2, 1); puts("doWhileLoop created"); }
| DO WHILE '(' expr ')' {$$ = createWhileLoop($4, 1); puts("doWhileLoop created"); }
;

forLoop: FOR '(' ID ':' type IN expr ')' stmt	{$$ = createForLoop($3, $5, $7, $9); puts("forLoop created"); }
| FOR '(' ID ':' type IN expr ')' block semis	{$$ = createForLoop($3, $5, $7, $9); puts("forLoop created"); }
| FOR '(' ID ':' type IN expr ')' semis 	{$$ = createForLoop($3, $5, $7); puts("forLoop created"); }
| FOR '(' '(' formalParams ')' IN expr ')' stmt	{$$ = createForLoop($4, $7, $9); puts("forLoop created"); }
| FOR '(' '(' formalParams ')' IN expr ')' block semis	{$$ = createForLoop($4, $7, $9); puts("forLoop created"); }
| FOR '(' '(' formalParams ')' IN expr ')' semis	{$$ = createForLoop($4, $7); puts("forLoop created"); }
| FOR '(' ID ':' type IN expr ')' block newLines	{$$ = createForLoop($3, $5, $7, $9); puts("forLoop created"); }
| FOR '(' ID ':' type IN expr ')' newLines 	{$$ = createForLoop($3, $5, $7); puts("forLoop created"); }
| FOR '(' '(' formalParams ')' IN expr ')' block newLines	{$$ = createForLoop($4, $7, $9); puts("forLoop created"); }
| FOR '(' '(' formalParams ')' IN expr ')' newLines	{$$ = createForLoop($4, $7); puts("forLoop created"); }
;

ifStmt: IF '(' expr ')' stmt	{$$ = createIfStmt($3, $5); puts("ifStmt created"); }
| IF '(' expr ')' semis {$$ = createIfStmt($3); puts("ifStmt created"); }
| IF '(' expr ')' block	semis {$$ = createIfStmt($3, $5); puts("ifStmt created"); }
| IF '(' expr ')' expr ELSE stmt	{$$ = createIfStmt($3, $5, $7); puts("ifStmt created"); }
| IF '(' expr ')' stmt ELSE stmt	{$$ = createIfStmt($3, $5, $7); puts("ifStmt created"); }
| IF '(' expr ')' block ELSE stmt	{$$ = createIfStmt($3, $5, $7); puts("ifStmt created"); }
| IF '(' expr ')' semis ELSE stmt	{$$ = createIfStmt($3, 0, $7); puts("ifStmt created"); }
| IF '(' expr ')' expr ELSE block semis	{$$ = createIfStmt($3, $5, $7); puts("ifStmt created"); }
| IF '(' expr ')' stmt ELSE block semis	{$$ = createIfStmt($3, $5, $7); puts("ifStmt created"); }
| IF '(' expr ')' block ELSE block semis	{$$ = createIfStmt($3, $5, $7); puts("ifStmt created"); }
| IF '(' expr ')' semis ELSE block semis	{$$ = createIfStmt($3, 0, $7); puts("ifStmt created"); }
| IF '(' expr ')' expr ELSE semis	{$$ = createIfStmt($3, $5); puts("ifStmt created"); }
| IF '(' expr ')' stmt ELSE	semis	{$$ = createIfStmt($3, $5); puts("ifStmt created"); }
| IF '(' expr ')' block ELSE semis	{$$ = createIfStmt($3, $5); puts("ifStmt created"); }
| IF '(' expr ')' newLines {$$ = createIfStmt($3); puts("ifStmt created"); }
| IF '(' expr ')' block	newLines {$$ = createIfStmt($3, $5); puts("ifStmt created"); }
| IF '(' expr ')' newLines ELSE stmt	{$$ = createIfStmt($3, 0, $7); puts("ifStmt created"); }
| IF '(' expr ')' expr ELSE block newLines	{$$ = createIfStmt($3, $5, $7); puts("ifStmt created"); }
| IF '(' expr ')' stmt ELSE block newLines	{$$ = createIfStmt($3, $5, $7); puts("ifStmt created"); }
| IF '(' expr ')' block ELSE block newLines	{$$ = createIfStmt($3, $5, $7); puts("ifStmt created"); }
| IF '(' expr ')' newLines ELSE block newLines	{$$ = createIfStmt($3, 0, $7); puts("ifStmt created"); }
| IF '(' expr ')' expr ELSE newLines	{$$ = createIfStmt($3, $5); puts("ifStmt created"); }
| IF '(' expr ')' stmt ELSE	newLines	{$$ = createIfStmt($3, $5); puts("ifStmt created"); }
| IF '(' expr ')' block ELSE newLines	{$$ = createIfStmt($3, $5); puts("ifStmt created"); }
;

optNewLines: /*empty*/
| newLines
;

newLines: NEW_LINE
| newLines NEW_LINE 
;

semis: ';'	{ puts("semis created"); }
| semis ';'	{ puts("; added to semis"); }
| semis newLines { puts("newLines added to semis"); }
;


%%
//Секция пользовательского кода



void main(int argc, char **argv ){
	//yyin = fopen(argv[1], "r");
	yyin = fopen("easy_test.txt", "r");
	FILE * file = fopen("tree.dot", "w");
	root = 0;
    yyparse();

	fprintf(file, "digraph G {\n");
	print(root, file);
	fprintf(file, "\n}");

	fclose(file);

    return;
}