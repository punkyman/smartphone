#include "mess_page.h"
#include "types.h"
#include "renderer.h"

namespace Menu
{

MessPage::MessPage(Page* parent, const __FlashStringHelper * name, uint8_t nbitems)
: Page(parent, name, nbitems), menu(nullptr)
{
}

void MessPage::draw(Renderer* render)
{
    Rect area(0,0, render->screenWidth, render->screenHeight);

    for(uint8_t i = 0; i < nb; ++i)
    {
        content[i]->drawInPage(render, &area);
    }
}

Page* MessPage::update(Inputs inputs)
{
    // No inputs passed to the widgets here
    if(inputs & INPUT_BACK)
    {
        return parent ? parent : this;
    }
    if(inputs & INPUT_VALIDATE)
    {
        return menu;
    }

    return this;
}

void MessPage::setmenu(Page* page)
{
    menu = page;
}

};
