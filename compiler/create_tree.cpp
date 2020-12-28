#include "create_tree.h"
//Вспомогательные функция
struct programS* createProgram(struct programElementS* pe)
{
	struct programS* prog = (struct programS*) malloc(sizeof(struct programS));
	prog->first = pe;
	prog->last = pe;
	return prog;
}

struct programS* addToProgram(struct programS* prog, struct programElementS* pe)
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

struct programElementS* createProgramElement(struct classS* clas, struct methodS* meth, struct propertyS* prop, struct programElementS* next)
{
	struct programElementS* pe = (struct programElementS*) malloc(sizeof(struct programElementS));
	pe->clas = clas;
	pe->method = meth;
	pe->property = prop;
	pe->next = next;
	return pe;
}

struct programElementS* createProgramElement(struct classS* clas)
{
	return createProgramElement(clas, 0, 0, 0);
}

struct programElementS* createProgramElement(struct methodS* meth)
{
	return createProgramElement(0, meth, 0, 0);
}

struct programElementS* createProgramElement(struct propertyS* prop)
{
	return createProgramElement(0, 0, prop, 0);
}

//Нужные функции
struct programS* createProgram()
{
	struct programS* prog = (struct programS*) malloc(sizeof(struct programS));
	prog->first = 0;
	prog->last = 0;
	return prog;
}

struct programS* createProgram(struct classS* clas)
{
	return createProgram(createProgramElement(clas));
}

struct programS* createProgram(struct methodS* meth)
{
	return createProgram(createProgramElement(meth));
}

struct programS* createProgram(struct propertyS* prop)
{
	return createProgram(createProgramElement(prop));
}

struct programS* addToProgram(struct programS* prog, struct classS* clas)
{
	return addToProgram(prog, createProgramElement(clas));
}

struct programS* addToProgram(struct programS* prog, struct methodS* meth)
{
	return addToProgram(prog, createProgramElement(meth));
}

struct programS* addToProgram(struct programS* prog, struct propertyS* prop)
{
	return addToProgram(prog, createProgramElement(prop));
}



struct classS* createClass(struct modifiersS* mods, char* id, char* parentId, struct classBodyS* body)
{
	struct classS* clas = (struct classS*)malloc(sizeof(struct classS));
	clas->mods = mods;
	clas->name = id;
	clas->parentClassName = parentId;
	clas->body = body;
	return clas;

}

struct classS* createClass(struct modifiersS* mods, char* id, struct classBodyS* body)
{
	return createClass(mods, id, 0, body);
}

struct classS* createClass(char* id, char* parentId, struct classBodyS* body)
{
	return createClass(0, id, parentId, body);
}

struct classS* createClass(char* id, struct classBodyS* body)
{
	return createClass(0, id, 0, body);
}

//Вспомогательные функции
struct classBodyElementS* createClassBodyElement(struct methodS* meth, struct initializerS* initializer, struct propertyS* prop, struct constructorS* constr, struct classBodyElementS* next)
{
	struct classBodyElementS* cbe = (struct classBodyElementS*)malloc(sizeof(struct classBodyElementS));
	cbe->method = meth;
	cbe->property = prop;
	cbe->constructor = constr;
	cbe->init = initializer;
	cbe->next = next;
	return cbe;
}

struct classBodyS* createClassBody(struct classBodyElementS* cbe)
{
	struct classBodyS* cb = (struct classBodyS*)malloc(sizeof(struct classBodyS));
	cb->first = cbe;
	cb->last = cbe;
	return cb;
}

struct classBodyS* addToClassBody(struct classBodyS* body, struct classBodyElementS* cbe)
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
struct classBodyS* createClassBody()
{
	struct classBodyS* cb = (struct classBodyS*)malloc(sizeof(struct classBodyS));
	cb->first = 0;
	cb->last = 0;
	return cb;
}

struct classBodyS* createClassBody(struct methodS* meth)
{
	return createClassBody(createClassBodyElement(meth, 0, 0, 0, 0));
}

struct classBodyS* createClassBody(struct initializerS* initializer)
{
	return createClassBody(createClassBodyElement(0, initializer, 0, 0, 0));
}

struct classBodyS* createClassBody(struct propertyS* prop)
{
	return createClassBody(createClassBodyElement(0, 0, prop, 0, 0));
}

struct classBodyS* createClassBody(struct constructorS* constr)
{
	return createClassBody(createClassBodyElement(0, 0, 0, constr, 0));
}

struct classBodyS* addToClassBody(struct classBodyS* body, struct methodS* meth)
{
	return addToClassBody(body, createClassBodyElement(meth, 0, 0, 0, 0));
}

struct classBodyS* addToClassBody(struct classBodyS* body, struct initializerS* initializer)
{
	return addToClassBody(body, createClassBodyElement(0, initializer, 0, 0, 0));
}

struct classBodyS* addToClassBody(struct classBodyS* body, struct propertyS* prop)
{
	return addToClassBody(body, createClassBodyElement(0, 0, prop, 0, 0));
}

struct classBodyS* addToClassBody(struct classBodyS* body, struct constructorS* constr)
{
	return addToClassBody(body, createClassBodyElement(0, 0, 0, constr, 0));
}



struct propertyS* createProperty(struct modifiersS* mods, struct varOrValDeclS* decl)
{
	struct propertyS* p = (struct propertyS*)malloc(sizeof(struct propertyS));
	p->mods = mods;
	p->varOrVal = decl;
	return p;
}

struct propertyS* createProperty(struct varOrValDeclS* decl)
{
	return createProperty(0, decl);
}


struct methodS* createMethod(struct modifiersS* mods, struct funcDeclS* funcDecl, struct funcS* func)
{
	struct methodS* m = (struct methodS*)malloc(sizeof(struct methodS));
	m->mods = mods;
	m->func = func;
	m->funcDecl = funcDecl;
	return m;
}

struct methodS* createMethod(struct modifiersS* mods, struct funcDeclS* funcDecl)
{
	return createMethod(mods, funcDecl, 0);
}

struct methodS* createMethod(struct modifiersS* mods, struct funcS* func)
{
	return createMethod(mods, 0, func);
}

struct methodS* createMethod(struct funcDeclS* funcDecl)
{
	return createMethod(0, funcDecl, 0);
}

struct methodS* createMethod(struct funcS* func)
{
	return createMethod(0, 0, func);
}


struct initializerS* createInit(struct stmtList* stmts)
{
	struct initializerS* i = (struct initializerS*)malloc(sizeof(struct initializerS*));
	i->stmts = stmts;
	return i;
}




struct constructorS* createConstructor(enum visibilityMod mod, struct formalParamsList* params, struct stmtList* stmts)
{
	return createConstructor(mod, params, 0, 0, stmts);
}

struct constructorS* createConstructor(enum visibilityMod mod, struct formalParamsList* params)
{
	return createConstructor(mod, params, 0, 0, 0);
}

struct constructorS* createConstructor(enum visibilityMod mod, struct formalParamsList* params, const char* parentOrAnotherConstr, struct factParamsList* anotherConstrParams)
{
	return createConstructor(mod, params, parentOrAnotherConstr, anotherConstrParams, 0);
}

struct constructorS* createConstructor(enum visibilityMod mod, struct formalParamsList* params, const char* parentOrAnotherConstr, struct factParamsList* anotherConstrParams, struct stmtList* stmts)
{
	struct constructorS* c = (struct constructorS*)malloc(sizeof(struct constructorS));
	c->mod = mod;
	c->params = params;
	c->stmts = stmts;
	c->isStatic = false;
	if (parentOrAnotherConstr != 0)
	{
		c->anotherConstructorId = (char*)malloc(strlen(parentOrAnotherConstr));
		strcpy(c->anotherConstructorId, parentOrAnotherConstr);
	}
	else
	{
		c->anotherConstructorId = 0;
	}
	c->anotherConstrParams = anotherConstrParams;
	return c;
}

struct constructorS* createConstructor(struct formalParamsList* params, struct stmtList* stmts)
{
	return createConstructor(Public, params, 0, 0, stmts);
}

struct constructorS* createConstructor(struct formalParamsList* params)
{
	return createConstructor(Public, params, 0, 0, 0);
}

struct constructorS* createConstructor(struct formalParamsList* params, const char* parentOrAnotherConstr, struct factParamsList* anotherConstrParams)
{
	return createConstructor(Public, params, parentOrAnotherConstr, anotherConstrParams, 0);
}

struct constructorS* createConstructor(struct formalParamsList* params, const char* parentOrAnotherConstr, struct factParamsList* anotherConstrParams, struct stmtList* stmts)
{
	return createConstructor(Public, params, parentOrAnotherConstr, anotherConstrParams, stmts);
}


struct formalParamS* createFormalParam(char* id, struct typeS* type)
{
	struct formalParamS* fp = (struct formalParamS*)malloc(sizeof(struct formalParamS));
	fp->type = type;
	fp->name = id;
	fp->next = 0;
	return fp;
}

struct formalParamsList* createFormalParamsList(char* id, struct typeS* type)
{
	struct formalParamsList* fpl = (struct formalParamsList*)malloc(sizeof(struct formalParamsList));
	fpl->first = createFormalParam(id, type);
	fpl->last = fpl->first;
	return fpl;
}

struct formalParamsList* addToFormalParamsList(struct formalParamsList* list, char* id, struct typeS* type)
{
	list->last->next = createFormalParam(id, type);
	list->last = list->last->next;
	return list;
}



struct modifiersS* createModifiers(int isAbstruct, int isOverride, enum visibilityMod vMod, enum inheritanceMod iMod)
{
	struct modifiersS* m = (struct modifiersS*)malloc(sizeof(struct modifiersS));
	m->isAbstract = isAbstruct;
	m->isOverride = isOverride;
	m->vMod = vMod;
	m->iMod = iMod;
	m->isStatic = false;
	return m;
}


struct funcS* createFunc(struct funcDeclS* decl, struct stmtList* stmts, struct exprS* expr)
{
	struct funcS* f = (struct funcS*)malloc(sizeof(struct funcS));
	f->decl = decl;
	f->stmts = stmts;
	f->expr = expr;
	return f;
}

struct funcS* createFunc(struct funcDeclS* decl, struct stmtList* stmts)
{
	return createFunc(decl, stmts, 0);
}

struct funcS* createFunc(struct funcDeclS* decl, struct exprS* expr)
{
	return createFunc(decl, 0, expr);
}


struct funcDeclS* createFuncDecl(char* id, struct formalParamsList* params, struct typeS* type)
{
	struct funcDeclS* fd = (struct funcDeclS*)malloc(sizeof(struct funcDeclS));
	fd->name = id;
	fd->params = params;
	fd->type = type;
	return fd;
}


struct stmtList* createStmtList(struct stmtS* stmt)
{
	struct stmtList* sl = (struct stmtList*)malloc(sizeof(struct stmtList));
	sl->first = stmt;
	sl->last = stmt;
	return sl;
}

struct stmtList* addToStmtList(struct stmtList* list, struct stmtS* stmt)
{
	list->last->next = stmt;
	list->last = stmt;
	return list;
}


struct varOrValDeclS* createVarOrValDecl(char* id, struct typeS* type, struct formalParamsList* idsAndTypes, struct exprS* initValue, int isVal)
{
	struct varOrValDeclS* v = (struct varOrValDeclS*)malloc(sizeof(struct varOrValDeclS));
	v->isVal = isVal;
	v->id = id;
	v->type = type;
	v->namesAndTypes = idsAndTypes;
	v->initValue = initValue;
	v->varNumber = -1;
	return v;
}

struct varOrValDeclS* createVarOrValDecl(char* id, struct typeS* type, int isVal)
{
	return createVarOrValDecl(id, type, 0, 0, isVal);
}

struct varOrValDeclS* createVarOrValDecl(char* id, struct typeS* type, struct exprS* initValue, int isVal)
{
	return createVarOrValDecl(id, type, 0, initValue, isVal);
}

struct varOrValDeclS* createVarOrValDecl(struct formalParamsList* idsAndTypes, struct exprS* initValue, int isVal)
{
	return createVarOrValDecl(0, 0, idsAndTypes, initValue, isVal);
}


struct typeS* createType(char* id, struct templateTypeS* type)
{
	struct typeS* t = (struct typeS*)malloc(sizeof(struct typeS));
	t->easyType = id;
	t->complexType = type;
	t->next = 0;
	return t;
}

struct typeS* createType(char* id)
{
	return createType(id, 0);
}

struct typeS* createType(struct templateTypeS* type)
{
	return createType(0, type);
}


struct templateTypeS* createTemplateType(char* id, struct typesList* templateTypes)
{
	struct templateTypeS* tt = (struct templateTypeS*)malloc(sizeof(struct templateTypeS));
	tt->type = id;
	tt->list = templateTypes;
	return tt;
}


struct typesList* createTypesList(char* id, struct templateTypeS* type)
{
	struct typesList* tl = (struct typesList*)malloc(sizeof(struct typesList));
	struct typeS* listElement = 0;
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

struct typesList* createTypesList(char* id)
{
	return createTypesList(id, 0);
}

struct typesList* createTypesList(struct templateTypeS* type)
{
	return createTypesList(0, type);
}

struct typesList* addToTypesList(struct typesList* list, char* id, struct templateTypeS* type)
{
	struct typeS* newListElement = 0;
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

struct typesList* addToTypesList(struct typesList* list, char* id)
{
	return addToTypesList(list, id, 0);
}

struct typesList* addToTypesList(struct typesList* list, struct templateTypeS* type)
{
	return addToTypesList(list, 0, type);
}




struct stmtS* createStmt(struct varOrValDeclS* v, struct assignmentS* assign, struct whileLoopS* wLoop, forLoopS* fLoop, struct ifStmtS* ifStmt, struct exprS* expr, enum stmtType type)
{
	struct stmtS* s = (struct stmtS*)malloc(sizeof(struct stmtS));
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

struct stmtS* createStmt(struct varOrValDeclS* v, enum stmtType type)
{
	return createStmt(v, 0, 0, 0, 0, 0, type);
}

struct stmtS* createStmt(struct assignmentS* assign, enum stmtType type)
{
	return createStmt(0, assign, 0, 0, 0, 0, type);
}

struct stmtS* createStmt(struct whileLoopS* loop, enum stmtType type)
{
	return createStmt(0, 0, loop, 0, 0, 0, type);
}

struct stmtS* createStmt(struct forLoopS* loop, enum stmtType type)
{
	return createStmt(0, 0, 0, loop, 0, 0, type);
}

struct stmtS* createStmt(struct ifStmtS* ifStmt, enum stmtType type)
{
	return createStmt(0, 0, 0, 0, ifStmt, 0, type);
}

struct stmtS* createStmt(struct exprS* expr, enum stmtType type)
{
	return createStmt(0, 0, 0, 0, 0, expr, type);
}

struct stmtS* createStmt(enum stmtType type)
{
	return createStmt(0, 0, 0, 0, 0, 0, type);
}


struct exprS* createExprCopy(exprS* e1)
{
	exprS* newE = (exprS*)malloc(sizeof(exprS));
	newE->type = e1->type;
	newE->left = e1->left;
	newE->right = e1->right;
	newE->factParams = e1->factParams;
	newE->stringOrId = e1->stringOrId;
	newE->charV = e1->charV;
	newE->intV = e1->intV;
	newE->floatV = e1->floatV;
	newE->doubleV = e1->doubleV;
	newE->booleanV = e1->booleanV;
	newE->next = 0;
	newE->varInTableNum = e1->varInTableNum;
	newE->refInfo = e1->refInfo;
	newE->isStaticCall = e1->isStaticCall;
	newE->exprRes = e1->exprRes;
	
	return newE;
}

struct exprS* createExpr(char* idOrString, int iVal, struct factParamsList* params, float fVal, double dVal, char cVar, bool bVar, struct exprS* exprL, struct exprS* exprR, enum exprType type)
{
	struct exprS* e = new exprS();
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
	e->varInTableNum = -1;
	e->refInfo = -1;
	e->isStaticCall = false;
	return e;

}

struct exprS* createExpr(char* idOrString, enum exprType type)
{
	return createExpr(idOrString, 0, 0, 0, 0, 0, 0, 0, 0, type);
}

struct exprS* createExpr(int val, enum exprType type)
{
	return createExpr(0, val, 0, 0, 0, 0, 0, 0, 0, type);
}

struct exprS* createExpr(char* idOrString, struct factParamsList* params, enum exprType type)
{
	return createExpr(idOrString, 0, params, 0, 0, 0, 0, 0, 0, type);
}

struct exprS* createExpr(float val, enum exprType type)
{
	return createExpr(0, 0, 0, val, 0, 0, 0, 0, 0, type);
}

struct exprS* createExpr(double val, enum exprType type)
{
	return createExpr(0, 0, 0, 0, val, 0, 0, 0, 0, type);
}

struct exprS* createExpr(char val, enum exprType type)
{
	return createExpr(0, 0, 0, 0, 0, val, 0, 0, 0, type);
}

struct exprS* createExpr(bool val, enum exprType type)
{
	return createExpr(0, 0, 0, 0, 0, 0, val, 0, 0, type);
}

struct exprS* createExpr(struct exprS* expr, enum exprType type)
{
	return createExpr(0, 0, 0, 0, 0, 0, 0, expr, 0, type);
}

struct exprS* createExpr(struct exprS* left, struct exprS* right, enum exprType type)
{
	return createExpr(0, 0, 0, 0, 0, 0, 0, left, right, type);
}

struct exprS* createExpr(struct exprS* left, char* right, enum exprType type)
{
	return createExpr(right, 0, 0, 0, 0, 0, 0, left, 0, type);
}

struct exprS* createExpr(struct exprS* left, char* right, struct factParamsList* params, enum exprType type)
{
	return createExpr(right, 0, params, 0, 0, 0, 0, left, 0, type);
}



struct factParamsList* createFactParamsList(struct exprS* expr)
{
	struct factParamsList* l = (struct factParamsList*)malloc(sizeof(struct factParamsList));
	l->first = expr;
	l->last = expr;
	return l;
}

struct factParamsList* addToFactParamsList(struct factParamsList* list, struct exprS* expr)
{
	list->last->next = expr;
	list->last = expr;
	return list;
}



struct assignmentS* createAssignment(struct exprS* left, struct exprS* right, enum assignmentType type)
{
	struct assignmentS* a = (struct assignmentS*)malloc(sizeof(struct assignmentS));
	a->type = type;
	a->left = left;
	a->right = right;
	a->subLeft = 0;
	a->fieldName = 0;
	a->refInfo = -1;
	return a;
}

struct whileLoopS* createWhileLoop(struct exprS* cond, struct exprS* expr, struct stmtS* stmt, struct stmtList* stmts, int isDoWhile)
{
	struct whileLoopS* l = (struct whileLoopS*)malloc(sizeof(struct whileLoopS));
	l->isDoWhile = isDoWhile;
	l->cond = cond;
	if (expr == 0)
	{
		if (stmt != 0)
		{
			l->stmts = createStmtList(stmt);
		}
		else
		{
			l->stmts = stmts;
		}
	}
	else
	{
		l->stmts = createStmtList(createStmt(expr, Expr));
	}
	return l;
}

struct whileLoopS* createWhileLoop(struct exprS* cond, struct exprS* expr, int isDoWhile)
{
	return createWhileLoop(cond, expr, 0, 0, isDoWhile);
}

struct whileLoopS* createWhileLoop(struct exprS* cond, struct stmtS* stmt, int isDoWhile)
{
	return createWhileLoop(cond, 0, stmt, 0, isDoWhile);
}

struct whileLoopS* createWhileLoop(struct exprS* cond, struct stmtList* stmts, int isDoWhile)
{
	return createWhileLoop(cond, 0, 0, stmts, isDoWhile);
}

struct whileLoopS* createWhileLoop(struct exprS* cond, int isDoWhile)
{
	return createWhileLoop(cond, 0, 0, 0, isDoWhile);
}



struct forLoopS* createForLoop(char* id, struct typeS* type, struct exprS* iterableExpr, struct stmtS* stmt, struct stmtList* stmts, struct formalParamsList* idsAndTypes, bool isDestructing)
{
	struct forLoopS* l = (struct forLoopS*)malloc(sizeof(struct forLoopS));

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
	l->isDestructing = isDestructing;
	return l;
}

struct forLoopS* createForLoop(char* id, struct typeS* type, struct exprS* iterableExpr, struct stmtS* stmt)
{
	return createForLoop(id, type, iterableExpr, stmt, 0, 0, false);
}

struct forLoopS* createForLoop(char* id, struct typeS* type, struct exprS* iterableExpr, struct stmtList* stmts)
{
	return createForLoop(id, type, iterableExpr, 0, stmts, 0, false);
}

struct forLoopS* createForLoop(struct formalParamsList* idsAndTypes, struct exprS* iterableExpr, struct stmtList* stmts, bool isDestructing)
{
	return createForLoop(0, 0, iterableExpr, 0, stmts, idsAndTypes, isDestructing);
}

struct forLoopS* createForLoop(struct formalParamsList* idsAndTypes, struct exprS* iterableExpr, struct stmtS* stmt, bool isDestructing)
{
	return createForLoop(0, 0, iterableExpr, stmt, 0, idsAndTypes, isDestructing);
}

struct forLoopS* createForLoop(char* id, struct typeS* type, struct exprS* iterableExpr)
{
	return createForLoop(id, type, iterableExpr, 0, 0, 0, false);
}

struct forLoopS* createForLoop(struct formalParamsList* idsAndTypes, struct exprS* iterableExpr, bool isDestructing)
{
	return createForLoop(0, 0, iterableExpr, 0, 0, idsAndTypes, isDestructing);
}


struct ifStmtS* createIfStmt(struct exprS* cond, struct stmtList* actions, struct stmtList* altActions, struct stmtS* action, struct stmtS* altAction, struct exprS* expr)
{
	struct ifStmtS* i = (struct ifStmtS*)malloc(sizeof(struct ifStmtS));
	i->condition = cond;
	if (action == 0)
	{
		if (expr != 0)
		{
			i->actions = createStmtList(createStmt(expr, Expr));
		}
		else
		{
			i->actions = actions;
		}
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

struct ifStmtS* createIfStmt(struct exprS* cond, struct stmtS* action)
{
	return createIfStmt(cond, 0, 0, action, 0, 0);
}

struct ifStmtS* createIfStmt(struct exprS* cond, struct exprS* action)
{
	return createIfStmt(cond, 0, 0, 0, 0, action);
}

struct ifStmtS* createIfStmt(struct exprS* cond, struct stmtList* actions)
{
	return createIfStmt(cond, actions, 0, 0, 0, 0);
}

struct ifStmtS* createIfStmt(struct exprS* cond)
{
	return createIfStmt(cond, 0, 0, 0, 0, 0);
}

struct ifStmtS* createIfStmt(struct exprS* cond, struct exprS* action, struct stmtS* altAction)
{
	return createIfStmt(cond, 0, 0, 0, altAction, action);
}

struct ifStmtS* createIfStmt(struct exprS* cond, struct stmtS* action, struct stmtS* altAction)
{
	return createIfStmt(cond, 0, 0, action, altAction, 0);
}

struct ifStmtS* createIfStmt(struct exprS* cond, struct exprS* action, struct stmtList* altActions)
{
	return createIfStmt(cond, 0, altActions, 0, 0, action);
}

struct ifStmtS* createIfStmt(struct exprS* cond, struct stmtS* action, struct stmtList* altActions)
{
	return createIfStmt(cond, 0, altActions, action, 0, 0);
}

struct ifStmtS* createIfStmt(struct exprS* cond, struct stmtList* actions, struct stmtS* altAction)
{
	return createIfStmt(cond, actions, 0, 0, altAction, 0);
}

struct ifStmtS* createIfStmt(struct exprS* cond, struct stmtList* actions, struct stmtList* altActions)
{
	return createIfStmt(cond, actions, altActions, 0, 0, 0);
}

struct ifStmtS* createIfStmt(struct exprS* cond, int action, struct stmtS* altAction)
{
	return createIfStmt(cond, 0, 0, 0, altAction, 0);
}

struct ifStmtS* createIfStmt(struct exprS* cond, int action, struct stmtList* altActions)
{
	return createIfStmt(cond, 0, altActions, 0, 0, 0);
}
