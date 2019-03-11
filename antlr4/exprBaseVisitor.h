
// Generated from expr.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "exprVisitor.h"


/**
 * This class provides an empty implementation of exprVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  exprBaseVisitor : public exprVisitor {
public:

  virtual antlrcpp::Any visitProg(exprParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypefct(exprParser::TypefctContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNomfct(exprParser::NomfctContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInstruction(exprParser::InstructionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNombre(exprParser::NombreContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRet(exprParser::RetContext *ctx) override {
    return visitChildren(ctx);
  }


};

