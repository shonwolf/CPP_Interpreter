/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#include "PlacementOperatorCommand.h"

/****************************************************************************************************
* function name: this is constructor.
* The Input: vector<string> parameters, VariablesData* variablesData.
* The output: nothing.
* The Function operation: initialize the members with the data.
****************************************************************************************************/
PlacementOperatorCommand::PlacementOperatorCommand(vector<string> parameters, VariablesData* variablesData)
                                                   : Command(parameters, variablesData) {
    this->m_createExpression = CreateExpression();
}

/****************************************************************************************************
* function name: doCommand.
* The Input: nothing.
* The output: nothing.
* The Function operation: this function to the command of this class.
****************************************************************************************************/
void PlacementOperatorCommand::doCommand() {
    ConnectToServer connectToServer = ConnectToServer();
    this->setParameters(this->translateParameters());
    // if the second parameter is bind than we declare on new bind-declaration
    if (this->getParameters()[1] == "bind") {
        // bind the variable to the path or to the other variable or too both of them if there is
        if (this->getVariablesData()->getBindDeclarationTable().count(this->getParameters()[2]) == 1) {
            string bindDeclaration = this->getVariablesData()->getBindDeclarationTable()[this->getParameters()[2]];
            this->getVariablesData()->addBindDeclaration(this->getParameters()[0], bindDeclaration);
            this->getVariablesData()->addBindVariable(this->getParameters()[0], this->getParameters()[2]);
            this->getVariablesData()->addBindVariable(this->getParameters()[2], this->getParameters()[0]);
            string path = this->getVariablesData()->getBindDeclarationTable()[this->getParameters()[2]];
            string valStr = to_string(this->getVariablesData()->getSymbolTable()[this->getParameters()[2]]);
            int socketId = this->getVariablesData()->getSocketsIdTable()["ConnectToServer"];
            // set the parameter on the simulator
            connectToServer.writeToSimulator("set " + path + " " + valStr, socketId);
        } else if (this->getVariablesData()->getSymbolTable().count(this->getParameters()[2]) == 1) {
            this->getVariablesData()->addBindVariable(this->getParameters()[0], this->getParameters()[2]);
            this->getVariablesData()->addBindVariable(this->getParameters()[2], this->getParameters()[0]);
        } else {
            // move the quotation marks from the quote
            string bindPath = this->getParameters()[2].substr(1, this->getParameters()[2].length() - 2);
            this->getVariablesData()->addBindDeclaration(this->getParameters()[0], bindPath);
        }
        // need to update the variable value to be the same as in the simulator!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        return;
    }
    // the second parameter will be the value to change in the unordered map and set in the simulator
    double val = stod(this->getParameters()[1]);
    // set the val of the symbol in the left side of the placement operator
    this->getVariablesData()->updateSymbolVal(this->getParameters()[0], val);
    string path = this->getVariablesData()->getBindDeclarationTable()[this->getParameters()[0]];
    string valStr = to_string(val);
    int socketId = this->getVariablesData()->getSocketsIdTable()["ConnectToServer"];
    connectToServer.writeToSimulator("set " + path + " " + valStr, socketId);
}

/****************************************************************************************************
* function name: translateParameters.
* The Input: nothing.
* The output: vector<string>.
* The Function operation: this function get the parameters that this class do does her command on
*                         and return them.
****************************************************************************************************/
vector<string> PlacementOperatorCommand::translateParameters() {
    vector<string> parameters = {};
    parameters.push_back(this->getParameters()[0]);
    /* we need to check now if the parameter from the right is bind-declaration/Expression */
    if (this->getParameters()[1] == "bind") {
        // we check if the parameter from the right is bind-declaration and if it does take the declaration needed
        parameters.push_back(this->getParameters()[1]);
        parameters.push_back(this->getParameters()[2]);
    } else {
        // if it's an Expression so we will get final value after calculate it
        vector<string> expression = this->getParameters();
        expression.erase(expression.begin());
        Expression* exp = this->m_createExpression.fromExpression(expression, this->getVariablesData());
        double result = exp->calculate();
        parameters.push_back(to_string(result));
        delete(exp);
    }
    return parameters;
}