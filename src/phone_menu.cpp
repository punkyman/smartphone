#include "phone_menu.h"
#include <Arduino.h>

#include <menu.h>
#include "modules/module_display.h"
#include "globals.h"

PhoneMenu::PhoneMenu()
{
    currentPage = new Menu::RootPage(2);
    currentPage->setitem(0, new Menu::DisplayTextWidget(currentPage, F("temperature"), g_get_temperature));
    currentPage->setitem(1, new Menu::DisplayTextWidget(currentPage, F("pressure"), g_get_pressure));

    render = new Menu::Renderer(ModuleDisplay::getScreenWidth(), ModuleDisplay::getScreenHeight());
    render->getTextSizeChar = ModuleDisplay::getTextSizeChar;
    render->getTextSizeFSH = ModuleDisplay::getTextSizeFSH;
    render->drawTextChar = ModuleDisplay::drawTextChar;
    render->drawTextFSH = ModuleDisplay::drawTextFSH;
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
