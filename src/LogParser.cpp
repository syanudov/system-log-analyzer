#include "LogParser.h"
#include <sstream>

bool LogParser::parseLine(const std::string& line, LogEntry& entry) {
    std::istringstream stream(line);

    std::string date;
    std::string time;
    std::string level;
    std::string message;

    if (!(stream >> date >> time >> level)) {
        return false;
    }

    std::getline(stream >> std::ws, message);

    if (message.empty()) {
        return false;
    }

    entry.timestamp = date + " " + time;
    entry.level = level;
    entry.message = message;

    return true;
}