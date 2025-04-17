#include "clock.h"

const std::map<int, timeType> clockType::intToTimeType = {{12, TWELVE}, {24, TWENTYFOUR}};
const std::map<int, partType> clockType::intToPartType = {{1, AM}, {2, PM}};

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

void twentyFourHrClock::incrementHours()
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
    int oldmin = min;
    min = m;
    if (!validMin())
    {
        min = oldmin;
        throw invalid_minute(m);
        }
}

void clockType::setSecond(int s)
{

    sec = s;
    if (!validSec())
    {
        /* std::cout << "Seconds must be between 0 and 59" << std::endl;
        std::cout << "Defaulting to 0." << std::endl; */
        sec = 0;
        throw std::invalid_argument("Seconds must be between 0 and 59");
    }
}

/* clockType::clockType(int h, int m, int s)
{
    setMinute(m);
    setSecond(s);
    // setHour(h);
    hr = h;
    // setTime(h, m, s);
} */

bool twentyFourHrClock::validHr() const
{

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

void twentyFourHrClock::invalidHour()
{

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
twelveHrClock::twelveHrClock(int h, int m, int s, partType part)
{
    setTime(h, m, s, part);
    if (!validHr())
    {
        invalidHour();
    }
    // partOfDay = part;
}
void twelveHrClock::setHour(int h)
{
    hr = h;
    if (!validHr())
    {
        invalidHour();
    }
}

std::string twelveHrClock::tostring() const
{
    return clockType::tostring() + " " + partToStr[partOfDay];
}

std::string twelveHrClock::getPartOfDay() const
{
    return partToStr[partOfDay];
}
void twelveHrClock::setPartOfDay(std::string part)
{
    std::string partCpy = part;
    std::transform(partCpy.begin(), partCpy.end(), partCpy.begin(), ::toupper);
    bool valid = false;
    for (int i = 0; i < 2; i++)
    {
        if (partCpy == partToStr[i])
        {
            valid = true;
            partOfDay = parts[i];
        }
    }
    if (!valid)
    {
        std::cout << part << " is not a valid part of day. Your choices are AM or PM. Defaulting to PM." << std::endl;
        partOfDay = PM;
    }
}

void twelveHrClock::setTime(int hr, int min, int sec, partType part)
{
    clockType::setTime(hr, min, sec);
    partOfDay = part;
}

void twelveHrClock::incrementHours()
{
    hr++;
    if (hr == 12)
    {
        if (partOfDay == AM)
        {
            partOfDay = PM;
        }
        else
        {
            partOfDay = AM;
        }
    }
    else if (hr > 12)
    {
        hr = 1;
    }
}

twentyFourHrClock::twentyFourHrClock(int h, int m, int s)
{
    setTime(h, m, s);
}

/* bool twelveHrClock::operator==(const twelveHrClock &rightClock) const
{
    if (this->partOfDay != rightClock.partOfDay)
    {
        return false;
    }
    return this->hr == rightClock.hr && this->min == rightClock.min && this->sec == rightClock.sec;
} */

bool operator==(const twelveHrClock &leftClock, const twelveHrClock &rightClock)
{
    if (leftClock.partOfDay != rightClock.partOfDay)
    {
        return false;
    }
    return leftClock.hr == rightClock.hr && leftClock.min == rightClock.min && leftClock.sec == rightClock.sec;
}

bool twelveHrClock::operator==(const twentyFourHrClock &rightClock) const
{
    int standardHour = hr;

    if (standardHour == 12)
    {
        standardHour = 0;
    }
    if (partOfDay == PM)
    {
        standardHour = standardHour + 12;
    }
    return standardHour == rightClock.getHour() && this->min == rightClock.getMinute() && this->sec == rightClock.getSecond();
}

bool operator==(const twentyFourHrClock &leftclock, const twelveHrClock &rightClock)
{
    return rightClock == leftclock;
}

std::ostream &operator<<(std::ostream &outputStream, const clockType &clockToPrint)
{
    outputStream << clockToPrint.tostring();
    return outputStream;
}

std::ostream &operator<<(std::ostream &out, const twelveHrClock &clockToPrint)
{
    out << clockToPrint.tostring(); // << " " << clockType::partToStr[clockToPrint.partOfDay];
    return out;
}

std::istream &operator>>(std::istream &inputStream, clockType &clockToInput)
{
    int hour = 0;
    int minute = 0;
    int second = 0;
    inputStream >> hour >> minute >> second;
    clockToInput.setTime(hour, minute, second);
    return inputStream;
}

const clockType &clockType::operator=(const clockType &rightClock)
{
    if (this != &rightClock)
    {
        this->hr = rightClock.hr;
        this->min = rightClock.min;
        this->sec = rightClock.sec;
    }
    return *this;
}

const twentyFourHrClock &twentyFourHrClock::operator=(const twelveHrClock &rightClock)
{

    this->hr = rightClock.convertTo24Hr();
    this->min = rightClock.getMinute();
    this->sec = rightClock.getSecond();
    return *this;
}

twentyFourHrClock::twentyFourHrClock(const twelveHrClock &otherClock)
{
    this->hr = otherClock.convertTo24Hr();
    this->min = otherClock.getMinute();
    this->sec = otherClock.getSecond();
}
int twentyFourHrClock::convertTo24Hr() const
{
    return hr;
}

int twelveHrClock::convertTo24Hr() const
{
    int standardHour = hr;

    if (standardHour == 12)
    {
        standardHour = 0;
    }
    if (partOfDay == PM)
    {
        standardHour = standardHour + 12;
    }
    return standardHour;
}

twelveHrClock::twelveHrClock(const twentyFourHrClock &otherClock)
{
    convertTo12Hr(otherClock.getHour());
    this->min = otherClock.getMinute();
    this->sec = otherClock.getSecond();
}

void twelveHrClock::convertTo12Hr(int h)
{
    if (h >= 12)
    {
        partOfDay == PM;
        if (h != 12)
        {
            h -= 12;
        }
    }
    else
    {
        partOfDay == AM;
    }
    hr = h;
}

const twelveHrClock &twelveHrClock::operator=(const twelveHrClock &rightClock)
{
    if (this != &rightClock)
    {
        this->hr = rightClock.hr;
        this->min = rightClock.min;
        this->sec = rightClock.sec;
        this->partOfDay = rightClock.partOfDay;
    }
    return *this;
}
const twelveHrClock &twelveHrClock::operator=(const twentyFourHrClock &rightClock)
{
    convertTo12Hr(rightClock.getHour());
    this->min = rightClock.getMinute();
    this->sec = rightClock.getMinute();
    return *this;
}

twentyFourHrClock twentyFourHrClock::operator++()
{
    this->incrementSeconds();
    return *this;
}

twentyFourHrClock twentyFourHrClock::operator++(int)
{
    twentyFourHrClock cpy = *this;
    this->incrementSeconds();
    return cpy;
}

twentyFourHrClock twentyFourHrClock::operator+(int secondsToAdd)
{
    for (int i = 0; i < secondsToAdd; i++)
    {
        incrementSeconds();
    }
    return *this;
}

twentyFourHrClock operator+(int secondsToAdd, twentyFourHrClock &rightClock)
{
    return rightClock + secondsToAdd;
}

bool operator>(const clockType &leftClock, const clockType &rightclock)
{
    int leftHr = leftClock.convertTo24Hr();
    int rightHr = rightclock.convertTo24Hr();
    if (leftHr < rightHr)
    {
        return false;
    }
    if (leftHr > rightHr)
    {
        return true;
    }
    else if (leftClock.min > rightclock.min)
    {
        return true;
    }
    else if (leftClock.min < rightclock.min)
    {
        return false;
    }
    else if (leftClock.sec > rightclock.sec)
    {
        return true;
    }
    else
        return false;
}
