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
        // returns if the widget can fit in the area, and updates the area with its size
        virtual bool canDrawInPage(const Renderer* render, Rect* area) const = 0;

        // rtti like to know if the item is of type page
        virtual bool ispage() const = 0;

        // in-page selection
        void focus();
        void unfocus();


        Page* getparent();

        Page* parent;
        const __FlashStringHelper* name;
        bool focused;
    };
};
