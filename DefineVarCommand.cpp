/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#include "DefineVarCommand.h"

/****************************************************************************************************
* function name: this is constructor.
* The Input: vector<string> parameters, VariablesData* variablesData.
* The output: nothing.
* The Function operation: initialize the members with the data.
****************************************************************************************************/
DefineVarCommand::DefineVarCommand(vector<string> parameters, VariablesData* variablesData) : Command(parameters,
                                                                                                      variablesData) {}

/****************************************************************************************************
* function name: doCommand.
* The Input: nothing.
* The output: nothing.
* The Function operation: this function to the command of this class.
****************************************************************************************************/
void DefineVarCommand::doCommand() {
    // put the variable in the symbolTable and default his values to 0
    this->getVariablesData()->addSymbol(this->getParameters()[0], 0);
}
