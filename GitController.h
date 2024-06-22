#pragma once
#include "Configuration.h"

class GitController
{
public:
    GitController(Configuration* configuration);
    ~GitController();
    void UpdateRepository(std::string message);

private:
    Configuration* configuration;
};