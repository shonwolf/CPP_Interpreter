/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#ifndef EXITCOMMAND_H
#define EXITCOMMAND_H

#include "Command.h"
#include <unistd.h>
class ExitCommand : public Command {
public:
    ExitCommand(vector<string> parameters, VariablesData* variablesData);
    virtual void doCommand();
};

#endif
