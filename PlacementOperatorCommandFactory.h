/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#ifndef PLACEMENTOPERATORCOMMANDFACTORY_H
#define PLACEMENTOPERATORCOMMANDFACTORY_H

#include "CommandFactory.h"
#include "PlacementOperatorCommand.h"
class PlacementOperatorCommandFactory : public CommandFactory {
public:
    virtual Command* getNewCommand(vector<string> parameters, VariablesData* variablesData) {
        return new PlacementOperatorCommand(parameters, variablesData);
    }
};

#endif
