/***********************************************************
 *
 * timer.h
 *
 * Free to use and abuse
 * Written by Morgan Baron on or around 12/2012
 *
 *
 *
 ***********************************************************/

#ifndef __TIMER_H__
#define __TIMER_H__


#include <time.h>
#include <iostream>

class Timer
{
 public:
    Timer() { is_running_ = 0; }
    void Start();
    void Stop();
    void Reset();
    
    friend std::ostream& operator<< (std::ostream &out, const Timer &T);
 private:
    timespec start_, end_;
    bool is_running_;
    double elapsed_;

};

#endif
