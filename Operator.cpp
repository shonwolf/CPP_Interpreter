/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#include "Operator.h"

/****************************************************************************************************
* function name: this is constructor.
* The Input: VariablesData* variablesData.
* The output: nothing.
* The Function operation: initialize the members with the data.
****************************************************************************************************/
Operator::Operator() {
    // in this map we represent the number I give for each operator
    this->m_operatorNumber = {{"!=", '1'},
                              {"==", '2'},
                              {">=", '3'},
                              {"<=", '4'},
                              {">", '5'},
                              {"<", '6'}};
}

/****************************************************************************************************
* function name: getOperatorNumber.
* The Input: nothing.
* The output: the operatorNumber map.
* The Function operation: this function return the operatorNumber map.
****************************************************************************************************/
unordered_map<string, char> Operator::getOperatorNumber() {
    return this->m_operatorNumber;
}

/****************************************************************************************************
* function name: condition.
* The Input: vector<string> left, string op, vector<string> right, VariablesData* variablesData.
* The output: true if the condition between the two expressions is true, false otherwise.
* The Function operation: this function checks if the condition between the two expressions is true,
*                         and if it does return true, false otherwise.
****************************************************************************************************/
bool Operator::condition(vector<string> left, string op ,vector<string> right, VariablesData* variablesData) {
    CreateExpression createExpression = CreateExpression();
    // create the Expression of the left vector
    Expression* leftExp = createExpression.fromExpression(left, variablesData);
    // create the Expression of the right vector
    Expression* rightExp = createExpression.fromExpression(right, variablesData);
    double leftResult = leftExp->calculate();
    double rightResult = rightExp->calculate();
    delete(leftExp);
    delete(rightExp);
    char opNum = this->m_operatorNumber[op];
    // switch on the number that represent the operators
    switch (opNum) {
        case '1':
            // != is represented by 1
            return (leftResult != rightResult);
        case '2':
            // == is represented by 2
            return (leftResult == rightResult);
        case '3':
            // >= is represented by 3
            return (leftResult >= rightResult);
        case '4':
            // <= is represented by 4
            return (leftResult <= rightResult);
        case '5':
            // > is represented by 5
            return (leftResult > rightResult);
        case '6':
            // < is represented by 6
            return (leftResult < rightResult);
        default:
            __throw_invalid_argument("There is no such operator");
    }
}