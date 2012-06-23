linear-algebra-speed-tests
==========================
This repo will hold multiple speed tests for basic linear algebra applications.

Currently there are two speed tests:

1. armadillo\_test.cpp
    * 20x20 LU decomposition with partial pivoting: 7.9 us
2. custom\_test.cpp
    * 20x20 LDLt decomposition: 2.4 us
    * 20x20 LDLt decomposition with one solve step: 2.9 us
    * 20x20 LDLt decomposition with two solve steps: 3.4 us
