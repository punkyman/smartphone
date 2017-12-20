#include "verticallistpage.h"
#include "types.h"
#include "renderer.h"

namespace Menu
{

VerticalListPage::VerticalListPage(Page* parent, const __FlashStringHelper * name, uint8_t nbitems)
: Page(parent, name, nbitems), index(-1) 
{
}

void VerticalListPage::draw(Renderer* render)
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


void VerticalListPage::next()
{
    if(index < nb - 1)
    {
        // special case as the page starts up with no item focused
        if(index != -1)
            content[index]->unfocus();
        
        content[++index]->focus();
    }
}
void VerticalListPage::previous()
{
    if(index > 0)
    {
        content[index]->unfocus();
        content[--index]->focus();
    }
}

Page* VerticalListPage::back()
{
    return parent;
}

Page* VerticalListPage::validate()
{
    // may require RTTI mechanism to return only pages
}

};
