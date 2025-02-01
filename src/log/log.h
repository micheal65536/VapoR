#pragma once

//#define LOG_TRACE
//#define LOG_SILENT

#include <cstdio>

#ifndef LOG_SILENT
    #define LOG(fmt, ...) \
        std::fprintf(stderr, "[VapoR] (%s %s:%d) " fmt "\n", __func__, __FILE__, __LINE__, ##__VA_ARGS__);
#else
    #define LOG(fmt, ...)
#endif

#ifdef LOG_TRACE
    #define TRACE() \
        LOG("TRACE");
#else
    #define TRACE()
#endif

#ifdef LOG_TRACE
    #define TRACE_F(fmt, ...) \
        LOG("TRACE: " fmt, ##__VA_ARGS__);
#else
    #define TRACE_F(fmt, ...)
#endif
