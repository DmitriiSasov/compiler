#pragma once
#include "create_tree.h"
#include <utility>
#include <map>
#include <list>
#include <vector>
#include <iostream>

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


vector <char> intToBytes(int value);

vector<char> flToBytes(float value);

vector<char> doubleToBytes(double value);

VisibilityMod translateVisibilityMod(visibilityMod vMod);

bool canCastType(const string& type1, const string& type2, const programS* const program);

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
	int fieldName = 0;

	int descriptor = 0;

	int accessFlags = 0;

public:

	FieldTableElement(uint16_t fieldName, uint16_t descriptor, VisibilityMod vMod, bool isStatic, bool isFinal);

	void generate();
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

public:

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

	int nestingLevel = 0; //������� ����������� ������ (����� ��� ����������� ������ ���������� � �������)

	attribute code;

	int name = 0;

	int descriptor = 0;

	int accessFlags = 0;

	bool isStatic = false;

	methodS* method = 0;

	constructorS* constructor = 0;

public:
	MethodTableElement(uint16_t methName, uint16_t descriptor, VisibilityMod vMod, 
		bool isFinal, bool isStatic, constructorS* constructor, methodS* method);

	int addLocalVar(varOrValDeclS* varOrValDecl);

	int addLocalVar(LocalVariableInfo* varOrValDecl);

	void incNestingLevel();

	void decNestingLevel();

	int find(string varOrValName);

	LocalVariableInfo find(int indexInTable);

	int getNestingLevel() { return nestingLevel; }

	bool isStaticMethod() { return this->isStatic; }

	void generate();
};

using IdT = unsigned long long;
using IntT = std::int32_t;
using FloatT = double;

class ConstantsTableElement
{
public:

	ConstantType type = UTF_8;

	int refValue[2] = { -1, -1 };

	string value = string("");

	double valueD = 0.0;

	float valueF = 0.0f;

	int valueI = 0;


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
		this->type = type;
		this->value = value;
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
			return "INT \t" + to_string(valueI)+"\n";
		}
		else if (this->type == _FLOAT) {
			return "FLOAT \t" + to_string(valueF) + "\n";
		}
		else if (this->type == _DOUBLE) {
			return "DOUBLE \t" + to_string(valueD) + "\n";
		}
		else if (this->type == UTF_8) {
			return "UTF-8 \t" + value + "\n";
		}
		else if (this->type == _STRING) {
			return "STRING \t" + to_string(refValue[0]) + "\n";
		}
		else if (this->type == _CLASS) {
			return "CLASS \t" + to_string(refValue[0]) + "\n";
		}
		else if (this->type == NAME_AND_TYPE) {
			return "NAME_AND_TYPE \t" + to_string(refValue[0]) + ' ' + (refValue[1] != -1 ? to_string(refValue[1]) : "") + "\n";
		}
		else if (this->type == METHOD_REF) {
			return "METHOD_REF \t" + to_string(refValue[0]) + ' ' + (refValue[1] != -1 ? to_string(refValue[1]) : "") + "\n";
		}
		else if (this->type == FIELD_REF) {
			return "FIELD_REF \t" + to_string(refValue[0]) + ' ' + (refValue[1] != -1 ? to_string(refValue[1]) : "") + "\n";
		}

	}
	int getConstType() { return type; }
	
	string getValue() { return value; }

	int getRefValue(unsigned int index) { return refValue[index]; }

	string getValueString()
	{
		return value;
	}

	void generate();

	friend bool operator==(const ConstantsTableElement& lhs, const ConstantsTableElement& rhs);
};


bool cmp(pair<ConstantsTableElement, int>& a, pair<ConstantsTableElement, int>& b);

class ClassFile
{

	const int magic = 0xCAFEBABE;

	const int minorV = 0;

	const int majorV = 52;

	int accessFlags = 0;

	int thisClass = 0;

	string className = "";

	int superClass = 0;

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
	
	void addMain(classS* clas, const programS* const program);
	
	bool addConstantsFrom(stmtS* stmt, programS* program, const string& methodKey);

	void addConstantsFrom(varOrValDeclS* v, programS* program, const string& methodKey);
	
	void checkReturnValue(const string& res, const string& methodSign, const programS* const program);

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

	bool isAbstract = false;

	bool isFinal = true;

	VisibilityMod vMod = _PUBLIC;

public:

	void generate();
	
	ClassFile(classS* clas, programS* program);

	int findUtf8OrAdd(std::string const& utf8);

	int findIntOrAdd(IntT i);

	int findFloatOrAdd(float i);

	int findDoubleOrAdd(double i);

	int findStringOrAdd(string& v);

	int findClassOrAdd(string const& className);

	int findNameAndTypeOrAdd(string const& name, string const& type);
	
	int findFieldRefOrAdd(string const& className, string const& name, string const& type);

	int findMethodRefOrAdd(string const& className, string const& name, string const& type);

	string constsTableToStr();

};

