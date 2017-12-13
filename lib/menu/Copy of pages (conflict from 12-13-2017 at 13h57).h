#pragma once

#include "item.h"
#include <Arduino.h>

namespace Menu
{
    struct Page : Item 
    {
        Item** content;

        Page(Page* parent, const char* name, uint8_t nbitems);

        virtual void update();
        
        // draw the name of the page
        virtual void drawInPage(Renderer* render);

        // full page draw
        virtual void draw(Renderer* render);

        void setitem(uint8_t index, Item* item);
    };

    struct RootPage : Page 
    {
        RootPage(uint8_t nbitems);
    };
};
