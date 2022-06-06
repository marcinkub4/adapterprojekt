CC=g++

CFLAGS=-c -Wall

all: adapter

adapter: adapter.o
	$(CC) adapter.o -o adapter

adapter.o: adapter.cpp
	$(CC) $(CFLAGS) adapter.cpp

clean:
	  rm -rf *.o

