
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

  virtual antlrcpp::Any visitFunction(exprParser::FunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypefct(exprParser::TypefctContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRightValueID(exprParser::RightValueIDContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRightValueNBR(exprParser::RightValueNBRContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprPar(exprParser::ExprParContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprAdd(exprParser::ExprAddContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprMinus(exprParser::ExprMinusContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRightValue(exprParser::RightValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprMult(exprParser::ExprMultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLeftValue(exprParser::LeftValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclaration(exprParser::DeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimpleId(exprParser::SimpleIdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMultipleId(exprParser::MultipleIdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefinition(exprParser::DefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAffectation(exprParser::AffectationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReturn(exprParser::ReturnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCorpsAffectRet(exprParser::CorpsAffectRetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCorpsRetour(exprParser::CorpsRetourContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCorpsDeclareRet(exprParser::CorpsDeclareRetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCorpsAffect(exprParser::CorpsAffectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCorpsRec(exprParser::CorpsRecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCorpsDeclare(exprParser::CorpsDeclareContext *ctx) override {
    return visitChildren(ctx);
  }


};

