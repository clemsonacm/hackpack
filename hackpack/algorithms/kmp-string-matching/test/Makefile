SRCS=$(wildcard *.cpp)
all: $(SRCS)
	g++ $(SRCS) -g -Wall -o kmp-string-matching-test.exe
clean:
	rm kmp-string-matching-test.exe
test: all
	./kmp-string-matching-test.exe < kmp-string-matching-test.in
