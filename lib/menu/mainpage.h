#pragma once

#include "page.h"

namespace Menu
{
    struct MainPage : Page 
    {
        MainPage();

        virtual void draw(Renderer* render);

        virtual Page* back();
        virtual Page* validate();

        void setroot(Page* page);

        Page* root;
    };
};

