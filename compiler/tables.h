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

void transformForLoop(stmtS* forLoop);

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
	int nestingLevel;

	LocalVariableInfo(bool isConst, bool hasValue, string name, string type, 
		int nestingLevel)
	{
		this->isConst = isConst;
		this->hasValue = hasValue;
		this->name = name;
		this->type = type;
		this->nestingLevel = nestingLevel;
	}

	LocalVariableInfo& operator=(LocalVariableInfo other)
	{
		this->isConst = other.isConst;
		this->hasValue = other.hasValue;
		this->name = other.name;
		this->type = other.type;
		this->nestingLevel = other.nestingLevel;
		return *this;
	}

	friend bool operator==(LocalVariableInfo i1, LocalVariableInfo i2);
};

class MethodTableElement
{

	int localVarsCount = 0;

	//Type and name
	list<LocalVariableInfo> localVarsAndConsts;

	int nestingLevel = 0; //Уровень вложенности блоков (нужен для правильного поиска переменных в таблице)

	attribute code;

public:

	uint16_t name = 0;

	uint16_t descriptor = 0;

	uint16_t accessFlags = 0;

	bool isStatic = false;

	MethodTableElement(uint16_t methName, uint16_t descriptor,
		VisibilityMod vMod, bool isFinal, bool isStatic);

	int addLocalVar(varOrValDeclS* varOrValDecl);

	int addLocalVar(LocalVariableInfo* varOrValDecl);

	void incNestingLevel();

	void decNestingLevel();

	int find(string varOrValName);

	LocalVariableInfo find(int indexInTable);

	int getNestingLevel() { return nestingLevel; }

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

	string to_str() {
		if (this->type == _INT) {
			return "INT " + to_string(valueI)+"\n";
		}
		else if (this->type == _FLOAT) {
			return "FLOAT " + to_string(valueF) + "\n";
		}
		else if (this->type == _DOUBLE) {
			return "DOUBLE " + to_string(valueD) + "\n";
		}
		else if (this->type == UTF_8) {
			return "UTF-8 " + value + "\n";
		}
		else if (this->type == _STRING) {
			return "STRING " + value + "\n";
		}
		else if (this->type == _CLASS) {
			return "CLASS " + to_string(refValue[0]) + "\n";
		}
		else if (this->type == NAME_AND_TYPE) {
			return "NAME_AND_TYPE " + to_string(refValue[0]) + (refValue[1] == 0 ? to_string(refValue[1]) : "") + "\n";
		}
		else if (this->type == METHOD_REF) {
			return "METHOD_REF " + to_string(refValue[0]) + (refValue[1] == 0 ? to_string(refValue[1]) : "") + "\n";
		}
		else if (this->type == FIELD_REF) {
			return "FIELD_REF " + to_string(refValue[0]) + (refValue[1] == 0 ? to_string(refValue[1]) : "") + "\n";
		}

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

	bool fillHighLevelObjectsConstants(classS* clas, programS* program);

	void fillHighLevelObjectsConstants(propertyS* prop, programS* program);

	bool fillHighLevelObjectsConstants(methodS* meth, programS* program);

	bool fillHighLevelObjectsConstants(constructorS* constr, programS* program);

	bool addConstantsFrom(methodS* meth, programS* program);
	
	bool addConstantsFrom(stmtS* stmt, programS* program, const string& methodKey);

	void addConstantsFrom(varOrValDeclS* v, programS* program, const string& methodKey);
	

	void addConstantsFrom(assignmentS* a, programS* program, const string& methodKey);
	

	bool addConstantsFrom(whileLoopS* w, programS* program, const string& methodKey);
	

	void addConstantsFrom(forLoopS* f, programS* program, const string& methodKey);
	

	bool addConstantsFrom(ifStmtS* i, programS* program, const string& methodKey);
	
	bool addConstantsFrom(stmtList* stmts, programS* program, const string& methodKey);

	void calcType(exprS* e1, programS* program, const string& methodKey);

	void calcTypeOfIdentifier(exprS* e1, programS* program, const string& methodKey);

	void calcTypeOfMethodCall(exprS* e1, programS* program, const string& methodKey);

	void calcTypeOfFieldCalsExpr(exprS* e1, programS* program, const string& methodKey);

	void calcTypeOfMethodCalcExpr(exprS* e1, programS* program, const string& methodKey);

	void calcTypeOfArrayElementCall(exprS* e1, programS* program, const string& methodKey);

	void calcTypeOfParentFieldCall(exprS* e1, programS* program, const string& methodKey);

	void calcTypeOfParentMethodCall(exprS* e1, programS* program, const string& methodKey);

	void calcTypeOfLiterals(exprS* e1, const string& methodKey);

	void calcTypeOfUnaryOperators(exprS* e1, programS* program, const string& methodKey);

	void calcTypeOfSum(exprS* e1, programS* program, const string& methodKey);
	
	void calcTypeOfOtherArithmeticOperations(exprS* e1, programS* program,
		const string& methodKey);
	
	int calcType(factParamsList* fpl, programS* program, const string& methodKey);

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

	IdT findStringOrAdd(string& v);

	IdT findClassOrAdd(string const& className);

	IdT findNameAndTypeOrAdd(string const& name, string const& type);

	IdT findFieldRefOrAdd(string const& className, string const& name, string const& type);

	IdT findMethodRefOrAdd(string const& className, string const& name, string const& type);

	string constsTableToStr();

};

