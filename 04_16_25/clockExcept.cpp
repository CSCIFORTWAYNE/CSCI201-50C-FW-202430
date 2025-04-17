#include "clockExcept.h"

invalid_minute::invalid_minute(int minute) : std::invalid_argument(std::to_string(minute) + " is not between 0 and 59. Invalid Minute Exception Thrown.")
{
}