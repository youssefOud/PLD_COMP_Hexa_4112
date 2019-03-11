
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


//----------------- ProgContext ------------------------------------------------------------------

exprParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

exprParser::TypeContext* exprParser::ProgContext::type() {
  return getRuleContext<exprParser::TypeContext>(0);
}

exprParser::PrContext* exprParser::ProgContext::pr() {
  return getRuleContext<exprParser::PrContext>(0);
}


size_t exprParser::ProgContext::getRuleIndex() const {
  return exprParser::RuleProg;
}

antlrcpp::Any exprParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

exprParser::ProgContext* exprParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, exprParser::RuleProg);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(12);
    type();
    setState(13);
    match(exprParser::T__0);
    setState(14);
    match(exprParser::T__1);
    setState(15);
    match(exprParser::T__2);
    setState(16);
    match(exprParser::T__3);
    setState(17);
    pr();
    setState(18);
    match(exprParser::T__4);
   
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
    setState(20);
    match(exprParser::INT);
   
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

//----------------- NomfctContext ------------------------------------------------------------------

tree::TerminalNode* exprParser::NomfctContext::ID() {
  return getToken(exprParser::ID, 0);
}

exprParser::NomfctContext::NomfctContext(FunctionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::NomfctContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitNomfct(this);
  else
    return visitor->visitChildren(this);
}
exprParser::FunctionContext* exprParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 4, exprParser::RuleFunction);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<FunctionContext *>(_tracker.createInstance<exprParser::NomfctContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(22);
    match(exprParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrContext ------------------------------------------------------------------

exprParser::PrContext::PrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t exprParser::PrContext::getRuleIndex() const {
  return exprParser::RulePr;
}

void exprParser::PrContext::copyFrom(PrContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- InstructionContext ------------------------------------------------------------------

exprParser::RetContext* exprParser::InstructionContext::ret() {
  return getRuleContext<exprParser::RetContext>(0);
}

exprParser::ExprContext* exprParser::InstructionContext::expr() {
  return getRuleContext<exprParser::ExprContext>(0);
}

exprParser::InstructionContext::InstructionContext(PrContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::InstructionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitInstruction(this);
  else
    return visitor->visitChildren(this);
}
exprParser::PrContext* exprParser::pr() {
  PrContext *_localctx = _tracker.createInstance<PrContext>(_ctx, getState());
  enterRule(_localctx, 6, exprParser::RulePr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<PrContext *>(_tracker.createInstance<exprParser::InstructionContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(24);
    ret();
    setState(25);
    expr();
    setState(26);
    match(exprParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

exprParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t exprParser::ExprContext::getRuleIndex() const {
  return exprParser::RuleExpr;
}

void exprParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- NombreContext ------------------------------------------------------------------

tree::TerminalNode* exprParser::NombreContext::NBR() {
  return getToken(exprParser::NBR, 0);
}

exprParser::NombreContext::NombreContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::NombreContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitNombre(this);
  else
    return visitor->visitChildren(this);
}
exprParser::ExprContext* exprParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 8, exprParser::RuleExpr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<ExprContext *>(_tracker.createInstance<exprParser::NombreContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(28);
    match(exprParser::NBR);
   
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

antlrcpp::Any exprParser::RetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitRet(this);
  else
    return visitor->visitChildren(this);
}

exprParser::RetContext* exprParser::ret() {
  RetContext *_localctx = _tracker.createInstance<RetContext>(_ctx, getState());
  enterRule(_localctx, 10, exprParser::RuleRet);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(30);
    match(exprParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> exprParser::_decisionToDFA;
atn::PredictionContextCache exprParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN exprParser::_atn;
std::vector<uint16_t> exprParser::_serializedATN;

std::vector<std::string> exprParser::_ruleNames = {
  "prog", "type", "function", "pr", "expr", "ret"
};

std::vector<std::string> exprParser::_literalNames = {
  "", "'main'", "'('", "')'", "'{'", "'}'", "';'", "'return'", "'int'"
};

std::vector<std::string> exprParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "INT", "NBR", "ID", "WS"
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
    0x3, 0xd, 0x23, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x2, 
    0x2, 0x8, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0x2, 0x2, 0x2, 0x1c, 0x2, 0xe, 
    0x3, 0x2, 0x2, 0x2, 0x4, 0x16, 0x3, 0x2, 0x2, 0x2, 0x6, 0x18, 0x3, 0x2, 
    0x2, 0x2, 0x8, 0x1a, 0x3, 0x2, 0x2, 0x2, 0xa, 0x1e, 0x3, 0x2, 0x2, 0x2, 
    0xc, 0x20, 0x3, 0x2, 0x2, 0x2, 0xe, 0xf, 0x5, 0x4, 0x3, 0x2, 0xf, 0x10, 
    0x7, 0x3, 0x2, 0x2, 0x10, 0x11, 0x7, 0x4, 0x2, 0x2, 0x11, 0x12, 0x7, 
    0x5, 0x2, 0x2, 0x12, 0x13, 0x7, 0x6, 0x2, 0x2, 0x13, 0x14, 0x5, 0x8, 
    0x5, 0x2, 0x14, 0x15, 0x7, 0x7, 0x2, 0x2, 0x15, 0x3, 0x3, 0x2, 0x2, 
    0x2, 0x16, 0x17, 0x7, 0xa, 0x2, 0x2, 0x17, 0x5, 0x3, 0x2, 0x2, 0x2, 
    0x18, 0x19, 0x7, 0xc, 0x2, 0x2, 0x19, 0x7, 0x3, 0x2, 0x2, 0x2, 0x1a, 
    0x1b, 0x5, 0xc, 0x7, 0x2, 0x1b, 0x1c, 0x5, 0xa, 0x6, 0x2, 0x1c, 0x1d, 
    0x7, 0x8, 0x2, 0x2, 0x1d, 0x9, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x1f, 0x7, 
    0xb, 0x2, 0x2, 0x1f, 0xb, 0x3, 0x2, 0x2, 0x2, 0x20, 0x21, 0x7, 0x9, 
    0x2, 0x2, 0x21, 0xd, 0x3, 0x2, 0x2, 0x2, 0x2, 
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
