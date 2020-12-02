enum exprType {
	Identificator,
	This,
	MethodCall,
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
	ArrayElementCall,
	ParentElementCall,
	Range
};

enum stmtType {
	Property,
	Method,
	Class,
	Constructor,
	Initializer,
	Assignment,
	WhileLoop,
	ForLoop,
	DoWhileLoop,
	IfStmt,
	Expr,
	Break,
	Continue,
	Return,
	ReturnValue;
};

struct exprS {
	enum exprType type;
	
	struct exprS * left;
	struct exprS * right;
	struct factParamsList * factParams;
	
	char * stringOrVarName;
	char charV;
	int intV;
	float floatV;
	double doubleV;
	bool booleanV;
	
};

struct factParamsList {
	struct factParam * first;
	struct factParam * last;
};

struct factParamS {
	struct exprS * param;
	struct exprS * next;

};

struct stmtS {
	enum stmtType;
	struct propertyS * property;
	struct methodS * method;
	struct classS * _class;
	struct constructorS * constructor;
	struct initializerS * initializer;
	struct assignmentS * assignment;
	struct whileLoopS * whileLoop;
	struct forLoopS * forLoop;
	struct doWhileLoopS * doWhileLoop;
	struct ifStmtS * ifStmt;	
	struct exprS * expr;	
};

struct ifStmtS {
	struct exprS * condition;
	struct stmtList * actions;
	struct stmtList * altActions;	
};

struct forLoopS {
	




};
















