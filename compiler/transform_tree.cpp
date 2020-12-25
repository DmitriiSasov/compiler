#include "transform_root.h"

void addBaseClassAsParent(programS* program)
{
	for (auto pe = program->first; pe != 0; pe = pe->next)
	{
		if (pe->clas != 0 && pe->clas->parentClassName == 0 && strcmp(pe->clas->name, "Main$") != 0)
		{
			char* tmp = new char[strlen("MyLib/Any") + 1];
			strcpy(tmp, "MyLib/Any");
			pe->clas->parentClassName = tmp;
		}
	}
}

void transformAssignmentWithFieldAndArrays(stmtList* stmts);

void templateTypeFree(templateTypeS* type);

void transformTypes(stmtList* stmts, list<string>& classesNames);

void freeMem(programElementS* firstElement, programElementS* stopElement)
{
	programElementS* pe = firstElement;
	while (pe != 0 && pe != stopElement)
	{
		programElementS* tmp = pe->next;
		free(pe);
		pe = tmp;
	}
}

programS* removeRedundantNodes(programS* program)
{
	if (program->first == 0)
	{
		return program;
	}

	list<classS*> classes;

	//Ќайти первый pe класс
	programElementS* pe = program->first;
	while (pe != 0) 
	{
		if (pe->clas != 0)	classes.push_back(pe->clas);
		pe = pe->next;
	}

	freeMem(program->first, 0);

	free(program);
	
	program = createProgram();
	for (classS* i : classes)
	{
		program = addToProgram(program, i);
	}

	return program;
}

programS* transformProgramToClass(programS* programTreeRoot)
{
	classS* newClass = new classS();
	newClass->name = new char[7]();
	strcpy(newClass->name, "Main$");
	newClass->mods = createModifiers(0, 0, Public, None);
	newClass->parentClassName = 0;
	newClass->body = createClassBody();
	programElementS* pe = programTreeRoot->first;
	
	bool isCorrectTransformation = true;

	//ƒобавили все глобальные пол€ и методы в новый класс
	while (pe != 0)
	{
		if (pe->method != 0) 
		{
			if (pe->method->mods != 0)
			{
				if (pe->method->mods->isOverride)
				{
					printf("Error! Top level function \"%s\" cannot be overriden",
						pe->method->funcDecl->name);
					isCorrectTransformation = false;
				}

				pe->method->mods->isStatic = true;
			}
			else
			{
				pe->method->mods = createModifiers(0, 0, Public, Final);
				pe->method->mods->isStatic = true;
			}
			newClass->body = addToClassBody(newClass->body, pe->method);
		}
		else if (pe->property != 0)
		{
			if (pe->property->varOrVal->isVal)
			{
				printf("EXCEPTION!Unsupported static constant value \"%s\"", pe->property->varOrVal->id);
				isCorrectTransformation = false;
			}
			if (pe->property->mods != 0)	pe->property->mods->isStatic = true;
			else
			{
				pe->property->mods = createModifiers(0, 0, Public, None);
				pe->property->mods->isStatic = true;
			}
			newClass->body = addToClassBody(newClass->body, pe->property);
		}
			
		pe = pe->next;
	}
	//”брали из дерева лишние узлы
	programTreeRoot = removeRedundantNodes(programTreeRoot);
	if (newClass->body->first != 0)
	{
		//ƒобавили новый класс
		if (programTreeRoot->first == 0)	programTreeRoot = createProgram(newClass);
		else	programTreeRoot = addToProgram(programTreeRoot, newClass);
	}	

	if (!isCorrectTransformation)
	{
		throw exception("Exception! Error in transformation of global function and variables!");
	}

	return programTreeRoot;
}

void transformAssignmentWithFieldAndArrays(assignmentS* assign)
{
	if (assign == 0)
		return;

	
	if (assign->left->type == FieldCalcExpr || assign->left->type == ParentFieldCall)
	{

		assign->fieldName = assign->left->stringOrId;
		
		
		if (assign->left->type == ParentFieldCall)
		{
			
			assign->left->stringOrId = new char[6];
			strcpy(assign->left->stringOrId, "super");
			assign->left->type = Identificator;
		}
		else if (assign->left->left->type == This)
		{
			assign->left->stringOrId = new char[5];
			strcpy(assign->left->stringOrId, "this");
			assign->left->type = Identificator;
		}
		else
		{
			assign->left->type = assign->left->left->type;
			assign->left = assign->left->left;
		}
		
		switch (assign->type)
		{
		case Assign:
			assign->type = AssignToField;
			break;
		case Asum:
			assign->type = AsumToField;
			break;
		case Asub:
			assign->type = AsubToField;
			break;
		case Adiv:
			assign->type = AdivToField;
			break;
		case Amul:
			assign->type = AmulToField;
			break;
		case Amod:
			assign->type = AmodToField;
			break;
		}
	}
	else if (assign->left->type == ArrayElementCall)
	{
		assign->subLeft = assign->left->right;
		assign->subLeft->type = assign->left->right->type;
		assign->left->type = assign->left->left->type;
		assign->left = assign->left->left;
		
		switch (assign->type)
		{
		case Assign:
			assign->type = AssignToArray;
			break;
		case Asum:
			assign->type = AsumToArray;
			break;
		case Asub:
			assign->type = AsubToArray;
			break;
		case Adiv:
			assign->type = AdivToArray;
			break;
		case Amul:
			assign->type = AmulToArray;
			break;
		case Amod:
			assign->type = AmodToArray;
			break;
		}
	}
}

void transformAssignmentWithFieldAndArrays(stmtS* stmt) {
	if (stmt == 0)
		return;

	switch (stmt->type) {
	case Assignment:
		transformAssignmentWithFieldAndArrays(stmt->assignment);
		break;
	case WhileLoop:
		if (stmt->whileLoop->stmts != 0)
			transformAssignmentWithFieldAndArrays(stmt->whileLoop->stmts);			
		break;
	case ForLoop:
		if (stmt->forLoop->stmts != 0)
			transformAssignmentWithFieldAndArrays(stmt->forLoop->stmts);		
		break;
	case DoWhileLoop:
		if (stmt->whileLoop->stmts != 0)
			transformAssignmentWithFieldAndArrays(stmt->whileLoop->stmts);		
		break;
	case IfStmt:
		if (stmt->ifStmt->actions != 0)
			transformAssignmentWithFieldAndArrays(stmt->ifStmt->actions);
		if (stmt->ifStmt->altActions != 0)
			transformAssignmentWithFieldAndArrays(stmt->ifStmt->altActions);
		break;
	}
}

void transformAssignmentWithFieldAndArrays(stmtList* stmts) 
{
	if (stmts == 0)
		return;

	stmtS* stmt = stmts->first;
	while (stmt != 0)
	{
		transformAssignmentWithFieldAndArrays(stmt);
		stmt = stmt->next;
	}
}

void transformAssignmentWithFieldAndArrays(methodS* meth)
{
	if (meth->funcDecl != 0)
		return;
	stmtList* stmts = meth->func->stmts;
	transformAssignmentWithFieldAndArrays(meth->func->stmts);
}

void transformAssignmentWithFieldAndArrays(classS* cl)
{
	if (cl->body == 0)
	{
		return;
	}
	classBodyElementS* cbe = cl->body->first;
	while (cbe != 0)
	{
		if (cbe->method != 0) transformAssignmentWithFieldAndArrays(cbe->method);
		cbe = cbe->next;
	}
}

void transformAssignmentWithFieldAndArrays(programS* program)
{
	if (program == 0)
	{
		return;
	}
	programElementS* pe = program->first;
	while (pe != 0) 
	{
		if (pe->clas != 0) transformAssignmentWithFieldAndArrays(pe->clas);
		pe = pe->next;
	}
}

void transformInit(classS* program)
{
	list<initializerS*> inits;
	list<constructorS*> constrs;
	classBodyElementS* cbe = program->body->first;
	while (cbe != 0)
	{
		if (cbe->init != 0)	inits.push_back(cbe->init);
		else if (cbe->constructor) constrs.push_back(cbe->constructor);
		cbe = cbe->next;
	}

	//≈сли конструкторов нет, то создаем конструктор по умолчанию
	if (constrs.size() == 0 && inits.size() > 0)
	{
		auto defaultConstr = createConstructor(0);
		program->body = addToClassBody(program->body, defaultConstr);
		constrs.push_back(defaultConstr);
	}

	for (auto constr : constrs) 
	{
		for (auto init : inits)
		{
			if (init->stmts != 0)
			{
				stmtS* stmt = init->stmts->first;
				while (stmt != 0)
				{
					if (constr->stmts != 0)
					{
						constr->stmts = addToStmtList(constr->stmts, stmt);
					}
					else 
					{
						constr->stmts = createStmtList(stmt);
					}
					stmt = stmt->next;
				}				
			}			
		}
	}
	
	//”брать inits
	
	classBodyS* newBody = createClassBody();

	cbe = program->body->first;
	while (cbe != 0)
	{
		if (cbe->init == 0)  newBody = addToClassBody(newBody, cbe);
		cbe = cbe->next;
	}
	
	free(program->body);
	program->body = newBody;

}

void transformInit(programS* program)
{
	
	programElementS* pe = program->first;
	while (pe != 0) 
	{
		if (pe->clas != 0) transformInit(pe->clas);
		pe = pe->next;
	}
}


bool checkConstructorMod(const constructorS* const constr)
{
	if (constr->mod != Public)
	{
		printf("Error! Unsupported NOT PUBLIC contructors");
		return false;
	}
	return true;
}

bool complementModifiers(methodS* meth)
{
	bool res = true;

	if (meth->funcDecl != 0)
	{
		printf("Error! Unsupported ABSTRACT method with name \"%s\"", meth->funcDecl->name);
		res = false;
	}

	if (meth->mods != 0)
	{
		if (meth->mods->iMod == None) meth->mods->iMod = Final;
		if (meth->mods->vMod == Unknown) meth->mods->vMod = Public;
		else if (meth->mods->vMod == Internal)
		{
			printf("Error! Unsupported INTERNAL visibility mod with method \"%s\"", meth->funcDecl->name);
			res = false;
		}
		if (meth->mods->isAbstract == true)
		{
			printf("Error! Unsupported ABSTRACT mod with method \"%s\"", meth->funcDecl->name);
			res = false;
		}

		if (meth->mods->isOverride == true && meth->mods->vMod == Private)
		{
			printf("Error! Method with name \"%s\"\" cannot be OVERRIDE and PRIVATE", meth->funcDecl->name);
			res = false;
		}
	}
	else
	{
		meth->mods = createModifiers(0, 0, Public, Final);
	}

	return res;
}

bool complementModifiers(propertyS* prop)
{
	bool res = true;

	if (prop->mods != 0)
	{
		if (prop->mods->iMod == Open || prop->mods->iMod == Final)
		{
			printf("Error! Inheritance mods of properties are not supported. Property \"%s\" \
				has inheritance mod", prop->varOrVal->id);
			res = false;
		}

		if (prop->mods->vMod == Unknown) prop->mods->vMod = Public;
		else if (prop->mods->vMod == Internal)
		{
			printf("Error! Unsupported INTERNAL visibility mod with property \"%s\"", 
				prop->varOrVal->id);
			res = false;
		}
		if (prop->mods->isAbstract == true)
		{
			printf("Error! Unsupported ABSTRACT mod with property \"%s\"",
				prop->varOrVal->id);
			res = false;
		}
		if (prop->mods->isOverride == true)
		{
			printf("Error! Unsupported OVERRIDE mod with property \"%s\"",
				prop->varOrVal->id);
			res = false;
		}
	}
	else
	{
		prop->mods = createModifiers(0, 0, Public, None);
	}	

	return res;
}

bool complementModifiers(classS* cl)
{
	if (cl == 0)
		return true;
	
	bool res = true;
	
	for (classBodyElementS* cbe = cl->body->first; cbe != 0; cbe = cbe->next) 
	{
		if (cbe->property)
		{
			res = res && complementModifiers(cbe->property);
		}
		else if (cbe->method)
		{
			res = res && complementModifiers(cbe->method);
		}
		else if (cbe->constructor)
		{
			res = res && checkConstructorMod(cbe->constructor);
		}
	}

	if (res == false)
	{
		if (strcmp(cl->name, "Main$") == 0)
			printf("Errors in class - %s", cl->name);
		else
			printf("Errors in global scope");
		return res;
	}
	
	return res;
}

void complementModifiers(programS* program)
{
	if (program == 0)
		return ;

	bool res = true;

	for (programElementS* pe = program->first; pe != 0; pe = pe->next) 
	{
		if (pe->clas != 0)
		{
			res = res && complementModifiers(pe->clas);
			if (pe->clas->mods != 0)
			{
				if (pe->clas->mods->iMod == None) pe->clas->mods->iMod = Final;
				if (pe->clas->mods->vMod == Unknown) pe->clas->mods->vMod = Public;
				else if (pe->clas->mods->vMod == Internal) 
				{
					printf("Error! Unsupported INTERNAL visibility mod with class \"%s\"", pe->clas->name);
					res = false;
				}
				else if (pe->clas->mods->vMod == Protected || pe->clas->mods->vMod == Private)
				{
					printf("Error! Invalid visibility mod with no inner class \"%s\"", pe->clas->name);
					res = false;
				}
				if (pe->clas->mods->isAbstract == true) 
				{
					printf("Error! Unsupported ABSTRACT mod with class \"%s\"", pe->clas->name);
					res = false;
				}
				if (pe->clas->mods->isOverride == true)
				{
					printf("Error! Invalid OVERRIDE mod with class \"%s\"", pe->clas->name);
					res = false;
				}
			}
			else
			{
				pe->clas->mods = createModifiers(0, 0, Public, Final);
			}
		}
	}

	if (res == false)
		throw exception("Exception! Error in modifiers complementing");
}

//ѕровер€ем, что у родительского метода менее строгий уровень доступа
bool isParentMethodVisModWeaken(visibilityMod vMod, const programS* const program, 
	const string& methodSign, const string& parentClassName)
{
	if (&parentClassName == NULL || parentClassName == "")
		return false;

	if (parentClassName == "MyLib/Any")
	{
		if ((methodSign == "equals(MyLib/Any)" || methodSign == "toString()") && vMod != Public)
		{
			return false;
		}
	}
	else
	{
		for (auto pe = program->first; pe != 0; pe = pe->next)
		{
			if (pe->clas != 0 && parentClassName == pe->clas->name)
			{
				if (pe->clas->body == 0)
				{
					return isParentMethodVisModWeaken(vMod, program, methodSign, pe->clas->parentClassName);
				}
				else
				{
					for (auto cbe = pe->clas->body->first; cbe != 0; cbe = cbe->next)
					{
						if (cbe->method != 0 && createMethodSignature(cbe->method) == methodSign
							&& cbe->method->mods->vMod < vMod)
							return true;
					}
				}
			}
		}
	}
}

//ѕровер€ем понижение уровн€ доступа дл€ методов класса, которые переопредел€ютс€
void checkMethodsVilibilityLevelIncreasing(const programS* const program)
{
	for (auto pe = program->first; pe != 0; pe = pe->next)
	{
		if (pe->clas != 0 && pe->clas->body != 0 && strcmp(pe->clas->name, "Main$") != 0)
		{
			for (auto cbe = pe->clas->body->first; cbe != 0; cbe = cbe->next)
			{
				if (cbe->method != 0 && cbe->method->mods->isOverride 
					&& isParentMethodVisModWeaken(cbe->method->mods->vMod, program, 
						createMethodSignature(cbe->method), pe->clas->parentClassName))
				{
					char message[200] = "EXCEPTION! Method \"";
					exception e(strcat(strcat(strcat(message, pe->clas->name), "\" has stricter visibility modifier than parent's method"),
						pe->clas->parentClassName));
					throw e;
				}
			}
		}
	}
}

void checkPropsNames(classS* clas, const  programS* const program)
{
	if (clas == 0 || clas->body == 0)
		return;

	list<string> propertyNames;
	for (auto cbe = clas->body->first; cbe != 0; cbe = cbe->next)
	{
		if (cbe->property != 0)
		{
			if (find(propertyNames.begin(), propertyNames.end(), cbe->property->varOrVal->id) 
				!= propertyNames.end())
			{
				char message[200] = "EXCEPTION! property with name \"";
				exception e((strcat(strcat(message, cbe->property->varOrVal->id), "\" is already declared")));
				throw e;
			}
			
			if (clas->parentClassName != 0 && getPropertyType(cbe->property->varOrVal->id, 
				program, clas->parentClassName) != "")
			{
				char message[200] = "EXCEPTION! Redefine of parent property \"";
				exception e((strcat(strcat(message, cbe->property->varOrVal->id), "\"")));
				throw e;
			}
			
			propertyNames.push_back(cbe->property->varOrVal->id);
		}
	}
}


bool isChildType(const string& potentialChildType, const string& potentialParentType,
	const programS* const program)
{
	if (potentialChildType == "" || potentialParentType == "")
		return false;

	//≈сли в качестве дочернего класса указан базовый класс
	if (potentialChildType == "MyLib/Any")
		return false;

	//≈сли в качестве родительского типа выступает Any, т.е. базовый класс
	if (potentialParentType == "MyLib/Any")
		return true;

	//≈сли родителем €вл€етс€ стандартный тип (они все final) кроме Any
	if (isMyStandartClass(potentialParentType))
		return false;

	//≈сли родителем €вл€етс€ массив
	if (potentialParentType.find("[]") != -1)
		return false;

	//≈сли дочений класс - стандартный тип и родитель не Any
	if (isMyStandartClass(potentialChildType))
		return false;

	//≈сли дочерний класс - массив и родитель не Any
	if (potentialChildType.find("[]") != -1)
		return false;

	//≈сли оба класса - пользовательские, то провер€ем их
	if (isUserClass(potentialChildType.c_str(), program))
	{
		return isParentClass(potentialParentType, potentialChildType, program);
	}
}


void checkMethods(classS* clas, programS* program)
{
	if (clas == 0 || clas->body == 0)
		return;

	list<string> methodSigns;
	for (auto cbe = clas->body->first; cbe != 0; cbe = cbe->next)
	{
		if (cbe->method != 0)
		{
			string methodSign = createMethodSignature(cbe->method);
			if (find(methodSigns.begin(), methodSigns.end(), methodSign)
				!= methodSigns.end())
			{
				char message[200] = "EXCEPTION! Method with name \"";
				exception e((strcat(strcat(message, cbe->method->func->delc->name), "\" is already declared")));
				throw e;
			}

			//≈сли это не созданный статический класс
			if (strcmp(clas->name, "Main$") != 0)
			{
				string retValue = getMethodType(methodSign, program, clas->parentClassName);
				if (clas->parentClassName != 0 && retValue != "")
				{
					if (retValue != cbe->method->func->delc->type->easyType && 
						!isChildType(cbe->method->func->delc->type->easyType, retValue, program))
					{
						char message[200] = "EXCEPTION! Return value of method \"";
						exception e(strcat(strcat(strcat(message, cbe->method->func->delc->name), 
							"\" is not a child of type - "), retValue.c_str()));
						throw e;
					}
					if (!cbe->method->mods->isOverride)
					{
						char message[200] = "EXCEPTION! Method with name \"";
						exception e((strcat(strcat(message, cbe->method->func->delc->name), "\" hasn't modifier OVERRIDE")));
						throw e;
					}
				}
				else if (methodSign == "equals(MyLib/Any|)")
				{
					if (!cbe->method->mods->isOverride)
					{
						char message[200] = "EXCEPTION! Method with name \"";
						exception e((strcat(strcat(message, cbe->method->func->delc->name), "\" hasn't modifier OVERRIDE")));
						throw e;
					}
					else if (strcmp(cbe->method->func->delc->type->easyType, "MyLib/Boolean") != 0)
					{
						char message[200] = "EXCEPTION! Method \"equals\" return value is not a child of Boolean in class \"";
						exception e(strcat(strcat(message, clas->name), "\""));
						throw e;
					}
					
				}
				else if (methodSign == "toString()" )
				{
					if (!cbe->method->mods->isOverride)
					{
						char message[200] = "EXCEPTION! Method with name \"";
						exception e((strcat(strcat(message, cbe->method->func->delc->name), "\" hasn't modifier OVERRIDE")));
						throw e;
					}
					else if (strcmp(cbe->method->func->delc->type->easyType, "MyLib/String") != 0)
					{
						char message[200] = "EXCEPTION! Method \"toString\" return value is not a child of String in class \"";
						exception e(strcat(strcat(message, clas->name), "\""));
						throw e;
					}
					else
					{
						char* tmp = new char[strlen("toMyString") + 1];
						strcpy(tmp, "toMyString");
						cbe->method->func->delc->name = tmp;
					}					
				}
			}
			
		}
	}
}

void checkMethodsAndPropsNames(programS* program)
{
	for (auto pe = program->first; pe != 0; pe = pe->next)
	{
		if (pe->clas != 0)
		{
			checkMethods(pe->clas, program);
			checkPropsNames(pe->clas, program);
		}
	}
}


/*ѕровер€ем, нет ли переобъ€влени€ пользовательских классов*/
void checkClassesNames(const programS* const program)
{
	if (program == 0)
		return;

	list<string> classNames;
	
	for (programElementS* pe = program->first; pe != 0; pe = pe->next) 
	{
		if (pe->clas != 0)
		{
			auto res = find(classNames.begin(), classNames.end(), string(pe->clas->name));
			if (res != classNames.end())
			{
				char message[200] = "EXCEPTION! class with name \"";
				exception e((strcat(strcat(message, pe->clas->name), "\" is already declared")));
				throw e;
			}
			else	classNames.push_back(string(pe->clas->name));
		}
	}
}

void transformFuncsLikeExpr(methodS* meth)
{
	if (meth->func != 0 && meth->func->expr != 0)
	{
		meth->func->stmts = createStmtList(createStmt(meth->func->expr, ReturnValue));
		meth->func->expr = 0;
	}
}

void transformFuncsLikeExpr(classS* cl)
{
	if (cl->body == 0)
	{
		return;
	}
	classBodyElementS* cbe = cl->body->first;
	while (cbe != 0)
	{
		if (cbe->method != 0) transformFuncsLikeExpr(cbe->method);
		cbe = cbe->next;
	}
}

void transformFuncsLikeExpr(programS* program)
{
	if (program == 0)
		return;

	programElementS* pe = program->first;
	while (pe != 0)
	{
		if (pe->clas != 0) transformFuncsLikeExpr(pe->clas);
		pe = pe->next;
	}
}

void checkStaticFuncsLikeConstructors(const programS* const program)
{
	classS* mainClass = 0;
	for (auto pe = program->first; pe != 0 && mainClass == 0; pe = pe->next)
	{
		if (pe->clas != 0 && strcmp(pe->clas->name, "Main$") == 0) mainClass = pe->clas;
	}

	if (mainClass != 0 && mainClass->body != 0)
	{
		for (auto cbe = mainClass->body->first; cbe != 0; cbe = cbe->next)
		{
			if (cbe->method != 0 && isUserClass(cbe->method->func->delc->name, program) 
				&& cbe->method->func->delc->params == 0)
			{
				char message[200] = "EXCEPTION! Global function overlap constructor of class \"";
				exception e((strcat(strcat(message, cbe->method->func->delc->name), "\"")));
				throw e;
			}
		}
	}
	
}

void checkConstructorsAndInits(const classS* const cl)
{
	if (cl->body == 0)
	{
		return;
	}
	
	classBodyElementS* cbe = cl->body->first;
	int publicConstrCount = 0;
	while (cbe != 0)
	{
		//«апрещены все конструкторы кроме public constructor() 
		if (cbe->constructor != 0 && (cbe->constructor->anotherConstrParams != 0
			|| cbe->constructor->anotherConstructorId != 0 || cbe->constructor->params != 0
			|| cbe->constructor->stmts != 0 || cbe->constructor->mod != Public))
		{
			char message[200] = "EXCEPTION! Unsupported not public not default constructor  in class \"";
			exception e((strcat(strcat(message, cl->name), "\"")));
			throw e;
		}
		else publicConstrCount++;

		if (cbe->init != 0)
		{
			char message[200] = "EXCEPTION! Unsupported initializator in class \"";
			exception e((strcat(strcat(message, cl->name), "\"")));
			throw e;
		}
		cbe = cbe->next;
	}

	if (publicConstrCount > 1)
	{
		char message[200] = "EXCEPTION! Redefine of default contructor in class \"";
		exception e((strcat(strcat(message, cl->name), "\"")));
		throw e;
	}
}

void checkConstructorsAndInits(const programS* const program)
{
	if (program == 0)
		return;

	programElementS* pe = program->first;
	while (pe != 0)
	{
		if (pe->clas != 0) checkConstructorsAndInits(pe->clas);
		pe = pe->next;
	}

	checkStaticFuncsLikeConstructors(program);
}

void checkPropertyInitialization(const classS* const cl)
{
	if (cl->body == 0)
	{
		return;
	}

	classBodyElementS* cbe = cl->body->first;
	while (cbe != 0)
	{
		if (cbe->property != 0)
		{
			if (cbe->property->varOrVal->initValue != 0)
			{
				char message[200] = "EXCEPTION! Unsupported intialization of property \"";

				exception e(strcat(strcat(strcat(message, cbe->property->varOrVal->id), "\"  in class - "), cl->name));
				throw e;
			}			
		}
		cbe = cbe->next;
	}
}

void checkPropertyInitialization(const programS* const program)
{
	if (program == 0)
		return;

	programElementS* pe = program->first;
	while (pe != 0)
	{
		if (pe->clas != 0) checkPropertyInitialization(pe->clas);
		pe = pe->next;
	}

}

void transformDestructAssign(methodS* meth)
{
	if (meth->func == 0 || meth->func->stmts == 0)
	{
		return;
	}
	stmtS* stmt = meth->func->stmts->first;
	while (stmt != 0)
	{
		stmtS* currentStmt = 0;
		if (stmt->type == VarOrVal && stmt->varOrVal->namesAndTypes != 0)
		{
			stmtS* afterMultiDeclStmt = stmt->next;
			exprS* startInitValue = stmt->varOrVal->initValue;
			
			formalParamS* fp = stmt->varOrVal->namesAndTypes->first;
			stmt->varOrVal->id = fp->name;
			stmt->varOrVal->type= fp->type;
			char* methodName = new char[13];
			strcpy(methodName, "component1");
			exprS* newInitValue = createExpr(startInitValue, methodName, 0, MethodCalcExpr);
			stmt->varOrVal->initValue = newInitValue;
			
			int fpCount = 2;
			currentStmt = stmt;
			for (fp = fp->next; fp != 0; fp = fp->next)
			{
				char componentNum[3] = "";
				methodName = new char[13];
				strcat(strcpy(methodName, "component"), _itoa(fpCount, componentNum, 10));
				newInitValue = createExpr(startInitValue, methodName, 0, MethodCalcExpr);
				stmtS* newStmt = createStmt(createVarOrValDecl(fp->name, fp->type, newInitValue, stmt->varOrVal->isVal), VarOrVal);
				currentStmt->next = newStmt;
				currentStmt = currentStmt->next;
				++fpCount;
				
				if (fpCount > 100)
				{
					char message[200] = "EXCEPTION! Unsupported call of componentN in method \"";

					exception e(strcat(strcat(message, meth->func->delc->name), "\""));
					throw e;
				}
			}
			
			if (afterMultiDeclStmt == 0) meth->func->stmts->last = currentStmt;
			free(stmt->varOrVal->namesAndTypes);
			stmt->varOrVal->namesAndTypes = 0;
			currentStmt->next = afterMultiDeclStmt;
		}
		else if (stmt->forLoop != 0 && stmt->forLoop->isDestructing)
		{
			char message[200] = "EXCEPTION! Unsupported destruction in for loop in method \"";

			exception e(strcat(strcat(message, meth->func->delc->name), "\""));
			throw e;
		}


		if (currentStmt != 0)	stmt = currentStmt->next;
		else					stmt = stmt->next;
	}
}

void transformDestructAssign(classS* cl)
{
	if (cl->body == 0)
	{
		return;
	}
	classBodyElementS* cbe = cl->body->first;
	while (cbe != 0)
	{
		if (cbe->method != 0) transformDestructAssign(cbe->method);
		cbe = cbe->next;
	}
}

void transformDestructAssign(programS* program)
{
	if (program == 0)
		return;

	programElementS* pe = program->first;
	while (pe != 0)
	{
		if (pe->clas != 0) transformDestructAssign(pe->clas);
		pe = pe->next;
	}
}

void typeFree(typesList* type)
{
	for (typeS* t = type->first; t != 0;)
	{
		if (t->easyType != 0) return;
		else
		{
			templateTypeFree(t->complexType);
			typeS* next = t->next;
			free(t);
			t = next;
		}
	}
}

void templateTypeFree(templateTypeS* type)
{
	free(type->type);
	typeFree(type->list);
	free(type->list);
}

bool isStandartKotlinType(const char* typeName)
{
	if (strcmp(typeName, "Int") == 0 || strcmp(typeName, "Float") == 0
		|| strcmp(typeName, "Double") == 0 || strcmp(typeName, "String") == 0
		|| strcmp(typeName, "Char") == 0 || strcmp(typeName, "Unit") == 0
		|| strcmp(typeName, "Boolean") == 0 || strcmp(typeName, "Any") == 0)
	{
		return true;
	}
	return false;
}

bool existsEasyType(char* typeName, const list<string>& classesNames)
{
	return isStandartKotlinType(typeName) || isUserClass(typeName, classesNames) 
		|| isMyStandartClass(typeName);
}

char * collectArrayInfo(templateTypeS* type, const list<string>& classesNames, int& nestingLevel)
{
	if (type == 0)
		return 0;

	if (strcmp(type->type, "Array") != 0)
	{
		char message[200] = "EXCEPTION! Unsupported template type \"";
		exception e(strcat(strcat(message, type->type), "\""));
		throw e;
	}
	if (type->list->first != type->list->last)
	{
		char message[200] = "EXCEPTION! More than 1 array type \"";
		exception e(message);
		throw e;
	}
	if (type->list->first->easyType != 0)
	{
		char* typeOfArray;
		if (isStandartKotlinType(type->list->first->easyType)
			&& !isUserClass(type->list->first->easyType, classesNames))
		{
			typeOfArray = transformStdKotlinTypeToMyKotlinTypes(type->list->first->easyType);
		}
		else if (isUserClass(type->list->first->easyType, classesNames))
		{
			typeOfArray = type->list->first->easyType;
		}
		else if (!isUserClass(type->list->first->easyType, classesNames))
		{
			char message[200] = "EXCEPTION! Unknown array type \"";
			exception e(strcat(strcat(message, type->list->first->easyType), "\""));
			throw e;
		}
		return typeOfArray;
	}
	else
	{
		++nestingLevel;
		return collectArrayInfo(type->list->first->complexType, classesNames, nestingLevel);
	}
}

char* transformStdKotlinTypeToMyKotlinTypes(const char* type)
{
	if (isStandartKotlinType(type))
	{
		char* myTypeName;
		if (strcmp(type, "String") == 0)
		{
			myTypeName = new char[strlen("MyLib/MyString") + 1];
			strcpy(myTypeName, "MyLib/MyString");
		}
		else
		{
			myTypeName = new char[strlen("MyLib/") + strlen(type) + 1];
			strcat(strcpy(myTypeName, "MyLib/"), type);
		}
		return myTypeName;
	}
	else return NULL;
}

void transformTypes(typeS* type, const list<string>& classesNames)
{
	//≈сли простой тип €вл€етс€ стандартным котлин типом, то мен€ем его на свой котлин тип
	if (type->easyType != 0)
	{
		if (isStandartKotlinType(type->easyType)
			&& !isUserClass(type->easyType, classesNames))
		{
			type->easyType = transformStdKotlinTypeToMyKotlinTypes(type->easyType);
		}
		else if (!isUserClass(type->easyType, classesNames))
		{
			char message[200] = "EXCEPTION! Incorrect type \"";
			exception e(strcat(strcat(message, type->easyType), "\""));
			throw e;
		}
	}
	else if (type->complexType != 0 )
	{
		int templateNestingLevel = 1;
		char* arrayType = collectArrayInfo(type->complexType, classesNames, templateNestingLevel);;
		char* newType = new char(strlen(arrayType) + templateNestingLevel * 2 + 1);
		strcpy(newType, arrayType);
		for (int i = 0; i < templateNestingLevel; ++i)
			strcat(newType, "[]");
		type->easyType = newType;
		templateTypeFree(type->complexType);
		free(type->complexType);
		type->complexType = 0;
	}

}

void transformTypes(formalParamsList* fps, const list<string>& classesNames)
{
	if (fps != 0)
	{
		for (auto fp = fps->first; fp != 0; fp = fp->next)
		{
			transformTypes(fp->type, classesNames);
		}
	}
}

void transformTypes(funcDeclS* decl, const list<string>& classesNames)
{
	if (decl == 0) return;

	transformTypes(decl->type, classesNames);
	transformTypes(decl->params, classesNames);
}

void transformTypes(methodS* meth, const list<string>& classesNames)
{
	if (meth == 0 || meth->func == 0)
	{
		return;
	}

	if (meth->func->delc != 0)
	{
		transformTypes(meth->func->delc, classesNames);
	}
	
	if (meth->func->stmts != 0) transformTypes(meth->func->stmts, classesNames);
}

void transformTypes(stmtS* stmt, const list<string>& classesNames)
{
	switch (stmt->type) 
	{
	case VarOrVal:
		if (stmt->varOrVal->type != 0)
			transformTypes(stmt->varOrVal->type, classesNames);
		else
			transformTypes(stmt->varOrVal->namesAndTypes, classesNames);
		break;
	case WhileLoop:
	case DoWhileLoop:
		transformTypes(stmt->whileLoop->stmts, classesNames);
		break;
	case ForLoop:
		transformTypes(stmt->forLoop->params, classesNames);
		transformTypes(stmt->forLoop->stmts, classesNames);
		break;
	case IfStmt:
		if (stmt->ifStmt->actions != 0)
			transformTypes(stmt->ifStmt->actions, classesNames);
		else
			transformTypes(stmt->ifStmt->altActions, classesNames);
		break;
	}
}

void transformTypes(stmtList* stmts, const list<string>& classesNames)
{
	if (stmts == 0) return;

	for (stmtS* stmt = stmts->first; stmt != 0; stmt = stmt->next)
	{
		transformTypes(stmt, classesNames);
	}
}

void transformTypes(propertyS* prop, const list<string>& classesNames)
{
	if (prop == 0) return;

	transformTypes(prop->varOrVal->type, classesNames);
}

void transformTypes(classS* cl, const list<string>& classesNames)
{
	if (cl == 0 || cl->body == 0)
	{
		return;
	}
	classBodyElementS* cbe = cl->body->first;
	while (cbe != 0)
	{
		if (cbe->method != 0) transformTypes(cbe->method, classesNames);
		else if (cbe->property != 0) transformTypes(cbe->property, classesNames);
		cbe = cbe->next;
	}
}

//ѕроверить типы на корректность, все ли указанные типы вообще существуют.
//ѕреобразовать типы Kotlin к моим базовым типам
void transformTypes(programS* program) 
{
	if (program == 0)
		return;
	list<string> classesNames;

	programElementS* pe = program->first;
	while (pe != 0)
	{
		if (pe->clas != 0) classesNames.push_back(pe->clas->name);
		pe = pe->next;
	}
	pe = program->first;
	while (pe != 0)
	{
		if (pe->clas != 0)	transformTypes(pe->clas, classesNames);
		pe = pe->next;
	}
}

bool isParentClass(const string& potentialParent, const string& potentialChild, const programS* const program) 
{

	for (auto pe = program->first; pe != 0; pe = pe->next)
	{
		if (pe->clas != 0 && pe->clas->name == potentialChild)
		{
			if (pe->clas->parentClassName == 0) return false;
			else if (pe->clas->parentClassName == potentialParent) return true;
			else	return isParentClass(potentialParent, pe->clas->parentClassName, program);
		}
	}

	return false;
}

bool isParentClass(const string& potentialParent, const string& potentialChild, const list<pair<string, string>>& classesAndParents) 
{
	
	for (auto classAndParent : classesAndParents)
	{
		if (classAndParent.first == potentialChild)
		{
			if (classAndParent.second == "")	return false;
			else if (classAndParent.second == potentialParent)	 return true;
			else	return isParentClass(potentialParent, classAndParent.second, classesAndParents);
		}		
	}
	return false;
}

//ѕроверить, что у класса есть модификатор open
bool isOpenClass(const string& className, const programS* const program)
{
	for (programElementS* pe = program->first; pe != 0; pe = pe->next)
	{
		if (pe->clas != 0 && pe->clas->name == className && pe->clas->mods != 0
			&& pe->clas->mods->iMod == Open || className == "Any" && !isUserClass("Any", program))
			return true;
	}
	return false;
}

void checkInheritance(const programS* const program)
{
	list<pair<string, string>> classesAndParents;
	for (programElementS* pe = program->first; pe != 0; pe = pe->next)
	{
		if (pe->clas != 0)
		{
			pair<string, string> classAndParent;
			classAndParent.first = pe->clas->name;
			if (pe->clas->parentClassName != 0) classAndParent.second = pe->clas->parentClassName;
			else classAndParent.second = "";
			classesAndParents.push_back(classAndParent);
		}
	}
	for (programElementS* pe = program->first; pe != 0; pe = pe->next)
	{
		if (pe->clas != 0 && pe->clas->parentClassName != 0)
		{
			//ѕровер€ем, что класс не наследуютс€ от себ€ или своего дочернего класса
			if (isParentClass(pe->clas->name, pe->clas->parentClassName, classesAndParents))
			{
				char message[200] = "EXCEPTION! Class \"";
				exception e(strcat(strcat(strcat(message, pe->clas->name), "\" cannot be a child of class "),
					pe->clas->parentClassName));
				throw e;

			}
			//ѕровер€ем, что класс наследуетс€ от открытого класса
			else if (!isOpenClass(pe->clas->parentClassName, program))
			{
				char message[200] = "EXCEPTION! Class \"";
				exception e(strcat(strcat(strcat(message, pe->clas->name), "\" cannot be a child of FINAL class "),
					pe->clas->parentClassName));
				throw e;
			}
			//ѕровер€ем, что класс, от которого наследуемс€ вообще существует
			else if (!isUserClass(pe->clas->parentClassName, program) && pe->clas->parentClassName != "Any")
			{
				char message[200] = "EXCEPTION! Class \"";
				exception e(strcat(strcat(strcat(message, pe->clas->name), "\" cannot be a child of undeclared or  \
					class - "), pe->clas->parentClassName));
				throw e;
			}
			
		}

	}
}

void fillClassesFiles(list<ClassFile> files, programS* program)
{
	for (programElementS* pe = program->first; pe != 0; pe = pe->next)
	{
		if (pe->clas != 0)
		{
			ClassFile* file = new ClassFile(pe->clas, program);
			files.push_back(*file);
		}
	}
}


programS* transformProgram(list<ClassFile> classesFiles, programS* program)
{
	if (program == 0 || program->first == 0) return program;

	program = transformProgramToClass(program);
	checkClassesNames(program);
	checkInheritance(program);
	transformTypes(program);
	addBaseClassAsParent(program);
	transformFuncsLikeExpr(program);	
	complementModifiers(program);
	checkConstructorsAndInits(program);
	transformDestructAssign(program);
	checkMethodsAndPropsNames(program);
	checkMethodsVilibilityLevelIncreasing(program);
	checkPropertyInitialization(program);
	transformAssignmentWithFieldAndArrays(program);
	fillClassesFiles(classesFiles, program);
	return program;
}