
#include <string>

using namespace std;

enum exprType 
{
	Identificator,
	This,
	MethodCall,
	ConstructorCall,
	Int,
	Float,
	String,
	Char,
	Double,
	Boolean,
	ExprInBrackets,
	LogicalNot,
	UnaryPlusExpr,
	UnaryMinusExpr,
	Sum,
	Sub,
	Mul,
	Div,
	Mod,
	Less,
	More,
	Or,
	And,
	Eq,
	Aeq,
	Neq,
	Naeq,
	Loeq,
	Moeq,
	FieldCalcExpr,
	MethodCalcExpr,
	ArrayElementCall,
	ParentFieldCall,
	ParentMethodCall,
	Range,
	TypeCast
};

enum assignmentType
{
	Assign,
	Asum,
	Asub,
	Adiv,
	Amul,
	Amod,
	AssignToField,
	AsumToField,
	AsubToField,
	AdivToField,
	AmulToField,
	AmodToField,
	AssignToArray,
	AsumToArray,
	AsubToArray,
	AdivToArray,
	AmulToArray,
	AmodToArray
};

enum stmtType 
{
	VarOrVal,
	Assignment,
	WhileLoop,
	ForLoop,
	DoWhileLoop,
	IfStmt,
	Expr,
	Break,
	Continue,
	Return,
	ReturnValue
};

struct modifiersS
{
	bool isAbstract;
	bool isOverride;
	enum visibilityMod vMod;
	enum inheritanceMod iMod;
	bool isStatic;
};

enum visibilityMod 
{
	Public,
	Protected,
	Private,
	Internal,
	Local,
	Unknown
};	

enum inheritanceMod
{
	Final,
	Open,
	None
};

struct exprS 
{
	enum exprType type;
	
	struct exprS * left;
	struct exprS * right;
	struct factParamsList * factParams;
	
	char * stringOrId;
	char charV;
	int intV;
	float floatV;
	double doubleV;
	bool booleanV;
	
	struct exprS * next;

	int varInTableNum;
	uint16_t refInfo;
	bool isStaticCall;
	string exprRes;
};

struct factParamsList 
{
	struct exprS * first;
	struct exprS * last;
};


struct stmtS 
{
	enum stmtType type;
	struct varOrValDeclS * varOrVal;
	struct assignmentS * assignment;
	struct whileLoopS * whileLoop;
	struct forLoopS * forLoop;
	struct ifStmtS * ifStmt;	
	struct exprS * expr;	
	struct stmtS * next;
};

struct stmtList 
{
	struct stmtS * first;
	struct stmtS * last;
};

struct ifStmtS 
{
	struct exprS * condition;
	struct stmtList * actions;
	struct stmtList * altActions;	
};

struct forLoopS 
{
	struct formalParamsList * params;
	struct exprS * iterableExpr;
	struct stmtList * stmts;
	bool isDestructing;
};

struct whileLoopS 
{
	bool isDoWhile;
	struct exprS * cond;
	struct stmtList * stmts;	
};

struct assignmentS
{
	enum assignmentType type;
	struct exprS * left;
	struct exprS * right;
	struct exprS* subLeft;
	char* fieldName;
};

struct propertyS 
{
	struct varOrValDeclS * varOrVal;
	struct modifiersS * mods;
};

struct varOrValDeclS 
{
	bool isVal;
	char * id;
	struct typeS * type;
	struct formalParamsList * namesAndTypes;
	struct exprS * initValue;
};

struct typeS 
{
	char * easyType;
	struct templateTypeS * complexType;
	struct typeS * next;
};

struct templateTypeS 
{
	char * type;
	struct typesList * list;
};

struct typesList
{
	struct typeS * first;
	struct typeS * last;
};


struct formalParamS 
{
	struct typeS * type;
	char * name;
	struct formalParamS * next;
};	

struct formalParamsList
{
	struct formalParamS * first;
	struct formalParamS * last;
};

struct funcDeclS
{
	char * name;
	struct formalParamsList * params;
	struct typeS * type;
};

struct funcS 
{
	struct funcDeclS * delc;
	struct stmtList * stmts;
	struct exprS * expr;
};

struct constructorS
{
	enum visibilityMod mod;
	struct formalParamsList * params;
	struct stmtList * stmts;
	char * anotherConstructorId;
	struct factParamsList * anotherConstrParams;
};

struct methodS
{
	struct modifiersS * mods;
	struct funcS * func;
	struct funcDeclS * funcDecl;
};

struct initializerS
{
	struct stmtList * stmts;
};

struct classS
{
	struct modifiersS * mods;
	char * name;
	char * parentClassName;
	struct classBodyS * body;
};

struct classBodyElementS
{
	struct methodS * method;
	struct propertyS * property;
	struct constructorS * constructor;
	struct initializerS * init;
	struct classBodyElementS * next;
};

struct classBodyS
{
	struct classBodyElementS * first;
	struct classBodyElementS * last;
};

struct programElementS
{
	struct classS * clas;
	struct methodS * method;
	struct propertyS * property;
	struct programElementS * next;
};

struct programS
{
	struct programElementS * first;
	struct programElementS * last;
};