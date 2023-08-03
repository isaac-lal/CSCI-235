CXX = g++
CXXFLAGS = -std=c++17 -g -Wall

SRC = '.'
EXEC = main

OBJ = Book.cpp Manual.cpp Novel.cpp Textbook.cpp main.cpp

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(SRC)/$@ $(OBJ)


clean:
	rm -rf $(EXEC)

rebuild: clean all