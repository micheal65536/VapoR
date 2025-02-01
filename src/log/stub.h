#pragma once

#include "log.h"

#define STUB() \
    LOG("STUB");

#define STUB_F(fmt, ...) \
    LOG("STUB: " fmt, ##__VA_ARGS__);
