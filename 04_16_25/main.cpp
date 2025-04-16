#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include "clock.h"

int main()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::vector<clockType *> timeClockIn;
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distributionClockType(1, 2);
    std::uniform_int_distribution<int> distributionClockNum(1, 100);

    int numClocks = distributionClockNum(generator);
    for (int i = 0; i < numClocks; i++)
    {
        try
        {
            clockType *clock;
            timeType clockT = clockType::intToTimeType.at(distributionClockType(generator) * 12);
            int min = distributionClockNum(generator);
            int sec = distributionClockNum(generator);
            if (clockT == TWELVE)
            {
                int hr = distributionClockNum(generator);
                partType part = clockType::intToPartType.at(distributionClockType(generator));
                clock = new twelveHrClock(hr, min, sec, part);
            }
            else
            {
                int hr = distributionClockNum(generator);
                clock = new twentyFourHrClock(hr, min, sec);
            }
            timeClockIn.push_back(clock);
        }
        catch (...)
        {
            std::cout << "Exception thrown. Clock is invalid. Restarting." << std::endl;
            i--;
            continue;
        }
    }

    for (int i = 0; i < timeClockIn.size(); i++)
    {
        std::cout << *(timeClockIn[i]) << std::endl;
    }

    return 0;
}