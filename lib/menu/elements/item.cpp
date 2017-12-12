#pragma once

#include "item.cpp"

namespace Menu
{

void Item::focus()
{
    focused = true;
}

void Item::unfocus()
{
    focused = false;
}

}; // namespace Menu