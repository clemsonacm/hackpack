CXX=g++
all: largest-increassing.o
	$(CXX) $^ -o largest-increassing.exe
test: all
	./largest-increassing.exe < largest-increassing.in
	./largest-increassing.exe < largest-increassing-test.in
clean:
	-rm *.o *.exe
