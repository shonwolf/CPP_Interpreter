/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#include <vector>
#include <string>
#include "Parser.h"
#include "Lexer.h"
#include "CreateExpression.h"
using namespace std;

/****************************************************************************************************
* function name: main.
* The Input: int argc, char* argv[].
* The output: number who show the exit of the process.
* The Function operation: this function start all the program.
****************************************************************************************************/
int main(int argc, char* argv[]) {
    Lexer l = Lexer();
    // getting the script split into vector
    vector<string> strings = l.lexer(argv[1]);
    VariablesData* variablesData = new VariablesData();
    Parser p = Parser(variablesData);
    // start doing all the commands after parse the string
    p.parser(strings);
    delete(variablesData);
    return 0;
}