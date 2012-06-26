/**
 *  \file timer.cpp
 *
 *  \brief Simple timer functions
 *  \author Andy Wright
 *  \date June 23, 2012
 */

#include "timer.hpp"

namespace timer {

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

auto_timer::auto_timer()
{
    id = next_id;
    next_id++;
    cout << "Timer " << id << ": Started" << endl;
    start_time = clock();
}

auto_timer::~auto_timer()
{
    clock_t stop_time = clock();
    cout << "Timer " << id << ": Stopped" << endl;
    double running_time_sec = double(stop_time - start_time) / CLOCKS_PER_SEC;
    if( running_time_sec < 1e-3 ) {
        cout << "Timer " << id << ": Running time = " << running_time_sec * 1e6 << " us" << endl;
    } else if( running_time_sec < 1 ) {
        cout << "Timer " << id << ": Running time = " << running_time_sec * 1e3 << " ms" << endl;
    } else {
        cout << "Timer " << id << ": Running time = " << running_time_sec << " s" << endl;
    }
}

int auto_timer::next_id = 0;

}

