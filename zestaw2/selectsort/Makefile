CXX = g++

CXXFLAGS = -Wall -std=c++11

.SUFFIXES = .cpp

.PHONY: run clean cw1

cw1: selectsort.h main.cpp
	@$(CXX) $(CXXFLAGS) -o cw1 main.cpp

run: cw1
	@./cw1

clean:
	@rm -f cw1 
