#pragma once
#include "item.h"
#include "inputs.h"

namespace Menu
{
    struct Widget : Item
    {
        Widget(Page* parent, const __FlashStringHelper * name) : Item(parent, name) {}

        // rtti style method to determine if it is a page
        virtual bool ispage() const { return false; }

        // returns true if the widget absorbs the inputs
        virtual bool update(Inputs inputs) = 0;
    };

    struct DisplayWidget : Widget
    {
        DisplayWidget(Page* parent, const __FlashStringHelper * name) : Widget(parent, name) {}

        virtual bool isinteractive() const { return false; }

        virtual bool update(Inputs inputs) { (void) inputs; return false; }
    };
}