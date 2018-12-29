/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#ifndef OPENSERVERCOMMANDFACTORY_H
#define OPENSERVERCOMMANDFACTORY_H

#include "CommandFactory.h"
#include "OpenServerCommand.h"
class OpenServerCommandFactory : public CommandFactory {
public:
    virtual Command* getNewCommand(vector<string> parameters, VariablesData* variablesData) {
        return new OpenServerCommand(parameters, variablesData);
    }
};

#endif
