#ifndef DRINKORDER_H
#define DRINKORDER_H

#include "drink.h"
#include <string>
#include <sstream>

class drinkOrder
{
public:
    drinkOrder();
    drinkOrder(const drinkOrder &);
    ~drinkOrder();
    void addDrink(const drink &);
    std::string tostring() const;
    void removeLastDrink();

private:
    drink **drinks;
    int numDrinks;
};

#endif