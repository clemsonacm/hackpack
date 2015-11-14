SRCS=$(wildcard *.cpp)
all: $(SRCS)
	g++ $(SRCS) -g -Wall -O2 -o coming-and-going.exe
clean:
	rm coming-and-going.exe
test: all
	./coming-and-going.exe < coming-and-going.in
