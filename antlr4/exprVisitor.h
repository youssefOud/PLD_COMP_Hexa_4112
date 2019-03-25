
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
    virtual antlrcpp::Any visitFunction(exprParser::FunctionContext *context) = 0;

    virtual antlrcpp::Any visitTypefct(exprParser::TypefctContext *context) = 0;

    virtual antlrcpp::Any visitRightValueID(exprParser::RightValueIDContext *context) = 0;

    virtual antlrcpp::Any visitRightValueNBR(exprParser::RightValueNBRContext *context) = 0;

    virtual antlrcpp::Any visitExprPar(exprParser::ExprParContext *context) = 0;

    virtual antlrcpp::Any visitExprAdd(exprParser::ExprAddContext *context) = 0;

    virtual antlrcpp::Any visitExprMinus(exprParser::ExprMinusContext *context) = 0;

    virtual antlrcpp::Any visitRightValue(exprParser::RightValueContext *context) = 0;

    virtual antlrcpp::Any visitExprMult(exprParser::ExprMultContext *context) = 0;

    virtual antlrcpp::Any visitLeftValue(exprParser::LeftValueContext *context) = 0;

    virtual antlrcpp::Any visitDeclaration(exprParser::DeclarationContext *context) = 0;

    virtual antlrcpp::Any visitSimpleId(exprParser::SimpleIdContext *context) = 0;

    virtual antlrcpp::Any visitMultipleId(exprParser::MultipleIdContext *context) = 0;

    virtual antlrcpp::Any visitDefinition(exprParser::DefinitionContext *context) = 0;

    virtual antlrcpp::Any visitAffectation(exprParser::AffectationContext *context) = 0;

    virtual antlrcpp::Any visitReturn(exprParser::ReturnContext *context) = 0;

    virtual antlrcpp::Any visitCorpsAffectRet(exprParser::CorpsAffectRetContext *context) = 0;

    virtual antlrcpp::Any visitCorpsRetour(exprParser::CorpsRetourContext *context) = 0;

    virtual antlrcpp::Any visitCorpsDeclareRet(exprParser::CorpsDeclareRetContext *context) = 0;

    virtual antlrcpp::Any visitCorpsAffect(exprParser::CorpsAffectContext *context) = 0;

    virtual antlrcpp::Any visitCorpsRec(exprParser::CorpsRecContext *context) = 0;

    virtual antlrcpp::Any visitCorpsDeclare(exprParser::CorpsDeclareContext *context) = 0;


};

