/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#ifndef CONNECTCOMMAND_H
#define CONNECTCOMMAND_H

#include "Command.h"
#include "ConnectToServer.h"
#include "CreateExpression.h"
#include <pthread.h>
#include <iostream>

class ConnectCommand : public Command {
    void checkIP(string ip);
public:
    ConnectCommand(vector<string> parameters, VariablesData* variablesData);
    virtual void doCommand();
};

#endif
