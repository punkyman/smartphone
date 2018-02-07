#pragma once
#include <listener.h>

namespace Menu
{
    struct Renderer;
    struct Page;
    struct Widget;
    struct Modal;
}

struct PhoneMenu : Messaging::Listener
{
    PhoneMenu();
    void update();
    void draw();

    virtual bool listener(uint8_t msg);

    Menu::Renderer* render;
    Menu::Page* currentPage;
    Menu::Modal* modal;
};

