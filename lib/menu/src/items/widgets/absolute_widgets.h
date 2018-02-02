#pragma once
#include "widget.h"
#include "functors.h"

#define BATTERY_BAR1 10
#define BATTERY_BAR2 25
#define BATTERY_BAR3 50
#define BATTERY_BAR4 75

// < -110dBm : No signal
// < -100dBm : Poor
#define SIGNAL_BAR1 2
// < -85dBm : Fair
#define SIGNAL_BAR2 14
// < -70 dBm : Good
#define SIGNAL_BAR3 22
// < -54 dBm or greater
#define SIGNAL_BAR4 30

namespace Menu
{
    struct AbsoluteWidget : DisplayWidget
    {
        // no name for these widgets 
        AbsoluteWidget(Page* parent) : DisplayWidget(parent, nullptr) {} 
        // no space computation
        bool canDrawInPage(const Renderer* render, Rect* area) const { return true; }
    };

    struct BatteryWidget : AbsoluteWidget
    {
        static const uint8_t w = 16;
        static const uint8_t h = 8;

        static const uint8_t bar_w = 2;
        static const uint8_t bar_h = 4;
        static const uint8_t bar_s = 1;

        BatteryWidget(Page* parent, GETU8 getter);

        virtual void drawInPage(Renderer* render, Rect* area);

        GETU8 get;
    };

    struct SignalWidget : AbsoluteWidget
    {
        static const uint8_t w = 16;
        static const uint8_t h = 8;
        static const uint8_t bw = 8;
        static const uint8_t bh = 8;

        static const uint8_t bar_w = 2;
        static const uint8_t bar_h = 2;
        static const uint8_t bar_s = 1;

        SignalWidget(Page* parent, GETU8 getter);

        virtual void drawInPage(Renderer* render, Rect* area);

        GETU8 get;
    };

    struct ClockWidget : AbsoluteWidget
    {
        static const uint8_t space = 2;
        ClockWidget(Page* parent, GETSTR getclock, GETSTR getdate);

        virtual void drawInPage(Renderer* render, Rect* area);

        GETSTR getclock;
        GETSTR getdate;
    };

    struct CompassWidget : AbsoluteWidget
    {
        CompassWidget(Page* parent, GETCOMPASSDATA getter);

        virtual void drawInPage(Renderer* render, Rect* area);

        GETCOMPASSDATA get;
    };

    struct CallWidget : AbsoluteWidget
    {
        CallWidget(Page* parent, CALLNUMBER set);

        virtual bool update(Inputs inputs);

        virtual void drawInPage(Renderer* render, Rect* area);

        CALLNUMBER set;

        String number;
        char num;
    };
};
