/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#include "Parser.h"

/****************************************************************************************************
* function name: this is constructor.
* The Input: VariablesData* variablesData.
* The output: nothing.
* The Function operation: initialize the members with the data.
****************************************************************************************************/
Parser::Parser(VariablesData* variablesData) {
    this->m_variablesData = variablesData;
    this->m_commandsByKey = {{"openDataServer", new OpenServerCommandFactory()},
                             {"connect", new ConnectCommandFactory()},
                             {"while", new LoopCommandFactory()},
                             {"=", new PlacementOperatorCommandFactory()},
                             {"var", new DefineVarCommandFactory()},
                             {"if", new IfCommandFactory()},
                             {"print", new PrintCommandFactory()},
                             {"sleep", new SleepCommandFactory()},
                             {"exit", new ExitCommandFactory()}};
    this->m_commands = {};
}

/****************************************************************************************************
* function name: parser.
* The Input: vector<string> strings.
* The output: nothing.
* The Function operation: this function parse all the strings to commands or parameters and do
*                         those commands with the needed parameters.
****************************************************************************************************/
void Parser::parser(vector<string> strings) {
    int len = strings.size();
    // move on all the array
    for (int i = 0; i < len; i++) {
        // if this string is command than do him with his parameters
        if (this->m_commandsByKey.count(strings[i]) == 1) {
            Command* command = this->createCommand(strings, i);
            // do the command needed with her parameters
            command->doCommand();
        }
    }
}

/****************************************************************************************************
* function name: createCommand.
* The Input: vector<string> strings, int& i.
* The output: the next Command.
* The Function operation: this function return the next Command.
****************************************************************************************************/
Command* Parser::createCommand(vector<string> strings, int& i) {
    vector<string> parameters = {};
    int commandIndex = i;
    // get the parameter for the Command
    parameters = this->getInfoUntilEndOfLine(strings, i);
    Command* command = this->m_commandsByKey[strings[commandIndex]]->getNewCommand(parameters, this->m_variablesData);
    // save for delete from heap memory afterwords
    this->m_commands.push_back(command);
    return command;
}

/****************************************************************************************************
* function name: getInfoUntilEndOfLine.
* The Input: vector<string> strings, int& i.
* The output: the line until her end.
* The Function operation: this function return the line until her end.
****************************************************************************************************/
vector<string> Parser::getInfoUntilEndOfLine(vector<string> strings, int& i) {
    vector<string> lineUntilTheEnd = {};
    if (strings[i] == "if" || strings[i] == "while") {
        i++;
        // if the command is command that contain another commands in it
        while (strings[i] != "}") {
            lineUntilTheEnd.push_back(strings[i]);
            i++;
        }
        return lineUntilTheEnd;
    }
    if (strings[i] == "var") {
        i++;
        lineUntilTheEnd.push_back(strings[i]);
        return lineUntilTheEnd;
    }
    // if the command is "=" takes the name of the variable too
    if (strings[i] == "=") {
        lineUntilTheEnd.push_back(strings[i - 1]);
    }
    i++;
    // get all the line until the end
    while (strings[i] != ";") {
        lineUntilTheEnd.push_back(strings[i]);
        i++;
    }
    return lineUntilTheEnd;
}

/****************************************************************************************************
* function name: getCommands.
* The Input: nothing.
* The output: the commands.
* The Function operation: this function return the commands.
****************************************************************************************************/
vector<Command*> Parser::getCommands() {
    return this->m_commands;
}

/****************************************************************************************************
* function name: getCommandsByKey.
* The Input: nothing.
* The output: the commandsByKey.
* The Function operation: this function return the commandsByKey.
****************************************************************************************************/
unordered_map<string, CommandFactory*> Parser::getCommandsByKey() {
    return this->m_commandsByKey;
}

/****************************************************************************************************
* function name: this is destructor.
* The Input: nothing.
* The output: nothing.
* The Function operation: free all the data was allocate on the heap in this class.
****************************************************************************************************/
Parser::~Parser() {
    for (auto &curCommandFactory : this->m_commandsByKey) {
        delete(curCommandFactory.second);
    }
    for(auto &curCommand : this->m_commands) {
        delete(curCommand);
    }
}
