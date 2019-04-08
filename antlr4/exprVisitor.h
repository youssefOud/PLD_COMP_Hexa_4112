
// Generated from expr.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "exprParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by exprParser.
 */
class  exprVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by exprParser.
   */
    virtual antlrcpp::Any visitFichier(exprParser::FichierContext *context) = 0;

    virtual antlrcpp::Any visitFctMult(exprParser::FctMultContext *context) = 0;

    virtual antlrcpp::Any visitFctUnique(exprParser::FctUniqueContext *context) = 0;

    virtual antlrcpp::Any visitAppelFuncSansParam(exprParser::AppelFuncSansParamContext *context) = 0;

    virtual antlrcpp::Any visitAppelFuncAvecParam(exprParser::AppelFuncAvecParamContext *context) = 0;

    virtual antlrcpp::Any visitParamUnique(exprParser::ParamUniqueContext *context) = 0;

    virtual antlrcpp::Any visitParamMult(exprParser::ParamMultContext *context) = 0;

    virtual antlrcpp::Any visitFct(exprParser::FctContext *context) = 0;

    virtual antlrcpp::Any visitFctSansParam(exprParser::FctSansParamContext *context) = 0;

    virtual antlrcpp::Any visitDefParamUnique(exprParser::DefParamUniqueContext *context) = 0;

    virtual antlrcpp::Any visitDefParamMult(exprParser::DefParamMultContext *context) = 0;

    virtual antlrcpp::Any visitRetourInt(exprParser::RetourIntContext *context) = 0;

    virtual antlrcpp::Any visitRetourVoid(exprParser::RetourVoidContext *context) = 0;

    virtual antlrcpp::Any visitTypeVarInt(exprParser::TypeVarIntContext *context) = 0;

    virtual antlrcpp::Any visitTypeVarChar(exprParser::TypeVarCharContext *context) = 0;

    virtual antlrcpp::Any visitRightValueID(exprParser::RightValueIDContext *context) = 0;

    virtual antlrcpp::Any visitRightValueNBR(exprParser::RightValueNBRContext *context) = 0;

    virtual antlrcpp::Any visitRightValueCHAR(exprParser::RightValueCHARContext *context) = 0;

    virtual antlrcpp::Any visitExprNeg(exprParser::ExprNegContext *context) = 0;

    virtual antlrcpp::Any visitExprPar(exprParser::ExprParContext *context) = 0;

    virtual antlrcpp::Any visitExprApp(exprParser::ExprAppContext *context) = 0;

    virtual antlrcpp::Any visitRightValue(exprParser::RightValueContext *context) = 0;

    virtual antlrcpp::Any visitExprAddMinus(exprParser::ExprAddMinusContext *context) = 0;

    virtual antlrcpp::Any visitExprMult(exprParser::ExprMultContext *context) = 0;

    virtual antlrcpp::Any visitLeftValue(exprParser::LeftValueContext *context) = 0;

    virtual antlrcpp::Any visitDeclaration(exprParser::DeclarationContext *context) = 0;

    virtual antlrcpp::Any visitSimpleId(exprParser::SimpleIdContext *context) = 0;

    virtual antlrcpp::Any visitMultipleId(exprParser::MultipleIdContext *context) = 0;

    virtual antlrcpp::Any visitDefinition(exprParser::DefinitionContext *context) = 0;

    virtual antlrcpp::Any visitAffectation(exprParser::AffectationContext *context) = 0;

    virtual antlrcpp::Any visitReturn(exprParser::ReturnContext *context) = 0;

    virtual antlrcpp::Any visitIfInstr(exprParser::IfInstrContext *context) = 0;

    virtual antlrcpp::Any visitWhileInstr(exprParser::WhileInstrContext *context) = 0;

    virtual antlrcpp::Any visitInstrAff(exprParser::InstrAffContext *context) = 0;

    virtual antlrcpp::Any visitInstrDec(exprParser::InstrDecContext *context) = 0;

    virtual antlrcpp::Any visitInstrExpr(exprParser::InstrExprContext *context) = 0;

    virtual antlrcpp::Any visitInstrRet(exprParser::InstrRetContext *context) = 0;

    virtual antlrcpp::Any visitInstr(exprParser::InstrContext *context) = 0;

    virtual antlrcpp::Any visitInstrCorps(exprParser::InstrCorpsContext *context) = 0;


};

