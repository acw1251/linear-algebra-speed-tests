CC = g++
OPT = -O3
NO_OPT =
ASM_FLAG = -S -fverbose-asm
ARMADILLO_LINKING = -larmadillo

.PHONY: all assembly clean

all: armadillo_test custom_test assembly

assembly: custom_test_opt.s custom_test.s

armadillo_test: armadillo_test.o timer.o
	$(CC) $(OPT) armadillo_test.o timer.o $(ARMADILLO_LINKING) -o armadillo_test
armadillo_test.o: armadillo_test.cpp
	$(CC) $(OPT) -c armadillo_test.cpp

custom_test: custom_test.o timer.o
	$(CC) $(OPT) custom_test.o timer.o -o custom_test
custom_test.o: custom_test.cpp
	$(CC) $(OPT) -c custom_test.cpp

custom_test.s: custom_test.cpp
	$(CC) $(NO_OPT) $(ASM_FLAG) custom_test.cpp -o custom_test.s
custom_test_opt.s: custom_test.cpp
	$(CC) $(OPT) $(ASM_FLAG) custom_test.cpp -o custom_test_opt.s

timer.o: timer.cpp timer.hpp
	$(CC) $(OPT) -c timer.cpp


clean:
	rm -rf armadillo_test custom_test
	rm -rf *.o *.s
