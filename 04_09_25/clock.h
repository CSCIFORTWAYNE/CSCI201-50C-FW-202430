#ifndef CLOCK_H
#define CLOCK_H
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>

enum timeType
{
    TWELVE = 12,
    TWENTYFOUR = 24
};
enum partType
{
    AM,
    PM
};

class clockType
{
public:
    clockType(int = 0, int = 0, int = 0);

    void setTime(int, int, int);
    void getTime(int &, int &, int &) const;
    // void printTime() const;
    virtual std::string tostring() const;
    void incrementSeconds();
    void incrementMinutes();
    virtual void incrementHours() = 0;
    virtual void invalidHour() = 0;
    bool equalTime(const clockType &) const;
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    virtual void setHour(int h);
    void setMinute(int m);
    void setSecond(int s);
    virtual bool validHr() const = 0;
    bool validMin() const;
    bool validSec() const;
    // bool operator==(const clockType &rightClock) const = 0;

    static timeType formats[2];
    static partType parts[2];
    static std::string formatToStr[2];
    static std::string partToStr[2];

protected:
    int hr;
    int min;
    int sec;
};

class twelveHrClock : public clockType
{
public:
    twelveHrClock(int h, int m, int s, partType part);
    bool validHr() const;
    void setHour(int h);
    void invalidHour();
    void incrementHours();
    std::string tostring() const;
    std::string getPartOfDay() const;
    void setPartOfDay(std::string);

    void setTime(int, int, int, partType);
    // bool operator==(const twelveHrClock &rightClock) const;
    friend bool operator==(const twelveHrClock &leftClock, const twelveHrClock &rightClock);

private:
    partType partOfDay;
};

class twentyFourHrClock : public clockType
{
public:
    twentyFourHrClock(int h, int m, int s);
    void incrementHours();
    void invalidHour();
    bool validHr() const;
};
#endif