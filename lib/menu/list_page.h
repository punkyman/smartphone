#pragma once

#include "page.h"

namespace Menu
{
    static const int scrollbar_width = 2;
    static const int scrollbar_spacing = 1;

    struct ListPage : Page
    {
        ListPage(Page* parent, const __FlashStringHelper * name, uint8_t nbitems);

        virtual void draw(Renderer* render);

        virtual void next();
        virtual void previous();
        virtual Item* back();
        virtual Item* validate();

        virtual void enter();

        uint8_t index; 
        uint8_t draw_start_index;
    };
};
