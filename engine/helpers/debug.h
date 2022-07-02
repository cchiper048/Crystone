#ifndef DEBUG_H
#define DEBUG_H

#define DEBUG
#ifndef DEBUG

class DebugClass {
    public:
        DebugClass() {}
        ~DebugClass() {}
        template<typename T>
        inline void Log(T message) {}
        inline void LogWarning() {}
        inline void LogError() {}
        inline void ClearDeveloperConsole() {}
};

#else

#include <iostream>
#include <chrono>
#include <ctime>
class DebugClass {
    public:
        DebugClass() {}
        ~DebugClass() {}

        template<typename T>
        inline void Log(T message) {
            const auto time = std::chrono::system_clock::now();
            const std::time_t printTime = std::chrono::system_clock::to_time_t(time);

            std::cout << "\033[94m  " << std::ctime(&printTime) <<
                         "  Debug Log: " << message << "\033[0m \n \n";
        }

        template<typename T>
        inline void LogWarning(T message) {
            const auto time = std::chrono::system_clock::now();
            const std::time_t printTime = std::chrono::system_clock::to_time_t(time);

            std::cout << "\033[93m  " << std::ctime(&printTime) <<
                         "  Debug Warn: " << message << "\033[0m \n \n";
        }

        template<typename T>
        inline void LogError(T message) {
            const auto time = std::chrono::system_clock::now();
            const std::time_t printTime = std::chrono::system_clock::to_time_t(time);

            std::cout << "\033[31m  " << std::ctime(&printTime) <<
                         "  Debug Error: " << message << "\033[0m \n \n";
        }
        
        inline void ClearDeveloperConsole() {
            std::cout << "\x1B[2J\x1B[H";
        }
};

#endif

DebugClass Debug;
#endif

