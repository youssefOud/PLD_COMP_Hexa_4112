
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


size_t exprParser::ProgContext::getRuleIndex() const {
  return exprParser::RuleProg;
}

void exprParser::ProgContext::copyFrom(ProgContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ProggeneralContext ------------------------------------------------------------------

exprParser::TypeContext* exprParser::ProggeneralContext::type() {
  return getRuleContext<exprParser::TypeContext>(0);
}

exprParser::NomfonctionContext* exprParser::ProggeneralContext::nomfonction() {
  return getRuleContext<exprParser::NomfonctionContext>(0);
}

exprParser::CodeContext* exprParser::ProggeneralContext::code() {
  return getRuleContext<exprParser::CodeContext>(0);
}

exprParser::ProggeneralContext::ProggeneralContext(ProgContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::ProggeneralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitProggeneral(this);
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
    _localctx = dynamic_cast<ProgContext *>(_tracker.createInstance<exprParser::ProggeneralContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(8);
    type();
    setState(9);
    nomfonction();
    setState(10);
    match(exprParser::T__0);
    setState(11);
    match(exprParser::T__1);
    setState(12);
    code();
    setState(13);
    match(exprParser::T__2);
   
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

//----------------- TypevarContext ------------------------------------------------------------------

exprParser::TypevarContext::TypevarContext(TypeContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::TypevarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitTypevar(this);
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
    _localctx = dynamic_cast<TypeContext *>(_tracker.createInstance<exprParser::TypevarContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(15);
    match(exprParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NomfonctionContext ------------------------------------------------------------------

exprParser::NomfonctionContext::NomfonctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t exprParser::NomfonctionContext::getRuleIndex() const {
  return exprParser::RuleNomfonction;
}

void exprParser::NomfonctionContext::copyFrom(NomfonctionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- NomContext ------------------------------------------------------------------

tree::TerminalNode* exprParser::NomContext::NOM() {
  return getToken(exprParser::NOM, 0);
}

exprParser::NomContext::NomContext(NomfonctionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::NomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitNom(this);
  else
    return visitor->visitChildren(this);
}
exprParser::NomfonctionContext* exprParser::nomfonction() {
  NomfonctionContext *_localctx = _tracker.createInstance<NomfonctionContext>(_ctx, getState());
  enterRule(_localctx, 4, exprParser::RuleNomfonction);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<NomfonctionContext *>(_tracker.createInstance<exprParser::NomContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(17);
    match(exprParser::NOM);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CodeContext ------------------------------------------------------------------

exprParser::CodeContext::CodeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t exprParser::CodeContext::getRuleIndex() const {
  return exprParser::RuleCode;
}

void exprParser::CodeContext::copyFrom(CodeContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- CodefonctionContext ------------------------------------------------------------------

tree::TerminalNode* exprParser::CodefonctionContext::INT() {
  return getToken(exprParser::INT, 0);
}

exprParser::CodefonctionContext::CodefonctionContext(CodeContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::CodefonctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitCodefonction(this);
  else
    return visitor->visitChildren(this);
}
exprParser::CodeContext* exprParser::code() {
  CodeContext *_localctx = _tracker.createInstance<CodeContext>(_ctx, getState());
  enterRule(_localctx, 6, exprParser::RuleCode);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<CodeContext *>(_tracker.createInstance<exprParser::CodefonctionContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(19);
    match(exprParser::T__4);
    setState(20);
    match(exprParser::INT);
    setState(21);
    match(exprParser::T__5);
   
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
  "prog", "type", "nomfonction", "code"
};

std::vector<std::string> exprParser::_literalNames = {
  "", "'()'", "'{'", "'}'", "'int'", "'return'", "';'"
};

std::vector<std::string> exprParser::_symbolicNames = {
  "", "", "", "", "", "", "", "WS", "INT", "NOM"
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
    0x3, 0xb, 0x1a, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x2, 0x2, 0x6, 0x2, 0x4, 
    0x6, 0x8, 0x2, 0x2, 0x2, 0x15, 0x2, 0xa, 0x3, 0x2, 0x2, 0x2, 0x4, 0x11, 
    0x3, 0x2, 0x2, 0x2, 0x6, 0x13, 0x3, 0x2, 0x2, 0x2, 0x8, 0x15, 0x3, 0x2, 
    0x2, 0x2, 0xa, 0xb, 0x5, 0x4, 0x3, 0x2, 0xb, 0xc, 0x5, 0x6, 0x4, 0x2, 
    0xc, 0xd, 0x7, 0x3, 0x2, 0x2, 0xd, 0xe, 0x7, 0x4, 0x2, 0x2, 0xe, 0xf, 
    0x5, 0x8, 0x5, 0x2, 0xf, 0x10, 0x7, 0x5, 0x2, 0x2, 0x10, 0x3, 0x3, 0x2, 
    0x2, 0x2, 0x11, 0x12, 0x7, 0x6, 0x2, 0x2, 0x12, 0x5, 0x3, 0x2, 0x2, 
    0x2, 0x13, 0x14, 0x7, 0xb, 0x2, 0x2, 0x14, 0x7, 0x3, 0x2, 0x2, 0x2, 
    0x15, 0x16, 0x7, 0x7, 0x2, 0x2, 0x16, 0x17, 0x7, 0xa, 0x2, 0x2, 0x17, 
    0x18, 0x7, 0x8, 0x2, 0x2, 0x18, 0x9, 0x3, 0x2, 0x2, 0x2, 0x2, 
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
