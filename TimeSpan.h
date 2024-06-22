#pragma once
#include <chrono>
#include <string>

struct TimeSpan
{
    std::chrono::system_clock::time_point start;
    std::chrono::system_clock::time_point stop;

    std::chrono::seconds duration();
    std::string TimePointToString(const std::chrono::system_clock::time_point& timePoint);
};
