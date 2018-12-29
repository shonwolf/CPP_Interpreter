/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#include "IfCommand.h"
#include "Parser.h"

/****************************************************************************************************
* function name: this is constructor.
* The Input: vector<string> parameters, VariablesData* variablesData.
* The output: nothing.
* The Function operation: initialize the members with the data.
****************************************************************************************************/
IfCommand::IfCommand(vector<string> parameters, VariablesData* variablesData) : Command(parameters, variablesData) {}

/****************************************************************************************************
* function name: doCommand.
* The Input: nothing.
* The output: nothing.
* The Function operation: this function to the command of this class.
****************************************************************************************************/
void IfCommand::doCommand() {
    vector<string> left = {};
    vector<string> right = {};
    string op;
    bool isOpFound = false;
    Operator o = Operator();
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
        if (o.getOperatorNumber().count(curString) == 0 && isOpFound == false) {
            // if this is the left expression
            left.push_back(curString);
        } else if (o.getOperatorNumber().count(curString) == 1) {
            // if this is the operator
            op = curString;
            isOpFound = true;
        } else {
            // if this is the right expression
            right.push_back(curString);
        }
    }
    vector<Command *> commands = {};
    Parser p = Parser(this->getVariablesData());
    int len = this->getParameters().size();
    // move on all the parameters and get the commands
    for (int i = 0; i < len; i++) {
        // if this string is command than do him with his parameters
        if (p.getCommandsByKey().count(this->getParameters()[i]) == 1) {
            Command *command = p.createCommand(this->getParameters(), i);
            commands.push_back(command);
        }
    }
    // do all the commands
    if (o.condition(left, op, right, this->getVariablesData())) {
        for (auto &curCommand : commands) {
            curCommand->doCommand();
        }
    }
}



