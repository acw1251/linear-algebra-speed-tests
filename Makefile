CC = g++
OPT = -O3
ARMADILLO_LINKING = -larmadillo

.PHONY: all

all: armadillo_test custom_test

armadillo_test: armadillo_test.o timer.o
	$(CC) $(OPT) armadillo_test.o timer.o $(ARMADILLO_LINKING) -o armadillo_test
armadillo_test.o: armadillo_test.cpp
	$(CC) $(OPT) -c armadillo_test.cpp

custom_test: custom_test.o timer.o
	$(CC) $(OPT) custom_test.o timer.o -o custom_test
custom_test.o: custom_test.cpp
	$(CC) $(OPT) -c custom_test.cpp

timer.o: timer.cpp timer.hpp
	$(CC) $(OPT) -c timer.cpp

.PHONY: clean

clean:
	rm -rf armadillo_test custom_test
	rm -rf *.o
