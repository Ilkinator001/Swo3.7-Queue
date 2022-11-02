CC=g++
CPPFLAGS=-std=c++17 -pedantic -Wall -Wextra -ggdb -Iinclude ${DEFINES}
LD=g++
LDFLAGS=-lm

all: queue

queue: main.o Queue.o Data.o
	g++ $(LDFLAGS) -o $@ $+

main.o: main.cpp Queue.h Data.h
Queue.o: Queue.cpp Queue.h Data.h
Data.o: Data.cpp Data.h

.PHONY: clean test

clean:
	rm -f *.o queue

test:
	./queue