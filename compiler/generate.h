#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include "tree_nodes.h"
#include "tables.h"


void generate(ClassFile* classFile);
void generate(ConstantsTableElement constant);
void generate(FieldTableElement field);
void generate(MethodTableElement method);

std::vector <char> intToBytes(int value);

std::vector<char> flToBytes(float value);

bool cmp(std::pair<ConstantsTableElement, int>& a, std::pair<ConstantsTableElement, int>& b);

