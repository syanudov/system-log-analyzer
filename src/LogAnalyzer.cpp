#include "LogAnalyzer.h"

void LogAnalyzer::addEntry(const LogEntry& entry) {
    entries.push_back(entry);
}

std::size_t LogAnalyzer::getTotalCount() const {
    return entries.size();
}

std::size_t LogAnalyzer::countByLevel(const std::string& level) const {
    std::size_t count = 0;

    for (const LogEntry& entry : entries) {
        if (entry.level == level) {
            ++count;
        }
    }

    return count;
}