#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <map>
#include <random>
#include "clock.h"
#include "drink.h"

/* int larger(int num1, int num2);
double larger(double num1, double num2);
long larger(long num1, long num2); */
// clockType larger(clockType num1, clockType num2);

// lecture activity fix the inputDrinkSize and inputDrinkTemp to use the new maps from drink

template <class comparableType>
comparableType larger(comparableType item1, comparableType item2);

drink::sizeType inputDrinkSize();
drink::baseType inputDrinkBase();
drink::tempType inputDrinkTemperature();
std::string inputDrinkFlavor();
std::string inputDrinkDairy();
bool numInRange(int num, int lower, int upper);
bool numGT0(int num, int = 0, int = 0);
bool negNum(int num, int = 0, int = 0);
int inputInt(std::string prompt, std::string err, bool (*func)(int, int, int), int lower = 0, int upper = 0);

int main()
{
    // std::vector<int> intVector;
    std::vector<clockType *> timeClockIn;
    std::vector<clockType *> timeClockOut;
    srand(time(0));
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    double a = distribution(generator);
    double b = distribution(generator);
    double largerDouble = larger(a, b);
    std::cout << "The larger value is " << largerDouble << " from a = " << a << " and b = " << b << std::endl;
    int x = rand() % 10 + 1;
    int y = rand() % 10 + 1;
    int largerInt = larger(x, y);
    std::cout << "The larger value is " << largerInt << " from x = " << x << " and y = " << y << std::endl;

    std::uniform_int_distribution<int> distributionClockType(1, 2);
    std::uniform_int_distribution<int> distributionClockNum(1, 100);
    std::uniform_int_distribution<int> distributionClock24Hr(0, 23);
    std::uniform_int_distribution<int> distributionClock12Hr(1, 12);
    std::uniform_int_distribution<int> distributionClockMin(0, 59);

    int numClocks = distributionClockNum(generator);
    for (int i = 0; i < numClocks; i++)
    {
        clockType *clock;
        timeType clockT = clockType::intToTimeType.at(distributionClockType(generator) * 12);
        int min = distributionClockMin(generator);
        int sec = distributionClockMin(generator);
        if (clockT == TWELVE)
        {
            int hr = distributionClock12Hr(generator);
            partType part = clockType::intToPartType.at(distributionClockType(generator));
            clock = new twelveHrClock(hr, min, sec, part);
        }
        else
        {
            int hr = distributionClock24Hr(generator);
            clock = new twentyFourHrClock(hr, min, sec);
        }
        timeClockIn.push_back(clock);
    }

    for (int i = 0; i < timeClockIn.size(); i++)
    {
        std::cout << *(timeClockIn[i]) << std::endl;
    }

    // twelveHrClock c = larger(*timeClockIn[0], *timeClockIn[1]);
    // std::cout << c << std::endl;

    /* for (int i = 0; i < 52; i++)
    {
        int randNum = rand() % 100 + 1;
        intVector.push_back(randNum);
        std::cout << intVector[i] << std::endl;
    } */
    // clockType largerClock = larger(clockType(1, 0, 0), clockType(2, 0, 0));

    drink newDrink(inputDrinkBase(), inputDrinkTemperature(), inputDrinkSize(), inputDrinkDairy(), inputDrinkFlavor());
    return 0;
}

template <class comparableType>
comparableType larger(comparableType item1, comparableType item2)
{
    if (item1 > item2)
    {
        return item1;
    }
    return item2;
}

/* int larger(int num1, int num2)
{
    if (num1 > num2)
    {
        return num1;
    }
    return num2;
}

double larger(double num1, double num2)
{
    if (num1 > num2)
    {
        return num1;
    }
    return num2;
}

long larger(long num1, long num2)
{
    if (num1 > num2)
    {
        return num1;
    }
    return num2;
}

clockType &larger(clockType &num1, clockType &num2)
{
    if (num1 > num2)
    {
        return num1;
    }
    return num2;
} */

drink::sizeType inputDrinkSize()
{

    return drink::MED;
}

drink::baseType inputDrinkBase()
{
    std::string inputBase;
    std::cout << "Would you like ";
    std::map<drink::baseType, std::string>::const_iterator it = drink::baseToStr.begin();
    std::cout << it->second;
    for (++it; it != drink::baseToStr.end(); ++it)
    {
        auto itCpy = it;
        ++itCpy;
        if (itCpy == drink::baseToStr.end())
        {
            std::cout << ", or ";
        }
        else
        {
            std::cout << ", ";
        }
        std::cout << it->second;
    }
    std::cout << "? ";
    std::cin >> std::ws;
    getline(std::cin, inputBase);
    std::transform(inputBase.begin(), inputBase.end(), inputBase.begin(), ::toupper);
    while (!drink::strToBase.count(inputBase))
    {
        std::cout << inputBase << " is not a valid choice" << std::endl;
        it = drink::baseToStr.begin();
        std::cout << it->second;
        for (++it; it != drink::baseToStr.end(); ++it)
        {
            auto itCpy = it;
            ++itCpy;
            if (itCpy == drink::baseToStr.end())
            {
                std::cout << ", or";
            }
            else
            {
                std::cout << ", ";
            }
            std::cout << it->second;
        }
        std::cout << "? ";
        std::cin >> std::ws;
        getline(std::cin, inputBase);
        std::transform(inputBase.begin(), inputBase.end(), inputBase.begin(), ::toupper);
    }

    return drink::strToBase.at(inputBase);
}

drink::tempType inputDrinkTemperature()
{

    return drink::ICE;
}

std::string inputDrinkFlavor()
{
    std::string flavor;
    std::cout << "Please enter a flavor for your drink: ";
    std::cin >> std::ws;
    std::getline(std::cin, flavor);
    return flavor;
}

std::string inputDrinkDairy()
{
    std::string dairy;
    std::cout << "What kind of dairy would you like? ";
    std::cin >> std::ws;
    std::getline(std::cin, dairy);
    return dairy;
}

bool numInRange(int num, int lower, int upper)
{

    return num >= lower && num <= upper;
}

bool numGT0(int num, int, int)
{
    return num > 0;
}

bool negNum(int num, int, int)
{
    return num < 0;
}

int inputInt(std::string prompt, std::string err, bool (*func)(int, int, int), int lower, int upper)
{
    int input;
    std::cout << prompt;
    std::cin >> input;
    std::cout << std::endl;
    while (!std::cin || !func(input, lower, upper))
    {
        if (!std::cin)
        {
            std::cout << "You entered something that is not a number." << std::endl;
            // resetStream();
        }
        std::cout << err << std::endl;
        std::cout << prompt;
        std::cin >> input;
        std::cout << std::endl;
    }
    return input;
}
