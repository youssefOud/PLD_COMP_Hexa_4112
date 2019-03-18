#Makefile generique
#Outils
CXX=g++
LD=g++
RM=rm
ECHO=echo

#Options
CXXFLAGS=-std=c++11
LDFLAGS=
RMFLAGS=-rf

#Fichiers
HEAD=$(wildcard *.h)
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
LIBS=

#Cibles speciales
BIN=Diagnostic
CLEAN=clean
.PHONY: $(CLEAN) $(RUN)

#Cibles
$(BIN): $(OBJ)
	@$(ECHO) Edition des liens
	@$(LD) $(LDFLAGS) $^ -o $@ $(LIBS)

$(CLEAN):
	@$(RM) $(RMFLAGS) $(BIN) $(OBJ)

#Dependances complementaires

#Regles d'inference
%.o: %.cpp
	@$(ECHO) Compilation de $<
	@$(CXX) $(CXXFLAGS) -c $< -o $@

#Dependances supplementaires
Empreinte.o: Attribut.h
Interface.o: Resultat.h Empreinte.h Attribut.h