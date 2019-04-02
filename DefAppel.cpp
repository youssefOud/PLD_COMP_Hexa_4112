#include "DefAppel.h"

DefAppel::DefAppel(unordered_multimap<string,string> par) {
	unordered_multimap<string, string>::iterator it;  
	for (it = par.begin(); it != par.end(); it++) {
		parameters.insert(make_pair(it->first, it->second));	
	}
}

DefAppel::~DefAppel(){

}
	
unordered_multimap<string,string> DefAppel::getParameters(){
	return parameters;
}
 
void DefAppel::setParameters(unordered_multimap<string,string> par){
	parameters.clear();
	unordered_multimap<string, string>::iterator it;  
	for (it = par.begin(); it != par.end(); it++) {
		parameters.insert(make_pair(it->first, it->second));	
	}

}
void DefAppel::addParameter(string name, string type){
	parameters.insert(make_pair(name, type));
}
string DefAppel::toString(){
	string print;
    	print += " Def Appel ";
    	/*print += " \r\n List<Expression*> \r\n ";
	for (list<Expression*>::iterator it = expressions.begin(); it != expressions.end(); it++) {
		print += (*it)->toString()+"\r\n";	
	}

    	print += "\r\n";*/
	return print;
}
	
