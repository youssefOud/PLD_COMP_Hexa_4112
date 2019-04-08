#include "Declaration.h"

Declaration::Declaration(std::string nomVar, std::string varType)
{
    	id = nomVar;
	type = convertTypeToInt(varType);
}

Declaration::~Declaration()
{

}

void Declaration::setId(std::string nV)
{
    id = nV;
}
std::string Declaration::getId()
{
    return id;
}

void Declaration::setType(Type t)
{
    type = t;
}

Type Declaration::getType()
{
    return type;
}

std::string Declaration::stringifyType() {
  
    std::string print = "UNKNOWN";
    
    switch(this->type) {
      case INT :
        print = "INT";
        break;
      case VIDE :
        print = "VOID";
        break;
	case CHAR :
        print = "CHAR";
        break;
    }
  
    return print;
}

std::string Declaration::toSmallString() 
{
    std::string print;
    print += id;
    print += " ("+stringifyType()+")";
    return print;
}

std::string Declaration::toString() 
{
    std::string print;
    print += " Declaration id "+id;
    print += " type ("+stringifyType()+")";
    print += "\r\n";
    
    return print;
}

Type Declaration::convertTypeToInt(string nom) {
	Type t = Type::VIDE;
	if (nom == "") t = Type::VIDE;
	else if (nom == "int") t = Type::INT;
	return t; 
}

int Declaration::getClassName(){
	return 1;
}


// TODO : A verifier
string Declaration::buildIR(CFG *cfg) {
	return "25";
}

void Declaration::analyse(map<string,vector<int>> & staticAnalysis,list<string> & errors,list<string> & warnings, multimap<string,pair<Type,DefAppel*>> & prototypes,bool returnType) {
	map<string,vector<int>>::iterator it2;
			it2 = staticAnalysis.find(id);
			if (it2 == staticAnalysis.end()) {	
				//déclaration d'une nouvelle variable
				vector<int> flags(2, 0);
				staticAnalysis.insert(make_pair(id,flags ));
				//ATTENTION LES DECLARATIONS MULTIPLES SONT GEREES DU COTE DE LA ST
			}

}
