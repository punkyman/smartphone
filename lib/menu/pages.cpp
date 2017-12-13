#include "pages.h"
#include "widgets.h"
#include "renderer.h"

namespace Menu
{

Page::Page(Page* parent, const char* name, uint8_t nbitems)
: Item(parent, name)
{
    content = new Item*[nbitems];
}

void Page::setitem(uint8_t index, Item* item)
{
    if (index < (sizeof(content) / sizeof(Item*)))
    {
        content[index] = item;
    }
}

void Page::update()
{
    /*for(uint8_t i = 0; i < (sizeof(content) / sizeof(Item*)); ++i)
    {
        content[i]->update();
    }*/
}

void Page::draw(Renderer* render)
{
    for(uint8_t i = 0; i < (sizeof(content) / sizeof(Item*)); ++i)
    {
        content[i]->drawInPage(render);
    }
}

void Page::drawInPage(Renderer* render)
{
    render->drawText(0, 0, name);
}

RootPage::RootPage(uint8_t nbitems)
: Page(nullptr, "main", nbitems)
{
    
}

}