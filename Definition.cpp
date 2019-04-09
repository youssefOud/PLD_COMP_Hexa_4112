#include "Definition.h"
#include <string>
#include <vector>


std::string Definition::toString() 
{
    return "Definition Expression "+expr->toString()+" LeftValue "+left->toString()+ " Type "+to_string(type)+"\n";
}


int Definition::getClassName(){
	return 2;
}

string Definition::buildIR (CFG* cfg){
	string r = expr->buildIR(cfg);
	string l = left->buildIR(cfg);
	vector<string> params;
	params.push_back(l);
	params.push_back(r);
	cfg->addInstruction( IRInstr::Operation::wmem, params);
	return r;
}

void Definition::analyse(map<string,vector<int>> & staticAnalysis,list<string> & errors,list<string> & warnings, multimap<string,pair<Type,DefAppel*>> & prototypes,bool returnType) {
			map<string,vector<int>>::iterator it2;
			expr->analyse(staticAnalysis,errors,warnings,prototypes,returnType);
			// traitement de la left value quel que soit le retour de la partie droite
			it2 = staticAnalysis.find(left->getId());
			if (it2 == staticAnalysis.end()) {// elle n'a jamais été déclarée
				//on notifie qu'elle a été déclarée et initialisée
				vector<int> flags{1,0};
				staticAnalysis.insert(make_pair(left->getId(),flags ));
			}
			//ATTENTION LES DECLARATIONS MULTIPLES SONT GEREES PAR LA ST	

}
