#pragma once

#include "antlr4-runtime.h"
#include "exprBaseVisitor.h"

using namespace std;

class Compilateur : public exprBaseVisitor {
 public:

  antlrcpp::Any visitProggeneral(exprParser::ProggeneralContext *ctx) override  {
	cout << "Prog General" << endl;
    return (int) visit(ctx->code());
  }

  antlrcpp::Any visitTypevar(exprParser::TypevarContext *ctx) override {
	cout << "Type var" << endl;
    return (int) 0; //stoi (ctx->INT()->getText());
  }

  antlrcpp::Any visitNom(exprParser::NomContext *ctx) override {
	cout << "Nom" << endl;
    return ctx->NOM()->getText();
  }

  antlrcpp::Any visitCodefonction(exprParser::CodefonctionContext *ctx) override {
	cout << "Code fonction" << endl;
    return (int) stoi (ctx->INT()->getText());
  }
};
