#include "phone_menu.h"
#include <Arduino.h>

#include <menu.h>
#include "modules/module_display.h"
#include "globals.h"

PhoneMenu::PhoneMenu()
{
    currentPage = new Menu::RootPage(3);
    currentPage->setitem(0, new Menu::Page(currentPage, F("menu"), 0));
    currentPage->setitem(1, new Menu::DisplayTextWidget(currentPage, F("temperature"), g_get_temperature));
    currentPage->setitem(2, new Menu::DisplayTextWidget(currentPage, F("pressure"), g_get_pressure));

    render = new Menu::Renderer(ModuleDisplay::getScreenWidth(), ModuleDisplay::getScreenHeight());
    render->getTextSizeChar = ModuleDisplay::getTextSizeChar;
    render->getTextSizeFSH = ModuleDisplay::getTextSizeFSH;
    render->drawTextChar = ModuleDisplay::drawTextChar;
    render->drawTextFSH = ModuleDisplay::drawTextFSH;
    render->drawLine = ModuleDisplay::drawLine;
    render->drawRect = ModuleDisplay::drawRect;
    render->fillRect = ModuleDisplay::fillRect;
}

void PhoneMenu::update()
{
    currentPage->update();
}
    
void PhoneMenu::draw()
{
    ModuleDisplay::begin();
    currentPage->draw(render);
    ModuleDisplay::end();
}
