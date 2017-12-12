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

        virtual void draw();
        // draw the name of the page
        virtual void drawInPage();

        void setitem(uint8_t index, Item* item);

        virtual Page* interact() {}
        virtual Page* cancel() {}

    };

    struct MainPage : Page 
    {
        MainPage(Page* root, uint8_t nbitems);

        virtual Page* interact();        

        Page* root;
    };
};
