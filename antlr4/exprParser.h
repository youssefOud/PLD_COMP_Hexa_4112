
// Generated from expr.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  exprParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, INT = 7, 
    NBR = 8, RETURN = 9, ID = 10, WS = 11
  };

  enum {
    RuleFunction = 0, RuleType = 1, RuleRight = 2, RuleLeft = 3, RuleDeclare = 4, 
    RuleAffect = 5, RuleRet = 6, RuleCorps = 7
  };

  exprParser(antlr4::TokenStream *input);
  ~exprParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class FunctionContext;
  class TypeContext;
  class RightContext;
  class LeftContext;
  class DeclareContext;
  class AffectContext;
  class RetContext;
  class CorpsContext; 

  class  FunctionContext : public antlr4::ParserRuleContext {
  public:
    FunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    antlr4::tree::TerminalNode *ID();
    CorpsContext *corps();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionContext* function();

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

  class  RightContext : public antlr4::ParserRuleContext {
  public:
    RightContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    RightContext() : antlr4::ParserRuleContext() { }
    void copyFrom(RightContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  RightValueIDContext : public RightContext {
  public:
    RightValueIDContext(RightContext *ctx);

    antlr4::tree::TerminalNode *ID();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  RightValueNBRContext : public RightContext {
  public:
    RightValueNBRContext(RightContext *ctx);

    antlr4::tree::TerminalNode *NBR();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  RightContext* right();

  class  LeftContext : public antlr4::ParserRuleContext {
  public:
    LeftContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    LeftContext() : antlr4::ParserRuleContext() { }
    void copyFrom(LeftContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  LeftValueContext : public LeftContext {
  public:
    LeftValueContext(LeftContext *ctx);

    antlr4::tree::TerminalNode *ID();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  LeftContext* left();

  class  DeclareContext : public antlr4::ParserRuleContext {
  public:
    DeclareContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    DeclareContext() : antlr4::ParserRuleContext() { }
    void copyFrom(DeclareContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  DeclarationContext : public DeclareContext {
  public:
    DeclarationContext(DeclareContext *ctx);

    TypeContext *type();
    antlr4::tree::TerminalNode *ID();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  DeclareContext* declare();

  class  AffectContext : public antlr4::ParserRuleContext {
  public:
    AffectContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    AffectContext() : antlr4::ParserRuleContext() { }
    void copyFrom(AffectContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  DefinitionContext : public AffectContext {
  public:
    DefinitionContext(AffectContext *ctx);

    TypeContext *type();
    LeftContext *left();
    RightContext *right();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AffectationContext : public AffectContext {
  public:
    AffectationContext(AffectContext *ctx);

    LeftContext *left();
    RightContext *right();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  AffectContext* affect();

  class  RetContext : public antlr4::ParserRuleContext {
  public:
    RetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    RetContext() : antlr4::ParserRuleContext() { }
    void copyFrom(RetContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ReturnContext : public RetContext {
  public:
    ReturnContext(RetContext *ctx);

    antlr4::tree::TerminalNode *RETURN();
    RightContext *right();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  RetContext* ret();

  class  CorpsContext : public antlr4::ParserRuleContext {
  public:
    CorpsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    CorpsContext() : antlr4::ParserRuleContext() { }
    void copyFrom(CorpsContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  CorpsAffectRetContext : public CorpsContext {
  public:
    CorpsAffectRetContext(CorpsContext *ctx);

    AffectContext *affect();
    RetContext *ret();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CorpsRetourContext : public CorpsContext {
  public:
    CorpsRetourContext(CorpsContext *ctx);

    RetContext *ret();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CorpsDeclareRetContext : public CorpsContext {
  public:
    CorpsDeclareRetContext(CorpsContext *ctx);

    DeclareContext *declare();
    RetContext *ret();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CorpsAffectContext : public CorpsContext {
  public:
    CorpsAffectContext(CorpsContext *ctx);

    AffectContext *affect();
    CorpsContext *corps();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CorpsRecContext : public CorpsContext {
  public:
    CorpsRecContext(CorpsContext *ctx);

    CorpsContext *corps();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CorpsDeclareContext : public CorpsContext {
  public:
    CorpsDeclareContext(CorpsContext *ctx);

    DeclareContext *declare();
    CorpsContext *corps();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  CorpsContext* corps();
  CorpsContext* corps(int precedence);

  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool corpsSempred(CorpsContext *_localctx, size_t predicateIndex);

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

