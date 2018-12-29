/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#include "ConnectToServer.h"
#include <iostream>

/****************************************************************************************************
* function name: connectServer.
* The Input: string ipAddress, int port,  VariablesData* variablesData.
* The output: nothing.
* The Function operation: this function connect to server.
****************************************************************************************************/
void ConnectToServer::connectServer(string ipAddress, int port,  VariablesData* variablesData) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    // wait in a loop until the simulator has connected to as
    while (!variablesData->getIsConnected()) {}
    // get the port to work on
    portno = port;
    // create a socket point
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    variablesData->addSocketId("ConnectToServer", sockfd);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    char ip[ipAddress.length() + 1];
    int index = 0;
    // take the ip as char*
    while(ipAddress[0] != '\0') {
        ip[index] = ipAddress[0];
        ipAddress = ipAddress.substr(1, ipAddress.length());
        index++;
    }
    ip[index] = '\0';
    server = gethostbyname(ip);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char*) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char*)server->h_addr, (char*)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    // now connect to the server
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }
}

/****************************************************************************************************
* function name: writeToSimulator.
* The Input: string message, int sockfd.
* The output: nothing.
* The Function operation: this function write message to the simulator.
****************************************************************************************************/
void ConnectToServer::writeToSimulator(string message, int sockfd) {
    char buffer[1024];
    bzero(buffer, 1024);
    int index = 0;
    // take the message as char[]
    while(message[0] != '\0') {
        buffer[index] = message[0];
        message = message.substr(1, message.length());
        index++;
    }
    strcat(buffer, "\r\n");
    // send message to the server
    int n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
    // now read server response
    bzero(buffer, 1024);
    n = read(sockfd, buffer, 1023);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
}
