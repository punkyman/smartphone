#pragma once
#include <Arduino.h>

#include "item.h"

namespace Menu
{   
    struct Rect;

    static const uint8_t widget_spacing = 1;

    struct Page : Item 
    {
        Page(Page* parent, const __FlashStringHelper * name, uint8_t nbitems);
        
        // draw the name of the page
        virtual void drawInPage(Renderer* render, Rect* area);
        // full page draw
        virtual void draw(Renderer* render);

        void setitem(uint8_t index, Item* item);

        // navigation methods
        virtual void next() = 0;
        virtual void previous() = 0;
        virtual Page* back() = 0;
        virtual Page* validate() = 0;

        Item** content;
        uint8_t nb;
    };
};
