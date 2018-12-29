/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#include "DataReaderServer.h"

/****************************************************************************************************
* function name: openDataServer.
* The Input: void* arg.
* The output: void* type.
* The Function operation: open server to read buffers and return void* type.
****************************************************************************************************/
void* DataReaderServer::openDataServer(void* arg) {
    unordered_map<string, int> allSmallsBindPaths = getAllSmallsBindsPathFromFile();
    struct MyParamsServer* myParams = (struct MyParamsServer*) arg;
    int sockfd, newsockfd, portno, clilen;
    char buffer[1024];
    struct sockaddr_in serv_addr, cli_addr;
    int  n;
    // first call to socket function
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    myParams->variablesData->addSocketId("DataReaderServer", sockfd);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        delete(myParams);
        exit(1);
    }
    // initialize socket structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = myParams->port;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    // now bind the host address using bind() call
    if (bind(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        delete(myParams);
        exit(1);
    }

    /*
     * now start listening for the clients, here process will go in sleep mode and will wait for the incoming
     * connection.
     */
    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    // accept actual connection from the client
    newsockfd = accept(sockfd, (struct sockaddr*)&cli_addr, (socklen_t*)&clilen);
    cout<<newsockfd<<endl;
    if (newsockfd < 0) {
        perror("ERROR on accept");
        delete(myParams);
        exit(1);
    }
    // read data every 10 milliseconds from the simulator until the program will end
    while(true) {
        // if connection is established then start communicating
        bzero(buffer,1024);
        n = read(newsockfd, buffer, 1023);
        if (n < 0) {
            perror("ERROR reading from socket");
            delete (myParams);
            exit(1);
        }
        // the simulator has connected to as and started to get information from him
        myParams->variablesData->setIsConnected(true);
        int size = allSmallsBindPaths.size();
        double smalls[size];
        int bufIndex = 0;
        // put every small in the array of the smalls
        for (int i = 0; i < size; i++) {
            string strNum = "";
            while (buffer[bufIndex] != ',' && buffer[bufIndex] != '\n') {
                strNum += buffer[bufIndex];
                bufIndex++;
            }
            if (strNum == "") {
                continue;
            }
            double num = stod(strNum);
            smalls[i] = num;
            bufIndex++;
        }
        // here we move on all the map of the bind paths that we defined in the program
        for (auto &curBindDeclaration : myParams->variablesData->getBindDeclarationTable()) {
            // here we move on all the map of the smalls bind paths
            for (auto &curSmallBindPath : allSmallsBindPaths) {

                /*
                 * if the bindDeclarationTable contain this bind path than need to change his value to the one we got
                 * from the simulator.
                 */
                if (curBindDeclaration.second == curSmallBindPath.first) {

                    /*
                     * update the symbolTable in the place of the curBindsDeclaration with the small in the index that
                     * the bind path is show in the file.
                     */
                    myParams->variablesData->updateSymbolVal(curBindDeclaration.first,
                                                             smalls[curSmallBindPath.second]);
                }
            }
        }
        for (auto &i : myParams->variablesData->getSymbolTable()) {
            cout << i.first << ":    " << i.second << endl;
        }
    }
}

/****************************************************************************************************
* function name: getAllSmallsBindsPathFromFile.
* The Input: nothing.
* The output: an unordered_map with all the bind's paths from the file "generic_small.xml" and there
*             index the way they are written there.
* The Function operation: this function checks the bind's paths who written in the file and gets
*                         them and written them in an unordered_map with with the index they written
*                         there and the index they are being wrote in.
****************************************************************************************************/
unordered_map<string, int> DataReaderServer::getAllSmallsBindsPathFromFile() {
    unordered_map<string, int> allSmallsBindsPaths = {};
    fstream fs;
    fs.open("generic_small.xml", fstream::in | fstream::out | fstream::app);
    if (fs.fail()) {
        __throw_runtime_error("there was error in opening to the file");
    }
    string line;
    int index = 0;
    // move on all the lines and get the smalls bind's path
    while(getline(fs, line)) {
        // take down the spaces or tabs before the line
        while (line[0] == ' ' || line[0] == '\t') {
            line = line.substr(1, line.length());
        }
        // check if start with "<node>"
        if(line.substr(0, 6) == "<node>") {
            // take from after the "<node>" until the "</node>" in the line - this is the bind's path
            line = line.substr(6, line.length() - 7 - 6);
            allSmallsBindsPaths.emplace(line, index);
            index++;
        }
    }
    fs.close();
    if (fs.is_open()) {
        __throw_runtime_error("there was error in closing to the file");
    }
    return allSmallsBindsPaths;
}