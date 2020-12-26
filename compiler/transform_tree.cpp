#include "transform_root.h"

char* transformStdKotlinTypeToMyKotlinTypes(const char* type);

void transformAssignmentWithFieldAndArrays(stmtList* stmts);

bool isParentClass(const string& potentialParent, const string& potentialChild, const programS* const program);

void templateTypeFree(templateTypeS* type);

bool transformTypes(stmtList* stmts, const list<string>& classesNames);

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

	//Найти первый pe класс
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

	//Добавили все глобальные поля и методы в новый класс
	while (pe != 0)
	{
		if (pe->method != 0) 
		{
			if (pe->method->mods != 0)
			{
				if (pe->method->mods->isOverride)
				{
					printf("Error! Top level function \"%s\" cannot be overriden\n",
						pe->method->func->decl->name);
					isCorrectTransformation = false;
				}
				if (pe->method->mods->vMod == Protected)
				{
					printf("Error! Top level function \"%s\" cannot be protected\n",
						pe->method->func->decl->name);
					isCorrectTransformation = false;
				}
				else if (pe->method->mods->vMod == Private)
				{
					pe->method->mods->vMod = Public;
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
				printf("Error! Unsupported static constant value \"%s\"\n", pe->property->varOrVal->id);
				isCorrectTransformation = false;
			}
			if (pe->property->mods != 0)
			{
				pe->property->mods->isStatic = true;
				if (pe->property->mods->vMod == Protected)
				{
					printf("Error! Top level property \"%s\" cannot be protected\n",
						pe->property->varOrVal->id);
					isCorrectTransformation = false;
				}
				else if (pe->property->mods->vMod == Private)
				{
					pe->property->mods->vMod = Public;
				}
			}
			else
			{
				pe->property->mods = createModifiers(0, 0, Public, None);
				pe->property->mods->isStatic = true;
			}
			newClass->body = addToClassBody(newClass->body, pe->property);
		}
			
		pe = pe->next;
	}
	//Убрали из дерева лишние узлы
	programTreeRoot = removeRedundantNodes(programTreeRoot);
	if (newClass->body->first != 0)
	{
		//Добавили новый класс
		if (programTreeRoot->first == 0)	programTreeRoot = createProgram(newClass);
		else	programTreeRoot = addToProgram(programTreeRoot, newClass);
	}	

	if (!isCorrectTransformation)
	{
		throw exception("Exception! Error in transformation of global function and variables!\n");
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

	//Если конструкторов нет, то создаем конструктор по умолчанию
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
	
	//Убрать inits
	
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
		printf("Error! Unsupported NOT PUBLIC contructors\n");
		return false;
	}
	return true;
}

bool complementModifiers(methodS* meth)
{
	bool res = true;

	if (meth->funcDecl != 0)
	{
		printf("Error! Unsupported ABSTRACT method with name \"%s\"\n", meth->funcDecl->name);
		res = false;
	}

	if (meth->mods != 0)
	{
		if (meth->mods->iMod == None) meth->mods->iMod = Final;
		if (meth->mods->vMod == Unknown) meth->mods->vMod = Public;
		else if (meth->mods->vMod == Internal)
		{
			printf("Error! Unsupported INTERNAL visibility mod with method \"%s\"\n", meth->func->decl->name);
			res = false;
		}
		if (meth->mods->isAbstract == true)
		{
			printf("Error! Unsupported ABSTRACT mod with method \"%s\"\n", meth->func->decl->name);
			res = false;
		}

		if (meth->mods->isOverride == true && meth->mods->vMod == Private)
		{
			printf("Error! Method with name \"%s\" cannot be OVERRIDE and PRIVATE\n", meth->func->decl->name);
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
				has inheritance mod\n", prop->varOrVal->id);
			res = false;
		}

		if (prop->mods->vMod == Unknown) prop->mods->vMod = Public;
		else if (prop->mods->vMod == Internal)
		{
			printf("Error! Unsupported INTERNAL visibility mod with property \"%s\"\n", 
				prop->varOrVal->id);
			res = false;
		}
		if (prop->mods->isAbstract == true)
		{
			printf("Error! Unsupported ABSTRACT mod with property \"%s\"\n",
				prop->varOrVal->id);
			res = false;
		}
		if (prop->mods->isOverride == true)
		{
			printf("Error! Unsupported OVERRIDE mod with property \"%s\"\n",
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
		bool tmp = true;
		if (cbe->property)
		{
			tmp = complementModifiers(cbe->property);
			res = res && tmp;
		}
		else if (cbe->method)
		{
			tmp = complementModifiers(cbe->method);
			res = res && tmp;
		}
		else if (cbe->constructor)
		{
			tmp = checkConstructorMod(cbe->constructor);
			res = res && tmp;
		}
	}

	if (res == false)
	{
		if (strcmp(cl->name, "Main$") == 0)
			printf("Errors in global scope\n");
		else
			printf("Errors in class - %s\n", cl->name);
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
					printf("Error! Unsupported INTERNAL visibility mod with class \"%s\"\n", pe->clas->name);
					res = false;
				}
				else if (pe->clas->mods->vMod == Protected || pe->clas->mods->vMod == Private)
				{
					printf("Error! Invalid visibility mod with no inner class \"%s\"\n", pe->clas->name);
					res = false;
				}
				if (pe->clas->mods->isAbstract == true) 
				{
					printf("Error! Unsupported ABSTRACT mod with class \"%s\"\n", pe->clas->name);
					res = false;
				}
				if (pe->clas->mods->isOverride == true)
				{
					printf("Error! Invalid OVERRIDE mod with class \"%s\"\n", pe->clas->name);
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
		throw exception("Exception! Error in modifiers complementing\n");
}

//Проверяем, что у родительского метода менее строгий уровень доступа
bool isParentMethodVisModWeaken(visibilityMod vMod, const programS* const program, 
	const string& methodSign, const string& parentClassName)
{
	if (&parentClassName == NULL || parentClassName == "")
		return false;

	if (parentClassName == "MyLib/Any")
	{
		if ((methodSign == "equals(MyLib/Any)" || methodSign == "toMyString()") && vMod != Public)
		{
			return true;
		}
		else	return false;
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
		return false;
	}
}

//Проверяем понижение уровня доступа для методов класса, которые переопределяются
void checkMethodsVilibilityLevelIncreasing(const programS* const program)
{
	bool res = true;

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
					printf("Error! Method \"%s\" in class \"%s\"  has stricter visibility modifier than parent's method\n", 
						cbe->method->func->decl->name, pe->clas->name);
					res = false;
				}
			}
		}
	}

	if (!res)
		throw exception("Exception! Errors in methods visibility modifiers\n");
}

bool checkPropsNames(classS* clas, const  programS* const program)
{
	if (clas == 0 || clas->body == 0)
		return true;

	bool res = true;

	list<string> propertyNames;
	for (auto cbe = clas->body->first; cbe != 0; cbe = cbe->next)
	{
		if (cbe->property != 0)
		{
			if (find(propertyNames.begin(), propertyNames.end(), cbe->property->varOrVal->id) 
				!= propertyNames.end())
			{
				printf("Error! Property with name \"%s\" is already declared in class \"%s\"\n",
					cbe->property->varOrVal->id, clas->name);
				res = false;
			}
			
			if (clas->parentClassName != 0 && getPropertyType(cbe->property->varOrVal->id, 
				program, clas->parentClassName) != "")
			{
				printf("Error!  Redefine of parent property \"%s\" in class \"%s\"\n",
					cbe->property->varOrVal->id, clas->name);
				res = false;
			}
			
			propertyNames.push_back(cbe->property->varOrVal->id);
		}
	}

	return res;
}


bool isChildType(const string& potentialChildType, const string& potentialParentType,
	const programS* const program)
{
	if (potentialChildType == "" || potentialParentType == "")
		return false;

	//Если в качестве дочернего класса указан базовый класс
	if (potentialChildType == "MyLib/Any")
		return false;

	//Если в качестве родительского типа выступает Any, т.е. базовый класс
	if (potentialParentType == "MyLib/Any")
		return true;

	//Если родителем является стандартный тип (они все final) кроме Any
	if (isMyStandartClass(potentialParentType))
		return false;

	//Если родителем является массив
	if (potentialParentType.find("[]") != -1)
		return false;

	//Если дочений класс - стандартный тип и родитель не Any
	if (isMyStandartClass(potentialChildType))
		return false;

	//Если дочерний класс - массив и родитель не Any
	if (potentialChildType.find("[]") != -1)
		return false;

	//Если оба класса - пользовательские, то проверяем их
	if (isUserClass(potentialChildType.c_str(), program))
	{
		return isParentClass(potentialParentType, potentialChildType, program);
	}
}

//Находит модификаторы ближайшего родительского метода с идентичной сигнатурой или метода указанного класса
const modifiersS* findMethodModifiers(const string& methodSign, 
	const programS* const program, const string& startClassName)
{
	if (startClassName == "")
		return 0;

	if (startClassName == "MyLib/Any")
	{
		if (methodSign == "equals(MyLib/Any|)")
			return createModifiers(0, 0, Public, Open);

		if (methodSign == "toMyString()")
			return createModifiers(0, 0, Public, Open);

		return 0;
	}
	else
	{
		auto method = findMethod(methodSign, program, startClassName);
		if (method != 0)
		{
			const modifiersS* resMods;
			if (method->mods->isOverride)
				resMods = createModifiers(method->mods->isAbstract, method->mods->isOverride,
					method->mods->vMod, Open);
			else
				resMods = method->mods;

			return resMods;
		}
			
		else
			return 0;
	}	
}

bool checkMethods(classS* clas, programS* program)
{
	if (clas == 0 || clas->body == 0)
		return true;

	bool res = true;

	list<string> methodSigns;
	for (auto cbe = clas->body->first; cbe != 0; cbe = cbe->next)
	{
		if (cbe->method != 0)
		{
			string methodSign = createMethodSignature(cbe->method);

			//Заменяем имя на имя стандартной функции моей библиотеки
			if (methodSign == "toString()" && strcmp(clas->name, "Main$") != 0)
			{
				char* tmp = new char[strlen("toMyString") + 1];
				strcpy(tmp, "toMyString");
				cbe->method->func->decl->name = tmp;
				methodSign = "toMyString()";
			}

			if (find(methodSigns.begin(), methodSigns.end(), methodSign)
				!= methodSigns.end())
			{
				printf("Error! Method with name \"%s\" is already declared in class \"%s\"\n",
					cbe->method->func->decl->name, clas->name);
				res = false;
			}

			//Если это не созданный статический класс
			if (strcmp(clas->name, "Main$") != 0)
			{
				string retValue = getMethodType(methodSign, program, clas->parentClassName);
				
				//У метода нет родительского аналога
				if (retValue == "" && cbe->method->mods->isOverride)
				{
					printf("Error! Method \"%s\" in class \"%s\" doesn't overrides any parent's method\n", 
						cbe->method->func->decl->name, clas->name);
					res = false;
				}

				//Проверяем модификаторы для случаев, когда у метода есть родительский аналог
				if (clas->parentClassName != 0 && retValue != "")
				{
					if (retValue != cbe->method->func->decl->type->easyType && 
						!isChildType(cbe->method->func->decl->type->easyType, retValue, program))
					{
						printf("Error! Return value of method \"%s\" in class \"%s\" is not a child \
							of type - \"%s\"\n", cbe->method->func->decl->name, clas->name, retValue.c_str());
						res = false;
					}
					if (!cbe->method->mods->isOverride)
					{
						printf("Error! Method with name \"%s\" in class \"%s\" hasn't modifier OVERRIDE\n", 
							cbe->method->func->decl->name, clas->name);
						res = false;
					}
					
					const modifiersS* parentMethodMods = findMethodModifiers(methodSign, program, clas->parentClassName);
					if (parentMethodMods != 0 && parentMethodMods->iMod == Final)
					{
						printf("Error! Parent's method of method with name \"%s\" in class \"%s\" is NOT OPEN\n",
							cbe->method->func->decl->name, clas->name);
						res = false;
					}
					if (parentMethodMods != 0 && parentMethodMods->vMod == Private)
					{
						printf("Error! Parent's method of method with name \"%s\" in class \"%s\" has modifier PRIVATE\n",
							cbe->method->func->decl->name, clas->name);
						res = false;
					}
				}
			}			
		}
	}

	return res;
}

void checkMethodsAndPropsNames(programS* program)
{
	bool res = true;

	for (auto pe = program->first; pe != 0; pe = pe->next)
	{
		if (pe->clas != 0)
		{
			bool tmp = checkMethods(pe->clas, program);
			res = res && tmp;
			tmp = checkPropsNames(pe->clas, program);
			res = res && tmp;
		}
	}

	if (!res)
		throw exception("Exception! Errors in methods names or properties names\n");
}


/*Проверяем, нет ли переобъявления пользовательских классов*/
void checkClassesNames(const programS* const program)
{
	if (program == 0)
		return;

	list<string> classNames;
	
	bool checkingRes = true;

	for (programElementS* pe = program->first; pe != 0; pe = pe->next) 
	{
		if (pe->clas != 0)
		{
			auto res = find(classNames.begin(), classNames.end(), string(pe->clas->name));
			if (res != classNames.end())
			{
				printf("Error! Class with name \"%s\" is already declared\n", pe->clas->name);
				checkingRes = false;
			}
			else	classNames.push_back(string(pe->clas->name));
		}
	}

	if (!checkingRes)
		throw exception("Exception! Errors in checking of class names\n");
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

bool checkStaticFuncsLikeConstructors(const programS* const program)
{
	classS* mainClass = 0;
	for (auto pe = program->first; pe != 0 && mainClass == 0; pe = pe->next)
	{
		if (pe->clas != 0 && strcmp(pe->clas->name, "Main$") == 0) mainClass = pe->clas;
	}

	bool res = true;

	if (mainClass != 0 && mainClass->body != 0)
	{
		for (auto cbe = mainClass->body->first; cbe != 0; cbe = cbe->next)
		{
			if (cbe->method != 0 && isUserClass(cbe->method->func->decl->name, program) 
				&& cbe->method->func->decl->params == 0)
			{
				printf("Error! Global function overlap constructor of class \"%s\"\n", cbe->method->func->decl->name);
				res = false;
			}
		}
	}
	
	return res;
}

bool checkConstructorsAndInits(const classS* const cl)
{
	if (cl->body == 0)
	{
		return true;
	}
	
	bool res = true;

	classBodyElementS* cbe = cl->body->first;
	int publicConstrCount = 0;
	while (cbe != 0)
	{
		//Запрещены все конструкторы кроме public constructor() 
		if (cbe->constructor != 0 && (cbe->constructor->anotherConstrParams != 0
			|| cbe->constructor->anotherConstructorId != 0 || cbe->constructor->params != 0
			|| cbe->constructor->stmts != 0 || cbe->constructor->mod != Public))
		{
			printf("Error! Unsupported not public not default constructor in class \"%s\"\n", cl->name);
			res = false;
		}
		else if (cbe->constructor != 0 && cbe->constructor->anotherConstrParams == 0
			&& cbe->constructor->anotherConstructorId == 0 && cbe->constructor->params == 0
			&& cbe->constructor->stmts == 0 && cbe->constructor->mod == Public)
		{
			publicConstrCount++;
		}

		if (cbe->init != 0)
		{
			printf("Error! Unsupported initializator in class \"%s\"\n", cl->name);
			res = false;
		}
		cbe = cbe->next;
	}

	if (publicConstrCount > 1)
	{
		printf("Error! Redefine of default contructor in class \"%s\"\n", cl->name);
		res = false;
	}

	return res;
}

void checkConstructorsAndInits(const programS* const program)
{
	if (program == 0)
		return;

	bool res = true;
	bool tmp = true;

	programElementS* pe = program->first;
	while (pe != 0)
	{
		
		if (pe->clas != 0)
		{
			tmp = checkConstructorsAndInits(pe->clas);
			res = res && tmp;
		}
		pe = pe->next;
	}

	tmp = checkStaticFuncsLikeConstructors(program);
	res = res && tmp;

	if (!res)
		throw exception("Exception! Errors in ckecking of constructors and initializers");
}

constructorS* findDefaultConstructorOrAdd(classS* cl)
{
	//Ищем конструктор по умолчанию
	constructorS* constr = 0;
	if (cl->body != 0)
	{
		for (auto cbe = cl->body->first; cbe != 0 && constr == 0; cbe = cbe->next)
		{
			if (cbe->constructor != 0) constr = cbe->constructor;
		}
	}
	
	//Если не нашли - создаем
	if (constr == 0)
	{
		constr = createConstructor(Public, 0);
		if (cl->body == 0)
			cl->body = createClassBody(constr);
		else
			cl->body = addToClassBody(cl->body, constr);
	}
	
	return constr;
}

bool checkPropertyInitialization(classS* cl)
{
	if (cl->body == 0)
	{
		return true;
	}

	bool res = true;

	auto constr = findDefaultConstructorOrAdd(cl);

	classBodyElementS* cbe = cl->body->first;
	while (cbe != 0)
	{
		if (cbe->property != 0)
		{
			//Запрещаем деструктивное присваивание
			if (cbe->property->varOrVal->namesAndTypes != 0) 
			{
				printf("Error! Destructing assignment in property declaration in class - \"%s\"\n",
					cl->name);
				res = false;
			}

			if (res && cbe->property->varOrVal->initValue == 0)
			{
				printf("Error! property \"%s\" of class \"%s\" must be initialized\n",
					cbe->property->varOrVal->id, cl->name);
				res = false;
			}

			//Перемещаем присваивание в конструктор
			if (res != 0 && cbe->property->varOrVal->initValue != 0)
			{
				stmtS* stmt = createStmt(createAssignment(createExpr(cbe->property->varOrVal->id,
					Identificator), cbe->property->varOrVal->initValue, Assign), Assignment);
				//Если конструктор пустой
				if (constr->stmts == 0)	constr->stmts = createStmtList(stmt);
				//Если в конструкторе были инструкции
				else	constr->stmts = addToStmtList(constr->stmts, stmt);
				
				//Убираем инициализацию из объявления поля
				cbe->property->varOrVal->initValue = 0;
			}
		}
		cbe = cbe->next;
	}

	if (strcmp(cl->name, "Main$") == 0)
	{
		constr->isStatic = true;
	}

	return res;
}

void checkPropertyInitialization(const programS* const program)
{
	if (program == 0)
		return;

	bool res = true;

	programElementS* pe = program->first;
	while (pe != 0)
	{
		if (pe->clas != 0) res = res && checkPropertyInitialization(pe->clas);
		pe = pe->next;
	}

	if (!res)
		throw exception("Exception! Errors in property initialization\n");
}

bool transformDestructAssign(methodS* meth)
{
	if (meth->func == 0 || meth->func->stmts == 0)
	{
		return true;
	}

	bool res = true;

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
					printf("Unsupported call of componentN in method \"%s\"\n", meth->func->decl->name);
					res = false;
				}
			}
			
			if (afterMultiDeclStmt == 0) meth->func->stmts->last = currentStmt;
			free(stmt->varOrVal->namesAndTypes);
			stmt->varOrVal->namesAndTypes = 0;
			currentStmt->next = afterMultiDeclStmt;
		}
		else if (stmt->forLoop != 0 && stmt->forLoop->isDestructing)
		{
			printf("Unsupported destruction assignment in for loop in method \"%s\"\n", meth->func->decl->name);
			res = false;
		}


		if (currentStmt != 0)	stmt = currentStmt->next;
		else					stmt = stmt->next;
	}

	return res;
}

bool transformDestructAssign(classS* cl)
{
	if (cl->body == 0)
	{
		return true;
	}

	bool res = true;

	classBodyElementS* cbe = cl->body->first;
	while (cbe != 0)
	{
		if (cbe->method != 0) res = res && transformDestructAssign(cbe->method);
		cbe = cbe->next;
	}

	return res;
}

void transformDestructAssign(programS* program)
{
	if (program == 0)
		return;

	bool res = true;

	programElementS* pe = program->first;
	while (pe != 0)
	{
		if (pe->clas != 0) res = res && transformDestructAssign(pe->clas);
		pe = pe->next;
	}

	if (!res)
		throw exception("Exception! Errors in destructing assignment\n");
	
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

char* collectArrayInfo(templateTypeS* type, const list<string>& classesNames, int& nestingLevel)
{
	if (type == 0)
		return 0;

	if (strcmp(type->type, "Array") != 0)
	{
		printf("Unsupported template type \"%s\"\n", type->type);
	}
	if (type->list->first != type->list->last)
	{
		printf("EXCEPTION! More than 1 array type\n");
	}
	if (type->list->first->easyType != 0)
	{
		char* typeOfArray = 0;
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
			printf("EXCEPTION! Unknown array type \"%s\"\n", type->list->first->easyType);
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

bool transformTypes(typeS* type, const list<string>& classesNames)
{
	bool res = true;

	//Если простой тип является стандартным котлин типом, то меняем его на свой котлин тип
	if (type->easyType != 0)
	{
		if (isStandartKotlinType(type->easyType)
			&& !isUserClass(type->easyType, classesNames))
		{
			type->easyType = transformStdKotlinTypeToMyKotlinTypes(type->easyType);
		}
		else if (!isUserClass(type->easyType, classesNames))
		{
			printf("Error! Unknown type \"%s\"\n", type->easyType);
			res = false;
		}
	}
	else if (type->complexType != 0 )
	{
		int templateNestingLevel = 1;
		char* arrayType = collectArrayInfo(type->complexType, classesNames, templateNestingLevel);
		if (arrayType != 0)
		{
			char* newType = new char(strlen(arrayType) + templateNestingLevel * 2 + 1);
			strcpy(newType, arrayType);
			for (int i = 0; i < templateNestingLevel; ++i)
				strcat(newType, "[]");
			type->easyType = newType;
			templateTypeFree(type->complexType);
			free(type->complexType);
			type->complexType = 0;
		}
		else res = false;
	}

	return res;
}

bool transformTypes(formalParamsList* fps, const list<string>& classesNames)
{
	bool res = true;

	if (fps != 0)
	{
		for (auto fp = fps->first; fp != 0; fp = fp->next)
		{
			bool tmp = transformTypes(fp->type, classesNames);
			res = res && tmp;
		}
	}

	return res;
}

bool transformTypes(funcDeclS* decl, const list<string>& classesNames)
{
	if (decl == 0) return true;

	bool res = true;
	bool tmp = transformTypes(decl->type, classesNames);
	res = res && tmp;
	tmp = transformTypes(decl->params, classesNames);
	res = res && tmp;

	return res;
}

bool transformTypes(methodS* meth, const list<string>& classesNames)
{
	if (meth == 0 || meth->func == 0)
	{
		return true;
	}

	bool res = true;

	if (meth->func->decl != 0)
	{
		bool tmp = transformTypes(meth->func->decl, classesNames);
		res = res && tmp;
	}
	
	if (meth->func->stmts != 0)
	{
		bool tmp = transformTypes(meth->func->stmts, classesNames);
		res = res && tmp;
	}

	if (res == false)
		printf("Errors in method \"%s\"\n", meth->func->decl->name);

	return res;
}

bool transformTypes(stmtS* stmt, const list<string>& classesNames)
{
	bool res = true;
	bool tmp = true;
	switch (stmt->type) 
	{
	case VarOrVal:
		if (stmt->varOrVal->type != 0)
		{
			tmp = transformTypes(stmt->varOrVal->type, classesNames);
			res = res && tmp;
		}
		else
		{
			tmp = transformTypes(stmt->varOrVal->namesAndTypes, classesNames);
			res = res && tmp;
		}			
		break;
	case WhileLoop:
	case DoWhileLoop:
		tmp = transformTypes(stmt->whileLoop->stmts, classesNames);
		res = res && tmp;
		break;
	case ForLoop:
		tmp = transformTypes(stmt->forLoop->params, classesNames);
		res = res && tmp;
		tmp = transformTypes(stmt->forLoop->stmts, classesNames);
		res = res && tmp;
		break;
	case IfStmt:
		if (stmt->ifStmt->actions != 0)
		{
			tmp = transformTypes(stmt->ifStmt->actions, classesNames);
			res = res && tmp;
		}
		else
		{
			tmp = transformTypes(stmt->ifStmt->altActions, classesNames);
			res = res && tmp;
		}			
		break;
	}

	return res;
}

bool transformTypes(stmtList* stmts, const list<string>& classesNames)
{
	if (stmts == 0) return true;

	bool res = true;

	for (stmtS* stmt = stmts->first; stmt != 0; stmt = stmt->next)
	{
		bool tmp = transformTypes(stmt, classesNames);
		res = res && tmp;
	}

	return res;
}

bool transformTypes(propertyS* prop, const list<string>& classesNames)
{
	if (prop == 0) return true;

	bool res;
	if (prop->varOrVal->id != 0)
		res = transformTypes(prop->varOrVal->type, classesNames);
	else
	{
		printf("Error! Property multideclaration\n");
		return false;
	}
	if (res)
		return true;
	else
	{
		printf("Error in property declaration \"%s\"\n", prop->varOrVal->id);
		return false;
	}
}

bool transformTypes(classS* cl, const list<string>& classesNames)
{
	if (cl == 0 || cl->body == 0)
	{
		return true;
	}

	bool res = true;

	classBodyElementS* cbe = cl->body->first;
	while (cbe != 0)
	{
		bool tmp = true;
		if (cbe->method != 0) 
		{
			tmp = transformTypes(cbe->method, classesNames);
			res = res && tmp;
		}
		else if (cbe->property != 0)
		{
			tmp = transformTypes(cbe->property, classesNames);
			res = res && tmp;
		}
		cbe = cbe->next;
	}

	return res;
}

//Проверить типы на корректность, все ли указанные типы вообще существуют.
//Преобразовать типы Kotlin к моим базовым типам
void transformTypes(programS* program) 
{
	if (program == 0)
		return;
	list<string> classesNames;

	bool res = true;

	programElementS* pe = program->first;
	while (pe != 0)
	{
		if (pe->clas != 0) classesNames.push_back(pe->clas->name);
		pe = pe->next;
	}
	pe = program->first;
	while (pe != 0)
	{
		bool tmp = true;
		if (pe->clas != 0)
		{
			tmp = transformTypes(pe->clas, classesNames);
			res = res && tmp;
		}
		pe = pe->next;
	}

	if (!res)
		throw exception("Exception! Errors in types transformation\n");
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

//Проверить, что у класса есть модификатор open
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

	bool res = true;

	for (programElementS* pe = program->first; pe != 0; pe = pe->next)
	{
		if (pe->clas != 0 && pe->clas->parentClassName != 0)
		{
			//Проверяем, что класс не наследуются от себя или своего дочернего класса
			if (isParentClass(pe->clas->name, pe->clas->parentClassName, classesAndParents))
			{
				printf("Error! Class \"%s\" cannot be a child of class \"%s\"\n", pe->clas->name, pe->clas->parentClassName);
				res = false;
			}
			//Проверяем, что класс наследуется от открытого класса
			else if (!isOpenClass(pe->clas->parentClassName, program))
			{
				printf("Error! Class \"%s\" cannot be a child of FINAL class \"%s\"\n", pe->clas->name, pe->clas->parentClassName);
				res = false;
			}
			//Проверяем, что класс, от которого наследуемся вообще существует
			else if (!isUserClass(pe->clas->parentClassName, program) && strcmp(pe->clas->parentClassName, "Any"))
			{
				printf("Error! Class \"%s\" cannot be a child of undeclared class \"%s\"\n", pe->clas->name, pe->clas->parentClassName);
				res = false;
			}
		}
	}

	if (!res)
		throw exception("Exception! Errors in inheritance\n");
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