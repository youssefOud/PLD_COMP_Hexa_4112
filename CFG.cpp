#include "CFG.h"
#include "BasicBlock.h"
#include "Instruction.h"

CFG::CFG(Fonction* f, multimap<string,pair<Type,DefAppel *>> *protos, int cmpt)
{
    ast = f;
    symbolTable = f->getST();
    nextFreeInit = nextFree;
    maxNextFree = nextFree;
    prototypes = protos;
    current_bb = new BasicBlock(this, "." + f->getId());
    add_bb(current_bb);
    nbIf = 0;
    nbWhile = 0;
    cmptFct = cmpt;
}

void CFG::genererIR()
{
    for(list<Instruction*>::iterator it = ast->getInstructions()->begin(); it != ast->getInstructions()->end(); it++){
	(*it)->buildIR(this);
    }
}

void CFG::add_bb(BasicBlock* bb)
{
    bbs.push_back(bb);
}

void CFG::genererCodeAssembleur(ostream& o)
{
    gen_asm_prologue(o);
    for(vector <BasicBlock*>::iterator it = this->bbs.begin(); it != this->bbs.end(); it++)
    {
        (*it)->genererCodeAssembleur(o);
    }
    gen_asm_epilogue(o);
}

void CFG::gen_asm_prologue(ostream& o)
{
    // Calcule la taille nécessaire pour l'AR
    maxSizeAR = - (maxNextFree+8);
    if(maxSizeAR % 16 !=0)
    {
        maxSizeAR += 8;
    }

    o << ast->getId() << ": \r\n";
    o << "# prologue \r\n";
    o << "pushq %rbp # save %rbp on the stack \r\n";
    o << "movq %rsp, %rbp # define %rbp for the current function \r\n";
    o << "subq $" << to_string(maxSizeAR) << ", %rsp\r\n";
    //On copie les variables passées en paramètre dans leurs cases mémoire
    int cmpt = 1;
    for (unordered_multimap<string,string>::iterator itParam = ast->getDefAppel()->getParameters()->begin(); itParam != ast->getDefAppel()->getParameters()->end(); itParam++){    
		switch (cmpt){
			case 1:{
				o << "movq %rdi, %rax\r\n";
				break;
			}
			case 2:{
				o << "movq %rsi, %rax\r\n";
				break;
			}
			case 3:{
				o << "movq %rdx, %rax\r\n";
				break;
			}
			case 4:{
				o << "movq %rcx, %rax\r\n";
				break;
			}
			case 5:{
				o << "movq %r8, %rax\r\n";
				break;
			}
			case 6:{
				o << "movq %r9, %rax\r\n";
				break;
			}
		}
		int memoryCase = getOffsetFromSymbolTable((*itParam).first);
		o << "movq %rax, " << to_string(memoryCase) << "(%rbp)\r\n";
		cmpt++;
	}
    o << "\r\n";
    o << "# body \r\n";
}

void CFG::gen_asm_epilogue(ostream& o)
{
    o << ".epilogue" << to_string(cmptFct) <<":\r\n";
    o << "# epilogue \r\n";
    o << "leave # restore %rbp from the stack \r\n";
    o << "ret # return to the caller (here the shell) \r\n";
    o << "\r\n";
}

void CFG::add_to_symbol_table(string name, Type t)
{
    symbolTable->insert( make_pair(name, make_pair(t, nextFree) ));
    nextFree -=8;
}

string CFG::create_new_tempvar(Type t)
{
    string newVarName = "!temp" + to_string(nextFree);
    add_to_symbol_table(newVarName, t);
    return newVarName;
}

int CFG::get_var_index(string name)
{
    return symbolTable->find(name)->second.second;
}

int CFG::get_var_type(string name)
{
    return symbolTable->find(name)->second.first;
}

void CFG::addInstruction (IRInstr::Operation mnemo, vector<string> params)
{
    current_bb->add_IRInstr(mnemo, symbolTable->find(params[0])->second.first, params);
}


void CFG::setInitOffset(){
	//save the maximum memory offset for the function
	if(nextFree > maxNextFree){
		maxNextFree = nextFree;
	}
	nextFree = nextFreeInit;
}

int CFG::getOffsetFromSymbolTable(string id)
{
    map<string,pair<Type, int>>::iterator  it= symbolTable->find(id);
    if( it != symbolTable->end() )
    {
        return symbolTable->find(id)->second.second;
    }
    else
    {
        return 0; // 0 signifie que aucune variable de ce nom n'a été trouvée
    }
}

Type CFG::getPrototypeType(string label)
{
    return prototypes->find(label)->second.first;
}

int CFG::getNbIf()
{
    return nbIf;
}

int CFG::getNbWhile()
{
    return nbWhile;
}

int CFG::getCmptFct()
{
    return cmptFct;
}

void CFG::incrementNbIf()
{
    nbIf++;
}
void CFG::incrementNbWhile()
{
    nbWhile++;
}
