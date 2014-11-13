SRCS=$(wildcard *.cpp)
all: $(SRCS)
	g++ $(SRCS) -g -Wall -o sieve-of-eratosthenes-test.exe
clean:
	rm sieve-of-eratosthenes-test.exe
test: all
	./sieve-of-eratosthenes-test.exe < sieve-of-eratosthenes-test.in
