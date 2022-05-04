#ifndef LOGGER_HPP_INCLUDED
#define LOGGER_HPP_INCLUDED

#include <iostream>

enum class LogLevel { kTrace, kDebug, kInfo, kWarning, kError, kFatal };

std::ostream& logger(LogLevel level);

#endif