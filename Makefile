CC=g++
CFLAGS=-c -g -Wall -Wextra
LDFLAGS= -lpthread -lcrypto++
SOURCES= main.cpp server.cpp authorization.cpp read_base.cpp connection.cpp error_processing.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=server

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm $(OBJECTS) $(EXECUTABLE)
