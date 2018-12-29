/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#ifndef DATEFROMSCRIPT_H
#define DATEFROMSCRIPT_H

#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>
using namespace std;
class Lexer {
    string getStringFromFile(string script);
    int indexToConcat(string scriptInString);
    string putSpacesWhereNeeded(string scriptInString);
    vector<string> markDifferentParametersWhereNeeded(vector<string> strings);
    vector<string> splitStringBySpaces(string scriptInString);
    string convertWhiteSpacesToSpace(string scriptInString);
    bool isOperator(string s);
public:
    vector<string> lexer(string script);
};

#endif
