linear-algebra-speed-tests
==========================
This repo will hold multiple speed tests for basic linear algebra applications.

Currently there are two speed tests: (All of these results are for double precision)

1. armadillo\_test.cpp
    * 20x20 LU decomposition with partial pivoting: 7.9 us
2. custom\_test.cpp
    * 10x10 Matrices:
        * LDLt decomposition: 435 ns
        * LDLt decomposition with one solve step: 607 ns
        * LDLt decomposition with two solve steps: 765 ns
    * 20x20 Matrices:
        * LDLt decomposition: 2.34 us
        * LDLt decomposition with one solve step: 2.81 us
        * LDLt decomposition with two solve steps: 3.28 us
    * 50x50 Matrices:
        * LDLt decomposition: 25.9 us
        * LDLt decomposition with one solve step: 28.9 us
        * LDLt decomposition with two solve steps: 31.5 us
    * 100x100 Matrices:
        * LDLt decomposition: 178 us
        * LDLt decomposition with one solve step: 188 us
        * LDLt decomposition with two solve steps: 197 us
    * 200x200 Matrices:
        * LDLt decomposition: 1.38 ms
        * LDLt decomposition with one solve step: 1.43 ms
        * LDLt decomposition with two solve steps: 1.47 ms
    * 500x500 Matrices:
        * LDLt decomposition: 226 ms
        * LDLt decomposition with one solve step: 229 ms
        * LDLt decomposition with two solve steps: 231 ms
    * 1000x1000 Matrices:
        * LDLt decomposition: 621 ms
        * LDLt decomposition with one solve step: 624 ms
        * LDLt decomposition with two solve steps: 627 ms
