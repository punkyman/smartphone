#pragma once
#include <Arduino.h>
#include "functors.h"
#include "widget.h"

namespace Menu
{
    struct DisplayTextWidget : Widget
    {
        DisplayTextWidget(Page* parent, const __FlashStringHelper * name, GETSTR getter);

        virtual void drawInPage(Renderer* render, Rect* area);
        virtual bool canDrawInPage(const Renderer* render, Rect* area) const;

        GETSTR get;
    };

};

