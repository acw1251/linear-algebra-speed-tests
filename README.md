linear-algebra-speed-tests
==========================
This repo will hold multiple speed tests for basic linear algebra applications.

Currently there are two speed tests:

1. armadillo\_test.cpp
    * 20x20 LU decomposition with partial pivoting: 7.9 us
2. custom\_test.cpp
    * 20x20 LDLt decomposition: 2.4 us
    * 20x20 LDLt decomposition with the solve steps: 2.9 us
