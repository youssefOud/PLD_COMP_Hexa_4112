// Generated from expr.g4 by ANTLR 4.7.1
#ifdef DEBUG_ENABLE
    #define debug(debugString) std::cout << (debugString) << std::endl;
#else
    #define debug(debugString)
#endif

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
#include "RightValueChar.h"
#include "ExprMult.h"
#include "ExprPlus.h"
#include "ExprMoins.h"
#include "Expression.h"
#include "ExprSimple.h"
#include "ExprNeg.h"
#include "Appel.h"
#include <unordered_map> 
#include <utility> 

// TODO Import new classes
using namespace std;

class  calc : public exprBaseVisitor {
public:

	virtual antlrcpp::Any visitFichier(exprParser::FichierContext *ctx) override {
    return visit(ctx->programme());
  }

   virtual antlrcpp::Any visitFctUnique(exprParser::FctUniqueContext *ctx) override {

	fonctions.push_back(visit(ctx->function()));
	return NULL;
  }

  virtual antlrcpp::Any visitFctMult(exprParser::FctMultContext *ctx) override {

	fonctions.push_back(visit(ctx->function()));
	visit(ctx->programme());
	return NULL;
  }

//TODO QUELLE CLASSE METTRE
  virtual antlrcpp::Any visitAppelFuncSansParam(exprParser::AppelFuncSansParamContext *ctx) override {
    Instruction * appel = new Appel((string) ctx->ID()->getText());
	return appel;
  }
//TODO QUELLE CLASSE METTRE
  virtual antlrcpp::Any visitAppelFuncAvecParam(exprParser::AppelFuncAvecParamContext *ctx) override {
    Instruction * appel = new Appel((string) ctx->ID()->getText(),visit(ctx->vars()));
	return appel;
  }

  virtual antlrcpp::Any visitParamUnique(exprParser::ParamUniqueContext *ctx) override {
  	list<Instruction *> expressions;
  	expressions.push_back(visit(ctx->expression()));
    return expressions;
  }

  virtual antlrcpp::Any visitParamMult(exprParser::ParamMultContext *ctx) override {
    list<Instruction *> expressions = {visit(ctx->expression())};
    expressions.splice(expressions.end(),visit(ctx->vars()));
    return expressions;
  }

  virtual antlrcpp::Any visitFct(exprParser::FctContext *ctx) override {

		DefAppel * defAppel=new DefAppel();
		defAppel->setParameters(visit(ctx->defAppel()));
    return new Fonction((string) ctx->ID()->getText(),
			(string) ctx->typefct()->getText(), visit(ctx->corps()),defAppel);
  }
  
  virtual antlrcpp::Any visitFctSansParam(exprParser::FctSansParamContext *ctx) override {

    return new Fonction((string) ctx->ID()->getText(),
			(string) ctx->typefct()->getText(), visit(ctx->corps()),new DefAppel());
  }

  virtual antlrcpp::Any visitDefParamUnique(exprParser::DefParamUniqueContext *ctx) override {
  	unordered_multimap<string, string> params; 
    params.insert(std::make_pair((string) ctx->ID()->getText(), (string) ctx->type()->getText())); 
    return params;
  }

  virtual antlrcpp::Any visitDefParamMult(exprParser::DefParamMultContext *ctx) override {
    unordered_multimap<string, string> params ;
    params.insert(std::make_pair((string) ctx->ID()->getText(), (string) ctx->type()->getText()));  
    unordered_multimap<string, string> paramsRetour = visit(ctx->defAppel());
    params.insert(paramsRetour.begin(),paramsRetour.end());
    return params;
  }

  virtual antlrcpp::Any visitRetourInt(exprParser::RetourIntContext *ctx) override {
    return visit(ctx->INT());
  }

  virtual antlrcpp::Any visitRetourVoid(exprParser::RetourVoidContext *ctx) override {
    return visit(ctx->VOID());
  }

  virtual antlrcpp::Any visitTypeVarChar(exprParser::TypeVarCharContext *ctx) override {
     return visit(ctx->CHAR());
  }
  
  virtual antlrcpp::Any visitTypeVarInt(exprParser::TypeVarIntContext *ctx) override {
     return visit(ctx->INT());
  }

   virtual antlrcpp::Any visitRightValueID(exprParser::RightValueIDContext *context) override {
    RightValue * rvid = new RightValueId((string) context->ID()->getText());
    return rvid;
  }

  virtual antlrcpp::Any visitRightValueNBR(exprParser::RightValueNBRContext *context) override {
     RightValue * rvnbr = new RightValueNbr( (int) stoi(context->NBR()->getText()));
     return rvnbr;
  }

	virtual antlrcpp::Any visitRightValueCHAR(exprParser::RightValueCHARContext *context) override {
     RightValue * rvchar = new RightValueChar( (context->CARACTERE()->getText()).at(1));
     return rvchar;
  }

  virtual antlrcpp::Any visitLeftValue(exprParser::LeftValueContext *context) override {
    return new LeftValue((string) context->ID()->getText());
  }

  /*virtual antlrcpp::Any visitExprNeg(exprParser::ExprNegContext *ctx) override {
    Instruction * expr = new ExprNeg((Instruction *) visit(ctx->expression()));
    return expr;
  }*/
  
  virtual antlrcpp::Any visitExprApp(exprParser::ExprAppContext *ctx) override {
    return visit(ctx->appel());
  }
  

	virtual antlrcpp::Any visitExprAddMinus(exprParser::ExprAddMinusContext *ctx) override {
		Instruction * expr;
		//debug ((string) ctx->op());
		if( ctx->op->getText() == "+"){
			 expr = new ExprPlus((Instruction *) visit(ctx->expression(0)), (Instruction *)visit(ctx->expression(1)));
		}
		else {
			expr = new ExprMoins((Instruction *) visit(ctx->expression(0)), (Instruction *)visit(ctx->expression(1)));
		}
    
    return expr;
  }
 
  virtual antlrcpp::Any visitExprPar(exprParser::ExprParContext *context) override {
    return visit(context->expression());
  }
  
  virtual antlrcpp::Any visitRightValue(exprParser::RightValueContext *context) override {
    Instruction * expr = new ExprSimple((RightValue *)visit(context->right()));
    return expr;
  }

  virtual antlrcpp::Any visitExprMult(exprParser::ExprMultContext *context) override {
    Instruction * expr = new ExprMult((Instruction *) visit(context->expression(0)), (Instruction *)visit(context->expression(1)));
    return expr;
  }


  virtual antlrcpp::Any visitSimpleId(exprParser::SimpleIdContext *context) override {
	list<string> id;
	id.push_back((string) context->ID()->getText());
    return id;
  }
  
  virtual antlrcpp::Any visitMultipleId(exprParser::MultipleIdContext *context) override {
    list<string> ids = {(string) context->ID()->getText()};
    ids.splice(ids.end(),visit(context->ids()));
    return ids;
  }

  virtual antlrcpp::Any visitDeclaration(exprParser::DeclarationContext *context) override {
  // TODO modifier
    list<string> ids = visit(context->ids());
    list<Instruction*> instructions;
    for(list<string>::iterator it = ids.begin(); it != ids.end(); it++){
		  Instruction * dec = new Declaration((*it),(string) context->type()->getText());
      instructions.push_back(dec);
    }
		return instructions;
  }

  virtual antlrcpp::Any visitDefinition(exprParser::DefinitionContext *context) override {
		Instruction * def = new Definition((Instruction *)visit(context->expression()),(LeftValue *)visit(context->left()),(string) context->type()->getText());
		return def;
  }

  virtual antlrcpp::Any visitAffectation(exprParser::AffectationContext *context) override {
		Instruction * affS =new AffectationSimple((Instruction *)visit(context->expression()),(LeftValue *)visit(context->left()),"");
		return affS;
  }

  virtual antlrcpp::Any visitReturn(exprParser::ReturnContext *context) override {
  		Instruction * ret = new Return((Instruction *)visit(context->expression()));
		return ret;
  }

  virtual antlrcpp::Any visitInstrAff(exprParser::InstrAffContext *ctx) override {
   list<Instruction*> instructions = {visit(ctx->affect())};
    return instructions;
  }

  virtual antlrcpp::Any visitInstrDec(exprParser::InstrDecContext *ctx) override {
   list<Instruction*> instructions = visit(ctx->declare());
    return instructions;
  }

  virtual antlrcpp::Any visitInstrExpr(exprParser::InstrExprContext *ctx) override {
  	list<Instruction*> instructions = {visit(ctx->expression())};
    return instructions;
  }

  virtual antlrcpp::Any visitInstr(exprParser::InstrContext *ctx) override {
  	list<Instruction*> instructions = visit(ctx->instruction());
    return instructions;
  }

  virtual antlrcpp::Any visitInstrCorps(exprParser::InstrCorpsContext *ctx) override {
    list<Instruction*> instructions = visit(ctx->instruction());
    instructions.splice(instructions.end(),visit(ctx->corps()));
    return instructions;
  }

  virtual antlrcpp::Any visitInstrRet(exprParser::InstrRetContext *ctx) override {
    list<Instruction*> instructions = {visit(ctx->ret())};
    return instructions;
  }
  
  list<Fonction*> getFonctions() {
    return fonctions;
  } 
  
protected :
  list<Fonction*> fonctions ;

};
