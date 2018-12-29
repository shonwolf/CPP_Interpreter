/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#ifndef SLEEPCOMMANDFACTORY_H
#define SLEEPCOMMANDFACTORY_H

#include "CommandFactory.h"
#include "SleepCommand.h"
class SleepCommandFactory : public CommandFactory {
public:
    virtual Command* getNewCommand(vector<string> parameters, VariablesData* variablesData) {
        return new SleepCommand(parameters, variablesData);
    }
};

#endif
