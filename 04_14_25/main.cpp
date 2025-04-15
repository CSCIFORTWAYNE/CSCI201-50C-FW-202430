#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
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
    std::vector<int> intVector;
    srand(time(0));

    int x = rand() % 10 + 1;
    int y = rand() % 10 + 1;
    int largerInt = larger(x, y);
    std::cout << "The larger value is " << largerInt << " from x = " << x << " and y = " << y << std::endl;

    for (int i = 0; i < 52; i++)
    {
        int randNum = rand() % 100 + 1;
        intVector.push_back(randNum);
        std::cout << intVector[i] << std::endl;
    }
    // clockType largerClock = larger(clockType(1, 0, 0), clockType(2, 0, 0));
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
    std::ostringstream out;

    out << "Please choose the drink size:" << std::endl;
    for (int i = 0; i < ENUM_NUM; i++)
    {
        out << i + 1 << ": " << sizeStr[i] << std::endl;
    }
    int drinkSize = inputInt(out.str(), "That is not a valid drink Size!", numInRange, 1, 3);

    return sizes[drinkSize - 1];
}

drink::baseType inputDrinkBase()
{
    std::string inputBase;
    std::cout << "Would you like Coffee, Tea, or Cream? ";
    std::cin >> std::ws;
    getline(std::cin, inputBase);
    std::transform(inputBase.begin(), inputBase.end(), inputBase.begin(), ::toupper);
    while (!drink::strToBase.count(inputBase))
    {
        std::cout << inputBase << " is not a valid choice" << std::endl;
        std::cout << "Would you like Coffee, Tea, or Cream? ";
        std::cin >> std::ws;
        getline(std::cin, inputBase);
        std::transform(inputBase.begin(), inputBase.end(), inputBase.begin(), ::toupper);
    }

    return drink::strToBase.at(inputBase);
}

drink::tempType inputDrinkTemperature()
{
    std::ostringstream out;
    int drinkTemp;
    out << "Please choose the drink temperature:" << std::endl;
    for (int i = 0; i < ENUM_NUM; i++)
    {
        out << i + 1 << ": " << tempStr[i] << std::endl;
    }
    drinkTemp = inputInt(out.str(), "That is not a valid drink temperature!", numInRange, 1, 3);

    return temps[drinkTemp - 1];
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
            resetStream();
        }
        std::cout << err << std::endl;
        std::cout << prompt;
        std::cin >> input;
        std::cout << std::endl;
    }
    return input;
}
