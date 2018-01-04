#pragma once
#include "item.h"

namespace Menu
{
    struct Widget : Item
    {
        Widget(Page* parent, const __FlashStringHelper * name) : Item(parent, name) {}

        // rtti style method to determine if it is a page
        virtual bool ispage() const { return false; }

        // rtti to know if the widget is a DisplayWidget or an interactive widget
        virtual bool isinteractive() const = 0;
    };

    struct DisplayWidget : Widget
    {
        DisplayWidget(Page* parent, const __FlashStringHelper * name) : Widget(parent, name) {}

        virtual bool isinteractive() const { return false; }

        virtual void next() {}
        virtual void previous() {}
        virtual Item* back() { return nullptr; }
        virtual Item* validate() {return nullptr; }
    };
}