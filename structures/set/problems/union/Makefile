CXX=g++
CPPFLAGS=-std=gnu++0x -Wall -g 
union: union.cpp
	$(CXX) $(CPPFLAGS) $^ -o union.exe
test: union
	bats -t union.bats
clean:
	-rm union.exe
