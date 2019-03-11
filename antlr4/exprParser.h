
// Generated from expr.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  exprParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    INT = 8, NBR = 9, ID = 10, WS = 11
  };

  enum {
    RuleProg = 0, RuleType = 1, RuleFunction = 2, RulePr = 3, RuleExpr = 4, 
    RuleRet = 5
  };

  exprParser(antlr4::TokenStream *input);
  ~exprParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ProgContext;
  class TypeContext;
  class FunctionContext;
  class PrContext;
  class ExprContext;
  class RetContext; 

  class  ProgContext : public antlr4::ParserRuleContext {
  public:
    ProgContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    PrContext *pr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgContext* prog();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    TypeContext() : antlr4::ParserRuleContext() { }
    void copyFrom(TypeContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  TypefctContext : public TypeContext {
  public:
    TypefctContext(TypeContext *ctx);

    antlr4::tree::TerminalNode *INT();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  TypeContext* type();

  class  FunctionContext : public antlr4::ParserRuleContext {
  public:
    FunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    FunctionContext() : antlr4::ParserRuleContext() { }
    void copyFrom(FunctionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  NomfctContext : public FunctionContext {
  public:
    NomfctContext(FunctionContext *ctx);

    antlr4::tree::TerminalNode *ID();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  FunctionContext* function();

  class  PrContext : public antlr4::ParserRuleContext {
  public:
    PrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    PrContext() : antlr4::ParserRuleContext() { }
    void copyFrom(PrContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  InstructionContext : public PrContext {
  public:
    InstructionContext(PrContext *ctx);

    RetContext *ret();
    ExprContext *expr();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  PrContext* pr();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExprContext() : antlr4::ParserRuleContext() { }
    void copyFrom(ExprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  NombreContext : public ExprContext {
  public:
    NombreContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *NBR();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExprContext* expr();

  class  RetContext : public antlr4::ParserRuleContext {
  public:
    RetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RetContext* ret();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

