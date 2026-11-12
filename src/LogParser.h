#ifndef LOG_PARSER_H
#define LOG_PARSER_H

#include <string>
#include "LogEntry.h"

class LogParser {
public:
    bool parseLine(const std::string& line, LogEntry& entry);
};

#endif