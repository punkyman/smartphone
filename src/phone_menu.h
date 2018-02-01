#pragma once

namespace Menu
{
    struct Renderer;
    struct Page;
    struct Widget;
    struct Modal;
}

struct PhoneMenu
{
    PhoneMenu();
    void update();
    void draw();

    Menu::Renderer* render;
    Menu::Page* currentPage;
    Menu::Modal* modal;
};

