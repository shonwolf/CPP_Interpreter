/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#ifndef LOOPCOMMANDFACTORY_H
#define LOOPCOMMANDFACTORY_H

#include "CommandFactory.h"
#include "LoopCommand.h"
class LoopCommandFactory : public CommandFactory {
public:
    virtual Command* getNewCommand(vector<string> parameters, VariablesData* variablesData) {
        return new LoopCommand(parameters, variablesData);
    }
};

#endif
