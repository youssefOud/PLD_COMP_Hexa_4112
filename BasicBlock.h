# pragma once

#include <vector>
#include <string>

#include <iostream>
#include <initializer_list>

// Declarations from the parser -- replace with your own
#include "Enum.h"
#include "IRInstr.h"

#include "CFG.h"


using namespace std;

/**  The class for a basic block */

class BasicBlock
{
public:
    BasicBlock(CFG* cfg, string entry_label);
    void genererCodeAssembleur(ostream &o); /**< x86 assembly code generation for this basic block */

    void add_IRInstr(IRInstr::Operation op, Type t, vector<string> params);

    BasicBlock* exit_true;  // pointer to the next basic block, true branch. If nullptr, return from procedure
    BasicBlock* exit_false; // pointer to the next basic block, false branch. If null_ptr, the basic block ends with an unconditional jump
    string label; // label of the BB, also will be the label in the generated code
    CFG* cfg; // the CFG where this block belongs
    vector<IRInstr*> instrs; // the instructions themselves.
    string varTest;
protected:


};
