#include "generate.h"

void generate(ClassFile* classFile) {
	std::string classname = classFile->className + ".class";
	freopen( classname.c_str(), "wb", stdout);
	std::vector<char> len = intToBytes(classFile->getConstsTable().size() + 1);

	// CAFEBABE
	std::vector<char> tmp = intToBytes(classFile->magic);
	std::cout << tmp[0] << tmp[1] << tmp[2] << tmp[3];

	// JAVA
	tmp = intToBytes(classFile->minorV);
	std::cout << tmp[2] << tmp[3];
	tmp = intToBytes(classFile->majorV);
	std::cout << tmp[1] << tmp[0];

	// constants count
	std::cout << len[2] << len[3];

	//constants table
	for (auto i : classFile->constsTable) {
		generate(i);
	}

	// Flags 
	tmp = intToBytes(classFile->accessFlags);
	std::cout << tmp[2] << tmp[3];

	// This class constant
	tmp = intToBytes(classFile->thisClass);
	std::cout << tmp[2] << tmp[3];

	// Parent class constant
	tmp = intToBytes(classFile->superClass);
	std::cout << tmp[2] << tmp[3];

	// Interfaces table
	std::cout << (char)0x00 << (char)0x00;

	// Fields table
	tmp = intToBytes(classFile->fieldTable.size());
	std::cout << tmp[2] << tmp[3];

	for (auto i : classFile->fieldTable) {
		generate(i.second);
	}

	// Methods table
	tmp = intToBytes(classFile->methodTable.size());
	std::cout << tmp[2] << tmp[3];

	for (auto i : classFile->methodTable) {
		generate(i.second);
	}

	// atributes
	std::cout << (char)0x00 << (char)0x00;
	
}

void generate(ConstantsTableElement constant) {
	// UTF-8
	if (constant.type == UTF_8) {
		char const* c = constant.value.c_str();
		std::cout << (char)UTF_8;
		std::vector<char> len = intToBytes(strlen(c));
		std::cout << (char)len[2] << (char)len[3];
		for (int i = 0; i < strlen(c); ++i) {
			std::cout << c[i];
		}
	}

	// Integer
	if (constant.type == _INT) {
		std::cout << (char)_INT;
		std::vector<char> len = intToBytes(constant.valueI);
		std::cout << len[0] << len[1] << len[2] << len[3];
	}

	// Float
	if (constant.type == _FLOAT) {
		std::cout << (char)_FLOAT;
		std::vector<char> len = flToBytes(constant.valueF);
		std::cout << len[0] << len[1] << len[2] << len[3];
	}

	// Class
	if (constant.type == _CLASS) {
		std::cout << (char)_CLASS;
		std::vector<char> len = intToBytes(constant.refValue[0]);
		std::cout << len[2] << len[3];
	}

	// String !!!!!!!ÎÁÐÀÒÈ ÂÍÈÌÀÍÈÅ ÍÀ ÐÅÔ ÂÀËÓÅ 0!!!!!!!!!!!!
	if (constant.type == _STRING) {
		std::cout << (char)_STRING;
		std::vector<char> len = intToBytes(constant.refValue[0]);
		std::cout << len[2] << len[3];
	}

	// Fieldref
	if (constant.type == FIELD_REF) {
		std::cout << (char)FIELD_REF;
		std::vector<char> len = intToBytes(constant.refValue[0]);
		std::cout << len[2] << len[3];
		len = intToBytes(constant.refValue[1]);
		std::cout << len[2] << len[3];
	}

	// Methodref
	if (constant.type == METHOD_REF) {
		std::cout << (char)METHOD_REF;
		std::vector<char> len = intToBytes(constant.refValue[0]);
		std::cout << len[2] << len[3];
		len = intToBytes(constant.refValue[1]);
		std::cout << len[2] << len[3];
	}

	// NameAndType
	if (constant.type == NAME_AND_TYPE) {
		std::cout << (char)NAME_AND_TYPE;
		std::vector<char> len = intToBytes(constant.refValue[0]);
		std::cout << len[2] << len[3];
		len = intToBytes(constant.refValue[1]);
		std::cout << len[2] << len[3];
	}
}

void generate(FieldTableElement field) {
	std::vector<char> tmp;
	// flags
	tmp = intToBytes(field.accessFlags);
	std::cout << tmp[2] << tmp[3];
	
	// name
	tmp = intToBytes(field.fieldName);
	std::cout << tmp[2] << tmp[3];
	
	// descriptor
	tmp = intToBytes(field.descriptor);
	std::cout << tmp[2] << tmp[3];

	// attributes
	tmp = intToBytes(0);
	std::cout << tmp[2] << tmp[3];
}

void generate(MethodTableElement method) {
	std::vector<char> tmp;

	// flags
	tmp = intToBytes(method.accessFlags);
	std::cout << tmp[2] << tmp[3];

	// name
	tmp = intToBytes(method.name);
	std::cout << tmp[2] << tmp[3];

	// descriptor
	tmp = intToBytes(method.descriptor);
	std::cout << tmp[2] << tmp[3];

	// method atributes count (01)
	std::cout << (char)0x00 << (char)0x01;
	// method atribute (Code - 0x01)
	std::cout << (char)0x00 << (char)0x01;
}

std::vector <char> intToBytes(int value) {
	std::vector<char> arrayOfByte(4);
	for (int i = 0; i < 4; ++i) {
		arrayOfByte[3 - i] = (value >> (i * 8));
	}
	return arrayOfByte;
}

std::vector<char> flToBytes(float value)
{
	std::vector<char> arrayOfByte(4);

	for (int i = 0; i < sizeof(float); ++i)
		arrayOfByte[3 - i] = ((char*)&value)[i];
	return arrayOfByte;
}

bool cmp(std::pair<ConstantsTableElement, int>& a, std::pair<ConstantsTableElement, int>& b) {
	return a.second < b.second;
}
