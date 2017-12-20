#include "pages.h"
#include "widgets.h"
#include "types.h"
#include "renderer.h"

namespace Menu
{

Page::Page(Page* parent, const __FlashStringHelper * name, uint8_t nbitems)
: Item(parent, name), nb(nbitems)
{
    content = new Item*[nbitems];
}

void Page::setitem(uint8_t index, Item* item)
{
    if (index < nb)
    {
        content[index] = item;
    }
}

void Page::draw(Renderer* render)
{
    Rect area(0,0, render->screenWidth, render->screenHeight);
    uint8_t textw, texth;
    render->getTextSizeFSH(name, &textw, &texth);

    render->drawRect(area.x, area.y, area.w, area.h);
    area.x += 1; // line + space
    area.y += 1; // line + space
    area.w -= 2; // -x - line
    area.h -= 2; // -y - line
    uint8_t x = (render->screenWidth - textw) / 2, y = area.y;
    render->drawTextFSH(x, y, name);
    area.y += texth + 1; // text + space
    render->drawLine(area.x, area.y, area.w, area.y);
    area.y += 1; // line;

    for(uint8_t i = 0; i < nb; ++i)
    {
        content[i]->drawInPage(render, &area);
    }
}

void Page::drawInPage(Renderer* render, Rect* area)
{
    uint8_t textw, texth;
    render->getTextSizeFSH(name, &textw, &texth);

    if(focused)
    {
        render->fillRect(area->x, area->y, textw+2, texth+2);
    }

    area->y += 1; // space
    render->drawTextFSH(area->x + 2, area->y, name);
    area->y += texth;
}

RootPage::RootPage(uint8_t nbitems)
: Page(nullptr, F("main"), nbitems)
{

}

}