all: cowpens.cpp cowpens-verification.cpp
	g++ -std=c++11 cowpens.cpp -o cowpens -Wall
	g++ -std=c++11 cowpens-verification.cpp -o cowpens-verification -Wall
test: all
	./cowpens < cowpens-test.in
	./cowpens-verification < cowpens-test.in
clean:
	rm cowpens cowpens-verification
