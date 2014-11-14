CXX=g++
CPPFLAGS=-g -Wall -std=c++11
fine-print: fine-print.o
	$(CXX) $(CPPFLAGS) $^ -o fine-print.exe
clean:
	-rm *.o *.exe
test: fine-print
	./fine-print.exe < fine-print-test.in
