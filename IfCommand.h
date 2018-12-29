/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#ifndef IFCOMMAND_H
#define IFCOMMAND_H

#include "Command.h"
#include "Operator.h"
class IfCommand : public Command {
public:
    IfCommand(vector<string> parameters, VariablesData* variablesData);
    virtual void doCommand();
};

#endif
