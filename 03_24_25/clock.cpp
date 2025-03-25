#include "clock.h"

void clockType::setTime(int h, int m, int s)
{
    setHour(h);
    setMinute(m);
    setSecond(s);
}

void clockType::getTime(int &h, int &m, int &s) const
{
    h = hr;
    m = min;
    s = sec;
}

std::string clockType::tostring() const
{
    std::ostringstream out;
    out << std::setfill('0');
    out << std::setw(2) << hr << ":" << std::setw(2) << min << ":" << std::setw(2) << sec;
    return out.str();
}

void clockType::incrementSeconds()
{
    sec++;
    if (sec > 59)
    {
        sec = 0;
        incrementMinutes();
    }
}

void clockType::incrementMinutes()
{
    min++;
    if (min > 59)
    {
        min = 0;
        incrementHours();
    }
}

void clockType::incrementHours()
{
    hr++;
    if (hr > 23)
    {
        hr = 0;
    }
}

bool clockType::equalTime(const clockType &otherClock) const
{
    /* int standardHour = hr;
    int othStandardHour = otherClock.hr;
    if (format == TWELVE)
    {
        if (standardHour == 12)
        {
            standardHour = 0;
        }
        if (partOfDay == PM)
        {
            standardHour = standardHour + 12;
        }
    }

    if (otherClock.format == TWELVE)
    {
        if (othStandardHour == 12)
        {
            othStandardHour = 0;
        }
        if (otherClock.partOfDay == PM)
        {
            othStandardHour = othStandardHour + 12;
        }
    } */

    return otherClock.hr == hr && otherClock.min == min && otherClock.sec == sec;
}

int clockType::getHour() const
{

    return hr;
}
int clockType::getMinute() const
{
    return min;
}

int clockType::getSecond() const { return sec; }

void clockType::setHour(int h)
{
    hr = h;
    if (!validHr())
    {
        invalidHour();
    }
}

void clockType::setMinute(int m)
{
    min = m;
    if (!validMin())
    {
        std::cout << "Minutes must be between 0 and 59" << std::endl;
        std::cout << "Defaulting to 0." << std::endl;
        min = 0;
    }
}

void clockType::setSecond(int s)
{

    sec = s;
    if (!validSec())
    {
        std::cout << "Seconds must be between 0 and 59" << std::endl;
        std::cout << "Defaulting to 0." << std::endl;
        sec = 0;
    }
}

clockType::clockType(int h, int m, int s) : hr{h}, min{m}, sec{s}
{
    if (!validHr())
    {
        invalidHour();
    }
    if (!validMin())
    {
        std::cout << "Minutes must be between 0 and 59" << std::endl;
        std::cout << "Defaulting to 0." << std::endl;
        min = 0;
    }
    if (!validSec())
    {
        std::cout << "Seconds must be between 0 and 59" << std::endl;
        std::cout << "Defaulting to 0." << std::endl;
        sec = 0;
    }
    // setTime(h, m, s);
}

bool clockType::validHr() const
{
    /* bool valid = true;
    if (format == TWENTYFOUR)
    {
        valid = hr >= 0 && hr <= 23;
    }
    else
    {
        valid = hr >= 1 && hr <= 12;
    } */
    return hr >= 0 && hr <= 23; //&& sec >= 0 && sec <= 59 && min >= 0 && min <= 59;
}

bool clockType::validMin() const
{
    return min >= 0 && min <= 59;
}

bool clockType::validSec() const
{
    return sec >= 0 && sec <= 59;
}

void clockType::invalidHour()
{
    /* if (format == TWENTYFOUR)
    {

    }
    else
    {
        std::cout << "Hours must be between 1 and 12." << std::endl;
        std::cout << "Defaulting to 12." << std::endl;
        hr = 12;
    } */
    std::cout << "Hours must be between 0 and 23." << std::endl;
    std::cout << "Defaulting to 0." << std::endl;
    hr = 0;
}

timeType clockType::formats[2] = {TWELVE, TWENTYFOUR};
partType clockType::parts[2] = {AM, PM};
std::string clockType::formatToStr[2] = {"12 hour clock", "24 hour clock"};
std::string clockType::partToStr[2] = {"AM", "PM"};

bool twelveHrClock::validHr() const
{
    return hr >= 1 && hr <= 12;
}

void twelveHrClock::invalidHour()
{
    std::cout << "Hours must be between 1 and 12." << std::endl;
    std::cout << "Defaulting to 12." << std::endl;
    hr = 12;
}
twelveHrClock::twelveHrClock(int h, int m, int s, partType part) : clockType(h, m, s)
{
    if (!validHr())
    {
        invalidHour();
    }
    partOfDay = part;
}
void twelveHrClock::setHour(int h)
{
    hr = h;
    if (!validHr())
    {
        invalidHour();
    }
}