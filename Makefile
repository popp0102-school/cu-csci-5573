# Compiler
CXXFLAGS = -Wall -g
LDFLAGS  =

# Structure
src    = $(wildcard src/*.cpp)
obj    = $(src:.c=.o)
target = modulus-prime
dest   = bin

modulus-prime: $(obj)
	$(CXX) $(CXXFLAGS) $^ -o $(dest)/$@ $(LDFLAGS)

clean:
	rm -f *.o $(target)

.PHONY: clean
