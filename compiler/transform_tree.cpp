#include "transform_root.h"

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
	strcpy(newClass->name, "<Main>");
	newClass->mods = createModifiers(0, 0, Public, Final);
	newClass->parentClassName = 0;
	newClass->body = createClassBody();
	programElementS* pe = programTreeRoot->first;
	
	//Добавили все глобальные поля и методы в новый класс
	while (pe != 0)
	{
		if (pe->method != 0)
			newClass->body = addToClassBody(newClass->body, pe->method);
		else if (pe->property != 0)
			newClass->body = addToClassBody(newClass->body, pe->property);
		pe = pe->next;
	}
	//Убрали из дерева лишние узлы
	programTreeRoot = removeRedundantNodes(programTreeRoot);
	
	//Добавили новый класс
	if (programTreeRoot->first == 0)
		programTreeRoot = createProgram(newClass);
	else programTreeRoot = addToProgram(programTreeRoot, newClass);

	return programTreeRoot;
}


void replaceSquareBracetsWithGetSet(classS* program)
{

}

void transformAssignmentWithField(classS* program)
{

}


void transformInit(classS* program)
{

}

void complementModifiers(classS* clas)
{

}



programS* transformProgram(programS* program)
{
	program = transformProgramToClass(program);

	return program;
}