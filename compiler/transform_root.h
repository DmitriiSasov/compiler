#pragma once
#include "tables.h"

void checkInheritance(const programS* const program);

programS* transformProgram(list<ClassFile> classesFiles, programS* program);