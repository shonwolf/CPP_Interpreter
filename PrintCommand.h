/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#ifndef PRINTCOMMAND_H
#define PRINTCOMMAND_H

#include "Command.h"
#include "CreateExpression.h"
class PrintCommand : public Command {
public:
    PrintCommand(vector<string> parameters, VariablesData* variablesData);
    virtual void doCommand();
};

#endif
