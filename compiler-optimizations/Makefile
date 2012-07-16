CC = g++
OPT = -O3
OPT_FAST = -Ofast
ASM_FLAG = -S -fverbose-asm

.PHONY: all clean

all: normal fast

normal: add.s iadd.s mul.s and.s

fast: add_fast.s iadd_fast.s mul_fast.s and_fast.s

%.s: %.cpp
	$(CC) $(OPT) $(ASM_FLAG) $< -o $@
%_fast.s: %.cpp
	$(CC) $(OPT_FAST) $(ASM_FLAG) $< -o $@


clean:
	rm -rf *.s
