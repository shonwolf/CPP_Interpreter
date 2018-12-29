/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#ifndef MYPARAMSSERVER_H
#define MYPARAMSSERVER_H

#include "VariablesData.h"
// define the parameter I want to pass with void*
struct MyParamsServer {
    int port;
    double numberTimesReadInSecond;
    VariablesData* variablesData;
};

#endif
