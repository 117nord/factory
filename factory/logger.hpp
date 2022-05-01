#include <iostream>

enum class LogLevel { kTrace, kDebug, kInfo, kWarning, kError, kFatal };

std::ostream& logger(LogLevel level);
