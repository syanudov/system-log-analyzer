# System Log Analyzer

A small C++17 command-line application that reads a log file,
counts entries by severity level, and reports invalid lines.

Built as a learning project to practice file handling, classes,
references, const correctness, and the C++ Standard Library.

## Features

- Read a log file provided as a command-line argument.
- Parse timestamps, severity levels, and messages.
- Count successfully parsed entries.
- Count INFO, WARNING, and ERROR entries.
- Report the number of invalid lines.
- Handle missing arguments and files that cannot be opened.

## Log Format

Each line should follow this format:

```text
YYYY-MM-DD HH:MM:SS LEVEL Message
```

Example:

```text
2026-11-12 15:10:00 INFO Application started
2026-11-12 15:11:00 WARNING Low disk space
2026-11-12 15:12:00 ERROR Failed to open file
```

Messages can contain spaces.

## Project Structure

```text
.
├── README.md
├── sample.log
└── src/
    ├── LogEntry.h
    ├── LogParser.h
    ├── LogParser.cpp
    ├── LogAnalyzer.h
    ├── LogAnalyzer.cpp
    └── main.cpp
```

- `LogEntry` stores the timestamp, level, and message of one entry.
- `LogParser` converts a text line into a `LogEntry`.
- `LogAnalyzer` stores entries and counts them by level.
- `main.cpp` handles command-line arguments, file reading, and output.

## Build

Requirements: a C++ compiler with C++17 support.

From the project root, run:

```bash
g++ -std=c++17 -Wall -Wextra src/main.cpp src/LogParser.cpp src/LogAnalyzer.cpp -o log_analyzer
```

## Run

```bash
./log_analyzer sample.log
```

You can also provide a path to another log file:

```bash
./log_analyzer /path/to/server.log
```

Relative paths are resolved from the current working directory.

## Example

For this input:

```text
2026-11-12 15:10:00 INFO Application started
2026-11-12 15:11:00 WARNING Low disk space
2026-11-12 15:12:00 ERROR Failed to open file
Invalid line
2026-11-12 15:15:00 ERROR Connection failed
```

The output is:

```text
Total logs: 4
INFO: 1
WARNING: 1
ERROR: 2
Invalid lines: 1
```

`Total logs` includes only successfully parsed entries.

## Error Handling

Running without a file argument prints usage instructions:

```text
Usage: ./log_analyzer <log-file>
```

If the file cannot be opened, the program prints an error message.
Both cases return exit code `1`.

## Current Limitations

- The parser checks for three whitespace-separated fields followed
  by a non-empty message. It does not validate date or time values.
- Unknown severity levels are accepted and included in the total,
  but only INFO, WARNING, and ERROR counts are displayed.
- Severity matching is case-sensitive.
- Empty lines are counted as invalid.
- All valid entries are stored in memory.
- The application expects the format described above; it does not
  support arbitrary system log formats.

## Possible Improvements

- Validate timestamps and severity levels.
- Add automated tests.
- Filter entries by severity.