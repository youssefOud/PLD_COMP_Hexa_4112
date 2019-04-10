# pragma once

#include <vector>
#include <string>
#include <iostream>
#include <initializer_list>
#include <map>
#include "Fonction.h"
#include "Enum.h"
#include "IRInstr.h"

using namespace std;

class Instruction;
class BacicBlock;
class CFG
{
public:
    CFG(Fonction* ast, multimap<string,pair<Type,DefAppel *>> *protos, int cmpt);

    Fonction* ast; /**< The AST this CFG comes from */

    void addInstruction (IRInstr::Operation mnemo, vector<string> params);
    void add_bb(BasicBlock* bb);

    void genererCodeAssembleur(ostream& o);
    void gen_asm_prologue(ostream& o);
    void gen_asm_epilogue(ostream& o);

    // symbol table methods
    void add_to_symbol_table(string name, Type t);
    string create_new_tempvar(Type t);
    int get_var_index(string name);
    int get_var_type(string name);
    int getOffsetFromSymbolTable(string id);

    int getNextFreeIndex();

    void genererIR();

    // basic bloc management
    string new_BB_name();
    BasicBlock* current_bb;
    Type getPrototypeType(string label);

    int getNbIf();
    int getNbWhile();
    int getCmptFct();
    void incrementNbIf();
    void incrementNbWhile();

protected:
    map<string,pair<Type, int>> *symbolTable; // The first int in the pair is the type of the variable and the second is its offset
    int nextFreeSymbolIndex; // to allocate new symbols in the symbol table
    int nextBBnumber; // just for naming
    vector <BasicBlock*> bbs; // all the basic blocs of this CFG
    multimap<string,pair<Type,DefAppel *>> *prototypes;
    int maxSizeAR;
    int nbIf; // nombre de "blocs IF" dans le CFG
    int nbWhile; // nombre de "blocs while" dans le CFG
    int cmptFct;
};
