#pragma once

#include "functor_declarations.h"
#include "item.h"

namespace Menu
{
    struct Widget : Item
    {
        Widget(Page* parent, const char* name);
    };

    struct DisplayFloatWidget : Widget
    {
        DisplayFloatWidget(Page* parent, const char* name, GETFLOAT getter);
        virtual void update();
        virtual void drawInPage(Renderer* render, Rect* area);

        GETFLOAT get;
        float value;
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

