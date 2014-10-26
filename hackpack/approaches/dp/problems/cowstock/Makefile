CXX=g++
CPPFLAGS=-std=c++11
all: cowstock.o
	$(CXX) $^ -o cowstock.exe
clean:
	rm *.o *.exe
test: all
	./cowstock.exe < cowstock.in
