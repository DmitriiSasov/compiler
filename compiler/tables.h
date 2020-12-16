#pragma once
#include <utility>
#include <string>
#include <map>
using namespace std;

map<int, ConstantsTableElement> constsTable;

enum ConstantType {
	UTF_8,
	_CLASS,
	_INT,
	_FLOAT,
	_DOUBLE,
	_BOOLEAN,
	NAME_AND_TYPE,
	FIELD_REF,
	METHOD_REF,

};

class ConstantsTableElement 
{

	unsigned int constNum = 0;

	unsigned int strNum = -1;

	ConstantType type = UTF_8;

	int refValue[2] = { -1, -1 };

	string value = string("");

	ConstantsTableElement(unsigned int constNum, unsigned int strNum, 
		ConstantType type, string value)
	{
		this->constNum = constNum;
		this->strNum = strNum;
		this->type = type;
		this->value = value;
	}

	ConstantsTableElement(unsigned int constNum, unsigned int strNum,
		ConstantType type, int value[2])
	{
		this->constNum = constNum;
		this->strNum = strNum;
		this->type = type;
		this->refValue[0] = value[0];
		this->refValue[1] = value[1];
	}

	ConstantsTableElement(unsigned int constNum, unsigned int strNum,
		ConstantType type, char* value)
	{
		ConstantsTableElement(constNum, strNum, type, string(value));
	}
};

class ClassTableElement 
{
	string className = "";

	string parentClassName = "";

	bool isAbstract = false;

	//bool is
};
