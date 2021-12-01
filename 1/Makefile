CXX=g++
IDIR=
CXXFLAGS = -Wall -Wextra -Werror -pedantic --std=c++20 #-I$(IDIR)
LDFLAGS=
RM=rm

all: part1 part2

*.o: *.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

part1: part1.o common.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

part2: part2.o common.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

clean:
	$(RM) *.o part1 part2
