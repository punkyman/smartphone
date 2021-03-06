#include "item.h"

namespace Menu
{

Item::Item(Page* parent, const __FlashStringHelper * name)
: parent(parent), name((const char*)name), focused(false)
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

}; // namespace Menu