CC=g++
CFLAGS=-c -g -Wall -DNDEBUG
LDFLAGS= -lUnitTest++
SOURCES= main.cpp error_processing.cpp
HEADERS =	calculation.h error_processing.h
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=testing

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm $(OBJECTS) $(EXECUTABLE)
