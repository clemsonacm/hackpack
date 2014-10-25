SRCS=$(wildcard *.cpp)
all: $(SRCS)
	g++ $(SRCS) -g -Wall -o fine-print.exe
clean:
	rm fine-print.exe
test:
	fine-print.exe fine-print.in
	fine-print.exe fine-print-no-pool.in
