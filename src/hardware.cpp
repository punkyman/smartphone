#include "hardware.h"
#include "hardware_config.h"

#include "i2c_communication.h"

#include "modules/module_display.h"
#include "modules/module_input.h"

#if defined(HARDWARE_ENABLE_SENSORS)
#include "modules/module_compass.h"
#include "modules/module_barometer.h"
#include "modules/module_acceleration.h"
#include "modules/module_gyroscope.h"
#endif

#if defined(HARDWARE_ENABLE_GPS)
#include "modules/module_gps.h"
#endif

#if defined(HARDWARE_ENABLE_GSM)
#include "modules/module_gsm.h"
#endif

#if defined(HARDWARE_ENABLE_BATTERY)
#include "modules/module_battery.h"
#endif

#if defined(HARDWARE_ENABLE_RTC)
#include "modules/module_rtc.h"
#endif

namespace Hardware
{
    unsigned long updateTime;

    void setup()
    {
        i2c::setup();
        ModuleDisplay::setup();
        ModuleInput::setup();

#if defined(HARDWARE_ENABLE_SENSORS)
        ModuleGyroscope::setup();
        ModuleCompass::setup();
        ModuleAcceleration::setup();
        ModuleBarometer::setup();
#endif

#if defined(HARDWARE_ENABLE_GPS)
        ModuleGps::setup();
#endif

#if defined(HARDWARE_ENABLE_GSM)
        ModuleGsm::setup();
#endif

#if defined(HARDWARE_ENABLE_BATTERY)
        ModuleBattery::setup();
#endif

#if defined(HARDWARE_ENABLE_RTC)
        ModuleRtc::setup();
#endif

        updateTime = micros();
    }

    void update()
    {
        updateTime = micros();
        // no ModuleDisplay::update, as it is handled by the menu
        ModuleInput::update();

        // sensors have their own refresh timing implementation don't put them in slow update for now
#if defined(HARDWARE_ENABLE_SENSORS)
        ModuleGyroscope::update();
        ModuleCompass::update();
        ModuleAcceleration::update();
        ModuleBarometer::update();
#endif

        // everything that does not need frame update goes there
        if(updateTime > SLOW_UPDATE)
        {
                updateTime -= SLOW_UPDATE;
#if defined(HARDWARE_ENABLE_GPS)
                ModuleGps::update();
#endif
#if defined(HARDWARE_ENABLE_GSM)
                ModuleGsm::update();
#endif
#if defined(HARDWARE_ENABLE_BATTERY)
                ModuleBattery::update();
#endif
#if defined(HARDWARE_ENABLE_RTC)
                ModuleRtc::update();
#endif
        }
    }
}
