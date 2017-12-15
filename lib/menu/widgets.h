#pragma once

#include "functor_declarations.h"
#include "item.h"

namespace Menu
{
    struct Widget : Item
    {
        Widget(Page* parent, const char* name);
    };

    struct DisplayTextWidget : Widget
    {
        DisplayTextWidget(Page* parent, const char* name, GETSTR getter);
        virtual void update();
        virtual void drawInPage(Renderer* render, Rect* area);

        GETSTR get;
    };

    /*struct ModifyIntWidget : Widget
    {
        ModifyIntWidget(Item* parent, const char* name, GETINT getter, SETINT setter);
        virtual void update();
        virtual void drawInPage();

        GETINT get;
        SETINT set;
        int value;
    };*/
};

