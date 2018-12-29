/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#ifndef COMMANDEXPRESSION_H
#define COMMANDEXPRESSION_H

#include "Expression.h"
#include "Command.h"
class CommandExpression : public Expression {
    // the members
    Command* m_command;
public:
    CommandExpression(Command* command);
    virtual double calculate();
    Command* getCommand();
    virtual ~CommandExpression();
};

#endif
