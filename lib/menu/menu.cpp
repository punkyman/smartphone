#include "menu.h"

namespace Menu
{

MenuBrowser::MenuBrowser(Page* root)
{
    currentPage = root;
}

void MenuBrowser::update()
{
    currentPage->update();
}

void MenuBrowser::render()
{
    currentPage->draw();
}

};