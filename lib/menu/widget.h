#pragma once
#include "item.h"

namespace Menu
{
    struct Widget : Item
    {
        Widget(Page* parent, const __FlashStringHelper * name) : Item(parent, name) {}

        virtual bool ispage() const { return false; }
    };
}