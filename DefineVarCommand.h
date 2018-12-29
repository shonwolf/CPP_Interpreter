/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#ifndef DEFINEVARCOMMAND_H
#define DEFINEVARCOMMAND_H

#include "Command.h"
class DefineVarCommand : public Command {
public:
    DefineVarCommand(vector<string> parameters, VariablesData* variablesData);
    virtual void doCommand();
};

#endif
