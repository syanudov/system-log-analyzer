#ifndef LOG_ANALYZER_H
#define LOG_ANALYZER_H

#include <cstddef>
#include <string>
#include <vector>
#include "LogEntry.h"

class LogAnalyzer {
public:
    void addEntry(const LogEntry& entry);
    std::size_t getTotalCount() const;
    std::size_t countByLevel(const std::string& level) const;

private:
    std::vector<LogEntry> entries;
};

#endif