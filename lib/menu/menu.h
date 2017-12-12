#pragma once
//#include "macros.h"

#include "pages.h"
#include "widgets.h"

namespace Menu
{

struct MenuBrowser
{
    MenuBrowser(Page* root);
    void update();
    void render();

    Page* currentPage;
};

};
 