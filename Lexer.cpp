/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#include "Lexer.h"

/****************************************************************************************************
* function name: lexer.
* The Input: string script.
* The output: array of the strings from the script.
* The Function operation: this function interpret the script into strings and return the array from
*                         it.
****************************************************************************************************/
vector<string> Lexer::lexer(string script) {
    string concat = " ";
    string scriptInString = "";
    vector<string> strings = {};
    // we get the script from the file
    scriptInString = getStringFromFile(script);
    // add to know when to exit
    scriptInString += " exit";
    scriptInString += " ;";
    scriptInString = this->convertWhiteSpacesToSpace(scriptInString);
    scriptInString = this->putSpacesWhereNeeded(scriptInString);
    strings =  this->splitStringBySpaces(scriptInString);
    strings = this->markDifferentParametersWhereNeeded(strings);
    return strings;
}

/****************************************************************************************************
* function name: splitStringBySpaces.
* The Input: string scriptInString.
* The output: vector of strings that the result of the split by spaces of the string that the
 *            function gets.
* The Function operation: this function return vector of strings that the result of the split by
*                         spaces of the string that the function gets.
****************************************************************************************************/
vector<string> Lexer::splitStringBySpaces(string scriptInString) {
    int endPos = 0;
    vector<string> strings = {};
    while(scriptInString[0] != '\0') {
        if(this->indexToConcat(scriptInString) == -1) {
            // get last string
            strings.push_back(scriptInString.substr(0, scriptInString.length()));
            break;
        } else {
            endPos = this->indexToConcat(scriptInString);
        }
        // get next string
        strings.push_back(scriptInString.substr(0, endPos));
        // keep interpret from the next string in the script
        scriptInString = scriptInString.substr(endPos + 1, scriptInString.length() - 1);
    }
    strings[strings.size() - 1] = ";";
    return strings;
}

/****************************************************************************************************
* function name: indexToConcat.
* The Input: string scriptInString.
* The output: the place to split in him.
* The Function operation: this function return the place to split in him.
****************************************************************************************************/
int Lexer::indexToConcat(string scriptInString) {
    if (scriptInString.find(" ", 0) != string::npos) {
        return scriptInString.find(" ", 0);
    }
    return -1;
}

/****************************************************************************************************
* function name: putSpacesWhereNeeded.
* The Input: string scriptInString.
* The output: the same string, only if there is not space after an operator than put one before him.
* The Function operation: this function checks if after each operator there is space and if there is
*                         not put one.
****************************************************************************************************/
string Lexer::putSpacesWhereNeeded(string scriptInString) {
    // the signs to make sure that there is space after
    unordered_map<char, int> concatSigns = {{'!', -1}, {'>', -1}, {'<', -1}, {'=', -1}, {'+', -1}, {'-', -1},
                                            {'/', -1}, {'*', -1}, {'(', -1}, {')', -1}, {',', -1}};
    string newScriptInString = "";
    bool inQuotationMarks = false;
    int len = scriptInString.length();
    // move on all the string and make sure that after each operator there is space
    for (int i = 0; i < len; i++) {
        // if the sign is in quotation marks than we do not put space before or after him in the quote
        if (scriptInString[i] == '"') {
            // if was fales than now start quote, if was true than now end quote
            inQuotationMarks = !inQuotationMarks;
        }
        if (concatSigns.count(scriptInString[i]) == 1 && !inQuotationMarks) {
            if (scriptInString[i - 1] != ' ' && newScriptInString[newScriptInString.length() - 1] != ' ') {
                newScriptInString += ' ';
            }
            newScriptInString += scriptInString[i];
            if (scriptInString[i + 1] != '=') {
                if (scriptInString[i + 1] != ' ') {
                    newScriptInString += ' ';
                }
            } else {
                i++;
                newScriptInString += scriptInString[i];
                if (scriptInString[i + 1] != ' ') {
                    newScriptInString += ' ';
                }
            }
        } else {
            newScriptInString += scriptInString[i];
        }
    }
    return newScriptInString;
}

/****************************************************************************************************
* function name: markDifferentParametersWhereNeeded.
* The Input: vector<string> strings.
* The output: the new marked vector after commands need two parameters.
* The Function operation: this function checks if its command that need to get 2 parameters
*                         and if it is put after each one sign ',' to mark it and return the new
*                         vector.
****************************************************************************************************/
vector<string> Lexer::markDifferentParametersWhereNeeded(vector<string> strings) {
    int i = 0;
    int commaCount = 0;
    vector<string> newStrings = {};
    bool isTwoParameters = false;
    int size = strings.size();
    // move on all the strings
    while (i < size) {
        // if its command string that need to get 2 parameters than put after each one sign ',' to mark it
        if (strings[i] == "openDataServer" || strings[i] == "connect" || strings[i] == "print") {
            if (strings[i] == "openDataServer" || strings[i] == "connect") {
                isTwoParameters = true;
            }
            newStrings.push_back(strings[i]);
            i++;
            while (strings[i] != ";") {
                // if the user put ',' between the program will count the parameters until now as the first expression
                if (strings[i] == ",") {
                    i++;
                    commaCount++;
                    continue;
                }
                // if we have expression now, put the "," after all the expression
                while (this->isOperator(strings[i]) || this->isOperator(strings[i + 1])) {
                    newStrings.push_back(strings[i]);
                    i++;
                }
                // if we have quote now, put the "," after all the quote (from first '"' second '"')
                if (strings[i][0] == '"') {
                    if (strings[i].back() != '"') {
                        newStrings.push_back(strings[i]);
                        i++;
                    }
                    if (strings[i - 1].back() != '"') {
                        while (strings[i].back() != '"') {
                            newStrings.push_back(strings[i]);
                            i++;
                        }
                    }
                }
                newStrings.push_back(strings[i]);
                newStrings.push_back(",");
                commaCount++;
                i++;
            }
            // if there is only one parameter and there is in the end (-)number, than take him as the second parameter
            if (commaCount == 1 && isTwoParameters) {
                if (newStrings[newStrings.size() - 3] == "-") {
                    string s1 = newStrings.back();
                    newStrings.pop_back();
                    string s2 = newStrings.back();
                    newStrings.pop_back();
                    string s3 = newStrings.back();
                    newStrings.pop_back();
                    newStrings.push_back(",");
                    newStrings.push_back(s3);
                    newStrings.push_back(s2);
                    newStrings.push_back(s1);
                }
            }
            newStrings.push_back(";");
            commaCount = 0;
            isTwoParameters = false;
        } else {
            newStrings.push_back(strings[i]);
        }
        i++;
    }
    return newStrings;
}

/****************************************************************************************************
* function name: isOperator.
* The Input: string s.
* The output: true if s is operator, false otherwise.
* The Function operation: this function return yes if s is operator, else otherwise.
****************************************************************************************************/
bool Lexer::isOperator(string s) {
    if (s == "+" || s == "-" || s == "/" || s == "*") {
        return true;
    }
    return false;
}

/****************************************************************************************************
* function name: convertWhiteSpacesToSpace.
* The Input: string scriptInString.
* The output: string that every tab or concat of spaces and tabs is convert to space.
* The Function operation: this function convert every tab or concat of spaces and tabs and return
*                         the new string.
****************************************************************************************************/
string Lexer::convertWhiteSpacesToSpace(string scriptInString) {
    string newScriptInString = "";
    int i = 0;
    // move on all the string and convert every tab or concat of spaces and tabs to space
    while (scriptInString[i] != '\0') {
        // if this is space or tab or concat of them than put instead of all only space
        if (scriptInString[i] == ' ' || scriptInString[i] == '\t') {
            while ((scriptInString[i] == ' ' || scriptInString[i] == '\t') && scriptInString[i] != '\0') {
                i++;
            }
            if (scriptInString[i] != '\0') {
                newScriptInString += ' ';
                newScriptInString += scriptInString[i];
            }
        } else {
            newScriptInString += scriptInString[i];
        }
        i++;
    }
    return newScriptInString;
}

/****************************************************************************************************
* function name: getStringFromFile.
* The Input: string script.
* The output: string made of all the lines in the file with space between every string in the file.
* The Function operation: this function takes every line from the text and put her after the last
*                         one with space between them in the string and return this string in the
*                         end.
****************************************************************************************************/
string Lexer::getStringFromFile(string script) {
    fstream fs;
    string line;
    string scriptInString = "";
    fs.open(script, fstream::in | fstream::out | fstream::app);
    if (fs.fail()) {
        __throw_runtime_error("there was error in opening to the file");
    }

    /*
     * move on all the script and get the strings in it, after each end of line in the input entered, put ' ;' to
     * show it is the end of a line.
     */
    while(getline(fs, line)) {
        // take down the spaces or tabs before the line
        while (line[0] == ' ' || line[0] == '\t') {
            line = line.substr(1, line.length());
        }
        // if empty line than continue
        if (line == "") {
            continue;
        }
        scriptInString += line;
        // add ' ;' to the end of the line
        scriptInString += " ;";
        // add ' ' for making different between this string to the next
        scriptInString += " ";
    }
    fs.close();
    if (fs.is_open()) {
        __throw_runtime_error("there was error in closing to the file");
    }
    // take down the last ' '
    scriptInString = scriptInString.substr(0, scriptInString.length() - 1);
    return scriptInString;
}


