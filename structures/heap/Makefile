CC=g++ -std=c++11
CXX=$(CC)
CXXFLAGS=-Wall -g

heap.exe: heap.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@
clean:
	$(RM) heap.exe
test: heap.exe
	./heap.bats
.PHONY: clean test
