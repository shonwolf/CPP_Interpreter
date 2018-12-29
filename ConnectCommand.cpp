/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#include "ConnectCommand.h"

/****************************************************************************************************
* function name: this is constructor.
* The Input: vector<string> parameters, VariablesData* variablesData.
* The output: nothing.
* The Function operation: initialize the members with the data.
****************************************************************************************************/
ConnectCommand::ConnectCommand(vector<string> parameters, VariablesData* variablesData) : Command(parameters,
                                                                                                  variablesData) {}

/****************************************************************************************************
* function name: doCommand.
* The Input: nothing.
* The output: nothing.
* The Function operation: this function to the command of this class.
****************************************************************************************************/
void ConnectCommand::doCommand() {
    int commaCount = 0;
    // count the number of commas in the parameters vector
    for (auto &curParameter: this->getParameters()) {
        if (curParameter == ",") {
            commaCount++;
        }
    }
    // check if the function get 2 parameters only - if there are no more than two commas
    if (commaCount != 2) {
        __throw_invalid_argument("Invalid number of arguments");
    }
    vector<string> expression = {};
    int i;
    int size = this->getParameters().size();
    // get expression - start after the ip and the ',' after him - so start from place 2
    for (i = 2; i < size; i++) {
        // ',' marks the end of the expresion
        if (this->getParameters()[i] == ",") {
            break;
        }
        expression.push_back(this->getParameters()[i]);
    }
    string ip = this->getParameters()[0];
    checkIP(ip);
    CreateExpression createExpression = CreateExpression();
    Expression* exp = createExpression.fromExpression(expression, this->getVariablesData());
    int port = exp->calculate();
    delete(exp);
    // the port need to be in the range of 0 - 65535
    if (port < 0 || port > 65535) {
        __throw_invalid_argument("Invalid number of port - not in range");
    }
    ConnectToServer connectToServer = ConnectToServer();
    // connect to the server
    connectToServer.connectServer(ip, port, this->getVariablesData());
}

/****************************************************************************************************
* function name: checkIP.
* The Input: string ip.
* The output: nothing.
* The Function operation: this function check if the IP is fine.
****************************************************************************************************/
void ConnectCommand::checkIP(string ip) {
    int endPos = 0;
    string concat = ".";
    string strNum;
    int num;
    // check if every number is between 0 - 255 and that has 3 dots - contain 4 numbers
    for (int i = 0; i < 4; i++) {
        if (ip.find(concat, 0) == string::npos && i < 3) {
            __throw_invalid_argument("Invalid format of IP, there are not enough dots");
        }
        if (ip.find(concat, 0) == string::npos) {
            // get last number
            strNum = ip.substr(0, ip.length());
            num = stoi(strNum);
            // check the number in range 0 - 255
            if (num < 0 || num > 255) {
                __throw_invalid_argument("Invalid number in IP");
            }
            break;
        } else {
            endPos = ip.find(concat, 0);
        }
        strNum = ip.substr(0, endPos);
        num = stoi(strNum);
        // check the number in range 0 - 255
        if (num < 0 || num > 255) {
            __throw_invalid_argument("Invalid number in IP");
        }
        ip = ip.substr(endPos + 1, ip.length() - 1);
    }
}