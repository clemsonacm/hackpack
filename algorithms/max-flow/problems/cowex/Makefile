CXX=clang++
CPPFLAGS=-Wall -g -std=c++11
all: cowex.exe
%.exe : %.cpp
	$(CXX) $(CPPFLAGS) -o $@ $^
clean:
	-rm cowex.exe
test: all
	./cowex.bats -t
