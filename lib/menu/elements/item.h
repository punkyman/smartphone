#pragma once

namespace Menu
{
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
        virtual Item* interact() = 0;
        virtual Item* cancel() = 0;

        Item* parent;
        const char* name;
        bool focused;
    };
};
