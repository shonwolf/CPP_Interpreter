/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#include "CommandExpression.h"

/****************************************************************************************************
* function name: this is constructor.
* The Input: Command* command.
* The output: nothing.
* The Function operation: initialize the members with the data.
****************************************************************************************************/
CommandExpression::CommandExpression(Command* command) {
    this->m_command = command;
}

/****************************************************************************************************
* function name: calculate.
* The Input: nothing.
* The output: the doCommand of the commandExpressions.
* The Function operation: this function return the doCommand of the commandExpressions.
****************************************************************************************************/
double CommandExpression::calculate() {
    this->m_command->doCommand();
    // return 0 for no reason, this function here need only to doCommand
    return 0;
}

/****************************************************************************************************
* function name: getCommand.
* The Input: nothing.
* The output: the Command.
* The Function operation: this function return the Command.
****************************************************************************************************/
Command* CommandExpression::getCommand() {
    return this->m_command;
}

/****************************************************************************************************
* function name: this is destructor.
* The Input: nothing.
* The output: nothing.
* The Function operation: free all the data was allocate on the heap in this class.
****************************************************************************************************/
CommandExpression::~CommandExpression() {
    delete(this->m_command);
}
