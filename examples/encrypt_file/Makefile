CXX = g++
SRC = ../../src
OBJECTS = $(SRC)/caesarcipher.o $(SRC)/dummycipher.o $(SRC)/textcipher.o $(SRC)/functorobject.o
SOURCES = main.cpp
EXEC = main
CFLAGS = -Wall -ansi -O2

main.o : main.cpp
	$(CXX) $(CFLAGS) $(SOURCES) $(OBJECTS) -o $(EXEC)

objects:
	$(MAKE) -C $(SRC)

main.o : objects

all: main.o objects

clean:
	rm -rf *.o $(EXEC)