#pragma once

#include "page.h"

namespace Menu
{
    struct MainPage : Page 
    {
        MainPage(uint8_t nbitems);

        virtual void next();
        virtual void previous();
        virtual Page* back();
        virtual Page* validate();

        void setroot(Page* page);

        Page* root;
    };
};

