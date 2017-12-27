#pragma once
#include "widget.h"
#include "functor_declarations.h"

#define BATTERY_BAR1 10
#define BATTERY_BAR2 25
#define BATTERY_BAR3 50
#define BATTERY_BAR4 75

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

    struct ClockWidget : Widget
    {
        ClockWidget(Page* parent, GETSTR getter);

        virtual void drawInPage(Renderer* render, Rect* area);
        virtual bool canDrawInPage(const Renderer* render, Rect* area) const;

        GETSTR get;
    };
};
