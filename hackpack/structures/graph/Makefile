CXX=g++
CPPFLAGS=-g -Wall -std=c++11
test: graph.o graph-test.o
	$(CXX) $(CPPFLAGS) $^ -o graph-test.exe
	./graph-test.exe
clean:
	-rm *.o graph-test.exe

