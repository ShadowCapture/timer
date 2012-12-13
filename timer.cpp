/***********************************************************
 *
 * timer.cpp
 *
 * Free to use and abuse
 * Written by Morgan Baron on or around 12/2012
 *
 *
 *
 ***********************************************************/

#include <timer.h>

void Timer::Start()
{
    is_running_ = 1;
    clock_gettime(CLOCK_REALTIME, &start_); 
}

void Timer::Stop()
{
    is_running_ = 0;
    clock_gettime(CLOCK_REALTIME, &end_);

    elapsed_  = difftime(end_.tv_sec, start_.tv_sec);
    if (!elapsed_)
    {
        elapsed_ = difftime(end_.tv_nsec, start_.tv_nsec);
        elapsed_ /= 1000;
    }
}

void Timer::Reset()
{
    is_running_ = 0;
    elapsed_ = 0;
}

std::ostream& operator<< (std::ostream &out, const Timer &T)
{
    out << "elapsed: " << T.elapsed_ << "us" << std::endl;
    
    return out;
}
