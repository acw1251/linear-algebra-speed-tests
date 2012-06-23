/**
 *  \file armadillo_test.cpp
 *
 *  \brief Tests some functions from the armadillo c++ library
 *
 *  The armadillo c++ library can be found at arma.sourceforge.net
 *
 *  \author Andy Wright
 *  \date June 22, 2012
 */

#include <iostream>
#include <armadillo>

#include <ctime>

using namespace std;
using namespace arma;

int main( int argc, char *argv[] )
{
    int const num_tests = 1000000;
    int i;
    double time;
    double time_per;
    clock_t start_clock;
    clock_t stop_clock;

    // The only algorithm of interest that armadillo
    // has is lu decomposition with partial pivoting
    mat A = randu<mat>(20,20);
    mat L, U, P;
    cout << "Begining LU decomposition." << endl;
    start_clock = clock();
    for( i = 0 ; i < num_tests ; i++ ) {
        lu( L, U, P, A );
    }
    stop_clock = clock();
    cout << "LU Decomposition done." << endl;
    time = (float)(stop_clock - start_clock)/CLOCKS_PER_SEC;
    time_per = time / num_tests;
    cout << "time_per = " << time_per * 1e6 << " us" << endl;
}
