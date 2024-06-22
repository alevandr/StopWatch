#pragma
#include <iostream>
#include <Windows.h>
#include "Configuration.h"
#include "TextWriter.h"
#include "GitController.h"


int main()
{
    bool TimerWasStarted = false;
    const auto& ctrl = []() { return GetAsyncKeyState(0x11); };
    const auto& alt = []() { return GetAsyncKeyState(0x12); };
    const auto& S = []() { return GetAsyncKeyState(0x53); };
    const auto& F = []() { return GetAsyncKeyState(0x46); };

    const auto& StartTimer = [ctrl, alt, S]() { return ctrl() && alt() && S(); };
    const auto& StopTimer = [ctrl, alt, F]() { return ctrl() && alt() && F(); };

    Configuration configuration("configuration.json");

    TimeSpan timeSpan;
    timeSpan.start = std::chrono::system_clock::now();
    timeSpan.stop = std::chrono::system_clock::now();

    while (true) {
        if (StartTimer()) {
            if (!TimerWasStarted) {
                TimerWasStarted = true;
                timeSpan.start = std::chrono::system_clock::now();
                std::cout << "Start point: " << timeSpan.TimePointToString(timeSpan.start) << std::endl;

                Sleep(200); // TOOD: change sleep to 5000 or secure safety of algorighm in other way
            }
        }
        if (StopTimer())
        {
            if (TimerWasStarted) {
                TimerWasStarted = false;
                timeSpan.stop = std::chrono::system_clock::now();
                std::cout << "Stop point: " << timeSpan.TimePointToString(timeSpan.stop) << std::endl;

                TextWriter writer(&configuration);
                writer.WriteToLogFile(timeSpan);

                GitController controller(&configuration);
                std::string message = timeSpan.TimePointToString(timeSpan.start) + " / " + timeSpan.TimePointToString(timeSpan.stop) + "\n";
                controller.UpdateRepository(message);

                std::cout << std::endl;
                Sleep(200);
            }
        }
        Sleep(100);
    }
    return 0;
}