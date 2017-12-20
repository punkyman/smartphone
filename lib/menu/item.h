#pragma once

#include <Arduino.h>

namespace Menu
{
    struct Rect;
    struct Page;
    struct Renderer;

    struct Item
    {
        Item(Page* parent,  const __FlashStringHelper * name); // support for F() macro

        // in-page draw
        virtual void drawInPage(Renderer* render, Rect* area) = 0;

        // in-page selection
        void focus();
        void unfocus();

        Page* getparent();

        Page* parent;
        const __FlashStringHelper* name;
        bool focused;
    };
};
