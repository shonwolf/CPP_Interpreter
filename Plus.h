/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#ifndef PLUS_H
#define PLUS_H

#include "Expression.h"
#include "BinaryExpression.h"
class Plus: public BinaryExpression {
public:
    Plus(Expression* left, Expression* right);
    virtual double calculate();
};

#endif
