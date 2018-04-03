all: main.cpp file.o util.o
	g++ main.cpp file.o util.o -std=c++17 -lavcodec -lavformat -lavutil -o surround2hrtf

file.o: file.cpp
	g++ -c file.cpp

util.o: util.cpp
	g++ -c util.cpp

clean:
	rm -rf surround2hrtf *.o

.PHONY: clean
