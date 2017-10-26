BINARY = mystring
OBJECTS = mystring.cpp test.cpp
HEADERS = mystring.h 

CC = gcc
CFLAGS = -std=c11 -O0 -Wall -Wdeprecated -pedantic -g
LDFLAGS = -g

CXX = g++
CXXFLAGS = -std=c++11 -O0 -Wall -Wdeprecated -pedantic -g

.PHONY: all clean

all: $(BINARY)

clean:
	rm -f $(BINARY) $(OBJECTS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BINARY): $(OBJECTS)
	$(CXX) $(LDFLAGS) $^ -o $@