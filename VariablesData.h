/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#ifndef VARIABLESDATA_H
#define VARIABLESDATA_H

#include <unordered_map>
#include <string>
#include <vector>
using namespace std;
class VariablesData {
    // the members
    unordered_map<string, double> m_symbolTable;
    unordered_map<string, string> m_bindDeclarationTable;
    unordered_map<string, pthread_t*> m_pthreadIdTable;
    unordered_multimap<string, string> m_bindVariablesTable;
    unordered_map<string, int> m_socketsIdTable;
    bool m_isConnected;
public:
    VariablesData();
    unordered_map<string, double> getSymbolTable();
    void addSymbol(string var, double val);
    void updateSymbolVal(string var, double val);
    unordered_map<string, string> getBindDeclarationTable();
    void addBindDeclaration(string var, string bindDeclaration);
    unordered_map<string, pthread_t*> getPthreadIdTable();
    void addPthreadId(string pthreadName, pthread_t* pthreadId);
    void addBindVariable(string variable, string bindVariable);
    unordered_map<string, int> getSocketsIdTable();
    void addSocketId(string sockBelong, int socketId);
    bool  getIsConnected();
    void setIsConnected(bool isConnected);
    pthread_mutex_t* getMutex();
    ~VariablesData();
};

#endif
