CC     = g++
CFLAGS = -c -Wall
TARGET = modulus-prime

build: main.o
	$(CC) main.o -o $(TARGET)

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -f *o $(TARGET)
