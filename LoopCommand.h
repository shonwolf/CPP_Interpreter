/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#ifndef LOOPCOMMAND_H
#define LOOPCOMMAND_H

#include "Command.h"
#include "Operator.h"
class LoopCommand : public Command {
public:
    LoopCommand(vector<string> parameters, VariablesData* variablesData);
    virtual void doCommand();
};


#endif
