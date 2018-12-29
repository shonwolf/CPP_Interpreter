/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#ifndef CONNECTCOMMANDFACTORY_H
#define CONNECTCOMMANDFACTORY_H

#include "CommandFactory.h"
#include "ConnectCommand.h"
class ConnectCommandFactory : public CommandFactory {
public:
    virtual Command* getNewCommand(vector<string> parameters, VariablesData* variablesData) {
        return new ConnectCommand(parameters, variablesData);
    }
};

#endif
