/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#ifndef DEFINEVARCOMMANDFACTORY_H
#define DEFINEVARCOMMANDFACTORY_H

#include "CommandFactory.h"
#include "DefineVarCommand.h"
class DefineVarCommandFactory : public CommandFactory {
public:
    virtual Command* getNewCommand(vector<string> parameters, VariablesData* variablesData) {
        return new DefineVarCommand(parameters, variablesData);
    }
};

#endif
