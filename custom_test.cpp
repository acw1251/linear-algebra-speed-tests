/**
 *  \file custom_test.cpp
 *
 *  \brief Tests the speed of a custom implementation of LDLt
 *
 *  Everything in this function is specialized for square matricies
 *
 *  \author Andy Wright
 *  \date June 23, 2012
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "timer.hpp"

#define TEST_ALGORITHM( algorithmname, A ) \
    time = 0; \
    num_tests = 1; \
    while( time < min_time ) { \
        cout << "Begining " << algorithmname << " with " << num_tests << " repetitions." << endl; \
        timer::start_timer(); \
        for( i = 0 ; i < num_tests ; i++ ) { \
            A \
        } \
        time = timer::stop_timer(); \
        if( time < min_time ) { \
            cout << "Test completed too fast" << endl; \
            num_tests *= 10; \
        } \
    } \
    cout << algorithmname << " done." << endl; \
    cout << "Total time = " << time * 1e3 << " ms" << endl; \
    time_per = time / num_tests; \
    cout << "Time per repetition = " << time_per * 1e6 << " us" << endl << endl;

using namespace std;

// Global variable set by user input
// This variable is used in all of the functions below
int size;

// Change this typedef to float to get the results for single precision
typedef double float_type;
void mult( float_type* A, float_type* B, float_type* Result );
void aat( float_type* A, float_type* Result );
void ldlt( float_type* A, float_type* L, float_type* D );
void ldlt_solve( float_type* L, float_type* D, float_type* b, float_type* x, float_type* workspace );

timer::auto_timer global;


int main( int argc, char *argv[] )
{
    int num_tests;
    int i, j, k;
    double min_time;
    double time;
    double time_per;
    float_type *workspace, *A, *L, *D, *b, *x;

    cout << endl << endl;
    cout << "This program runs sample LDLt decompositions and solves" << endl;
    cout << "for NxN matricies where N is given by the user." << endl;
    cout << endl;

    cout << "N = ";
    cin >> size;
    cout << endl;

    if( size <= 1 ) {
        cout << "Error! N must be greater than 1." << endl;
        exit(1);
    }

    cout << "Minimum amount of time to measure = ";
    cin >> min_time;
    cout << endl;

    if( min_time < 0.001 ) {
        cout << "Error! Minimum time to measure must be at least 1 ms." << endl;
        exit(1);
    }

    workspace = new float_type[size*size];
    A = new float_type[size*size];
    L = new float_type[size*size];
    D = new float_type[size*size];
    b = new float_type[size];
    x = new float_type[size];

    // random A matrix
    srand( std::time( NULL ) );
    for( i = 0 ; i < size * size; i++ ) {
        workspace[i] = (float_type) rand() / RAND_MAX;
        if( i < size ) {
            b[i] = (float_type) rand() / RAND_MAX;
        }
    }
    // A = workspace * workspace^T
    aat( workspace, A );

    // LDLt decomposition
    TEST_ALGORITHM( "LDLt decomposition" ,
        ldlt( A, L, D );
    )

    // LDLt decomposition with solve
    TEST_ALGORITHM( "LDLt decomposition with 1 solve" ,
        ldlt( A, L, D );
        ldlt_solve( L, D, b, x, workspace );
    )

    // LDLt decomposition with 2 solve steps
    TEST_ALGORITHM( "LDLt decomposition with 2 solves" ,
        ldlt( A, L, D );
        ldlt_solve( L, D, b, x, workspace );
        ldlt_solve( L, D, b, x, workspace );
    )
}

// Result = A * B
void mult( float_type * __restrict__ A, float_type * __restrict__ B, float_type * __restrict__ Result )
{
    int i, j, k;
    for( i = 0 ; i < size ; i++ ) {
        for( j = 0 ; j < size ; j++ ) {
            Result[size*i+j] = 0.0;
            for( int k = 0 ; k < size ; k++ ) {
                Result[size*i+j] += A[size*i+k] * B[size*k+j];
            }
        }
    }
}

// Result = A * A^T
void aat( float_type * __restrict__ A, float_type * __restrict__ Result )
{
    int i, j, k;
    for( i = 0 ; i < size ; i++ ) {
        for( j = 0 ; j < size ; j++ ) {
            Result[size*i+j] = 0.0;
            for( int k = 0 ; k < size ; k++ ) {
                Result[size*i+j] += A[size*i+k] * A[size*j+k];
            }
        }
    }
}

void ldlt( float_type * __restrict__ A, float_type * __restrict__ L, float_type * __restrict__ D )
{
    int i, j, k;
    float_type sum_over_k;
    for( int i = 0 ; i < size ; i++ ) {
        for( int j = 0 ; j < i ; j++ ) {
            if( j == 0 ) {
                // sum_over_k = 0
                L[size*i+j] = A[size*i+j] / D[size*0+0];
            } else {
                sum_over_k = L[size*i+0] * D[size*0+0] * L[size*j+0];
                for( int k = 1 ; k < j ; k++ ) {
                    sum_over_k += L[size*i+k] * D[size*k+k] * L[size*j+k];
                }
                L[size*i+j] = (A[size*i+j] - sum_over_k) / D[size*j+j];
            }
        }
        if( i == 0 ) {
            // sum_over_k = 0
            D[size*i+i] = A[size*i+i];
        } else {
            sum_over_k = L[size*i+0] * L[size*i+0] * D[size*0+0];
            for( int k = 1 ; k < i ; k++ ) {
                sum_over_k += L[size*i+k] * L[size*i+k] * D[size*k+k];
            }
            D[size*i+i] = A[size*i+i] - sum_over_k;
        }
    }
}

void ldlt_solve( float_type * __restrict__ L, float_type * __restrict__ D, float_type * __restrict__ b, float_type * __restrict__ x, float_type * __restrict__ workspace )
{
    // workspace is a vector
    int i,j;
    float_type tmp;

    // Forward substitution: (solves L*x = b)
    // solving for x(0,0) first and x(n-1,0) last
    for( i = 0 ; i < size ; i++ ) {
        if( i == 0 ) {
            x[i] = b[i]; // L(0,0) = 1
        } else {
            tmp = L[size*i+0] * x[0];
            for( j = 1 ; j < i ; j++ ) {
                tmp += L[size*i+j] * x[j];
            }
            x[i] = b[i] - tmp; // L(i,i) = 1
        }
    }
    
    // Diagonal solve: (solves D*z = y)
    for( i = 0 ; i < size ; i++ ) {
        workspace[i] = x[i] / D[size*i+i];
    }

    // Back substitution: (solves L^T*x = y)
    // solving for x(n-1,0) first and x(0,0) last
    for( i = size-1 ; i >= 0 ; i-- ) {
        if( i == size-1 ) {
            x[i] = workspace[i]; // L(0,0) = 1
        } else {
            tmp = L[size*(size-1)+i] * x[size-1]; // L^T
            for( j = size-2 ; j > i ; j-- ) {
                tmp += L[size*j+i] * x[j]; // L^T
            }
            x[i] = (workspace[i] - tmp); // L(i,i) = 1
        }
    }
    // x should now have the solution to Ax = b
}

