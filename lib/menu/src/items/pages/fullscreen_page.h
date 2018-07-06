///////////////////////////////////////////////////////////////////////////////
// Page made to handle one widget fullscreen
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include "page.h"

namespace Menu
{
    struct FullscreenPage : Page 
    {
        FullscreenPage(Page* parent, const __FlashStringHelper * name);

        virtual void draw(Renderer* render);

        virtual Page* update(const Inputs& inputs);
    };
};

