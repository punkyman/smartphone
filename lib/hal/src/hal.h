#pragma once
#include "assert.h"
#include <Arduino.h> // make sure the macros we are based on are declared

#if defined(PLATFORM_ststm32)
// some compatibility things do exist from atmel to stm32 int the file pgmspace.h
// adding here what is missing, so that it does not get lost after a platform re-install
#define snprintf_P(s, l, f, ...) snprintf((s), (l), (f), __VA_ARGS__)

#elif defined(PLATFORM_atmelavr)

#else
STATIC_ASSERT(false);
#endif


