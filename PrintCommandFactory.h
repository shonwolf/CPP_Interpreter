/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#ifndef PRINTCOMMANDFACTORY_H
#define PRINTCOMMANDFACTORY_H

#include "CommandFactory.h"
#include "PrintCommand.h"
class PrintCommandFactory : public CommandFactory {
public:
    virtual Command* getNewCommand(vector<string> parameters, VariablesData* variablesData) {
        return new PrintCommand(parameters, variablesData);
    }
};

#endif
