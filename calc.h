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

// TODO Import new classes
using namespace std;

class  calc : public exprBaseVisitor {
public:

  virtual antlrcpp::Any visitFunction(exprParser::FunctionContext *context) override {
		fonctions.push_back(
			new Fonction((std::string) context->ID()->getText(),
			(std::string) context->type()->getText(), visit(context->corps())));

    return NULL;
  }

  virtual antlrcpp::Any visitTypefct(exprParser::TypefctContext *context) override {
    return visit(context->INT());
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
  // TODO modifier
    list<string> ids = (list<string>) visit(context->ids());
    list<Instruction*> instructions;
    for(list<string>::iterator it = ids.begin(); it != ids.end(); it++){
		  Instruction * dec = new Declaration((std::string) (*it)->getText(),(std::string) context->type()->getText());
      instructions.push_back(dec);
    }
		return instructions;
  }

  virtual antlrcpp::Any visitDefinition(exprParser::DefinitionContext *context) override {
    //TODO ; modifier
		Instruction * def = new Definition((Expression *)visit(context->expression()),(LeftValue *)visit(context->left()),(std::string) context->type()->getText());

		return def;
  }

  virtual antlrcpp::Any visitAffectation(exprParser::AffectationContext *context) override {
  	//TODO ; modifier
		Instruction * affS =new AffectationSimple((Expression *)visit(context->expression()),(LeftValue *)visit(context->left()),"");
		
		return affS;
  }

  virtual antlrcpp::Any visitReturn(exprParser::ReturnContext *context) override {
  		Instruction * ret = new Return((Expression *)visit(context->expression()));
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
    list<Instruction*> declarations = visit(context->declare());
    list<Instruction*> instructions;
    for(list<Instruction*>::iterator it = declarations.begin(); it != declarations.end(); it++){
      instructions.push_back((*it));
    }
    instructions.push_back(visit(context->ret()));
    return instructions ;
  }

  virtual antlrcpp::Any visitCorpsAffect(exprParser::CorpsAffectContext *context) override {
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
    list<Instruction*> declarations = visit(context->declare());
    for(list<Instruction*>::iterator it = declarations.begin(); it != declarations.end(); it++){
      instructions.push_back((*it));
    }
    instructions.splice(instructions.end(),visit(context->corps()));
    return instructions;
  }
  
  virtual antlrcpp::Any visitExprMult(exprParser::ExprMultContext *context) override {
    Expression * expr = new ExprMult((Expression *) visit(context->expression(0)), (Expression *)visit(context->expression(1)));
    return expr;
  }
  
  virtual antlrcpp::Any visitExprAdd(exprParser::ExprAddContext *context) override {
    Expression * expr = new ExprAdd((Expression *) visit(context->expression(0)), (Expression *)visit(context->expression(1)));
    return expr;
  }
  
  virtual antlrcpp::Any visitExprMinus(exprParser::ExprMinusContext *context) override {
    Expression * expr = new ExprMoins((Expression *) visit(context->expression(0)), (Expression *)visit(context->expression(1)));
    return expr;
  }
  
  virtual antlrcpp::Any visitExprPar(exprParser::ExprParContext *context) override {
    Expression * expr = new Expr((Expression *) visit(context->expression()));
    return expr;
  }
  
  virtual antlrcpp::Any visitRightValue(exprParser::RightValueContext *context) override {
    return visitChildren((RightValue *)visit(context->right()));
  }
  
  virtual antlrcpp::Any visitSimpleId(exprParser::SimpleIdContext *context) override {
    return visit(context->ID());
  }
  
  virtual antlrcpp::Any visitMultipleId(exprParser::MultipleIdContext *context) override {
    list<string> ids = {visit(context->ID())};
    ids.splice(ids.end(),visit(context->ids()));
    return ids;
  }
  
  list<Fonction*> getFonctions() {
    return fonctions;
  } 
  
protected :
  list<Fonction*> fonctions ;

};





