#include "phone_menu.h"

#include <menu.h>
#include "module_display.h"
#include "globals.h"

PhoneMenu::PhoneMenu()
{
    currentPage = new Menu::RootPage(1);
    currentPage->setitem(0, new Menu::DisplayFloatWidget(currentPage, "temperature", &g_get_temperature));

    render = new Menu::Renderer;
    render->drawText = ModuleDisplay::drawText;
}

void PhoneMenu::update()
{
    currentPage->update();
}
    
void PhoneMenu::draw()
{
    currentPage->draw(render);
}
