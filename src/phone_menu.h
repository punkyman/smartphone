#pragma once

namespace Menu
{
    struct Renderer;
    struct Page;
    struct Widget;
}

struct PhoneMenu
{
    PhoneMenu();
    void update();
    void draw();

    Menu::Renderer* render;
    Menu::Page* currentPage;
};

