#pragma once
#include "Configuration.h"
#include "TimeSpan.h"

class TextWriter
{
public:
    TextWriter(Configuration* configuration);
    ~TextWriter();
    void WriteToLogFile(TimeSpan tSpan);

private:
    Configuration* configuration;
};