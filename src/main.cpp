#include <fstream>
#include <iostream>
#include <string>
#include "LogParser.h"
#include "LogAnalyzer.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <log-file>\n";
        return 1;
    }

    std::ifstream file(argv[1]);

    if (!file.is_open()) {
        std::cerr << "Could not open: " << argv[1] << '\n';
        return 1;
    }

    LogParser parser;
    LogAnalyzer analyzer;

    std::string line;
    std::size_t invalidLines = 0;

    while (std::getline(file, line)) {
        LogEntry entry;

        if (parser.parseLine(line, entry)) {
            analyzer.addEntry(entry);
        } else {
            ++invalidLines;
        }
    }

    std::cout << "Total logs: " << analyzer.getTotalCount() << '\n';
    std::cout << "INFO: " << analyzer.countByLevel("INFO") << '\n';
    std::cout << "WARNING: " << analyzer.countByLevel("WARNING") << '\n';
    std::cout << "ERROR: " << analyzer.countByLevel("ERROR") << '\n';
    std::cout << "Invalid lines: " << invalidLines << '\n';

    return 0;
}