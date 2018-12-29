/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#include "VariablesData.h"
pthread_mutex_t mutex;

/****************************************************************************************************
* function name: this is constructor.
* The Input: nothing.
* The output: nothing.
* The Function operation: initialize the members with the data.
****************************************************************************************************/
VariablesData::VariablesData() {
    this->m_symbolTable = {};
    this->m_bindDeclarationTable = {};
    this->m_pthreadIdTable = {};
    this->m_bindDeclarationTable = {};
    this->m_socketsIdTable = {};
    this->m_isConnected = false;
    pthread_mutex_init(&mutex, nullptr);
}

/****************************************************************************************************
* function name: getSymbolTable.
* The Input: nothing.
* The output: the symbolTable.
* The Function operation: this function return the symbolTable.
****************************************************************************************************/
unordered_map<string, double> VariablesData::getSymbolTable() {
    pthread_mutex_lock(&mutex);
    // create copy of the unordered_map in the mutex so that pthreads will not take at the same time and return it
    unordered_map<string, double> temp = this->m_symbolTable;
    pthread_mutex_unlock(&mutex);
    return temp;
}

/****************************************************************************************************
* function name: addSymbol.
* The Input: string var, double val.
* The output: nothing.
* The Function operation: this function add symbol to the symbolTable.
****************************************************************************************************/
void VariablesData::addSymbol(string var, double val) {
    pthread_mutex_lock(&mutex);
    this->m_symbolTable.emplace(var, val);
    pthread_mutex_unlock(&mutex);
}

/****************************************************************************************************
* function name: updateSymbolVal.
* The Input: string var, double val.
* The output: nothing.
* The Function operation: this function update the value of the symbol that she gets in the
*                         symbolTable.
****************************************************************************************************/
void VariablesData::updateSymbolVal(string var, double val) {
    pthread_mutex_lock(&mutex);
    this->m_symbolTable[var] = val;
    // if this variable who we update him is binded than we update his bind variables too
    if (this->m_bindVariablesTable.count(var)) {
        for (auto &curBindVariable : this->m_bindVariablesTable) {
            if (curBindVariable.first == var) {
                this->m_symbolTable[curBindVariable.second] = val;
            }
        }
    }
    pthread_mutex_unlock(&mutex);
}

/****************************************************************************************************
* function name: getBindDeclarationTable.
* The Input: nothing.
* The output: the bindDeclarationTable.
* The Function operation: this function return the bindDeclarationTable.
****************************************************************************************************/
unordered_map<string, string> VariablesData::getBindDeclarationTable() {
    pthread_mutex_lock(&mutex);
    // create copy of the unordered_map in the mutex so that pthreads will not take at the same time and return it
    unordered_map<string, string> temp = this->m_bindDeclarationTable;
    pthread_mutex_unlock(&mutex);
    return temp;
}

/****************************************************************************************************
* function name: addBindDeclaration.
* The Input: string var, string bindDeclaration.
* The output: nothing.
* The Function operation: this function add bindDeclaration to the bindDeclarationTable.
****************************************************************************************************/
void VariablesData::addBindDeclaration(string var, string bindDeclaration) {
    pthread_mutex_lock(&mutex);
    this->m_bindDeclarationTable.emplace(var, bindDeclaration);
    pthread_mutex_unlock(&mutex);
}

/****************************************************************************************************
* function name: getPthreadIdTable.
* The Input: nothing.
* The output: the pthreadIdTable.
* The Function operation: this function return the pthreadIdTable.
****************************************************************************************************/
unordered_map<string, pthread_t*> VariablesData::getPthreadIdTable() {
    pthread_mutex_lock(&mutex);
    // create copy of the unordered_map in the mutex so that pthreads will not take at the same time and return it
    unordered_map<string, pthread_t*> temp = this->m_pthreadIdTable;
    pthread_mutex_unlock(&mutex);
    return temp;
}

/****************************************************************************************************
* function name: addBindDeclaration.
* The Input: string pthreadName, pthread_t* pthreadId.
* The output: nothing.
* The Function operation: this function add pthreadId to the pthreadIdTable.
****************************************************************************************************/
void VariablesData::addPthreadId(string pthreadName, pthread_t* pthreadId) {
    pthread_mutex_lock(&mutex);
    this->m_pthreadIdTable.emplace(pthreadName, pthreadId);
    pthread_mutex_unlock(&mutex);
}

/****************************************************************************************************
* function name: addBindVariable.
* The Input: string variable, string bindVariable.
* The output: nothing.
* The Function operation: this function add the variable with the variable bind to him.
****************************************************************************************************/
void VariablesData::addBindVariable(string variable, string bindVariable) {
    pthread_mutex_lock(&mutex);
    this->m_bindDeclarationTable.emplace(variable, bindVariable);
    pthread_mutex_unlock(&mutex);
}

/****************************************************************************************************
* function name: getSocketsIdTable.
* The Input: nothing.
* The output: the socketsIdTable.
* The Function operation: this function return the socketsIdTable.
****************************************************************************************************/
unordered_map<string, int> VariablesData::getSocketsIdTable() {
    pthread_mutex_lock(&mutex);
    // create copy of the unordered_map in the mutex so that pthreads will not take at the same time and return it
    unordered_map<string, int> temp = this->m_socketsIdTable;
    pthread_mutex_unlock(&mutex);
    return temp;
}

/****************************************************************************************************
* function name: addSocketId.
* The Input: string sockBelong, int* socketId.
* The output: nothing.
* The Function operation: this function add the socketId to the table.
****************************************************************************************************/
void VariablesData::addSocketId(string sockBelong, int socketId) {
    pthread_mutex_lock(&mutex);
    this->m_socketsIdTable.emplace(sockBelong, socketId);
    pthread_mutex_unlock(&mutex);
}

/****************************************************************************************************
* function name: getIsConnected.
* The Input: nothing.
* The output: true if connected to server, false otherwise.
* The Function operation: this function return true if connected to server, false otherwise.
****************************************************************************************************/
bool VariablesData::getIsConnected() {
    bool temp;
    pthread_mutex_lock(&mutex);
    temp =  this->m_isConnected;
    pthread_mutex_unlock(&mutex);
    return temp;
}

/****************************************************************************************************
* function name: setIsConnected.
* The Input: nothing.
* The output: nothing.
* The Function operation: this function set the m_isConnected.
****************************************************************************************************/
void VariablesData::setIsConnected(bool isConnected) {
    pthread_mutex_lock(&mutex);
    this->m_isConnected = isConnected;
    pthread_mutex_unlock(&mutex);
}

/****************************************************************************************************
* function name: ~VariablesData.
* The Input: nothing.
* The output: nothing.
* The Function operation: the destructor make sure to erase all the things that were put on the
*                         heap.
****************************************************************************************************/
VariablesData::~VariablesData() {
    pthread_mutex_destroy(&mutex);
}