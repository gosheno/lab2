#pragma once
#include <string>
#include <sstream>
template <typename T>
std::string toString(T val)
{
    std::ostringstream oss;
    oss << val;
    return oss.str();
}

