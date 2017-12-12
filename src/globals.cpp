#include "globals.h"

namespace Globals
{
    int16_t g_temperature;

float g_get_temperature()
{
    return g_temperature / 10.0f; // according to module_barometer.cpp
}

}; // namespace Globals