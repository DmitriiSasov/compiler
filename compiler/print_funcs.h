#include "tree_nodes.h"
#include <stdio.h>

void print(struct modifiersS * m, FILE* file);
void print(struct exprS * e, FILE* file);
void print(struct factParamsList * fpl, FILE* file);
void print(struct stmtS * s, FILE* file);
void print(struct stmtList * sl, FILE* file);
void print(struct ifStmtS * is, FILE* file);
void print(struct forLoopS * fl, FILE* file);
void print(struct whileLoopS * wl, FILE* file);
void print(struct assignmentS * a, FILE* file);
void print(struct propertyS * p, FILE* file);
void print(struct varOrValDeclS * vd, FILE* file);
void print(struct typeS * t, FILE* file);
void print(struct templateTypeS * tt, FILE* file);
void print(struct typesList * tl, FILE* file);
void print(struct formalParamS * fp, FILE* file);
void print(struct formalParamsList * fpl, FILE* file);
void print(struct funcS * f, FILE* file);
void print(struct funcDeclS * fd, FILE* file);
void print(struct constructorS * c, FILE* file);
void print(struct methodS * m, FILE* file);
void print(struct initializerS * i, FILE* file);
void print(struct classS * c, FILE* file);
void print(struct classBodyElementS * cbe, FILE* file);
void print(struct classBodyS * cb, FILE* file);
void print(struct programElementS * pe, FILE* file);
void print(struct programS * p, FILE* file);
