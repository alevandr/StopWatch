#include "TextWriter.h"
#include <iostream>
#include <fstream>
#include <algorithm>

TextWriter::TextWriter(Configuration* configuration)
{
    this->configuration = configuration;
}

TextWriter::~TextWriter()
{
}

void TextWriter::WriteToLogFile(TimeSpan tSpan) // try "chrono::cast" instead of "seconds / 60 / 60"
{
    std::ofstream file;
    file.open(configuration->LogFilePath(), std::ios::app);

    auto seconds = tSpan.duration();

    std::string first = tSpan.TimePointToString(tSpan.start) + " / " + tSpan.TimePointToString(tSpan.stop) + "\n";
    file.write(first.c_str(), first.size());

    std::string second = std::to_string(seconds.count() / 60 / 60) + ":" + std::to_string(seconds.count() / 60) + ":" + std::to_string(seconds.count() % 60) + "\n";
    file.write(second.c_str(), second.size());

    const auto& GetShortSummary = []() {
        std::cout << "Please, enter short summary: " << std::endl;
        std::string summary;
        std::getline(std::cin, summary);
        std::replace(summary.begin(), summary.end(), '\"', '\'');
        return summary;
        };

    std::string summary = GetShortSummary() + "\n\n";
    file.write(summary.c_str(), summary.size());

    file.close();
}