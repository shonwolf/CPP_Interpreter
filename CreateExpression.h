/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#ifndef CREATEEXPRESSION_H
#define CREATEEXPRESSION_H

#include <string>
#include <vector>
#include "Expression.h"
#include "BinaryExpression.h"
#include "Number.h"
#include "Plus.h"
#include "Minus.h"
#include "Div.h"
#include "Mul.h"
#include <queue>
#include <stack>
#include <unordered_map>
#include "VariablesData.h"
using namespace std;
class CreateExpression {
    // the members
    int m_stepsForward;
    queue<string> getPostfixUsingShuntingYardAlgorithm(vector<string> expression);
    bool isOperator(string s);
    bool fromStackHasGreaterPrecedence(string curOperator, string operatorFromStack);
    Expression* createExpression(vector<string> prefix, int start);
    BinaryExpression* getNewBinaryExpression(string op);
    vector<string> convertUnaryPartsToBinary(vector<string> translateExpression);
public:
    CreateExpression();
    Expression* fromExpression(vector<string> expression, VariablesData* variablesData);
};

#endif
