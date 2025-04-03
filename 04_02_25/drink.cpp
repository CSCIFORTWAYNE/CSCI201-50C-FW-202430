#include "drink.h"

int drink::numDrinks = 0;

std::string drink::getBaseStr() const
{
    return baseStr[base];
}

std::string drink::getTemperature() const
{
    return tempStr[temperature];
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
    return sizeStr[size];
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
    bool set = false;
    for (int i = 0; i < ENUM_NUM; i++)
    {
        if (b == bases[i])
        {
            base = b;
            set = true;
            break;
        }
    }
    if (!set)
    {
        base = COFFEE;
    }
}

void drink::setTemperature(tempType t)
{
    bool set = false;
    for (int i = 0; i < ENUM_NUM; i++)
    {
        if (t == temps[i])
        {
            temperature = t;
            set = true;
            break;
        }
    }
    if (!set)
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
    bool set = false;
    for (int i = 0; i < ENUM_NUM; i++)
    {
        if (s == sizes[i])
        {
            size = s;
            set = true;
            break;
        }
    }
    if (!set)
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
    out << "Price: $" << getPrice() << std::endl;

    return out.str();
}