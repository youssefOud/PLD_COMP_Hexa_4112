# pragma once

#include <vector>
#include <string>
#include <iostream>
#include <initializer_list>

// TODO : A completer

#include "Fonction.h"
#include "Enum.h"

using namespace std;

class BasicBlock;

class IRInstr
{

public:
    typedef enum
    {
        ldconst,
        add,
        sub,
        mul,
        rmem,
        wmem,
        call,
        cmp_eq,
        cmp_lt,
        cmp_le,
        cmp_mt,
        cmp_me,
        cmp_diff,
        neg
    } Operation;

    //  constructor
    IRInstr(BasicBlock* bb_, Operation op, Type t, vector<string> params);

    // Actual code generation
    void genererCodeAssembleur(ostream &o); // x86 assembly code generation for this IR instruction

    string getMemoryOffset(string param);

private:
    BasicBlock* bb; // The BB this instruction belongs to, which provides a pointer to the CFG this instruction belong to
    Operation op;
    Type t;
    vector<string> params;
};
