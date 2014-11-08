all: cowpens.cpp cowpens-test.cpp
	g++ -std=c++11 cowpens.cpp -o cowpens.exe -Wall
	g++ -std=c++11 cowpens-test.cpp -o cowpens-test.exe -Wall
test: all
	./cowpens.exe < cowpens-test.in
	./cowpens-test.exe < cowpens-test.in
clean:
	rm *.exe
