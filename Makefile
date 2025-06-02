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

TEST_SRC = tests/Test.cpp
TEST_OBJ = $(TEST_SRC:.cpp=.o)
TEST_EXEC = test_game

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

Main: $(EXEC)
	./$(EXEC)

test: $(TEST_EXEC)
	./$(TEST_EXEC)

$(TEST_EXEC): $(TEST_OBJ) $(filter-out main.o,$(OBJ))
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

valgrind: $(EXEC)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(EXEC)

valgrind-test: $(TEST_EXEC)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TEST_EXEC)

clean:
	rm -f $(OBJ) $(EXEC) $(TEST_OBJ) $(TEST_EXEC)

rebuild: clean all