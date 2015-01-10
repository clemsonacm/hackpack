SRCS=$(wildcard *.cpp)
all: $(SRCS)
	g++ $(SRCS) -g -Wall -o gpsduel.exe
clean:
	rm gpsduel.exe
test: all
	./gpsduel.exe < gpsduel.in
	./gpsduel.exe < gpsdueltest1.in
	./gpsduel.exe < gpsdueltest2.in
	./gpsduel.exe < gpsdueltest3.in