
// Generated from expr.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  exprParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, VOID = 17, INT = 18, CHAR = 19, NBR = 20, RETURN = 21, 
    IF = 22, ELSE = 23, WHILE = 24, ID = 25, CARACTERE = 26, WS = 27
  };

  enum {
    RuleFichier = 0, RuleProgramme = 1, RuleAppel = 2, RuleVars = 3, RuleFunction = 4, 
    RuleDefAppel = 5, RuleTypefct = 6, RuleType = 7, RuleRight = 8, RuleExpression = 9, 
    RuleLeft = 10, RuleDeclare = 11, RuleIds = 12, RuleAffect = 13, RuleRet = 14, 
    RuleInstruction = 15, RuleCorps = 16
  };

  exprParser(antlr4::TokenStream *input);
  ~exprParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class FichierContext;
  class ProgrammeContext;
  class AppelContext;
  class VarsContext;
  class FunctionContext;
  class DefAppelContext;
  class TypefctContext;
  class TypeContext;
  class RightContext;
  class ExpressionContext;
  class LeftContext;
  class DeclareContext;
  class IdsContext;
  class AffectContext;
  class RetContext;
  class InstructionContext;
  class CorpsContext; 

  class  FichierContext : public antlr4::ParserRuleContext {
  public:
    FichierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ProgrammeContext *programme();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FichierContext* fichier();

  class  ProgrammeContext : public antlr4::ParserRuleContext {
  public:
    ProgrammeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ProgrammeContext() : antlr4::ParserRuleContext() { }
    void copyFrom(ProgrammeContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  FctMultContext : public ProgrammeContext {
  public:
    FctMultContext(ProgrammeContext *ctx);

    FunctionContext *function();
    ProgrammeContext *programme();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FctUniqueContext : public ProgrammeContext {
  public:
    FctUniqueContext(ProgrammeContext *ctx);

    FunctionContext *function();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ProgrammeContext* programme();

  class  AppelContext : public antlr4::ParserRuleContext {
  public:
    AppelContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    AppelContext() : antlr4::ParserRuleContext() { }
    void copyFrom(AppelContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  AppelFuncAvecParamContext : public AppelContext {
  public:
    AppelFuncAvecParamContext(AppelContext *ctx);

    antlr4::tree::TerminalNode *ID();
    VarsContext *vars();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AppelFuncSansParamContext : public AppelContext {
  public:
    AppelFuncSansParamContext(AppelContext *ctx);

    antlr4::tree::TerminalNode *ID();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  AppelContext* appel();

  class  VarsContext : public antlr4::ParserRuleContext {
  public:
    VarsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    VarsContext() : antlr4::ParserRuleContext() { }
    void copyFrom(VarsContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ParamUniqueContext : public VarsContext {
  public:
    ParamUniqueContext(VarsContext *ctx);

    ExpressionContext *expression();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParamMultContext : public VarsContext {
  public:
    ParamMultContext(VarsContext *ctx);

    ExpressionContext *expression();
    VarsContext *vars();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  VarsContext* vars();

  class  FunctionContext : public antlr4::ParserRuleContext {
  public:
    FunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    FunctionContext() : antlr4::ParserRuleContext() { }
    void copyFrom(FunctionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  FctSansParamContext : public FunctionContext {
  public:
    FctSansParamContext(FunctionContext *ctx);

    TypefctContext *typefct();
    antlr4::tree::TerminalNode *ID();
    CorpsContext *corps();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FctContext : public FunctionContext {
  public:
    FctContext(FunctionContext *ctx);

    TypefctContext *typefct();
    antlr4::tree::TerminalNode *ID();
    DefAppelContext *defAppel();
    CorpsContext *corps();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  FunctionContext* function();

  class  DefAppelContext : public antlr4::ParserRuleContext {
  public:
    DefAppelContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    DefAppelContext() : antlr4::ParserRuleContext() { }
    void copyFrom(DefAppelContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  DefParamMultContext : public DefAppelContext {
  public:
    DefParamMultContext(DefAppelContext *ctx);

    TypeContext *type();
    antlr4::tree::TerminalNode *ID();
    DefAppelContext *defAppel();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DefParamUniqueContext : public DefAppelContext {
  public:
    DefParamUniqueContext(DefAppelContext *ctx);

    TypeContext *type();
    antlr4::tree::TerminalNode *ID();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  DefAppelContext* defAppel();

  class  TypefctContext : public antlr4::ParserRuleContext {
  public:
    TypefctContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    TypefctContext() : antlr4::ParserRuleContext() { }
    void copyFrom(TypefctContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  RetourIntContext : public TypefctContext {
  public:
    RetourIntContext(TypefctContext *ctx);

    antlr4::tree::TerminalNode *INT();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  RetourVoidContext : public TypefctContext {
  public:
    RetourVoidContext(TypefctContext *ctx);

    antlr4::tree::TerminalNode *VOID();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  TypefctContext* typefct();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    TypeContext() : antlr4::ParserRuleContext() { }
    void copyFrom(TypeContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  TypeVarCharContext : public TypeContext {
  public:
    TypeVarCharContext(TypeContext *ctx);

    antlr4::tree::TerminalNode *CHAR();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TypeVarIntContext : public TypeContext {
  public:
    TypeVarIntContext(TypeContext *ctx);

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

  class  RightValueCHARContext : public RightContext {
  public:
    RightValueCHARContext(RightContext *ctx);

    antlr4::tree::TerminalNode *CARACTERE();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  RightContext* right();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExpressionContext() : antlr4::ParserRuleContext() { }
    void copyFrom(ExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ExprNegContext : public ExpressionContext {
  public:
    ExprNegContext(ExpressionContext *ctx);

    ExpressionContext *expression();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprCompContext : public ExpressionContext {
  public:
    ExprCompContext(ExpressionContext *ctx);

    antlr4::Token *opc = nullptr;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprParContext : public ExpressionContext {
  public:
    ExprParContext(ExpressionContext *ctx);

    ExpressionContext *expression();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprAppContext : public ExpressionContext {
  public:
    ExprAppContext(ExpressionContext *ctx);

    AppelContext *appel();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  RightValueContext : public ExpressionContext {
  public:
    RightValueContext(ExpressionContext *ctx);

    RightContext *right();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprAddMinusContext : public ExpressionContext {
  public:
    ExprAddMinusContext(ExpressionContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprMultContext : public ExpressionContext {
  public:
    ExprMultContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
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
    IdsContext *ids();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  DeclareContext* declare();

  class  IdsContext : public antlr4::ParserRuleContext {
  public:
    IdsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    IdsContext() : antlr4::ParserRuleContext() { }
    void copyFrom(IdsContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  MultipleIdContext : public IdsContext {
  public:
    MultipleIdContext(IdsContext *ctx);

    antlr4::tree::TerminalNode *ID();
    IdsContext *ids();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SimpleIdContext : public IdsContext {
  public:
    SimpleIdContext(IdsContext *ctx);

    antlr4::tree::TerminalNode *ID();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  IdsContext* ids();

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
    ExpressionContext *expression();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AffectationContext : public AffectContext {
  public:
    AffectationContext(AffectContext *ctx);

    LeftContext *left();
    ExpressionContext *expression();
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
    ExpressionContext *expression();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  RetContext* ret();

  class  InstructionContext : public antlr4::ParserRuleContext {
  public:
    InstructionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    InstructionContext() : antlr4::ParserRuleContext() { }
    void copyFrom(InstructionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  WhileInstrContext : public InstructionContext {
  public:
    WhileInstrContext(InstructionContext *ctx);

    antlr4::tree::TerminalNode *WHILE();
    ExpressionContext *expression();
    CorpsContext *corps();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  InstrAffContext : public InstructionContext {
  public:
    InstrAffContext(InstructionContext *ctx);

    AffectContext *affect();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  InstrExprContext : public InstructionContext {
  public:
    InstrExprContext(InstructionContext *ctx);

    ExpressionContext *expression();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  InstrRetContext : public InstructionContext {
  public:
    InstrRetContext(InstructionContext *ctx);

    RetContext *ret();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IfInstrContext : public InstructionContext {
  public:
    IfInstrContext(InstructionContext *ctx);

    antlr4::tree::TerminalNode *IF();
    ExpressionContext *expression();
    std::vector<CorpsContext *> corps();
    CorpsContext* corps(size_t i);
    antlr4::tree::TerminalNode *ELSE();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  InstrDecContext : public InstructionContext {
  public:
    InstrDecContext(InstructionContext *ctx);

    DeclareContext *declare();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  InstructionContext* instruction();

  class  CorpsContext : public antlr4::ParserRuleContext {
  public:
    CorpsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    CorpsContext() : antlr4::ParserRuleContext() { }
    void copyFrom(CorpsContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  InstrCorpsContext : public CorpsContext {
  public:
    InstrCorpsContext(CorpsContext *ctx);

    InstructionContext *instruction();
    CorpsContext *corps();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  InstrContext : public CorpsContext {
  public:
    InstrContext(CorpsContext *ctx);

    InstructionContext *instruction();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  CorpsContext* corps();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);

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

