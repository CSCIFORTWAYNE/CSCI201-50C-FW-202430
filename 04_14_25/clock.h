#ifndef CLOCK_H
#define CLOCK_H
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <stdexcept>

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
    friend std::ostream &operator<<(std::ostream &outputStream, const clockType &clockToPrint);
    friend std::istream &operator>>(std::istream &inputStream, clockType &clockToInput);
    const clockType &operator=(const clockType &);
    int convertTo24Hr(int hr, partType part);
    // friend bool operator>(const clockType &leftClock, const clockType &rightclock);

protected:
    int hr;
    int min;
    int sec;
    virtual std::string tostring() const;
};
class twelveHrClock;
class twentyFourHrClock : public clockType
{
public:
    twentyFourHrClock(int h, int m, int s);
    twentyFourHrClock(const twelveHrClock &);
    void incrementHours();
    void invalidHour();
    bool validHr() const;
    const twentyFourHrClock &operator=(const twelveHrClock &rightClock);
    twentyFourHrClock operator++();
    twentyFourHrClock operator++(int);
    twentyFourHrClock operator+(int);
    friend twentyFourHrClock operator+(int, twentyFourHrClock &);
    // letcture activity functions
    friend bool operator>(const twentyFourHrClock &leftClock, const twentyFourHrClock &rightclock);
    friend bool operator>(const twentyFourHrClock &leftClock, const twelveHrClock &rightclock);
    friend bool operator>(const twelveHrClock &leftClock, const twentyFourHrClock &rightclock);
    friend bool operator>=(const twentyFourHrClock &leftClock, const twentyFourHrClock &rightclock);
    friend bool operator>=(const twentyFourHrClock &leftClock, const twelveHrClock &rightclock);
    friend bool operator>=(const twelveHrClock &leftClock, const twentyFourHrClock &rightclock);
    friend bool operator<(const twentyFourHrClock &leftClock, const twentyFourHrClock &rightclock);
    friend bool operator<(const twentyFourHrClock &leftClock, const twelveHrClock &rightclock);
    friend bool operator<(const twelveHrClock &leftClock, const twentyFourHrClock &rightclock);
    friend bool operator<=(const twentyFourHrClock &leftClock, const twentyFourHrClock &rightclock);
    friend bool operator<=(const twentyFourHrClock &leftClock, const twelveHrClock &rightclock);
    friend bool operator<=(const twelveHrClock &leftClock, const twentyFourHrClock &rightclock);
};

class twelveHrClock : public clockType
{
public:
    twelveHrClock(int h, int m, int s, partType part);
    twelveHrClock(const twentyFourHrClock &otherClock);
    bool validHr() const;
    void setHour(int h);
    void invalidHour();
    void incrementHours();
    void convertTo12Hr(int h);
    const twelveHrClock &operator=(const twelveHrClock &rightClock);
    const twelveHrClock &operator=(const twentyFourHrClock &rightClock);

    std::string getPartOfDay() const;
    partType getPart() const { return partOfDay; };
    void setPartOfDay(std::string);

    void setTime(int, int, int, partType);
    // bool operator==(const twelveHrClock &rightClock) const;
    friend bool operator==(const twelveHrClock &leftClock, const twelveHrClock &rightClock);
    bool operator==(const twentyFourHrClock &rightClock) const;
    friend bool operator==(const twentyFourHrClock &leftclock, const twelveHrClock &rightClock);
    friend std::ostream &operator<<(std::ostream &out, const twelveHrClock &clockToPrint);

    // lecture activity functions
    bool operator!=(const twelveHrClock);
    // friend bool operator>(const twelveHrClock &leftClock, const twelveHrClock &rightclock);
    friend bool operator>(const twentyFourHrClock &leftClock, const twelveHrClock &rightclock);
    friend bool operator>(const twelveHrClock &leftClock, const twentyFourHrClock &rightclock);
    friend bool operator>=(const twelveHrClock &leftClock, const twelveHrClock &rightclock);
    friend bool operator>=(const twentyFourHrClock &leftClock, const twelveHrClock &rightclock);
    friend bool operator>=(const twelveHrClock &leftClock, const twentyFourHrClock &rightclock);
    friend bool operator<(const twelveHrClock &leftClock, const twelveHrClock &rightclock);
    friend bool operator<(const twentyFourHrClock &leftClock, const twelveHrClock &rightclock);
    friend bool operator<(const twelveHrClock &leftClock, const twentyFourHrClock &rightclock);
    friend bool operator<=(const twelveHrClock &leftClock, const twelveHrClock &rightclock);
    friend bool operator<=(const twentyFourHrClock &leftClock, const twelveHrClock &rightclock);
    friend bool operator<=(const twelveHrClock &leftClock, const twentyFourHrClock &rightclock);

private:
    partType partOfDay;
    std::string tostring() const;
};

#endif