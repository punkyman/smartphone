#include "list_page.h"
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

void drawScrollBar(Renderer* render, uint8_t start_index, uint8_t end_index, uint8_t nb, Rect* area)
{
    uint8_t size = (area->y1 - area->y0 - (2 * scrollbar_spacing))/ nb;

    uint8_t begin_x = area->x1 - (3 * scrollbar_spacing) - scrollbar_width; 
    render->drawLine(begin_x, area->y0,
        begin_x, area->y1);

    begin_x += scrollbar_spacing * 2;
    render->fillRect(begin_x, area->y0 + (start_index*size) + scrollbar_spacing,
        scrollbar_width, ((end_index - start_index) * size) - 2 * scrollbar_spacing);

    area->x1 -= (2 * scrollbar_spacing) - scrollbar_width;
}

ListPage::ListPage(Page* parent, const __FlashStringHelper * name, uint8_t nbitems)
: Page(parent, name, nbitems), index(0), draw_start_index(0)
{
}

void ListPage::enter()
{
    // for now, avoid implementation of leave() by unfocusing previous item here
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

void ListPage::draw(Renderer* render)
{
    Rect area(0,0, render->screenWidth, render->screenHeight);
    uint8_t textw, texth;
    render->getTextSizeFSH(name, &textw, &texth, NORMAL);

    render->drawRect(area.x0, area.y0, area.x1 - area.x0, area.y1 - area.y0);
    area.x0 += 1;
    area.y0 += 1;
    area.x1 -= 1;
    area.y1 -= 1;

    uint8_t x = (render->screenWidth - textw) / 2;
    render->drawTextFSH(x, area.y0, name, NORMAL);
    area.y0 += texth + text_spacing;
    render->drawLine(area.x0, area.y0, area.x1, area.y0);
    area.y0 += 1; // line;

    if(nb)
    {
        uint8_t draw_end_index = nb;

        computeWindow(render, &area, (const Menu::Item**) content, index, &draw_start_index, &draw_end_index);

        if( (draw_end_index - draw_start_index) != nb )
        {
            drawScrollBar(render, draw_start_index, draw_end_index, nb, &area);
        }

        for(uint8_t i = draw_start_index; i < draw_end_index; ++i)
        {
            content[i]->drawInPage(render, &area);
        }
    }
}

Page* ListPage::update(Inputs inputs)
{
    if(inputs & INPUT_PREVIOUS)
    {
        if(index > 0)
        {
            content[index]->unfocus();
            content[--index]->focus();
        }

        return this;
    }

    if(inputs & INPUT_NEXT)
    {
        if(index < nb - 1)
        {
            content[index]->unfocus();
            content[++index]->focus();
        }

        return this;
    }

    if(inputs & INPUT_BACK)
    {
        return parent;
    }

    if(inputs & INPUT_VALIDATE)
    {
        if(content[index]->ispage())
            return (Page*) content[index];
        else
            return this;
    }

    return this;
}

};
