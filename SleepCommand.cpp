/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#include "SleepCommand.h"

/****************************************************************************************************
* function name: this is constructor.
* The Input: vector<string> parameters, VariablesData* variablesData.
* The output: nothing.
* The Function operation: initialize the members with the data.
****************************************************************************************************/
SleepCommand::SleepCommand(vector<string> parameters, VariablesData *variablesData) : Command(parameters,
                                                                                              variablesData) {}

/****************************************************************************************************
* function name: doCommand.
* The Input: nothing.
* The output: nothing.
* The Function operation: this function to the command of this class.
****************************************************************************************************/
void SleepCommand::doCommand() {
    // check if the parameter is legal
    if (!isdigit(this->getParameters()[0][0])) {
        __throw_invalid_argument("the sleep has to get number as argument");
    }
    CreateExpression createExpression = CreateExpression();
    Expression* exp = createExpression.fromExpression(this->getParameters(), this->getVariablesData());
    // 1 millisecond = 1000 microseconds and we get our number to sleep for in milliseconds
    unsigned int microseconds = exp->calculate() * 1000;
    delete(exp);
    usleep(microseconds);
}