#pragma once

#include "page.h"

namespace Menu
{
    static const int scrollbar_width = 2;
    static const int scrollbar_spacing = 1;

    struct VerticalListPage : Page
    {
        VerticalListPage(Page* parent, const __FlashStringHelper * name, uint8_t nbitems);

        virtual void draw(Renderer* render);

        virtual void next();
        virtual void previous();
        virtual Page* back();
        virtual Page* validate();

        virtual void enter();

        uint8_t index; 
        uint8_t draw_start_index;
    };
};
