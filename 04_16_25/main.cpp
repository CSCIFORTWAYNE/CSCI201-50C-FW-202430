#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <stdexcept>
#include "clock.h"

// create invalid_hour and invalid_second in clockExcept.h and clockExcept.cpp
// update the catch blocks in the main to use the new exceptions.

int main()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::vector<clockType *> timeClockIn;
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distributionClockType(1, 2);
    std::uniform_int_distribution<int> distributionClockNum(1, 100);

    int numClocks = distributionClockNum(generator);
    try
    {
        timeClockIn.at(1);
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << e.what() << '\n';
    }
    int min;
    int sec;
    int hr;
    bool validMinute = false;
    bool validSecond = false;
    bool validHour = false;
    bool newClock = true;
    timeType clockT;
    for (int i = 0; i < numClocks; i++)
    {

        try
        {
            clockType *clock;
            if (newClock)
            {
                clockT = clockType::intToTimeType.at(distributionClockType(generator) * 12);
                newClock = false;
            }
            if (!validMinute)
            {
                min = distributionClockNum(generator);
                validMinute = true;
            }
            if (!validSecond)
            {
                sec = distributionClockNum(generator);
                // validSecond = true;
            }
            if (!validHour)
            {
                hr = distributionClockNum(generator);
                validHour = true;
            }
            if (clockT == TWELVE)
            {
                partType part = clockType::intToPartType.at(distributionClockType(generator));
                clock = new twelveHrClock(hr, min, sec, part);
            }
            else
            {
                clock = new twentyFourHrClock(hr, min, sec);
            }
            timeClockIn.push_back(clock);
            validHour = false;
            validMinute = false;
            validSecond = false;
            newClock = true;
        }
        catch (invalid_minute e)
        {
            std::cout << e.what() << std::endl;
            validMinute = false;
            i--;
            continue;
        }
        catch (std::invalid_argument e)
        {
            std::cout << e.what() << std::endl;

            i--;
            continue;
        }
    }
    if (*timeClockIn[0] > *timeClockIn[1])
    {
        std::cout << ">" << std::endl;
    }

    for (int i = 0; i < timeClockIn.size(); i++)
    {
        std::cout << *(timeClockIn[i]) << std::endl;
        delete timeClockIn[i];
    }

    return 0;
}