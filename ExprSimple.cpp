#include "ExprSimple.h"

using namespace std;

string ExprSimple::toString ()
{
    return "Right Value " + right->toString();
}

int ExprSimple::eval()
{
    return right->getNbr();
}

void ExprSimple::analyse(map<string,vector<int>> & staticAnalysis,list<string> & errors,list<string> & warnings, multimap<string,pair<Type,DefAppel*>> & prototypes, bool returnType)
{

    map<string,vector<int>>::iterator it2;
    if(right->getId() != "")// c'est une variable
    {
        it2 = staticAnalysis.find(right->getId());
        if (it2 != staticAnalysis.end())
        {
            // on vérifie qu'elle a bien été initialisée
            if((*it2).second[0]==1)
            {
                // on met à jour la ligne de la variable en disant qu'elle est utilisée
                (*it2).second[1]=1;

            }
            else
            {
                warnings.push_back("Variable utilisee mais non initialisee " +right->getId());
            }
        }
        else
        {
            errors.push_back("Variable utilisee mais non declaree " + right->getId());
        }
    }

}

string ExprSimple::buildIR (CFG* cfg)
{
    if(!right->getId().empty())
    {
        return right->getId();
    }
    else
    {
        string var = cfg->create_new_tempvar(Type::INT);
        vector<string> params;
        params.push_back(var);
        params.push_back(to_string(right->getNbr()));
        cfg->addInstruction(IRInstr::Operation::ldconst, params);
        return var;
    }
}

bool ExprSimple::estCst(list<string> & opti)
{
    return right->estCst(opti);
}


