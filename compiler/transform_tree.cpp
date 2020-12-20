#include "transform_root.h"

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
	
	//Добавили все глобальные поля и методы в новый класс
	while (pe != 0)
	{
		if (pe->method != 0) 
		{
			if (pe->method->mods != 0)
			{
				if (pe->method->mods->isOverride)
				{
					char message[200] = "EXCEPTION! Top level function \"";
					exception e((strcat(strcat(message, pe->method->funcDecl->name), "\" cannot be overriden")));
					throw e;
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
			if (pe->property->mods != 0)	pe->property->mods->isStatic = true;
			else
			{
				if (pe->property->varOrVal->isVal)	pe->property->mods = createModifiers(0, 0, Public, Final);
				else pe->property->mods = createModifiers(0, 0, Public, None);

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

void complementModifiers(classS* cl)
{
	if (cl == 0)
		return;

	for (classBodyElementS* cbe = cl->body->first; cbe != 0; cbe = cbe->next) 
	{
		if (cbe->property )
		{
			if (cbe->property->mods != 0)
			{
				if (cbe->property->mods->iMod == Open || cbe->property->mods->iMod == Final)
				{
					char message[200] = "EXCEPTION! Inheritance mods of properties are not supported. Property \"";

					exception e((strcat(strcat(message, cbe->property->varOrVal->id), "\" has inheritance mod")));
					throw e;
				}
				else if (cbe->property->varOrVal->isVal) cbe->property->mods->iMod = Final;

				if (cbe->property->mods->vMod == Unknown) cbe->property->mods->vMod = Public;
				else if (cbe->property->mods->vMod == Internal)
				{
					char message[200] = "EXCEPTION! Unsupported INTERNAL visibility mod with property \"";

					exception e((strcat(strcat(message, cbe->property->varOrVal->id), "\"")));
					throw e;
				}
				if (cbe->property->mods->isAbstract == true)
				{
					char message[200] = "EXCEPTION! Unsupported ABSTRACT mod with property \"";

					exception e((strcat(strcat(message, cbe->property->varOrVal->id), "\"")));
					throw e;
				}
				if (cbe->property->mods->isOverride == true)
				{
					char message[200] = "EXCEPTION! Unsupported OVERRIDE mod with property \"";

					exception e((strcat(strcat(message, cbe->property->varOrVal->id), "\"")));
					throw e;
				}
			}
			else
			{
				if (cbe->property->varOrVal->isVal)	cbe->property->mods = createModifiers(0, 0, Public, Final);
				else	cbe->property->mods = createModifiers(0, 0, Public, None);
				
			}
		}
		else if (cbe->method)
		{
			if (cbe->method->funcDecl != 0) 
			{
				char message[200] = "EXCEPTION! Unsupported ABSTRACT method with name \"";

				exception e((strcat(strcat(message, cbe->method->funcDecl->name), "\"")));
				throw e;
			}

			if (cbe->method->mods != 0)
			{
				if (cbe->method->mods->iMod == None) cbe->method->mods->iMod = Final;
				if (cbe->method->mods->vMod == Unknown) cbe->method->mods->vMod = Public;
				else if (cbe->method->mods->vMod == Internal)
				{
					char message[200] = "EXCEPTION! Unsupported INTERNAL visibility mod with method \"";

					exception e((strcat(strcat(message, cbe->method->func->delc->name), "\"")));
					throw e;
				}
				if (cbe->method->mods->isAbstract == true)
				{
					char message[200] = "EXCEPTION! Unsupported ABSTRACT mod with method \"";

					exception e((strcat(strcat(message, cbe->method->func->delc->name), "\"")));
					throw e;
				}

				if (cbe->method->mods->isOverride == true && cbe->method->mods->vMod == Private) 
				{
					char message[200] = "EXCEPTION! Method with name \"";

					exception e((strcat(strcat(message, cbe->method->func->delc->name), "\" cannot be OVERRIDE and PRIVATE")));
					throw e;
				}
			}
			else
			{
				cbe->method->mods = createModifiers(0, 0, Public, Final);
			}
		}
	}
}

void complementModifiers(programS* program)
{
	if (program == 0)
		return;

	for (programElementS* pe = program->first; pe != 0; pe = pe->next) 
	{
		if (pe->clas != 0)
		{
			complementModifiers(pe->clas);
			if (pe->clas->mods != 0)
			{
				if (pe->clas->mods->iMod == None) pe->clas->mods->iMod = Final;
				if (pe->clas->mods->vMod == Unknown) pe->clas->mods->vMod = Public;
				else if (pe->clas->mods->vMod == Internal) 
				{
					char message[200] = "EXCEPTION! Unsupported INTERNAL visibility mod with class \"";

					exception e((strcat(strcat(message, pe->clas->name), "\"")));
					throw e;
				}
				else if (pe->clas->mods->vMod == Protected || pe->clas->mods->vMod == Private)
				{
					char message[200] = "EXCEPTION! Invalid visibility mod with no inner class \"";

					exception e((strcat(strcat(message, pe->clas->name), "\"")));
					throw e;
				}
				if (pe->clas->mods->isAbstract == true) 
				{
					char message[200] = "EXCEPTION! Unsupported ABSTRACT mod with class \"";

					exception e((strcat(strcat(message, pe->clas->name), "\"")));
					throw e;
				}
				if (pe->clas->mods->isOverride == true)
				{
					char message[200] = "EXCEPTION! Invalid OVERRIDE mod with class \"";

					exception e((strcat(strcat(message, pe->clas->name), "\"")));
					throw e;
				}
			}
			else
			{
				pe->clas->mods = createModifiers(0, 0, Public, Final);
			}
		}
	}
}

void checkMethodsAndPropsNames(classS* clas) 
{
	if (clas == 0 || clas->body == 0)
		return;
	
	list<string> methodNames;
	list<string> propertyNames;
	for (classBodyElementS* cbe = clas->body->first; cbe != 0; cbe = cbe->next)
	{
		if (cbe->property != 0)
		{
			auto res = find(propertyNames.begin(), propertyNames.end(), string(cbe->property->varOrVal->id));
			if (res != propertyNames.end())
			{
				char message[200] = "EXCEPTION! property with name \"";

				exception e((strcat(strcat(message, cbe->property->varOrVal->id), "\" is already declared")));
				throw e;
			}
			else	propertyNames.push_back(string(cbe->property->varOrVal->id));
		}
		else if (cbe->method != 0)
		{
			auto res = find(methodNames.begin(), methodNames.end(), string(cbe->method->func->delc->name));
			if (res != methodNames.end())
			{
				char message[200] = "EXCEPTION! method with name \"";

				exception e((strcat(strcat(message, cbe->method->func->delc->name), "\" is already declared")));
				throw e;
			}
			else	methodNames.push_back(string(cbe->method->func->delc->name));
		}
	}
}

void checkClassesNames(programS* program)
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

			checkMethodsAndPropsNames(pe->clas);
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

void checkConstructorsAndInits(classS* cl)
{
	if (cl->body == 0)
	{
		return;
	}
	
	classBodyElementS* cbe = cl->body->first;
	while (cbe != 0)
	{
		if (cbe->constructor != 0) 
		{
			char message[200] = "EXCEPTION! Unsupported constructor in class \"";

			exception e((strcat(strcat(message, cl->name), "\"")));
			throw e;
		}
		if (cbe->init != 0)
		{
			char message[200] = "EXCEPTION! Unsupported initializator in class \"";

			exception e((strcat(strcat(message, cl->name), "\"")));
			throw e;
		}
		cbe = cbe->next;
	}
}

void checkConstructorsAndInits(programS* program)
{
	if (program == 0)
		return;

	programElementS* pe = program->first;
	while (pe != 0)
	{
		if (pe->clas != 0) checkConstructorsAndInits(pe->clas);
		pe = pe->next;
	}
}

void checkPropertyInitialization(classS* cl)
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

void checkPropertyInitialization(programS* program)
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

bool existsEasyType(char* typeName, list<string>& classesNames)
{
	bool res = strcmp(typeName, "Int") != 0 && strcmp(typeName, "Float") != 0
		&& strcmp(typeName, "Double") != 0 && strcmp(typeName, "String") != 0
		&& strcmp(typeName, "Char") != 0 && strcmp(typeName, "Unit") != 0
		&& strcmp(typeName, "Boolean") != 0;


	for (auto className: classesNames)
	{
		res = res && strcmp(typeName, className.c_str()) != 0;
	}
	return !res;
}

char * collectArrayInfo(templateTypeS* type, list<string>& classesNames, int& nestingLevel)
{
	if (type == 0)
		return 0;

	if (strcmp(type->type, "Array") != 0)
	{
		char message[200] = "EXCEPTION! Unsupported type \"";
		exception e(strcat(strcat(message, type->type), "\""));
		throw e;
	}
	if (type->list->first != type->list->last)
	{
		char message[200] = "EXCEPTION! invalid array type \"";
		exception e(message);
		throw e;
	}
	if (type->list->first->easyType != 0)
	{
		if (!existsEasyType(type->list->first->easyType, classesNames))
		{
			char message[200] = "EXCEPTION! Incorrect array type \"";
			exception e(strcat(strcat(message, type->list->first->easyType), "\""));
			throw e;
		}
		char * typeOfArray = new char[strlen(type->list->first->easyType) + 1];
		strcpy(typeOfArray, type->list->first->easyType);
		return typeOfArray;
	}
	else
	{
		++nestingLevel;
		return collectArrayInfo(type->list->first->complexType, classesNames, nestingLevel);
	}
}

void transformTypes(typeS* type, list<string>& classesNames)
{
	//Проверяем простые типы
	if (type->easyType != 0 && !existsEasyType(type->easyType, classesNames))
	{
		char message[200] = "EXCEPTION! Incorrect type \"";
		exception e(strcat(strcat(message, type->easyType), "\""));
		throw e;
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

void transformTypes(funcDeclS* decl, list<string>& classesNames)
{
	if (decl == 0) return;

	transformTypes(decl->type, classesNames);
}

void transformTypes(methodS* meth, list<string>& classesNames)
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

void transformTypes(stmtS* stmt, list<string>& classesNames)
{
	switch (stmt->type) 
	{
	case VarOrVal:
		transformTypes(stmt->varOrVal->type, classesNames);
		break;
	case WhileLoop:
	case DoWhileLoop:
		transformTypes(stmt->whileLoop->stmts, classesNames);
		break;
	case ForLoop:
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

void transformTypes(stmtList* stmts, list<string>& classesNames)
{
	if (stmts == 0) return;

	for (stmtS* stmt = stmts->first; stmt != 0; stmt = stmt->next)
	{
		transformTypes(stmt, classesNames);
	}
}

void transformTypes(propertyS* prop, list<string>& classesNames)
{
	if (prop == 0) return;

	transformTypes(prop->varOrVal->type, classesNames);
}

void transformTypes(classS* cl, list<string>& classesNames)
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

//Проверить типы на корректность, все ли указанные типы вообще существуют.
//Преобразовать типы Kotlin к базовым в java
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


bool isParentClass(string potentialParent, string potentialChild, list<pair<string, string>>& classesAndParents) {
	
	for (auto classAndParent : classesAndParents)
	{
		if (classAndParent.first == potentialChild)
		{
			if (classAndParent.second == "")
				return false;
			else if (classAndParent.second == potentialParent) return true;
			else return isParentClass(potentialParent, classAndParent.second, classesAndParents);
		}		
	}
	return false;
}

void checkCirclesInInheritance(programS* program)
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
		if (pe->clas != 0 && pe->clas->parentClassName != 0 
			&& isParentClass(pe->clas->name, pe->clas->parentClassName, classesAndParents))
		{
			char message[200] = "EXCEPTION! Class \"";
			exception e(strcat(strcat(strcat(message, pe->clas->name), "\" cannot be a child of class "),
				pe->clas->parentClassName));
			throw e;
		}
	}
}


void fillClassesFiles(list<ClassFile*> files, programS* program)
{
	list<ShortClassInfo*> classesInfo;
	for (programElementS* pe = program->first; pe != 0 ; pe = pe->next)
	{
		if (pe->clas != 0) 
		{
			ShortClassInfo* sci = new ShortClassInfo();
			sci->className = pe->clas->name;
			if (pe->clas->body != 0)
			{
				for (classBodyElementS* cbe = pe->clas->body->first; cbe != 0; cbe = cbe->next)
				{
					if (cbe->property != 0)
					{
						sci->propertiesInfo.push_back(string(cbe->property->varOrVal->type->easyType) + "|"
						+ string(cbe->property->varOrVal->id));
					}
					else if (cbe->method != 0) 
					{
						string methodInfo = string(cbe->method->func->delc->type->easyType) + "|"
							+ string(cbe->method->func->delc->name);
						if (cbe->method->func->delc->params != 0)
						{
							for (formalParamS* fp = cbe->method->func->delc->params->first; fp != 0; fp = fp->next)
							{
								methodInfo = methodInfo + fp->type->easyType + '|' + fp->name;
							}
						}
						sci->methodsInfo.push_back(methodInfo);
					}
				}
			}
			classesInfo.push_back(sci);
		}
	}
	for (programElementS* pe = program->first; pe != 0; pe = pe->next)
	{
		if (pe->clas != 0)
		{
			ClassFile* file = new ClassFile(pe->clas, classesInfo);
		}
	}
}


programS* transformProgram(programS* program)
{
	if (program == 0 || program->first == 0) return program;

	program = transformProgramToClass(program);
	transformFuncsLikeExpr(program);
	checkConstructorsAndInits(program);
	checkPropertyInitialization(program);
	transformAssignmentWithFieldAndArrays(program);
	complementModifiers(program);
	transformDestructAssign(program);
	checkClassesNames(program);
	transformTypes(program);
	checkCirclesInInheritance(program);
	fillConstantsTable(classesFiles, program);
	return program;
}