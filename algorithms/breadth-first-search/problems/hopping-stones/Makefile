SRCS=$(wildcard *.cpp)
all: $(SRCS)
	g++ $(SRCS) -g -Wall -o hopping-stones.exe
clean:
	rm hopping-stones.exe
test: all
	./hopping-stones.bats
