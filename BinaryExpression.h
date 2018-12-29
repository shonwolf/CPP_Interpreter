/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#ifndef BINARYEXPRESSION_H
#define BINARYEXPRESSION_H

#include "Expression.h"
class BinaryExpression : public Expression {
    // the members
    Expression* m_left;
    Expression* m_right;
public:
    BinaryExpression(Expression* left, Expression* right);
    virtual Expression* getLeft();
    virtual Expression* getRight();
    virtual void setLeft(Expression* newLeft);
    virtual void setRight(Expression* newRight);
    virtual ~BinaryExpression();
};

#endif
