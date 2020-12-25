#include "tables.h"


VisibilityMod translateVisibilityMod(visibilityMod vMod)
{
	switch (vMod)
	{
	case Public:
		return _PUBLIC;
	case Private:
		return _PRIVATE;
	case Protected:
		return _PROTECTED;
	default:
		break;
	}
	char message[200] = "EXCEPTION! Unsupported visibility mod translated \"";
	exception e(message);
	throw e;
}



bool isMyStandartClass(const string& className)
{
	if (className == "MyLib/Int" || className == "MyLib/Float"
		|| className == "MyLib/Double"  || className == "MyLib/MyString"
		|| className == "MyLib/Char" || className == "MyLib/Unit"
		|| className == "MyLib/Boolean" || className == "MyLib/Any")
		return true;
	return false;
}

string getPropertyType(const char* propName, const programS* const program, const string& currentClassName) 
{
	string res = "";
	for (auto pe = program->first; pe != 0; pe = pe->next)
	{
		if (pe->clas != 0 && pe->clas->name == currentClassName  && pe->clas->body != 0)
		{
			for (auto cbe = pe->clas->body->first; cbe != 0; cbe = cbe->next)
			{
				if (cbe->property != 0 && strcmp(cbe->property->varOrVal->id, propName) == 0)
				{				
					res = cbe->property->varOrVal->id;
				}
			}
			if (res == "" && pe->clas->parentClassName != 0 && strcmp(pe->clas->parentClassName, "MyLib/Any") != 0)
			{
				res = getPropertyType(propName, program, pe->clas->parentClassName);
			}
		}
	}
	return res;

}

//Является ли метод библиотечным
string isStandartStaticMethod(string methodSign)
{
	if (methodSign == "print(Int|)" || methodSign == "print(Float|)" || methodSign == "print(Double|)"
		|| methodSign == "print(Char|)" || methodSign == "print(MyString|)" || methodSign == "print(Boolean|)"
		|| methodSign == "print(Any|)")
		return "Unit";
	else if (methodSign == "readInt()")	return "Int";
	else if (methodSign == "readLine()") return "MyString";
	else if (methodSign == "readDouble()") return "Double";
	else if (methodSign == "readChar()") return "Char";
	else if (methodSign == "readFloat()") return "Float";
	else if (methodSign == "readBoolean()") return "Boolean";
	else if (methodSign.find("arrayOf(") == 0)
	{
		//??????ЧТо возвращать???
	}
	else return "";

}

string isObjectMethod(string methodSign)
{
	if (methodSign == "toString()") return "String";
	else if (methodSign == "equals(Object)") return "Boolean";
	else return "";
}

string getMethodType(string methodSign, const programS* const program, const string& currentClassName)
{
	if (currentClassName == "")	return "";

	string res = "";
	for (auto pe = program->first; pe != 0; pe = pe->next)
	{
		if (pe->clas != 0 && pe->clas->name == currentClassName && pe->clas->body != 0)
		{
			for (auto cbe = pe->clas->body->first; cbe != 0; cbe = cbe->next)
			{
				if (cbe->method != 0)
				{
					string methodInfo = createShortInfo(cbe->method);
					if (strstr(methodInfo.c_str(), methodSign.c_str()) != 0)
					{
						res = cbe->method->func->delc->type->easyType;
					}
				}
				if (res == "" && pe->clas->parentClassName != 0)
				{
					res = getMethodType(methodSign, program, pe->clas->parentClassName);
				}
			}
		}
	}
	return res;
}


string createShortInfo(propertyS* prop)
{
	string isConstant;
	if (prop->varOrVal->isVal) isConstant = "val";
	else	isConstant = "var";

	return isConstant + string(prop->varOrVal->type->easyType) + "|"
		+ string(prop->varOrVal->id);
}

string createShortInfo(exprS* methodCall)
{

	if (methodCall->type != MethodCall && methodCall->type != MethodCalcExpr 
		&& methodCall->type != ParentMethodCall)
	{
		return "";
	}
	string methInfo = methodCall->stringOrId + '(';

	if (methodCall->factParams != 0)
	{
		for (exprS* e = methodCall->factParams->first; e != 0; e = e->next)
		{
			methInfo += e->exprRes + '|';
		}
	}
	
	return methInfo + ')';
}

string createMethodSignature(methodS* meth)
{
	string methInfo = string(meth->func->delc->name) + '(';

	if (meth->func->delc->params != 0)
	{
		for (formalParamS* fp = meth->func->delc->params->first; fp != 0; fp = fp->next)
		{
			methInfo = methInfo + fp->type->easyType + '|';
		}
	}
	methInfo += ')';
	return methInfo;
}

FieldTableElement::FieldTableElement(uint16_t fieldName, uint16_t descriptor, VisibilityMod vMod, bool isStatic, bool isFinal)
{
	this->fieldName = fieldName;
	this->descriptor = descriptor;
	switch (vMod)
	{
	case _PUBLIC:
		accessFlags |= 0x0001;
		break;
	case _PROTECTED:
		accessFlags |= 0x0004;
		break;
	case _PRIVATE:
		accessFlags |= 0x0002;
		break;
	}
	if (isStatic)	accessFlags |= 0x0008;

	if (isFinal)	accessFlags |= 0x0010;
}

MethodTableElement::MethodTableElement(uint16_t methName, uint16_t descriptor,
	VisibilityMod vMod, bool isFinal, bool isStatic)
{
	this->name = methName;
	this->descriptor = descriptor;
	this->isStatic = isStatic;

	switch (vMod)
	{
	case _PUBLIC:
		accessFlags |= 0x0001;
		break;
	case _PROTECTED:
		accessFlags |= 0x0004;
		break;
	case _PRIVATE:
		accessFlags |= 0x0002;
		break;
	}
	if (isStatic)	accessFlags |= 0x0008;

	if (isFinal)	accessFlags |= 0x0010;
}

bool operator==(const ConstantsTableElement& lhs, const ConstantsTableElement& rhs)
{
	if (lhs.type != rhs.type)
	{
		return false;
	}
	switch (lhs.type) {
	case UTF_8:
		return lhs.value == rhs.value;
	case _INT:
		return lhs.valueI == rhs.valueI;
	case _FLOAT:
		return lhs.valueF == rhs.valueF;
	case _DOUBLE:
		return lhs.valueD == rhs.valueD;
	case _STRING:
	case _CLASS:
		return lhs.refValue[0] == rhs.refValue[0];
	case NAME_AND_TYPE:
		return lhs.refValue[0] == rhs.refValue[0] && lhs.refValue[1] == rhs.refValue[1];
	case METHOD_REF:
	case FIELD_REF:
		return lhs.refValue[0] == rhs.refValue[0] && lhs.refValue[1] == rhs.refValue[1];
	}
}

ClassFile::ClassFile(classS* clas, programS* program)
{
	this->isAbstract = false;
	this->isFinal = clas->mods->iMod == Final;
	this->vMod = translateVisibilityMod(clas->mods->vMod);
	className = clas->name;
	if (clas->parentClassName != 0)	parentClassName = clas->parentClassName;
}

IdT ClassFile::findUtf8OrAdd(std::string const& utf8)
{
	ConstantsTableElement constant(UTF_8, utf8);
	const auto foundIter = std::find(constsTable.begin(), constsTable.end(), constant);
	if (foundIter == constsTable.end())
	{
		constsTable.push_back(constant);
		return constsTable.end() - constsTable.begin() + 1;
	}
	return foundIter - constsTable.begin() + 1;
}

IdT ClassFile::findIntOrAdd(IntT i)
{
	ConstantsTableElement constant(_INT, i);
	const auto foundIter = std::find(constsTable.begin(), constsTable.end(), constant);
	if (foundIter == constsTable.end())
	{
		constsTable.push_back(constant);
		return constsTable.end() - constsTable.begin() + 1;
	}
	return foundIter - constsTable.begin() + 1;
}

IdT ClassFile::findFloatOrAdd(float i)
{
	ConstantsTableElement constant(_FLOAT, i);
	const auto foundIter = std::find(constsTable.begin(), constsTable.end(), constant);
	if (foundIter == constsTable.end())
	{
		constsTable.push_back(constant);
		return constsTable.end() - constsTable.begin() + 1;
	}
	return foundIter - constsTable.begin() + 1;
}

IdT ClassFile::findDoubleOrAdd(double i)
{
	ConstantsTableElement constant(_DOUBLE, i);
	const auto foundIter = std::find(constsTable.begin(), constsTable.end(), constant);
	if (foundIter == constsTable.end())
	{
		constsTable.push_back(constant);
		return constsTable.end() - constsTable.begin() + 1;
	}
	return foundIter - constsTable.begin() + 1;
}

IdT ClassFile::findStringOrAdd(string v)
{
	ConstantsTableElement constant(_STRING, v);
	const auto foundIter = std::find(constsTable.begin(), constsTable.end(), constant);
	if (foundIter == constsTable.end())
	{
		constsTable.push_back(constant);
		return constsTable.end() - constsTable.begin() + 1;
	}
	return foundIter - constsTable.begin() + 1;
}

IdT ClassFile::findClassOrAdd(std::string const& className)
{
	int value[2] = { findUtf8OrAdd(className), 0 };
	ConstantsTableElement constant(_CLASS, value);
	const auto foundIter = std::find(constsTable.begin(), constsTable.end(), constant);
	if (foundIter == constsTable.end())
	{
		constsTable.push_back(constant);
		return constsTable.end() - constsTable.begin() + 1;
	}
	return foundIter - constsTable.begin() + 1;
}

IdT ClassFile::findNameAndTypeOrAdd(std::string const& name, std::string const& type)
{
	int value[2] = { findUtf8OrAdd(name), findUtf8OrAdd(type) };
	ConstantsTableElement constant(NAME_AND_TYPE, value);
	const auto foundIter = std::find(constsTable.begin(), constsTable.end(), constant);
	if (foundIter == constsTable.end())
	{
		constsTable.push_back(constant);
		return constsTable.end() - constsTable.begin() + 1;
	}
	return foundIter - constsTable.begin() + 1;
}

IdT ClassFile::findFieldRefOrAdd(std::string const& className, std::string const& name, std::string const& type)
{

	int value[2] = { findNameAndTypeOrAdd(name, type), findClassOrAdd(className) };
	ConstantsTableElement constant(FIELD_REF, value);
	const auto foundIter = std::find(constsTable.begin(), constsTable.end(), constant);
	if (foundIter == constsTable.end())
	{
		constsTable.push_back(constant);
		return constsTable.end() - constsTable.begin() + 1;
	}
	return foundIter - constsTable.begin() + 1;
}

IdT ClassFile::findMethodRefOrAdd(std::string const& className, std::string const& name, std::string const& type)
{
	int value[2] = { findNameAndTypeOrAdd(name, type), findClassOrAdd(className) };
	ConstantsTableElement constant(METHOD_REF, value);
	const auto foundIter = std::find(constsTable.begin(), constsTable.end(), constant);
	if (foundIter == constsTable.end())
	{
		constsTable.push_back(constant);
		return constsTable.end() - constsTable.begin() + 1;
	}
	return foundIter - constsTable.begin() + 1;
}

string transformMethodCallToDescriptor(exprS* e, const programS* program)
{
	string res = "(";
	if (e->factParams != 0)
	{
		for (exprS* ex = e->factParams->first; ex != 0; ex = ex->next)
		{
			res += transformTypeToDescriptor(ex->exprRes.c_str(), program);
		}
	}
	res += ')' + transformTypeToDescriptor(e->exprRes.c_str(), program);
	return res;
}

string transformTypeToDescriptor(const char* type, const programS* program)
{
	
	if (strcmp(type, "Int") == 0)	return string("I");
	else if (strcmp(type, "Boolean") == 0)	return string("Z");
	else if (strcmp(type, "Double") == 0)	return string("D");
	else if (strcmp(type, "Float") == 0)	return string("F");
	else if (strcmp(type, "Char") == 0)	return string("C");
	else if (strcmp(type, "String") == 0)	return string("Ljava/lang/String;");
	else if (strcmp(type, "Unit") == 0)	return string("V");
	else
	{
		if (isUserClass(type, program))	return string("L") + type + ';';
		else
		{
			string typeName = type;
			int typeNameEndIndex = typeName.find_first_of('[');
			int countOfDementions = (typeName.length() - typeNameEndIndex) / 2;
			string descriptor;
			for (int i = 0; i < countOfDementions; ++i) descriptor.push_back('[');
			typeName = "";
			for (int i = 0; i < typeNameEndIndex; ++i)
			{
				typeName.push_back(type[i]);
			}
			return descriptor + transformTypeToDescriptor(typeName.c_str(), program) + ';';
		}
	}
}


void ClassFile::fillHighLevelObjectsConstants(propertyS* prop, programS* program)
{
	
	uint16_t nameId = findUtf8OrAdd(prop->varOrVal->id);
	
	uint16_t descId = findUtf8OrAdd(transformTypeToDescriptor(prop->varOrVal->type->easyType, 
		program));
	
	FieldTableElement fte(nameId, descId, translateVisibilityMod(prop->mods->vMod), prop->mods->isStatic, 
		prop->varOrVal->isVal);
	
	fieldTable.insert(make_pair(prop->varOrVal->id, fte));
}


void ClassFile::fillHighLevelObjectsConstants(methodS* meth, programS* program)
{
	uint16_t nameId = findUtf8OrAdd(meth->func->delc->name);

	string methodDescr = "(";
	if (meth->func->delc->params != 0)
	{
		for (formalParamS* fp = meth->func->delc->params->first; fp != 0; fp = fp->next)
		{
			methodDescr += transformTypeToDescriptor(fp->type->easyType, program);
		}
	}
	methodDescr = ')';

	methodDescr += transformTypeToDescriptor(meth->func->delc->type->easyType,
		program);
	uint16_t descId = findUtf8OrAdd(methodDescr);
	
	MethodTableElement mte(nameId, descId, translateVisibilityMod(meth->mods->vMod), 
		meth->mods->iMod == Final, meth->mods->isStatic);

	methodTable.insert(make_pair(createShortInfo(meth), mte));
	addConstantsFrom(meth, program);
}

void ClassFile::fillHighLevelObjectsConstants(classS* clas, programS* program)
{
	findUtf8OrAdd("Code");
	thisClass = findClassOrAdd(clas->name);
	if (clas->parentClassName != 0)	superClass = findClassOrAdd(clas->name);
	
	//Заполняю флаги доступа к классу
	accessFlags |= 0x0001; //Устанавливаю флаг PUBLIC
	if (isFinal) accessFlags |= 0x0010; //Устанавливаю флаг FINAL
	accessFlags |= 0x0020; //Устанавливаю флаг SUPER !Он устанавливается для совместимости

	findUtf8OrAdd("<init>");
	findUtf8OrAdd("()V");

	if (clas->body != 0)
	{
		for (auto cbe = clas->body->first; cbe != 0; cbe = cbe->next)
		{
			if (cbe->method != 0)	fillHighLevelObjectsConstants(cbe->method, program);
			else if (cbe->property != 0) fillHighLevelObjectsConstants(cbe->property, program);
		}
	}
}



//Привести типы для базовых типов без использования методов valueOf и to<Type>
void castType(exprS* e1, string type)
{
	exprS* newE = createExprCopy(e1);
	e1->exprRes = type;
	e1->type = TypeCast;
	e1->left = newE;
	e1->right = 0;
	e1->factParams = 0;
	e1->stringOrId = 0;
	e1->charV = 0;
	e1->intV = 0;
	e1->floatV = 0;
	e1->doubleV = 0;
	e1->varInTableNum = -1;
	e1->isStaticCall = 0;
	e1->refInfo = -1;
}


void ClassFile::transformTypeCastToValueOf(exprS* e, const char* staticClassName)
{
	e->type = MethodCalcExpr;
	e->exprRes = staticClassName;
	e->isStaticCall = true;
	e->factParams = createFactParamsList(e->left);
	char* tmp = new char[strlen("valueOf") + 1];
	strcpy(tmp, "valueOf");
	e->stringOrId = tmp;
	tmp = new char[strlen(staticClassName) + 1];
	strcpy(tmp, staticClassName);
	e->left = createExpr(tmp, Identificator);
	e->left->exprRes = tmp;
	e->left->exprRes = staticClassName;	
}

bool ClassFile::transformKotlinTypeCastOperators(exprS* e)
{
	//меняем операции строк на аналогичные в Java
	if (e->left->exprRes == "String")
	{
		if (strcmp(e->right->stringOrId, "toInt") == 0)
		{
			transformTypeCastToValueOf(e, "Int");
			e->refInfo = findMethodRefOrAdd("java/lang/Integer", "Integer", "(Ljava/lang/String;)I");
		}
		else if (strcmp(e->right->stringOrId, "toFloat") == 0)
		{
			transformTypeCastToValueOf(e, "Float");
			e->refInfo = findMethodRefOrAdd("java/lang/Float", "valueOf", "(Ljava/lang/String;)F");
		}
		else if (strcmp(e->right->stringOrId, "toDouble") == 0)
		{
			transformTypeCastToValueOf(e, "Double");
			e->refInfo = findMethodRefOrAdd("java/lang/Double", "valueOf", "(Ljava/lang/String;)D");
		}
		else if (strcmp(e->right->stringOrId, "toBoolean") == 0)
		{
			transformTypeCastToValueOf(e, "Boolean");
			e->refInfo = findMethodRefOrAdd("java/lang/Boolean", "valueOf", "(Ljava/lang/String;)Z");
		}
		else if (strcmp(e->right->stringOrId, "toString") == 0)
		{
			e->type = String;
			e->stringOrId = e->left->stringOrId;
			e->exprRes = "String";
			e->refInfo = findStringOrAdd(e->stringOrId);
		}
		else
		{
			return false;
		}
	}
	else if (e->left->exprRes == "Int")
	{
		if (strcmp(e->right->stringOrId, "toInt") == 0)
		{
			e->type = Int;
			e->intV = e->left->intV;
			e->exprRes = "Int";
			e->refInfo = findIntOrAdd(e->intV);
		}
		else if (strcmp(e->right->stringOrId, "toFloat") == 0)
		{
			e->type = Int;
			e->intV = e->left->intV;
			e->exprRes = "Int";
			e->refInfo = findIntOrAdd(e->intV);
			castType(e, "Float");
		}
		else if (strcmp(e->right->stringOrId, "toDouble") == 0)
		{
			e->type = Int;
			e->intV = e->left->intV;
			e->exprRes = "Int";
			e->refInfo = findIntOrAdd(e->intV);
			castType(e, "Double");
		}
		else if (strcmp(e->right->stringOrId, "toString") == 0)
		{
			transformTypeCastToValueOf(e, "String");
			e->refInfo = findMethodRefOrAdd("java/lang/String", "valueOf", "(I)Ljava/lang/String;");
		}
		else if (strcmp(e->right->stringOrId, "toChar") == 0)
		{
			e->type = Int;
			e->intV = e->left->intV;
			e->exprRes = "Int";
			e->refInfo = findIntOrAdd(e->intV);
			castType(e, "Char");
		}
		else
		{
			return false;
		}
	}
	else if (e->left->exprRes == "Float")
	{
		if (strcmp(e->right->stringOrId, "toInt") == 0)
		{
			e->type = Float;
			e->floatV = e->left->floatV;
			e->exprRes = "Float";
			e->refInfo = findFloatOrAdd(e->floatV);
			castType(e, "Int");
		}
		else if (strcmp(e->right->stringOrId, "toFloat") == 0)
		{
			e->type = Float;
			e->floatV = e->left->floatV;
			e->exprRes = "Float";
			e->refInfo = findFloatOrAdd(e->floatV);
		}
		else if (strcmp(e->right->stringOrId, "toDouble") == 0)
		{
			e->type = Float;
			e->floatV = e->left->floatV;
			e->exprRes = "Float";
			e->refInfo = findFloatOrAdd(e->floatV);
			castType(e, "Double");
		}
		else if (strcmp(e->right->stringOrId, "toString") == 0)
		{
			transformTypeCastToValueOf(e, "String");
			e->refInfo = findMethodRefOrAdd("java/lang/String", "valueOf", "(F)Ljava/lang/String;");
		}
		else if (strcmp(e->right->stringOrId, "toChar") == 0)
		{
			e->type = Float;
			e->floatV = e->left->floatV;
			e->exprRes = "Float";
			e->refInfo = findFloatOrAdd(e->floatV);
			castType(e, "Int");
			castType(e, "Char");
		}
		else
		{
			return false;
		}
	}
	else if (e->left->exprRes == "Double")
	{
		if (strcmp(e->right->stringOrId, "toInt") == 0)
		{
			e->type = Double;
			e->doubleV = e->left->doubleV;
			e->exprRes = "Double";
			e->refInfo = findDoubleOrAdd(e->doubleV);
			castType(e, "Int");
		}
		else if (strcmp(e->right->stringOrId, "toFloat") == 0)
		{
			e->type = Double;
			e->doubleV = e->left->doubleV;
			e->exprRes = "Double";
			e->refInfo = findDoubleOrAdd(e->doubleV);
			castType(e, "Float");
		}
		else if (strcmp(e->right->stringOrId, "toDouble") == 0)
		{
			e->type = Double;
			e->doubleV = e->left->doubleV;
			e->exprRes = "Double";
			e->refInfo = findDoubleOrAdd(e->doubleV);
		}
		else if (strcmp(e->right->stringOrId, "toString") == 0)
		{
			transformTypeCastToValueOf(e, "String");
			e->refInfo = findMethodRefOrAdd("java/lang/String", "valueOf", "(D)Ljava/lang/String;");
		}
		else if (strcmp(e->right->stringOrId, "toChar") == 0)
		{
			e->type = Double;
			e->doubleV = e->left->doubleV;
			e->exprRes = "Double";
			e->refInfo = findDoubleOrAdd(e->doubleV);
			castType(e, "Int");
			castType(e, "Char");
		}
		else
		{
			return false;
		}
	}
	else if (e->left->exprRes == "Boolean")
	{
		if (strcmp(e->right->stringOrId, "toString") == 0)
		{
			transformTypeCastToValueOf(e, "String");
			e->refInfo = findMethodRefOrAdd("java/lang/String", "valueOf", "(Z)Ljava/lang/String;");
		}
		else
		{
			return false;
		}
	}
	else if (e->left->exprRes == "Char")
	{
		if (strcmp(e->right->stringOrId, "toInt") == 0)
		{
			e->type = Char;
			e->charV = e->left->charV;
			e->exprRes = "Char";
			castType(e, "Int");
		}
		else if (strcmp(e->right->stringOrId, "toFloat") == 0)
		{
			e->type = Char;
			e->charV = e->left->charV;
			e->exprRes = "Char";
			castType(e, "Int");
			castType(e, "Float");
		}
		else if (strcmp(e->right->stringOrId, "toDouble") == 0)
		{
			e->type = Char;
			e->charV = e->left->charV;
			e->exprRes = "Char";
			castType(e, "Int");
			castType(e, "Double");
		}
		else if (strcmp(e->right->stringOrId, "toString") == 0)
		{
			transformTypeCastToValueOf(e, "String");
			e->refInfo = findMethodRefOrAdd("java/lang/String", "valueOf", "(C)Ljava/lang/String;");
		}
		else if (strcmp(e->right->stringOrId, "toChar") == 0)
		{
			e->type = Char;
			e->charV = e->left->charV;
			e->exprRes = "Char";
		}
		else
		{
			return false;
		}
	}

	return true;
}


void castType(exprS* e1)
{

}

int ClassFile::calcType(factParamsList* fpl, programS* program, string& methodKey)
{
	int paramsCount = 0;
	if (fpl != 0)
	{
		for (auto fp = fpl->first; fp != 0; fp = fp->next)
		{
			++paramsCount;
			calcType(fp, program, methodKey);
		}
	}
	return paramsCount;
}

int isComponent(const char* methodName) 
{
	if (strcmp(methodName, "component1") == 0)
	{
		return 1;
	}
	else if (strcmp(methodName, "component2") == 0)
	{
		return 2;
	}
	else if (strcmp(methodName, "component3") == 0)
	{
		return 3;
	}
	else if (strcmp(methodName, "component4") == 0)
	{
		return 4;
	}
	else if (strcmp(methodName, "component5") == 0)
	{
		return 5;
	}
	else
	{
		return 0;
	}
}

void ClassFile::convertToJavaBasicTypeClass(exprS* e)
{
	string clName = "";
	string exprRes = "";
	string descriptor = "";
	if (e->exprRes == "Int")
	{
		clName = "Integer";
		exprRes = "Int";
		descriptor = "I";
	}
	else if (e->exprRes == "Float")
	{
		clName = "Float";
		exprRes = "Float";
		descriptor = "F";
	}
	else if (e->exprRes == "Double")
	{
		clName = "Double";
		exprRes = "Double";
		descriptor = "D";
	}
	else if (e->exprRes == "Boolean")
	{
		clName = "Boolean";
		exprRes = "Boolean";
		descriptor = "Z";
	}
	else if (e->exprRes == "Char")
	{
		clName = "Character";
		exprRes = "Char";
		descriptor = "C";
	}
	else
	{
		return;
	}
	e->factParams = createFactParamsList(createExprCopy(e));
	e->type = MethodCalcExpr;
	char* tmp = new char[strlen("valueOf") + 1];
	strcpy(tmp, "valueOf");
	e->stringOrId = tmp;
	e->exprRes = exprRes;
	e->isStaticCall = true;
	tmp = new char[clName.size() + 1];
	strcpy(tmp, clName.c_str());
	e->left = createExpr(tmp, Identificator);
	e->left->exprRes = exprRes;
	e->refInfo = findMethodRefOrAdd("java/lang/" + clName, "valueOf", '(' + descriptor + ")Ljava/lang/" + clName + ';');
	e->varInTableNum = -1;
}

bool isUserClass(const char* name, const list<string>& classesNames)
{
	bool res = false;

	for (auto clName : classesNames)
	{
		if (name == clName && name != "Main$")	res = true;
	}

	return res;
}

bool isUserClass(const char* name, const programS * const program)
{

	bool res = false;

	for (auto pe = program->first; pe != 0 && res == false; pe = pe->next)
	{
		if (pe->clas != 0 && strcmp(name, pe->clas->name) == 0 
			&& strcmp(name, "Main$") != 0)
		{
			res = true;
		}
	}

	return res;
}

bool checkUnitOperandsInExpr(exprS* e, const string& methodKey)
{
	if (e->factParams != 0)
	{
		for (auto fp = e->factParams->first; fp != 0; fp = fp->next)
		{
			if (fp->exprRes == "Unit")
			{
				char message[200] = "EXCEPTION! Incorrect operand with UNIT (void) type in method - ";
				exception e(strcat(message, methodKey.c_str()));
				throw e;
			}
		}
	}
	if (e->left != 0 && e->left->exprRes == "Unit" 
		|| e->right != 0 && e->right->exprRes == "Unit")
	{
		char message[200] = "EXCEPTION! Incorrect operand with UNIT (void) type in method - ";
		exception e(strcat(message, methodKey.c_str()));
		throw e;
	}
}

void ClassFile::addToStringCall(exprS* e, programS* program)
{
	exprS* newE = createExprCopy(e);
	e->type = MethodCalcExpr;
	char* tmp = new char[strlen("toString") + 1];
	strcpy(tmp, "toString");
	e->stringOrId = tmp;
	e->left = newE;
	e->factParams = 0;

	string basicToStringClass;
	if (strstr(newE->exprRes.c_str(), "[]") != 0)
	{
		basicToStringClass = "java/lang/Object";
	}
	else
	{
		basicToStringClass = newE->exprRes;
	}
	e->exprRes = "String";
	e->refInfo = findMethodRefOrAdd(basicToStringClass, "toString", "()Ljava/lang/String;");
}

void ClassFile::calcType(exprS* e1, programS* program, string& methodKey)
{
	if (e1->type == Identificator)
	{
		MethodTableElement method = methodTable.at(methodKey);
		e1->varInTableNum = method.find(e1->stringOrId);
		string res;
		if (e1->varInTableNum == -1)
		{
			res = getPropertyType(e1->stringOrId, program, className);
			if (res == "")
			{
				res = getPropertyType(e1->stringOrId, program, "Main$");
				if (res == "")
				{
					char message[200] = "EXCEPTION! Undefined variable or property name \"";
					exception e((strcat(strcat(message, e1->stringOrId), "\"")));
					throw e;
				}
				e1->isStaticCall = true;
				e1->refInfo = findFieldRefOrAdd("Main$", e1->stringOrId, transformTypeToDescriptor(res.c_str(), program));
			}
			else	e1->refInfo = findFieldRefOrAdd(className, e1->stringOrId, transformTypeToDescriptor(res.c_str(), program));
		}
		else
		{
			res = method.find(e1->varInTableNum).type;
			
		}
		e1->exprRes = res;
	}
	else if (e1->type == This)
	{
		auto method = methodTable.at(methodKey);
		if (method.isStatic)
		{
			char message[200] = "EXCEPTION! Call THIS in static method \"";
			exception e((strcat(strcat(message, methodKey.c_str()), "\"")));
			throw e;
		}
		e1->varInTableNum = 0;
		e1->exprRes = method.find(0).type;
	}
	else if (e1->type == MethodCall)
	{
		//Рассчитать типы для параметров
		int paramsCount = calcType(e1->factParams, program, methodKey);
		checkUnitOperandsInExpr(e1, methodKey);

		//Проверка на методы equals and toString()
		if (className != "Main$")	//Если вызов вне статического класса
		{
			if (strcmp(e1->stringOrId, "equals") && paramsCount == 1)
			{
				if (isMyStandartClass(e1->factParams->first->exprRes))
				{
					convertToJavaBasicTypeClass(e1->factParams->first);
				}
				e1->varInTableNum = 0;
				e1->exprRes = "Boolean";
				e1->refInfo = findMethodRefOrAdd(className, "equals",
					"(Ljava/lang/Object;)Z");
			}
			else if (strcmp(e1->stringOrId, "toString") && paramsCount == 0)
			{
				e1->varInTableNum = 0;
				e1->exprRes = "String";
				e1->refInfo = findMethodRefOrAdd(className, "equals",
					"()Ljava/lang/String;");
			}
		}
		
		if (e1->exprRes == "")
		{
			//Проверить, существует ли такой метод
			string res = getMethodType(createShortInfo(e1), program, className);

			if (res == "")
			{
				//Вызов конструктора
				if (isUserClass(e1->stringOrId, program) && paramsCount == 0)
				{
					e1->type = ConstructorCall;
					e1->exprRes = e1->stringOrId;
					e1->refInfo = findMethodRefOrAdd(e1->stringOrId, "<init>", "()V");
				}
				else
				{
					//Вызов глобального метода
					res = getMethodType(createShortInfo(e1), program, "Main$");
					if (res == "")
					{
						//Вызов метода моей библиотеки
						res = isStandartStaticMethod(createShortInfo(e1));
						if (res == "")
						{
							char message[200] = "EXCEPTION! Call of unknown method \"";
							exception e((strcat(strcat(message, methodKey.c_str()), "\"")));
							throw e;
						}
						e1->exprRes = res;
						e1->refInfo = findMethodRefOrAdd("MyLib/MyIO", e1->stringOrId,
							transformMethodCallToDescriptor(e1, program));
					}
					else
					{
						e1->exprRes = res;
						e1->refInfo = findMethodRefOrAdd("Main$", e1->stringOrId,
							transformMethodCallToDescriptor(e1, program));
					}

					e1->isStaticCall = true;
				}				
			}
			else
			{
				e1->varInTableNum = 0;
				e1->exprRes = res;
				e1->refInfo = findMethodRefOrAdd(className, e1->stringOrId,
					transformMethodCallToDescriptor(e1, program));
			}
		}

	}
	else if (e1->type == FieldCalcExpr)
	{
		calcType(e1->left, program, methodKey);
		checkUnitOperandsInExpr(e1, methodKey);
		//Найти поле в классе
		string res = getPropertyType(e1->stringOrId, program, e1->left->exprRes);
		if (res == "")
		{
			//Если пользователь хочет узнать длину массива
			if (strstr(e1->left->exprRes.c_str(), "[]") != 0 && strcmp(e1->stringOrId, "size"))
			{
				char* tmp = new char[strlen("length") + 1];
				strcpy(tmp, "length");
				e1->stringOrId = tmp;
				e1->exprRes = "Int";
			}
			else if (e1->left->exprRes == "String" && strcmp(e1->stringOrId, "length"))
			{
				e1->type = MethodCalcExpr;
				e1->exprRes = "Int";
				e1->refInfo = findMethodRefOrAdd("java/lang/String", "length", "()I");
			}
			else
			{
				char message[200] = "EXCEPTION! Call of unknown field \"";
				exception e(strcat(strcat(strcat(message, methodKey.c_str()), "\" in method - "),
					methodKey.c_str()));
				throw e;
			}			
		}
		else
		{
			e1->exprRes = res;
			e1->refInfo = findFieldRefOrAdd(e1->left->exprRes, e1->stringOrId,
				transformTypeToDescriptor(res.c_str(), program));
		}
		
	}
	else if (e1->type == MethodCalcExpr)
	{
		int paramsCount = calcType(e1->factParams, program, methodKey);
		calcType(e1->left, program, methodKey);
		checkUnitOperandsInExpr(e1, methodKey);
		
		string res = getMethodType(createShortInfo(e1), program, className);
		//Если метод у объекта такого типа существует:
		if (res != "")
		{
			e1->exprRes = res;
			e1->refInfo = findMethodRefOrAdd(e1->left->exprRes, e1->stringOrId,
				transformMethodCallToDescriptor(e1, program));
		}
		//Обращение к методу equals
		else if (strcmp(e1->stringOrId, "equals") == 0 && paramsCount == 1)
		{
			if (isMyStandartClass(e1->left->exprRes))
			{
				convertToJavaBasicTypeClass(e1->left);
			}
			if (isMyStandartClass(e1->factParams->first->exprRes))
			{
				convertToJavaBasicTypeClass(e1->factParams->first);
			}
			e1->exprRes = "Boolean";
			e1->refInfo = findMethodRefOrAdd(e1->left->exprRes, "equals",
				"(Ljava/lang/Object;)Z");
		}
		//Если объект - базовый класс Kotlin + toString для базовых типов
		else if (isMyStandartClass(e1->left->exprRes))
		{
			if (e1->left->exprRes == "String" && strcmp(e1->stringOrId, "get") == 0 
				&& paramsCount == 1 && e1->factParams->first->exprRes == "Integer")
			{
				char* tmp = new char[strlen("charAt") + 1];
				strcpy(tmp, "charAt");
				e1->stringOrId = tmp;
				e1->refInfo = findMethodRefOrAdd("java/lang/String", e1->stringOrId,
					"(I)C");
			}
			else if (!transformKotlinTypeCastOperators(e1))
			{
				char message[200] = "EXCEPTION! Call of unknown method \"";
				exception e(strcat(strcat(strcat(message, e1->stringOrId), "\" in method - "), 
					methodKey.c_str()));
				throw e;
			}
		}
		//Обращение к методу toString для нестандартных классов
		else if (strcmp(e1->stringOrId, "toString") == 0 && paramsCount == 0)
		{
			e1->exprRes = "String";
			string basicToStringClass = e1->left->exprRes;
			if (strstr(e1->left->exprRes.c_str(), "[]") != 0)
			{
				basicToStringClass = "java/lang/Object";
			}
			e1->refInfo = findMethodRefOrAdd(e1->left->exprRes, "toString",
				"()Ljava/lang/String;");
		}
		//Если объект массив и у него берут одну из компонент
		else if (strstr(e1->left->exprRes.c_str(), "[]") != 0
			&& paramsCount == 0)
		{
			int componntNum = isComponent(e1->stringOrId);
			if (componntNum != 0)
			{
				e1->type = ArrayElementCall;
				e1->right = createExpr(componntNum - 1, Int);
				e1->stringOrId = 0;
			}
			else
			{
				char message[200] = "EXCEPTION! Call of incorrect component method \"";
				exception e(strcat(strcat(strcat(message, e1->stringOrId), "\" in method - "),
					methodKey.c_str()));
				throw e;
			}
		}
		else
		{
			char message[200] = "EXCEPTION! Call of unknown method \"";
			exception e(strcat(strcat(strcat(message, e1->right->stringOrId), "\" in method - "),
				methodKey.c_str()));
			throw e;
		}
	}
	else if (e1->type == ArrayElementCall)
	{
		calcType(e1->left, program, methodKey);
		calcType(e1->right, program, methodKey);
		if (e1->right->exprRes == "Int")
		{
			if (strstr(e1->left->exprRes.c_str(), "[]") != 0)
			{
				//В возвращаемом значении уменьшить количество []
				string res = e1->left->exprRes;
				res.pop_back();
				res.pop_back();
				e1->exprRes = res;
			}
			else if (e1->left->exprRes == "String")
			{
				e1->factParams = createFactParamsList(e1->right);
				e1->right->stringOrId = 0;
				e1->right = 0;
				char* tmp = new char[strlen("charAt") + 1];
				strcpy(tmp, "charAt");
				e1->stringOrId = tmp;
				e1->exprRes = "Char";
				e1->refInfo = findMethodRefOrAdd("java/lang/String", tmp, "(I)C");
			}
			else
			{
				char message[200] = "EXCEPTION! Try to get index of not array or string object in method \"";
				exception e(strcat(strcat(message, methodKey.c_str()), "\""));
				throw e;
			}
		}
		else 
		{
			char message[200] = "EXCEPTION! Not integer index  in method \"";
			exception e(strcat(strcat(message, methodKey.c_str()), "\""));
			throw e;
		}
	}
	else if (e1->type == ParentFieldCall)
	{
		if (parentClassName == "")
		{
			char message[200] = "EXCEPTION! Call of unknown parent field \"";
			exception e(strcat(strcat(strcat(message, methodKey.c_str()), "\" in method - "),
				methodKey.c_str()));
			throw e;
		}

		//Найти поле в классе
		string res = getPropertyType(e1->stringOrId, program, parentClassName);
		if (res == "")
		{
			char message[200] = "EXCEPTION! Call of unknown parent field \"";
			exception e(strcat(strcat(strcat(message, methodKey.c_str()), "\" in method - "),
				methodKey.c_str()));
			throw e;
		}
		e1->exprRes = res;
		e1->refInfo = findFieldRefOrAdd(parentClassName, e1->stringOrId,
			transformTypeToDescriptor(res.c_str(), program));
		e1->varInTableNum = 0;
	}
	else if (e1->type == ParentMethodCall)
	{
		int paramsCount = calcType(e1->factParams, program, methodKey);
		checkUnitOperandsInExpr(e1, methodKey);

		e1->varInTableNum = 0;
		//Если метод equals
		if (strcmp(e1->stringOrId, "equals") == 0 && paramsCount == 1)
		{
			if (isMyStandartClass(e1->factParams->first->exprRes))
			{
				convertToJavaBasicTypeClass(e1->factParams->first);
			}
			e1->exprRes = "Boolean";
			e1->refInfo = findMethodRefOrAdd(parentClassName, "equals",
				"(Ljava/lang/Object;)Z");
		}
		//Если метод toString
		else if(strcmp(e1->stringOrId, "toString") == 0 && paramsCount == 0)
		{
			e1->exprRes = "String";
			e1->refInfo = findMethodRefOrAdd(parentClassName, "equals",
				"()Ljava/lang/String;");
		}
		//Если метод у объекта такого типа существует:
		else
		{
			string res = getMethodType(createShortInfo(e1), program, parentClassName);
			if (res != "")
			{
				e1->exprRes = res;
				e1->refInfo = findMethodRefOrAdd(parentClassName, e1->stringOrId,
					transformMethodCallToDescriptor(e1, program));
			}
			else
			{
				char message[200] = "EXCEPTION! Call of unknown parent method \"";
				exception e(strcat(strcat(strcat(message, e1->stringOrId), "\" in method - "),
					methodKey.c_str()));
				throw e;
			}
		}
	}
	else if (e1->type == Int)
	{
		e1->exprRes = "Int";
		e1->refInfo = findIntOrAdd(e1->intV);
	}
	else if (e1->type == Double)
	{
		e1->exprRes = "Double";
		e1->refInfo = findDoubleOrAdd(e1->doubleV);
	}
	else if (e1->type == Float)
	{
		e1->exprRes = "Float";
		e1->refInfo = findFloatOrAdd(e1->floatV);
	}
	else if (e1->type == String)
	{
		e1->exprRes = "String";
		e1->refInfo = findStringOrAdd(e1->stringOrId);
	}
	else if (e1->type == Char)
	{
		e1->exprRes = "Char";
	}
	else if (e1->type == Boolean)
	{
		e1->exprRes = "Boolean";
	}
	else if (e1->type == Range)
	{
		char message[200] = "EXCEPTION! Unsupported range out of For loop in method - ";
		exception e(strcat(message,methodKey.c_str()));
		throw e;
	}
	else if (e1->type == LogicalNot)
	{
		calcType(e1->left, program, methodKey);
		if (e1->left->exprRes != "Boolean")
		{
			char message[200] = "EXCEPTION! Incorrect operator! operand with not boolean type in method - ";
			exception e(strcat(message, methodKey.c_str()));
			throw e;
		}
		e1->exprRes = "Boolean";
	}
	else if (e1->type == UnaryPlusExpr || e1->type == UnaryMinusExpr)
	{
		calcType(e1->left, program, methodKey);

		if (e1->left->exprRes != "Int" && e1->left->exprRes != "Double" && e1->left->exprRes != "Float")
		{
			char message[200] = "EXCEPTION! Incorrect operator+ (unary) operand with not number type in method - ";
			exception e(strcat(message, methodKey.c_str()));
			throw e;
		}
		e1->exprRes = e1->left->exprRes;
	}
	else if (e1->type == Sum)
	{
		calcType(e1->left, program, methodKey);
		calcType(e1->right, program, methodKey);
		checkUnitOperandsInExpr(e1, methodKey);

		if (e1->left->exprRes == "String")
		{
			if (e1->right->exprRes != "String");
			{
				if (isMyStandartClass(e1->right->exprRes))
				{ 
					convertBasicTypeExprToString(e1->right);
				}
				else
				{
					addToStringCall(e1, program);
				}
			}
			e1->type = MethodCalcExpr;
			e1->exprRes = "String";
			char* tmp = new char[strlen("concat") + 1];
			strcpy(tmp, "concat");
			e1->stringOrId = tmp;
			e1->factParams = createFactParamsList(e1->right);
			e1->right = 0;
			e1->refInfo = findMethodRefOrAdd("java/lang/String", "concat", "(Ljava/lang/String;)Ljava/lang/String;");
		}
		else if (e1->left->exprRes == "Int")
		{
			if (e1->right->exprRes == "Float" || e1->right->exprRes == "Double")
			{
				castType(e1->left, e1->right->exprRes);
			}
			else if(e1->right->exprRes != "Int")
			{
				char message[200] = "EXCEPTION! Incorrect operator+ right operand with type";
				exception e(strcat(strcat(strcat(message, e1->right->exprRes.c_str()), 
					" in method - "), methodKey.c_str()));
				throw e;
			}
			e1->exprRes = e1->right->exprRes;
		}
		else if (e1->left->exprRes == "Char")
		{
			if (e1->right->exprRes == "String")
			{
				convertBasicTypeExprToString(e1->left);
				e1->type = MethodCalcExpr;
				e1->exprRes = "String";
				char* tmp = new char[strlen("concat") + 1];
				strcpy(tmp, "concat");
				e1->stringOrId = tmp;
				e1->factParams = createFactParamsList(e1->right);
				e1->right = 0;
				e1->refInfo = findMethodRefOrAdd("java/lang/String", "concat", "(Ljava/lang/String;)Ljava/lang/String;");
			}
			else if (e1->right->exprRes != "Int")
			{
				char message[200] = "EXCEPTION! Incorrect operator+ right operand with type";
				exception e(strcat(strcat(strcat(message, e1->right->exprRes.c_str()),
					" in method - "), methodKey.c_str()));
				throw e;
			}
			else
			{
				castType(e1->left, "Int");
				e1->exprRes = "Int";
				castType(e1, "Char");
			}			
		}
		else if (e1->left->exprRes == "Float")
		{
			if (e1->right->exprRes == "Double")
			{
				castType(e1->left, "Double");
				e1->exprRes = "Double";
			}
			else if (e1->right->exprRes == "Int")
			{
				castType(e1->right, "Float");
				e1->exprRes = "Float";
			}
			else if (e1->right->exprRes == "Float")
			{
				e1->exprRes = "Float";
			}
			else
			{
				char message[200] = "EXCEPTION! Incorrect operator+ right operand with type";
				exception e(strcat(strcat(strcat(message, e1->right->exprRes.c_str()),
					" in method - "), methodKey.c_str()));
				throw e;
			}
		}
		else if (e1->left->exprRes == "Double")
		{
			if (e1->right->exprRes == "Float" || e1->right->exprRes == "Int")
			{
				castType(e1->right, e1->left->exprRes);
			}
			else if (e1->right->exprRes != "Double")
			{
				char message[200] = "EXCEPTION! Incorrect operator+ right operand with type";
				exception e(strcat(strcat(strcat(message, e1->right->exprRes.c_str()),
					" in method - "), methodKey.c_str()));
				throw e;
			}
			e1->exprRes = e1->left->exprRes;
		}
		else
		{
			char message[200] = "EXCEPTION! Incorrect operator+ left operand with type";
			exception e(strcat(strcat(strcat(message, e1->left->exprRes.c_str()),
				" in method - "), methodKey.c_str()));
		}
	}
	else if (e1->type == Sub)
	{
		calcType(e1->left, program, methodKey);
		calcType(e1->right, program, methodKey);
		checkUnitOperandsInExpr(e1, methodKey);
		
		if (e1->left->exprRes == "")
		{

		}
	}
	else if (e1->type == Mul)
	{

	}
	else if (e1->type == Div)
	{

	}
	else if (e1->type == Mod)
	{

	}
	else if (e1->type == Less)
	{

	}
	else if (e1->type == More)
	{

	}
	else if (e1->type == Or)
	{

	}
	else if (e1->type == And)
	{

	}
	else if (e1->type == Eq)
	{

	}
	else if (e1->type == Neq)
	{

	}
	else if (e1->type == Loeq)
	{

	}
	else if (e1->type == Moeq)
	{

	}
}

//type1 - к чему приводить, type2 - что приводить, return - тип к которому можно привести
bool canCastType(const char* type1, const char* type2)
{
	if (strcmp(type1, type2) == 0)
		return true;

	if (strcmp(type1, "Float") == 0 && strcmp(type1, "Int") || strcmp(type1, "Int") == 0 && strcmp(type1, "Float"))
		return true;
	
	if (strcmp(type1, "Double") == 0 && strcmp(type1, "Int") || strcmp(type1, "Int") == 0 && strcmp(type1, "Double"))
		return true;

	if (strcmp(type1, "Double") == 0 && strcmp(type1, "Float") || strcmp(type1, "Float") == 0 && strcmp(type1, "Double"))
		return true;

	if (strcmp(type1, "Double") == 0 && strcmp(type1, "Float") || strcmp(type1, "Float") == 0 && strcmp(type1, "Double"))
		return true;

	return false;
}

void ClassFile::convertBasicTypeExprToString(exprS* e)
{
	string descr = "(";
	if (e->exprRes == "Int")
	{
		descr += "I";
	}
	else if (e->exprRes != "Float")
	{
		descr += "F";
	}
	else if (e->exprRes != "Double")
	{
		descr += "D";
	}
	else if (e->exprRes != "Char")
	{
		descr += "C";
	}
	else if (e->exprRes != "Boolean")
	{
		descr += "Z";
	}
	else
	{
		return;
	}
	descr += ')';

	e->factParams = createFactParamsList(createExprCopy(e));
	e->type = MethodCalcExpr;
	e->exprRes = "String";
	e->isStaticCall = true;
	char* tmp = new char[strlen("valueOf") + 1];
	strcpy(tmp, "valueOf");
	e->stringOrId = tmp;
	tmp = new char[strlen("String") + 1];
	strcpy(tmp, "String");
	e->left = createExpr(tmp, Identificator);
	e->left->exprRes = tmp;
	e->left->exprRes = "String";
	e->refInfo = findMethodRefOrAdd("java/lang/String", "valueOf", descr + "Ljava/lang/String;");
}

void ClassFile::addConstantsFrom(varOrValDeclS* v, programS* program, string methodKey)
{
	MethodTableElement res = methodTable.at(methodKey);
	if (res.addLocalVar(v))
	{
		char message[200] = "EXCEPTION! Redefine of variable \"";
		exception e((strcat(strcat(message, v->id), "\"")));
		throw e;
	}
	if (v->initValue != 0)
	{
		addConstantsFrom(v->initValue, program, methodKey);
		if (strcmp(v->type->easyType, v->initValue->exprRes.c_str()) != 0)
		{
			if (canCastType(v->type->easyType, v->initValue->exprRes.c_str()))
			{
				//Создать узел с новым типом
			}
			else
			{
				char message[300] = "EXCEPTION! Cast error. Cannot cast \"";
				exception e(strcat(strcat(strcat(strcat(strcat(strcat(message, v->type->easyType), 
					"\" of variable \""), v->id), "\" to type \""), v->initValue->exprRes.c_str()), "\""));
				throw e;
			}
		}
	}
	
}


void ClassFile::addConstantsFrom(assignmentS* a, programS* program, string methodKey)
{
	if (a->left->type != Identificator && a->subLeft == 0)
	{
		char message[100] = "EXCEPTION! Not l-value expr in assignment \"";
		exception e(message);
		throw e;
	}
	addConstantsFrom(a->left, program, methodKey);
	addConstantsFrom(a->right, program, methodKey);

	if (a->subLeft == 0)
	{
		if (a->left->exprRes != a->right->exprRes)
		{
			if (canCastType(a->left->exprRes.c_str(), a->right->exprRes.c_str()))
			{
				//Создать узел с новым типом
			}
			else
			{
				char message[300] = "EXCEPTION! Cast error. Cannot cast \"";
				exception e(strcat(strcat(strcat(strcat(message, a->left->exprRes.c_str()),
					"\" to type \""), a->right->exprRes.c_str()), "\" in assignment"));
				throw e;
			}
		}
	}
	else
	{
		if (a->type == AssignToField || a->type == AsumToField || a->type == AsubToField
			|| a->type == AdivToField || a->type == AmulToField || a->type == AmodToField)
		{
			//Найти поле в классе
			//Если есть, создаем fieldRef
			//Если нет - ошибка - обращение к несуществующему полю
			
		}
		else
		{
			if (a->subLeft->exprRes != "Int")
			{
				char message[300] = "EXCEPTION! Not integer array index in assignment ";
				exception e(message);
				throw e;
			}

			//Сравнить тип левой части без [] с правой частью
			//Если не равны, то привести
				//Если не равны опять - ошибка
		}
	}
}

void ClassFile::addConstantsFrom(whileLoopS* w, programS* program, string methodKey)
{
	//Проверить условие цикла
	//Проверить все stmt цикла
}

void ClassFile::addConstantsFrom(forLoopS* f, programS* program, string methodKey)
{
	//Проверить переменную
	//Проверить условие
	//Проверить все stmt цикла
}

void ClassFile::addConstantsFrom(ifStmtS* i, programS* program, string methodKey)
{
	//Проверить условие
	//Проверить все ветви
}


void ClassFile::addConstantsFrom(exprS* e, programS* program, string methodKey)
{
	//Собрать инфу для таблицы
	//Преобразовать типы

}

void ClassFile::addConstantsFrom(stmtS* stmt, programS* program, string methodKey)
{

	if (stmt->type == Continue)
	{
		exception e("EXCEPTION! Unsupported CONTINUE operator");
		throw e;
	}
		
	switch (stmt->type)
	{
	case VarOrVal:
		addConstantsFrom(stmt->varOrVal, program, methodKey);
		break;
	case Assignment:
		addConstantsFrom(stmt->assignment, program, methodKey);
		break;
	case WhileLoop:
		addConstantsFrom(stmt->whileLoop, program, methodKey);
		break;
	case ForLoop:
		addConstantsFrom(stmt->forLoop, program, methodKey);
		break;
	case DoWhileLoop:
		addConstantsFrom(stmt->whileLoop, program, methodKey);
		break;
	case IfStmt:
		addConstantsFrom(stmt->ifStmt, program, methodKey);
		break;
	case Expr:
		addConstantsFrom(stmt->expr, program, methodKey);
		break;
	case ReturnValue:
		addConstantsFrom(stmt->expr, program, methodKey);
		break;
	}

}

void ClassFile::addConstantsFrom(methodS* meth, programS* program)
{
	//Загружаем указатель на объект
	string methKey = createShortInfo(meth);
	if (!methodTable.at(methKey).isStatic)
	{
		methodTable.at(methKey).addLocalVar(new LocalVariableInfo(true, true, "this", className));
	}

	//Загружаем локальные переменные
	if (meth->func->delc->params != 0)
	{
		for (formalParamS* fp = meth->func->delc->params->first; fp != 0; fp = fp->next)
		{
			methodTable.at(methKey).addLocalVar(new LocalVariableInfo(false, false, fp->name, fp->type->easyType));
		}
	}

	if (meth->func->stmts != 0)
	{
		for (stmtS* stmt = meth->func->stmts->first; stmt != 0; stmt = stmt->next)
		{
			addConstantsFrom(stmt, program, methKey);
		}
	}
	
}















bool MethodTableElement::addLocalVar(varOrValDeclS* varOrValDecl)
{
	return 0;
}

bool MethodTableElement::addLocalVar(LocalVariableInfo* varOrValDecl)
{
	return false;
}

void MethodTableElement::remove(int varOrValDeclIndex)
{
}


int MethodTableElement::find(string varOrValName)
{
	return 0;
}

LocalVariableInfo MethodTableElement::find(int indexInTable)
{
	return LocalVariableInfo(false, false, "", "");
}
