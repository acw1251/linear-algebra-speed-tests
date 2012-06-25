linear-algebra-speed-tests
==========================
This repo will hold multiple speed tests for basic linear algebra applications.

Currently there are two speed tests:

1. armadillo\_test.cpp
    * 20x20 LU decomposition with partial pivoting: 7.9 us
2. custom\_test.cpp
    * 10x10 Matricies:
        * LDLt decomposition: 435 ns
        * LDLt decomposition with one solve step: 607 ns
        * LDLt decomposition with two solve steps: 765 ns
    * 20x20 Matricies:
        * LDLt decomposition: 2.34 us
        * LDLt decomposition with one solve step: 2.81 us
        * LDLt decomposition with two solve steps: 3.28 us
    * 100x100 Matricies:
        * LDLt decomposition: 178 us
        * LDLt decomposition with one solve step: 188 us
        * LDLt decomposition with two solve steps: 197 us
    * 1000x1000 Matricies:
        * LDLt decomposition: 621 ms
        * LDLt decomposition with one solve step: 624 ms
        * LDLt decomposition with two solve steps: 627 ms
