#pragma once

namespace Menu
{
    struct Page;

    struct Item
    {
        Item(Page* parent, const char* name);

        virtual void update() = 0;        

        // in-page draw
        virtual void drawInPage() = 0;

        // in-page selection
        void focus();
        void unfocus();

        Page* getparent();

        Page* parent;
        const char* name;
        bool focused;
    };
};
