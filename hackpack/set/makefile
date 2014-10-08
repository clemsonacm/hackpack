all: cowpens.cpp cowpens_verification.cpp
	g++ -std=c++11 cowpens.cpp -o cowpens -Wall
	g++ -std=c++11 cowpens_verification.cpp -o cowpens_verify -Wall
test: all
	./cowpens < data_out
	./cowpens_verify < data_out
clean:
	rm cowpens cowpens_verify
