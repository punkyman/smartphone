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
        virtual bool canDrawInPage(const Renderer* render, Rect* area) const;
        // full page draw
        virtual void draw(Renderer* render) = 0;

        virtual bool ispage() const { return true; }

        void setitem(uint8_t index, Item* item);

        // navigation methods
        virtual void next() {}
        virtual void previous() {}
        virtual Item* back() = 0;
        virtual Item* validate() = 0;

        // page initialisation
        virtual void enter() {}

        Item** content;
        uint8_t nb;
    };
};
