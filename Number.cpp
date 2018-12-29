/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#include "Number.h"

/****************************************************************************************************
* function name: this is constructor.
* The Input: nothing.
* The output: nothing.
* The Function operation: initialize the members with the data.
****************************************************************************************************/
Number::Number(const double& value) {
    this->m_value = value;
}

/****************************************************************************************************
* function name: calculate.
* The Input: nothing.
* The output: the value.
* The Function operation: this function return the value.
****************************************************************************************************/
double Number::calculate() {
    return this->m_value;
}