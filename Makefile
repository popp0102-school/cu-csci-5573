# Compiler
CXXFLAGS = -Wall -g
LDFLAGS  =
INCLUDES = -I src/os

# Structure
src    = $(wildcard src/*.cpp) \
         $(wildcard src/os/*.cpp)
         $(wildcard src/os/scheduler/*.cpp)
obj    = $(src:.c=.o)
target = bin/modulus-prime

modulus-prime: $(obj)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $(target) $(LDFLAGS)

clean:
	rm -f *.o $(target)

.PHONY: clean
