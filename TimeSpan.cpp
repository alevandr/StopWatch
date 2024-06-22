#include "TimeSpan.h"

std::chrono::seconds TimeSpan::duration()
{
    return std::chrono::duration_cast<std::chrono::seconds>(stop - start);
}

std::string TimeSpan::TimePointToString(const std::chrono::system_clock::time_point& timePoint)
{
    std::time_t t = std::chrono::system_clock::to_time_t(timePoint);
    char tmBuff[30];
    ctime_s(tmBuff, sizeof(tmBuff), &t);
    std::string result(tmBuff);
    result.resize(result.size() - 1);
    return result;
}