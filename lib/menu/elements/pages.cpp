#include "pages.h"
#include "widgets.h"

namespace Menu
{
Page::Page(const char* name, uint8_t nbitems)
: name(name)
{
    content = (Item**) malloc(sizeof(Item*) * nbitems);
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
    for(uint8_t i = 0; i < (sizeof(content) / sizeof(Item*)); ++i)
    {
        content[i]->update();
    }
}

void Page::draw()
{
    for(uint8_t i = 0; i < (sizeof(content) / sizeof(Item*)); ++i)
    {
        content[i]->drawInPage();
    }
}

void Page::drawInPage()
{

}

MainPage::MainPage(Page* root, uint8_t nbitems)
: Page(nullptr, "main", nbitems), root(root)
{
    
}

Page* MainPage::interact()
{
    return root;
}        

}