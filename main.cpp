#ifdef DEBUG_ENABLE
    #define debug(debugString) std::cout << (debugString) << std::endl;
#else
    #define debug(debugString)
#endif

#include <iostream>
#include <fstream>
#include <string.h>
#include <utility>
#include <map>
#include "antlr4-runtime.h"
#include "exprLexer.h"
#include "exprParser.h"
#include "exprBaseVisitor.h"
#include "calc.h"
#include "DefAppel.h"

using namespace antlr4;
using namespace std;

void gen_asm_prologue_general(ostream& o) {
	o << ".text                       # section declaration\r\n";
	o << ".global main                # entry point\r\n";
	o << "\r\n";
}

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
	tree::ParseTree* tree = parser.fichier();

	

	if(parser.getNumberOfSyntaxErrors() == 0){

		calc visitor;
		visitor.visit(tree);
		
		// Une fois l'AST construit, on le parcours pour renseigner la table des symboles
		list<Fonction*> fonctions = (list<Fonction*>)visitor.getFonctions();
		multimap<string,pair<Type,DefAppel *>> prototypes;
		//A partir des fonctions que nous avons, nous nous assurons d'abord qu'il existe bien une fonction MAIN et qu'il n'y a pas d'erreur dans les fonctions ! 
		int numberOfMains = 0;
		int numberOfErrors = 0;
		for(list<Fonction*>::iterator it=fonctions.begin() ; it!=fonctions.end(); ++it){
			prototypes.insert(make_pair((*it)->getId(),make_pair((*it)->getType(),(*it)->getDefAppel())));
			if((*it)->getId() == "main"){
				numberOfMains++;
			}
			numberOfErrors += (*it)->getNumberOfErrors();
		}
		//On vérifie qu'il ny a pas eu de définitions multiples d'une fonction
		set<string> fctRedef;
		for(auto it=prototypes.begin() ; it!=prototypes.end()  ; ++it){
			if(prototypes.count(it->first)>1){
				fctRedef.insert(it->first);
			}
		}

		if(fctRedef.size() == 0 && numberOfMains == 1){
				
				ofstream myfile;
				//On vérifie si l'option -c est activée et qu'il n'y a pas d'erreur afin de générer le fichier .s
				if (c && numberOfErrors == 0) {
					nomFichier.replace(nomFichier.length()-2, 3,".s");
				    	myfile.open(nomFichier);
					gen_asm_prologue_general(myfile);			
				}
	      			else if (c && numberOfErrors>0){			
					cerr << "Erreur ! Le fichier assembleur n'a pas été généré !" <<endl;
				}
			
				//On rajoute les fonctions de la librairie C que l'on souhaite gérer à nos prototypes 
				unordered_multimap<string,string> par;

				//Fonction putchar
				par.insert({"char","int"});
				prototypes.insert(make_pair("putchar",make_pair(INT,new DefAppel(par))));

				//Fonction getchar
				prototypes.insert(make_pair("getchar",make_pair(INT,new DefAppel())));


				for(list<Fonction*>::iterator it=fonctions.begin() ; it!=fonctions.end() ; ++it) 
				{
					  debug((*it)->toString());
				  	  (*it)->generateST();
					  CFG * cfg = new CFG((*it), &prototypes);
					  for(list<Instruction*>::iterator it2 = (*it)->getInstructions()->begin(); it2 != (*it)->getInstructions()->end(); it2++){
						  ( *it2)->buildIR(cfg);
					  }
					  (*it)->generateSA(prototypes);
					  (*it)->processSA();

					  if (a) {
					    // Générer que si argument passé en option
					    (*it)->displaySymbolTable();
					    //cout << endl;
					    (*it)->displayStaticAnalysis();
					    //cout << endl;
					    (*it)->displayWarnings();
					    //cout << endl;
					    (*it)->displayErrors();
					  }
				  
					  if (c && numberOfErrors==0) 
					  {
					    cfg->genererCodeAssembleur(myfile); 
					  } 
				}
				myfile.close();			
			}
			else {

				if(numberOfMains ==0){
					cerr << "Erreur ! Aucune fonction main n'a été trouvé !" <<endl;
				}
				else if(numberOfMains > 1){
					cerr << "Erreur ! Plusieurs fonctions main ont été trouvé !" <<endl;
				}
		    
				if(fctRedef.size()!=0){
				cerr << "Erreur ! Multiples définitions des fonctions " ;
				for(auto it=fctRedef.begin() ; it!=fctRedef.end()  ; ++it){
						cerr<<*it<<" ";
				}
				cerr << "!"<<endl;
			}
		}
	}
	else{
		cerr << "Erreur ! L'arbre est mal formé, il ne pourra pas être visité." <<endl;
	}
	
	return 0;
}
