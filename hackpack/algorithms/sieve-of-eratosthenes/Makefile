SRCS=$(wildcard *.cpp)
all: $(SRCS)
	g++ $(SRCS) -g -Wall
clean:
	rm a.out
test: all
	./a.out < sieve-of-eratosthenes.in
