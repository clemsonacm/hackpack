CXX=g++
CPPFLAGS=-g -Wall -std=gnu++0x
all: graph-test.exe
%.exe: %.cpp
	$(CXX) $(CPPFLAGS) -o $@ $^
test: all
	./graph-test.exe < graph-test.in
clean:
	-rm *.o graph-test.exe

