/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#include "OpenServerCommand.h"

/****************************************************************************************************
* function name: this is constructor.
* The Input: vector<string> parameters, VariablesData* variablesData.
* The output: nothing.
* The Function operation: initialize the members with the data.
****************************************************************************************************/
OpenServerCommand::OpenServerCommand(vector<string> parameters, VariablesData* variablesData)
                                     : Command(parameters, variablesData) {}

/****************************************************************************************************
* function name: doCommand.
* The Input: nothing.
* The output: nothing.
* The Function operation: this function to the command of this class.
****************************************************************************************************/
void OpenServerCommand::doCommand() {
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
    vector<string> expression1 = {};
    int i;
    int size = this->getParameters().size();
    // get the first expression
    for (i = 0; i < size; i++) {
        // ',' marks the end of the expresion
        if (this->getParameters()[i] == ",") {
            break;
        }
        expression1.push_back(this->getParameters()[i]);
    }
    i++;
    size = this->getParameters().size();
    vector<string> expression2 = {};
    // get the second expression - keep going from the last one
    for ( ; i < size; i++) {
        // ',' marks the end of the expresion
        if (this->getParameters()[i] == ",") {
            break;
        }
        expression2.push_back(this->getParameters()[i]);
    }
    CreateExpression createExpression = CreateExpression();
    Expression* exp1 = createExpression.fromExpression(expression1, this->getVariablesData());
    int port = exp1->calculate();
    delete(exp1);
    // the port need to be in the range of 0 - 65535
    if (port < 0 || port > 65535) {
        __throw_invalid_argument("Invalid number of port - not in range");
    }
    Expression* exp2 = createExpression.fromExpression(expression2, this->getVariablesData());
    double numberTimesReadInSecond = exp2->calculate();
    delete(exp2);
    // the number of times to read line in one second should be positive
    if (numberTimesReadInSecond <= 0) {
        __throw_invalid_argument("Invalid number of times to read line in second");
    }
    DataReaderServer dataReaderServer = DataReaderServer();
    this->m_myParams = new MyParamsServer();
    this->m_myParams->port = port;
    this->m_myParams->numberTimesReadInSecond = numberTimesReadInSecond;
    this->m_myParams->variablesData = this->getVariablesData();
    pthread_t pthreadOpenServerCommand;
    // the pthread for openServerCommand is saved so that we will not finish the program until finish there
    this->getVariablesData()->addPthreadId("openServerCommand", &pthreadOpenServerCommand);
    pthread_create(&pthreadOpenServerCommand, nullptr, dataReaderServer.openDataServer, this->m_myParams);
    pthread_detach(pthreadOpenServerCommand);
}

/****************************************************************************************************
* function name: ~OpenServerCommand.
* The Input: nothing.
* The output: nothing.
* The Function operation: the destructor make sure to erase all the things that were put on the
*                         heap.
****************************************************************************************************/
OpenServerCommand::~OpenServerCommand() {
    delete(this->m_myParams);
}