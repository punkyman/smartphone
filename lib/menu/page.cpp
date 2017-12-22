#include "page.h"
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

void Page::drawInPage(Renderer* render, Rect* area)
{
    uint8_t textw, texth;
    render->getTextSizeFSH(name, &textw, &texth);

    if(focused)
    {
        render->fillRect(area->x, area->y, textw + text_margin, texth + text_margin);
    }

    area->y += text_spacing;
    render->drawTextFSH(area->x + text_margin, area->y, name);
    area->y += texth + text_spacing;
}

bool Page::canDrawInPage(const Renderer* render, Rect* area) const
{
    uint8_t textw, texth;
    render->getTextSizeFSH(name, &textw, &texth);

    area->y += text_spacing;
    area->y += texth + text_spacing;

    return area->y < render->screenHeight;    
}

}