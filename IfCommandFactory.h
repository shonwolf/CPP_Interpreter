/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#ifndef IFCOMMANDFACTORY_H
#define IFCOMMANDFACTORY_H

#include "CommandFactory.h"
#include "IfCommand.h"
class IfCommandFactory : public CommandFactory {
public:
    virtual Command* getNewCommand(vector<string> parameters, VariablesData* variablesData) {
        return new IfCommand(parameters, variablesData);
    }
};

#endif
