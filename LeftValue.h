#include <string.h>
#include <iostream>

using namespace std;

class LeftValue {
	public:
		LeftValue();
		LeftValue(string id) : id(id) {};
		~LeftValue() {};
		string toString() { return "LeftValue "+id+"\n";}
		string getId() { return id; };
		void setId(string nom) { id = nom; };

	private:
		string id;
};
