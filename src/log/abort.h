#pragma once

#include "log.h"

#include <cstdlib>

#define ABORT(fmt, ...) \
    LOG("ABORT: " fmt, ##__VA_ARGS__); \
    exit(1);
