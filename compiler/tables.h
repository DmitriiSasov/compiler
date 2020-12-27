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

string transformTypeToDescriptor(const char* type, const programS* program);

bool isUserClass(const char* name, const list<string>& classesNames);

bool isMyStandartClass(const string& className);

bool isUserClass(const char* name, const programS * const program);

string getPropertyType(const char* propName, const programS* const program, const string& currentClassName);

string getMethodType(const string& methodSign, const programS* const program, const string& currentClassName);

string createMethodSignature(methodS* meth);

bool isParentClass(const string& potentialParent, const string& potentialChild, const programS* const program);

const methodS* findMethod(const string& methodSign, const programS* const program,
	const string& currentClassName);

struct ShortClassInfo 
{
	string className = "";
	list<string> methodsInfo;
	list<string> propertiesInfo;
};

string createShortInfo(propertyS* prop);

string createMethodSignature(methodS* meth);

struct FieldTableElement
{

public:

	uint16_t fieldName = 0;

	uint16_t descriptor = 0;

	uint16_t accessFlags = 0;

	FieldTableElement(uint16_t fieldName, uint16_t descriptor, VisibilityMod vMod, bool isStatic, bool isFinal);

};

struct attribute
{

};

struct LocalVariableInfo
{
	bool isConst;
	bool hasValue;
	string name;
	string type;

	LocalVariableInfo(bool isConst, bool hasValue, string name, string type)
	{
		this->isConst = isConst;
		this->hasValue = hasValue;
		this->name = name;
		this->type = type;
	}
};

class MethodTableElement
{

	int localVarsCount = 0;

	//Type and name
	list<LocalVariableInfo> localVarsAndConsts;

	attribute code;

public:

	uint16_t name = 0;

	uint16_t descriptor = 0;

	uint16_t accessFlags = 0;

	bool isStatic = false;

	MethodTableElement(uint16_t methName, uint16_t descriptor,
		VisibilityMod vMod, bool isFinal, bool isStatic);

	bool addLocalVar(varOrValDeclS* varOrValDecl);

	bool addLocalVar(LocalVariableInfo* varOrValDecl);

	void remove(int varOrValDeclIndex);


	int find(string varOrValName);

	LocalVariableInfo find(int indexInTable);

	void addCode();


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

	string strV = "";


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

	string getValueString()
	{
		return strV;
	}

	friend bool operator==(const ConstantsTableElement& lhs, const ConstantsTableElement& rhs);
};



class ClassFile
{
	const uint32_t magic = 0xCAFEBABE;

	const uint16_t minorV = 0;

	const uint16_t majorV = 52;

	uint16_t accessFlags = 0;

	uint16_t thisClass = 0;

	string className = "";

	uint16_t superClass = 0;

	string parentClassName = "";

	const uint16_t interfaces_count = 0;

	vector<ConstantsTableElement> constsTable;

	map<string, FieldTableElement> fieldTable;

	map<string, MethodTableElement> methodTable;

	void fillHighLevelObjectsConstants(classS* clas, programS* program);

	void fillHighLevelObjectsConstants(propertyS* prop, programS* program);

	void fillHighLevelObjectsConstants(methodS* meth, programS* program);

	void fillHighLevelObjectsConstants(constructorS* constr, programS* program);

	void addConstantsFrom(methodS* meth, programS* program);
	
	void addConstantsFrom(stmtS* stmt, programS* program, string methodKey);

	void addConstantsFrom(varOrValDeclS* v, programS* program, string methodKey);
	

	void addConstantsFrom(assignmentS* a, programS* program, string methodKey);
	

	void addConstantsFrom(whileLoopS* w, programS* program, string methodKey);
	

	void addConstantsFrom(forLoopS* f, programS* program, string methodKey);
	

	void addConstantsFrom(ifStmtS* i, programS* program, string methodKey);
	
	void addConstantsFrom(exprS* e, programS* program, string methodKey);

	void addConstantsFrom(stmtList* stmts, programS* program);

	void calcType(exprS* e1, programS* program, string& methodKey);

	void calcTypeOfIdentifier(exprS* e1, programS* program, string& methodKey);

	void calcTypeOfMethodCall(exprS* e1, programS* program, string& methodKey);

	void calcTypeOfFieldCalsExpr(exprS* e1, programS* program, string& methodKey);

	void calcTypeOfMethodCalcExpr(exprS* e1, programS* program, string& methodKey);

	void calcTypeOfArrayElementCall(exprS* e1, programS* program, string& methodKey);

	void calcTypeOfParentFieldCall(exprS* e1, programS* program, string& methodKey);

	void calcTypeOfParentMethodCall(exprS* e1, programS* program, string& methodKey);

	bool transformKotlinTypeCastOperators(exprS* e);
	
	void transformTypeCastToValueOf(exprS* e, const char* staticClassName);

	int calcType(factParamsList* fpl, programS* program, string& methodKey);

	void convertToJavaBasicTypeClass(exprS* e1);

	void convertBasicTypeExprToString(exprS* e);
	
	void addToStringCall(exprS* e, programS* program);

public:

	bool isAbstract = false;

	bool isFinal = true;

	VisibilityMod vMod = _PUBLIC;

	
	ClassFile(classS* clas, programS* program);

	IdT findUtf8OrAdd(std::string const& utf8);

	IdT findIntOrAdd(IntT i);

	IdT findFloatOrAdd(float i);

	IdT findDoubleOrAdd(double i);

	IdT findStringOrAdd(string v);

	IdT findClassOrAdd(std::string const& className);

	IdT findNameAndTypeOrAdd(std::string const& name, std::string const& type);

	IdT findFieldRefOrAdd(std::string const& className, std::string const& name, std::string const& type);

	IdT findMethodRefOrAdd(std::string const& className, std::string const& name, std::string const& type);

};

