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
	
	struct programS * root;
	
	struct programS * createProgram();
	struct programS * createProgram(struct classS * clas);
	struct programS * createProgram(struct methodS * meth);
	struct programS * createProgram(struct propertyS * prop);
	struct programS * addToProgram(struct programS * prog, struct classS * clas);
	struct programS * addToProgram(struct programS * prog, struct methodS * meth);
	struct programS * addToProgram(struct programS * prog, struct propertyS * prop);
	
	struct classS * createClass(struct modifiersS * mods, char * id, char * parentId, struct classBodyS * body);
	struct classS * createClass(struct modifiersS * mods, char * id, struct classBodyS * body);
	
	struct classBodyS * createClassBody();
	struct classBodyS * createClassBody(struct methodS * meth);
	struct classBodyS * createClassBody(struct initializerS * initializer);
	struct classBodyS * createClassBody(struct propertyS * prop);
	struct classBodyS * createClassBody(struct constructorS * constr);
	struct classBodyS * addToClassBody(struct classBodyS * body, struct methodS * meth);
	struct classBodyS * addToClassBody(struct classBodyS * body, struct initializerS * initializer);
	struct classBodyS * addToClassBody(struct classBodyS * body, struct propertyS * prop);
	struct classBodyS * addToClassBody(struct classBodyS * body, struct constructorS * constr);
	
	struct propertyS * createProperty(struct modifiersS * mods, struct varOrValDeclS * decl);
	struct propertyS * createProperty(struct varOrValDeclS * decl);
	
	struct methodS * createMethod(struct modifiersS * mods, struct funcDeclS * funcDecl);
	struct methodS * createMethod(struct modifiersS * mods, struct funcS * func);
	struct methodS * createMethod(struct funcDeclS * funcDecl);
	struct methodS * createMethod(struct funcS * func);
	
	struct initializerS * createInit(struct stmtList * stmts);
	
	struct constructorS * createConstructor(enum visibilityMod mod, struct formalParamsList * params, struct stmtList * stmts);
	struct constructorS * createConstructor(enum visibilityMod mod, struct formalParamsList * params);
	struct constructorS * createConstructor(enum visibilityMod mod, struct formalParamsList * params, const char * parentOrAnotherConstr, struct factParamsList * anotherConstrParams);
	struct constructorS * createConstructor(enum visibilityMod mod, struct formalParamsList * params, const char * parentOrAnotherConstr, struct factParamsList * anotherConstrParams, struct stmtList * stmts);
	struct constructorS * createConstructor(struct formalParamsList * params, struct stmtList * stmts);
	struct constructorS * createConstructor(struct formalParamsList * params);
	struct constructorS * createConstructor(struct formalParamsList * params, const char * parentOrAnotherConstr, struct factParamsList * anotherConstrParams);
	struct constructorS * createConstructor(struct formalParamsList * params, const char * parentOrAnotherConstr, struct factParamsList * anotherConstrParams, struct stmtList * stmts);
	
	struct formalParamsList * createFormalParamsList();
	struct formalParamsList * createFormalParamsList(char * id, struct typeS * type);
	struct formalParamsList * addToFormalParamsList(struct formalParamsList * list, char * id, struct typeS * type);
	
	struct modifiersS * createModifiers(int isAbstruct, int isOverride, enum visibilityMod vMod, enum inheritanceMod iMod);
	
	struct funcS * createFunc(struct funcDeclS * decl, struct stmtList * stmts);
	struct funcS * createFunc(struct funcDeclS * decl, struct exprS * expr);
	
	struct funcDeclS * createFuncDecl(char * id, struct formalParamsList * params, struct typeS * type);
	
	struct stmtList * createStmtList();
	struct stmtList * createStmtList(struct stmtS * stmt);
	struct stmtList * addToStmtList(struct stmtList * list, struct stmtS * stmt);
	
	struct varOrValDeclS * createVarOrValDecl(char * id, struct typeS * type, int isVal);
	struct varOrValDeclS * createVarOrValDecl(char * id, struct typeS * type, struct exprS * initValue, int isVal);
	struct varOrValDeclS * createVarOrValDecl(struct formalParamsList * idsAndTypes, struct exprS * initValue, int isVal);
	
	struct typeS * createType(char * id);
	struct typeS * createType(struct templateTypeS * type);
	
	struct templateTypeS * createTemplateType(char * id, struct typesList * templateTypes);
	struct templateTypeS * createTemplateType(char * id, struct templateTypeS * type);
	
	struct typesList * createTypesList(char * id);
	struct typesList * addToTypesList(struct typesList * list, char * id);
	
	struct stmtS * createStmt(struct propertyS * prop, enum stmtType type);
	struct stmtS * createStmt(struct assignmentS * assign, enum stmtType type);
	struct stmtS * createStmt(struct whileLoopS * loop, enum stmtType type);
	struct stmtS * createStmt(struct forLoopS * loop, enum stmtType type);
	struct stmtS * createStmt(struct ifStmtS * ifStmt, enum stmtType type);
	struct stmtS * createStmt(struct exprS * expr, enum stmtType type);
	struct stmtS * createStmt(enum stmtType type);
	
	struct exprS * createExpr(char * idOrString, enum exprType type);
	struct exprS * createExpr(int val, enum exprType type);
	struct exprS * createExpr(char * idOrString, struct factParamsList * params, enum exprType type);
	struct exprS * createExpr(float val, enum exprType type);
	struct exprS * createExpr(double val, enum exprType type);
	struct exprS * createExpr(char val, enum exprType type);
	struct exprS * createExpr(bool val, enum exprType type);
	struct exprS * createExpr(struct exprS * expr, enum exprType type);
	struct exprS * createExpr(struct exprS * left, struct exprS * right, enum exprType type);
	struct exprS * createExpr(struct exprS * left, char * right, enum exprType type);
	struct exprS * createExpr(struct exprS * left, char * right, struct factParamsList * params, enum exprType type);
	
	struct factParamsList * createFactParamsList();
	struct factParamsList * createFactParamsList(struct exprS * expr);
	struct factParamsList * addToFactParamsList(struct factParamsList * list, struct exprS * expr);
	
	struct assignmentS * createAssignment(struct exprS * left, struct exprS * right, enum assignmentType type); 
	
	struct whileLoopS * createWhileLoop(struct exprS * cond, struct stmtS * stmt, int isDoWhile);
	struct whileLoopS * createWhileLoop(struct exprS * cond, struct stmtList * stmts, int isDoWhile);
	struct whileLoopS * createWhileLoop(struct exprS * cond, int isDoWhile);
	
	struct forLoopS * createForLoop(char * id, struct typeS * type, struct exprS * iterableExpr, struct stmtS * stmt);
	struct forLoopS * createForLoop(char * id, struct typeS * type, struct exprS * iterableExpr, struct stmtList * stmts);
	struct forLoopS * createForLoop(struct formalParamsList * idsAndTypes, struct exprS * iterableExpr, struct stmtList * stmts);
	struct forLoopS * createForLoop(struct formalParamsList * idsAndTypes, struct exprS * iterableExpr, struct stmtS * stmt);
	struct forLoopS * createForLoop(char * id, struct typeS * type, struct exprS * iterableExpr);
	struct forLoopS * createForLoop(struct formalParamsList * idsAndTypes, struct exprS * iterableExpr);
	
	struct ifStmtS * createIfStmt(struct exprS * cond, struct stmtS * action);
	struct ifStmtS * createIfStmt(struct exprS * cond, struct stmtList * actions);
	struct ifStmtS * createIfStmt(struct exprS * cond);
	struct ifStmtS * createIfStmt(struct exprS * cond, struct stmtS * action, struct stmtS * altAction);
	struct ifStmtS * createIfStmt(struct exprS * cond, struct stmtS * action, struct stmtList * altActions);
	struct ifStmtS * createIfStmt(struct exprS * cond, struct stmtList * actions, struct stmtS * altAction);
	struct ifStmtS * createIfStmt(struct exprS * cond, struct stmtList * actions, struct stmtList * altActions);
	struct ifStmtS * createIfStmt(struct exprS * cond, int action, struct stmtS * altAction);
	struct ifStmtS * createIfStmt(struct exprS * cond, int action, struct stmtList * altActions);
	
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
	struct idS * idU;
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

program: semis	{root = createProgram();}
| newLines	{root = createProgram();}
| class	{root = createProgram($1);}
| method	{root = createProgram($1);}
| property semis	{root = createProgram($1);}
| property newLines	{root = createProgram($1);}
| program class	{$$ = addToProgram($1, $2);}
| program method	{$$ = addToProgram($1, $2);}
| program property semis	{$$ = addToProgram($1, $2);}
| program property newLines	{$$ = addToProgram($1, $2);}
| program newLines
| program semis
; 

class: modifiers optNewLines CLASS optNewLines ID optNewLines ':' optNewLines ID optNewLines '{' optNewLines classBody '}'	{$$ = createClass($1, $5, $9, $13);}
| modifiers optNewLines CLASS optNewLines ID optNewLines '{' optNewLines classBody '}'	{$$ = createClass($1, $5, $9);}
;

classBody: semis 	{$$ = createClassBody();}
| newLines	{$$ = createClassBody();}
| method	{$$ = createClassBody($1);}
| property semis	{$$ = createClassBody($1);}
| property newLines	{$$ = createClassBody($1);}
| constructor	{$$ = createClassBody($1);}
| initializer	{$$ = createClassBody($1);}
| classBody method	{$$ = addToClassBody($1, $2);}
| classBody property semis	{$$ = addToClassBody($1, $2);}
| classBody property newLines	{$$ = addToClassBody($1, $2);}
| classBody newLines
| classBody constructor	{$$ = addToClassBody($1, $2);}
| classBody initializer	{$$ = addToClassBody($1, $2);}
| classBody semis
;

property: modifiers optNewLines valDeclaration	{$$ = createProperty($1, $3);}
| modifiers optNewLines varDeclaration	{$$ = createProperty($1, $3);}
| valDeclaration	{$$ = createProperty($1);}
| varDeclaration	{$$ = createProperty($1);}
;

method: modifiers optNewLines funcDeclaration ';'	{$$ = createMethod($1, $3);}
| modifiers optNewLines func	{$$ = createMethod($1, $3);}
| funcDeclaration ';'	{$$ = createMethod($1);}
| func	{$$ = createMethod($1);}
;

initializer: INIT optNewLines block	{$$ = createInit($3);}
;


constructor: visibilityModifier optNewLines CONSTRUCTOR optNewLines '(' optNewLines optFormalParams optNewLines ')' optNewLines block	{$$ = createConstructor($1, $7, $11);}
| visibilityModifier optNewLines CONSTRUCTOR optNewLines '(' optNewLines optFormalParams optNewLines ')'	{$$ = createConstructor($1, $7);}
| visibilityModifier optNewLines CONSTRUCTOR optNewLines '(' optNewLines optFormalParams optNewLines ')' optNewLines ':' optNewLines SUPER optNewLines '(' optNewLines optFactParams optNewLines ')'	{$$ = createConstructor($1, $7, "super", $17);}
| visibilityModifier optNewLines CONSTRUCTOR optNewLines '(' optNewLines optFormalParams optNewLines ')'  optNewLines ':' optNewLines THIS optNewLines '(' optNewLines optFactParams optNewLines ')' 	{$$ = createConstructor($1, $7, "this", $17);}
| visibilityModifier optNewLines CONSTRUCTOR optNewLines '(' optNewLines optFormalParams optNewLines ')'  optNewLines ':' optNewLines SUPER optNewLines '(' optNewLines optFactParams optNewLines ')' optNewLines block	{$$ = createConstructor($1, $7, "super", $17, $21);}
| visibilityModifier optNewLines CONSTRUCTOR optNewLines '(' optNewLines optFormalParams optNewLines ')' optNewLines ':' optNewLines THIS optNewLines '(' optNewLines optFactParams optNewLines ')' optNewLines block	{$$ = createConstructor($1, $7, "this", $17, $21);}
| CONSTRUCTOR optNewLines '(' optNewLines optFormalParams optNewLines ')' optNewLines block 	{$$ = createConstructor($5, $9);}
| CONSTRUCTOR optNewLines '(' optNewLines optFormalParams optNewLines ')' 	{$$ = createConstructor($5);}
| CONSTRUCTOR optNewLines '(' optNewLines optFormalParams optNewLines ')' optNewLines ':' optNewLines SUPER optNewLines '(' optNewLines optFactParams optNewLines ')'	{$$ = createConstructor($5, "super", $15);}
| CONSTRUCTOR optNewLines '(' optNewLines optFormalParams optNewLines ')'  optNewLines ':' optNewLines THIS optNewLines '(' optNewLines optFactParams optNewLines ')' 	{$$ = createConstructor($5, "this", $15);}
| CONSTRUCTOR optNewLines '(' optNewLines optFormalParams optNewLines ')'  optNewLines ':' optNewLines SUPER optNewLines '(' optNewLines optFactParams optNewLines ')' optNewLines block	{$$ = createConstructor($5, "super", $15, $19);}
| CONSTRUCTOR optNewLines '(' optNewLines optFormalParams optNewLines ')' optNewLines ':' optNewLines THIS optNewLines '(' optNewLines optFactParams optNewLines ')' optNewLines block	{$$ = createConstructor($5, "this", $15, $19);}
;

optFormalParams: /*empty*/	{$$ = createFormalParamsList();}
| formalParams	{$$ = $1;}
;

formalParams: ID optNewLines ':' optNewLines type	{$$ = createFormalParamsList($1, $5);}
| formalParams optNewLines ',' optNewLines ID optNewLines ':' optNewLines type	{$$ = addToFormalParamsList($1, $5, $9);}
;

modifiers: OVERRIDE	{$$ = createModifiers(0, 1, Local, None);}
| visibilityModifier	{$$ = createModifiers(0, 1, $1, None);}
| inheritanceModifier	{$$ = createModifiers(0, 1, Local, $1);}
| ABSTRACT	{$$ = createModifiers(1, 0, Local, None);}
| OVERRIDE optNewLines visibilityModifier	{$$ = createModifiers(0, 1, $3, None);}
| OVERRIDE optNewLines inheritanceModifier	{$$ = createModifiers(0, 1, Local, $3);}
| OVERRIDE optNewLines ABSTRACT	{$$ = createModifiers(1, 1, Local, None);}
| visibilityModifier optNewLines OVERRIDE	{$$ = createModifiers(0, 1, $1, None);}
| visibilityModifier optNewLines inheritanceModifier	{$$ = createModifiers(0, 0, $1, $3);}
| visibilityModifier optNewLines ABSTRACT	{$$ = createModifiers(1, 0, $1, None);}
| inheritanceModifier optNewLines OVERRIDE	{$$ = createModifiers(0, 1, Local, $1);}
| inheritanceModifier optNewLines visibilityModifier	{$$ = createModifiers(0, 0, $3, $1);}
| inheritanceModifier optNewLines ABSTRACT 	{$$ = createModifiers(1, 0, Local, $1);}
| ABSTRACT optNewLines OVERRIDE	{$$ = createModifiers(1, 1, Local, None);}
| ABSTRACT optNewLines visibilityModifier 	{$$ = createModifiers(1, 0, $3, None);}
| ABSTRACT optNewLines inheritanceModifier	{$$ = createModifiers(1, 0, Local, $3);}
| OVERRIDE optNewLines visibilityModifier optNewLines inheritanceModifier	{$$ = createModifiers(0, 1, $3, $5);}
| OVERRIDE optNewLines visibilityModifier optNewLines ABSTRACT	{$$ = createModifiers(1, 1, $3, None);}
| OVERRIDE optNewLines inheritanceModifier optNewLines visibilityModifier	{$$ = createModifiers(0, 1, $5, $3);}
| OVERRIDE optNewLines inheritanceModifier optNewLines ABSTRACT	{$$ = createModifiers(1, 1, Local, $3);}
| OVERRIDE optNewLines ABSTRACT optNewLines visibilityModifier	{$$ = createModifiers(1, 1, $5, None);}
| OVERRIDE optNewLines ABSTRACT optNewLines inheritanceModifier	{$$ = createModifiers(1, 1, Local, $5);}
| visibilityModifier optNewLines OVERRIDE optNewLines inheritanceModifier	{$$ = createModifiers(0, 1, $1, $5);}
| visibilityModifier optNewLines OVERRIDE optNewLines ABSTRACT	{$$ = createModifiers(1, 1, $1, None);}
| visibilityModifier optNewLines inheritanceModifier optNewLines OVERRIDE 	{$$ = createModifiers(0, 1, $1, $3);}
| visibilityModifier optNewLines inheritanceModifier optNewLines ABSTRACT	{$$ = createModifiers(1, 0, $1, $3);}
| visibilityModifier optNewLines ABSTRACT optNewLines inheritanceModifier	{$$ = createModifiers(1, 0, $1, $5);}
| visibilityModifier optNewLines ABSTRACT optNewLines OVERRIDE	{$$ = createModifiers(1, 1, $1, None);}
| inheritanceModifier optNewLines OVERRIDE optNewLines visibilityModifier 	{$$ = createModifiers(0, 1, $5, $1);}
| inheritanceModifier optNewLines OVERRIDE optNewLines ABSTRACT	{$$ = createModifiers(1, 1, Local, $1);}
| inheritanceModifier optNewLines visibilityModifier optNewLines ABSTRACT	{$$ = createModifiers(1, 0, $3, $1);}
| inheritanceModifier optNewLines visibilityModifier optNewLines OVERRIDE	{$$ = createModifiers(0, 1, $3, $1);}
| inheritanceModifier optNewLines ABSTRACT optNewLines visibilityModifier 	{$$ = createModifiers(1, 0, $5, $1);}
| inheritanceModifier optNewLines ABSTRACT optNewLines OVERRIDE	{$$ = createModifiers(1, 1, Local, $1);}
| ABSTRACT optNewLines OVERRIDE optNewLines inheritanceModifier	{$$ = createModifiers(1, 1, Local, $5);}
| ABSTRACT optNewLines OVERRIDE optNewLines visibilityModifier	{$$ = createModifiers(1, 1, $5, None);}
| ABSTRACT optNewLines visibilityModifier optNewLines OVERRIDE	{$$ = createModifiers(1, 1, $3, None);}
| ABSTRACT optNewLines visibilityModifier optNewLines inheritanceModifier	{$$ = createModifiers(1, 0, $3, $5);}
| ABSTRACT optNewLines inheritanceModifier optNewLines OVERRIDE	{$$ = createModifiers(1, 1, Local, $3);}
| ABSTRACT optNewLines inheritanceModifier optNewLines visibilityModifier	{$$ = createModifiers(1, 0, $5, $3);}
| OVERRIDE optNewLines visibilityModifier optNewLines inheritanceModifier optNewLines ABSTRACT	{$$ = createModifiers(1, 1, $3, $5);}
| OVERRIDE optNewLines visibilityModifier optNewLines ABSTRACT optNewLines inheritanceModifier	{$$ = createModifiers(1, 1, $3, $7);}
| OVERRIDE optNewLines inheritanceModifier optNewLines visibilityModifier optNewLines ABSTRACT	{$$ = createModifiers(1, 1, $5, $3);}
| OVERRIDE optNewLines inheritanceModifier optNewLines ABSTRACT optNewLines visibilityModifier	{$$ = createModifiers(1, 1, $7, $3);}
| OVERRIDE optNewLines ABSTRACT optNewLines visibilityModifier optNewLines inheritanceModifier	{$$ = createModifiers(1, 1, $5, $7);}
| OVERRIDE optNewLines ABSTRACT optNewLines inheritanceModifier optNewLines visibilityModifier	{$$ = createModifiers(1, 1, $7, $5);}
| visibilityModifier optNewLines OVERRIDE optNewLines inheritanceModifier optNewLines ABSTRACT	{$$ = createModifiers(1, 1, $1, $5);}
| visibilityModifier optNewLines OVERRIDE optNewLines ABSTRACT optNewLines inheritanceModifier	{$$ = createModifiers(1, 1, $1, $7);}
| visibilityModifier optNewLines inheritanceModifier optNewLines OVERRIDE optNewLines ABSTRACT	{$$ = createModifiers(1, 1, $1, $3);}
| visibilityModifier optNewLines inheritanceModifier optNewLines ABSTRACT optNewLines OVERRIDE	{$$ = createModifiers(1, 1, $1, $3);}
| visibilityModifier optNewLines ABSTRACT optNewLines inheritanceModifier optNewLines OVERRIDE	{$$ = createModifiers(1, 1, $1, $5);}
| visibilityModifier optNewLines ABSTRACT optNewLines OVERRIDE optNewLines inheritanceModifier	{$$ = createModifiers(1, 1, $1, $7);}
| inheritanceModifier optNewLines OVERRIDE optNewLines visibilityModifier optNewLines ABSTRACT	{$$ = createModifiers(1, 1, $5, $1);}
| inheritanceModifier optNewLines OVERRIDE optNewLines ABSTRACT optNewLines visibilityModifier	{$$ = createModifiers(1, 1, $7, $1);}
| inheritanceModifier optNewLines visibilityModifier optNewLines ABSTRACT optNewLines OVERRIDE
	{$$ = createModifiers(1, 1, $3, $1);}
| inheritanceModifier optNewLines visibilityModifier optNewLines OVERRIDE optNewLines ABSTRACT
	{$$ = createModifiers(1, 1, $3, $1);}
| inheritanceModifier optNewLines ABSTRACT optNewLines visibilityModifier optNewLines OVERRIDE
	{$$ = createModifiers(1, 1, $5, $1);}
| inheritanceModifier optNewLines ABSTRACT optNewLines OVERRIDE optNewLines visibilityModifier
	{$$ = createModifiers(1, 1, $7, $1);}
| ABSTRACT optNewLines OVERRIDE optNewLines inheritanceModifier optNewLines visibilityModifier
	{$$ = createModifiers(1, 1, $7, $5);}
| ABSTRACT optNewLines OVERRIDE optNewLines visibilityModifier optNewLines inheritanceModifier
	{$$ = createModifiers(1, 1, $5, $7);}
| ABSTRACT optNewLines visibilityModifier optNewLines OVERRIDE optNewLines inheritanceModifier	{$$ = createModifiers(1, 1, $3, $7);}
| ABSTRACT optNewLines visibilityModifier optNewLines inheritanceModifier optNewLines OVERRIDE	{$$ = createModifiers(1, 1, $3, $5);}
| ABSTRACT optNewLines inheritanceModifier optNewLines OVERRIDE optNewLines visibilityModifier
	{$$ = createModifiers(1, 1, $7, $3);}
| ABSTRACT optNewLines inheritanceModifier optNewLines visibilityModifier optNewLines OVERRIDE
	{$$ = createModifiers(1, 1, $5, $3);}
;

visibilityModifier: PUBLIC	{$$ = Public;}
| PRIVATE	{$$ = Private;}
| INTERNAL	{$$ = Internal;}
| PROTECTED	{$$ = Protected;}
;


inheritanceModifier: FINAL {$$ = Final;}
| OPEN {$$ = Open;}
;

func : funcDeclaration optNewLines block	{$$ = createFunc($1, $3);}
| funcDeclaration optNewLines '=' optNewLines expr	{$$ = createFunc($1, $5);}
;


funcDeclaration: FUN optNewLines ID optNewLines '(' optNewLines optFormalParams optNewLines ')' optNewLines ':' optNewLines type	{$$ = createFuncDecl($3, $7, $13);}
;


block : '{' optNewLines stmts optNewLines'}'	{$$ = $3;}
| '{' semis stmts '}'	{$$ = $3;}
| '{' semis '}'	{$$ = createStmtList();}
| '{' optNewLines '}'	{$$ = createStmtList();}
;


varDeclaration: VAR optNewLines ID optNewLines ':' optNewLines type	{$$ = createVarOrValDecl($3, $7, 0);}
| VAR optNewLines ID optNewLines ':' optNewLines type optNewLines '=' optNewLines expr	{$$ = createVarOrValDecl($3, $7, $11, 0);}
| VAR optNewLines '(' optNewLines formalParams optNewLines ')' optNewLines '=' optNewLines expr	{$$ = createVarOrValDecl($5, $11, 0);}
;


valDeclaration: VAL optNewLines ID optNewLines ':' optNewLines type	{$$ = createVarOrValDecl($3, $7, 1);}
| VAL optNewLines ID optNewLines ':' optNewLines type optNewLines '=' optNewLines expr	{$$ = createVarOrValDecl($3, $7, $11, 1);}
| VAL optNewLines '(' optNewLines formalParams optNewLines ')' optNewLines '=' optNewLines expr	{$$ = createVarOrValDecl($5, $11, 1);}
;

type: ID	{$$ = createType($1);}
| templateType	{$$ = createType($1);}
;

templateType: ID optNewLines '<' optNewLines type_seq optNewLines '>'	{$$ = createTemplateType($1, $5);}
| ID optNewLines '<' optNewLines templateType optNewLines '>' 	{$$ = createTemplateType($1, $5);}
;

type_seq: ID	{$$ = createTypesList($1);}
| type_seq optNewLines ',' optNewLines ID	{$$ = addToTypesList($1, $5); }
;

stmts : stmt	{$$ = createStmtList($1);}
| stmts stmt	{$$ = addToStmtList($1, $2);}
;

stmt : property semis	{$$ = createStmt($1, Property);}
| property newLines	{$$ = createStmt($1, Property);}
| assignment semis	{$$ = createStmt($1, Assignment);}
| assignment newLines	{$$ = createStmt($1, Assignment);}
| whileLoop semis	{$$ = createStmt($1, WhileLoop);}
| whileLoop newLines	{$$ = createStmt($1, WhileLoop);}
| forLoop semis	{$$ = createStmt($1, ForLoop);}
| forLoop newLines	{$$ = createStmt($1, ForLoop);}
| doWhileLoop semis	{$$ = createStmt($1, DoWhileLoop);}
| doWhileLoop newLines	{$$ = createStmt($1, DoWhileLoop);}
| ifStmt semis	{$$ = createStmt($1, IfStmt);}
| ifStmt newLines	{$$ = createStmt($1, IfStmt);}
| expr newLines	{$$ = createStmt($1, Expr);}
| expr semis	{$$ = createStmt($1, Expr);}
| BREAK semis	{$$ = createStmt(Break);}
| BREAK newLines	{$$ = createStmt(Break);}
| CONTINUE semis	{$$ = createStmt(Continue);}
| CONTINUE newLines	{$$ = createStmt(Continue);}
| RETURN semis	{$$ = createStmt(Return);}
| RETURN newLines	{$$ = createStmt(Return);}
| RETURN expr newLines	{$$ = createStmt($2, ReturnValue);}
| RETURN expr semis	{$$ = createStmt($2, ReturnValue);}
;

expr: ID	{$$ = createExpr($1, Identificator);}
| THIS 	{$$ = createExpr(0, This);}
| ID '(' optNewLines optFactParams optNewLines ')'	{$$ = createExpr($1, $4, MethodCall);}
| INT 	{$$ = createExpr($1, Int);}
| FLOAT 	{$$ = createExpr($1, Float);}
| STRING 	{$$ = createExpr($1, String);}
| CHAR 	{$$ = createExpr($1, Char);}
| DOUBLE 	{$$ = createExpr($1, Double);}
| BOOLEAN	{$$ = createExpr($1, Boolean);}
| '(' expr ')' 	{$$ = createExpr($2, ExprInBrackets);}
| '!' expr 	{$$ = createExpr($2, LogicalNot);}
| '+' expr %prec UPLUS	{$$ = createExpr($2, UnaryPlusExpr);}
| '-' expr %prec UMINUS	{$$ = createExpr($2, UnaryMinusExpr);}
| expr '+' expr 	{$$ = createExpr($1, $3, Sum);}
| expr '-' expr 	{$$ = createExpr($1, $3, Sub);}
| expr '*' expr 	{$$ = createExpr($1, $3, Mul);}
| expr '/' expr 	{$$ = createExpr($1, $3, Div);}
| expr '%' expr 	{$$ = createExpr($1, $3, Mod);}
| expr '<' expr 	{$$ = createExpr($1, $3, Less);}
| expr '>' expr 	{$$ = createExpr($1, $3, More);}
| expr OR expr 	{$$ = createExpr($1, $3, Or);}
| expr AND expr 	{$$ = createExpr($1, $3, And);}
| expr EQ expr 	{$$ = createExpr($1, $3, Eq);}
| expr AEQ expr 	{$$ = createExpr($1, $3, Aeq);}
| expr NEQ expr 	{$$ = createExpr($1, $3, Neq);}
| expr NAEQ expr	{$$ = createExpr($1, $3, Naeq);}
| expr LOEQ expr	{$$ = createExpr($1, $3, Loeq);}
| expr MOEQ expr	{$$ = createExpr($1, $3, Moeq);}
| expr '.' ID 	{$$ = createExpr($1, $3, FieldCalcExpr);}
| expr '.' ID '(' optNewLines optFactParams optNewLines ')'	{$$ = createExpr($1, $3, $6, MethodCalcExpr);}
| expr '[' expr ']'	{$$ = createExpr($1, $3, ArrayElementCall);} 
| SUPER '.' ID	{$$ = createExpr(0, $3, ParentFieldCall);}
| SUPER '.' ID '(' optNewLines optFactParams optNewLines ')'	{$$ = createExpr(0, $3, $6, ParentMethodCall);}
| expr RANGE expr	{$$ = createExpr($1, $3, Range);}
;

optFactParams: /*empty*/	{$$ = createFactParamsList();}
| factParams	{$$ = $1;}
;

factParams: expr	{$$ = createFactParamsList($1);}
| factParams optNewLines ',' optNewLines expr	{$$ = addToFactParamsList($1, $5);}
;

assignment: expr '=' optNewLines expr	{$$ = createAssignment($1, $4, Assign);}
| expr ASUM optNewLines expr 	{$$ = createAssignment($1, $4, Asum);}
| expr ASUB optNewLines expr 	{$$ = createAssignment($1, $4, Asub);}
| expr ADIV optNewLines expr 	{$$ = createAssignment($1, $4, Adiv);}
| expr AMUL optNewLines expr 	{$$ = createAssignment($1, $4, Amul);}
| expr AMOD optNewLines expr	{$$ = createAssignment($1, $4, Amod);}
;

whileLoop: WHILE optNewLines '(' optNewLines expr optNewLines ')' optNewLines stmt	{$$ = createWhileLoop($5, $9, 0);}
| WHILE optNewLines '(' optNewLines expr optNewLines ')' optNewLines block	{$$ = createWhileLoop($5, $9, 0);}
| WHILE optNewLines '(' optNewLines expr optNewLines ')' optNewLines ';'	{$$ = createWhileLoop($5, 0);}
;

doWhileLoop: DO optNewLines stmt optNewLines WHILE optNewLines '(' optNewLines expr optNewLines ')'	{$$ = createWhileLoop($9, $3, 1);}
| DO optNewLines block optNewLines WHILE optNewLines '(' optNewLines expr optNewLines ')'	{$$ = createWhileLoop($9, $3, 1);}
| DO optNewLines WHILE optNewLines '(' optNewLines expr optNewLines ')' optNewLines	{$$ = createWhileLoop($7, 1);}
;

forLoop: FOR optNewLines '(' optNewLines ID optNewLines ':' optNewLines type optNewLines IN optNewLines expr optNewLines ')' optNewLines stmt	{$$ = createForLoop($5, $9, $13, $17);}
| FOR optNewLines '(' optNewLines ID optNewLines ':' optNewLines type optNewLines IN optNewLines expr optNewLines ')' optNewLines block	{$$ = createForLoop($5, $9, $13, $17);}
| FOR optNewLines '(' optNewLines ID optNewLines ':' optNewLines type optNewLines IN optNewLines expr optNewLines ')' optNewLines ';' 	{$$ = createForLoop($5, $9, $13);}
| FOR optNewLines '(' optNewLines '(' optNewLines formalParams optNewLines ')' optNewLines IN optNewLines expr optNewLines ')' optNewLines stmt	{$$ = createForLoop($7, $13, $17);}
| FOR optNewLines '(' optNewLines '(' optNewLines formalParams optNewLines ')' optNewLines IN optNewLines expr optNewLines ')' optNewLines block	{$$ = createForLoop($7, $13, $17);}
| FOR optNewLines '(' optNewLines '(' optNewLines formalParams optNewLines ')' optNewLines IN optNewLines expr optNewLines ')' optNewLines ';'	{$$ = createForLoop($7, $13);}
;

ifStmt: IF optNewLines '(' optNewLines expr optNewLines ')' optNewLines stmt	{$$ = createIfStmt($5, $9);}
| IF optNewLines '(' optNewLines expr optNewLines ')' optNewLines block	{$$ = createIfStmt($5, $9);}
| IF optNewLines '(' optNewLines expr optNewLines ')' optNewLines semis 	{$$ = createIfStmt($5);}
| IF optNewLines '(' optNewLines expr optNewLines ')' optNewLines stmt optNewLines ELSE optNewLines stmt	{$$ = createIfStmt($5, $9, $13);}
| IF optNewLines '(' optNewLines expr optNewLines ')' optNewLines block optNewLines ELSE optNewLines stmt	{$$ = createIfStmt($5, $9, $13);}
| IF optNewLines '(' optNewLines expr optNewLines ')' optNewLines semis optNewLines ELSE optNewLines stmt	{$$ = createIfStmt($5, 0, $13);}
| IF optNewLines '(' optNewLines expr optNewLines ')' optNewLines stmt optNewLines ELSE optNewLines block	{$$ = createIfStmt($5, $9, $13);}
| IF optNewLines '(' optNewLines expr optNewLines ')' optNewLines block optNewLines ELSE optNewLines block	{$$ = createIfStmt($5, $9, $13);}
| IF optNewLines '(' optNewLines expr optNewLines ')' optNewLines semis optNewLines ELSE optNewLines block	{$$ = createIfStmt($5, 0, $13);}
| IF optNewLines '(' optNewLines expr optNewLines ')' optNewLines stmt optNewLines ELSE optNewLines semis	{$$ = createIfStmt($5, $9);}
| IF optNewLines '(' optNewLines expr optNewLines ')' optNewLines block optNewLines ELSE optNewLines semis	{$$ = createIfStmt($5, $9);}
| IF optNewLines '(' optNewLines expr optNewLines ')' optNewLines semis optNewLines ELSE optNewLines semis	{$$ = createIfStmt($5);}
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
	FILE * file = fopen("tree.dot", "w");
	
    yyparse();
	
	
    return;
}



















