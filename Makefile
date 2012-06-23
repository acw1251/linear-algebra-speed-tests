CC = g++
OPT = -O3
ARMADILLO_LINKING = -larmadillo

.PHONY: all

all: armadillo_test

armadillo_test: armadillo_test.o timer.o
	$(CC) $(OPT) armadillo_test.o timer.o $(ARMADILLO_LINKING) -o armadillo_test
armadillo_test.o: armadillo_test.cpp
	$(CC) $(OPT) -c armadillo_test.cpp

timer.o: timer.cpp timer.hpp
	$(CC) $(OPT) -c timer.cpp

.PHONY: clean

clean:
	rm -rf armadillo_test
	rm -rf *.o
