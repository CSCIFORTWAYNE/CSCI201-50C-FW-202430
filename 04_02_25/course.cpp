#include "course.h"

course::course(deptType dept, int courseNum, std::string sectNum, const dayType days[], int numDays, int startHour, int startMin, int endHour, int endMin, std::string building, std::string campus, int roomNum)
{
    this->dept = dept;
    this->courseNum = courseNum;
    this->sectNum = sectNum;
    this->numDays = numDays;
    this->days = new dayType[numDays];
    for (int i = 0; i < this->numDays; i++)
    {
        this->days[i] = days[i];
    }
    this->startHour = startHour;
    this->startMin = startMin;
    this->endHour = endHour;
    this->endMin = endMin;
    this->classroom = new room(campus, building, roomNum);
}

room course::getClassroom() const
{
    return *classroom;
}

course::~course()
{
    // delete[] days;
    delete classroom;
}

course::course(const course &otherCourse)
{
    this->dept = otherCourse.dept;
    this->courseNum = otherCourse.courseNum;
    this->sectNum = otherCourse.sectNum;
    this->numDays = otherCourse.numDays;
    this->days = new dayType[numDays];
    for (int i = 0; i < this->numDays; i++)
    {
        this->days[i] = otherCourse.days[i];
    }
    this->startHour = otherCourse.startHour;
    this->startMin = otherCourse.startMin;
    this->endHour = otherCourse.endHour;
    this->endMin = otherCourse.endMin;
    this->classroom = new room(*(otherCourse.classroom));
}