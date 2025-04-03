CXX = g++

CXXFLAGS = -Wall -std=c++11

.SUFFIXES = .cpp .h

.PHONY: run clean cw1

cw1: quick.h main.cpp
	@$(CXX) $(CXXFLAGS) -o cw1 main.cpp

run: cw1
	@./cw1

clean:
	@rm -f cw1 
