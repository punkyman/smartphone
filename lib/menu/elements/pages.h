#pragma once

#include "item.h"

namespace Menu
{
    struct Page : Item 
    {
        Item* content;

        Page(const char* name);

        virtual void update();

        virtual void draw();
        // draw the name of the page
        virtual void drawInPage();

        void insert(Item* item);
    };

    struct MainPage : Page 
    {
        MainPage();

        virtual void draw();
        // draw the name of the page
        virtual void drawInPage();

        virtual Item* interact();        
    };
};
