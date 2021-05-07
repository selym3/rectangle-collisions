#ifndef __TIMER_HPP__
#define __TIMER_HPP__ 

#include <chrono>

namespace Timed
{
    auto getTimeStamp()
    {
        return std::chrono::system_clock::now();
    }

    struct Timer
    {

        // Constructors

        using Time = 
            std::chrono::system_clock::time_point;
        using Duration =
            std::chrono::duration<double>;

        Timer()
        {
            this->last = getTimeStamp();
        }

        // Get time

        Duration getTimeDuration() const
        {
            return (getTimeStamp() - this->last);
        }

        double getTime() const
        {
            return getTimeDuration().count();
        }

        // Get time and reset stopwatch

        Duration resetDuration()
        {
            auto now = getTimeStamp();
            auto elapsed = now - this->last;
            this->last = now;

            return elapsed;
        }

        double reset()
        {
            auto d = resetDuration();
            return d.count();
        }

    private:
        Time last;

    }; 
}

#endif