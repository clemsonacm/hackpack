SRCS=$(wildcard *.cpp)
all: $(SRCS)
	g++ $(SRCS) -g -Wall -o shaky-stones.exe

test: all
	./shaky-stones.bats --tap

.PHONY: clean
clean:
	rm shaky-stones.exe
