CC     = g++
CFLAGS = -c -Wall

build: main.o
	$(CC) main.o -o modulus-prime

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm *o modulus-prime
