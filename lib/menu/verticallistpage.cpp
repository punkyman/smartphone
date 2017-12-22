#include "verticallistpage.h"
#include "types.h"
#include "renderer.h"

namespace Menu
{

// establish the beginning and the end of what has to be drawn on-screen, so that the selected index is drawn on-screen and nothing goes out of the area
// expects start to be at currently drawn value, and end to be at the number of items
void computeWindow(const Renderer* render, const Rect* area, const Item** content, uint8_t index, uint8_t* start, uint8_t* end)
{
    if(index < *start)
    {
        *start = index;
    }
    
    uint8_t nb = *end;
    do
    {
        Rect space = *area;
        *end = nb;

        for(uint8_t i = *start; i < nb; ++i)
        {
            if(!content[i]->canDrawInPage(render, &space))
            {
                *end = i;
                break;
            }
        }

        if(index >= *end)
        {
            ++(*start);
        }
        else
        {
            break;
        }
    } while (1);
}

VerticalListPage::VerticalListPage(Page* parent, const __FlashStringHelper * name, uint8_t nbitems)
: Page(parent, name, nbitems), index(0), draw_start_index(0)
{
}

void VerticalListPage::enter()
{
    if(nb)
    {
        content[index]->unfocus();
    }
    
    index = 0;
    draw_start_index = 0;

    if(nb)
    {
        content[index]->focus();
    }
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

    uint8_t draw_end_index = nb;

    computeWindow(render, &area, (const Menu::Item**) content, index, &draw_start_index, &draw_end_index);

    for(uint8_t i = draw_start_index; i < draw_end_index; ++i)
    {
        content[i]->drawInPage(render, &area);
    }
}

void VerticalListPage::next()
{
    if(index < nb - 1)
    {
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
    return this;
    // may require RTTI mechanism to return only pages
}

};
