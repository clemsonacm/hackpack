SRCS=$(wildcard *.cpp)
all: $(SRCS)
	g++ $(SRCS) -g -Wall -o fine-print.exe
clean:
	rm fine-print.exe
test: all
	./fine-print.exe < fine-print.in
