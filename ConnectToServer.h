/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#ifndef CONNECTTOSERVER_H
#define CONNECTTOSERVER_H

#include <string>
#include "VariablesData.h"
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
using namespace std;
class ConnectToServer {
public:
    void connectServer(string ipAddress, int port,  VariablesData* variablesData);
    void writeToSimulator(string message, int sockfd);
};

#endif
