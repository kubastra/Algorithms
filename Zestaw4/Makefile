CXX = g++

CXXFLAGS = -Wall -std=c++11

.SUFFIXES = .h .cpp

.PHONY = clean run

cw1: singlelist.h main.cpp
	@$(CXX) $(CXXFLAGS) -o cw1 main.cpp

run: cw1
	@./cw1

clean:
	@rm -f cw1
