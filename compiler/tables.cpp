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

ClassFile::ClassFile(classS* clas, list<ShortClassInfo*> allClassesInfo)
{
	
	this->isAbstract = isAbstract;
	this->isFinal = clas->mods->iMod == Final;
	this->vMod = translateVisibilityMod(clas->mods->vMod);


}

IdT ClassFile::findUtf8OrAdd(std::string const& utf8)
{
	ConstantsTableElement constant(UTF_8, utf8);
	const auto foundIter = std::find(constsTable.begin(), constsTable.end(), constant);
	if (foundIter == constsTable.end())
	{
		constsTable.push_back(constant);
		return constsTable.end() - constsTable.begin();
	}
	return foundIter - constsTable.begin();
}

IdT ClassFile::findIntOrAdd(IntT i)
{
	ConstantsTableElement constant(_INT, i);
	const auto foundIter = std::find(constsTable.begin(), constsTable.end(), constant);
	if (foundIter == constsTable.end())
	{
		constsTable.push_back(constant);
		return constsTable.end() - constsTable.begin();
	}
	return foundIter - constsTable.begin();
}

IdT ClassFile::findFloatOrAdd(float i)
{
	ConstantsTableElement constant(_FLOAT, i);
	const auto foundIter = std::find(constsTable.begin(), constsTable.end(), constant);
	if (foundIter == constsTable.end())
	{
		constsTable.push_back(constant);
		return constsTable.end() - constsTable.begin();
	}
	return foundIter - constsTable.begin();
}

IdT ClassFile::findFloatOrAdd(double i)
{
	ConstantsTableElement constant(_DOUBLE, i);
	const auto foundIter = std::find(constsTable.begin(), constsTable.end(), constant);
	if (foundIter == constsTable.end())
	{
		constsTable.push_back(constant);
		return constsTable.end() - constsTable.begin();
	}
	return foundIter - constsTable.begin();
}

IdT ClassFile::findClassOrAdd(std::string const& className)
{
	int value[2] = { findUtf8OrAdd(className), 0 };
	ConstantsTableElement constant(_CLASS, value);
	const auto foundIter = std::find(constsTable.begin(), constsTable.end(), constant);
	if (foundIter == constsTable.end())
	{
		constsTable.push_back(constant);
		return constsTable.end() - constsTable.begin();
	}
	return foundIter - constsTable.begin();
}

IdT ClassFile::findNameAndTypeOrAdd(std::string const& name, std::string const& type)
{
	int value[2] = { findUtf8OrAdd(name), findUtf8OrAdd(type) };
	ConstantsTableElement constant(NAME_AND_TYPE, value);
	const auto foundIter = std::find(constsTable.begin(), constsTable.end(), constant);
	if (foundIter == constsTable.end())
	{
		constsTable.push_back(constant);
		return constsTable.end() - constsTable.begin();
	}
	return foundIter - constsTable.begin();
}

IdT ClassFile::findFieldRefOrAdd(std::string const& className, std::string const& name, std::string const& type)
{

	int value[2] = { findNameAndTypeOrAdd(name, type), findClassOrAdd(className) };
	ConstantsTableElement constant(FIELD_REF, value);
	const auto foundIter = std::find(constsTable.begin(), constsTable.end(), constant);
	if (foundIter == constsTable.end())
	{
		constsTable.push_back(constant);
		return constsTable.end() - constsTable.begin();
	}
	return foundIter - constsTable.begin();
}

IdT ClassFile::findMethodRefOrAdd(std::string const& className, std::string const& name, std::string const& type)
{
	int value[2] = { findNameAndTypeOrAdd(name, type), findClassOrAdd(className) };
	ConstantsTableElement constant(METHOD_REF, value);
	const auto foundIter = std::find(constsTable.begin(), constsTable.end(), constant);
	if (foundIter == constsTable.end())
	{
		constsTable.push_back(constant);
		return constsTable.end() - constsTable.begin();
	}
	return foundIter - constsTable.begin();
}

string transformTypeToDescriptor(const char* type, list<string> allClassesNames)
{
	
	if (strcmp(type, "Int") == 0)	return string("I");
	else if (strcmp(type, "Boolean") == 0)	return string("Z");
	else if (strcmp(type, "Double") == 0)	return string("D");
	else if (strcmp(type, "Float") == 0)	return string("F");
	else if (strcmp(type, "Char") == 0)	return string("C");
	else if (strcmp(type, "String") == 0)	return string("Ljava/lang/String");
	else if (strcmp(type, "Unit") == 0)	return string("V");
	else
	{
		auto res = find(allClassesNames.begin(), allClassesNames.end(), string(type));
		if (res != allClassesNames.end())	return string("L") + type;
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
			return descriptor + transformTypeToDescriptor(typeName.c_str, allClassesNames);
		}
	}
}

void ClassFile::fillHighLevelObjectsConstants(propertyS* prop, list<ShortClassInfo*> allClassesInfo)
{
	findUtf8OrAdd(prop->varOrVal->id);
	list<string> allClassesNames;
	for (auto info : allClassesInfo) 
	{
		allClassesNames.push_back(info->className);
	}
	findUtf8OrAdd(transformTypeToDescriptor(prop->varOrVal->type->easyType, allClassesNames));


}

void ClassFile::fillHighLevelObjectsConstants(methodS* meth, list<ShortClassInfo*> allClassesInfo)
{

}

void ClassFile::fillHighLevelObjectsConstants(classS* clas, list<ShortClassInfo*> allClassesInfo)
{
	findUtf8OrAdd("Code");
	thisClass = findClassOrAdd(clas->name);
	if (clas->parentClassName != 0)
	{
		superClass = findClassOrAdd(clas->name);
	}
	else	superClass = 0;
	
	//Заполняю флаги доступа к классу
	accessFlags |= 0x0001; //Устанавливаю флаг PUBLIC
	if (isFinal) accessFlags |= 0x0010; //Устанавливаю флаг FINAL
	accessFlags |= 0x0020; //Устанавливаю флаг SUPER !Он устанавливается для совместимости

	if (clas->body != 0)
	{
		for (auto cbe = clas->body->first; cbe != 0; cbe = cbe->next)
		{
			if (cbe->method != 0)	fillHighLevelObjectsConstants(cbe->method, allClassesInfo);
			else if (cbe->property != 0) fillHighLevelObjectsConstants(cbe->property, allClassesInfo);
		}
	}
}


















void MethodTableElement::addLocalVar(varOrValDeclS* varOrValDecl)
{
}

void MethodTableElement::remove(int varOrValDeclIndex)
{
}

int MethodTableElement::find(string varOrValName)
{
	return 0;
}

varOrValDeclS* MethodTableElement::find(int varOrValIndex)
{
	return 0;
}