SRCS=$(wildcard *.cpp)
all: $(SRCS)
	g++ $(SRCS) -g -Wall -o all-or-nothing.exe
clean:
	rm a.out
test: all
	./all-or-nothing.exe < all-or-nothing.in
