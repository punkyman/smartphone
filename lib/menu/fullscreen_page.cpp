#include "fullscreen_page.h"
#include "types.h"
#include "renderer.h"

namespace Menu
{

FullscreenPage::FullscreenPage(Page* parent, const __FlashStringHelper * name, uint8_t nbitems)
: Page(parent, name, nbitems), menu(nullptr)
{
}

void FullscreenPage::draw(Renderer* render)
{
    Rect area(0,0, render->screenWidth, render->screenHeight);

    for(uint8_t i = 0; i < nb; ++i)
    {
        content[i]->drawInPage(render, &area);
    }
}

Item* FullscreenPage::back()
{
    return parent ? parent : this;
}
Item* FullscreenPage::validate()
{
    return menu;
}

void FullscreenPage::setmenu(Page* page)
{
    menu = page;
}

};
