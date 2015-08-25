SRCS=$(wildcard *.cpp)
all: $(SRCS)
	g++ $(SRCS) -g -Wall -o all-or-nothing.exe
clean:
	rm all-or-nothing.exe
test: all
	./all-or-nothing.exe < all-or-nothing.in
