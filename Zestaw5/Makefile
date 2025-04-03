GXX = g++
GXXFLAGS = -Wall -std=c++17

.SUFFIXES = .cpp .h

cw1: main.cpp doublelist.h
	@$(GXX) $(GXXFLAGS) -o cw1 main.cpp

run: cw1
	@./cw1

clean:
	@rm -f cw1
