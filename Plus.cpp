/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#include "Plus.h"

/****************************************************************************************************
* function name: this is constructor.
* The Input: Expression* left, Expression* right.
* The output: nothing.
* The Function operation: initialize the members with the data.
****************************************************************************************************/
Plus::Plus(Expression* left, Expression* right) : BinaryExpression(left, right) {}

/****************************************************************************************************
* function name: calculate.
* The Input: nothing.
* The output: the sum of the expressions.
* The Function operation: this function return the sum of the expressions.
****************************************************************************************************/
double Plus::calculate() {
    return this->getLeft()->calculate() + this->getRight()->calculate();
}