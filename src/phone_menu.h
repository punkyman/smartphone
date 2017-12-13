#pragma once

#include <menu.h>

struct PhoneMenu
{
    PhoneMenu();
    void update();
    void render();

    Menu::Page* currentPage;
};

