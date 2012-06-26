/**
 *  \file timer.hpp
 *
 *  \brief simple timer functions
 *  \author Andy Wright
 *  \date June 23, 2012
 */

#ifndef TIMER_HPP
#define TIMER_HPP

#include <iostream>
#include <ctime>

using namespace std;

namespace timer {

void start_timer();
double stop_timer();

/**
 *  \brief This class tiems how long it exists
 */
class auto_timer {
    public:
        auto_timer();
        ~auto_timer();
    private:
        clock_t start_time; 
        int id;
        static int next_id;
};

}

#endif // TIMER_HPP

