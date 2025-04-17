#ifndef CLOCKEXCEPT_H
#define CLOCKEXCEPT_H
#include <stdexcept>
#include <string>

class invalid_minute : public std::invalid_argument
{
public:
    invalid_minute(int minute);
};

#endif