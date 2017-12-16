#include "phone_menu.h"

#include <menu.h>
#include "modules/module_display.h"
#include "globals.h"

PhoneMenu::PhoneMenu()
{
    currentPage = new Menu::RootPage(2);
    currentPage->setitem(0, new Menu::DisplayTextWidget(currentPage, "temperature", g_get_temperature));
    currentPage->setitem(1, new Menu::DisplayTextWidget(currentPage, "pressure", g_get_pressure));

    render = new Menu::Renderer(ModuleDisplay::getScreenWidth(), ModuleDisplay::getScreenHeight());
    render->getTextSize = ModuleDisplay::getTextSize;
    render->drawText = ModuleDisplay::drawText;
    render->drawLine = ModuleDisplay::drawLine;
    render->drawRect = ModuleDisplay::drawRect;
}

void PhoneMenu::update()
{
    currentPage->update();
}
    
void PhoneMenu::draw()
{
    currentPage->draw(render);
}
