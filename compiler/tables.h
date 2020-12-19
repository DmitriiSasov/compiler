#pragma once
#include "create_tree.h"
#include <utility>
#include <map>
#include <list>
#include <vector>

using namespace std;

enum VisibilityMod 
{
	_PUBLIC,
	_PRIVATE,
	_PROTECTED
};

enum ConstantType 
{
	UTF_8 = 1,
	_CLASS = 7,
	_INT = 3,
	_FLOAT = 4,
	_DOUBLE = 6,
	_STRING = 8,
	NAME_AND_TYPE = 12,
	FIELD_REF = 9,
	METHOD_REF = 10,
};

VisibilityMod translateVisibilityMod(visibilityMod vMod);

struct ShortClassInfo 
{
	string className = "";
	list<string> methodsInfo;
	list<string> propertiesInfo;
};


class FieldTableElement
{

public:

	string fieldName = "";

	string descriptor = "";

	VisibilityMod vMod = _PUBLIC;

	bool isFinal = true;

	bool isStatic = false;



	FieldTableElement(string fieldName, string descriptor, VisibilityMod vMod, bool isStatic)
	{
		this->fieldName = fieldName;
		this->descriptor = descriptor;
		this->vMod = vMod;
	}

};

class MethodTableElement
{

	methodS* meth = 0;

	int localVarsCount = 0;

	map<string, varOrValDeclS*> localVarsAndConsts;

public:

	string methName = "";

	string descriptor = "";

	VisibilityMod vMod = _PUBLIC;

	bool isAbstract = false;

	bool isFinal = true;

	bool isStatic = false;

	MethodTableElement(string methName, string descriptor,
		VisibilityMod vMod, bool isAbstract, bool isFinal, bool isStatic)
	{

	}

	void addLocalVar(varOrValDeclS* varOrValDecl);

	void remove(int varOrValDeclIndex);


	int find(string varOrValName);

	varOrValDeclS* find(int varOrValIndex);



};

using IdT = unsigned long long;
using IntT = std::int32_t;
using FloatT = double;

class ConstantsTableElement
{

	ConstantType type = UTF_8;

	int refValue[2] = { 0, 0 };

	string value = string("");

	double valueD = 0.0;

	float valueF = 0.0f;

	int valueI = 0;

public:
	ConstantsTableElement(ConstantType type, string value)
	{
		this->type = type;
		this->value = value;
	}

	ConstantsTableElement(ConstantType type, int value[2])
	{
		this->type = type;
		this->refValue[0] = value[0];
		this->refValue[1] = value[1];
	}

	ConstantsTableElement(ConstantType type, char* value)
	{
		ConstantsTableElement(type, string(value));
	}

	ConstantsTableElement(ConstantType type, double value)
	{
		this->type = type;
		valueD = value;
	}

	ConstantsTableElement(ConstantType type, float value)
	{
		this->type = type;
		valueF = value;
	}

	ConstantsTableElement(ConstantType type, int value)
	{
		this->type = type;
		valueI = value;
	}

	int getConstType() { return type; }
	
	string getValue() { return value; }

	int getRefValue(unsigned int index) { return refValue[index]; }

	friend bool operator==(const ConstantsTableElement& lhs, const ConstantsTableElement& rhs);
};



class ClassFile
{
	const uint32_t magic = 0xCAFEBABE;

	const uint16_t minorV = 0;

	const uint16_t majorV = 0;

	uint16_t accessFlags = 0;

	uint16_t thisClass = 0;

	uint16_t superClass = 0;

	const uint16_t interfaces_count = 0;

	vector<ConstantsTableElement> constsTable;

	map<string, FieldTableElement> fieldTable;

	map<string, MethodTableElement> methodTable;

	string& generateMethodKey(methodS* meth);

	void fillHighLevelObjectsConstants(classS* clas, list<ShortClassInfo*> allClassesInfo);

	void fillHighLevelObjectsConstants(propertyS* prop, list<ShortClassInfo*> allClassesInfo);

	void fillHighLevelObjectsConstants(methodS* meth, list<ShortClassInfo*> allClassesInfo);

public:

	bool isAbstract = false;

	bool isFinal = true;

	VisibilityMod vMod = _PUBLIC;

	
	ClassFile(classS* clas, list<ShortClassInfo*> allClassesInfo);

	IdT findUtf8OrAdd(std::string const& utf8);

	IdT findIntOrAdd(IntT i);

	IdT findFloatOrAdd(float i);

	IdT findFloatOrAdd(double i);

	IdT findClassOrAdd(std::string const& className);

	IdT findNameAndTypeOrAdd(std::string const& name, std::string const& type);

	IdT findFieldRefOrAdd(std::string const& className, std::string const& name, std::string const& type);

	IdT findMethodRefOrAdd(std::string const& className, std::string const& name, std::string const& type);

};


list<ClassFile*> classesFiles;


class ProgramInfo
{
	
	list<classS*> classes;
	map<string, methodS*> methods;
	map<string, propertyS*> properties;

	bool addMethod(string className, methodS* meth)
	{

	}

public:

	bool addClass(classS* cl) 
	{
		if (cl != 0) 
		{
			auto res = find(classes.begin(), classes.end(), cl);
			if (res != classes.end())
			{
				classes.push_back(cl);
				if (cl->body != 0)
				{
					for (auto cbe = cl->body->first; cbe != 0; cbe = cbe->next)
					{

					}
				}
				return true;
			}
			else return false;
		}
		
	}





};



