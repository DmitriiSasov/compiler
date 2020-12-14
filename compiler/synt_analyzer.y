%define parse.error verbose

%{

	#include <stdio.h>
	#include <malloc.h>
	#include <string.h>
	#include "print_funcs.h"
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

program: semis	{root = createProgram(); puts("program created");}
| newLines	{root = createProgram();puts("program created");}
| class	{root = createProgram($1);puts("program created");}
| method	{root = createProgram($1);puts("program created");}
| property semis	{root = createProgram($1);puts("program created");}
| property newLines	{root = createProgram($1);puts("program created");}
| program class	{$$ = addToProgram($1, $2);puts("class added to prog");}
| program method	{$$ = addToProgram($1, $2);puts("meth added to prog");}
| program property semis	{$$ = addToProgram($1, $2);puts("prop added to prog");}
| program property newLines	{$$ = addToProgram($1, $2);puts("prop added to prog");}
| program newLines {$$ = $1;puts("new lines added to prog");}
| program semis {$$ = $1;puts("semis added to prog");}
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
| newLines	{$$ = createClassBody();  puts("class body created");}
| method	{$$ = createClassBody($1);  puts("class body created");}
| property semis	{$$ = createClassBody($1);  puts("class body created");}
| property newLines	{$$ = createClassBody($1);  puts("class body created");}
| constructor	{$$ = createClassBody($1);  puts("class body created");}
| initializer	{$$ = createClassBody($1);  puts("class body created");}
| classBody method	{$$ = addToClassBody($1, $2);  puts("meth added to class body");}
| classBody property semis	{$$ = addToClassBody($1, $2); puts("prop added to class body");}
| classBody property newLines	{$$ = addToClassBody($1, $2); puts("prop added to class body");}
| classBody newLines	 {$$ = $1; puts("new lines added to class body");}
| classBody constructor	{$$ = addToClassBody($1, $2); puts("constr added to class body");}
| classBody initializer	{$$ = addToClassBody($1, $2); puts("init added to class body");}
| classBody semis	{$$ = $1; puts("semis added to class body");}
;

property: modifiers valDeclaration	{$$ = createProperty($1, $2); puts("prop created");}
| modifiers varDeclaration	{$$ = createProperty($1, $2); puts("prop created");}
| valDeclaration	{$$ = createProperty($1); puts("prop created");}
| varDeclaration	{$$ = createProperty($1); puts("prop created");}
;

method: modifiers funcDeclaration ';'	{$$ = createMethod($1, $2); puts("meth created");}
| modifiers func	{$$ = createMethod($1, $2); puts("meth created");}
| funcDeclaration ';'	{$$ = createMethod($1); puts("meth created");}
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
| visibilityModifier	{$$ = createModifiers(0, 1, $1, None); puts("mods created");}
| inheritanceModifier	{$$ = createModifiers(0, 1, Unknown, $1); puts("mods created");}
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


block : '{' optNewLines stmts optNewLines '}'	{$$ = $3;  puts("block created");}
| '{' semis stmts optNewLines '}'	{$$ = $3;  puts("block created");}
| '{' semis '}'	{$$ = 0;  puts("block created");}
| '{' optNewLines '}'	{$$ = 0;  puts("block created");}
;


varDeclaration: VAR ID ':' type	{$$ = createVarOrValDecl($2, $4, 0); puts("val created");}
| VAR ID ':' type '=' expr	{$$ = createVarOrValDecl($2, $4, $6, 0); puts("val created");}
| VAR '(' formalParams ')' '=' expr	{$$ = createVarOrValDecl($3, $6, 0); puts("val created"); }
;


valDeclaration: VAL ID ':' type	{$$ = createVarOrValDecl($2, $4, 1); puts("var created"); }
| VAL ID ':' type '=' expr	{$$ = createVarOrValDecl($2, $4, $6, 1); puts("var created"); }
| VAL '(' formalParams ')' '=' expr	{$$ = createVarOrValDecl($3, $6, 1); puts("var created"); }
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
| stmts optNewLines stmt	{$$ = addToStmtList($1, $3);  puts("stmts created"); }
;

stmt : valDeclaration semis	{$$ = createStmt($1, VarOrVal);  puts("stmt created"); }
| valDeclaration newLines	{$$ = createStmt($1, VarOrVal);  puts("stmt created"); }
| varDeclaration semis	{$$ = createStmt($1, VarOrVal);  puts("stmt created"); }
| varDeclaration newLines	{$$ = createStmt($1, VarOrVal);  puts("stmt created"); }
| assignment semis	{$$ = createStmt($1, Assignment);  puts("stmt created"); }
| assignment newLines	{$$ = createStmt($1, Assignment);  puts("stmt created"); }
| whileLoop semis	{$$ = createStmt($1, WhileLoop);  puts("stmt created"); }
| whileLoop newLines	{$$ = createStmt($1, WhileLoop);  puts("stmt created"); }
| forLoop semis	{$$ = createStmt($1, ForLoop);  puts("stmt created"); }
| forLoop newLines	{$$ = createStmt($1, ForLoop);  puts("stmt created"); }
| doWhileLoop semis	{$$ = createStmt($1, DoWhileLoop);  puts("stmt created"); }
| doWhileLoop newLines	{$$ = createStmt($1, DoWhileLoop);  puts("stmt created"); }
| ifStmt semis	{$$ = createStmt($1, IfStmt);  puts("stmt created"); }
| ifStmt newLines	{$$ = createStmt($1, IfStmt);  puts("stmt created"); }
| expr newLines	{$$ = createStmt($1, Expr);  puts("stmt created"); }
| expr semis	{$$ = createStmt($1, Expr);  puts("stmt created"); }
| BREAK semis	{$$ = createStmt(Break);  puts("stmt created"); }
| BREAK newLines	{$$ = createStmt(Break);  puts("stmt created"); }
| CONTINUE semis	{$$ = createStmt(Continue);  puts("stmt created"); }
| CONTINUE newLines	{$$ = createStmt(Continue);  puts("stmt created"); }
| RETURN semis	{$$ = createStmt(Return);  puts("stmt created"); }
| RETURN newLines	{$$ = createStmt(Return);  puts("stmt created"); }
| RETURN expr newLines	{$$ = createStmt($2, ReturnValue);  puts("stmt created"); }
| RETURN expr semis	{$$ = createStmt($2, ReturnValue);  puts("stmt created"); }
;

expr: ID	{$$ = createExpr($1, Identificator);  puts("expr created"); }
| THIS 	{$$ = createExpr(0, This);  puts("expr created"); }
| ID '(' optFactParams ')'	{$$ = createExpr($1, $3, MethodCall);  puts("expr created"); }
| INT 	{$$ = createExpr($1, Int);  puts("expr created"); }
| FLOAT 	{$$ = createExpr($1, Float);  puts("expr created"); }
| STRING 	{$$ = createExpr($1, String);  puts("expr created"); }
| CHAR 	{$$ = createExpr($1, Char);  puts("expr created"); }
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
| WHILE '(' expr ')' block	{$$ = createWhileLoop($3, $5, 0); puts("whileLoop created"); }
| WHILE '(' expr ')' ';'	{$$ = createWhileLoop($3, 0); puts("whileLoop created"); }
;

doWhileLoop: DO stmt WHILE '(' expr ')'	{$$ = createWhileLoop($5, $2, 1); puts("doWhileLoop created"); }
| DO block WHILE '(' expr ')'	{$$ = createWhileLoop($5, $2, 1); puts("doWhileLoop created"); }
| DO WHILE '(' expr ')' optNewLines	{$$ = createWhileLoop($4, 1); puts("doWhileLoop created"); }
;

forLoop: FOR '(' ID ':' type IN expr ')' stmt	{$$ = createForLoop($3, $5, $7, $9); puts("forLoop created"); }
| FOR '(' ID ':' type IN expr ')' block	{$$ = createForLoop($3, $5, $7, $9); puts("forLoop created"); }
| FOR '(' ID ':' type IN expr ')' ';' 	{$$ = createForLoop($3, $5, $7); puts("forLoop created"); }
| FOR '(' '(' formalParams ')' IN expr ')' stmt	{$$ = createForLoop($4, $7, $9); puts("forLoop created"); }
| FOR '(' '(' formalParams ')' IN expr ')' block	{$$ = createForLoop($4, $7, $9); puts("forLoop created"); }
| FOR '(' '(' formalParams ')' IN expr ')' ';'	{$$ = createForLoop($4, $7); puts("forLoop created"); }
;

ifStmt: IF '(' expr ')' stmt	{$$ = createIfStmt($3, $5); puts("ifStmt created"); }
| IF '(' expr ')' block	{$$ = createIfStmt($3, $5); puts("ifStmt created"); }
| IF '(' expr ')' semis 	{$$ = createIfStmt($3); puts("ifStmt created"); }
| IF '(' expr ')' stmt ELSE stmt	{$$ = createIfStmt($3, $5, $7); puts("ifStmt created"); }
| IF '(' expr ')' block ELSE stmt	{$$ = createIfStmt($3, $5, $7); puts("ifStmt created"); }
| IF '(' expr ')' semis ELSE stmt	{$$ = createIfStmt($3, 0, $7); puts("ifStmt created"); }
| IF '(' expr ')' stmt ELSE block	{$$ = createIfStmt($3, $5, $7); puts("ifStmt created"); }
| IF '(' expr ')' block ELSE block	{$$ = createIfStmt($3, $5, $7); puts("ifStmt created"); }
| IF '(' expr ')' semis ELSE block	{$$ = createIfStmt($3, 0, $7); puts("ifStmt created"); }
| IF '(' expr ')' stmt ELSE semis	{$$ = createIfStmt($3, $5); puts("ifStmt created"); }
| IF '(' expr ')' block ELSE semis	{$$ = createIfStmt($3, $5); puts("ifStmt created"); }
| IF '(' expr ')' semis ELSE semis	{$$ = createIfStmt($3); puts("ifStmt created"); }
;


optNewLines: /*empty*/ { puts("opt new lines created"); }
| newLines { puts("opt new lines created"); }
;

newLines: NEW_LINE	{ puts("new lines created"); }
| newLines NEW_LINE		{ puts("new lines created"); }
;

semis: ';'	{ puts("semis created"); }
| semis ';'	{ puts("semis created"); }
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
	if (parentOrAnotherConstr != 0)
	{
		c->anotherConstructorId = (char *)malloc(strlen(parentOrAnotherConstr));
		strcpy(c->anotherConstructorId, parentOrAnotherConstr);
	}
	else
	{
		c->anotherConstructorId = 0;
	}
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
	yyin = fopen(argv[1], "r");
	FILE * file = fopen("tree.dot", "w");
	
    yyparse();

	fprintf(file, "digraph G {\n");
	print(root, file);
	fprintf(file, "\n}");

	fclose(file);

    return;
}



















