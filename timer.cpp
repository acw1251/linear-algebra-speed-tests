/**
 *  \file timer.cpp
 *
 *  \brief Simple timer functions
 *  \author Andy Wright
 *  \date June 23, 2012
 */

#include "timer.hpp"

clock_t start_clock;

/**
 *  \brief Starts a timer that will be stopped with \c stop_timer().
 *
 *  Sets \a start_clock to the current value of \c clock().
 */
void start_timer()
{
    start_clock = clock();
}

/**
 *  \brief calculates the amount of time passed since \c start_timer() was called.
 *  
 *  Records the value of \c clock() and compares it to \a start_clock.
 *
 *  \returns The amount of time in seconds since \c start_timer() was called.
 */
double stop_timer()
{
    clock_t stop_clock = clock();
    return (double)(stop_clock - start_clock) / CLOCKS_PER_SEC;
}

