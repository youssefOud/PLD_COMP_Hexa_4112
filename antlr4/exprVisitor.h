
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
    virtual antlrcpp::Any visitProggeneral(exprParser::ProggeneralContext *context) = 0;

    virtual antlrcpp::Any visitTypevar(exprParser::TypevarContext *context) = 0;

    virtual antlrcpp::Any visitNom(exprParser::NomContext *context) = 0;

    virtual antlrcpp::Any visitCodefonction(exprParser::CodefonctionContext *context) = 0;


};

