// Generated from expr.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "exprBaseVisitor.h"
#include <string.h>
#include <iostream>
#include <fstream>
#include <list>
#include "Fonction.h"
#include "Affectation.h"
#include "AffectationSimple.h"
#include "Declaration.h"
#include "Return.h"
#include "Definition.h"
#include "RightValueId.h"
#include "RightValueNbr.h"

using namespace std;

class  calc : public exprBaseVisitor {
public:

  virtual antlrcpp::Any visitFunction(exprParser::FunctionContext *context) override {
		fonctions.push_back(
			new Fonction((std::string) context->ID()->getText(),
			(std::string) context->type()->getText(), visit(context->corps())));

    return NULL;
  }

  virtual antlrcpp::Any visitTypefct(exprParser::TypefctContext *ctx) override {
    return visit(ctx->INT());
  }

  //il faut rendre le même type pas string une fois et int une fois
  // plutot utiliser le polymorphisme qui permettra également de vérifier s'il 'agit d'un ID Ou d'un NBR
  virtual antlrcpp::Any visitRightValueID(exprParser::RightValueIDContext *context) override {
    RightValue * rvid = new RightValueId((std::string) context->ID()->getText());
    return rvid;
  }

  virtual antlrcpp::Any visitRightValueNBR(exprParser::RightValueNBRContext *context) override {
     RightValue * rvnbr = new RightValueNbr( (int) stoi(context->NBR()->getText()));
     return rvnbr;
  }

  virtual antlrcpp::Any visitLeftValue(exprParser::LeftValueContext *context) override {
    return new LeftValue((std::string) context->ID()->getText());
  }

  virtual antlrcpp::Any visitDeclaration(exprParser::DeclarationContext *context) override {

		Instruction * dec = new Declaration((std::string) context->ID()->getText(),(std::string) context->type()->getText());
		return dec;
  }

  virtual antlrcpp::Any visitDefinition(exprParser::DefinitionContext *context) override {

		Instruction * def = new Definition((RightValue *)visit(context->right()),(LeftValue *)visit(context->left()),(std::string) context->type()->getText());

		return def;
  }

  virtual antlrcpp::Any visitAffectation(exprParser::AffectationContext *context) override {
  		
		Instruction * affS =new AffectationSimple((RightValue *)visit(context->right()),(LeftValue *)visit(context->left()),"");
		
		return affS;
  }

  virtual antlrcpp::Any visitReturn(exprParser::ReturnContext *context) override {

  		Instruction * ret = new Return((RightValue *)visit(context->right()));

		return ret;
  }

  virtual antlrcpp::Any visitCorpsAffectRet(exprParser::CorpsAffectRetContext *context) override {

    list<Instruction*> instructions = { visit(context->affect()) , visit(context->ret())};
    return instructions ;
  }

  virtual antlrcpp::Any visitCorpsRetour(exprParser::CorpsRetourContext *context) override {
	 list<Instruction*> instructions;

	instructions.push_back(visit(context->ret()));
    return instructions ;
  }

  virtual antlrcpp::Any visitCorpsDeclareRet(exprParser::CorpsDeclareRetContext *context) override {
  
    list<Instruction*> instructions = { visit(context->declare()) ,visit(context->ret())};
    return instructions ;
  }

  virtual antlrcpp::Any visitCorpsAffect(exprParser::CorpsAffectContext *context) override {
 	//list<Instruction*> instructions;
	//Affectation * i = dynamic_cast<Affectation*>((Declaration *)visit(context->declare()));
	//instructions.push_back(i);
    //instructions.splice(instructions.end(),visit(context->corps()));

    list<Instruction*> instructions = {visit(context->affect())};
    instructions.splice(instructions.end(),visit(context->corps()));
    return instructions;
  }

  virtual antlrcpp::Any visitCorpsRec(exprParser::CorpsRecContext *context) override {
  //TODO VERIFIER SI CA MARCHE

    return visit(context->corps());
  }

  virtual antlrcpp::Any visitCorpsDeclare(exprParser::CorpsDeclareContext *context) override {
    list<Instruction*> instructions;
	instructions.push_back(visit(context->declare()));
    instructions.splice(instructions.end(),visit(context->corps()));
    return instructions;
  }
  
  /*virtual antlrcpp::Any visitRet(exprParser::RetContext *context) override {
   myfile << "visit ret" << std::endl; 
   //return (int) stoi(ctx->NBR()->getText());
   return NULL;
  }*/
  
  list<Fonction*> getFonctions() {
    return fonctions;
  } 
  
protected :
  list<Fonction*> fonctions ;



};





