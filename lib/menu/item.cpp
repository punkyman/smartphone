#include "item.h"

namespace Menu
{

Item::Item(Page* parent,  const char* name)
: parent(parent), name(name)
{
    
}

Item::Item(Page* parent, const __FlashStringHelper * str)
: parent(parent)
{
    name = (const char*) str; 
}

void Item::focus()
{
    focused = true;
}

void Item::unfocus()
{
    focused = false;
}

Page* Item::getparent()
{
    return parent;
}

}; // namespace Menu