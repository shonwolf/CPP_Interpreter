/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#ifndef OPENSERVERCOMMAND_H
#define OPENSERVERCOMMAND_H

#include "Command.h"
#include "DataReaderServer.h"
#include <pthread.h>
#include <iostream>
#include "CreateExpression.h"
#include "MyParamsServer.h"

class OpenServerCommand : public Command {
    // the members
    struct MyParamsServer* m_myParams;
public:
    OpenServerCommand(vector<string> parameters, VariablesData* variablesData);
    virtual void doCommand();
    ~OpenServerCommand();
};

#endif
