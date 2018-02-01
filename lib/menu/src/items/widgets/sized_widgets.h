#pragma once
#include <Arduino.h>
#include "functors.h"
#include "widget.h"

namespace Menu
{
    struct DisplayTextWidget : DisplayWidget
    {
        DisplayTextWidget(Page* parent, const __FlashStringHelper * name, GETSTR getter);

        virtual void drawInPage(Renderer* render, Rect* area);
        virtual bool canDrawInPage(const Renderer* render, Rect* area) const;

        GETSTR get;
    };

    struct ModifyIntWidget : Widget
    {
        ModifyIntWidget(Page* parent, const __FlashStringHelper * name, GETINT get, SETINT set, int32_t minimum, int32_t maximum);

        virtual bool update(Inputs inputs);

        virtual void drawInPage(Renderer* render, Rect* area);
        virtual bool canDrawInPage(const Renderer* render, Rect* area) const;

        GETINT get;
        SETINT set;
        int32_t value;
        int32_t minimum;
        int32_t maximum;
        bool interacting;
    };
};

