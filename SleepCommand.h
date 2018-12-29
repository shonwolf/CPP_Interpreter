/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#ifndef SLEEPCOMMAND_H
#define SLEEPCOMMAND_H

#include "Command.h"
#include <unistd.h>
class SleepCommand : public Command {
public:
    SleepCommand(vector<string> parameters, VariablesData* variablesData);
    virtual void doCommand();
};

#endif
