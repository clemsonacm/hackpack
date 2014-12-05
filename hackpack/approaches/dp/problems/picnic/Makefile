CXX=g++
CXXFLAGS=-std=gnu++0x
all: picnic.o
	$(CXX) $^ -o picnic.exe
test: all
	./picnic.exe < picnic.in
clean:
	-rm picnic.exe *.o
