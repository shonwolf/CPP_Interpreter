/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#ifndef CONDITIONPARSER_H
#define CONDITIONPARSER_H

#include "Command.h"
#include "Parser.h"
#include "Operator.h"
#include <string>
class ConditionParser : public Command {
    // the members
    vector<Command*> m_commands;
    //Parser* m_p;
    vector<string> m_leftConditionSide;
    vector<string> m_rightConditionSide;
    string m_op;
    Operator m_o;
public:
    ConditionParser(vector<string> parameters, VariablesData* variablesData);
    virtual vector<Command*> getCommands();
    virtual bool checkCondition();
    virtual void doCommand() {};
    virtual ~ConditionParser() {}
};

#endif
