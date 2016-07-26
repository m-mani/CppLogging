/*!
    \file error_appender.cpp
    \brief Logging error appender implementation
    \author Ivan Shynkarenka
    \date 26.07.2016
    \copyright MIT License
*/

#include "logging/appenders/error_appender.h"

#include "errors/exceptions.h"

#include <cstdio>

namespace CppLogging {

void ErrorAppender::AppendRecord(Record& record)
{
    // Skip logging records without layout
    if (record.raw.first == nullptr)
        return;

    std::fwrite(record.raw.first, 1, record.raw.second, stderr);
}

void ErrorAppender::Flush()
{
    std::fflush(stderr);
}

} // namespace CppLogging
