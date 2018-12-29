/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#ifndef DATAREADERSERVER_H
#define DATAREADERSERVER_H

#include <unordered_map>
#include <string>
#include <vector>
#include "VariablesData.h"
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <iostream>
#include "ConnectToServer.h"
#include "MyParamsServer.h"
using namespace std;
class DataReaderServer {
public:
    static void* openDataServer(void* arg);
    static unordered_map<string, int> getAllSmallsBindsPathFromFile();
};

#endif
