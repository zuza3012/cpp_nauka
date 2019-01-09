CXX = g++
CXXFLAGS = -g -Wall 
LFLAGS =

OBJS = macierz.o main.o

all: macierz

macierz: $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@
	
clean:
	rm -f *.o m
	
.PHONY: all clean
