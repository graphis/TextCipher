#
# Makefile for Textcipher 0.1
#
SOURCES = textcipher.cpp dummycipher.cpp caesarcipher.cpp functorobject.cpp
OBJECTS = $(SOURCES:.cpp=.o)
CXX = g++
CFLAGS = -c -Wall -ansi -O2

%.o: %.cpp
	$(CXX) $(CFLAGS) $<

all : $(OBJECTS)

.PHONY: clean
clean:
	rm -rf $(OBJECTS)
