// Generated from expr.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "exprBaseVisitor.h"
#include <string.h>
#include <iostream>
#include <fstream>


/**
 * This class provides an empty implementation of exprVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
/*
class  Compilateur : public exprBaseVisitor {
public:

  virtual antlrcpp::Any visitProg(exprParser::ProgContext *ctx) override {
	return (int) visit(ctx->prog());
	}

  virtual antlrcpp::Any visitT(exprParser::TContext *ctx) override {
    return (int) visit(ctx->t());
  }

  virtual antlrcpp::Any visitF(exprParser::FContext *ctx) override {
    return (int) visit(ctx->f());
  }

  virtual antlrcpp::Any visitE(exprParser::EContext *ctx) override {
    return (int) visit(ctx->e());
  }

  virtual antlrcpp::Any visitP(exprParser::PContext *ctx) override {
    return (int) visit(ctx->p());
  }

  virtual antlrcpp::Any visitR(exprParser::RContext *ctx) override {
    return visitChildren(ctx);
  }


};*/

class  Compilateur : public exprBaseVisitor {
public:

  std::ofstream myfile;

  virtual antlrcpp::Any visitProg(exprParser::ProgContext *ctx) override {
    myfile.open("main.s");

    myfile << ".text" << std::endl;
    myfile << ".global main" << std::endl;
    myfile << "main:" << std::endl;
	
    return visit(ctx->pr());
    //return NULL;
  }

  virtual antlrcpp::Any visitTypefct(exprParser::TypefctContext *ctx) override {
    myfile << "visit Typefct" << std::endl;
    return visit(ctx->INT());
    //return NULL;
  }

  virtual antlrcpp::Any visitNomfct(exprParser::NomfctContext *ctx) override {
    myfile << "visit Nomfct" << std::endl;
    return (std::string) ctx->ID()->getText();
    //return NULL;
  }

  virtual antlrcpp::Any visitInstruction(exprParser::InstructionContext *ctx) override {
    myfile << "	movl $"; 
    return visit(ctx->expr());
    //return NULL;
  }

  virtual antlrcpp::Any visitNombre(exprParser::NombreContext *ctx) override {
    myfile << stoi(ctx->NBR()->getText()) << ", \%eax" << std::endl << "	ret" << std::endl;
    //return (int) stoi(ctx->NBR()->getText());
    return NULL;
  }

  virtual antlrcpp::Any visitRet(exprParser::RetContext *context) override {
    myfile << "visit ret" << std::endl; 
    //return (int) stoi(ctx->NBR()->getText());
    return NULL;
  }



};





