CXX=g++
all: knapsack.o
	$(CXX) knapsack.o -o knapsack.exe
clean:
	rm *.o knapsack.exe
test: all
	./knapsack.bats
