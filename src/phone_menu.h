#pragma once

namespace Menu
{
    struct Page;
    struct Renderer;
}

struct PhoneMenu
{
    PhoneMenu();
    void update();
    void draw();

    Menu::Renderer* render;
    Menu::Page* currentPage;
};

