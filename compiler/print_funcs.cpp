#include "print_funcs.h"

//Вспомогательные функции
const char * visModToStr(enum visibilityMod mod)
{
	switch(mod)
	{
		case Public:
			return "public";
		case Private:
			return "private";
		case Protected:
			return "protected";
		case Internal:
			return "internal";
		case Local:
			return "local";
		default:
			return "unknown";
	}
}



void print(struct modifiersS * m, FILE* file)
{
	fprintf(file, "Id%p [label=\"modifiers\\n", m);
	if (m->isAbstract)
	{
		fprintf(file, "abstract\\n");
	}
	
	if (m->isOverride)
	{
		fprintf(file, "override\\n");
	}

	if (m->isStatic == true)
	{
		fprintf(file, "static\\n");
	}

	if (m->vMod != Unknown)
	{		
		fprintf(file, "%s\\n", visModToStr(m->vMod));		
	}
	
	if (m->iMod != None)
	{
		if (m->iMod == Final)
		{
			fprintf(file, "final");
		}
		else if (m->iMod == Open)
		{
			fprintf(file, "open");
		}
	}


	fprintf(file, "\"]\n");
}

void print(struct exprS * e, FILE* file)
{
	
	switch (e->type)
	{
		case Identificator:
			fprintf(file, "Id%p [label=\"%s\"]\n", e, e->stringOrId);
		break;
		case This:
			fprintf(file, "Id%p [label=\"this\"]\n", e);
		break;
		case MethodCall:
			fprintf(file, "Id%p [label=\"%s( ... )\"]\n", e, e->stringOrId);
			if (e->factParams != 0)
			{
				fprintf(file, "Id%p->Id%p\n", e, e->factParams);
				print(e->factParams, file);
			}			
		break;
		case Int:
			fprintf(file, "Id%p [label=\"%d\"]\n", e, e->intV);
		break;
		case Float:
			fprintf(file, "Id%p [label=\"%f\"]\n", e, e->floatV);
		break;
		case String:
			fprintf(file, "Id%p [label=\"\\\"%s\\\"\"]\n", e, e->stringOrId);
		break;
		case Char:
			fprintf(file, "Id%p [label=\"%c\"]\n", e, e->charV);
		break;
		case Double:
			fprintf(file, "Id%p [label=\"%f\"]\n", e, e->doubleV);
		break;
		case Boolean:
			if (e->booleanV) fprintf(file, "Id%p [label=\"true\"]\n", e);
			else fprintf(file, "Id%p [label=\"false\"]\n", e);			
		break;
		case ExprInBrackets:
			fprintf(file, "Id%p [label=\"( ... )\"]\n", e);
			fprintf(file, "Id%p->Id%p\n", e, e->left);
			print(e->left, file);
		break;
		case LogicalNot:
			fprintf(file, "Id%p [label=\"!\"]\n", e);
			fprintf(file, "Id%p->Id%p\n", e, e->left);
			print(e->left, file);
		break;
		case UnaryPlusExpr:
			fprintf(file, "Id%p [label=\"+\"]\n", e);
			fprintf(file, "Id%p->Id%p\n", e, e->left);
			print(e->left, file);
		break;
		case UnaryMinusExpr:
			fprintf(file, "Id%p [label=\"-\"]\n", e);
			fprintf(file, "Id%p->Id%p\n", e, e->left);
			print(e->left, file);
		break;
		case Sum:
			fprintf(file, "Id%p [label=\"+\"]\n", e);
			fprintf(file, "Id%p->Id%p\n", e, e->left);
			print(e->left, file);
			fprintf(file, "Id%p->Id%p\n", e, e->right);
			print(e->right, file);
		break;
		case Sub:
			fprintf(file, "Id%p [label=\"-\"]\n", e);
			fprintf(file, "Id%p->Id%p\n", e, e->left);
			print(e->left, file);
			fprintf(file, "Id%p->Id%p\n", e, e->right);
			print(e->right, file);
		break;
		case Mul:
			fprintf(file, "Id%p [label=\"*\"]\n", e);
			fprintf(file, "Id%p->Id%p\n", e, e->left);
			print(e->left, file);
			fprintf(file, "Id%p->Id%p\n", e, e->right);
			print(e->right, file);
		break;
		case Div:
			fprintf(file, "Id%p [label=\"/\"]\n", e);
			fprintf(file, "Id%p->Id%p\n", e, e->left);
			print(e->left, file);
			fprintf(file, "Id%p->Id%p\n", e, e->right);
			print(e->right, file);
		break;
		case Mod:
			fprintf(file, "Id%p [label=\"%%\"]\n", e);
			fprintf(file, "Id%p->Id%p\n", e, e->left);
			print(e->left, file);
			fprintf(file, "Id%p->Id%p\n", e, e->right);
			print(e->right, file);
		break;
		case Less:
			fprintf(file, "Id%p [label=\"<\"]\n", e);
			fprintf(file, "Id%p->Id%p\n", e, e->left);
			print(e->left, file);
			fprintf(file, "Id%p->Id%p\n", e, e->right);
			print(e->right, file);
		break;
		case More:
			fprintf(file, "Id%p [label=\">\"]\n", e);
			fprintf(file, "Id%p->Id%p\n", e, e->left);
			print(e->left, file);
			fprintf(file, "Id%p->Id%p\n", e, e->right);
			print(e->right, file);
		break;
		case Or:
			fprintf(file, "Id%p [label=\"||\"]\n", e);
			fprintf(file, "Id%p->Id%p\n", e, e->left);
			print(e->left, file);
			fprintf(file, "Id%p->Id%p\n", e, e->right);
			print(e->right, file);
		break;
		case And:
			fprintf(file, "Id%p [label=\"&&\"]\n", e);
			fprintf(file, "Id%p->Id%p\n", e, e->left);
			print(e->left, file);
			fprintf(file, "Id%p->Id%p\n", e, e->right);
			print(e->right, file);
		break;
		case Eq:
			fprintf(file, "Id%p [label=\"==\"]\n", e);
			fprintf(file, "Id%p->Id%p\n", e, e->left);
			print(e->left, file);
			fprintf(file, "Id%p->Id%p\n", e, e->right);
			print(e->right, file);
		break;
		case Aeq:
			fprintf(file, "Id%p [label=\"===\"]\n", e);
			fprintf(file, "Id%p->Id%p\n", e, e->left);
			print(e->left, file);
			fprintf(file, "Id%p->Id%p\n", e, e->right);
			print(e->right, file);
		break;
		case Neq:
			fprintf(file, "Id%p [label=\"!=\"]\n", e);
			fprintf(file, "Id%p->Id%p\n", e, e->left);
			print(e->left, file);
			fprintf(file, "Id%p->Id%p\n", e, e->right);
			print(e->right, file);
		break;
		case Naeq:
			fprintf(file, "Id%p [label=\"!==\"]\n", e);
			fprintf(file, "Id%p->Id%p\n", e, e->left);
			print(e->left, file);
			fprintf(file, "Id%p->Id%p\n", e, e->right);
			print(e->right, file);
		break;
		case Loeq:
			fprintf(file, "Id%p [label=\"<=\"]\n", e);
			fprintf(file, "Id%p->Id%p\n", e, e->left);
			print(e->left, file);
			fprintf(file, "Id%p->Id%p\n", e, e->right);
			print(e->right, file);
		break;
		case Moeq:
			fprintf(file, "Id%p [label=\">=\"]\n", e);
			fprintf(file, "Id%p->Id%p\n", e, e->left);
			print(e->left, file);
			fprintf(file, "Id%p->Id%p\n", e, e->right);
			print(e->right, file);
		break;
		case FieldCalcExpr:
			fprintf(file, "Id%p [label=\".\"]\n", e);
			fprintf(file, "Id%p->Id%p\n", e, e->left);
			print(e->left, file);
			fprintf(file, "Id%p->Id%p\n", e, e->stringOrId);
			fprintf(file, "Id%p [label=\"%s\"]\n", e->stringOrId, e->stringOrId);
		break;
		case MethodCalcExpr:
			fprintf(file, "Id%p [label=\".\"]\n", e);
			fprintf(file, "Id%p->Id%p\n", e, e->left);
			print(e->left, file);
			fprintf(file, "Id%p->Id%p\n", e, e->stringOrId);
			fprintf(file, "Id%p [label=\"%s\"]\n", e->stringOrId, e->stringOrId);
			if (e->factParams != 0)
			{
				fprintf(file, "Id%p->Id%p\n", e, e->factParams);
				print(e->factParams, file);
			}
		break;
		case ArrayElementCall:
			fprintf(file, "Id%p [label=\"[ ... ]\"]\n", e);
			fprintf(file, "Id%p->Id%p\n", e, e->left);
			print(e->left, file);
			fprintf(file, "Id%p->Id%p\n", e, e->right);
			print(e->right, file);
		break;
		case ParentFieldCall:
			fprintf(file, "Id%p [label=\"super.%s\"]\n", e, e->stringOrId);
		break;
		case ParentMethodCall:
			fprintf(file, "Id%p [label=\"super.%s ( ... )\"]\n", e, e->stringOrId);
			if (e->factParams != 0)
			{
				fprintf(file, "Id%p->Id%p\n", e, e->factParams);
				print(e->factParams, file);
			}
		break;
		case Range:
			fprintf(file, "Id%p [label=\"..\"]\n", e);
			fprintf(file, "Id%p->Id%p\n", e, e->left);
			print(e->left, file);
			fprintf(file, "Id%p->Id%p\n", e, e->right);
			print(e->right, file);
		break;
	}
}

void print(struct factParamsList * fpl, FILE* file)
{
	fprintf(file, "Id%p [label=\"actual parameters\"]\n", fpl);
	struct exprS * e = fpl->first;
	do
	{
		fprintf(file, "Id%p->Id%p\n", fpl, e);
		print(e, file);
		e = e->next;
	}
	while(e != 0);
}


void print(struct stmtS * s, FILE* file)
{
	
}

void print(struct stmtList * sl, FILE* file)
{
	fprintf(file, "Id%p [label=\"statements list\"]\n", sl);
	struct stmtS * s = sl->first;
	while(s != 0)
	{
		switch(s->type)
		{
			case VarOrVal:
				fprintf(file, "Id%p->Id%p\n", sl, s->varOrVal);
				print(s->varOrVal, file);
			break;
			case Assignment:
				fprintf(file, "Id%p->Id%p\n", sl, s->assignment);
				print(s->assignment, file);
			break;
			case WhileLoop:
				fprintf(file, "Id%p->Id%p\n", sl, s->whileLoop);
				print(s->whileLoop, file);
			break;
			case ForLoop:
				fprintf(file, "Id%p->Id%p\n", sl, s->forLoop);
				print(s->forLoop, file);
			break;
			case DoWhileLoop:
				fprintf(file, "Id%p->Id%p\n", sl, s->whileLoop);
				print(s->whileLoop, file);
			break;
			case IfStmt:
				fprintf(file, "Id%p->Id%p\n", sl, s->ifStmt);
				print(s->ifStmt, file);
			break;
			case Expr:
				fprintf(file, "Id%p->Id%p\n", sl, s->expr);
				print(s->expr, file);
			break;
			case Break:
				fprintf(file, "Id%p->Id%p\n", sl, s);
				fprintf(file, "Id%p [label=\"break\"]\n", s);
			break;
			case Continue:
				fprintf(file, "Id%p->Id%p\n", sl, s);
				fprintf(file, "Id%p [label=\"continue\"]\n", s);
			break;
			case Return:
				fprintf(file, "Id%p->Id%p\n", sl, s);
				fprintf(file, "Id%p [label=\"return\"]\n", s);
			break;
			case ReturnValue:
				fprintf(file, "Id%p->Id%p\n", sl, s);
				fprintf(file, "Id%p [label=\"return\"]\n", s);
				fprintf(file, "Id%p->Id%p\n", s, s->expr);
				print(s->expr, file);
			break;
		}
		
		s = s->next;
	}	
}

void print(struct ifStmtS * is, FILE* file)
{
	fprintf(file, "Id%p [label=\"if statement\"]\n", is);
	
	fprintf(file, "Id%p->Id%p\n", is, is->condition);
	print(is->condition, file);
	
	if (is->actions != 0)
	{
		fprintf(file, "Id%p->Id%p\n", is, is->actions);
		print(is->actions, file);
	}
	
	if (is->altActions != 0)
	{
		fprintf(file, "Id%p->Id%p\n", is, is->altActions);
		print(is->altActions, file);
	}
}

void print(struct forLoopS * fl, FILE* file)
{
	fprintf(file, "Id%p [label=\"for loop\"]\n", fl);
	
	fprintf(file, "Id%p->Id%p\n", fl, fl->params);
	print(fl->params, file);
	
	fprintf(file, "Id%p->Id%p\n", fl, fl->iterableExpr);
	print(fl->iterableExpr, file);
	

	if (fl->stmts != 0)
	{
		fprintf(file, "Id%p->Id%p\n", fl, fl->stmts);
		print(fl->stmts, file);
	}
}

void print(struct whileLoopS * wl, FILE* file)
{
	if (wl->isDoWhile)
	{
		fprintf(file, "Id%p [label=\"do while loop\"]\n", wl);
	}
	else 
	{
		fprintf(file, "Id%p [label=\"while loop\"]\n", wl);	
	}
	
	fprintf(file, "Id%p->Id%p\n", wl, wl->cond);
	print(wl->cond, file);
	
	if (wl->stmts != 0)
	{
		fprintf(file, "Id%p->Id%p\n", wl, wl->stmts);
		print(wl->stmts, file);
	}
}

void print(struct assignmentS * a, FILE* file)
{
	switch(a->type)
	{
		case Assign:
			fprintf(file, "Id%p [label=\"=\"]\n", a);			
		break;
		case Asum:
			fprintf(file, "Id%p [label=\"+=\"]\n", a);
		break;
		case Asub:
			fprintf(file, "Id%p [label=\"-=\"]\n", a);
		break;
		case Adiv:
			fprintf(file, "Id%p [label=\"/=\"]\n", a);
		break;
		case Amul:
			fprintf(file, "Id%p [label=\"*=\"]\n", a);
		break;
		case Amod:
			fprintf(file, "Id%p [label=\"%=\"]\n", a);
		break;
		case AssignToField:
			fprintf(file, "Id%p [label=\".=\"]\n", a);
			break;
		case AsumToField:
			fprintf(file, "Id%p [label=\".+=\"]\n", a);
			break;
		case AsubToField:
			fprintf(file, "Id%p [label=\".-=\"]\n", a);
			break;
		case AdivToField:
			fprintf(file, "Id%p [label=\"./=\"]\n", a);
			break;
		case AmulToField:
			fprintf(file, "Id%p [label=\".*=\"]\n", a);
			break;
		case AmodToField:
			fprintf(file, "Id%p [label=\".%=\"]\n", a);
			break;
		case AssignToArray:
			fprintf(file, "Id%p [label=\"[]=\"]\n", a);
			break;
		case AsumToArray:
			fprintf(file, "Id%p [label=\"[].+=\"]\n", a);
			break;
		case AsubToArray:
			fprintf(file, "Id%p [label=\"[]-=\"]\n", a);
			break;
		case AdivToArray:
			fprintf(file, "Id%p [label=\"[]/=\"]\n", a);
			break;
		case AmulToArray:
			fprintf(file, "Id%p [label=\"[]*=\"]\n", a);
			break;
		case AmodToArray:
			fprintf(file, "Id%p [label=\"[]%=\"]\n", a);
			break;
	}
	
	fprintf(file, "Id%p->Id%p\n", a, a->left);
	print(a->left, file);
	if (a->subLeft != 0) 
	{
		fprintf(file, "Id%p->Id%p\n", a, a->subLeft);
		print(a->subLeft, file);
	}
	fprintf(file, "Id%p->Id%p\n", a, a->right);
	print(a->right, file);
}

void print(struct propertyS * p, FILE* file)
{
	fprintf(file, "Id%p [label=\"property\"]\n", p);
	if (p->mods != 0)
	{
		fprintf(file, "Id%p->Id%p\n", p, p->mods);
		print(p->mods, file);
	}
	
	fprintf(file, "Id%p->Id%p\n", p, p->varOrVal);
	print(p->varOrVal, file);
}

void print(struct varOrValDeclS * vd, FILE* file)
{
	
	if (vd->id != 0)
	{
		if (vd->isVal)
		{
			fprintf(file, "Id%p [label=\"value - %s\"]\n", vd, vd->id);
		}
		else
		{
			fprintf(file, "Id%p [label=\"variable - %s\"]\n", vd, vd->id);
		}
		
		fprintf(file, "Id%p->Id%p\n", vd, vd->type);
		print(vd->type, file);
	}
	else
	{
		if (vd->isVal)
		{
			fprintf(file, "Id%p [label=\"values\"]\n", vd);
		}
		else
		{
			fprintf(file, "Id%p [label=\"variables\"]\n", vd);
		}
		
		fprintf(file, "Id%p->Id%p\n", vd, vd->namesAndTypes);
		print(vd->namesAndTypes, file);
	}

	if (vd->initValue != 0)
	{
		fprintf(file, "Id%p->Id%p\n", vd, vd->initValue);
		print(vd->initValue, file);
	}
}

void print(struct typeS * t, FILE* file)
{
	fprintf(file, "Id%p [label=\"type", t);
	if (t->easyType != 0)
	{
		fprintf(file, " - %s\"]\n", t->easyType);
	}
	else
	{
		fprintf(file, "\"]\n");
		fprintf(file, "Id%p->Id%p\n", t, t->complexType);
		print(t->complexType, file);
	}	
}

void print(struct templateTypeS * tt, FILE* file)
{
	fprintf(file, "Id%p [label=\"template type - %s\"]\n", tt, tt->type);
	struct typeS * t = tt->list->first;
	do
	{
		fprintf(file, "Id%p->Id%p\n", tt, t);
		print(t, file);
		t = t->next;
	}
	while(t != 0);
}

void print(struct typesList * tl, FILE* file)
{
	
}

void print(struct formalParamS * fp, FILE* file)
{
	fprintf(file, "Id%p [label=\"formal param - %s\"]\n", fp, fp->name);
	fprintf(file, "Id%p->Id%p\n", fp, fp->type);
	print(fp->type, file);
}

void print(struct formalParamsList * fpl, FILE* file)
{
	fprintf(file, "Id%p [label=\"formal params\"]\n", fpl);
	
	struct formalParamS * fp = fpl->first;
	while(fp != 0)
	{
		fprintf(file, "Id%p->Id%p\n", fpl, fp);
		print(fp, file);
		fp = fp->next;
	}
	
}

void print(struct funcS * f, FILE* file)
{
	fprintf(file, "Id%p [label=\"func\"]\n", f);
	
	fprintf(file, "Id%p->Id%p\n", f, f->decl);
	print(f->decl, file);
	
	if (f->stmts != 0)
	{
		fprintf(file, "Id%p->Id%p\n", f, f->stmts);
		print(f->stmts, file);
	}
	else if (f->expr != 0)
	{
		fprintf(file, "Id%p->Id%p\n", f, f->expr);
		print(f->expr, file);
	}
}

void print(struct funcDeclS * fd, FILE* file)
{
	fprintf(file, "Id%p [label=\"declaration of func %s\"]\n", fd, fd->name);
	
	if (fd->params != 0)
	{
		fprintf(file, "Id%p->Id%p\n", fd, fd->params);
		print(fd->params, file);
	}
	
	fprintf(file, "Id%p->Id%p\n", fd, fd->type);
	print(fd->type, file);
}

void print(struct constructorS * c, FILE* file)
{
	fprintf(file, "Id%p [label=\"", c);	
	if (c->mod != Unknown)
	{
		fprintf(file, "%s ", visModToStr(c->mod));	
	}
	if (c->isStatic)
	{
		fprintf(file, "static ");
	}
	fprintf(file, "constructor");
	
	if (c->anotherConstructorId != 0)
	{
		fprintf(file, " : %s", c->anotherConstructorId);
	}
	
	fprintf(file, "\"]\n");
	
	if (c->params != 0)
	{
		fprintf(file, "Id%p->Id%p\n", c, c->params);
		print(c->params, file);
	}
	
	if (c->stmts != 0)
	{
		fprintf(file, "Id%p->Id%p\n", c, c->stmts);
		print(c->stmts, file);
	}
	
	if (c->anotherConstrParams != 0)
	{
		fprintf(file, "Id%p->Id%p\n", c, c->anotherConstrParams);
		print(c->anotherConstrParams, file);
	}
}

void print(struct methodS * m, FILE* file)
{
	fprintf(file, "Id%p [label=\"method\"]\n", m);
	if (m->mods != 0)
	{
		fprintf(file, "Id%p->Id%p\n", m, m->mods);
		print(m->mods, file);
	}
	
	if (m->func != 0)
	{
		fprintf(file, "Id%p->Id%p\n", m, m->func);
		print(m->func, file);
	}
	else
	{
		fprintf(file, "Id%p->Id%p\n", m, m->funcDecl);
		print(m->funcDecl, file);
	}
}


void print(struct initializerS * i, FILE* file)
{
	fprintf(file, "Id%p [label=\"initializer\"]\n", i);
	if (i->stmts != 0)
	{		
		fprintf(file, "Id%p->Id%p\n", i, i->stmts);
		print(i->stmts, file);
	}
}

void print(struct classS * c, FILE* file)
{
	fprintf(file, "Id%p [label=\"class\\n", c); 
	fprintf(file, "%s", c->name);
	if (c->parentClassName != 0)
	{
		fprintf(file, " : %s", c->parentClassName);
	}
	fprintf(file, "\"]\n");
	
	if (c->mods != 0)
	{
		fprintf(file, "Id%p->Id%p\n", c, c->mods); 
		print(c->mods, file);
	}
	
	struct classBodyElementS * cbe = c->body->first;
	while(cbe != 0)
	{
		fprintf(file, "Id%p->", c);
		print(cbe, file);
		cbe = cbe->next;
	}
}

void print(struct classBodyElementS * cbe, FILE* file)
{
	if (cbe->method != 0)
	{
		fprintf(file, "Id%p\n", cbe->method);
		print(cbe->method, file);
	}
	else if (cbe->property != 0)
	{
		fprintf(file, "Id%p\n", cbe->property);
		print(cbe->property, file);
	}
	else if (cbe->constructor != 0)
	{
		fprintf(file, "Id%p\n", cbe->constructor);
		print(cbe->constructor, file);
	}
	else 
	{
		fprintf(file, "Id%p\n", cbe->init);
		print(cbe->init, file);
	}
		
}


void print(struct programElementS * pe, FILE* file)
{
	if (pe->clas != 0)
	{
		fprintf(file, "Id%p\n", pe->clas);
		print(pe->clas, file);
	}
	else if (pe->method != 0)
	{
		fprintf(file, "Id%p\n", pe->method);
		print(pe->method, file);
	}
	else
	{
		fprintf(file, "Id%p\n", pe->property);
		print(pe->property, file);
	}
}

void print(struct programS * p, FILE* file)
{
	fprintf(file, "Id%p [label=\"program\"]\n", p);
	programElementS * pe = p->first;
	while(pe != 0)
	{
		fprintf(file, "Id%p->", p);
		print(pe, file);
		pe = pe->next;
	}
}

