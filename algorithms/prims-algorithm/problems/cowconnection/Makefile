CXX=g++
CPPFLAGS=-Wall -g -std=gnu++0x
all: cowconnection.exe
%.exe : %.cpp
	$(CXX) $(CPPFLAGS) -o $@ $^
clean:
	-rm cowconnection.exe
test: all
	./cowconnection.exe 
