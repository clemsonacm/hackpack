all:
	g++ knapsack.cpp -Wall -std=c++11 -g -o knapsack
	g++ onezeroknapsack.cpp -Wall -std=c++11 -g -o onezero
test: all
	./knapsack < knapsack_data
	./onezero < onezero_data
