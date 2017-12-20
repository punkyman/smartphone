#include "verticallistpage.h"

namespace Menu
{

VerticalListPage::VerticalListPage(Page* parent, const __FlashStringHelper * name, uint8_t nbitems)
: Page(parent, name, nbitems), index(-1) 
{
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
