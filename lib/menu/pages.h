#pragma once
#include <Arduino.h>

#include "item.h"

namespace Menu
{   
    struct Rect;

    struct Page : Item 
    {
        Page(Page* parent, const __FlashStringHelper * name, uint8_t nbitems);

        virtual void update();
        
        // draw the name of the page
        virtual void drawInPage(Renderer* render, Rect* area);

        // full page draw
        virtual void draw(Renderer* render);

        void setitem(uint8_t index, Item* item);

        Item** content;
        uint8_t nb;
    };

    struct RootPage : Page 
    {
        RootPage(uint8_t nbitems);
    };
};
