#pragma once
#include <Logger.hpp>

#define LOGGER common::Logger::getInstance()

// logs directly; doesn't add any prefix or postfix (such as timestamp, end of the line or any separator)
#define LOGPART LOGGER

// may add prefix and/or postfix
#define LOG common::Logger::Appender(LOGGER)
