/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#ifndef MUL_H
#define MUL_H

#include "Expression.h"
#include "BinaryExpression.h"
class Mul: public BinaryExpression {
public:
    Mul(Expression* left, Expression* right);
    virtual double calculate();
};

#endif
