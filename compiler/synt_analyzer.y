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
	struct classS * createClass(char * id, char * parentId, struct classBodyS * body);
	struct classS * createClass(char * id, struct classBodyS * body);
	
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
	
	struct typesList * createTypesList(char * id);
	struct typesList * createTypesList(struct templateTypeS * tt);
	struct typesList * addToTypesList(struct typesList * list, char * id);
	struct typesList * addToTypesList(struct typesList * list, struct templateTypeS * tt);
	
	struct stmtS * createStmt(struct varOrValDeclS * v, enum stmtType type);
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
| CLASS optNewLines ID optNewLines ':' optNewLines ID optNewLines '{' optNewLines classBody '}'	{$$ = createClass($3, $7, $11);}
| CLASS optNewLines ID optNewLines '{' optNewLines classBody '}'	{$$ = createClass($3, $7);}
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

optFormalParams: /*empty*/	{$$ = 0;}
| formalParams	{$$ = $1;}
;

formalParams: ID optNewLines ':' optNewLines type	{$$ = createFormalParamsList($1, $5);}
| formalParams optNewLines ',' optNewLines ID optNewLines ':' optNewLines type	{$$ = addToFormalParamsList($1, $5, $9);}
;

modifiers: OVERRIDE	{$$ = createModifiers(0, 1, Unknown, None);}
| visibilityModifier	{$$ = createModifiers(0, 1, $1, None);}
| inheritanceModifier	{$$ = createModifiers(0, 1, Unknown, $1);}
| ABSTRACT	{$$ = createModifiers(1, 0, Unknown, None);}
| OVERRIDE optNewLines visibilityModifier	{$$ = createModifiers(0, 1, $3, None);}
| OVERRIDE optNewLines inheritanceModifier	{$$ = createModifiers(0, 1, Unknown, $3);}
| OVERRIDE optNewLines ABSTRACT	{$$ = createModifiers(1, 1, Unknown, None);}
| visibilityModifier optNewLines OVERRIDE	{$$ = createModifiers(0, 1, $1, None);}
| visibilityModifier optNewLines inheritanceModifier	{$$ = createModifiers(0, 0, $1, $3);}
| visibilityModifier optNewLines ABSTRACT	{$$ = createModifiers(1, 0, $1, None);}
| inheritanceModifier optNewLines OVERRIDE	{$$ = createModifiers(0, 1, Unknown, $1);}
| inheritanceModifier optNewLines visibilityModifier	{$$ = createModifiers(0, 0, $3, $1);}
| inheritanceModifier optNewLines ABSTRACT 	{$$ = createModifiers(1, 0, Unknown, $1);}
| ABSTRACT optNewLines OVERRIDE	{$$ = createModifiers(1, 1, Unknown, None);}
| ABSTRACT optNewLines visibilityModifier 	{$$ = createModifiers(1, 0, $3, None);}
| ABSTRACT optNewLines inheritanceModifier	{$$ = createModifiers(1, 0, Unknown, $3);}
| OVERRIDE optNewLines visibilityModifier optNewLines inheritanceModifier	{$$ = createModifiers(0, 1, $3, $5);}
| OVERRIDE optNewLines visibilityModifier optNewLines ABSTRACT	{$$ = createModifiers(1, 1, $3, None);}
| OVERRIDE optNewLines inheritanceModifier optNewLines visibilityModifier	{$$ = createModifiers(0, 1, $5, $3);}
| OVERRIDE optNewLines inheritanceModifier optNewLines ABSTRACT	{$$ = createModifiers(1, 1, Unknown, $3);}
| OVERRIDE optNewLines ABSTRACT optNewLines visibilityModifier	{$$ = createModifiers(1, 1, $5, None);}
| OVERRIDE optNewLines ABSTRACT optNewLines inheritanceModifier	{$$ = createModifiers(1, 1, Unknown, $5);}
| visibilityModifier optNewLines OVERRIDE optNewLines inheritanceModifier	{$$ = createModifiers(0, 1, $1, $5);}
| visibilityModifier optNewLines OVERRIDE optNewLines ABSTRACT	{$$ = createModifiers(1, 1, $1, None);}
| visibilityModifier optNewLines inheritanceModifier optNewLines OVERRIDE 	{$$ = createModifiers(0, 1, $1, $3);}
| visibilityModifier optNewLines inheritanceModifier optNewLines ABSTRACT	{$$ = createModifiers(1, 0, $1, $3);}
| visibilityModifier optNewLines ABSTRACT optNewLines inheritanceModifier	{$$ = createModifiers(1, 0, $1, $5);}
| visibilityModifier optNewLines ABSTRACT optNewLines OVERRIDE	{$$ = createModifiers(1, 1, $1, None);}
| inheritanceModifier optNewLines OVERRIDE optNewLines visibilityModifier 	{$$ = createModifiers(0, 1, $5, $1);}
| inheritanceModifier optNewLines OVERRIDE optNewLines ABSTRACT	{$$ = createModifiers(1, 1, Unknown, $1);}
| inheritanceModifier optNewLines visibilityModifier optNewLines ABSTRACT	{$$ = createModifiers(1, 0, $3, $1);}
| inheritanceModifier optNewLines visibilityModifier optNewLines OVERRIDE	{$$ = createModifiers(0, 1, $3, $1);}
| inheritanceModifier optNewLines ABSTRACT optNewLines visibilityModifier 	{$$ = createModifiers(1, 0, $5, $1);}
| inheritanceModifier optNewLines ABSTRACT optNewLines OVERRIDE	{$$ = createModifiers(1, 1, Unknown, $1);}
| ABSTRACT optNewLines OVERRIDE optNewLines inheritanceModifier	{$$ = createModifiers(1, 1, Unknown, $5);}
| ABSTRACT optNewLines OVERRIDE optNewLines visibilityModifier	{$$ = createModifiers(1, 1, $5, None);}
| ABSTRACT optNewLines visibilityModifier optNewLines OVERRIDE	{$$ = createModifiers(1, 1, $3, None);}
| ABSTRACT optNewLines visibilityModifier optNewLines inheritanceModifier	{$$ = createModifiers(1, 0, $3, $5);}
| ABSTRACT optNewLines inheritanceModifier optNewLines OVERRIDE	{$$ = createModifiers(1, 1, Unknown, $3);}
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
| '{' semis '}'	{$$ = 0;}
| '{' optNewLines '}'	{$$ = 0;}
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
;

type_seq: ID	{$$ = createTypesList($1);}
| templateType	{$$ = createTypesList($1);}
| type_seq optNewLines ',' optNewLines ID	{$$ = addToTypesList($1, $5); }
| type_seq optNewLines ',' optNewLines templateType	{$$ = addToTypesList($1, $5); }
;

stmts : stmt	{$$ = createStmtList($1);}
| stmts stmt	{$$ = addToStmtList($1, $2);}
;

stmt : valDeclaration semis	{$$ = createStmt($1, VarOrVal);}
| valDeclaration newLines	{$$ = createStmt($1, VarOrVal);}
| varDeclaration semis	{$$ = createStmt($1, VarOrVal);}
| varDeclaration newLines	{$$ = createStmt($1, VarOrVal);}
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

optFactParams: /*empty*/	{$$ = 0;}
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


//Вспомогательные функция
struct programS * createProgram(struct programElementS * pe)
{
	struct programS * prog = (struct programS * ) malloc(sizeof(struct programS));
	prog->first = pe;
	prog->last = pe;
	return prog;
}

struct programS * addToProgram(struct programS * prog, struct programElementS * pe)
{
	if (prog->last != 0)
	{
		prog->last->next = pe;
		prog->last = pe;			
	}
	else
	{
		prog->first = pe;
		prog->last = pe;
	}
	return prog;
}

struct programElementS * createProgramElement(struct classS * clas, struct methodS * meth, struct propertyS * prop, struct programElementS * next)
{
	struct programElementS * pe = (struct programElementS *) malloc(sizeof(struct programElementS));
	pe->clas = clas;
	pe->method = meth;
	pe->property = prop;
	pe->next = next;
	return pe;
}

struct programElementS * createProgramElement(struct classS * clas)
{
	return createProgramElement(clas, 0, 0, 0);
}

struct programElementS * createProgramElement(struct methodS * meth)
{
	return createProgramElement(0, meth, 0, 0);
}

struct programElementS * createProgramElement(struct propertyS * prop)
{
	return createProgramElement(0, 0, prop, 0);
}

//Нужные функции
struct programS * createProgram()
{
	struct programS * prog = (struct programS * ) malloc(sizeof(struct programS));
	prog->first = 0;
	prog->last = 0;
	return prog;	
}

struct programS * createProgram(struct classS * clas)
{	
	return createProgram(createProgramElement(clas));
}

struct programS * createProgram(struct methodS * meth)
{
	return createProgram(createProgramElement(meth));
}

struct programS * createProgram(struct propertyS * prop)
{
	return createProgram(createProgramElement(prop));
}

struct programS * addToProgram(struct programS * prog, struct classS * clas)
{
	return addToProgram(prog, createProgramElement(clas));
}

struct programS * addToProgram(struct programS * prog, struct methodS * meth)
{
	return addToProgram(prog, createProgramElement(meth));
}

struct programS * addToProgram(struct programS * prog, struct propertyS * prop)
{
	return addToProgram(prog, createProgramElement(prop));
}



struct classS * createClass(struct modifiersS * mods, char * id, char * parentId, struct classBodyS * body)
{
	struct classS * clas = (struct classS *)malloc(sizeof(struct classS));
	clas->mods = mods;
	clas->name = id;
	clas->parentClassName = parentId;
	clas->body = body;
	return clas;
	
}

struct classS * createClass(struct modifiersS * mods, char * id, struct classBodyS * body)
{
	return createClass(mods, id, 0, body);
}

struct classS * createClass(char * id, char * parentId, struct classBodyS * body)
{
	return createClass(0, id, parentId, body);
}

struct classS * createClass(char * id, struct classBodyS * body)
{
	return createClass(0, id, 0, body);
}

//Вспомогательные функции
struct classBodyElementS * createClassBodyElement(struct methodS * meth, struct initializerS * initializer, struct propertyS * prop, struct constructorS * constr, struct classBodyElementS * next)
{
	struct classBodyElementS * cbe = (struct classBodyElementS * )malloc(sizeof(struct classBodyElementS));
	cbe->method = meth;
	cbe->property = prop;
	cbe->constructor = constr;
	cbe->init = initializer;
	cbe->next = next;
	return cbe;
}

struct classBodyS * createClassBody(struct classBodyElementS * cbe)
{
	struct classBodyS * cb = (struct classBodyS *)malloc(sizeof(struct classBodyS));
	cb->first = cbe;
	cb->last = cbe;
	return cb;
}

struct classBodyS * addToClassBody(struct classBodyS * body, struct classBodyElementS * cbe)
{
	if (body->last != 0)
	{
		body->last->next = cbe;
		body->last = cbe;
	}
	else
	{
		body->first = cbe;
		body->last = cbe;
	}
	
	return body;
}

//Нужные функции
struct classBodyS * createClassBody()
{
	struct classBodyS * cb = (struct classBodyS *)malloc(sizeof(struct classBodyS));
	cb->first = 0;
	cb->last = 0;
	return cb;
}

struct classBodyS * createClassBody(struct methodS * meth)
{
	return createClassBody(createClassBodyElement(meth, 0, 0, 0, 0));
}

struct classBodyS * createClassBody(struct initializerS * initializer)
{
	return createClassBody(createClassBodyElement(0, initializer, 0, 0, 0));
}

struct classBodyS * createClassBody(struct propertyS * prop)
{
	return createClassBody(createClassBodyElement(0, 0, prop, 0, 0));
}

struct classBodyS * createClassBody(struct constructorS * constr)
{
	return createClassBody(createClassBodyElement(0, 0, 0, constr, 0));
}

struct classBodyS * addToClassBody(struct classBodyS * body, struct methodS * meth)
{
	return addToClassBody(body, createClassBodyElement(meth, 0, 0, 0, 0));
}

struct classBodyS * addToClassBody(struct classBodyS * body, struct initializerS * initializer)
{
	return addToClassBody(body, createClassBodyElement(0, initializer, 0, 0, 0));
}

struct classBodyS * addToClassBody(struct classBodyS * body, struct propertyS * prop)
{
	return addToClassBody(body, createClassBodyElement(0, 0, prop, 0, 0));
}

struct classBodyS * addToClassBody(struct classBodyS * body, struct constructorS * constr)
{
	return addToClassBody(body, createClassBodyElement(0, 0, 0, constr, 0));
}



struct propertyS * createProperty(struct modifiersS * mods, struct varOrValDeclS * decl)
{
	struct propertyS * p = (struct propertyS *)malloc(sizeof(struct propertyS));
	p->mods = mods;
	p->varOrVal = decl;
	return p;
}

struct propertyS * createProperty(struct varOrValDeclS * decl)
{
	return createProperty(0, decl);
}


struct methodS * createMethod(struct modifiersS * mods, struct funcDeclS * funcDecl, struct funcS * func)
{
	struct methodS * m = (struct methodS *)malloc(sizeof(struct methodS));
	m->mods = mods;
	m->func = func;
	m->funcDecl = funcDecl;
	return m;
}

struct methodS * createMethod(struct modifiersS * mods, struct funcDeclS * funcDecl)
{
	return createMethod(mods, funcDecl, 0);
}

struct methodS * createMethod(struct modifiersS * mods, struct funcS * func)
{
	return createMethod(mods, 0, func);
}

struct methodS * createMethod(struct funcDeclS * funcDecl)
{
	return createMethod(0, funcDecl, 0);
}

struct methodS * createMethod(struct funcS * func)
{
	return createMethod(0, 0, func);
}


struct initializerS * createInit(struct stmtList * stmts)
{
	struct initializerS * i = (struct initializerS *)malloc(sizeof(struct initializerS * ));
	i->stmts = stmts;
	return i;
}




struct constructorS * createConstructor(enum visibilityMod mod, struct formalParamsList * params, struct stmtList * stmts)
{
	return createConstructor(mod, params, 0, 0, stmts);
}

struct constructorS * createConstructor(enum visibilityMod mod, struct formalParamsList * params)
{
	return createConstructor(mod, params, 0, 0, 0);
}

struct constructorS * createConstructor(enum visibilityMod mod, struct formalParamsList * params, const char * parentOrAnotherConstr, struct factParamsList * anotherConstrParams)
{
	return createConstructor(mod, params, parentOrAnotherConstr, anotherConstrParams, 0);
}

struct constructorS * createConstructor(enum visibilityMod mod, struct formalParamsList * params, const char * parentOrAnotherConstr, struct factParamsList * anotherConstrParams, struct stmtList * stmts)
{
	struct constructorS * c = (struct constructorS *)malloc(sizeof(struct constructorS));
	c->mod = mod;
	c->params = params;
	c->stmts = stmts;
	c->anotherConstructorId = (char *)parentOrAnotherConstr;
	c->anotherConstrParams = anotherConstrParams;
	return c;
}

struct constructorS * createConstructor(struct formalParamsList * params, struct stmtList * stmts)
{
	return createConstructor(Public, params, 0, 0, stmts);
}

struct constructorS * createConstructor(struct formalParamsList * params)
{
	return createConstructor(Public, params, 0, 0, 0);
}

struct constructorS * createConstructor(struct formalParamsList * params, const char * parentOrAnotherConstr, struct factParamsList * anotherConstrParams)
{
	return createConstructor(Public, params, parentOrAnotherConstr, anotherConstrParams, 0);
}

struct constructorS * createConstructor(struct formalParamsList * params, const char * parentOrAnotherConstr, struct factParamsList * anotherConstrParams, struct stmtList * stmts)
{
	return createConstructor(Public, params, parentOrAnotherConstr, anotherConstrParams, stmts);
}


struct formalParamS * createFormalParam(char * id, struct typeS * type)
{
	struct formalParamS * fp = (struct formalParamS *)malloc(sizeof(struct formalParamS));
	fp->type = type;
	fp->name = id;
	fp-> next = 0;
	return fp;
}

struct formalParamsList * createFormalParamsList(char * id, struct typeS * type)
{
	struct formalParamsList * fpl = (struct formalParamsList *)malloc(sizeof(struct formalParamsList));
	fpl->first = createFormalParam(id, type);
	fpl->last = fpl->first;
	return fpl;
}

struct formalParamsList * addToFormalParamsList(struct formalParamsList * list, char * id, struct typeS * type)
{
	list->last->next = createFormalParam(id, type);
	list->last = list->last->next;
	return list;
}



struct modifiersS * createModifiers(int isAbstruct, int isOverride, enum visibilityMod vMod, enum inheritanceMod iMod)
{
	struct modifiersS * m = (struct modifiersS * )malloc(sizeof(struct modifiersS));
	m->isAbstract = isAbstruct;
	m->isOverride = isOverride;
	m->vMod = vMod;
	m->iMod = iMod;
	return m;
}
	
	
struct funcS * createFunc(struct funcDeclS * decl, struct stmtList * stmts, struct exprS * expr)
{
	struct funcS * f = (struct funcS *)malloc(sizeof(struct funcS));
	f->delc = decl;
	f->stmts = stmts;
	f->expr = expr;
	return f;
}	

struct funcS * createFunc(struct funcDeclS * decl, struct stmtList * stmts)
{
	return createFunc(decl, stmts, 0);
}

struct funcS * createFunc(struct funcDeclS * decl, struct exprS * expr)
{
	return createFunc(decl, 0, expr);
}


struct funcDeclS * createFuncDecl(char * id, struct formalParamsList * params, struct typeS * type)
{
	struct funcDeclS * fd = (struct funcDeclS *)malloc(sizeof(struct funcDeclS));
	fd->name = id;
	fd->params = params;
	fd->type = type;
	return fd;
}


struct stmtList * createStmtList(struct stmtS * stmt)
{
	struct stmtList * sl = (struct stmtList *)malloc(sizeof(struct stmtList));
	sl->first = stmt;
	sl->last = stmt;
	return sl;
}

struct stmtList * addToStmtList(struct stmtList * list, struct stmtS * stmt)
{
	list->last->next = stmt;
	list->last = stmt;
	return list;
}


struct varOrValDeclS * createVarOrValDecl(char * id, struct typeS * type, struct formalParamsList * idsAndTypes, struct exprS * initValue, int isVal)
{
	struct varOrValDeclS * v = (struct varOrValDeclS *)malloc(sizeof(struct varOrValDeclS));
	v->isVal = isVal;
	v->id = id;
	v->type = type;
	v->namesAndTypes = idsAndTypes;
	v->initValue = initValue;
	return v;
}

struct varOrValDeclS * createVarOrValDecl(char * id, struct typeS * type, int isVal)
{
	return createVarOrValDecl(id, type, 0, 0, isVal);
}

struct varOrValDeclS * createVarOrValDecl(char * id, struct typeS * type, struct exprS * initValue, int isVal)
{
	return createVarOrValDecl(id, type, 0, initValue, isVal);
}

struct varOrValDeclS * createVarOrValDecl(struct formalParamsList * idsAndTypes, struct exprS * initValue, int isVal)
{
	return createVarOrValDecl(0, 0, idsAndTypes, initValue, isVal);
}


struct typeS * createType(char * id, struct templateTypeS * type)
{
	struct typeS * t = (struct typeS * )malloc(sizeof(struct typeS));
	t->easyType = id;
	t->complexType = type;
	return t;
}

struct typeS * createType(char * id)
{
	return createType(id, 0);
}

struct typeS * createType(struct templateTypeS * type)
{
	return createType(0, type);
}


struct templateTypeS * createTemplateType(char * id, struct typesList * templateTypes)
{
	struct templateTypeS * tt = (struct templateTypeS *)malloc(sizeof(struct templateTypeS));
	tt->type = id;
	tt->list = templateTypes;
	return tt;
}


struct typesList * createTypesList(char * id, struct templateTypeS * type)
{
	struct typesList * tl = (struct typesList *)malloc(sizeof(struct typesList));
	struct typeS * listElement = 0;
	if (id != 0)
	{
		listElement = createType(id, 0);
	}
	else
	{
		listElement = createType(0, type);
	}
	tl->first = listElement;
	tl->last = listElement;
	return tl;
}

struct typesList * createTypesList(char * id)
{
	return createTypesList(id, 0);
}

struct typesList * createTypesList(struct templateTypeS * type)
{
	return createTypesList(0, type);
}

struct typesList * addToTypesList(struct typesList * list, char * id, struct templateTypeS * type)
{
	struct typeS * newListElement = 0;
	if (id != 0)
	{
		newListElement = createType(id);
	}
	else
	{
		newListElement = createType(type);
	}
	list->last->next = newListElement;
	list->last = newListElement;
	return list;
}

struct typesList * addToTypesList(struct typesList * list, char * id)
{
	return addToTypesList(list, id, 0);
}

struct typesList * addToTypesList(struct typesList * list, struct templateTypeS * type)
{
	return addToTypesList(list, 0, type);
}




struct stmtS * createStmt(struct varOrValDeclS * v, struct assignmentS * assign, struct whileLoopS * wLoop, forLoopS * fLoop, struct ifStmtS * ifStmt, struct exprS * expr, enum stmtType type)
{
	struct stmtS * s = (struct stmtS *)malloc(sizeof(struct stmtS));
	s->varOrVal = v;
	s->assignment = assign;
	s->whileLoop = wLoop;
	s->forLoop = fLoop;
	s->ifStmt = ifStmt;
	s->expr = expr;
	s->type = type;
	s->next = 0;
	return s;
}

struct stmtS * createStmt(struct varOrValDeclS * v, enum stmtType type)
{
	return createStmt(v, 0, 0, 0, 0, 0, type);
}

struct stmtS * createStmt(struct assignmentS * assign, enum stmtType type)
{
	return createStmt(0, assign, 0, 0, 0, 0, type);
}

struct stmtS * createStmt(struct whileLoopS * loop, enum stmtType type)
{
	return createStmt(0, 0, loop, 0, 0, 0, type);
}

struct stmtS * createStmt(struct forLoopS * loop, enum stmtType type)
{
	return createStmt(0, 0, 0, loop, 0, 0, type);
}

struct stmtS * createStmt(struct ifStmtS * ifStmt, enum stmtType type)
{
	return createStmt(0, 0, 0, 0, ifStmt, 0, type);
}

struct stmtS * createStmt(struct exprS * expr, enum stmtType type)
{
	return createStmt(0, 0, 0, 0, 0, expr, type);
}

struct stmtS * createStmt(enum stmtType type)
{
	return createStmt(0, 0, 0, 0, 0, 0, type);
}


struct exprS * createExpr(char * idOrString, int iVal, struct factParamsList * params, float fVal, double dVal, char cVar, bool bVar, struct exprS * exprL, struct exprS * exprR,  enum exprType type)
{
	struct exprS * e = (struct exprS *)malloc(sizeof(struct exprS));
	e->type = type;
	e->left = exprL;
	e->right = exprR;
	e->factParams = params;
	e->stringOrId = idOrString;
	e->charV = cVar;
	e->intV = iVal;
	e->floatV = fVal;
	e->doubleV = dVal;
	e->booleanV = bVar;
	e->next = 0;
	return e;
	
}

struct exprS * createExpr(char * idOrString, enum exprType type)
{
	return createExpr(idOrString, 0, 0, 0, 0, 0, 0, 0, 0, type);
}

struct exprS * createExpr(int val, enum exprType type)
{
	return createExpr(0, val, 0, 0, 0, 0, 0, 0, 0, type);
}

struct exprS * createExpr(char * idOrString, struct factParamsList * params, enum exprType type)
{
	return createExpr(idOrString, 0, params, 0, 0, 0, 0, 0, 0, type);
}

struct exprS * createExpr(float val, enum exprType type)
{
	return createExpr(0, 0, 0, val, 0, 0, 0, 0, 0, type);
}

struct exprS * createExpr(double val, enum exprType type)
{
	return createExpr(0, 0, 0, 0, val, 0, 0, 0, 0, type);
}

struct exprS * createExpr(char val, enum exprType type)
{
	return createExpr(0, 0, 0, 0, 0, val, 0, 0, 0, type);
}

struct exprS * createExpr(bool val, enum exprType type)
{
	return createExpr(0, 0, 0, 0, 0, 0, val, 0, 0, type);
}

struct exprS * createExpr(struct exprS * expr, enum exprType type)
{
	return createExpr(0, 0, 0, 0, 0, 0, 0, expr, 0, type);
}

struct exprS * createExpr(struct exprS * left, struct exprS * right, enum exprType type)
{
	return createExpr(0, 0, 0, 0, 0, 0, 0, left, right, type);
}

struct exprS * createExpr(struct exprS * left, char * right, enum exprType type)
{
	return createExpr(right, 0, 0, 0, 0, 0, 0, left, 0, type);
}

struct exprS * createExpr(struct exprS * left, char * right, struct factParamsList * params, enum exprType type)
{
	return createExpr(right, 0, params, 0, 0, 0, 0, left, 0, type);
}



struct factParamsList * createFactParamsList(struct exprS * expr)
{
	struct factParamsList * l = (struct factParamsList *)malloc(sizeof(struct factParamsList));
	l->first = expr;
	l->last = expr;
	return l;
}

struct factParamsList * addToFactParamsList(struct factParamsList * list, struct exprS * expr)
{
	list->last->next = expr;
	list->last = expr;
	return list;
}



struct assignmentS * createAssignment(struct exprS * left, struct exprS * right, enum assignmentType type)
{
	struct assignmentS * a = (struct assignmentS *)malloc(sizeof(struct assignmentS));
	a->type = type;
	a->left = left;
	a->right = right;
	return a;
}

struct whileLoopS * createWhileLoop(struct exprS * cond, struct stmtS * stmt, struct stmtList * stmts, int isDoWhile)
{
	struct whileLoopS * l = (struct whileLoopS *)malloc(sizeof(struct whileLoopS));
	l->isDoWhile = isDoWhile;
	l->cond = cond;
	if (stmt == 0) 
	{
		l->stmts = stmts;		
	}
	else
	{
		stmts = createStmtList(stmt);
	}
	return l;
}

struct whileLoopS * createWhileLoop(struct exprS * cond, struct stmtS * stmt, int isDoWhile)
{
	return createWhileLoop(cond, stmt, 0, isDoWhile);
}

struct whileLoopS * createWhileLoop(struct exprS * cond, struct stmtList * stmts, int isDoWhile)
{
	return createWhileLoop(cond, 0, stmts, isDoWhile);
}

struct whileLoopS * createWhileLoop(struct exprS * cond, int isDoWhile)
{
	return createWhileLoop(cond, 0, 0, isDoWhile);
}



struct forLoopS * createForLoop(char * id, struct typeS * type, struct exprS * iterableExpr, struct stmtS * stmt, struct stmtList * stmts, struct formalParamsList * idsAndTypes)
{
	struct forLoopS * l = (struct forLoopS *)malloc(sizeof(struct forLoopS));
	
	if (id == 0)
	{
		l->params = idsAndTypes;
	}
	else
	{
		l->params = createFormalParamsList(id, type);
	}
	l->iterableExpr = iterableExpr;
	if (stmt == 0)
	{
		l->stmts = stmts;
	}
	else
	{
		l->stmts = createStmtList(stmt);
	}
	
	return l;
}

struct forLoopS * createForLoop(char * id, struct typeS * type, struct exprS * iterableExpr, struct stmtS * stmt)
{
	return createForLoop(id, type, iterableExpr, stmt, 0, 0);
}

struct forLoopS * createForLoop(char * id, struct typeS * type, struct exprS * iterableExpr, struct stmtList * stmts)
{
	return createForLoop(id, type, iterableExpr, 0, stmts, 0);
}

struct forLoopS * createForLoop(struct formalParamsList * idsAndTypes, struct exprS * iterableExpr, struct stmtList * stmts)
{
	return createForLoop(0, 0, iterableExpr, 0, stmts, idsAndTypes);
}

struct forLoopS * createForLoop(struct formalParamsList * idsAndTypes, struct exprS * iterableExpr, struct stmtS * stmt)
{
	return createForLoop(0, 0, iterableExpr, stmt, 0, idsAndTypes);
}

struct forLoopS * createForLoop(char * id, struct typeS * type, struct exprS * iterableExpr)
{
	return createForLoop(id, type, iterableExpr, 0, 0, 0);
}

struct forLoopS * createForLoop(struct formalParamsList * idsAndTypes, struct exprS * iterableExpr)
{
	return createForLoop(0, 0, iterableExpr, 0, 0, idsAndTypes);
}


struct ifStmtS * createIfStmt(struct exprS * cond, struct stmtList * actions, struct stmtList * altActions, struct stmtS * action, struct stmtS * altAction)
{
	struct ifStmtS * i = (struct ifStmtS *)malloc(sizeof(struct ifStmtS));
	i->condition = cond;
	if (action == 0)
	{
		i->actions = actions;
	}
	else
	{
		i->actions = createStmtList(action);
	}
	if (altAction == 0)
	{
		i->altActions = altActions;
	}
	else
	{
		i->altActions = createStmtList(altAction);
	}
	return i;
}


struct ifStmtS * createIfStmt(struct exprS * cond, struct stmtS * action)
{
	return createIfStmt(cond, 0, 0, action, 0);
}

struct ifStmtS * createIfStmt(struct exprS * cond, struct stmtList * actions)
{
	return createIfStmt(cond, actions, 0, 0, 0);
}

struct ifStmtS * createIfStmt(struct exprS * cond)
{
	return createIfStmt(cond, 0, 0, 0, 0);
}

struct ifStmtS * createIfStmt(struct exprS * cond, struct stmtS * action, struct stmtS * altAction)
{
	return createIfStmt(cond, 0, 0, action, altAction);
}

struct ifStmtS * createIfStmt(struct exprS * cond, struct stmtS * action, struct stmtList * altActions)
{
	return createIfStmt(cond, 0, altActions, action, 0);
}

struct ifStmtS * createIfStmt(struct exprS * cond, struct stmtList * actions, struct stmtS * altAction)
{
	return createIfStmt(cond, actions, 0, 0, altAction);
}

struct ifStmtS * createIfStmt(struct exprS * cond, struct stmtList * actions, struct stmtList * altActions)
{
	return createIfStmt(cond, actions, altActions, 0, 0);
}

struct ifStmtS * createIfStmt(struct exprS * cond, int action, struct stmtS * altAction)
{
	return createIfStmt(cond, 0, 0, 0, altAction);
}

struct ifStmtS * createIfStmt(struct exprS * cond, int action, struct stmtList * altActions)
{
	return createIfStmt(cond, 0, altActions, 0, 0);
}




void main(int argc, char **argv ){
	yyin = fopen(argv[1], "r" );
	FILE * file = fopen("tree.dot", "w");
	
    yyparse();
	
	
    return;
}



















