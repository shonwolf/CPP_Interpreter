/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#ifndef OPERATOR_H
#define OPERATOR_H

#include <string>
#include <unordered_map>
#include "CreateExpression.h"
#include "VariablesData.h"
using namespace std;
class Operator {
    // the members
    unordered_map<string, char> m_operatorNumber;
public:
    Operator();
    bool condition(vector<string> left, string op, vector<string> right, VariablesData* variablesData);
    unordered_map<string, char> getOperatorNumber();
};

#endif
