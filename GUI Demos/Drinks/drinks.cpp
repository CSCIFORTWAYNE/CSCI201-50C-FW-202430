#include "drinks.h"

drink::drink(baseType b, tempType t, sizeType s, std::string d)
{
    base = b;
    temperature = t;
    size = s;
    dairy = d;
}

std::string drink::getBaseStr() const
{
    return baseStr[base];
}

std::string drink::getTemperature() const
{
    return tempStr[temperature];
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
    std::ostringstream out;
    if(flavors.size() == 0)
    {
        return "None";
    }
    std::set<flavType>::const_iterator it = flavors.begin();
    out << flavStr[*it];
    for (++it; it != flavors.end(); ++it)
    {
        out << ", " << flavStr[*it];
    }
    return out.str();
}

double drink::getPrice() const
{
    double price = 0;
    switch (size)
    {
    case SMALL:
        price = 2;
        break;
    case MED:
        price = 3;
        break;
    case LARGE:
        price = 4;
        break;
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
        break;
    }
    switch (temperature)
    {
    case HOT:
        break;
    case ICE:
        price += .5;
        break;
    case BLEND:
        price += .75;
        break;
    }
    price += .25 * flavors.size();
    std::string lowerD = dairy;
    std::transform(lowerD.begin(), lowerD.end(), lowerD.begin(), ::tolower);
    if (lowerD == "whole milk")
    {
        price += .75;
    }
    else if (lowerD == "skim milk")
    {
        price += .75;
    }
    else if (lowerD == "cream")
    {
        price += 1.5;
    }
    else if (lowerD == "oat milk")
    {
        price += 2;
    }
    else if (lowerD == "almond milk")
    {
        price += 2;
    }
    else if(lowerD == "none" || lowerD == "")
    {
        price +=0;
    }
    else
    {
        price += .5;
    }

    return price;
}

void drink::setBase(baseType b)
{
    base = b;
}

void drink::setTemperature(tempType t)
{
    temperature = t;
}

void drink::setSize(sizeType s)
{
    size = s;
}

void drink::setDairy(std::string d)
{
    dairy = d;
}

void drink::addFlavor(flavType f)
{
    flavors.insert(f);
}

void drink::removeFlavor(flavType f)
{
    flavors.erase(f);
}

void drink::removeAllFlavor()
{
    flavors.clear();
}

std::string drink::tostring() const
{
    std::ostringstream out;
    out << std::setprecision(2) << std::fixed << std::showpoint;
    out << getSize() << " - " << getTemperature() << ", " << getBaseStr() << ", " << getDairy() << ", " << getFlavor()
        << " - $" << getPrice() << std::endl;
    return out.str();
}

std::ostream &operator<<(std::ostream &out, const drink &d)
{
    out << d.tostring();
    return out;
}
