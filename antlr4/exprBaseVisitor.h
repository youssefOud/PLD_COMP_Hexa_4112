
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

  virtual antlrcpp::Any visitFichier(exprParser::FichierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFctMult(exprParser::FctMultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFctUnique(exprParser::FctUniqueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAppelFuncSansParam(exprParser::AppelFuncSansParamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAppelFuncAvecParam(exprParser::AppelFuncAvecParamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParamUnique(exprParser::ParamUniqueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParamMult(exprParser::ParamMultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFct(exprParser::FctContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFctSansParam(exprParser::FctSansParamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefParamUnique(exprParser::DefParamUniqueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefParamMult(exprParser::DefParamMultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRetourInt(exprParser::RetourIntContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRetourVoid(exprParser::RetourVoidContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRetourChar(exprParser::RetourCharContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeVarInt(exprParser::TypeVarIntContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeVarChar(exprParser::TypeVarCharContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRightValueID(exprParser::RightValueIDContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRightValueNBR(exprParser::RightValueNBRContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRightValueCHAR(exprParser::RightValueCHARContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprNeg(exprParser::ExprNegContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprComp(exprParser::ExprCompContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprPar(exprParser::ExprParContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprApp(exprParser::ExprAppContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRightValue(exprParser::RightValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprAddMinus(exprParser::ExprAddMinusContext *ctx) override {
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

  virtual antlrcpp::Any visitIfInstr(exprParser::IfInstrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhileInstr(exprParser::WhileInstrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInstrAff(exprParser::InstrAffContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInstrDec(exprParser::InstrDecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInstrExpr(exprParser::InstrExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInstrRet(exprParser::InstrRetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInstr(exprParser::InstrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInstrCorps(exprParser::InstrCorpsContext *ctx) override {
    return visitChildren(ctx);
  }


};

