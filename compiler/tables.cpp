#include "tables.h"


vector<char> generate(stmtList* stmts);

string* generateMethodRefParams(const string& methodName, const string& className,
	int paramsCount);

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
	string message = "EXCEPTION! Unsupported visibility mod translated \"";
	exception e(message.c_str());
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

	//Если обращаются к стандартному полю массива
	if (currentClassName.find("[]") != -1 && strcmp(propName, "size") == 0)
	{
		res = "MyLib/Int";
	}
	//Если обращаются к стандартному полю строки моего класса
	else if (currentClassName == "MyLib/MyString" && strcmp(propName, "length") == 0)
	{
		res = "MyLib/Int";
	}	
	else
	{
		for (auto pe = program->first; pe != 0 && res == ""; pe = pe->next)
		{
			if (pe->clas != 0 && pe->clas->name == currentClassName && pe->clas->body != 0)
			{
				for (auto cbe = pe->clas->body->first; cbe != 0 && res == ""; cbe = cbe->next)
				{
					if (cbe->property != 0 && strcmp(cbe->property->varOrVal->id, propName) == 0)
					{
						res = cbe->property->varOrVal->type->easyType;
					}
				}
				if (res == "" && pe->clas->parentClassName != 0 && strcmp(pe->clas->parentClassName, "MyLib/Any") != 0)
				{
					res = getPropertyType(propName, program, pe->clas->parentClassName);
				}
			}
		}
	}
	
	return res;

}

//Является ли метод библиотечным
string isStandartStaticMethod(string methodSign)
{
	if (methodSign.find("print(") == 0 && methodSign.find_first_of('|') == 
		methodSign.find_last_of('|') && methodSign.find_first_of('|') != -1)
		return "MyLib/Unit";
	else if (methodSign == "readInt()")	return "MyLib/Int";
	else if (methodSign == "readLine()") return "MyLib/MyString";
	else if (methodSign == "readDouble()") return "MyLib/Double";
	else if (methodSign == "readChar()") return "MyLib/Char";
	else if (methodSign == "readFloat()") return "MyLib/Float";
	else if (methodSign == "readBoolean()") return "MyLib/Boolean";
	else if (methodSign.find("arrayOf(") == 0)
	{
		return "MyLib/Array";
	}
	else return "";
}

const methodS* findMethod(const string& methodSign, const programS* const program,
	const string& currentClassName)
{
	if (currentClassName == "" || methodSign == "")
		return 0;

	const methodS* res = 0;

	if (currentClassName == "MyLib/Any")
	{
		return res;
	}
	else
	{
		for (auto pe = program->first; pe != 0; pe = pe->next)
		{
			if (pe->clas != 0 && pe->clas->name == currentClassName && pe->clas->body != 0)
			{
				for (auto cbe = pe->clas->body->first; cbe != 0; cbe = cbe->next)
				{
					if (cbe->method != 0)
					{
						string methodInfo = createMethodSignature(cbe->method);
						if (strstr(methodInfo.c_str(), methodSign.c_str()) != 0)
						{
							res = cbe->method;
						}
					}
					if (res == 0 && pe->clas->parentClassName != 0)
					{
						res = findMethod(methodSign, program, pe->clas->parentClassName);
					}
				}
			}
		}
	}

	return res;
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


string getMethodTypeForArray(const string& methodSign, const string& currentClassName)
{
	string res = "";
	//Если класс - массив
	if (currentClassName.find('[') != -1)
	{
		//Вызывается метод get
		if (methodSign == "get(MyLib/Int|)")
		{
			res = currentClassName;
			res.pop_back();
			res.pop_back();
		}
		
		//set
		if (methodSign == "set(MyLib/Int|)")
		{
			res = "MyLib/Unit";
		}

		//component
		if (methodSign == "component1()" || methodSign == "component2()" || methodSign == "component3()" || 
			methodSign == "component4()" || methodSign == "component5()")
		{
			res = currentClassName;
			res.pop_back();
			res.pop_back();
		}
	}

	return res;
}

string getMethodTypeForStandartClass(const string& methodSign, const string& currentClassName)
{
	if (currentClassName == "")	return "";

	//Если класс - базовый
	if (isMyStandartClass(currentClassName) || currentClassName.find('[') != -1)
	{
		//В equals один параметр
		if (methodSign.find("equals(") == 0 && methodSign.find_last_of('|')
			== methodSign.find_first_of('|') && methodSign.find_last_of('|') != -1)
		{
			return "MyLib/Boolean";
		}
		else if (methodSign == "toMyString()" || methodSign == "toString()")
		{
			return "MyLib/MyString";
		}
	}

	//Если класс - массив
	if (currentClassName.find('[') != -1)
	{
		return getMethodTypeForArray(methodSign, currentClassName);
	}

	//Если класс - boolean
	if (currentClassName == "MyLib/Boolean")
	{
		return "";
	}

	if (currentClassName == "MyLib/Char" || currentClassName == "MyLib/Double" || 
		currentClassName == "MyLib/Float" || currentClassName == "MyLib/Int" ||
		currentClassName == "MyLib/MyString")
	{
		if (methodSign == "toInt()")
			return "MyLib/Int";

		if (methodSign == "toFloat()")
			return "MyLib/Float";

		if (methodSign == "toBoolean()")
			return "MyLib/Boolean";

		if (methodSign == "toDouble()")
			return "MyLib/Double";
	}

	if (currentClassName == "MyLib/MyString")
	{
		if (methodSign == "get(MyLib/Int|)")
			return "MyLib/Char";
	}

	return "";
}

//Ищет метод только в пользовательских классах с учетом наследования
string getMethodTypeForUserClass(const string& methodSign, const programS* const program, 
	const string& currentClassName)
{
	if (currentClassName == "")	return "";

	string res = "";

	if (res == "")
	{
		auto method = findMethod(methodSign, program, currentClassName);
		if (method != 0)
			res = method->func->decl->type->easyType;
	}
	return res;
}

string getMethodType(const string& methodSign, const programS* const program, const string& currentClassName)
{
	if (currentClassName == "")	return "";

	string res = "";

	//Поскольку у Main класс не является наследником Any, в нем не могут использоваться
	//Методы equals и toString, базового класса
	if (currentClassName != "Main$")
	{
		res = getMethodTypeForStandartClass(methodSign, currentClassName);
	}	
	
	
	if (res == "")
	{
		res = getMethodTypeForUserClass(methodSign, program, currentClassName);
	}	
	return res;
}

string getOperatorTypeForArray(const string& methodSign, const string& currentClassName)
{
	string res = "";
	//Если класс - массив
	if (currentClassName.find('[') != -1)
	{
		//add
		if (methodSign.find("add(") == 0 && methodSign.find_first_of('|') == 
			methodSign.find_last_of('|') && methodSign.find_last_of('|') != -1)
		{
			res = "MyLib/Array";
		}

		//addAssign
		if (methodSign.find("addAssign(") == 0 && methodSign.find_first_of('|') == 
			methodSign.find_last_of('|') && methodSign.find_last_of('|') != -1)
		{
			res = "MyLib/Unit";
		}
	}

	return res;
}

string getOperatorTypeForBoolean(const string& methodSign)
{
	string res = "";

	if (methodSign == "less(MyLib/Boolean|)" || methodSign == "more(MyLib/Boolean|)" ||
		methodSign == "or(MyLib/Boolean|)" || methodSign == "and(MyLib/Boolean|)" ||
		methodSign == "equal(MyLib/Boolean|)" || methodSign == "notEqual(MyLib/Boolean|)" ||
		methodSign == "lessOrEqual(MyLib/Boolean|)" || methodSign == "moreOrEqual(MyLib/Boolean|)" ||
		methodSign == "not()")
	{
		res = "MyLib/Boolean";
	}

	return res;
}

string getOperatorTypeForChar(const string& methodSign)
{
	string res = "";

	if (methodSign == "sub(MyLib/Char|)")
		res = "MyLib/Int";

	if (methodSign == "add(MyLib/Int|)" ||
		methodSign == "sub(MyLib/Int|)")
		res = "MyLib/Char";

	if (methodSign == "add(MyLib/MyString|)")
		res = "MyLib/MyString";

	if (methodSign == "less(MyLib/Char|)" || methodSign == "more(MyLib/Char|)" ||
		methodSign == "equal(MyLib/Char|)" || methodSign == "notEqual(MyLib/Char|)" ||
		methodSign == "lessOrEqual(MyLib/Char|)" || methodSign == "moreOrEqual(MyLib/Char|)")
		res = "MyLib/Boolean";

	return res;
}

string getOperatorTypeForDouble(const string& methodSign)
{
	if (methodSign == "add(MyLib/Int|)" || methodSign == "add(MyLib/Double|)" ||
		methodSign == "add(MyLib/Float|)" || methodSign == "sub(MyLib/Int|)" ||
		methodSign == "sub(MyLib/Double|)" || methodSign == "sub(MyLib/Float|)" ||
		methodSign == "mul(MyLib/Int|)" || methodSign == "mul(MyLib/Double|)" ||
		methodSign == "mul(MyLib/Float|)" || methodSign == "div(MyLib/Int|)" ||
		methodSign == "div(MyLib/Double|)" || methodSign == "div(MyLib/Float|)" ||
		methodSign == "unaryPlus()" || methodSign == "unaryMinus()")
		return "MyLib/Double";

	if (methodSign == "less(MyLib/Int|)" || methodSign == "less(MyLib/Double|)" ||
		methodSign == "less(MyLib/Float|)" || methodSign == "more(MyLib/Int|)" ||
		methodSign == "more(MyLib/Double|)" || methodSign == "more(MyLib/Float|)" ||
		methodSign == "equal(MyLib/Int|)" || methodSign == "equal(MyLib/Double|)" ||
		methodSign == "equal(MyLib/Float|)" || methodSign == "notEqual(MyLib/Int|)" ||
		methodSign == "notEqual(MyLib/Double|)" || methodSign == "notEqual(MyLib/Float|)" ||
		methodSign == "lessOrEqual(MyLib/Int|)" || methodSign == "lessOrEqual(MyLib/Double|)" ||
		methodSign == "lessOrEqual(MyLib/Float|)" || methodSign == "moreOrEqual(MyLib/Int|)" ||
		methodSign == "moreOrEqual(MyLib/Double|)" || methodSign == "moreOrEqual(MyLib/Float|)")
		return "MyLib/Boolean";

	return "";
}

string getOperatorTypeForFloat(const string& methodSign)
{
	if (methodSign == "add(MyLib/Int|)" || methodSign == "add(MyLib/Float|)" ||
		methodSign == "sub(MyLib/Int|)" || methodSign == "sub(MyLib/Float|)" ||
		methodSign == "mul(MyLib/Int|)" || methodSign == "mul(MyLib/Float|)" ||
		methodSign == "div(MyLib/Int|)" || methodSign == "div(MyLib/Float|)" ||
		methodSign == "unaryPlus()" || methodSign == "unaryMinus()")
		return "MyLib/Float";

	if (methodSign == "add(MyLib/Double|)" || methodSign == "sub(MyLib/Double|)" ||
		methodSign == "mul(MyLib/Double|)" || methodSign == "div(MyLib/Double|)")
		return "MyLib/Double";

	if (methodSign == "less(MyLib/Int|)" || methodSign == "less(MyLib/Double|)" ||
		methodSign == "less(MyLib/Float|)" || methodSign == "more(MyLib/Int|)" ||
		methodSign == "more(MyLib/Double|)" || methodSign == "more(MyLib/Float|)" ||
		methodSign == "equal(MyLib/Int|)" || methodSign == "equal(MyLib/Double|)" ||
		methodSign == "equal(MyLib/Float|)" || methodSign == "notEqual(MyLib/Int|)" ||
		methodSign == "notEqual(MyLib/Double|)" || methodSign == "notEqual(MyLib/Float|)" ||
		methodSign == "lessOrEqual(MyLib/Int|)" || methodSign == "lessOrEqual(MyLib/Double|)" ||
		methodSign == "lessOrEqual(MyLib/Float|)" || methodSign == "moreOrEqual(MyLib/Int|)" ||
		methodSign == "moreOrEqual(MyLib/Double|)" || methodSign == "moreOrEqual(MyLib/Float|)")
		return "MyLib/Boolean";

	return "";
}

string getOperatorTypeForInt(const string& methodSign)
{
	if (methodSign == "add(MyLib/Int|)" || methodSign == "sub(MyLib/Int|)" ||
		methodSign == "mul(MyLib/Int|)" || methodSign == "div(MyLib/Int|)" ||
		methodSign == "unaryPlus()" || methodSign == "unaryMinus()")
		return "MyLib/Int";

	if (methodSign == "add(MyLib/Float|)" || methodSign == "sub(MyLib/Float|)" ||
		methodSign == "mul(MyLib/Float|)" || methodSign == "div(MyLib/Float|)")
		return "MyLib/Float";

	if (methodSign == "add(MyLib/Double|)" || methodSign == "sub(MyLib/Double|)" ||
		methodSign == "mul(MyLib/Double|)" || methodSign == "div(MyLib/Double|)")
		return "MyLib/Double";

	if (methodSign == "less(MyLib/Int|)" || methodSign == "less(MyLib/Double|)" ||
		methodSign == "less(MyLib/Float|)" || methodSign == "more(MyLib/Int|)" ||
		methodSign == "more(MyLib/Double|)" || methodSign == "more(MyLib/Float|)" ||
		methodSign == "equal(MyLib/Int|)" || methodSign == "equal(MyLib/Double|)" ||
		methodSign == "equal(MyLib/Float|)" || methodSign == "notEqual(MyLib/Int|)" ||
		methodSign == "notEqual(MyLib/Double|)" || methodSign == "notEqual(MyLib/Float|)" ||
		methodSign == "lessOrEqual(MyLib/Int|)" || methodSign == "lessOrEqual(MyLib/Double|)" ||
		methodSign == "lessOrEqual(MyLib/Float|)" || methodSign == "moreOrEqual(MyLib/Int|)" ||
		methodSign == "moreOrEqual(MyLib/Double|)" || methodSign == "moreOrEqual(MyLib/Float|)")
		return "MyLib/Boolean";

	return "";
}

string getOperatorTypeForMyString(const string& methodSign)
{
	if (methodSign.find("add(") == 0 && methodSign.find_first_of('|') 
		== methodSign.find_last_of('|') && methodSign.find_last_of('|') != -1)
		return "MyLib/MyString";

	if (methodSign == "less(MyLib/MyString|)" || methodSign == "more(MyLib/MyString|)" ||
		methodSign == "equal(MyLib/MyString|)" || methodSign == "notEqual(MyLib/MyString|)" ||
		methodSign == "lessOrEqual(MyLib/MyString|)" || methodSign == "moreOrEqual(MyLib/MyString|)")
		return "MyLib/Boolean";

	return "";
}

string getOperatorTypeForStandartClass(const string& methodSign, const string& currentClassName)
{
	if (!isMyStandartClass(currentClassName) && currentClassName.find('[') == 0)
	{
		return "";
	}

	if (currentClassName.find('[') != -1)
		return getOperatorTypeForArray(methodSign, currentClassName);

	if (currentClassName == "MyLib/Boolean")
		return getOperatorTypeForBoolean(methodSign);

	if (currentClassName == "MyLib/Char")
		return getOperatorTypeForChar(methodSign);

	if (currentClassName == "MyLib/Double")
		return getOperatorTypeForDouble(methodSign);

	if (currentClassName == "MyLib/Float")
		return getOperatorTypeForFloat(methodSign);

	if (currentClassName == "MyLib/Int")
		return getOperatorTypeForInt(methodSign);

	if (currentClassName == "MyLib/MyString")
		return getOperatorTypeForMyString(methodSign);

	return "";
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
	string methInfo = string(methodCall->stringOrId) + "(";

	if (methodCall->factParams != 0)
	{
		for (exprS* e = methodCall->factParams->first; e != 0; e = e->next)
		{
			methInfo += e->exprRes + "|";
		}
	}
	
	return methInfo + ")";
}

string createMethodSignature(methodS* meth)
{
	string methInfo = string(meth->func->decl->name) + "(";

	if (meth->func->decl->params != 0)
	{
		for (formalParamS* fp = meth->func->decl->params->first; fp != 0; fp = fp->next)
		{
			methInfo = methInfo + string(fp->type->easyType) + "|";
		}
	}
	methInfo += ")";
	return methInfo;
}

bool operator==(LocalVariableInfo i1, LocalVariableInfo i2)
{
	return i1.name == i2.name && i1.nestingLevel == i2.nestingLevel;
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
	VisibilityMod vMod, bool isFinal, bool isStatic, constructorS* constructor, methodS* method)
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

	this->constructor = constructor;
	this->method = method;
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
	if (!fillHighLevelObjectsConstants(clas, program))
	{
		string error = "Exception! Errors in class file creating in class ";
		throw exception((error + clas->name).c_str());
	}
}

int ClassFile::findUtf8OrAdd(std::string const& utf8)
{
	ConstantsTableElement constant(UTF_8, utf8);
	const auto foundIter = std::find(constsTable.begin(), constsTable.end(), constant);
	if (foundIter == constsTable.end())
	{
		constsTable.push_back(constant);
		return constsTable.end() - constsTable.begin();
	}
	return foundIter - constsTable.begin() + 1;
}

int ClassFile::findIntOrAdd(IntT i)
{
	ConstantsTableElement constant(_INT, i);
	const auto foundIter = std::find(constsTable.begin(), constsTable.end(), constant);
	if (foundIter == constsTable.end())
	{
		constsTable.push_back(constant);
		return constsTable.end() - constsTable.begin();
	}
	return foundIter - constsTable.begin() + 1;
}

int ClassFile::findFloatOrAdd(float i)
{
	ConstantsTableElement constant(_FLOAT, i);
	const auto foundIter = std::find(constsTable.begin(), constsTable.end(), constant);
	if (foundIter == constsTable.end())
	{
		constsTable.push_back(constant);
		return constsTable.end() - constsTable.begin();
	}
	return foundIter - constsTable.begin() + 1;
}

int ClassFile::findDoubleOrAdd(double i)
{
	ConstantsTableElement constant(_DOUBLE, i);
	const auto foundIter = std::find(constsTable.begin(), constsTable.end(), constant);
	if (foundIter == constsTable.end())
	{
		constsTable.push_back(constant);
		return constsTable.end() - constsTable.begin();
	}
	return foundIter - constsTable.begin() + 1;
}

int ClassFile::findStringOrAdd(string& v)
{
	int value[2] = { findUtf8OrAdd(v), 0 };
	ConstantsTableElement constant(_STRING, value);
	const auto foundIter = std::find(constsTable.begin(), constsTable.end(), constant);
	if (foundIter == constsTable.end())
	{
		constsTable.push_back(constant);
		return constsTable.end() - constsTable.begin();
	}
	return foundIter - constsTable.begin() + 1;
}

int ClassFile::findClassOrAdd(std::string const& className)
{
	int value[2] = { findUtf8OrAdd(className), 0 };
	ConstantsTableElement constant(_CLASS, value);
	const auto foundIter = std::find(constsTable.begin(), constsTable.end(), constant);
	if (foundIter == constsTable.end())
	{
		constsTable.push_back(constant);
		return constsTable.end() - constsTable.begin();
	}
	return foundIter - constsTable.begin() + 1;
}

int ClassFile::findNameAndTypeOrAdd(std::string const& name, std::string const& type)
{
	int value[2] = { findUtf8OrAdd(name), findUtf8OrAdd(type) };
	ConstantsTableElement constant(NAME_AND_TYPE, value);
	const auto foundIter = std::find(constsTable.begin(), constsTable.end(), constant);
	if (foundIter == constsTable.end())
	{
		constsTable.push_back(constant);
		return constsTable.end() - constsTable.begin();
	}
	return foundIter - constsTable.begin() + 1;
}

int ClassFile::findFieldRefOrAdd(std::string const& className, std::string const& name, std::string const& type)
{

	int value[2] = { findClassOrAdd(className), findNameAndTypeOrAdd(name, type) };
	ConstantsTableElement constant(FIELD_REF, value);
	const auto foundIter = std::find(constsTable.begin(), constsTable.end(), constant);
	if (foundIter == constsTable.end())
	{
		constsTable.push_back(constant);
		return constsTable.end() - constsTable.begin();
	}
	return foundIter - constsTable.begin() + 1;
}

int ClassFile::findMethodRefOrAdd(std::string const& className, std::string const& name, std::string const& type)
{
	int value[2] = { findClassOrAdd(className),  findNameAndTypeOrAdd(name, type) };
	ConstantsTableElement constant(METHOD_REF, value);
	const auto foundIter = std::find(constsTable.begin(), constsTable.end(), constant);
	if (foundIter == constsTable.end())
	{
		constsTable.push_back(constant);
		return constsTable.end() - constsTable.begin();
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
	if (isUserClass(type, program) || isMyStandartClass(type))
	{
		if (strcmp(type, "MyLib/Unit") == 0)
			return "V";
		return string("L") + string(type) + ";";
	}
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
		return descriptor + transformTypeToDescriptor(typeName.c_str(), program);
	}
}

void ClassFile::fillHighLevelObjectsConstants(propertyS* prop, programS* program)
{
	
	uint16_t nameId = findUtf8OrAdd(prop->varOrVal->id);
	
	uint16_t descId = findUtf8OrAdd(transformTypeToDescriptor(prop->varOrVal->type->easyType.c_str(), 
		program));
	
	FieldTableElement fte(nameId, descId, translateVisibilityMod(prop->mods->vMod), prop->mods->isStatic, 
		prop->varOrVal->isVal);
	
	fieldTable.insert(make_pair(prop->varOrVal->id, fte));
}

bool ClassFile::fillHighLevelObjectsConstants(constructorS* constr, programS* program)
{
	uint16_t nameId = 0;
	string constrName;
	if (!constr->isStatic)
		constrName = "<init>";
		
	else
		constrName = "<clinit>";

	nameId = findUtf8OrAdd(constrName);
	uint16_t descr = findUtf8OrAdd("()V");

	MethodTableElement mte(nameId, descr, translateVisibilityMod(constr->mod),
		false, constr->isStatic, constr, 0);
	mte.addLocalVar(new LocalVariableInfo(true, true, "this$", className,
		mte.getNestingLevel()));
	methodTable.insert(make_pair(constrName + "()V", mte));
	
	bool res = addConstantsFrom(constr->stmts, program, constrName + "()V");

	//Добавить return и вызов родительского конструктора
	if (res)
	{
		if (constrName == "<init>")
		{
			//Добавить вызов родительского конструктора
			char* pClassName = new char[parentClassName.size() + 1];
			strcpy(pClassName, parentClassName.c_str());
			exprS* parentConstructorCall = createExpr(pClassName, 0, ParentConstrCall);
			parentConstructorCall->exprRes = parentClassName;
			parentConstructorCall->refInfo = findMethodRefOrAdd(parentClassName, "<init>", "()V");
			stmtS* newFirstStmt = createStmt(parentConstructorCall, Expr);
			if (constr->stmts == 0)
			{
				constr->stmts = createStmtList(newFirstStmt);
			}
			else
			{
				newFirstStmt->next = constr->stmts->first;
				constr->stmts->first = newFirstStmt;
			}
			constr->stmts = addToStmtList(constr->stmts, createStmt(Return));
		}
		else
		{
			if (constr->stmts == 0)
			{
				constr->stmts = createStmtList(createStmt(Return));
			}
			else
			{
				constr->stmts = addToStmtList(constr->stmts, createStmt(Return));
			}			
		}		
	}

	return res;
}

bool ClassFile::fillHighLevelObjectsConstants(methodS* meth, programS* program)
{
	uint16_t nameId = findUtf8OrAdd(meth->func->decl->name);

	string methodDescr = "(";
	if (meth->func->decl->params != 0)
	{
		for (formalParamS* fp = meth->func->decl->params->first; fp != 0; fp = fp->next)
		{
			methodDescr += transformTypeToDescriptor(fp->type->easyType.c_str(), program);
		}
	}
	methodDescr += ')';

	methodDescr += transformTypeToDescriptor(meth->func->decl->type->easyType.c_str(),
		program);
	uint16_t descId = findUtf8OrAdd(methodDescr);
	
	MethodTableElement mte(nameId, descId, translateVisibilityMod(meth->mods->vMod), 
		meth->mods->iMod == Final, meth->mods->isStatic, 0, meth);

	methodTable.insert(make_pair(createMethodSignature(meth), mte));
	bool res = addConstantsFrom(meth, program);
	
	return res;
}

void ClassFile::addMain(classS* clas, const programS* const program)
{
	if (strcmp(clas->name, "Main$") != 0)
		return;

	//Найти main()
	string res = getMethodType("main()", program, "Main$");

	char* argName = new char[5];
	strcpy(argName, "args");
	char* argType = new char[20];
	strcpy(argType, "java/lang/String[]");
	formalParamsList* fpl = createFormalParamsList(argName, createType(argType));
	char* funName = new char[5];
	strcpy(funName, "main");
	char* funType = new char[11];
	strcpy(funType, "MyLib/Unit");
	funcDeclS* mainFuncDelc = createFuncDecl(funName, fpl, createType(funType));
	
	stmtList* stmts = 0;
	//Если main() найдена
	if (res == "MyLib/Unit")
	{
		exprS* mainCall = createExpr(funName, 0, MethodCall);
		mainCall->exprRes = "void";
		mainCall->refInfo = findMethodRefOrAdd("Main$", "main", "()V");
		mainCall->isStaticCall = true;
		stmtS* stmt = createStmt(mainCall, Expr);
		stmts = createStmtList(stmt);
		stmts = addToStmtList(stmts, createStmt(Return));
	}
	else
	{
		stmts = createStmtList(createStmt(Return));
	}

	funcS* mainFunc = createFunc(mainFuncDelc, stmts);
	modifiersS* mods = createModifiers(0, 0, Public, Final);
	mods->isStatic = true;
	methodS* main = createMethod(mods, mainFunc);
	
	//Добавить таблицу переменных в метод + добавить сам метод в таблицу методов
	int methNameRef = findUtf8OrAdd("main");
	int methDescr = findUtf8OrAdd("([Ljava/lang/String;)V");
	MethodTableElement mte(methNameRef, methDescr, _PUBLIC, true, true, 0, main);
	mte.addLocalVar(new LocalVariableInfo(true, true, "args", "java/lang/String[]", 0));
	methodTable.insert(make_pair("main(java/lang/String[]|)",  mte));

	if (clas->body == 0)
		clas->body = createClassBody(main);
	else
		clas->body = addToClassBody(clas->body, main);
}

bool ClassFile::fillHighLevelObjectsConstants(classS* clas, programS* program)
{
	findUtf8OrAdd("Code");
	thisClass = findClassOrAdd(clas->name);
	if (clas->parentClassName != 0)	superClass = findClassOrAdd(clas->parentClassName);
	

	//Заполняю флаги доступа к классу
	accessFlags |= 0x0001; //Устанавливаю флаг PUBLIC
	if (isFinal) accessFlags |= 0x0010; //Устанавливаю флаг FINAL
	accessFlags |= 0x0020; //Устанавливаю флаг SUPER !Он устанавливается для совместимости

	bool res = true;
	bool tmp = true;
	if (clas->body != 0)
	{
		for (auto cbe = clas->body->first; cbe != 0; cbe = cbe->next)
		{
			if (cbe->method != 0)
			{
				tmp = fillHighLevelObjectsConstants(cbe->method, program);
				res = res && tmp;
			}
			else if (cbe->property != 0)
			{
				fillHighLevelObjectsConstants(cbe->property, program);
			}
			else if (cbe->constructor != 0)
			{
				tmp = fillHighLevelObjectsConstants(cbe->constructor, program);
				res = res && tmp;
			}
		}
	}

	if (res && strcmp(clas->name, "Main$") == 0)
		addMain(clas, program);
	

	if (clas->parentClassName == 0 && strcmp(clas->name, "Main$") == 0)
		superClass = findClassOrAdd("java/lang/Object");

	return res;
}

int ClassFile::calcType(factParamsList* fpl, programS* program, const string & methodKey)
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

bool checkUnitOperandsInExpr(assignmentS* a, const string& methodKey)
{
	if (a->left != 0 && a->left->exprRes == "MyLib/Unit"|| 
		a->right != 0 && a->right->exprRes == "MyLib/Unit" ||
		a->subLeft != 0 && a->subLeft->exprRes == "MyLib/Unit")
	{
		string message = "EXCEPTION! Incorrect operand with UNIT (void) type in method - ";
		exception e((message + methodKey).c_str());
		throw e;
	}
}

bool checkUnitOperandsInExpr(exprS* e, const string& methodKey)
{
	if (e->factParams != 0)
	{
		for (auto fp = e->factParams->first; fp != 0; fp = fp->next)
		{
			if (fp->exprRes == "MyLib/Unit")
			{
				string message = "EXCEPTION! Incorrect operand with UNIT (void) type in method - ";
				exception e((message + methodKey).c_str());
				throw e;
			}
		}
	}
	if (e->left != 0 && e->left->exprRes == "MyLib/Unit" 
		|| e->right != 0 && e->right->exprRes == "MyLib/Unit")
	{
		string message = "EXCEPTION! Incorrect operand with UNIT (void) type in method - ";
		exception e((message + methodKey).c_str());
		throw e;
	}
}

//Добавляем неявное обращение к this или super
void addParentOrThisToExpr(exprS* e, const string& className, bool isParent)
{
	char* tmp;
	exprType et;
	if (isParent)
	{
		tmp = new char[strlen("super") + 1];
		strcpy(tmp, "super");
		et = Identificator;
	}
	else
	{
		tmp = new char[strlen("this") + 1];
		strcpy(tmp, "this");
		et = This;
	}
	e->left = createExpr(tmp, et);
	e->left->varInTableNum = 0;
	e->left->exprRes = className;
}

void ClassFile::calcTypeOfIdentifier(exprS* e1, programS* program, const string& methodKey)
{
	if (e1->type != Identificator)
	{
		return;
	}
	
	MethodTableElement method = methodTable.at(methodKey);
	e1->varInTableNum = method.find(e1->stringOrId);
	string res;
	//Если переменная есть в таблице переменных
	if (e1->varInTableNum != -1)
	{
		res = method.find(e1->varInTableNum).type;
		e1->exprRes = res;
		return;
	}

	//Для идентификатора super, он может попасть сюда, только если был выделен при присвоении
	if (strcmp(e1->stringOrId, "super") == 0 && parentClassName != "")
	{
		e1->varInTableNum = 0;
		e1->exprRes = parentClassName;
		return;
	}

	//Ищем среди полей класса и его родителей
	res = getPropertyType(e1->stringOrId, program, className);
	if (res != "")
	{
		if (className != "Main$")
		{
			e1->type = FieldCalcExpr;
			addParentOrThisToExpr(e1, className, false);
		}			
		else
			e1->isStaticCall = true;
		e1->exprRes = res;
		e1->refInfo = findFieldRefOrAdd(className, e1->stringOrId, 
			transformTypeToDescriptor(res.c_str(), program));
		return;
	}
	
	//Ищем среди глобальных переменных
	res = getPropertyType(e1->stringOrId, program, "Main$");
	if (res != "")
	{
		e1->exprRes = res;
		e1->isStaticCall = true;
		e1->refInfo = findFieldRefOrAdd("Main$", e1->stringOrId, 
			transformTypeToDescriptor(res.c_str(), program));
		return;
	}

	//Поле не локальная переменная, не поле класса, не глобалка
	string message = "EXCEPTION! Undefined variable or property name \"";
	exception e((message + string(e1->stringOrId) + "\"\n").c_str());
	throw e;
}



string calcParentClass(const string& class1, const string& class2, const programS* const program)
{
	//Если классы одинаковые
	if (class1 == class2)
		return class1;

	//Если один из классов базовый
	if (class1 == "MyLib/Any" || class2 == "MyLib/Any")
		return class1;

	//Если один из классов мой базовый
	if (isMyStandartClass(class1) || isMyStandartClass(class2))
		return "MyLib/Any";

	//Если оба класса пользовательские
	if (isUserClass(class1.c_str(), program) && isUserClass(class2.c_str(), program))
	{
		if (isParentClass(class1, class2, program))
			return class1;

		if (isParentClass(class2, class1, program))
			return class2;

		for (auto pe = program->first; pe != 0; pe = pe->next)
		{
			if (pe->clas != 0 && class1 == pe->clas->name)
				return calcParentClass(pe->clas->parentClassName, class2, program);
		}
	}

	//Если пользовательский класс сравнивается с массивом, сравниваются разные массивы и т.д.
	return "MyLib/Any";
}

//Рассчитывает по типу параметров тип создаваемого массива
/*
e - вызов функции arrayOf
*/
void calcArrayOfType(exprS* e, programS* program, const string& methodKey)
{
	if (e->factParams == 0)
	{
		string message = "EXCEPTION! Creating of array without elements and type in method\"";
		exception e((message + methodKey + "\"\n").c_str());
		throw e;
	}

	e->type = ArrayCreating;
	if (e->factParams->first == e->factParams->last)
	{
		e->exprRes = e->factParams->first->exprRes;
		e->exprRes.push_back('[');
		e->exprRes.push_back(']');
		return;
	}

	string fp1Type = e->factParams->first->exprRes;
	exprS* fp2 = e->factParams->first->next;
	for (; fp2 != 0; fp2 = fp2->next)
	{
		fp1Type = calcParentClass(fp1Type, fp2->exprRes, program);
	}
	fp1Type.push_back('[');
	fp1Type.push_back(']');
	e->exprRes = fp1Type;
}

void ClassFile::calcTypeOfMethodCall(exprS* e1, programS* program, const string& methodKey)
{
	if (e1->type != MethodCall)
		return;

	//Рассчитать типы для параметров
	int paramsCount = calcType(e1->factParams, program, methodKey);
	checkUnitOperandsInExpr(e1, methodKey);

	string res = "";

	//Если вызван метод класса или его родителя (пользовательского класса)
	res = getMethodTypeForUserClass(createShortInfo(e1), program, className);
	if (res != "")
	{
		e1->exprRes = res;
		//Если метод динамический
		if (className != "Main$")
		{
			e1->type = MethodCalcExpr;
			addParentOrThisToExpr(e1, className, false);
		}			
		else 
			e1->isStaticCall = true;

		e1->refInfo = findMethodRefOrAdd(className, e1->stringOrId,
			transformMethodCallToDescriptor(e1, program));
		return;
	}

	//Если вызван метод родительского класса (базового класса Any)
	res = getMethodTypeForStandartClass(createShortInfo(e1), parentClassName);
	if (res != "")
	{
		e1->type = MethodCalcExpr;
		addParentOrThisToExpr(e1, className, false);
		if (strcmp(e1->stringOrId, "toString") == 0 && paramsCount == 0)
		{
			char* tmp = new char[strlen("toMyString") + 1];
			strcpy(tmp, "toMyString");
			e1->stringOrId = tmp;
		}
		
		string* params = generateMethodRefParams(e1->stringOrId, parentClassName,
			paramsCount);
		if (params[0] == "" || params[1] == "" || params[2] == "")
		{
			throw exception("EXCEPTION! Unknown my std method name\n");
		}
		e1->refInfo = findMethodRefOrAdd(params[0], params[1], params[2]);
		return;
	}

	//Если вызывается конструктор базового класса или пользовательского класса
	if (paramsCount == 0)
	{
		if (isUserClass(e1->stringOrId, program))
		{
			e1->exprRes = e1->stringOrId;
			e1->type = ConstructorCall;
			e1->classId = findClassOrAdd(e1->stringOrId);
			e1->refInfo = findMethodRefOrAdd(e1->stringOrId, "<init>", "()V");
			return;
		}
		else if (strcmp(e1->stringOrId, "Any") == 0)
		{
			char* tmp = new char[strlen("MyLib/Any") + 1];
			strcpy(tmp, "MyLib/Any");
			e1->type = ConstructorCall;
			e1->stringOrId = tmp;
			e1->classId = findClassOrAdd(tmp);
			e1->exprRes = tmp;
			e1->refInfo = findMethodRefOrAdd(tmp, "<init>", "()V");
			return;
		}
	}
	
	//Вызов глобального метода
	res = getMethodType(createShortInfo(e1), program, "Main$");
	if (res != "")
	{
		e1->isStaticCall = true;
		e1->exprRes = res;
		e1->refInfo = findMethodRefOrAdd("Main$", e1->stringOrId,
			transformMethodCallToDescriptor(e1, program));
		return;
	}

	//Вызов метода моей библиотеки
	res = isStandartStaticMethod(createShortInfo(e1));
	if (res != "")
	{
		e1->isStaticCall = true;
		if (res == "MyLib/Array")
		{
			calcArrayOfType(e1, program, methodKey);
			e1->refInfo = findMethodRefOrAdd("MyLib/Array", e1->stringOrId, "([Ljava/lang/Object;)LMyLib/Array;");
			string arrayElementType = e1->exprRes;
			arrayElementType.pop_back();
			arrayElementType.pop_back();
			if (arrayElementType.find('[') != -1)
				e1->classId = findClassOrAdd("MyLib/Array");
			else
				e1->classId = findClassOrAdd(arrayElementType);
		}
		else
		{
			e1->exprRes = res;
			if (strcmp(e1->stringOrId, "print") == 0)
				e1->refInfo = findMethodRefOrAdd("MyLib/MyIO", e1->stringOrId,
					"(LMyLib/Any;)V");
			else
				e1->refInfo = findMethodRefOrAdd("MyLib/MyIO", e1->stringOrId,
					transformMethodCallToDescriptor(e1, program));
		}
		return;
	}

	string message = "EXCEPTION! Call of unknown method \"";
	exception e((message + string(e1->stringOrId) + "\" in method - \"" + methodKey + "\"\n").c_str());
	throw e;
}

void ClassFile::calcTypeOfFieldCalsExpr(exprS* e1, programS* program, const string& methodKey)
{
	if (e1->type != FieldCalcExpr)
		return;

	calcType(e1->left, program, methodKey);
	checkUnitOperandsInExpr(e1, methodKey);

	string res = getPropertyType(e1->stringOrId, program, e1->left->exprRes);
	if (res != "")
	{
		e1->exprRes = res;
		string clName = e1->left->exprRes;
		if (e1->left->exprRes.find('[') != -1)
			clName = "MyLib/Array";
		e1->refInfo = findFieldRefOrAdd(clName, e1->stringOrId,
			transformTypeToDescriptor(res.c_str(), program));
		return;
	}

	string message = "EXCEPTION! Call of unknown field \"";
	exception e((message + string(e1->stringOrId) + "\" in method - " + methodKey + "\n").c_str());
	throw e;
}

//Генерирует параметр className для methodRef для стандартных методов с особенностями
string* generateMethodRefParams(const string& methodName, const string& className, 
	int paramsCount)
{
	string* res = new string[3];
	res[0] = "";
	res[1] = "";
	res[2] = "";
	if (methodName == "equals" && paramsCount == 1)
	{
		res[0] = "MyLib/Any";
		res[1] = methodName;
		res[2] = "(LMyLib/Any;)LMyLib/Boolean;";
		return res;
	}

	if (methodName == "toMyString" && paramsCount == 0)
	{
		res[0] = "MyLib/Any";
		res[1] = methodName;
		res[2] = "()LMyLib/MyString;";
		return res;
	}

	if (className == "MyLib/Char" || className == "MyLib/Boolean" ||
		className == "MyLib/Double" || className == "MyLib/Float" || 
		className == "MyLib/Int" || className == "MyLib/MyString")
	{
		if (className == "MyLib/MyString" && methodName == "add" && paramsCount == 1)
		{
			res[0] = "MyLib/MyString";
			res[1] = methodName;
			res[2] = "(LMyLib/Any;)LMyLib/MyString;";
			return res;
		}

		if ((methodName == "less" || methodName == "more" || 
			methodName == "or" || methodName == "and" || 
			methodName == "equal" || methodName == "notEqual" || 
			methodName == "lessOrEqual" || methodName == "moreOrEqual")
			&& paramsCount == 1)
		{
			res[0] = className;
			res[1] = methodName;
			res[2] = "(LMyLib/CalculatedClass;)LMyLib/Boolean;";
			return res;
		}
		else if ((methodName == "not" || methodName == "unaryPlus" || methodName == "unaryMinus")
			&& paramsCount == 0)
		{
			res[0] = className;
			res[1] = methodName;
			res[2] = "()L";
			res[2] += className + ";";
			return res;
		}
	}

	if (className == "MyLib/Array" || className.find('[') != -1)
	{
		if (methodName == "add" && paramsCount == 1)
		{
			res[0] = "MyLib/Array";
			res[1] = methodName;
			res[2] = "(Ljava/lang/Object;)LMyLib/Array;";
			return res;
		}
		else if (methodName == "addAssign" && paramsCount == 1)
		{
			res[0] = "MyLib/Array";
			res[1] = methodName;
			res[2] = "(Ljava/lang/Object;)V";
			return res;
		}
		else if (methodName == "get" && paramsCount == 1)
		{
			res[0] = "MyLib/Array";
			res[1] = methodName;
			res[2] = "(LMyLib/Int;)Ljava/lang/Object;";
			return res;
		}
		else if (methodName == "set" && paramsCount == 1)
		{
			res[0] = "MyLib/Array";
			res[1] = methodName;
			res[2] = "(LMyLib/Int;)V";
			return res;
		}
		else if ((methodName == "component1" || methodName == "component2" ||
			methodName == "component3" || methodName == "component4"
			|| methodName == "component5")&& paramsCount == 0)
		{
			res[0] = "MyLib/Array";
			res[1] = methodName;
			res[2] = "()Ljava/lang/Object;";
			return res;
		}
	}

	return res;
}

void ClassFile::calcTypeOfMethodCalcExpr(exprS* e1, programS* program, const string& methodKey)
{
	int paramsCount = calcType(e1->factParams, program, methodKey);
	calcType(e1->left, program, methodKey);
	checkUnitOperandsInExpr(e1, methodKey);

	string res = getMethodTypeForUserClass(createShortInfo(e1), program, e1->left->exprRes);
	//Если у класса есть такой метода
	if (res != "")
	{
		e1->exprRes = res;
		e1->refInfo = findMethodRefOrAdd(e1->left->exprRes, e1->stringOrId,
			transformMethodCallToDescriptor(e1, program));
		return;
	}
	
	res = getMethodTypeForStandartClass(createShortInfo(e1), e1->left->exprRes);
	if (res != "")
	{
		e1->exprRes = res;
		if (strcmp(e1->stringOrId, "toString") == 0 && paramsCount == 0)
		{
			char* tmp = new char[strlen("toMyString") + 1];
			strcpy(tmp, "toMyString");
			e1->stringOrId = tmp;
		}

		//Если метод toMyString, Equals или метод массива
		if (strcmp(e1->stringOrId, "toMyString") == 0 && paramsCount == 0 ||
			strcmp(e1->stringOrId, "toMyString") == 0 && paramsCount == 0 || 
			e1->left->exprRes.find('[') != -1)
		{
			string* params = generateMethodRefParams(e1->stringOrId, e1->left->exprRes, paramsCount);
			if (params[0] == "" || params[1] == "" || params[2] == "")
			{
				throw exception("EXCEPTION! Unknown my std method name\n");
			}
			e1->refInfo = findMethodRefOrAdd(params[0], params[1], params[2]);
		}
		//Если методы toChar(), toInt()...
		else
		{
			e1->refInfo = findMethodRefOrAdd(e1->left->exprRes, e1->stringOrId,
				transformMethodCallToDescriptor(e1, program));
		}
		return;
	}

	string message = "EXCEPTION! Call of unknown method \"";
	exception e((message + string(e1->stringOrId) + "\" in method - " + methodKey + "\n").c_str());
	throw e;
}

void ClassFile::calcTypeOfArrayElementCall(exprS* e1, programS* program, const string& methodKey)
{
	if (e1->type != ArrayElementCall)
		return;

	calcType(e1->left, program, methodKey);
	calcType(e1->right, program, methodKey);
	checkUnitOperandsInExpr(e1, methodKey);

	if (e1->right->exprRes != "MyLib/Int")
	{
		string message = "EXCEPTION! Not integer index  in method \"";
		exception e((message, methodKey + "\"\n").c_str());
		throw e;
	}


	if (strstr(e1->left->exprRes.c_str(), "[]") != 0 || e1->left->exprRes == "MyLib/MyString")
	{
		e1->type = MethodCalcExpr;
		e1->factParams = createFactParamsList(e1->right);
		e1->right = 0;
		
		char* methodName = new char[4];
		strcpy(methodName, "get");
		e1->stringOrId = methodName;
		if (strstr(e1->left->exprRes.c_str(), "[]") != 0)
		{
			//В возвращаемом значении уменьшить количество []
			string res = e1->left->exprRes;
			res.pop_back();
			res.pop_back();
			e1->exprRes = res;
			e1->refInfo = findMethodRefOrAdd("MyLib/Array", "get", "(LMyLib/Int;)Ljava/lang/Object;");
		}

		if (e1->left->exprRes == "MyLib/MyString")
		{
			e1->exprRes = "MyLib/Char";
			e1->refInfo = findMethodRefOrAdd("MyLib/MyString", "get", "(LMyLib/Int;)LMyLib/Char;");
		}

		return;
	}
			
	string message = "EXCEPTION! Try to get index of not array or string object in method \"";
	exception e((message + methodKey + "\"\n").c_str());
	throw e;

}

void ClassFile::calcTypeOfParentFieldCall(exprS* e1, programS* program, const string& methodKey)
{
	if (e1->type != ParentFieldCall)
		return;

	if (parentClassName == "MyLib/Any" || parentClassName == "")
	{
		string message = "EXCEPTION! Call of unknown parent field \"";
		exception e((message + string(e1->stringOrId) + "\" in method - " + methodKey + "\n").c_str());
		throw e;
	}

	//Найти поле в классе
	string res = getPropertyType(e1->stringOrId, program, parentClassName);
	if (res != "")
	{
		e1->exprRes = res;
		e1->refInfo = findFieldRefOrAdd(parentClassName, e1->stringOrId,
			transformTypeToDescriptor(res.c_str(), program));
		addParentOrThisToExpr(e1, parentClassName, true);
		return;
	}

	string message = "EXCEPTION! Call of unknown parent field \"";
	exception e((message + string(e1->stringOrId) + "\" in method - " + methodKey + "\n").c_str());
	throw e;
	
}

void ClassFile::calcTypeOfParentMethodCall(exprS* e1, programS* program, const string& methodKey)
{
	if (e1->type != ParentMethodCall)
		return;

	int paramsCount = calcType(e1->factParams, program, methodKey);
	checkUnitOperandsInExpr(e1, methodKey);

	if (parentClassName == "")
	{
		string message = "EXCEPTION! Call of unknown parent method \"";
		exception e((message + string(e1->stringOrId) + "\" in method - " + methodKey + "\n").c_str());
		throw e;
	}

	addParentOrThisToExpr(e1, parentClassName, true);
	string res = getMethodTypeForUserClass(createShortInfo(e1), program, parentClassName);
	if (res != "")
	{
		e1->exprRes = res;
		e1->refInfo = findMethodRefOrAdd(parentClassName, e1->stringOrId, 
			transformMethodCallToDescriptor(e1, program));
		return;
	}

	res = getMethodTypeForStandartClass(createShortInfo(e1), parentClassName);
	if (res != "")
	{
		//заменить вызов toString
		if (strcmp(e1->stringOrId, "toString") == 0 && paramsCount == 0)
		{
			char* tmp = new char[strlen("toMyString") + 1];
			strcpy(tmp, "toMyString");
			e1->stringOrId = tmp;
		}
		e1->exprRes = res;
		string* params = generateMethodRefParams(e1->stringOrId, parentClassName, paramsCount);
		if (params[0] == "" || params[1] == "" || params[2] == "")
		{
			throw exception("EXCEPTION! Unknown my std method name\n");
		}
		e1->refInfo = findMethodRefOrAdd(parentClassName, e1->stringOrId, params[2]);
		return;
	}

	string message = "EXCEPTION! Call of unknown parent method \"";
	exception e((message + string(e1->stringOrId) + "\" in method - " + methodKey + "\n").c_str());
	throw e;
}

void ClassFile::calcTypeOfLiterals(exprS* e1, const string& methodKey)
{
	if (e1->type != Int && e1->type != Double && e1->type != Float &&
		e1->type != String && e1->type != Char && e1->type != Boolean)
		return;

	string exprRes = "";
	string descr = "";
	exprS* newOperand = 0;

	if (e1->type == Int)
	{
		exprRes = "MyLib/Int";
		newOperand = createExpr(e1->intV, Int);
		if (e1->intV > 32767 || e1->intV < -32768)
			newOperand->refInfo = findIntOrAdd(e1->intV);
		newOperand->exprRes = "int";
		descr = "(I)V";
		e1->intV = 0;
	}
	else if (e1->type == Double)
	{
		exprRes = "MyLib/Double";
		newOperand = createExpr(e1->doubleV, Double);
		newOperand->refInfo = findDoubleOrAdd(e1->doubleV);
		newOperand->exprRes = "double";
		descr = "(D)V";
		e1->doubleV = 0;
	}
	else if (e1->type == Float)
	{
		exprRes = "MyLib/Float";
		newOperand = createExpr(e1->floatV, Float);
		newOperand->refInfo = findFloatOrAdd(e1->floatV);
		newOperand->exprRes = "Float";
		descr = "(F)V";
		e1->floatV = 0;
	}
	else if (e1->type == Char)
	{
		exprRes = "MyLib/Char";
		newOperand = createExpr(e1->charV, Char);
		newOperand->exprRes = "Char";
		descr = "(C)V";
		e1->charV = 0;
	}
	else if (e1->type == String)
	{
		exprRes = "MyLib/MyString";
		newOperand = createExpr(e1->stringOrId, String);
		string value = string(e1->stringOrId);
		newOperand->refInfo = findStringOrAdd(value);
		newOperand->exprRes = "String";
		descr = "(Ljava/lang/String;)V";
		e1->stringOrId = 0;
	}
	else if (e1->type == Boolean)
	{
		exprRes = "MyLib/Boolean";
		newOperand = createExpr(e1->booleanV, Boolean);
		newOperand->exprRes = "Boolean";
		descr = "(Z)V";
		e1->booleanV = 0;
	}
	e1->type = ConstructorCall;
	char* constructorName = new char[exprRes.size() + 1];
	strcpy(constructorName, exprRes.c_str());
	e1->stringOrId = constructorName;
	e1->classId = findClassOrAdd(exprRes);
	e1->exprRes = exprRes;
	e1->factParams = createFactParamsList(newOperand);
	e1->refInfo = findMethodRefOrAdd(exprRes, "<init>", descr);
}

void ClassFile::calcTypeOfUnaryOperators(exprS* e1, programS* program, const string& methodKey)
{
	if (e1->type != LogicalNot && e1->type != UnaryMinusExpr &&
		e1->type != UnaryPlusExpr)
		return;

	calcType(e1->left, program, methodKey);
	checkUnitOperandsInExpr(e1, methodKey);
	
	e1->type = MethodCalcExpr;
	string methodName;
	if (e1->type == LogicalNot)
		methodName = "not";
	else if (e1->type == UnaryPlusExpr)
		methodName = "unaryPlus";
	else
		methodName = "unaryMinus";
	char* tmp = new char[methodName.size() + 1];
	strcpy(tmp, methodName.c_str());
	e1->stringOrId = tmp;

	string res = getOperatorTypeForStandartClass(createShortInfo(e1), e1->left->exprRes);
	if (res != "")
	{
		e1->exprRes = res;
		string* params;
		params = generateMethodRefParams(methodName, e1->left->exprRes, 0);
		if (params[0] == "" || params[1] == "" || params[2] == "")
		{
			throw exception("EXCEPTION! Unknown my std method name\n");
		}
		e1->refInfo = findMethodRefOrAdd(params[0], params[1], params[2]);
		return;
	}

	//Ошибки
	if (methodName == "not")
	{
		string message = "EXCEPTION! Incorrect operator! operand with not boolean type in method - ";
		exception e((message + methodKey + "\n").c_str());
		throw e;
	}
	
	string message = "EXCEPTION! Incorrect operator+ (unary) operand with not number type in method - ";
	exception e((message + methodKey + "\n").c_str());
	throw e;
}


//Преобразуем операцию в аналогичный метод
char* transformOperatorToString(exprType type)
{
	char* res = new char[3];
	res[0] = 0;
	switch (type)
	{
	case Sum:
		strcpy(res, "+");
		break;
	case Sub:
		strcpy(res, "-");
		break;
	case Mul:
		strcpy(res, "*");
		break;
	case Div:
		strcpy(res, "/");
		break;
	case Less:
		strcpy(res, "<");
		break;
	case More:
		strcpy(res, ">");
		break;
	case Or:
		strcpy(res, "||");
		break;
	case And:
		strcpy(res, "&&");
		break;
	case Eq:
		strcpy(res, "==");
		break;
	case Neq:
		strcpy(res, "!=");
		break;
	case Loeq:
		strcpy(res, "<=");
		break;
	case Moeq:
		strcpy(res, ">=");
		break;
	}

	return res;
}

//Преобразуем операцию в аналогичный метод
char* transformOperatorToMethod(exprType type)
{
	string res = "";
	switch (type)
	{
	case Sum:
		res = "add";
		break;
	case Sub:
		res = "sub";
		break;
	case Mul:
		res = "mul";
		break;
	case Div:
		res = "div";
		break;
	case Less:
		res = "less";
		break;
	case More:
		res = "more";
		break;
	case Or:
		res = "or";
		break;
	case And:
		res = "and";
		break;
	case Eq:
		res = "equal";
		break;
	case Neq:
		res = "notEqual";
		break;
	case Loeq:
		res = "lessOrEqual";
		break;
	case Moeq:
		res = "moreOrEqual";
		break;
	}

	char* str = new char[res.size() + 1];
	strcpy(str, res.c_str());
	return str;
}


void ClassFile::calcTypeOfSum(exprS* e1, programS* program, const string & methodKey)
{
	if (e1->type != Sum)
		return;

	calcType(e1->left, program, methodKey);
	calcType(e1->right, program, methodKey);
	checkUnitOperandsInExpr(e1, methodKey);

	
	e1->stringOrId = transformOperatorToMethod(e1->type);
	e1->type = MethodCalcExpr;
	e1->factParams = createFactParamsList(e1->right);
	e1->right = 0;

	//Если в результате операции появился массив
	string res = getOperatorTypeForStandartClass(createShortInfo(e1), e1->left->exprRes);
	if (res == "MyLib/Array")
	{
		string arrayType = e1->left->exprRes;
		arrayType.pop_back();
		arrayType.pop_back();
		e1->exprRes = calcParentClass(arrayType, e1->factParams->first->exprRes, program);
		e1->exprRes.push_back('[');
		e1->exprRes.push_back(']');
		string* params = generateMethodRefParams("add", e1->left->exprRes, 1);
		if (params[0] == "" || params[1] == "" || params[2] == "")
		{
			throw exception("EXCEPTION! Unknown my std method name\n");
		}
		e1->refInfo = findMethodRefOrAdd(params[0], params[1], params[2]);		
		return;
	}

	if (res != "")
	{
		e1->exprRes = res;
		string* params = new string[3];
		if (e1->left->exprRes == "MyLib/MyString")
		{
			params = generateMethodRefParams("add", e1->left->exprRes, 1);
			if (params[0] == "" || params[1] == "" || params[2] == "")
			{
				throw exception("EXCEPTION! Unknown my std method name\n");
			}
		}
		else
		{
			params[0] = e1->left->exprRes;
			params[1] = "add";
			params[2] = transformMethodCallToDescriptor(e1, program);
		}
		e1->refInfo = findMethodRefOrAdd(params[0], params[1], params[2]);
		return;
	}

	string message = "EXCEPTION! Incorrect operator+ operands";
	exception e((message + " in method - " + methodKey + "\n").c_str());
	throw e;
}

void ClassFile::calcTypeOfOtherArithmeticOperations(exprS* e1, programS* program,
	const string& methodKey)
{
	if (e1->type != Sub && e1->type != Mul && e1->type != Div && e1->type != Less &&
		e1->type != More && e1->type != Or && e1->type != And && e1->type != Eq &&
		e1->type != Neq && e1->type != Loeq && e1->type != Moeq)
		return;

	calcType(e1->left, program, methodKey);
	calcType(e1->right, program, methodKey);
	checkUnitOperandsInExpr(e1, methodKey);

	string* params = new string[3];
	char* operatorName = transformOperatorToMethod(e1->type);
	char* operanorSymbol = transformOperatorToString(e1->type);
	exprType exprTypeBeforeTransforming = e1->type;
	e1->type = MethodCalcExpr;
	e1->factParams = createFactParamsList(e1->right);
	e1->right = 0;
	e1->stringOrId = operatorName;

	string res = getOperatorTypeForStandartClass(createShortInfo(e1), e1->left->exprRes);
	if (res != "")
	{
		e1->exprRes = res;
		if (exprTypeBeforeTransforming != Sub && exprTypeBeforeTransforming != Mul &&
			exprTypeBeforeTransforming != Div)
		{
			params = generateMethodRefParams(operatorName, e1->left->exprRes, 1);
			if (params[0] == "" || params[1] == "" || params[2] == "")
			{
				throw exception("EXCEPTION! Unknown my std method name\n");
			}
		}
		else
		{
			params[0] = e1->left->exprRes;
			params[1] = e1->stringOrId;
			params[2] = transformMethodCallToDescriptor(e1, program);
		}
		e1->refInfo = findMethodRefOrAdd(params[0], params[1],
			params[2]);

		return;
	}

	string message = "EXCEPTION! Incorrect operator";
	message += operanorSymbol;
	message += " operands in method - " + methodKey + "\n";
	exception e(message.c_str());
	throw e;
}

void ClassFile::calcType(exprS* e1, programS* program, const string& methodKey)
{
	if (e1->type == Identificator)
	{
		calcTypeOfIdentifier(e1, program, methodKey);
	}
	else if (e1->type == This)
	{
		auto method = methodTable.at(methodKey);
		if (method.isStaticMethod())
		{
			string message = "EXCEPTION! Call THIS in static method \"";
			exception e((message + methodKey + "\"\n").c_str());
			throw e;
		}
		e1->varInTableNum = 0;
		e1->exprRes = method.find(0).type;
	}
	else if (e1->type == MethodCall)
	{
		calcTypeOfMethodCall(e1, program, methodKey);
	}
	else if (e1->type == FieldCalcExpr)
	{
		calcTypeOfFieldCalsExpr(e1, program, methodKey);
	}
	else if (e1->type == MethodCalcExpr)
	{
		calcTypeOfMethodCalcExpr(e1, program, methodKey);
	}
	else if (e1->type == ArrayElementCall)
	{
		calcTypeOfArrayElementCall(e1, program, methodKey);
	}
	else if (e1->type == ParentFieldCall)
	{
		calcTypeOfParentFieldCall(e1, program, methodKey);
	}
	else if (e1->type == ParentMethodCall)
	{
		calcTypeOfParentMethodCall(e1, program, methodKey);
	}
	else if (e1->type == Int || e1->type == Double || e1->type == Float ||
		e1->type == String || e1->type == Char || e1->type == Boolean)
	{
		calcTypeOfLiterals(e1, methodKey);
	}
	else if (e1->type == Range)
	{
		string message = "EXCEPTION! Unsupported range out of FOR loop in method - ";
		exception e((message + methodKey + "\n").c_str());
		throw e;
	}
	else if (e1->type == LogicalNot || e1->type == UnaryPlusExpr || e1->type == UnaryMinusExpr)
	{
		calcTypeOfUnaryOperators(e1, program, methodKey);
	}
	else if (e1->type == Sum)
	{
		calcTypeOfSum(e1, program, methodKey);
	}
	else if (e1->type == Sub || e1->type == Mul || e1->type == Div || e1->type == Less ||
		e1->type == More || e1->type == Or || e1->type == And || e1->type == Eq ||
		e1->type == Neq || e1->type == Loeq || e1->type == Moeq)
	{
		calcTypeOfOtherArithmeticOperations(e1, program, methodKey);
	}
	else if (e1->type == Mod)
	{
		string message = "EXCEPTION! Unsupported operator% in method - ";
		exception e((message + methodKey + "\n").c_str());
		throw e;
	}
}

//type1 - к чему приводить, type2 - что приводить
bool canCastType(const string& type1, const string& type2, const programS* const program)
{
	if (type1 == "MyLib/Any")
		return true;

	if (type1 == type2)
		return true;

	if (isParentClass(type1, type2, program))
		return true;

	if (type1.find('[') != -1 && type2.find('[') != -1)
	{
		string subType1 = type1;
		string subType2 = type2;
		while (subType1.find('[') != -1 && subType2.find('[') != -1)
		{
			subType1.pop_back();
			subType2.pop_back();
		}
		return canCastType(subType1, subType2, program);
	}
	

	return false;
}

void ClassFile::addConstantsFrom(varOrValDeclS* v, programS* program, const string& methodKey)
{
	MethodTableElement res = methodTable.at(methodKey);
	v->varNumber = res.addLocalVar(v);
	methodTable.at(methodKey) = res;
	if (v->initValue != 0)
	{
		calcType(v->initValue, program, methodKey);
		checkUnitOperandsInExpr(v->initValue, methodKey);
		if (strcmp(v->type->easyType.c_str(), v->initValue->exprRes.c_str()) != 0)
		{
			if (!canCastType(v->type->easyType, v->initValue->exprRes, program) ||
				v->type->easyType.find('[') != -1 && v->initValue->exprRes.find('[') != -1 &&
				v->type->easyType != v->initValue->exprRes)
			{
				string message = "EXCEPTION! Cast error. Cannot cast \"";
				exception e((message + string(v->type->easyType) + "\" of variable \"" + string(v->id) + 
					"\" to type \"" + v->initValue->exprRes + "\"\n").c_str());
				throw e;
			}
		}
	}
	
}

void ClassFile::addConstantsFrom(assignmentS* a, programS* program, const string& methodKey)
{
	if (a->left->type != Identificator && a->subLeft == 0 && a->fieldName == 0)
	{
		string message = "EXCEPTION! Not l-value expr in assignment in method -" + methodKey + "\n";
		exception e(message.c_str());
		throw e;
	}
	
	if (a->type != Assign && a->type != AssignToArray && a->type != AssignToField)
	{
		string message = "EXCEPTION! Unsupported +=, -=, /=, *=, %= operators in method -" + methodKey + "\n";
		exception e(message.c_str());
		throw e;
	}

	calcType(a->left, program, methodKey);
	calcType(a->right, program, methodKey);
	if (a->subLeft != 0)
		calcType(a->subLeft, program, methodKey);
	checkUnitOperandsInExpr(a, methodKey);

	if (a->subLeft == 0 && a->fieldName == 0)
	{
		if (a->left->type == FieldCalcExpr)
		{
			a->type = AssignToField;
			a->fieldName = a->left->stringOrId;
			a->left = a->left->left;
		}
		else
		{
			if (a->left->exprRes != a->right->exprRes)
			{
				//Если типы можно привести
				if (!canCastType(a->left->exprRes, a->right->exprRes, program) || 
					a->left->exprRes.find('[') != -1 && a->right->exprRes.find('[') != -1 &&
					a->left->exprRes != a->right->exprRes)
				{
					string message = "EXCEPTION! Cast error. Cannot cast \"" + a->left->exprRes +
						"\" to type \"" + a->right->exprRes + "\" in assignment in method \"" +
						methodKey + "\"\n";
					exception e(message.c_str());
					throw e;
				}
			}
			//Cлева не константа, у которой уже есть значение
			LocalVariableInfo varInfo = methodTable.at(methodKey).find(a->left->varInTableNum);
			if (varInfo.isConst && varInfo.hasValue)
			{
				string message = "EXCEPTION! Assignment to contant value " + varInfo.name + " in method \""
					+ methodKey + "\"\n";
				exception e(message.c_str());
				throw e;
			}
		}		
	}
	if(a->subLeft != 0 || a->fieldName != 0)
	{
		if (a->type == AssignToField)
		{
			string res = getPropertyType(a->fieldName, program, a->left->exprRes);
			
			if (res == "")
			{
				string message = "EXCEPTION! Assignment to unknown property \"" + string(a->fieldName) +
					"\" in method - \"" + methodKey + "\"\n";
				exception e(message.c_str());
				throw e;
			}

			//Если типы найденного поля и правой части не совпадают
			if (res != a->right->exprRes)
			{
				//Если типы можно привести
				if (!canCastType(res, a->right->exprRes, program) ||
					res.find('[') != -1 && a->right->exprRes.find('[') != -1 && 
					res != a->right->exprRes)
				{
					string message = "EXCEPTION! Cast error. Cannot cast \"" + res +
						"\" to type \"" + a->right->exprRes + "\" in assignment in method \"" + 
						methodKey + "\"\n";
					exception e(message.c_str());
					throw e;
				}
			}

			//Если пытаются присвоить значение полю массива или строки с длинной
			if (a->left->exprRes.find('[') != -1 || a->left->exprRes == "MyLib/MyString")
			{
				string message = "EXCEPTION! Assignment to constant property \"" + string(a->fieldName) +
					"\" in method - \"" + methodKey + "\"\n";
				exception e(message.c_str());
				throw e;
			}

			a->refInfo = findFieldRefOrAdd(a->left->exprRes, a->fieldName, 
				transformTypeToDescriptor(res.c_str(), program));			
		}
		else
		{
			if (a->subLeft->exprRes != "MyLib/Int")
			{
				char message[] = "EXCEPTION! Not integer array index in assignment \n";
				exception e(message);
				throw e;
			}

			//Сравнить тип левой части без [] с правой частью
			string exprRes = a->left->exprRes;
			exprRes.pop_back();
			exprRes.pop_back();
			if (!canCastType(exprRes, a->right->exprRes, program) ||
				exprRes.find('[') != -1 && a->right->exprRes.find('[') != -1 &&
				exprRes != a->right->exprRes)
			{
				string message = "EXCEPTION! Cast error. Cannot cast \"" + exprRes +
					"\" to type \"" + a->right->exprRes + "\" in assignment in method \"" +
					methodKey + "\"\n";
				exception e(message.c_str());
				throw e;
			}

			a->refInfo = findMethodRefOrAdd("MyLib/Array", "set", "(LMyLib/Int;Ljava/lang/Object;)V");
		}
	}
}

exprS* addToBoolean(exprS* e)
{
	char* methodName = new char[strlen("getV") + 1];
	strcpy(methodName, "getV");
	exprS* newCondition = createExpr(e, methodName, 0, MethodCalcExpr);
	newCondition->exprRes = "Boolean";
	return newCondition;
}

bool ClassFile::addConstantsFrom(whileLoopS* w, programS* program, const string& methodKey)
{
	methodTable.at(methodKey).incNestingLevel();
	calcType(w->cond, program, methodKey);

	bool res = true;

	if (w->cond->exprRes != "MyLib/Boolean")
	{
		string message = "EXCEPTION! If statment condition is not Boolean";
		exception e(message.c_str());
		throw e;
	}

	//Приводим MyLib/Boolean к boolean
	w->cond = addToBoolean(w->cond);
	w->cond->refInfo = findMethodRefOrAdd("MyLib/Boolean", "getV", "()Z");

	if (w->stmts != 0)
	{
		bool tmp = addConstantsFrom(w->stmts, program, methodKey);
		res = res && tmp;
	}

	methodTable.at(methodKey).decNestingLevel();
	return res;
}

void ClassFile::addConstantsFrom(forLoopS* f, programS* program, const string& methodKey)
{
	exception e("EXCEPTION! Unsupported FOR loop \n");
	throw e;

	/*methodTable.at(methodKey).incNestingLevel();
	if (f->iterableExpr->type == Range)
	{

	}
	calcType(f->iterableExpr, program, methodKey);

	//Проверить переменную
	//Проверить условие
	//Проверить все stmt цикла*/
}

bool ClassFile::addConstantsFrom(ifStmtS* i, programS* program, const string& methodKey)
{
	methodTable.at(methodKey).incNestingLevel();
	calcType(i->condition, program, methodKey);

	bool res = true;

	if (i->condition->exprRes != "MyLib/Boolean")
	{
		string message = "EXCEPTION! If statment condition is not Boolean";
		exception e(message.c_str());
		throw e;
	}

	i->condition = addToBoolean(i->condition);
	i->condition->refInfo = findMethodRefOrAdd("MyLib/Boolean", "getV", "()Z");

	if (i->actions != 0)
	{
		bool tmp = addConstantsFrom(i->actions, program, methodKey);
		res = res && tmp;
	}

	if (i->altActions != 0)
	{
		bool tmp = addConstantsFrom(i->altActions, program, methodKey);
		res = res && tmp;
	}
	methodTable.at(methodKey).decNestingLevel();
	return res;
}

void transformForLoop(stmtS* forLoop)
{
	/*//Если цикл с range
	stmtS* newStmt;
	if (forLoop->forLoop->iterableExpr->type == Range)
	{
		

		varOrValDeclS* loopVar = createVarOrValDecl(forLoop->forLoop->params->first->name,
			forLoop->forLoop->params->first->type, forLoop->forLoop->iterableExpr->left, 1);
		char* tmp = new char[4];
		strcpy(tmp, "Inc");
		auto newExpr = createExpr(tmp, 0, Inc);
		forLoop->forLoop->stmts = addToStmtList(forLoop->forLoop->stmts, createStmt(newExpr, Expr));
		tmp = new char[6];
		strcpy(tmp, "cond$");
		varOrValDeclS* condition = createVarOrValDecl(,
			forLoop->forLoop->params->first->type, forLoop->forLoop->iterableExpr->left, 1);

		newStmt = createStmt(forLoop->)
	}
	else
	{

	}
	*/
}

void ClassFile::checkReturnValue(const string& res, const string& methodSign, 
	const programS* const program)
{
	if (methodSign.find('<') != -1 && res != "")
	{
		string message = "EXCEPTION! Return value of " + methodSign + " is not Unit";
		exception e(message.c_str());
		throw e;
	}
	else
	{
		string methodRetValue = getMethodType(methodSign, program, className);
		if (methodRetValue == "MyLib/Unit" && res != "")
		{
			string message = "EXCEPTION! Return value of " + methodSign + " is not Unit";
			exception e(message.c_str());
			throw e;
		}

		if (methodRetValue != "MyLib/Unit" && !canCastType(methodRetValue, res, program))
		{
			string message = "EXCEPTION! Return value of " + methodSign + " cannot be cast to - " + 
				methodRetValue;
			exception e(message.c_str());
			throw e;
		}
	}
	
}

bool ClassFile::addConstantsFrom(stmtS* stmt, programS* program, const string& methodKey)
{
	
	if (stmt->type == Continue)
	{
		exception e("EXCEPTION! Unsupported CONTINUE operator");
		throw e;
	}

	if (stmt->type == Break)
	{
		exception e("EXCEPTION! Unsupported BREAK operator");
		throw e;
	}

	bool res = true;
	bool tmp = true;
	switch (stmt->type)
	{
	case VarOrVal:
		addConstantsFrom(stmt->varOrVal, program, methodKey);
		break;
	case Assignment:
		addConstantsFrom(stmt->assignment, program, methodKey);
		break;
	case WhileLoop:
		tmp = addConstantsFrom(stmt->whileLoop, program, methodKey);
		res = res && tmp;
		break;
	case ForLoop:
		addConstantsFrom(stmt->forLoop, program, methodKey);
		break;
	case DoWhileLoop:
		tmp = addConstantsFrom(stmt->whileLoop, program, methodKey);
		res = res && tmp;
		break;
	case IfStmt:
		tmp = addConstantsFrom(stmt->ifStmt, program, methodKey);
		res = res && tmp;
		break;
	case Expr:
		calcType(stmt->expr, program, methodKey);
		break;
	case ReturnValue:
		calcType(stmt->expr, program, methodKey);
		checkUnitOperandsInExpr(stmt->expr, methodKey);
		checkReturnValue(stmt->expr->exprRes, methodKey, program);
		break;
	case Return:
		checkReturnValue("", methodKey, program);
		break;
	}
	
	return res;
}

bool ClassFile::addConstantsFrom(stmtList* stmts, programS* program, const string& methodKey)
{
	bool res = true;
	bool tmp = true;
	if (stmts != 0)
		for (stmtS* stmt = stmts->first; stmt != 0; stmt = stmt->next)
		{
			try
			{
				tmp = addConstantsFrom(stmt, program, methodKey);
				res = res && tmp;
			}
			catch (exception e)
			{
				printf(e.what());
				res = false;
			}
			
		}

	return res;
}

bool ClassFile::addConstantsFrom(methodS* meth, programS* program)
{
	//Загружаем указатель на объект
	string methKey = createMethodSignature(meth);
	if (!methodTable.at(methKey).isStaticMethod())
	{
		auto methodTableElement = methodTable.at(methKey);
		methodTableElement.addLocalVar(new LocalVariableInfo(true, true, "this$", className, 
			methodTableElement.getNestingLevel()));
		methodTable.at(methKey) = methodTableElement;
	}

	//Загружаем локальные переменные
	if (meth->func->decl->params != 0)
	{
		auto methodTableElement = methodTable.at(methKey);
		for (formalParamS* fp = meth->func->decl->params->first; fp != 0; fp = fp->next)
		{
			methodTableElement.addLocalVar(new LocalVariableInfo(true, true, fp->name, 
				fp->type->easyType, methodTableElement.getNestingLevel()));
		}
		methodTable.at(methKey) = methodTableElement;
	}

	if (meth->func->stmts != 0)
	{

		return addConstantsFrom(meth->func->stmts, program, methKey);
	}	
	return true;
}

string ClassFile::constsTableToStr() {
	string result = "";
	int len = constsTable.size();
	for (int i = 0; i < len; i++) {
		result.append(to_string(i + 1) + '\t' + constsTable[i].to_str());
	}
	return result;
}

int MethodTableElement::addLocalVar(varOrValDeclS* varOrValDecl)
{
	auto varInfo = new LocalVariableInfo(varOrValDecl->isVal, varOrValDecl->initValue != 0,
		varOrValDecl->id, varOrValDecl->type->easyType, nestingLevel);
	return addLocalVar(varInfo);
}

int MethodTableElement::addLocalVar(LocalVariableInfo* varOrValDecl)
{
	if (std::find(localVarsAndConsts.begin(), localVarsAndConsts.end(), *varOrValDecl)
		!= localVarsAndConsts.end())
	{
		string message = "EXCEPTION! Redefine of variable \"";
		exception e((message + string(varOrValDecl->name) + "\"\n").c_str());
		throw e;
	}

	localVarsAndConsts.push_back(*varOrValDecl);
	return localVarsAndConsts.size() - 1;
}


void MethodTableElement::incNestingLevel()
{
	this->nestingLevel++;
}

void MethodTableElement::decNestingLevel()
{
	if (this->nestingLevel > 0)
	{

		for (auto i = localVarsAndConsts.begin(); i != localVarsAndConsts.end(); ++i)
		{
			if ((*i).nestingLevel == nestingLevel)
			{
				(*i).name = "";
			}
		}

		this->nestingLevel--;
	}
}


int MethodTableElement::find(string varOrValName)
{
	LocalVariableInfo tmp(0, 0, varOrValName, "", nestingLevel);
	
	int num = 0;
	int index = -1;
	for (auto i = localVarsAndConsts.begin(); i != localVarsAndConsts.end(); ++i)
	{
		if ((*i).nestingLevel <= nestingLevel && (*i).name == tmp.name)
			index = num;
		num++;
	}

	return index;
}

LocalVariableInfo MethodTableElement::find(int indexInTable)
{
	LocalVariableInfo tmp(0, 0, "", "", nestingLevel);

	int index = 0;
	for (auto i : localVarsAndConsts)
	{
		if (index == indexInTable)
			tmp = i;
		index++;
	}

	return tmp;
}

vector<char> generate(exprS* expr)
{
	vector<char> resultCode;
	vector<char> tmp;
	int currentParamNum = 0;
	int paramsCount = 0;
	switch (expr->type)
	{
	case ParentConstrCall:
		resultCode.push_back((char)Command::aload_0);
		resultCode.push_back((char)Command::invokespecial);
		tmp = intToBytes(expr->refInfo);
		resultCode.push_back(tmp[2]);
		resultCode.push_back(tmp[3]);
		break;
	case ConstructorCall:
		resultCode.push_back((char)Command::new_);
		tmp = intToBytes(expr->classId);
		resultCode.push_back(tmp[2]);
		resultCode.push_back(tmp[3]);
		resultCode.push_back((char)Command::dup);
		//Заносим параметры конструктора
		if (expr->factParams != 0) 
		{
			for (auto fp = expr->factParams->first; fp != 0; fp = fp->next)
			{
				tmp = generate(fp);
				resultCode.insert(resultCode.end(), tmp.begin(), tmp.end());
			}
		}		
		resultCode.push_back((char)Command::invokespecial);
		tmp = intToBytes(expr->refInfo);
		resultCode.push_back(tmp[2]);
		resultCode.push_back(tmp[3]);
		break;
	case ArrayCreating:
		//Посчитать количество параметров		
		for (auto fp = expr->factParams->first; fp != 0; fp = fp->next)
			++paramsCount;
		//Создать массив
		resultCode.push_back((char)Command::bipush);
		tmp = intToBytes(paramsCount);
		resultCode.push_back(tmp[3]);
		resultCode.push_back((char)Command::anewarray);
		tmp = intToBytes(expr->classId);
		resultCode.push_back(tmp[2]);
		resultCode.push_back(tmp[3]);
		
		//Засунуть в соответствующий элемент массива параметр вызова функции
		for (auto fp = expr->factParams->first; fp != 0; fp = fp->next)
		{
			resultCode.push_back((char)Command::dup);
			tmp = intToBytes(currentParamNum);
			resultCode.push_back((char)Command::bipush);
			resultCode.push_back(tmp[3]);
			tmp = generate(fp);
			resultCode.insert(resultCode.end(), tmp.begin(), tmp.end());
			resultCode.push_back((char)Command::aastore);
			++currentParamNum;
		}
		
		//Вызвать функцию создания массива
		resultCode.push_back((char)Command::invokestatic);
		tmp = intToBytes(expr->refInfo);
		resultCode.push_back(tmp[2]);
		resultCode.push_back(tmp[3]);
		break;
	case MethodCall:
		//Заносим параметры конструктора
		if (expr->factParams != 0)
		{
			for (auto fp = expr->factParams->first; fp != 0; fp = fp->next)
			{
				tmp = generate(fp);
				resultCode.insert(resultCode.end(), tmp.begin(), tmp.end());
			}
		}
		resultCode.push_back((char)Command::invokestatic);
		tmp = intToBytes(expr->refInfo);
		resultCode.push_back(tmp[2]);
		resultCode.push_back(tmp[3]);
		break;
	case FieldCalcExpr:		
		tmp = generate(expr->left);
		resultCode.insert(resultCode.end(), tmp.begin(), tmp.end());
		resultCode.push_back((char)Command::getfield);			
		tmp = intToBytes(expr->refInfo);
		resultCode.push_back(tmp[2]);
		resultCode.push_back(tmp[3]);
		break;
	case ParentFieldCall:
		resultCode.push_back((char)Command::aload_0);
		resultCode.push_back((char)Command::getfield);
		tmp = intToBytes(expr->refInfo);
		resultCode.push_back(tmp[2]);
		resultCode.push_back(tmp[3]);
		break;
	case MethodCalcExpr:
		tmp = generate(expr->left);
		resultCode.insert(resultCode.end(), tmp.begin(), tmp.end());
		//Заносим параметры метода
		if (expr->factParams != 0)
		{
			for (auto fp = expr->factParams->first; fp != 0; fp = fp->next)
			{
				tmp = generate(fp);
				resultCode.insert(resultCode.end(), tmp.begin(), tmp.end());
			}
		}
		resultCode.push_back((char)Command::invokevirtual);
		tmp = intToBytes(expr->refInfo);
		resultCode.push_back(tmp[2]);
		resultCode.push_back(tmp[3]);
		break;
	case ParentMethodCall:
		resultCode.push_back((char)Command::aload_0);
		//Заносим параметры метода
		if (expr->factParams != 0)
		{
			for (auto fp = expr->factParams->first; fp != 0; fp = fp->next)
			{
				tmp = generate(fp);
				resultCode.insert(resultCode.end(), tmp.begin(), tmp.end());
			}
		}
		resultCode.push_back((char)Command::invokespecial);
		tmp = intToBytes(expr->refInfo);
		resultCode.push_back(tmp[2]);
		resultCode.push_back(tmp[3]);
		break;
	case Identificator:
		if (expr->isStaticCall)
		{
			resultCode.push_back((char)Command::getstatic);
			tmp = intToBytes(expr->refInfo);
			resultCode.push_back(tmp[2]);
			resultCode.push_back(tmp[3]);
		}			
		else if (expr->varInTableNum != -1)
		{
			resultCode.push_back((char)Command::aload);
			tmp = intToBytes(expr->varInTableNum);
			resultCode.push_back(tmp[3]);
		}		
		break;
	case This:
		resultCode.push_back((char)Command::aload_0);
		break;
	case Int:
		if (expr->intV < 128 && expr->intV > -129)
		{
			resultCode.push_back((char)Command::bipush);
			tmp = intToBytes(expr->intV);
			resultCode.push_back(tmp[3]);
		}
		else if (expr->intV < 32768 && expr->intV > -32769)
		{
			resultCode.push_back((char)Command::sipush);
			tmp = intToBytes(expr->intV);
			resultCode.push_back(tmp[2]);
			resultCode.push_back(tmp[3]);
		}
		else
		{
			resultCode.push_back((char)Command::ldc_w);
			tmp = intToBytes(expr->refInfo);
			resultCode.push_back(tmp[2]);
			resultCode.push_back(tmp[3]);
		}
		break;
	case String:
	case Float:		
		resultCode.push_back((char)Command::ldc_w);
		tmp = intToBytes(expr->refInfo);
		resultCode.push_back(tmp[2]);
		resultCode.push_back(tmp[3]);
		break;
	case Boolean:
		if (expr->booleanV == true)
			resultCode.push_back((char)Command::iconst_1);
		else
			resultCode.push_back((char)Command::iconst_0);
		break;
	case Char:
		resultCode.push_back((char)Command::bipush);
		resultCode.push_back(expr->charV);
		break;
	case Double:
		resultCode.push_back((char)Command::ldc2_w);
		tmp = intToBytes(expr->refInfo);
		resultCode.push_back(tmp[2]);
		resultCode.push_back(tmp[3]);
		break;
	}

	return resultCode;
}

vector<char> generate(whileLoopS* l, bool isDoWhile)
{
	vector<char> resultCode;
	vector<char> tmp;
	vector<char> code;
	vector<char> condition;

	condition = generate(l->cond);

	if (l->stmts != 0)
		code = generate(l->stmts);	
		
	if (!isDoWhile)
	{
		resultCode.push_back((char)Command::goto_);
		tmp = intToBytes(3 + code.size());
		resultCode.push_back(tmp[2]);
		resultCode.push_back(tmp[3]);
	}
	if (l->stmts != 0)
		resultCode.insert(resultCode.end(), code.begin(), code.end());
	resultCode.insert(resultCode.end(), condition.begin(), condition.end());
	resultCode.push_back((char)Command::ifne);
	tmp = intToBytes(-1 * (code.size() + condition.size()));
	resultCode.push_back(tmp[2]);
	resultCode.push_back(tmp[3]);

	return resultCode;
}

vector<char> generate(assignmentS* a)
{
	vector<char> resultCode;
	vector<char> tmp;
	if (a->left->type == Identificator && a->subLeft == 0 && a->fieldName == 0)
	{
		tmp = generate(a->right);
		resultCode.insert(resultCode.end(), tmp.begin(), tmp.end());
		if (a->left->isStaticCall)
		{
			resultCode.push_back((char)Command::putstatic);
			tmp = intToBytes(a->left->refInfo);
			resultCode.push_back(tmp[2]);
			resultCode.push_back(tmp[3]);
		}
		else
		{			
			resultCode.push_back((char)Command::astore);
			resultCode.push_back(intToBytes(a->left->varInTableNum)[3]);
		}		
	}
	else if (a->subLeft != 0)
	{
		tmp = generate(a->left);
		resultCode.insert(resultCode.end(), tmp.begin(), tmp.end());
		tmp = generate(a->subLeft);
		resultCode.insert(resultCode.end(), tmp.begin(), tmp.end());
		tmp = generate(a->right);
		resultCode.insert(resultCode.end(), tmp.begin(), tmp.end());
		resultCode.push_back((char)Command::invokevirtual);
		tmp = intToBytes(a->refInfo);
		resultCode.push_back(tmp[2]);
		resultCode.push_back(tmp[3]);
	}
	else if (a->fieldName != 0)
	{
		tmp = generate(a->left);
		resultCode.insert(resultCode.end(), tmp.begin(), tmp.end());
		tmp = generate(a->right);
		resultCode.insert(resultCode.end(), tmp.begin(), tmp.end());
		resultCode.push_back((char)Command::putfield);
		tmp = intToBytes(a->refInfo);
		resultCode.push_back(tmp[2]);
		resultCode.push_back(tmp[3]);
	}
	return resultCode;
}

vector<char> generate(varOrValDeclS* v)
{
	vector<char> resultCode;
	vector<char> tmp;
	tmp = generate(v->initValue);
	resultCode.insert(resultCode.end(), tmp.begin(), tmp.end());
	resultCode.push_back((char)Command::astore);
	resultCode.push_back(intToBytes(v->varNumber)[3]);

	return resultCode;
}

vector<char> generate(ifStmtS* i)
{
	vector<char> resultCode;
	vector<char> tmp;
	vector<char> condition = generate(i->condition);
	vector<char> trueBranch;
	vector<char> altBranch;
	if (i->actions != 0)
	{
		trueBranch = generate(i->actions);
	}
	if (i->altActions != 0)
	{
		altBranch = generate(i->altActions);
	}

	
	if (i->actions == 0 && i->altActions != 0)
	{
		condition.push_back((char)Command::ifne);
		tmp = intToBytes(altBranch.size() + 3);
		condition.push_back(tmp[2]);
		condition.push_back(tmp[3]);
	}
	else if (i->altActions == 0 && i->actions != 0)
	{
		condition.push_back((char)Command::ifeq);
		tmp = intToBytes(trueBranch.size() + 3);
		condition.push_back(tmp[2]);
		condition.push_back(tmp[3]);
	}
	else if (i->altActions != 0 && i->actions != 0)
	{
		trueBranch.push_back((char)Command::goto_);
		tmp = intToBytes(altBranch.size() + 3);
		trueBranch.push_back(tmp[2]);
		trueBranch.push_back(tmp[3]);

		condition.push_back((char)Command::ifeq);
		tmp = intToBytes(trueBranch.size() + 3);
		condition.push_back(tmp[2]);
		condition.push_back(tmp[3]);
	}

	resultCode.insert(resultCode.end(), condition.begin(), condition.end());
	if (trueBranch.size() != 0)
		resultCode.insert(resultCode.end(), trueBranch.begin(), trueBranch.end());
	if (altBranch.size() != 0)
		resultCode.insert(resultCode.end(), altBranch.begin(), altBranch.end());
	
	return resultCode;
}

vector<char> generate(stmtList* stmts)
{
	vector<char> resultCode;
	vector<char> tmp;

	for (auto stmt = stmts->first; stmt != 0; stmt = stmt->next)
	{
		switch (stmt->type)
		{
		case Expr:
			tmp = generate(stmt->expr);
			resultCode.insert(resultCode.end(), tmp.begin(), tmp.end());
			break;
		case VarOrVal:
			tmp = generate(stmt->varOrVal);
			resultCode.insert(resultCode.end(), tmp.begin(), tmp.end());
			break;
		case Assignment:
			tmp = generate(stmt->assignment);
			resultCode.insert(resultCode.end(), tmp.begin(), tmp.end());
			break;
		case WhileLoop:
			tmp = generate(stmt->whileLoop, false);
			resultCode.insert(resultCode.end(), tmp.begin(), tmp.end());
			break;
		case DoWhileLoop:
			tmp = generate(stmt->whileLoop, true);
			resultCode.insert(resultCode.end(), tmp.begin(), tmp.end());
			break;
		case IfStmt:
			tmp = generate(stmt->ifStmt);
			resultCode.insert(resultCode.end(), tmp.begin(), tmp.end());
			break;
		case Return:
			resultCode.push_back((char)Command::return_);
			break;
		case ReturnValue:
			tmp = generate(stmt->expr);
			resultCode.insert(resultCode.end(), tmp.begin(), tmp.end());
			resultCode.push_back((char)Command::areturn);
			break;
		default:
			break;
		}
	}

	return resultCode;
}

vector<char> generate(methodS* method)
{
	vector<char> bytes;

	if (method->func->stmts != 0)
	{
		bytes = generate(method->func->stmts);
	}
	return bytes;
}

vector<char> generate(constructorS* constr)
{
	vector<char> bytes;

	if (constr->stmts != 0)
	{
		bytes = generate(constr->stmts);
	}
	return bytes;
}


void ClassFile::generate() {
	string classname = className + ".class";
	freopen(classname.c_str(), "wb", stdout);
	vector<char> len = intToBytes(constsTable.size() + 1);

	// CAFEBABE
	vector<char> tmp = intToBytes(magic);
	cout << tmp[0] << tmp[1] << tmp[2] << tmp[3];

	// JAVA
	tmp = intToBytes(minorV);
	cout << tmp[2] << tmp[3];
	tmp = intToBytes(majorV);
	cout << tmp[2] << tmp[3];

	// constants count
	cout << len[2] << len[3];

	//constants table
	for (auto i : constsTable) {
		i.generate();
	}

	// Flags 
	tmp = intToBytes(accessFlags);
	cout << tmp[2] << tmp[3];

	// This class constant
	tmp = intToBytes(thisClass);
	cout << tmp[2] << tmp[3];

	// Parent class constant
	tmp = intToBytes(superClass);
	cout << tmp[2] << tmp[3];

	// Interfaces table
	cout << (char)0x00 << (char)0x00;

	// Fields table
	tmp = intToBytes(fieldTable.size());
	cout << tmp[2] << tmp[3];

	for (auto i : fieldTable) {
		i.second.generate();
	}

	// Methods table
	tmp = intToBytes(methodTable.size());
	cout << tmp[2] << tmp[3];

	for (auto i : methodTable) {
		i.second.generate();
	}

	// atributes
	cout << (char)0x00 << (char)0x00;
	fclose(stdout);
}

void ConstantsTableElement::generate() {
	// UTF-8
	if (type == UTF_8) {
		char const* c = value.c_str();
		std::cout << (char)UTF_8;
		std::vector<char> len = intToBytes(strlen(c));
		std::cout << (char)len[2] << (char)len[3];
		for (int i = 0; i < strlen(c); ++i) {
			std::cout << c[i];
		}
	}

	// Integer
	if (type == _INT) {
		std::cout << (char)_INT;
		std::vector<char> len = intToBytes(valueI);
		std::cout << len[0] << len[1] << len[2] << len[3];
	}

	// Float
	if (type == _FLOAT) {
		std::cout << (char)_FLOAT;
		std::vector<char> len = flToBytes(valueF);
		std::cout << len[0] << len[1] << len[2] << len[3];
	}

	// Double
	if (type == _DOUBLE)
	{
		std::cout << (char)_DOUBLE;
		std::vector<char> len = doubleToBytes(valueD);
		std::cout << len[0] << len[1] << len[2] << len[3] << len[4] << len[5] << len[6] << len[7];
	}

	// Class
	if (type == _CLASS) {
		std::cout << (char)_CLASS;
		std::vector<char> len = intToBytes(refValue[0]);
		std::cout << len[2] << len[3];
	}

	// String !!!!!!!ОБРАТИ ВНИМАНИЕ НА РЕФ ВАЛУЕ 0!!!!!!!!!!!!
	if (type == _STRING) {
		std::cout << (char)_STRING;
		std::vector<char> len = intToBytes(refValue[0]);
		std::cout << len[2] << len[3];
	}

	// Fieldref
	if (type == FIELD_REF) {
		std::cout << (char)FIELD_REF;
		std::vector<char> len = intToBytes(refValue[0]);
		std::cout << len[2] << len[3];
		len = intToBytes(refValue[1]);
		std::cout << len[2] << len[3];
	}

	// Methodref
	if (type == METHOD_REF) {
		std::cout << (char)METHOD_REF;
		std::vector<char> len = intToBytes(refValue[0]);
		std::cout << len[2] << len[3];
		len = intToBytes(refValue[1]);
		std::cout << len[2] << len[3];
	}

	// NameAndType
	if (type == NAME_AND_TYPE) {
		std::cout << (char)NAME_AND_TYPE;
		std::vector<char> len = intToBytes(refValue[0]);
		std::cout << len[2] << len[3];
		len = intToBytes(refValue[1]);
		std::cout << len[2] << len[3];
	}
}



void FieldTableElement::generate() {
	std::vector<char> tmp;
	// flags
	tmp = intToBytes(accessFlags);
	std::cout << tmp[2] << tmp[3];

	// name
	tmp = intToBytes(fieldName);
	std::cout << tmp[2] << tmp[3];

	// descriptor
	tmp = intToBytes(descriptor);
	std::cout << tmp[2] << tmp[3];

	// attributes
	tmp = intToBytes(0);
	std::cout << tmp[2] << tmp[3];
}

void MethodTableElement::generate() {
	vector<char> tmp;

	// flags
	tmp = intToBytes(accessFlags);
	cout << tmp[2] << tmp[3];

	// name
	tmp = intToBytes(name);
	cout << tmp[2] << tmp[3];

	// descriptor
	tmp = intToBytes(descriptor);
	cout << tmp[2] << tmp[3];

	// method atributes count (01)
	cout << (char)0x00 << (char)0x01;
	// method atribute (Code - 0x01)
	cout << (char)0x00 << (char)0x01;

	// attribute code
	std::vector<char> result_bytes = std::vector<char>();

	// size of operands stack
	vector<char> tmp_bytes = intToBytes(1000);
	result_bytes.push_back(tmp_bytes[2]);
	result_bytes.push_back(tmp_bytes[3]);

	// size of local variables
	tmp_bytes = intToBytes(localVarsAndConsts.size());
	result_bytes.push_back(tmp_bytes[2]);
	result_bytes.push_back(tmp_bytes[3]);

	// method code
	vector<char> methodCode;
	if (method != 0)
		methodCode = ::generate(method);
	else
		methodCode = ::generate(constructor);

	// size of method code
	tmp = intToBytes(methodCode.size());
	for (auto i : tmp)
		result_bytes.push_back(i);

	// method code
	for (auto i : methodCode)
		result_bytes.push_back(i);

	// exception table 
	result_bytes.push_back((char)0x00);
	result_bytes.push_back((char)0x00);

	// attrs table
	result_bytes.push_back((char)0x00);
	result_bytes.push_back((char)0x00);

	// attribute length
	tmp = intToBytes(result_bytes.size());
	for (auto i : tmp) {
		std::cout << i;
	}

	// attribute code
	for (auto i : result_bytes) {
		std::cout << i;
	}
}

vector <char> intToBytes(int value) {
	std::vector<char> arrayOfByte(4);
	for (int i = 0; i < 4; ++i) {
		arrayOfByte[3 - i] = (value >> (i * 8));
	}
	return arrayOfByte;
}

vector<char> flToBytes(float value)
{
	std::vector<char> arrayOfByte(4);

	for (int i = 0; i < sizeof(float); ++i)
		arrayOfByte[3 - i] = ((char*)&value)[i];
	return arrayOfByte;
}

vector<char> doubleToBytes(double value)
{
	std::vector<char> arrayOfByte(8);

	for (int i = 0; i < sizeof(double); ++i)
		arrayOfByte[8 - i] = ((char*)&value)[i];
	return arrayOfByte;
}

bool cmp(pair<ConstantsTableElement, int>& a, pair<ConstantsTableElement, int>& b) {
	return a.second < b.second;
}