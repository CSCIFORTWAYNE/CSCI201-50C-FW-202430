#include <iostream>
#include <limits>
#include <string>
#include <algorithm>
#include "clock.h"

enum class timePartType
{
    HOUR,
    MINUTE,
    SECOND,
};

void clockTick(clockType &clockToTick, timePartType timePart = timePartType::SECOND);
bool codeGradeLoopFix();
void makeClock();
bool validFormat(std::string format);
void resetStream();
bool validPart(std::string part);

int main()
{
    twelveHrClock tclock(11, 59, 0, PM);
    std::cout << tclock.tostring() << std::endl;
    clockTick(tclock, timePartType::MINUTE);
    std::cout << tclock.tostring() << std::endl;
    clockTick(tclock, timePartType::HOUR);
    std::cout << tclock.tostring() << std::endl;

    return 0;
}

void clockTick(clockType &clockToTick, timePartType timePart)
{
    switch (timePart)
    {
    case timePartType::HOUR:
        clockToTick.incrementHours();
        break;
    case timePartType::MINUTE:
        clockToTick.incrementMinutes();
        break;
    case timePartType::SECOND:
    default:
        clockToTick.incrementSeconds();
        break;
    }
}

bool codeGradeLoopFix()
{
    if (std::cin.eof())
    {
        std::cout << "Infinite loop detected. Out of input ending program." << std::endl;
        return true;
    }
    return false;
}

void makeClock()
{
    std::string format;
    timeType clockFormat = TWENTYFOUR;
    int hr, min, sec;
    std::string p;
    partType part = PM;
    std::cout << "Would you like a 12 hour clock or a 24 hour clock? " << std::endl;
    std::cin >> std::ws;
    getline(std::cin, format);
    while (!validFormat(format))
    {
        if (codeGradeLoopFix())
        {
            return;
        }
        std::cout << format << " is not a valid clock format." << std::endl;
        std::cout << "Would you like a 12 hour clock or a 24 hour clock? " << std::endl;
        std::cin >> std::ws;
        getline(std::cin, format);
    }
    std::transform(format.begin(), format.end(), format.begin(), ::tolower);
    for (int i = 0; i < 2; i++)
    {
        if (clockType::formatToStr[i] == format)
        {
            clockFormat = clockType::formats[i];
        }
    }
    std::cout << "What is the clock's hour? ";
    std::cin >> hr;
    if (clockFormat == TWENTYFOUR)
    {
        while (!std::cin || hr < 0 || hr > 23)
        {
            if (codeGradeLoopFix())
            {
                return;
            }
            else if (!std::cin)
            {
                resetStream();
            }
            std::cout << "Enter an hour between 0 and 24: ";
            std::cin >> hr;
        }
    }
    else
    {
        while (!std::cin || hr < 1 || hr > 12)
        {
            if (codeGradeLoopFix())
            {
                return;
            }
            else if (!std::cin)
            {
                resetStream();
            }
            std::cout << "Enter an hour between 1 and 12: ";
            std::cin >> hr;
        }
    }
    std::cout << "What is the clock's minute? ";
    std::cin >> min;
    // add input validation
    std::cout << "What is the clock's second? ";
    std::cin >> sec;
    // add input validation
    if (clockFormat == TWELVE)
    {
        std::cout << "Is it AM or PM? ";
        std::cin >> p;
        while (!validPart(p))
        {
            if (codeGradeLoopFix())
            {
                return;
            }
            std::cout << part << " is not a valid clock part." << std::endl;
            std::cout << "Is it AM or PM? ";
            std::cin >> p;
        }
        std::transform(p.begin(), p.end(), p.begin(), ::toupper);
        bool valid = false;
        for (int i = 0; i < 2; i++)
        {
            if (p == clockType::partToStr[i])
            {

                part = clockType::parts[i];
            }
        }
        twelveHrClock newClock(hr, min, sec, part);
        std::cout << newClock.tostring() << std::endl;
    }
    else
    {
        clockType newClock(hr, min, sec);
        std::cout << newClock.tostring() << std::endl;
    }
}

bool validFormat(std::string format)
{
    std::transform(format.begin(), format.end(), format.begin(), ::tolower);

    for (int i = 0; i < 2; i++)
    {
        if (clockType::formatToStr[i] == format)
            return true;
    }
    return false;
}

void resetStream()
{
    std::cout << "You entered something that is not a number." << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool validPart(std::string part)
{
    std::transform(part.begin(), part.end(), part.begin(), ::toupper);

    for (int i = 0; i < 2; i++)
    {
        if (part == clockType::partToStr[i])
        {
            return true;
        }
    }
    return false;
}
