#pragma once

#include "functor_declarations.h"
#include "item.h"

namespace Menu
{
    struct Widget : Item
    {
        // a widget does not display in fullscreen
        virtual void draw() {}
    };

    struct DisplayFloatWidget : Widget
    {
        DisplayFloatWidget(Item* parent, const char* name, GETFLOAT getter);
        virtual void update();
        virtual void drawInPage();

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

