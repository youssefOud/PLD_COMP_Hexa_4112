#include "AffectationSimple.h"
#include <vector>


std::string AffectationSimple::toString()
{
    return "AffectationSimple Expression "+expr->toString()+" LeftValue "+left->toString()+"\n";
}

int AffectationSimple::getClassName()
{
    return 3;
}

string AffectationSimple::buildIR (CFG* cfg)
{
    string r = expr->buildIR(cfg);
    string l = left->buildIR(cfg);
    vector<string> params;
    params.push_back(l);
    params.push_back(r);
    cfg->addInstruction( IRInstr::Operation::wmem, params);
    cfg->setInitOffset();
    return r;
}

void AffectationSimple::analyse(map<string,vector<int>> & staticAnalysis,list<string> & errors,list<string> & warnings, multimap<string,pair<Type,DefAppel*>> & 	prototypes,bool returnType)
{
    expr->analyse(staticAnalysis,errors,warnings,prototypes,returnType);
    map<string,vector<int>>::iterator it2;
    // traitement de la left value
    it2 = staticAnalysis.find(left->getId());
    if (it2 != staticAnalysis.end())  // elle a déjà été déclarée
    {
        //on notifie qu'elle a été initialisée ou affectée
        (*it2).second[0]=1;
    }
    else
    {
        //var gauche utilisée mais non déclarée
        errors.push_back("Variable utilisee mais non declaree " + (left->getId()));
    }
}
