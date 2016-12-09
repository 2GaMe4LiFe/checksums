#School: c++14
#Home: c++1y

CFLAGS = -std=c++11
OBJ = checksums.cpp main.cpp file_utility.cpp
BIN = prog

prog : $(OBJ)
	g++ -o $(BIN) $(OBJ) $(CFLAGS)

clear:
	delete $(OBJ)
