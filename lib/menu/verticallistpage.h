#pragma once

#include "page.h"

namespace Menu
{
    struct VerticalListPage : Page
    {
        VerticalListPage(Page* parent, const __FlashStringHelper * name, uint8_t nbitems);

        virtual void next();
        virtual void previous();
        virtual Page* back();
        virtual Page* validate();

        uint8_t index;
    };
};
