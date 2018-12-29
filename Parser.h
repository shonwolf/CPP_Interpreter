/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#ifndef PARSER_H
#define PARSER_H

#include <unordered_map>
#include "Command.h"
#include "CommandFactory.h"
#include "OpenServerCommandFactory.h"
#include "LoopCommandFactory.h"
#include "ConnectCommandFactory.h"
#include "PlacementOperatorCommandFactory.h"
#include "DefineVarCommandFactory.h"
#include "IfCommandFactory.h"
#include "PrintCommandFactory.h"
#include "SleepCommandFactory.h"
#include "ExitCommandFactory.h"
#include "VariablesData.h"
class Parser {
    // the members
    unordered_map<string, CommandFactory*> m_commandsByKey;
    VariablesData* m_variablesData;
    vector<Command*> m_commands;
    vector<string> getInfoUntilEndOfLine(vector<string> strings, int& i);
public:
    Parser(VariablesData* variablesData);
    void parser(vector<string> strings);
    vector<Command*> getCommands();
    unordered_map<string, CommandFactory*> getCommandsByKey();
    Command* createCommand(vector<string> strings, int& i);
    ~Parser();
};

#endif
