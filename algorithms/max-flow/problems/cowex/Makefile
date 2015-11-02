CXX=g++
CPPFLAGS=-Wall -g -std=gnu++0x
all: cowex.exe
%.exe : %.cpp
	$(CXX) $(CPPFLAGS) -o $@ $^
clean:
	-rm cowex.exe
test: all
	./cowex.bats -t
