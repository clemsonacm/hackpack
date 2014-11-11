all: cowpens.cpp cowpens-test.cpp
	g++ -std=gnu++0x cowpens.cpp -o cowpens.exe -Wall
	g++ -std=gnu++0x cowpens-test.cpp -o cowpens-test.exe -Wall
test: all
	./cowpens.exe < cowpens-test.in
	./cowpens-test.exe < cowpens-test.in
clean:
	rm *.exe
