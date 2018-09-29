# Compiler
CXXFLAGS = -c -Wall -g
LDFLAGS  =

# Structure
src    = $(wildcard src/*.cpp)
obj    = $(src:.c=.o)
target = modulus-prime

$(target): $(obj)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -f *o $(target)

.PHONY: clean
