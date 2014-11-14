CXX=g++
CPPFLAGS=-Wall -g -std=gnu++0x
all: escape.exe
%.exe: %.cpp 
	$(CXX) $(CPPFLAGS) -o $@ $^
test: all
	./escape.exe < escape.in
clean:
	-rm escape.exe
