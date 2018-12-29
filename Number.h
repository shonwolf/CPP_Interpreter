/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#ifndef NUMBER_H
#define NUMBER_H

#include "Expression.h"
class Number : public Expression {
    // the members
    double m_value;
public:
    Number(const double& value);
    virtual double calculate();
};

#endif
