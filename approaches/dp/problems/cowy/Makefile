CXX=g++
all: cowy.o
	$(CXX) $^ -o cowy.exe
test: all
	./cowy.exe < cowy.in
	./cowy.exe < cowy-test.in
clean:
	-rm *.o *.exe
