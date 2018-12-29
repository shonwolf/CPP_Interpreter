/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <vector>
#include <string>
#include "VariablesData.h"
#include "CreateExpression.h"
using namespace std;
class Command {
    // the members
    vector<string> m_parameters;
    VariablesData* m_variablesData;
public:
    Command(vector<string> parameters, VariablesData* variablesData) {
        this->m_parameters = parameters;
        this->m_variablesData = variablesData;
    }
    virtual void doCommand() = 0;
    virtual vector<string> getParameters() const {
        return this->m_parameters;
    }
    virtual void setParameters(vector<string> parameters) {
        this->m_parameters = parameters;
    }
    virtual VariablesData* getVariablesData() {
        return this->m_variablesData;
    }
    virtual void eraseFirstParameter() {
        this->m_parameters.erase(this->m_parameters.begin());
    }
    virtual ~Command() {}
};

#endif
