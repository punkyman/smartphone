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
        render->fillRect(area->x0, area->y0, textw + text_margin, texth + text_margin);
    }

    area->y0 += text_spacing;
    render->drawTextFSH(area->x0 + text_margin, area->y0, name);
    area->y0 += texth + text_spacing;
}

bool Page::canDrawInPage(const Renderer* render, Rect* area) const
{
    uint8_t textw, texth;
    render->getTextSizeFSH(name, &textw, &texth);

    area->y0 += text_spacing;
    area->y0 += texth + text_spacing;

    return area->y0 <= area->y1;    
}

}