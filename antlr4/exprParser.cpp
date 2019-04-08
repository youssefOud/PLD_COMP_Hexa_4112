
// Generated from expr.g4 by ANTLR 4.7.1


#include "exprVisitor.h"

#include "exprParser.h"


using namespace antlrcpp;
using namespace antlr4;

exprParser::exprParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

exprParser::~exprParser() {
  delete _interpreter;
}

std::string exprParser::getGrammarFileName() const {
  return "expr.g4";
}

const std::vector<std::string>& exprParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& exprParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- FichierContext ------------------------------------------------------------------

exprParser::FichierContext::FichierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

exprParser::ProgrammeContext* exprParser::FichierContext::programme() {
  return getRuleContext<exprParser::ProgrammeContext>(0);
}


size_t exprParser::FichierContext::getRuleIndex() const {
  return exprParser::RuleFichier;
}

antlrcpp::Any exprParser::FichierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitFichier(this);
  else
    return visitor->visitChildren(this);
}

exprParser::FichierContext* exprParser::fichier() {
  FichierContext *_localctx = _tracker.createInstance<FichierContext>(_ctx, getState());
  enterRule(_localctx, 0, exprParser::RuleFichier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(34);
    programme();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgrammeContext ------------------------------------------------------------------

exprParser::ProgrammeContext::ProgrammeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t exprParser::ProgrammeContext::getRuleIndex() const {
  return exprParser::RuleProgramme;
}

void exprParser::ProgrammeContext::copyFrom(ProgrammeContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- FctMultContext ------------------------------------------------------------------

exprParser::FunctionContext* exprParser::FctMultContext::function() {
  return getRuleContext<exprParser::FunctionContext>(0);
}

exprParser::ProgrammeContext* exprParser::FctMultContext::programme() {
  return getRuleContext<exprParser::ProgrammeContext>(0);
}

exprParser::FctMultContext::FctMultContext(ProgrammeContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::FctMultContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitFctMult(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FctUniqueContext ------------------------------------------------------------------

exprParser::FunctionContext* exprParser::FctUniqueContext::function() {
  return getRuleContext<exprParser::FunctionContext>(0);
}

exprParser::FctUniqueContext::FctUniqueContext(ProgrammeContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::FctUniqueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitFctUnique(this);
  else
    return visitor->visitChildren(this);
}
exprParser::ProgrammeContext* exprParser::programme() {
  ProgrammeContext *_localctx = _tracker.createInstance<ProgrammeContext>(_ctx, getState());
  enterRule(_localctx, 2, exprParser::RuleProgramme);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(40);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<ProgrammeContext *>(_tracker.createInstance<exprParser::FctMultContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(36);
      function();
      setState(37);
      programme();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<ProgrammeContext *>(_tracker.createInstance<exprParser::FctUniqueContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(39);
      function();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AppelContext ------------------------------------------------------------------

exprParser::AppelContext::AppelContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t exprParser::AppelContext::getRuleIndex() const {
  return exprParser::RuleAppel;
}

void exprParser::AppelContext::copyFrom(AppelContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- AppelFuncAvecParamContext ------------------------------------------------------------------

tree::TerminalNode* exprParser::AppelFuncAvecParamContext::ID() {
  return getToken(exprParser::ID, 0);
}

exprParser::VarsContext* exprParser::AppelFuncAvecParamContext::vars() {
  return getRuleContext<exprParser::VarsContext>(0);
}

exprParser::AppelFuncAvecParamContext::AppelFuncAvecParamContext(AppelContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::AppelFuncAvecParamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitAppelFuncAvecParam(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AppelFuncSansParamContext ------------------------------------------------------------------

tree::TerminalNode* exprParser::AppelFuncSansParamContext::ID() {
  return getToken(exprParser::ID, 0);
}

exprParser::AppelFuncSansParamContext::AppelFuncSansParamContext(AppelContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::AppelFuncSansParamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitAppelFuncSansParam(this);
  else
    return visitor->visitChildren(this);
}
exprParser::AppelContext* exprParser::appel() {
  AppelContext *_localctx = _tracker.createInstance<AppelContext>(_ctx, getState());
  enterRule(_localctx, 4, exprParser::RuleAppel);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(50);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<AppelContext *>(_tracker.createInstance<exprParser::AppelFuncSansParamContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(42);
      match(exprParser::ID);
      setState(43);
      match(exprParser::T__0);
      setState(44);
      match(exprParser::T__1);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<AppelContext *>(_tracker.createInstance<exprParser::AppelFuncAvecParamContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(45);
      match(exprParser::ID);
      setState(46);
      match(exprParser::T__0);
      setState(47);
      vars();
      setState(48);
      match(exprParser::T__1);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarsContext ------------------------------------------------------------------

exprParser::VarsContext::VarsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t exprParser::VarsContext::getRuleIndex() const {
  return exprParser::RuleVars;
}

void exprParser::VarsContext::copyFrom(VarsContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ParamUniqueContext ------------------------------------------------------------------

exprParser::ExpressionContext* exprParser::ParamUniqueContext::expression() {
  return getRuleContext<exprParser::ExpressionContext>(0);
}

exprParser::ParamUniqueContext::ParamUniqueContext(VarsContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::ParamUniqueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitParamUnique(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParamMultContext ------------------------------------------------------------------

exprParser::ExpressionContext* exprParser::ParamMultContext::expression() {
  return getRuleContext<exprParser::ExpressionContext>(0);
}

exprParser::VarsContext* exprParser::ParamMultContext::vars() {
  return getRuleContext<exprParser::VarsContext>(0);
}

exprParser::ParamMultContext::ParamMultContext(VarsContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::ParamMultContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitParamMult(this);
  else
    return visitor->visitChildren(this);
}
exprParser::VarsContext* exprParser::vars() {
  VarsContext *_localctx = _tracker.createInstance<VarsContext>(_ctx, getState());
  enterRule(_localctx, 6, exprParser::RuleVars);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(57);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<VarsContext *>(_tracker.createInstance<exprParser::ParamUniqueContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(52);
      expression(0);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<VarsContext *>(_tracker.createInstance<exprParser::ParamMultContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(53);
      expression(0);
      setState(54);
      match(exprParser::T__2);
      setState(55);
      vars();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

exprParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t exprParser::FunctionContext::getRuleIndex() const {
  return exprParser::RuleFunction;
}

void exprParser::FunctionContext::copyFrom(FunctionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- FctSansParamContext ------------------------------------------------------------------

exprParser::TypefctContext* exprParser::FctSansParamContext::typefct() {
  return getRuleContext<exprParser::TypefctContext>(0);
}

tree::TerminalNode* exprParser::FctSansParamContext::ID() {
  return getToken(exprParser::ID, 0);
}

exprParser::CorpsContext* exprParser::FctSansParamContext::corps() {
  return getRuleContext<exprParser::CorpsContext>(0);
}

exprParser::FctSansParamContext::FctSansParamContext(FunctionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::FctSansParamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitFctSansParam(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FctContext ------------------------------------------------------------------

exprParser::TypefctContext* exprParser::FctContext::typefct() {
  return getRuleContext<exprParser::TypefctContext>(0);
}

tree::TerminalNode* exprParser::FctContext::ID() {
  return getToken(exprParser::ID, 0);
}

exprParser::DefAppelContext* exprParser::FctContext::defAppel() {
  return getRuleContext<exprParser::DefAppelContext>(0);
}

exprParser::CorpsContext* exprParser::FctContext::corps() {
  return getRuleContext<exprParser::CorpsContext>(0);
}

exprParser::FctContext::FctContext(FunctionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::FctContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitFct(this);
  else
    return visitor->visitChildren(this);
}
exprParser::FunctionContext* exprParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 8, exprParser::RuleFunction);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(76);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<FunctionContext *>(_tracker.createInstance<exprParser::FctContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(59);
      typefct();
      setState(60);
      match(exprParser::ID);
      setState(61);
      match(exprParser::T__0);
      setState(62);
      defAppel();
      setState(63);
      match(exprParser::T__1);
      setState(64);
      match(exprParser::T__3);
      setState(65);
      corps();
      setState(66);
      match(exprParser::T__4);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<FunctionContext *>(_tracker.createInstance<exprParser::FctSansParamContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(68);
      typefct();
      setState(69);
      match(exprParser::ID);
      setState(70);
      match(exprParser::T__0);
      setState(71);
      match(exprParser::T__1);
      setState(72);
      match(exprParser::T__3);
      setState(73);
      corps();
      setState(74);
      match(exprParser::T__4);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefAppelContext ------------------------------------------------------------------

exprParser::DefAppelContext::DefAppelContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t exprParser::DefAppelContext::getRuleIndex() const {
  return exprParser::RuleDefAppel;
}

void exprParser::DefAppelContext::copyFrom(DefAppelContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- DefParamMultContext ------------------------------------------------------------------

exprParser::TypeContext* exprParser::DefParamMultContext::type() {
  return getRuleContext<exprParser::TypeContext>(0);
}

tree::TerminalNode* exprParser::DefParamMultContext::ID() {
  return getToken(exprParser::ID, 0);
}

exprParser::DefAppelContext* exprParser::DefParamMultContext::defAppel() {
  return getRuleContext<exprParser::DefAppelContext>(0);
}

exprParser::DefParamMultContext::DefParamMultContext(DefAppelContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::DefParamMultContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitDefParamMult(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DefParamUniqueContext ------------------------------------------------------------------

exprParser::TypeContext* exprParser::DefParamUniqueContext::type() {
  return getRuleContext<exprParser::TypeContext>(0);
}

tree::TerminalNode* exprParser::DefParamUniqueContext::ID() {
  return getToken(exprParser::ID, 0);
}

exprParser::DefParamUniqueContext::DefParamUniqueContext(DefAppelContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::DefParamUniqueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitDefParamUnique(this);
  else
    return visitor->visitChildren(this);
}
exprParser::DefAppelContext* exprParser::defAppel() {
  DefAppelContext *_localctx = _tracker.createInstance<DefAppelContext>(_ctx, getState());
  enterRule(_localctx, 10, exprParser::RuleDefAppel);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(86);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<DefAppelContext *>(_tracker.createInstance<exprParser::DefParamUniqueContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(78);
      type();
      setState(79);
      match(exprParser::ID);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<DefAppelContext *>(_tracker.createInstance<exprParser::DefParamMultContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(81);
      type();
      setState(82);
      match(exprParser::ID);
      setState(83);
      match(exprParser::T__2);
      setState(84);
      defAppel();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypefctContext ------------------------------------------------------------------

exprParser::TypefctContext::TypefctContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t exprParser::TypefctContext::getRuleIndex() const {
  return exprParser::RuleTypefct;
}

void exprParser::TypefctContext::copyFrom(TypefctContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- RetourIntContext ------------------------------------------------------------------

tree::TerminalNode* exprParser::RetourIntContext::INT() {
  return getToken(exprParser::INT, 0);
}

exprParser::RetourIntContext::RetourIntContext(TypefctContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::RetourIntContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitRetourInt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RetourVoidContext ------------------------------------------------------------------

tree::TerminalNode* exprParser::RetourVoidContext::VOID() {
  return getToken(exprParser::VOID, 0);
}

exprParser::RetourVoidContext::RetourVoidContext(TypefctContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::RetourVoidContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitRetourVoid(this);
  else
    return visitor->visitChildren(this);
}
exprParser::TypefctContext* exprParser::typefct() {
  TypefctContext *_localctx = _tracker.createInstance<TypefctContext>(_ctx, getState());
  enterRule(_localctx, 12, exprParser::RuleTypefct);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(90);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case exprParser::INT: {
        _localctx = dynamic_cast<TypefctContext *>(_tracker.createInstance<exprParser::RetourIntContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(88);
        match(exprParser::INT);
        break;
      }

      case exprParser::VOID: {
        _localctx = dynamic_cast<TypefctContext *>(_tracker.createInstance<exprParser::RetourVoidContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(89);
        match(exprParser::VOID);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

exprParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t exprParser::TypeContext::getRuleIndex() const {
  return exprParser::RuleType;
}

void exprParser::TypeContext::copyFrom(TypeContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- TypeVarCharContext ------------------------------------------------------------------

tree::TerminalNode* exprParser::TypeVarCharContext::CHAR() {
  return getToken(exprParser::CHAR, 0);
}

exprParser::TypeVarCharContext::TypeVarCharContext(TypeContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::TypeVarCharContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitTypeVarChar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TypeVarIntContext ------------------------------------------------------------------

tree::TerminalNode* exprParser::TypeVarIntContext::INT() {
  return getToken(exprParser::INT, 0);
}

exprParser::TypeVarIntContext::TypeVarIntContext(TypeContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::TypeVarIntContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitTypeVarInt(this);
  else
    return visitor->visitChildren(this);
}
exprParser::TypeContext* exprParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 14, exprParser::RuleType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(94);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case exprParser::INT: {
        _localctx = dynamic_cast<TypeContext *>(_tracker.createInstance<exprParser::TypeVarIntContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(92);
        match(exprParser::INT);
        break;
      }

      case exprParser::CHAR: {
        _localctx = dynamic_cast<TypeContext *>(_tracker.createInstance<exprParser::TypeVarCharContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(93);
        match(exprParser::CHAR);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RightContext ------------------------------------------------------------------

exprParser::RightContext::RightContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t exprParser::RightContext::getRuleIndex() const {
  return exprParser::RuleRight;
}

void exprParser::RightContext::copyFrom(RightContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- RightValueIDContext ------------------------------------------------------------------

tree::TerminalNode* exprParser::RightValueIDContext::ID() {
  return getToken(exprParser::ID, 0);
}

exprParser::RightValueIDContext::RightValueIDContext(RightContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::RightValueIDContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitRightValueID(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RightValueNBRContext ------------------------------------------------------------------

tree::TerminalNode* exprParser::RightValueNBRContext::NBR() {
  return getToken(exprParser::NBR, 0);
}

exprParser::RightValueNBRContext::RightValueNBRContext(RightContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::RightValueNBRContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitRightValueNBR(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RightValueCHARContext ------------------------------------------------------------------

tree::TerminalNode* exprParser::RightValueCHARContext::CARACTERE() {
  return getToken(exprParser::CARACTERE, 0);
}

exprParser::RightValueCHARContext::RightValueCHARContext(RightContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::RightValueCHARContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitRightValueCHAR(this);
  else
    return visitor->visitChildren(this);
}
exprParser::RightContext* exprParser::right() {
  RightContext *_localctx = _tracker.createInstance<RightContext>(_ctx, getState());
  enterRule(_localctx, 16, exprParser::RuleRight);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(99);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case exprParser::ID: {
        _localctx = dynamic_cast<RightContext *>(_tracker.createInstance<exprParser::RightValueIDContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(96);
        match(exprParser::ID);
        break;
      }

      case exprParser::NBR: {
        _localctx = dynamic_cast<RightContext *>(_tracker.createInstance<exprParser::RightValueNBRContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(97);
        match(exprParser::NBR);
        break;
      }

      case exprParser::CARACTERE: {
        _localctx = dynamic_cast<RightContext *>(_tracker.createInstance<exprParser::RightValueCHARContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(98);
        match(exprParser::CARACTERE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

exprParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t exprParser::ExpressionContext::getRuleIndex() const {
  return exprParser::RuleExpression;
}

void exprParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExprNegContext ------------------------------------------------------------------

exprParser::ExpressionContext* exprParser::ExprNegContext::expression() {
  return getRuleContext<exprParser::ExpressionContext>(0);
}

exprParser::ExprNegContext::ExprNegContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::ExprNegContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitExprNeg(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprCompContext ------------------------------------------------------------------

std::vector<exprParser::ExpressionContext *> exprParser::ExprCompContext::expression() {
  return getRuleContexts<exprParser::ExpressionContext>();
}

exprParser::ExpressionContext* exprParser::ExprCompContext::expression(size_t i) {
  return getRuleContext<exprParser::ExpressionContext>(i);
}

exprParser::ExprCompContext::ExprCompContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::ExprCompContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitExprComp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprParContext ------------------------------------------------------------------

exprParser::ExpressionContext* exprParser::ExprParContext::expression() {
  return getRuleContext<exprParser::ExpressionContext>(0);
}

exprParser::ExprParContext::ExprParContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::ExprParContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitExprPar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprAppContext ------------------------------------------------------------------

exprParser::AppelContext* exprParser::ExprAppContext::appel() {
  return getRuleContext<exprParser::AppelContext>(0);
}

exprParser::ExprAppContext::ExprAppContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::ExprAppContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitExprApp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RightValueContext ------------------------------------------------------------------

exprParser::RightContext* exprParser::RightValueContext::right() {
  return getRuleContext<exprParser::RightContext>(0);
}

exprParser::RightValueContext::RightValueContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::RightValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitRightValue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprAddMinusContext ------------------------------------------------------------------

std::vector<exprParser::ExpressionContext *> exprParser::ExprAddMinusContext::expression() {
  return getRuleContexts<exprParser::ExpressionContext>();
}

exprParser::ExpressionContext* exprParser::ExprAddMinusContext::expression(size_t i) {
  return getRuleContext<exprParser::ExpressionContext>(i);
}

exprParser::ExprAddMinusContext::ExprAddMinusContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::ExprAddMinusContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitExprAddMinus(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprMultContext ------------------------------------------------------------------

std::vector<exprParser::ExpressionContext *> exprParser::ExprMultContext::expression() {
  return getRuleContexts<exprParser::ExpressionContext>();
}

exprParser::ExpressionContext* exprParser::ExprMultContext::expression(size_t i) {
  return getRuleContext<exprParser::ExpressionContext>(i);
}

exprParser::ExprMultContext::ExprMultContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::ExprMultContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitExprMult(this);
  else
    return visitor->visitChildren(this);
}

exprParser::ExpressionContext* exprParser::expression() {
   return expression(0);
}

exprParser::ExpressionContext* exprParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  exprParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  exprParser::ExpressionContext *previousContext = _localctx;
  size_t startState = 18;
  enterRecursionRule(_localctx, 18, exprParser::RuleExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(110);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ExprNegContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;


      setState(102);
      match(exprParser::T__6);
      setState(103);
      expression(6);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ExprParContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(104);
      match(exprParser::T__0);
      setState(105);
      expression(0);
      setState(106);
      match(exprParser::T__1);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<RightValueContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(108);
      right();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ExprAppContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(109);
      appel();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(123);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(121);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ExprMultContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(112);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");

          setState(113);
          match(exprParser::T__5);
          setState(114);
          expression(8);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ExprAddMinusContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(115);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(116);
          dynamic_cast<ExprAddMinusContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == exprParser::T__6

          || _la == exprParser::T__7)) {
            dynamic_cast<ExprAddMinusContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(117);
          expression(6);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<ExprCompContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(118);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(119);
          dynamic_cast<ExprCompContext *>(_localctx)->opc = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << exprParser::T__8)
            | (1ULL << exprParser::T__9)
            | (1ULL << exprParser::T__10)
            | (1ULL << exprParser::T__11)
            | (1ULL << exprParser::T__12)
            | (1ULL << exprParser::T__13))) != 0))) {
            dynamic_cast<ExprCompContext *>(_localctx)->opc = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(120);
          expression(5);
          break;
        }

        } 
      }
      setState(125);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LeftContext ------------------------------------------------------------------

exprParser::LeftContext::LeftContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t exprParser::LeftContext::getRuleIndex() const {
  return exprParser::RuleLeft;
}

void exprParser::LeftContext::copyFrom(LeftContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- LeftValueContext ------------------------------------------------------------------

tree::TerminalNode* exprParser::LeftValueContext::ID() {
  return getToken(exprParser::ID, 0);
}

exprParser::LeftValueContext::LeftValueContext(LeftContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::LeftValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitLeftValue(this);
  else
    return visitor->visitChildren(this);
}
exprParser::LeftContext* exprParser::left() {
  LeftContext *_localctx = _tracker.createInstance<LeftContext>(_ctx, getState());
  enterRule(_localctx, 20, exprParser::RuleLeft);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<LeftContext *>(_tracker.createInstance<exprParser::LeftValueContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(126);
    match(exprParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclareContext ------------------------------------------------------------------

exprParser::DeclareContext::DeclareContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t exprParser::DeclareContext::getRuleIndex() const {
  return exprParser::RuleDeclare;
}

void exprParser::DeclareContext::copyFrom(DeclareContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- DeclarationContext ------------------------------------------------------------------

exprParser::TypeContext* exprParser::DeclarationContext::type() {
  return getRuleContext<exprParser::TypeContext>(0);
}

exprParser::IdsContext* exprParser::DeclarationContext::ids() {
  return getRuleContext<exprParser::IdsContext>(0);
}

exprParser::DeclarationContext::DeclarationContext(DeclareContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}
exprParser::DeclareContext* exprParser::declare() {
  DeclareContext *_localctx = _tracker.createInstance<DeclareContext>(_ctx, getState());
  enterRule(_localctx, 22, exprParser::RuleDeclare);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<DeclareContext *>(_tracker.createInstance<exprParser::DeclarationContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(128);
    type();
    setState(129);
    ids();
    setState(130);
    match(exprParser::T__14);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdsContext ------------------------------------------------------------------

exprParser::IdsContext::IdsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t exprParser::IdsContext::getRuleIndex() const {
  return exprParser::RuleIds;
}

void exprParser::IdsContext::copyFrom(IdsContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- MultipleIdContext ------------------------------------------------------------------

tree::TerminalNode* exprParser::MultipleIdContext::ID() {
  return getToken(exprParser::ID, 0);
}

exprParser::IdsContext* exprParser::MultipleIdContext::ids() {
  return getRuleContext<exprParser::IdsContext>(0);
}

exprParser::MultipleIdContext::MultipleIdContext(IdsContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::MultipleIdContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitMultipleId(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SimpleIdContext ------------------------------------------------------------------

tree::TerminalNode* exprParser::SimpleIdContext::ID() {
  return getToken(exprParser::ID, 0);
}

exprParser::SimpleIdContext::SimpleIdContext(IdsContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::SimpleIdContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitSimpleId(this);
  else
    return visitor->visitChildren(this);
}
exprParser::IdsContext* exprParser::ids() {
  IdsContext *_localctx = _tracker.createInstance<IdsContext>(_ctx, getState());
  enterRule(_localctx, 24, exprParser::RuleIds);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(136);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<IdsContext *>(_tracker.createInstance<exprParser::SimpleIdContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(132);
      match(exprParser::ID);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<IdsContext *>(_tracker.createInstance<exprParser::MultipleIdContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(133);
      match(exprParser::ID);
      setState(134);
      match(exprParser::T__2);
      setState(135);
      ids();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AffectContext ------------------------------------------------------------------

exprParser::AffectContext::AffectContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t exprParser::AffectContext::getRuleIndex() const {
  return exprParser::RuleAffect;
}

void exprParser::AffectContext::copyFrom(AffectContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- DefinitionContext ------------------------------------------------------------------

exprParser::TypeContext* exprParser::DefinitionContext::type() {
  return getRuleContext<exprParser::TypeContext>(0);
}

exprParser::LeftContext* exprParser::DefinitionContext::left() {
  return getRuleContext<exprParser::LeftContext>(0);
}

exprParser::ExpressionContext* exprParser::DefinitionContext::expression() {
  return getRuleContext<exprParser::ExpressionContext>(0);
}

exprParser::DefinitionContext::DefinitionContext(AffectContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::DefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitDefinition(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AffectationContext ------------------------------------------------------------------

exprParser::LeftContext* exprParser::AffectationContext::left() {
  return getRuleContext<exprParser::LeftContext>(0);
}

exprParser::ExpressionContext* exprParser::AffectationContext::expression() {
  return getRuleContext<exprParser::ExpressionContext>(0);
}

exprParser::AffectationContext::AffectationContext(AffectContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::AffectationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitAffectation(this);
  else
    return visitor->visitChildren(this);
}
exprParser::AffectContext* exprParser::affect() {
  AffectContext *_localctx = _tracker.createInstance<AffectContext>(_ctx, getState());
  enterRule(_localctx, 26, exprParser::RuleAffect);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(149);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case exprParser::INT:
      case exprParser::CHAR: {
        _localctx = dynamic_cast<AffectContext *>(_tracker.createInstance<exprParser::DefinitionContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(138);
        type();
        setState(139);
        left();
        setState(140);
        match(exprParser::T__15);
        setState(141);
        expression(0);
        setState(142);
        match(exprParser::T__14);
        break;
      }

      case exprParser::ID: {
        _localctx = dynamic_cast<AffectContext *>(_tracker.createInstance<exprParser::AffectationContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(144);
        left();
        setState(145);
        match(exprParser::T__15);
        setState(146);
        expression(0);
        setState(147);
        match(exprParser::T__14);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RetContext ------------------------------------------------------------------

exprParser::RetContext::RetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t exprParser::RetContext::getRuleIndex() const {
  return exprParser::RuleRet;
}

void exprParser::RetContext::copyFrom(RetContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ReturnContext ------------------------------------------------------------------

tree::TerminalNode* exprParser::ReturnContext::RETURN() {
  return getToken(exprParser::RETURN, 0);
}

exprParser::ExpressionContext* exprParser::ReturnContext::expression() {
  return getRuleContext<exprParser::ExpressionContext>(0);
}

exprParser::ReturnContext::ReturnContext(RetContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::ReturnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitReturn(this);
  else
    return visitor->visitChildren(this);
}
exprParser::RetContext* exprParser::ret() {
  RetContext *_localctx = _tracker.createInstance<RetContext>(_ctx, getState());
  enterRule(_localctx, 28, exprParser::RuleRet);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<RetContext *>(_tracker.createInstance<exprParser::ReturnContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(151);
    match(exprParser::RETURN);
    setState(152);
    expression(0);
    setState(153);
    match(exprParser::T__14);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InstructionContext ------------------------------------------------------------------

exprParser::InstructionContext::InstructionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t exprParser::InstructionContext::getRuleIndex() const {
  return exprParser::RuleInstruction;
}

void exprParser::InstructionContext::copyFrom(InstructionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- WhileInstrContext ------------------------------------------------------------------

tree::TerminalNode* exprParser::WhileInstrContext::WHILE() {
  return getToken(exprParser::WHILE, 0);
}

exprParser::ExpressionContext* exprParser::WhileInstrContext::expression() {
  return getRuleContext<exprParser::ExpressionContext>(0);
}

exprParser::CorpsContext* exprParser::WhileInstrContext::corps() {
  return getRuleContext<exprParser::CorpsContext>(0);
}

exprParser::WhileInstrContext::WhileInstrContext(InstructionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::WhileInstrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitWhileInstr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- InstrAffContext ------------------------------------------------------------------

exprParser::AffectContext* exprParser::InstrAffContext::affect() {
  return getRuleContext<exprParser::AffectContext>(0);
}

exprParser::InstrAffContext::InstrAffContext(InstructionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::InstrAffContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitInstrAff(this);
  else
    return visitor->visitChildren(this);
}
//----------------- InstrExprContext ------------------------------------------------------------------

exprParser::ExpressionContext* exprParser::InstrExprContext::expression() {
  return getRuleContext<exprParser::ExpressionContext>(0);
}

exprParser::InstrExprContext::InstrExprContext(InstructionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::InstrExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitInstrExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- InstrRetContext ------------------------------------------------------------------

exprParser::RetContext* exprParser::InstrRetContext::ret() {
  return getRuleContext<exprParser::RetContext>(0);
}

exprParser::InstrRetContext::InstrRetContext(InstructionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::InstrRetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitInstrRet(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfInstrContext ------------------------------------------------------------------

tree::TerminalNode* exprParser::IfInstrContext::IF() {
  return getToken(exprParser::IF, 0);
}

exprParser::ExpressionContext* exprParser::IfInstrContext::expression() {
  return getRuleContext<exprParser::ExpressionContext>(0);
}

std::vector<exprParser::CorpsContext *> exprParser::IfInstrContext::corps() {
  return getRuleContexts<exprParser::CorpsContext>();
}

exprParser::CorpsContext* exprParser::IfInstrContext::corps(size_t i) {
  return getRuleContext<exprParser::CorpsContext>(i);
}

tree::TerminalNode* exprParser::IfInstrContext::ELSE() {
  return getToken(exprParser::ELSE, 0);
}

exprParser::IfInstrContext::IfInstrContext(InstructionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::IfInstrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitIfInstr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- InstrDecContext ------------------------------------------------------------------

exprParser::DeclareContext* exprParser::InstrDecContext::declare() {
  return getRuleContext<exprParser::DeclareContext>(0);
}

exprParser::InstrDecContext::InstrDecContext(InstructionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::InstrDecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitInstrDec(this);
  else
    return visitor->visitChildren(this);
}
exprParser::InstructionContext* exprParser::instruction() {
  InstructionContext *_localctx = _tracker.createInstance<InstructionContext>(_ctx, getState());
  enterRule(_localctx, 30, exprParser::RuleInstruction);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(183);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<InstructionContext *>(_tracker.createInstance<exprParser::IfInstrContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(155);
      match(exprParser::IF);
      setState(156);
      match(exprParser::T__0);
      setState(157);
      expression(0);
      setState(158);
      match(exprParser::T__1);
      setState(159);
      match(exprParser::T__3);
      setState(160);
      corps();
      setState(161);
      match(exprParser::T__4);
      setState(167);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == exprParser::ELSE) {
        setState(162);
        match(exprParser::ELSE);
        setState(163);
        match(exprParser::T__3);
        setState(164);
        corps();
        setState(165);
        match(exprParser::T__4);
      }
      break;
    }

    case 2: {
      _localctx = dynamic_cast<InstructionContext *>(_tracker.createInstance<exprParser::WhileInstrContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(169);
      match(exprParser::WHILE);
      setState(170);
      match(exprParser::T__0);
      setState(171);
      expression(0);
      setState(172);
      match(exprParser::T__1);
      setState(173);
      match(exprParser::T__3);
      setState(174);
      corps();
      setState(175);
      match(exprParser::T__4);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<InstructionContext *>(_tracker.createInstance<exprParser::InstrAffContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(177);
      affect();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<InstructionContext *>(_tracker.createInstance<exprParser::InstrDecContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(178);
      declare();
      break;
    }

    case 5: {
      _localctx = dynamic_cast<InstructionContext *>(_tracker.createInstance<exprParser::InstrExprContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(179);
      expression(0);
      setState(180);
      match(exprParser::T__14);
      break;
    }

    case 6: {
      _localctx = dynamic_cast<InstructionContext *>(_tracker.createInstance<exprParser::InstrRetContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(182);
      ret();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CorpsContext ------------------------------------------------------------------

exprParser::CorpsContext::CorpsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t exprParser::CorpsContext::getRuleIndex() const {
  return exprParser::RuleCorps;
}

void exprParser::CorpsContext::copyFrom(CorpsContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- InstrCorpsContext ------------------------------------------------------------------

exprParser::InstructionContext* exprParser::InstrCorpsContext::instruction() {
  return getRuleContext<exprParser::InstructionContext>(0);
}

exprParser::CorpsContext* exprParser::InstrCorpsContext::corps() {
  return getRuleContext<exprParser::CorpsContext>(0);
}

exprParser::InstrCorpsContext::InstrCorpsContext(CorpsContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::InstrCorpsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitInstrCorps(this);
  else
    return visitor->visitChildren(this);
}
//----------------- InstrContext ------------------------------------------------------------------

exprParser::InstructionContext* exprParser::InstrContext::instruction() {
  return getRuleContext<exprParser::InstructionContext>(0);
}

exprParser::InstrContext::InstrContext(CorpsContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::InstrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitInstr(this);
  else
    return visitor->visitChildren(this);
}
exprParser::CorpsContext* exprParser::corps() {
  CorpsContext *_localctx = _tracker.createInstance<CorpsContext>(_ctx, getState());
  enterRule(_localctx, 32, exprParser::RuleCorps);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(189);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<CorpsContext *>(_tracker.createInstance<exprParser::InstrContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(185);
      instruction();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<CorpsContext *>(_tracker.createInstance<exprParser::InstrCorpsContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(186);
      instruction();
      setState(187);
      corps();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool exprParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 9: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool exprParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 7);
    case 1: return precpred(_ctx, 5);
    case 2: return precpred(_ctx, 4);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> exprParser::_decisionToDFA;
atn::PredictionContextCache exprParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN exprParser::_atn;
std::vector<uint16_t> exprParser::_serializedATN;

std::vector<std::string> exprParser::_ruleNames = {
  "fichier", "programme", "appel", "vars", "function", "defAppel", "typefct", 
  "type", "right", "expression", "left", "declare", "ids", "affect", "ret", 
  "instruction", "corps"
};

std::vector<std::string> exprParser::_literalNames = {
  "", "'('", "')'", "','", "'{'", "'}'", "'*'", "'-'", "'+'", "'=='", "'<'", 
  "'<='", "'>='", "'>'", "'!='", "';'", "'='", "'void'", "'int'", "'char'", 
  "", "'return'", "'if'", "'else'", "'while'"
};

std::vector<std::string> exprParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "VOID", 
  "INT", "CHAR", "NBR", "RETURN", "IF", "ELSE", "WHILE", "ID", "CARACTERE", 
  "WS"
};

dfa::Vocabulary exprParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> exprParser::_tokenNames;

exprParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x1d, 0xc2, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x5, 0x3, 0x2b, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x35, 0xa, 0x4, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x3c, 0xa, 0x5, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x4f, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 
    0x59, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x5d, 0xa, 0x8, 0x3, 0x9, 
    0x3, 0x9, 0x5, 0x9, 0x61, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 
    0xa, 0x66, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x71, 0xa, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x7, 0xb, 0x7c, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x7f, 0xb, 
    0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x8b, 0xa, 0xe, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0x98, 0xa, 0xf, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x5, 0x11, 0xaa, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xba, 
    0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0xc0, 
    0xa, 0x12, 0x3, 0x12, 0x2, 0x3, 0x14, 0x13, 0x2, 0x4, 0x6, 0x8, 0xa, 
    0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 
    0x2, 0x4, 0x3, 0x2, 0x9, 0xa, 0x3, 0x2, 0xb, 0x10, 0x2, 0xc8, 0x2, 0x24, 
    0x3, 0x2, 0x2, 0x2, 0x4, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x6, 0x34, 0x3, 0x2, 
    0x2, 0x2, 0x8, 0x3b, 0x3, 0x2, 0x2, 0x2, 0xa, 0x4e, 0x3, 0x2, 0x2, 0x2, 
    0xc, 0x58, 0x3, 0x2, 0x2, 0x2, 0xe, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x10, 
    0x60, 0x3, 0x2, 0x2, 0x2, 0x12, 0x65, 0x3, 0x2, 0x2, 0x2, 0x14, 0x70, 
    0x3, 0x2, 0x2, 0x2, 0x16, 0x80, 0x3, 0x2, 0x2, 0x2, 0x18, 0x82, 0x3, 
    0x2, 0x2, 0x2, 0x1a, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x97, 0x3, 0x2, 
    0x2, 0x2, 0x1e, 0x99, 0x3, 0x2, 0x2, 0x2, 0x20, 0xb9, 0x3, 0x2, 0x2, 
    0x2, 0x22, 0xbf, 0x3, 0x2, 0x2, 0x2, 0x24, 0x25, 0x5, 0x4, 0x3, 0x2, 
    0x25, 0x3, 0x3, 0x2, 0x2, 0x2, 0x26, 0x27, 0x5, 0xa, 0x6, 0x2, 0x27, 
    0x28, 0x5, 0x4, 0x3, 0x2, 0x28, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x29, 0x2b, 
    0x5, 0xa, 0x6, 0x2, 0x2a, 0x26, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x29, 0x3, 
    0x2, 0x2, 0x2, 0x2b, 0x5, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2d, 0x7, 0x1b, 
    0x2, 0x2, 0x2d, 0x2e, 0x7, 0x3, 0x2, 0x2, 0x2e, 0x35, 0x7, 0x4, 0x2, 
    0x2, 0x2f, 0x30, 0x7, 0x1b, 0x2, 0x2, 0x30, 0x31, 0x7, 0x3, 0x2, 0x2, 
    0x31, 0x32, 0x5, 0x8, 0x5, 0x2, 0x32, 0x33, 0x7, 0x4, 0x2, 0x2, 0x33, 
    0x35, 0x3, 0x2, 0x2, 0x2, 0x34, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x34, 0x2f, 
    0x3, 0x2, 0x2, 0x2, 0x35, 0x7, 0x3, 0x2, 0x2, 0x2, 0x36, 0x3c, 0x5, 
    0x14, 0xb, 0x2, 0x37, 0x38, 0x5, 0x14, 0xb, 0x2, 0x38, 0x39, 0x7, 0x5, 
    0x2, 0x2, 0x39, 0x3a, 0x5, 0x8, 0x5, 0x2, 0x3a, 0x3c, 0x3, 0x2, 0x2, 
    0x2, 0x3b, 0x36, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x37, 0x3, 0x2, 0x2, 0x2, 
    0x3c, 0x9, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3e, 0x5, 0xe, 0x8, 0x2, 0x3e, 
    0x3f, 0x7, 0x1b, 0x2, 0x2, 0x3f, 0x40, 0x7, 0x3, 0x2, 0x2, 0x40, 0x41, 
    0x5, 0xc, 0x7, 0x2, 0x41, 0x42, 0x7, 0x4, 0x2, 0x2, 0x42, 0x43, 0x7, 
    0x6, 0x2, 0x2, 0x43, 0x44, 0x5, 0x22, 0x12, 0x2, 0x44, 0x45, 0x7, 0x7, 
    0x2, 0x2, 0x45, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x46, 0x47, 0x5, 0xe, 0x8, 
    0x2, 0x47, 0x48, 0x7, 0x1b, 0x2, 0x2, 0x48, 0x49, 0x7, 0x3, 0x2, 0x2, 
    0x49, 0x4a, 0x7, 0x4, 0x2, 0x2, 0x4a, 0x4b, 0x7, 0x6, 0x2, 0x2, 0x4b, 
    0x4c, 0x5, 0x22, 0x12, 0x2, 0x4c, 0x4d, 0x7, 0x7, 0x2, 0x2, 0x4d, 0x4f, 
    0x3, 0x2, 0x2, 0x2, 0x4e, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x46, 0x3, 
    0x2, 0x2, 0x2, 0x4f, 0xb, 0x3, 0x2, 0x2, 0x2, 0x50, 0x51, 0x5, 0x10, 
    0x9, 0x2, 0x51, 0x52, 0x7, 0x1b, 0x2, 0x2, 0x52, 0x59, 0x3, 0x2, 0x2, 
    0x2, 0x53, 0x54, 0x5, 0x10, 0x9, 0x2, 0x54, 0x55, 0x7, 0x1b, 0x2, 0x2, 
    0x55, 0x56, 0x7, 0x5, 0x2, 0x2, 0x56, 0x57, 0x5, 0xc, 0x7, 0x2, 0x57, 
    0x59, 0x3, 0x2, 0x2, 0x2, 0x58, 0x50, 0x3, 0x2, 0x2, 0x2, 0x58, 0x53, 
    0x3, 0x2, 0x2, 0x2, 0x59, 0xd, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5d, 0x7, 
    0x14, 0x2, 0x2, 0x5b, 0x5d, 0x7, 0x13, 0x2, 0x2, 0x5c, 0x5a, 0x3, 0x2, 
    0x2, 0x2, 0x5c, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5d, 0xf, 0x3, 0x2, 0x2, 
    0x2, 0x5e, 0x61, 0x7, 0x14, 0x2, 0x2, 0x5f, 0x61, 0x7, 0x15, 0x2, 0x2, 
    0x60, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x60, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x61, 
    0x11, 0x3, 0x2, 0x2, 0x2, 0x62, 0x66, 0x7, 0x1b, 0x2, 0x2, 0x63, 0x66, 
    0x7, 0x16, 0x2, 0x2, 0x64, 0x66, 0x7, 0x1c, 0x2, 0x2, 0x65, 0x62, 0x3, 
    0x2, 0x2, 0x2, 0x65, 0x63, 0x3, 0x2, 0x2, 0x2, 0x65, 0x64, 0x3, 0x2, 
    0x2, 0x2, 0x66, 0x13, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0x8, 0xb, 0x1, 
    0x2, 0x68, 0x69, 0x7, 0x9, 0x2, 0x2, 0x69, 0x71, 0x5, 0x14, 0xb, 0x8, 
    0x6a, 0x6b, 0x7, 0x3, 0x2, 0x2, 0x6b, 0x6c, 0x5, 0x14, 0xb, 0x2, 0x6c, 
    0x6d, 0x7, 0x4, 0x2, 0x2, 0x6d, 0x71, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x71, 
    0x5, 0x12, 0xa, 0x2, 0x6f, 0x71, 0x5, 0x6, 0x4, 0x2, 0x70, 0x67, 0x3, 
    0x2, 0x2, 0x2, 0x70, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x70, 0x6e, 0x3, 0x2, 
    0x2, 0x2, 0x70, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x71, 0x7d, 0x3, 0x2, 0x2, 
    0x2, 0x72, 0x73, 0xc, 0x9, 0x2, 0x2, 0x73, 0x74, 0x7, 0x8, 0x2, 0x2, 
    0x74, 0x7c, 0x5, 0x14, 0xb, 0xa, 0x75, 0x76, 0xc, 0x7, 0x2, 0x2, 0x76, 
    0x77, 0x9, 0x2, 0x2, 0x2, 0x77, 0x7c, 0x5, 0x14, 0xb, 0x8, 0x78, 0x79, 
    0xc, 0x6, 0x2, 0x2, 0x79, 0x7a, 0x9, 0x3, 0x2, 0x2, 0x7a, 0x7c, 0x5, 
    0x14, 0xb, 0x7, 0x7b, 0x72, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x75, 0x3, 0x2, 
    0x2, 0x2, 0x7b, 0x78, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7f, 0x3, 0x2, 0x2, 
    0x2, 0x7d, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7e, 0x3, 0x2, 0x2, 0x2, 
    0x7e, 0x15, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x80, 
    0x81, 0x7, 0x1b, 0x2, 0x2, 0x81, 0x17, 0x3, 0x2, 0x2, 0x2, 0x82, 0x83, 
    0x5, 0x10, 0x9, 0x2, 0x83, 0x84, 0x5, 0x1a, 0xe, 0x2, 0x84, 0x85, 0x7, 
    0x11, 0x2, 0x2, 0x85, 0x19, 0x3, 0x2, 0x2, 0x2, 0x86, 0x8b, 0x7, 0x1b, 
    0x2, 0x2, 0x87, 0x88, 0x7, 0x1b, 0x2, 0x2, 0x88, 0x89, 0x7, 0x5, 0x2, 
    0x2, 0x89, 0x8b, 0x5, 0x1a, 0xe, 0x2, 0x8a, 0x86, 0x3, 0x2, 0x2, 0x2, 
    0x8a, 0x87, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x8c, 
    0x8d, 0x5, 0x10, 0x9, 0x2, 0x8d, 0x8e, 0x5, 0x16, 0xc, 0x2, 0x8e, 0x8f, 
    0x7, 0x12, 0x2, 0x2, 0x8f, 0x90, 0x5, 0x14, 0xb, 0x2, 0x90, 0x91, 0x7, 
    0x11, 0x2, 0x2, 0x91, 0x98, 0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 0x5, 0x16, 
    0xc, 0x2, 0x93, 0x94, 0x7, 0x12, 0x2, 0x2, 0x94, 0x95, 0x5, 0x14, 0xb, 
    0x2, 0x95, 0x96, 0x7, 0x11, 0x2, 0x2, 0x96, 0x98, 0x3, 0x2, 0x2, 0x2, 
    0x97, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x97, 0x92, 0x3, 0x2, 0x2, 0x2, 0x98, 
    0x1d, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9a, 0x7, 0x17, 0x2, 0x2, 0x9a, 0x9b, 
    0x5, 0x14, 0xb, 0x2, 0x9b, 0x9c, 0x7, 0x11, 0x2, 0x2, 0x9c, 0x1f, 0x3, 
    0x2, 0x2, 0x2, 0x9d, 0x9e, 0x7, 0x18, 0x2, 0x2, 0x9e, 0x9f, 0x7, 0x3, 
    0x2, 0x2, 0x9f, 0xa0, 0x5, 0x14, 0xb, 0x2, 0xa0, 0xa1, 0x7, 0x4, 0x2, 
    0x2, 0xa1, 0xa2, 0x7, 0x6, 0x2, 0x2, 0xa2, 0xa3, 0x5, 0x22, 0x12, 0x2, 
    0xa3, 0xa9, 0x7, 0x7, 0x2, 0x2, 0xa4, 0xa5, 0x7, 0x19, 0x2, 0x2, 0xa5, 
    0xa6, 0x7, 0x6, 0x2, 0x2, 0xa6, 0xa7, 0x5, 0x22, 0x12, 0x2, 0xa7, 0xa8, 
    0x7, 0x7, 0x2, 0x2, 0xa8, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xa4, 0x3, 
    0x2, 0x2, 0x2, 0xa9, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xba, 0x3, 0x2, 
    0x2, 0x2, 0xab, 0xac, 0x7, 0x1a, 0x2, 0x2, 0xac, 0xad, 0x7, 0x3, 0x2, 
    0x2, 0xad, 0xae, 0x5, 0x14, 0xb, 0x2, 0xae, 0xaf, 0x7, 0x4, 0x2, 0x2, 
    0xaf, 0xb0, 0x7, 0x6, 0x2, 0x2, 0xb0, 0xb1, 0x5, 0x22, 0x12, 0x2, 0xb1, 
    0xb2, 0x7, 0x7, 0x2, 0x2, 0xb2, 0xba, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xba, 
    0x5, 0x1c, 0xf, 0x2, 0xb4, 0xba, 0x5, 0x18, 0xd, 0x2, 0xb5, 0xb6, 0x5, 
    0x14, 0xb, 0x2, 0xb6, 0xb7, 0x7, 0x11, 0x2, 0x2, 0xb7, 0xba, 0x3, 0x2, 
    0x2, 0x2, 0xb8, 0xba, 0x5, 0x1e, 0x10, 0x2, 0xb9, 0x9d, 0x3, 0x2, 0x2, 
    0x2, 0xb9, 0xab, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xb3, 0x3, 0x2, 0x2, 0x2, 
    0xb9, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xb9, 
    0xb8, 0x3, 0x2, 0x2, 0x2, 0xba, 0x21, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xc0, 
    0x5, 0x20, 0x11, 0x2, 0xbc, 0xbd, 0x5, 0x20, 0x11, 0x2, 0xbd, 0xbe, 
    0x5, 0x22, 0x12, 0x2, 0xbe, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xbb, 0x3, 
    0x2, 0x2, 0x2, 0xbf, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xc0, 0x23, 0x3, 0x2, 
    0x2, 0x2, 0x12, 0x2a, 0x34, 0x3b, 0x4e, 0x58, 0x5c, 0x60, 0x65, 0x70, 
    0x7b, 0x7d, 0x8a, 0x97, 0xa9, 0xb9, 0xbf, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

exprParser::Initializer exprParser::_init;
