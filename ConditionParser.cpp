/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#include "ConditionParser.h"

/****************************************************************************************************
* function name: this is constructor.
* The Input: vector<string> parameters, VariablesData *variablesData.
* The output: nothing.
* The Function operation: initialize the members with the data.
****************************************************************************************************/
ConditionParser::ConditionParser(vector<string> parameters, VariablesData* variablesData)
                                 : Command(parameters, variablesData) {
    bool isOpFound = false;
    this->m_o = Operator();
    vector<string> condition = {};
    // get the condition of the while and erase him from the parameters
    while (this->getParameters()[0] != "{") {
        condition.push_back(this->getParameters()[0]);
        this->eraseFirstParameter();
    }
    // erase the "{"
    this->eraseFirstParameter();
    // erase the ";"
    this->eraseFirstParameter();
    // get expression from each side and the operator between them
    for (auto &curString : condition) {
        if(this->m_o.getOperatorNumber().count(curString) == 0 && isOpFound == false) {
            // if this is the left expression
            this->m_leftConditionSide.push_back(curString);
        } else if (this->m_o.getOperatorNumber().count(curString) == 1) {
            // if this is the operator
            this->m_op = curString;
            isOpFound = true;
        } else {
            // if this is the right expression
            this->m_rightConditionSide.push_back(curString);
        }
    }
    this->m_commands = {};
    Parser p = Parser(variablesData);
    int len = this->getParameters().size();
    // move on all the parameters and get the commands
    for (int i = 0; i < len; i++) {
        // if this string is command than do him with his parameters
        if (p.getCommandsByKey().count(this->getParameters()[i]) == 1) {
            Command* command = p.createCommand(this->getParameters(), i);
            this->m_commands.push_back(command);
        }
    }
}

/****************************************************************************************************
* function name: getCommands.
* The Input: nothing.
* The output: the map of the commands.
* The Function operation: this function return the map of the commands.
****************************************************************************************************/
vector<Command*> ConditionParser::getCommands() {
    return this->m_commands;
}

/****************************************************************************************************
* function name: checkCondition.
* The Input: nothing.
* The output: true if the condition is true, false otherwise.
* The Function operation: this function checks if the condition is true and return true if it does,
*                         false otherwise.
****************************************************************************************************/
bool ConditionParser::checkCondition() {
    return this->m_o.condition(this->m_leftConditionSide, this->m_op, this->m_rightConditionSide,
                               this->getVariablesData());
}
