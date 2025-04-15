#include "drink.h"

const std::map<drink::baseType, std::string> drink::baseToStr = {{drink::COFFEE, "Coffee"},
                                                                 {drink::TEA, "Tea"},
                                                                 {drink::CREAM, "Cream"}};

const std::map<std::string, drink::baseType> drink::strToBase = {{"COFFEE", drink::COFFEE},
                                                                 {"TEA", drink::TEA},
                                                                 {"CREAM", drink::CREAM}};
const std::map<drink::sizeType, std::string> drink::sizeToStr = {{drink::SMALL, "Small"},
                                                                 {drink::MED, "Medium"},
                                                                 {drink::LARGE, "Large"}};
const std::map<std::string, drink::sizeType> drink::strToSize = {{"SMALL", drink::SMALL},
                                                                 {"MEDIUM", drink::MED},
                                                                 {"LARGE", drink::LARGE}};
;
const std::map<drink::tempType, std::string> drink::tempToStr = {{drink::HOT, "Hot"},
                                                                 {drink::ICE, "Iced"},
                                                                 {drink::BLEND, "Blended"}};
const std::map<std::string, drink::tempType> drink::strToTemp = {{"HOT", drink::HOT},
                                                                 {"ICED", drink::ICE},
                                                                 {"BLENDED", drink::BLEND}};

int drink::numDrinks = 0;

std::string drink::getBaseStr() const
{
    return baseToStr.at(base);
}

std::string drink::getTemperature() const
{
    return tempToStr.at(temperature);
}

drink::drink(baseType b, tempType t, sizeType s, std::string d, std::string f)
{
    setBase(b);
    setTemperature(t);
    setSize(s);
    setDairy(d);
    setFlavor(f);
}

std::string drink::getSize() const
{
    return sizeToStr.at(size);
}
std::string drink::getDairy() const
{
    return dairy;
}
std::string drink::getFlavor() const
{
    return flavor;
}
/* drink::drink()
{
    setBase(COFFEE);
    setSize(LARGE);
    setTemperature(HOT);
    dairy = "";
    flavor = "";
} */
double drink::getPrice() const
{
    double price = 0;
    switch (size)
    {
    case SMALL:
        price += 2.00;
        break;
    case MED:
        price += 3.00;
        break;
    case LARGE:
        price += 4.00;
        break;
    default:
        price += 4.00;
    }

    switch (base)
    {
    case COFFEE:
        price += 2.75;
        break;
    case TEA:
        price += 1.75;
        break;
    case CREAM:
        price += 0;
        break;
    }
    switch (temperature)
    {
    case HOT:
        price += 0;
        break;
    case ICE:
        price += 0.5;
        break;
    case BLEND:
        price += 0.75;
        break;
    }
    if (!flavor.empty())
    {
        price += .5;
    }
    std::string dairyCpy = dairy;
    std::transform(dairyCpy.begin(), dairyCpy.end(), dairyCpy.begin(), ::tolower);
    if (dairyCpy == "whole milk")
    {
        price += .5;
    }
    else if (dairyCpy == "skim milk")
    {
        price += .75;
    }
    else if (dairyCpy == "cream")
    {
        price += 1.5;
    }
    else if (dairyCpy == "oat milk" || dairyCpy == "almond milk")
    {
        price += 2.0;
    }
    else
    {
        price += .5;
    }

    return price;
}

void drink::setBase(baseType b)
{
    if (baseToStr.count(b) == 1)
    {
        base = b;
    }
    else
    {
        base = drink::COFFEE;
    }
}

void drink::setTemperature(tempType t)
{
    if (tempToStr.count(t) == 1)
    {
        temperature = t;
    }
    else
    {
        temperature = HOT;
    }
}

void drink::setDairy(std::string d)
{
    dairy = d;
}

void drink::setSize(sizeType s)
{
    if (sizeToStr.count(s) == 1)
    {
        size = s;
    }
    else
    {
        size = LARGE;
    }
}

void drink::setFlavor(std::string f)
{
    flavor = f;
}

std::string drink::tostring() const
{
    std::ostringstream out;
    out << std::setprecision(2) << std::fixed << std::showpoint;
    out << "Size: " << getSize() << std::endl;
    out << "Base: " << getBaseStr() << std::endl;
    out << "Temperature: " << getTemperature() << std::endl;
    out << "Flavor: " << flavor << std::endl;
    out << "Dairy: " << dairy << std::endl;
    out << "Price: " << getPrice() << std::endl;

    return out.str();
}