/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#ifndef PLACEMENTOPERATORCOMMAND_H
#define PLACEMENTOPERATORCOMMAND_H

#include "Command.h"
#include <unordered_map>
#include <queue>
#include <stack>
#include "CreateExpression.h"
#include "ConnectToServer.h"
class PlacementOperatorCommand : public Command {
    // the members
    CreateExpression m_createExpression;
public:
    PlacementOperatorCommand(vector<string> parameters, VariablesData* variablesData);
    virtual void doCommand();
    virtual vector<string> translateParameters();
};

#endif
