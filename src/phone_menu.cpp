#include "phone_menu.h"
#include "globals.h"

PhoneMenu::PhoneMenu()
{
    currentPage = new Menu::RootPage(1);
    currentPage->setitem(0, new Menu::DisplayFloatWidget(currentPage, "temperature", &Globals::g_get_temperature));
}

void PhoneMenu::update()
{
    currentPage->update();
}
    
void PhoneMenu::render()
{
    currentPage->draw();
}
