/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#include "PrintCommand.h"

/****************************************************************************************************
* function name: this is constructor.
* The Input: vector<string> parameters, VariablesData* variablesData.
* The output: nothing.
* The Function operation: initialize the members with the data.
****************************************************************************************************/
PrintCommand::PrintCommand(vector<string> parameters, VariablesData *variablesData) : Command(parameters,
                                                                                              variablesData) {}

/****************************************************************************************************
* function name: doCommand.
* The Input: nothing.
* The output: nothing.
* The Function operation: this function to the command of this class.
****************************************************************************************************/
void PrintCommand::doCommand() {
    CreateExpression createExpression = CreateExpression();
    vector<string> printSection = {};
    int i = 0;
    int size = this->getParameters().size();
    // print all the parameters
    while (i < size) {
        // ',' marks the end of the string/expresion to print
        while (this->getParameters()[i] != ",") {
            printSection.push_back(this->getParameters()[i]);
            i++;
        }
        // if its string than print him and if its expression then print his result
        if (printSection[0][0] == '"') {
            if (printSection.size() == 1) {
                cout << printSection[0].substr(1, printSection[0].length() - 2);
            } else {
                int j = 0;
                cout << printSection[j].substr(1, printSection[j].length() - 1) << " ";
                j++;
                while (printSection[j].back() != '"') {
                    cout << printSection[j] << " ";
                    j++;
                }
                cout << printSection[j].substr(0, printSection[j].length() - 1);
            }
        } else {
            Expression* exp = createExpression.fromExpression(printSection, this->getVariablesData());
            cout << exp->calculate();
            delete(exp);
        }
        i++;
        if (i < size) {
            cout << " ";
        }
        printSection = {};
    }
    cout << endl;
}

