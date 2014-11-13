CXX=g++
CPPFLAGS=-g -Wall -std=gnu++0x
test: graph.o graph-test.o
	$(CXX) $(CPPFLAGS) $^ -o graph-test.exe
	./graph-test.exe
clean:
	-rm *.o graph-test.exe

