#ifndef PLD_COMP_DEFAPPEL_H
#define PLD_COMP_DEFAPPEL_H

#include <unordered_map>
#include <string>

using namespace std;

class DefAppel {

public:
	DefAppel() {}
	DefAppel(unordered_multimap<string,string> par);
	~DefAppel();
	
	unordered_multimap<string,string> getParameters(); 
	void setParameters(unordered_multimap<string,string>);
	void addParameter(string type, string name);
	string toString();
	
protected:
	unordered_multimap<string,string> parameters;

private:

};

#endif //PLD_COMP_INSTRUCTION_H
