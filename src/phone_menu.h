#pragma once

namespace Menu
{
    struct Page;
    struct Renderer;
}
#include <renderer.h>

struct PhoneMenu
{
    PhoneMenu();
    void update();
    void draw();

    Menu::Renderer* render;
    Menu::Page* currentPage;
};

