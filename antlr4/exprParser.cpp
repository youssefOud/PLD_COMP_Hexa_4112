
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


//----------------- FunctionContext ------------------------------------------------------------------

exprParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

exprParser::TypeContext* exprParser::FunctionContext::type() {
  return getRuleContext<exprParser::TypeContext>(0);
}

tree::TerminalNode* exprParser::FunctionContext::ID() {
  return getToken(exprParser::ID, 0);
}

exprParser::CorpsContext* exprParser::FunctionContext::corps() {
  return getRuleContext<exprParser::CorpsContext>(0);
}


size_t exprParser::FunctionContext::getRuleIndex() const {
  return exprParser::RuleFunction;
}

antlrcpp::Any exprParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitFunction(this);
  else
    return visitor->visitChildren(this);
}

exprParser::FunctionContext* exprParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 0, exprParser::RuleFunction);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(20);
    type();
    setState(21);
    match(exprParser::ID);
    setState(22);
    match(exprParser::T__0);
    setState(23);
    match(exprParser::T__1);
    setState(24);
    match(exprParser::T__2);
    setState(25);
    corps(0);
    setState(26);
    match(exprParser::T__3);
   
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

//----------------- TypefctContext ------------------------------------------------------------------

tree::TerminalNode* exprParser::TypefctContext::INT() {
  return getToken(exprParser::INT, 0);
}

exprParser::TypefctContext::TypefctContext(TypeContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::TypefctContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitTypefct(this);
  else
    return visitor->visitChildren(this);
}
exprParser::TypeContext* exprParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 2, exprParser::RuleType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<TypeContext *>(_tracker.createInstance<exprParser::TypefctContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(28);
    match(exprParser::INT);
   
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
exprParser::RightContext* exprParser::right() {
  RightContext *_localctx = _tracker.createInstance<RightContext>(_ctx, getState());
  enterRule(_localctx, 4, exprParser::RuleRight);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(32);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case exprParser::ID: {
        _localctx = dynamic_cast<RightContext *>(_tracker.createInstance<exprParser::RightValueIDContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(30);
        match(exprParser::ID);
        break;
      }

      case exprParser::NBR: {
        _localctx = dynamic_cast<RightContext *>(_tracker.createInstance<exprParser::RightValueNBRContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(31);
        match(exprParser::NBR);
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
//----------------- ExprAddContext ------------------------------------------------------------------

std::vector<exprParser::ExpressionContext *> exprParser::ExprAddContext::expression() {
  return getRuleContexts<exprParser::ExpressionContext>();
}

exprParser::ExpressionContext* exprParser::ExprAddContext::expression(size_t i) {
  return getRuleContext<exprParser::ExpressionContext>(i);
}

exprParser::ExprAddContext::ExprAddContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::ExprAddContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitExprAdd(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprMinusContext ------------------------------------------------------------------

std::vector<exprParser::ExpressionContext *> exprParser::ExprMinusContext::expression() {
  return getRuleContexts<exprParser::ExpressionContext>();
}

exprParser::ExpressionContext* exprParser::ExprMinusContext::expression(size_t i) {
  return getRuleContext<exprParser::ExpressionContext>(i);
}

exprParser::ExprMinusContext::ExprMinusContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::ExprMinusContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitExprMinus(this);
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
  size_t startState = 6;
  enterRecursionRule(_localctx, 6, exprParser::RuleExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(40);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case exprParser::T__0: {
        _localctx = _tracker.createInstance<ExprParContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(35);
        match(exprParser::T__0);
        setState(36);
        expression(0);
        setState(37);
        match(exprParser::T__1);
        break;
      }

      case exprParser::NBR:
      case exprParser::ID: {
        _localctx = _tracker.createInstance<RightValueContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(39);
        right();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(53);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(51);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ExprMultContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(42);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");

          setState(43);
          match(exprParser::T__4);
          setState(44);
          expression(6);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ExprAddContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(45);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");

          setState(46);
          match(exprParser::T__5);
          setState(47);
          expression(5);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<ExprMinusContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(48);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");

          setState(49);
          match(exprParser::T__6);
          setState(50);
          expression(4);
          break;
        }

        } 
      }
      setState(55);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
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
  enterRule(_localctx, 8, exprParser::RuleLeft);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<LeftContext *>(_tracker.createInstance<exprParser::LeftValueContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(56);
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
  enterRule(_localctx, 10, exprParser::RuleDeclare);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<DeclareContext *>(_tracker.createInstance<exprParser::DeclarationContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(58);
    type();
    setState(59);
    ids();
    setState(60);
    match(exprParser::T__7);
   
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
  enterRule(_localctx, 12, exprParser::RuleIds);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(66);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<IdsContext *>(_tracker.createInstance<exprParser::SimpleIdContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(62);
      match(exprParser::ID);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<IdsContext *>(_tracker.createInstance<exprParser::MultipleIdContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(63);
      match(exprParser::ID);
      setState(64);
      match(exprParser::T__8);
      setState(65);
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
  enterRule(_localctx, 14, exprParser::RuleAffect);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(79);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case exprParser::INT: {
        _localctx = dynamic_cast<AffectContext *>(_tracker.createInstance<exprParser::DefinitionContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(68);
        type();
        setState(69);
        left();
        setState(70);
        match(exprParser::T__9);
        setState(71);
        expression(0);
        setState(72);
        match(exprParser::T__7);
        break;
      }

      case exprParser::ID: {
        _localctx = dynamic_cast<AffectContext *>(_tracker.createInstance<exprParser::AffectationContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(74);
        left();
        setState(75);
        match(exprParser::T__9);
        setState(76);
        expression(0);
        setState(77);
        match(exprParser::T__7);
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
  enterRule(_localctx, 16, exprParser::RuleRet);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<RetContext *>(_tracker.createInstance<exprParser::ReturnContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(81);
    match(exprParser::RETURN);
    setState(82);
    expression(0);
    setState(83);
    match(exprParser::T__7);
   
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

//----------------- CorpsAffectRetContext ------------------------------------------------------------------

exprParser::AffectContext* exprParser::CorpsAffectRetContext::affect() {
  return getRuleContext<exprParser::AffectContext>(0);
}

exprParser::RetContext* exprParser::CorpsAffectRetContext::ret() {
  return getRuleContext<exprParser::RetContext>(0);
}

exprParser::CorpsAffectRetContext::CorpsAffectRetContext(CorpsContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::CorpsAffectRetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitCorpsAffectRet(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CorpsRetourContext ------------------------------------------------------------------

exprParser::RetContext* exprParser::CorpsRetourContext::ret() {
  return getRuleContext<exprParser::RetContext>(0);
}

exprParser::CorpsRetourContext::CorpsRetourContext(CorpsContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::CorpsRetourContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitCorpsRetour(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CorpsDeclareRetContext ------------------------------------------------------------------

exprParser::DeclareContext* exprParser::CorpsDeclareRetContext::declare() {
  return getRuleContext<exprParser::DeclareContext>(0);
}

exprParser::RetContext* exprParser::CorpsDeclareRetContext::ret() {
  return getRuleContext<exprParser::RetContext>(0);
}

exprParser::CorpsDeclareRetContext::CorpsDeclareRetContext(CorpsContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::CorpsDeclareRetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitCorpsDeclareRet(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CorpsAffectContext ------------------------------------------------------------------

exprParser::AffectContext* exprParser::CorpsAffectContext::affect() {
  return getRuleContext<exprParser::AffectContext>(0);
}

exprParser::CorpsContext* exprParser::CorpsAffectContext::corps() {
  return getRuleContext<exprParser::CorpsContext>(0);
}

exprParser::CorpsAffectContext::CorpsAffectContext(CorpsContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::CorpsAffectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitCorpsAffect(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CorpsRecContext ------------------------------------------------------------------

exprParser::CorpsContext* exprParser::CorpsRecContext::corps() {
  return getRuleContext<exprParser::CorpsContext>(0);
}

exprParser::CorpsRecContext::CorpsRecContext(CorpsContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::CorpsRecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitCorpsRec(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CorpsDeclareContext ------------------------------------------------------------------

exprParser::DeclareContext* exprParser::CorpsDeclareContext::declare() {
  return getRuleContext<exprParser::DeclareContext>(0);
}

exprParser::CorpsContext* exprParser::CorpsDeclareContext::corps() {
  return getRuleContext<exprParser::CorpsContext>(0);
}

exprParser::CorpsDeclareContext::CorpsDeclareContext(CorpsContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::CorpsDeclareContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitCorpsDeclare(this);
  else
    return visitor->visitChildren(this);
}

exprParser::CorpsContext* exprParser::corps() {
   return corps(0);
}

exprParser::CorpsContext* exprParser::corps(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  exprParser::CorpsContext *_localctx = _tracker.createInstance<CorpsContext>(_ctx, parentState);
  exprParser::CorpsContext *previousContext = _localctx;
  size_t startState = 18;
  enterRecursionRule(_localctx, 18, exprParser::RuleCorps, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(99);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CorpsAffectRetContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(86);
      affect();
      setState(87);
      ret();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CorpsAffectContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(89);
      affect();
      setState(90);
      corps(5);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<CorpsDeclareRetContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(92);
      declare();
      setState(93);
      ret();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<CorpsDeclareContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(95);
      declare();
      setState(96);
      corps(3);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<CorpsRetourContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(98);
      ret();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(105);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<CorpsRecContext>(_tracker.createInstance<CorpsContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleCorps);
        setState(101);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(102);
        match(exprParser::T__7); 
      }
      setState(107);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
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
    case 3: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);
    case 9: return corpsSempred(dynamic_cast<CorpsContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool exprParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 5);
    case 1: return precpred(_ctx, 4);
    case 2: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool exprParser::corpsSempred(CorpsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 1);

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
  "function", "type", "right", "expression", "left", "declare", "ids", "affect", 
  "ret", "corps"
};

std::vector<std::string> exprParser::_literalNames = {
  "", "'('", "')'", "'{'", "'}'", "'*'", "'+'", "'-'", "';'", "','", "'='", 
  "'int'", "", "'return'"
};

std::vector<std::string> exprParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "INT", "NBR", "RETURN", "ID", 
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
    0x3, 0x11, 0x6f, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x23, 
    0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x5, 0x5, 0x2b, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x36, 0xa, 0x5, 
    0xc, 0x5, 0xe, 0x5, 0x39, 0xb, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 
    0x8, 0x45, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 
    0x52, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x66, 
    0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0x6a, 0xa, 0xb, 0xc, 0xb, 0xe, 
    0xb, 0x6d, 0xb, 0xb, 0x3, 0xb, 0x2, 0x4, 0x8, 0x14, 0xc, 0x2, 0x4, 0x6, 
    0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x2, 0x2, 0x2, 0x70, 0x2, 0x16, 
    0x3, 0x2, 0x2, 0x2, 0x4, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x6, 0x22, 0x3, 0x2, 
    0x2, 0x2, 0x8, 0x2a, 0x3, 0x2, 0x2, 0x2, 0xa, 0x3a, 0x3, 0x2, 0x2, 0x2, 
    0xc, 0x3c, 0x3, 0x2, 0x2, 0x2, 0xe, 0x44, 0x3, 0x2, 0x2, 0x2, 0x10, 
    0x51, 0x3, 0x2, 0x2, 0x2, 0x12, 0x53, 0x3, 0x2, 0x2, 0x2, 0x14, 0x65, 
    0x3, 0x2, 0x2, 0x2, 0x16, 0x17, 0x5, 0x4, 0x3, 0x2, 0x17, 0x18, 0x7, 
    0x10, 0x2, 0x2, 0x18, 0x19, 0x7, 0x3, 0x2, 0x2, 0x19, 0x1a, 0x7, 0x4, 
    0x2, 0x2, 0x1a, 0x1b, 0x7, 0x5, 0x2, 0x2, 0x1b, 0x1c, 0x5, 0x14, 0xb, 
    0x2, 0x1c, 0x1d, 0x7, 0x6, 0x2, 0x2, 0x1d, 0x3, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0x1f, 0x7, 0xd, 0x2, 0x2, 0x1f, 0x5, 0x3, 0x2, 0x2, 0x2, 0x20, 
    0x23, 0x7, 0x10, 0x2, 0x2, 0x21, 0x23, 0x7, 0xe, 0x2, 0x2, 0x22, 0x20, 
    0x3, 0x2, 0x2, 0x2, 0x22, 0x21, 0x3, 0x2, 0x2, 0x2, 0x23, 0x7, 0x3, 
    0x2, 0x2, 0x2, 0x24, 0x25, 0x8, 0x5, 0x1, 0x2, 0x25, 0x26, 0x7, 0x3, 
    0x2, 0x2, 0x26, 0x27, 0x5, 0x8, 0x5, 0x2, 0x27, 0x28, 0x7, 0x4, 0x2, 
    0x2, 0x28, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x29, 0x2b, 0x5, 0x6, 0x4, 0x2, 
    0x2a, 0x24, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x29, 0x3, 0x2, 0x2, 0x2, 0x2b, 
    0x37, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2d, 0xc, 0x7, 0x2, 0x2, 0x2d, 0x2e, 
    0x7, 0x7, 0x2, 0x2, 0x2e, 0x36, 0x5, 0x8, 0x5, 0x8, 0x2f, 0x30, 0xc, 
    0x6, 0x2, 0x2, 0x30, 0x31, 0x7, 0x8, 0x2, 0x2, 0x31, 0x36, 0x5, 0x8, 
    0x5, 0x7, 0x32, 0x33, 0xc, 0x5, 0x2, 0x2, 0x33, 0x34, 0x7, 0x9, 0x2, 
    0x2, 0x34, 0x36, 0x5, 0x8, 0x5, 0x6, 0x35, 0x2c, 0x3, 0x2, 0x2, 0x2, 
    0x35, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x35, 0x32, 0x3, 0x2, 0x2, 0x2, 0x36, 
    0x39, 0x3, 0x2, 0x2, 0x2, 0x37, 0x35, 0x3, 0x2, 0x2, 0x2, 0x37, 0x38, 
    0x3, 0x2, 0x2, 0x2, 0x38, 0x9, 0x3, 0x2, 0x2, 0x2, 0x39, 0x37, 0x3, 
    0x2, 0x2, 0x2, 0x3a, 0x3b, 0x7, 0x10, 0x2, 0x2, 0x3b, 0xb, 0x3, 0x2, 
    0x2, 0x2, 0x3c, 0x3d, 0x5, 0x4, 0x3, 0x2, 0x3d, 0x3e, 0x5, 0xe, 0x8, 
    0x2, 0x3e, 0x3f, 0x7, 0xa, 0x2, 0x2, 0x3f, 0xd, 0x3, 0x2, 0x2, 0x2, 
    0x40, 0x45, 0x7, 0x10, 0x2, 0x2, 0x41, 0x42, 0x7, 0x10, 0x2, 0x2, 0x42, 
    0x43, 0x7, 0xb, 0x2, 0x2, 0x43, 0x45, 0x5, 0xe, 0x8, 0x2, 0x44, 0x40, 
    0x3, 0x2, 0x2, 0x2, 0x44, 0x41, 0x3, 0x2, 0x2, 0x2, 0x45, 0xf, 0x3, 
    0x2, 0x2, 0x2, 0x46, 0x47, 0x5, 0x4, 0x3, 0x2, 0x47, 0x48, 0x5, 0xa, 
    0x6, 0x2, 0x48, 0x49, 0x7, 0xc, 0x2, 0x2, 0x49, 0x4a, 0x5, 0x8, 0x5, 
    0x2, 0x4a, 0x4b, 0x7, 0xa, 0x2, 0x2, 0x4b, 0x52, 0x3, 0x2, 0x2, 0x2, 
    0x4c, 0x4d, 0x5, 0xa, 0x6, 0x2, 0x4d, 0x4e, 0x7, 0xc, 0x2, 0x2, 0x4e, 
    0x4f, 0x5, 0x8, 0x5, 0x2, 0x4f, 0x50, 0x7, 0xa, 0x2, 0x2, 0x50, 0x52, 
    0x3, 0x2, 0x2, 0x2, 0x51, 0x46, 0x3, 0x2, 0x2, 0x2, 0x51, 0x4c, 0x3, 
    0x2, 0x2, 0x2, 0x52, 0x11, 0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0x7, 0xf, 
    0x2, 0x2, 0x54, 0x55, 0x5, 0x8, 0x5, 0x2, 0x55, 0x56, 0x7, 0xa, 0x2, 
    0x2, 0x56, 0x13, 0x3, 0x2, 0x2, 0x2, 0x57, 0x58, 0x8, 0xb, 0x1, 0x2, 
    0x58, 0x59, 0x5, 0x10, 0x9, 0x2, 0x59, 0x5a, 0x5, 0x12, 0xa, 0x2, 0x5a, 
    0x66, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5c, 0x5, 0x10, 0x9, 0x2, 0x5c, 0x5d, 
    0x5, 0x14, 0xb, 0x7, 0x5d, 0x66, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5f, 0x5, 
    0xc, 0x7, 0x2, 0x5f, 0x60, 0x5, 0x12, 0xa, 0x2, 0x60, 0x66, 0x3, 0x2, 
    0x2, 0x2, 0x61, 0x62, 0x5, 0xc, 0x7, 0x2, 0x62, 0x63, 0x5, 0x14, 0xb, 
    0x5, 0x63, 0x66, 0x3, 0x2, 0x2, 0x2, 0x64, 0x66, 0x5, 0x12, 0xa, 0x2, 
    0x65, 0x57, 0x3, 0x2, 0x2, 0x2, 0x65, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x65, 
    0x5e, 0x3, 0x2, 0x2, 0x2, 0x65, 0x61, 0x3, 0x2, 0x2, 0x2, 0x65, 0x64, 
    0x3, 0x2, 0x2, 0x2, 0x66, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0xc, 
    0x3, 0x2, 0x2, 0x68, 0x6a, 0x7, 0xa, 0x2, 0x2, 0x69, 0x67, 0x3, 0x2, 
    0x2, 0x2, 0x6a, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x69, 0x3, 0x2, 0x2, 
    0x2, 0x6b, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x15, 0x3, 0x2, 0x2, 0x2, 
    0x6d, 0x6b, 0x3, 0x2, 0x2, 0x2, 0xa, 0x22, 0x2a, 0x35, 0x37, 0x44, 0x51, 
    0x65, 0x6b, 
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
