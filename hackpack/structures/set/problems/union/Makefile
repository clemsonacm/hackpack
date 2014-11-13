CXX=g++
CPPFLAGS=-std=gnu++0x -Wall -g 
union: union.cpp
	$(CXX) $(CPPFLAGS) $^ -o union.exe
test: union
	./union.exe < union-test.in
	cat union-test.out
clean:
	-rm union.exe
