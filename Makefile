#ronen.chereshn@msmail.ariel.ac.il

CXX = g++
CXXFLAGS = -std=c++17 -Wall -g
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRC = main.cpp \
      Player.cpp \
      GameRules.cpp \
      BoardGame.cpp \
      RolesC/Baron.cpp \
      RolesC/General.cpp \
      RolesC/Governor.cpp \
      RolesC/Judge.cpp \
      RolesC/Merchant.cpp \
      RolesC/Spy.cpp \
      display/Gui.cpp

OBJ = $(SRC:.cpp=.o)
EXEC = game

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

Main: $(EXEC)
	./$(EXEC)

clean:
	rm -f $(OBJ) $(EXEC)

rebuild: clean all

.PHONY: all clean rebuild Main
