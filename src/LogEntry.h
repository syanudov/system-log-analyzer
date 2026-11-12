#ifndef LOG_ENTRY_H
#define LOG_ENTRY_H

#include <string>

struct LogEntry {
    std::string timestamp;
    std::string level;
    std::string message;
};

#endif
