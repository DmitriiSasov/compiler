#pragma once
#include <malloc.h>
#include "print_funcs.h"
#include <string.h>

struct programS* createProgram();
struct programS* createProgram(struct classS* clas);
struct programS* createProgram(struct methodS* meth);
struct programS* createProgram(struct propertyS* prop);
struct programS* addToProgram(struct programS* prog, struct classS* clas);
struct programS* addToProgram(struct programS* prog, struct methodS* meth);
struct programS* addToProgram(struct programS* prog, struct propertyS* prop);

struct classS* createClass(struct modifiersS* mods, char* id, char* parentId, struct classBodyS* body);
struct classS* createClass(struct modifiersS* mods, char* id, struct classBodyS* body);
struct classS* createClass(char* id, char* parentId, struct classBodyS* body);
struct classS* createClass(char* id, struct classBodyS* body);

struct classBodyS* createClassBody();
struct classBodyS* createClassBody(struct methodS* meth);
struct classBodyS* createClassBody(struct initializerS* initializer);
struct classBodyS* createClassBody(struct propertyS* prop);
struct classBodyS* createClassBody(struct constructorS* constr);
struct classBodyS* addToClassBody(struct classBodyS* body, struct methodS* meth);
struct classBodyS* addToClassBody(struct classBodyS* body, struct initializerS* initializer);
struct classBodyS* addToClassBody(struct classBodyS* body, struct propertyS* prop);
struct classBodyS* addToClassBody(struct classBodyS* body, struct constructorS* constr);

struct propertyS* createProperty(struct modifiersS* mods, struct varOrValDeclS* decl);
struct propertyS* createProperty(struct varOrValDeclS* decl);

struct methodS* createMethod(struct modifiersS* mods, struct funcDeclS* funcDecl);
struct methodS* createMethod(struct modifiersS* mods, struct funcS* func);
struct methodS* createMethod(struct funcDeclS* funcDecl);
struct methodS* createMethod(struct funcS* func);

struct initializerS* createInit(struct stmtList* stmts);

struct constructorS* createConstructor(enum visibilityMod mod, struct formalParamsList* params, struct stmtList* stmts);
struct constructorS* createConstructor(enum visibilityMod mod, struct formalParamsList* params);
struct constructorS* createConstructor(enum visibilityMod mod, struct formalParamsList* params, const char* parentOrAnotherConstr, struct factParamsList* anotherConstrParams);
struct constructorS* createConstructor(enum visibilityMod mod, struct formalParamsList* params, const char* parentOrAnotherConstr, struct factParamsList* anotherConstrParams, struct stmtList* stmts);
struct constructorS* createConstructor(struct formalParamsList* params, struct stmtList* stmts);
struct constructorS* createConstructor(struct formalParamsList* params);
struct constructorS* createConstructor(struct formalParamsList* params, const char* parentOrAnotherConstr, struct factParamsList* anotherConstrParams);
struct constructorS* createConstructor(struct formalParamsList* params, const char* parentOrAnotherConstr, struct factParamsList* anotherConstrParams, struct stmtList* stmts);

struct formalParamsList* createFormalParamsList();
struct formalParamsList* createFormalParamsList(char* id, struct typeS* type);
struct formalParamsList* addToFormalParamsList(struct formalParamsList* list, char* id, struct typeS* type);

struct modifiersS* createModifiers(int isAbstruct, int isOverride, enum visibilityMod vMod, enum inheritanceMod iMod);

struct funcS* createFunc(struct funcDeclS* decl, struct stmtList* stmts);
struct funcS* createFunc(struct funcDeclS* decl, struct exprS* expr);

struct funcDeclS* createFuncDecl(char* id, struct formalParamsList* params, struct typeS* type);

struct stmtList* createStmtList();
struct stmtList* createStmtList(struct stmtS* stmt);
struct stmtList* addToStmtList(struct stmtList* list, struct stmtS* stmt);

struct varOrValDeclS* createVarOrValDecl(char* id, struct typeS* type, int isVal);
struct varOrValDeclS* createVarOrValDecl(char* id, struct typeS* type, struct exprS* initValue, int isVal);
struct varOrValDeclS* createVarOrValDecl(struct formalParamsList* idsAndTypes, struct exprS* initValue, int isVal);

struct typeS* createType(char* id);
struct typeS* createType(struct templateTypeS* type);

struct templateTypeS* createTemplateType(char* id, struct typesList* templateTypes);

struct typesList* createTypesList(char* id);
struct typesList* createTypesList(struct templateTypeS* tt);
struct typesList* addToTypesList(struct typesList* list, char* id);
struct typesList* addToTypesList(struct typesList* list, struct templateTypeS* tt);

struct stmtS* createStmt(struct varOrValDeclS* v, enum stmtType type);
struct stmtS* createStmt(struct assignmentS* assign, enum stmtType type);
struct stmtS* createStmt(struct whileLoopS* loop, enum stmtType type);
struct stmtS* createStmt(struct forLoopS* loop, enum stmtType type);
struct stmtS* createStmt(struct ifStmtS* ifStmt, enum stmtType type);
struct stmtS* createStmt(struct exprS* expr, enum stmtType type);
struct stmtS* createStmt(enum stmtType type);

struct exprS* createExpr(char* idOrString, enum exprType type);
struct exprS* createExpr(int val, enum exprType type);
struct exprS* createExpr(char* idOrString, struct factParamsList* params, enum exprType type);
struct exprS* createExpr(float val, enum exprType type);
struct exprS* createExpr(double val, enum exprType type);
struct exprS* createExpr(char val, enum exprType type);
struct exprS* createExpr(bool val, enum exprType type);
struct exprS* createExpr(struct exprS* expr, enum exprType type);
struct exprS* createExpr(struct exprS* left, struct exprS* right, enum exprType type);
struct exprS* createExpr(struct exprS* left, char* right, enum exprType type);
struct exprS* createExpr(struct exprS* left, char* right, struct factParamsList* params, enum exprType type);

struct factParamsList* createFactParamsList();
struct factParamsList* createFactParamsList(struct exprS* expr);
struct factParamsList* addToFactParamsList(struct factParamsList* list, struct exprS* expr);

struct assignmentS* createAssignment(struct exprS* left, struct exprS* right, enum assignmentType type);

struct whileLoopS* createWhileLoop(struct exprS* cond, struct stmtS* stmt, int isDoWhile);
struct whileLoopS* createWhileLoop(struct exprS* cond, struct stmtList* stmts, int isDoWhile);
struct whileLoopS* createWhileLoop(struct exprS* cond, int isDoWhile);

struct forLoopS* createForLoop(char* id, struct typeS* type, struct exprS* iterableExpr, struct stmtS* stmt);
struct forLoopS* createForLoop(char* id, struct typeS* type, struct exprS* iterableExpr, struct stmtList* stmts);
struct forLoopS* createForLoop(struct formalParamsList* idsAndTypes, struct exprS* iterableExpr, struct stmtList* stmts);
struct forLoopS* createForLoop(struct formalParamsList* idsAndTypes, struct exprS* iterableExpr, struct stmtS* stmt);
struct forLoopS* createForLoop(char* id, struct typeS* type, struct exprS* iterableExpr);
struct forLoopS* createForLoop(struct formalParamsList* idsAndTypes, struct exprS* iterableExpr);

struct ifStmtS* createIfStmt(struct exprS* cond, struct stmtS* action);
struct ifStmtS* createIfStmt(struct exprS* cond, struct stmtList* actions);
struct ifStmtS* createIfStmt(struct exprS* cond);
struct ifStmtS* createIfStmt(struct exprS* cond, struct stmtS* action, struct stmtS* altAction);
struct ifStmtS* createIfStmt(struct exprS* cond, struct stmtS* action, struct stmtList* altActions);
struct ifStmtS* createIfStmt(struct exprS* cond, struct stmtList* actions, struct stmtS* altAction);
struct ifStmtS* createIfStmt(struct exprS* cond, struct stmtList* actions, struct stmtList* altActions);
struct ifStmtS* createIfStmt(struct exprS* cond, int action, struct stmtS* altAction);
struct ifStmtS* createIfStmt(struct exprS* cond, int action, struct stmtList* altActions);