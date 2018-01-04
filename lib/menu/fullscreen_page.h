///////////////////////////////////////////////////////////////////////////////
// Page that draws all content fullscreen without its title
// and returns a hidden menu on interaction
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include "page.h"

namespace Menu
{
    struct FullscreenPage : Page 
    {
        FullscreenPage(Page* parent, const __FlashStringHelper * name, uint8_t nbitems);

        virtual void draw(Renderer* render);

        virtual Item* back();
        virtual Item* validate();

        void setmenu(Page* page);

        Page* menu;
    };
};

