/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#ifndef MINUS_H
#define MINUS_H

#include "Expression.h"
#include "BinaryExpression.h"
class Minus: public BinaryExpression {
public:
    Minus(Expression* left, Expression* right);
    virtual double calculate();
};


#endif
