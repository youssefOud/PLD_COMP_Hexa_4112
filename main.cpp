#include <iostream>
#include <fstream>
#include <string.h>
#include "antlr4-runtime.h"
#include "exprLexer.h"
#include "exprParser.h"
#include "exprBaseVisitor.h"
#include "calc.h"

using namespace antlr4;
using namespace std;
int main(int argc, const char ** argv) {
  
  bool a,c,o = false;
  for (int i = 1; i<argc ; i++) {
    string s(argv[i]);
    if (!s.compare("-a")) {
        a = true;
    }
    else if (!s.compare("-c")) {
        c = true;
    }
    else if (!s.compare("-o")) {
        o = true;
    }
  }
	
  string nomFichier(argv[argc-1]);
	ifstream myReadFile;
	myReadFile.open(nomFichier);
	string output="";
	string temp;
	if (myReadFile.is_open()) {
		myReadFile >> noskipws;
		while (!myReadFile.eof()) {
				getline(myReadFile,temp);
				output = output + temp;
		}
	}
	myReadFile.close();
	ANTLRInputStream input(output);


	exprLexer lexer(&input);
	CommonTokenStream tokens(&lexer);

	exprParser parser(&tokens);
	tree::ParseTree* tree = parser.function();

	if(parser.getNumberOfSyntaxErrors() == 0){
		calc visitor;
		visitor.visit(tree);
		
		// Une fois l'AST construit, on le parcours pour renseigner la table des symboles
		list<Fonction*> fonctions = (list<Fonction*>)visitor.getFonctions();
		
		//A partir des fonctions que nous avons, nous nous assurons d'abord qu'il existe bien une fonction main ! 
		bool mainFound = false;
		for(list<Fonction*>::iterator it=fonctions.begin() ; it!=fonctions.end() ; ++it){
			if((*it)->getId() == "main"){
				mainFound = true;
			}
		}
		if(mainFound){
			for(list<Fonction*>::iterator it=fonctions.begin() ; it!=fonctions.end() ; ++it) 
			{
			  (*it)->generateST();
			  (*it)->generateSA();
			  (*it)->processSA();
			  if (a) {
				  // Générer que si argument passé en option
				  (*it)->displaySymbolTable();
				  cout << endl;
				  (*it)->displayStaticAnalysis();
				  cout << endl;
				  (*it)->displayWarnings();
				  cout << endl;
				  (*it)->displayErrors();
			  }
			  
			  if (c && ((*it)->getNumberOfErrors()==0)) 
			  {
		  	  // Générer que si argument passé en option
			    nomFichier.replace(nomFichier.length()-2, 3,".s");
			    nomFichier.replace(0, 11,"");
			    ofstream myfile("./executables/"+nomFichier);
			    myfile << (*it)->genererCodeAssembleur() << endl;
			    myfile.close();
			  }else
			  {
			    cerr << "Erreur ! Le fichier assembleur n'a pas été généré !" <<endl;
			  }
			}
		}else{
			cerr << "Erreur ! Aucune fonction main n'a été trouvé!" <<endl;
		}
	}
	return 0;
}
