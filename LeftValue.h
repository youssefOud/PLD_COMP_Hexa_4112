#pragma once

#include <string.h>
#include <iostream>
#include <vector>
#include "CFG.h"


using namespace std;

class LeftValue
{
public:
    LeftValue();
    LeftValue(string id) : id(id) {};
    ~LeftValue() {};
    string toString(){ return "LeftValue "+id+"\n"; }
    string getId(){ return id; };
    void setId(string nom){ id = nom; };
    string buildIR(CFG *cfg);

private:
    string id;
};
