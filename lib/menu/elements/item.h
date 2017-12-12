#pragma once

namespace Menu
{
    struct Page;

    struct Item
    {
        virtual void update() = 0;        
        // fullscreen draw
        virtual void draw() = 0;
        // in-page draw
        virtual void drawInPage() = 0;

        // in-page selection
        void focus();
        void unfocus();

        // returns the address of a page for navigation, null otherwise
        virtual Page* interact() = 0;
        virtual Page* cancel() = 0;

        Page* parent;
        const char* name;
        bool focused;
    };
};
