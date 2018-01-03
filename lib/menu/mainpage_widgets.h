#pragma once
#include "widget.h"
#include "functor_declarations.h"

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
    struct BatteryWidget : Widget
    {
        static const uint8_t w = 16;
        static const uint8_t h = 8;

        static const uint8_t bar_w = 2;
        static const uint8_t bar_h = 4;
        static const uint8_t bar_s = 1;

        BatteryWidget(Page* parent, GETU8 getter);

        virtual void drawInPage(Renderer* render, Rect* area);
        virtual bool canDrawInPage(const Renderer* render, Rect* area) const;

        GETU8 get;
    };

    struct SignalWidget : Widget
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
        virtual bool canDrawInPage(const Renderer* render, Rect* area) const;

        GETU8 get;
    };

    struct ClockWidget : Widget
    {
        static const uint8_t space = 2;
        ClockWidget(Page* parent, GETSTR getclock, GETSTR getdate);

        virtual void drawInPage(Renderer* render, Rect* area);
        virtual bool canDrawInPage(const Renderer* render, Rect* area) const;

        GETSTR getclock;
        GETSTR getdate;
    };
};
