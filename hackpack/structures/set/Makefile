CXX=g++
CPPFLAGS=-Wall -g -std=gnu++0x
set: set.cpp
	$(CXX) $(CPPFLAGS) $^ -o set.exe
clean:
	-rm set.exe
test: set
	bats --tap ./set.bats 
