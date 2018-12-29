/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#include "ExitCommand.h"
#include "ConnectToServer.h"
/****************************************************************************************************
* function name: this is constructor.
* The Input: vector<string> parameters, VariablesData* variablesData.
* The output: nothing.
* The Function operation: initialize the members with the data.
****************************************************************************************************/
ExitCommand::ExitCommand(vector<string> parameters, VariablesData* variablesData) : Command(parameters,
                                                                                            variablesData) {}

/****************************************************************************************************
* function name: doCommand.
* The Input: nothing.
* The output: nothing.
* The Function operation: this function to the command of this class.
****************************************************************************************************/
void ExitCommand::doCommand() {
    // close all the sockets
    for (auto &curSocketToClose : this->getVariablesData()->getSocketsIdTable()) {
        close(curSocketToClose.second);
    }
}

