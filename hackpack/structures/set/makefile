all: cowpens.cpp cowpens-test.cpp
	g++ -std=c++11 cowpens.cpp -o cowpens -Wall
	g++ -std=c++11 cowpens-test.cpp -o cowpens-test -Wall
test: all
	./cowpens < cowpens-test.in
	./cowpens-test < cowpens-test.in
clean:
	rm cowpens cowpens-test
