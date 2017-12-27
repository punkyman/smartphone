#pragma once
#include "widget.h"
#include "functor_declarations.h"

namespace Menu
{
    struct BatteryWidget : Widget
    {
        static const uint8_t w = 16;
        static const uint8_t h = 8;

        BatteryWidget(Page* parent, GETU8 getter);

        virtual void drawInPage(Renderer* render, Rect* area);
        virtual bool canDrawInPage(const Renderer* render, Rect* area) const;

        GETU8 get;
    };
};
