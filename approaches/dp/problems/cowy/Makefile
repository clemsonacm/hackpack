CXX=g++
all: cowy.o
	$(CXX) $^ -o cowy.exe
test: all
	./cowy.bats
clean:
	-rm *.o *.exe
