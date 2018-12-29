/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#include "BinaryExpression.h"

/****************************************************************************************************
* function name: this is constructor.
* The Input: Expression* left, Expression* right.
* The output: nothing.
* The Function operation: initialize the members with the data.
****************************************************************************************************/
BinaryExpression::BinaryExpression(Expression* left, Expression* right) {
    this->m_left = left;
    this->m_right = right;
}

/****************************************************************************************************
* function name: getLeft.
* The Input: nothing.
* The output: the left expression.
* The Function operation: this function return the left expression.
****************************************************************************************************/
Expression* BinaryExpression::getLeft() {
    return this->m_left;
}

/****************************************************************************************************
* function name: getRight.
* The Input: nothing.
* The output: the right expression.
* The Function operation: this function return the right expression.
****************************************************************************************************/
Expression* BinaryExpression::getRight() {
    return this->m_right;
}

/****************************************************************************************************
* function name: setLeft.
* The Input: Expression* newLeft.
* The output: nothing.
* The Function operation: this function set the left expression.
****************************************************************************************************/
void BinaryExpression::setLeft(Expression* newLeft) {
    this->m_left = newLeft;
}

/****************************************************************************************************
* function name: setRight.
* The Input: Expression* newRight.
* The output: nothing.
* The Function operation: this function set the right expression.
****************************************************************************************************/
void BinaryExpression::setRight(Expression* newRight) {
    this->m_right = newRight;
}

/****************************************************************************************************
* function name: ~BinaryExpression.
* The Input: nothing.
* The output: nothing.
* The Function operation: the destructor make sure to erase all the things that were put on the
*                         heap.
****************************************************************************************************/
BinaryExpression::~BinaryExpression() {
    delete(this->m_left);
    delete(this->m_right);
}