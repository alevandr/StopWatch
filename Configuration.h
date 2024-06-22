#pragma once
#include <string>

class Configuration
{
public:
    Configuration(std::string configurationPath);
    ~Configuration();
    std::string GetRepositoryPath();
    std::string LogFilePath();

private:
    std::string RepositoryPath;
    std::string LogFileName;
};