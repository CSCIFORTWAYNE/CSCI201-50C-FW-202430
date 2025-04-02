#include <iostream>
#include <limits>
#include "drink.h"
#include "course.h"

void myFunc(int *p);
void resetStream();
sizeType inputDrinkSize();
baseType inputDrinkBase();
tempType inputDrinkTemperature();
std::string inputDrinkFlavor();
std::string inputDrinkDairy();
bool numInRange(int num, int lower, int upper);
bool numGT0(int num, int = 0, int = 0);
bool negNum(int num, int = 0, int = 0);
int inputInt(std::string prompt, std::string err, bool (*func)(int, int, int), int lower = 0, int upper = 0);

int main()
{

    drink *d = new drink(inputDrinkBase(), inputDrinkTemperature(), inputDrinkSize(), inputDrinkDairy(), inputDrinkFlavor());
    drink *yourDrink = d;
    yourDrink->setBase(TEA);
    std::cout << d->tostring() << std::endl;
    std::cout << yourDrink->tostring() << std::endl;

    // course **schedule;
    // schedule = new course *[2];
    dayType days[2] = {m, w};
    // schedule[0] = new course(CSCI, 201, "50C", days, 2, 6, 0, 9, 50, "FWCCC", "C", 2312);
    // schedule[1] = new course(CSCI, 101, "50C", days, 2, 6, 0, 9, 50, "FWCCC", "C", 2378);
    course c1(CSCI, 201, "50C", days, 2, 6, 0, 9, 50, "FWCCC", "C", 2312);
    course c2(CSCI, 101, "50C", days, 2, 6, 0, 9, 50, "FWCCC", "C", 2378);
    course c3 = c2;
    //*(schedule[1]) = *(schedule[0]);
    // delete schedule[0];
    // schedule[1]->getClassroom();

    return 0;
}

void myFunc(int *p)
{
    *p = 192;
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

sizeType inputDrinkSize()
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

baseType inputDrinkBase()
{
    std::ostringstream out;
    out << "Please choose the drink base:" << std::endl;
    for (int i = 0; i < ENUM_NUM; i++)
    {
        out << i + 1 << ": " << baseStr[i] << std::endl;
    }
    int drinkBase = inputInt(out.str(), "That is not a valid drink base", numInRange, 1, 3);

    return bases[drinkBase - 1];
}

tempType inputDrinkTemperature()
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
