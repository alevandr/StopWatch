#include "Configuration.h"
#include "json.hpp"
#include <fstream>

Configuration::Configuration(std::string configurationPath)
{
    std::ifstream f(configurationPath);
    nlohmann::json data = nlohmann::json::parse(f);
    RepositoryPath = data["RepositoryPath"];
    LogFileName = data["FileName"];
}

Configuration::~Configuration()
{
}

std::string Configuration::GetRepositoryPath()
{
    return RepositoryPath;
}

std::string Configuration::LogFilePath()
{
    return RepositoryPath + LogFileName;
}