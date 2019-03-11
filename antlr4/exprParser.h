
// Generated from expr.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  exprParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, WS = 7, 
    INT = 8, NOM = 9
  };

  enum {
    RuleProg = 0, RuleType = 1, RuleNomfonction = 2, RuleCode = 3
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
  class NomfonctionContext;
  class CodeContext; 

  class  ProgContext : public antlr4::ParserRuleContext {
  public:
    ProgContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ProgContext() : antlr4::ParserRuleContext() { }
    void copyFrom(ProgContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ProggeneralContext : public ProgContext {
  public:
    ProggeneralContext(ProgContext *ctx);

    TypeContext *type();
    NomfonctionContext *nomfonction();
    CodeContext *code();
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

  class  TypevarContext : public TypeContext {
  public:
    TypevarContext(TypeContext *ctx);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  TypeContext* type();

  class  NomfonctionContext : public antlr4::ParserRuleContext {
  public:
    NomfonctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    NomfonctionContext() : antlr4::ParserRuleContext() { }
    void copyFrom(NomfonctionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  NomContext : public NomfonctionContext {
  public:
    NomContext(NomfonctionContext *ctx);

    antlr4::tree::TerminalNode *NOM();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  NomfonctionContext* nomfonction();

  class  CodeContext : public antlr4::ParserRuleContext {
  public:
    CodeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    CodeContext() : antlr4::ParserRuleContext() { }
    void copyFrom(CodeContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  CodefonctionContext : public CodeContext {
  public:
    CodefonctionContext(CodeContext *ctx);

    antlr4::tree::TerminalNode *INT();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  CodeContext* code();


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

