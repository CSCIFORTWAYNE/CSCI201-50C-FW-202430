#ifndef COURSE_H
#define COURSE_H
#include "room.h"
#include <string>
#include <map>
#include <sstream>
#include <iomanip>
#include <iostream>
enum deptType
{
    CSCI,
    DBMS,
    INFM,
    SDEV
};
enum dayType
{
    m,
    t,
    w,
    r,
    f
};

class course
{
public:
    course(deptType dept, int courseNum, std::string sectNum, const dayType days[], int numDays, int startHour, int startMin, int endHour, int endMin, std::string building, std::string campus, int roomNum);
    course(const course &otherCourse);
    room getClassroom() const;

    ~course();

private:
    deptType dept;
    int courseNum;
    std::string sectNum;
    dayType *days;
    int numDays;
    int startHour;
    int startMin;
    int endHour;
    int endMin;
    room *classroom;
};

#endif