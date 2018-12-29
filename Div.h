/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#ifndef DIV_H
#define DIV_H

#include "Expression.h"
#include "BinaryExpression.h"
class Div: public BinaryExpression {
public:
    Div(Expression* left, Expression* right);
    virtual double calculate();
};

#endif
