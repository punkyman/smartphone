#pragma once
//#include "macros.h"

#include "pages.h"

namespace Menu
{
    struct MenuBrowser
    {
        Page* currentPage;
    }

    struct Menu
    {
        MainPage root;
        MenuBrowser navigation;

        void update();
        void render();
    }
};
 