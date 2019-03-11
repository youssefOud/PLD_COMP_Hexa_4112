
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

  virtual antlrcpp::Any visitProggeneral(exprParser::ProggeneralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypevar(exprParser::TypevarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNom(exprParser::NomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCodefonction(exprParser::CodefonctionContext *ctx) override {
    return visitChildren(ctx);
  }


};

