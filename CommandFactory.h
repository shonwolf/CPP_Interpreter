/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "Command.h"
#include <vector>
class CommandFactory {
public:
    virtual Command* getNewCommand(vector<string> parameters, VariablesData* variablesData) = 0;
    virtual ~CommandFactory() {}
};

#endif
