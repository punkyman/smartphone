#pragma once

namespace Menu
{
    struct Page;
}

struct PhoneMenu
{
    PhoneMenu();
    void update();
    void render();

    Menu::Page* currentPage;
};

