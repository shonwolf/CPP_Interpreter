/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#ifndef EXITCOMMANDFACTORY_H
#define EXITCOMMANDFACTORY_H

#include "CommandFactory.h"
#include "ExitCommand.h"
class ExitCommandFactory : public CommandFactory {
public:
    virtual Command* getNewCommand(vector<string> parameters, VariablesData* variablesData) {
        return new ExitCommand(parameters, variablesData);
    }
};

#endif
