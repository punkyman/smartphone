///////////////////////////////////////////////////////////////////////////////
// Page that draws all content fullscreen without its title
// and returns a hidden menu on interaction
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include "page.h"

namespace Menu
{
    struct MessPage : Page 
    {
        MessPage(Page* parent, const __FlashStringHelper * name, uint8_t nbitems);

        virtual void draw(Renderer* render);

        virtual Page* update(Inputs inputs);

        void setmenu(Page* page);

        Page* menu;
    };
};

