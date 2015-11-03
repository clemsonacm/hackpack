CXX=g++
CPPFLAGS=-g -Wall -std=c++11
fine-print.exe: fine-print.cpp
	$(CXX) $(CPPFLAGS) $^ -o fine-print.exe
clean:
	-rm *.o *.exe
test: fine-print.exe
	./fine-print.bats
