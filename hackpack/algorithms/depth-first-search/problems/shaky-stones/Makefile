SRCS=$(wildcard *.cpp)
all: $(SRCS)
	g++ $(SRCS) -g -Wall -o shaky-stones.exe
clean:
	rm shaky-stones.exe
test: all
	./shaky-stones.exe < shaky-stones.in
