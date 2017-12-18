#include "item.h"

namespace Menu
{

Item::Item(Page* parent, const __FlashStringHelper * name)
: parent(parent), name(name)
{

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