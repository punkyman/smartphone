#include "phone_menu.h"
#include <Arduino.h>

#include <menu.h>
#include "modules/module_display.h"
#include "modules/module_input.h"
#include "globals.h"

PhoneMenu::PhoneMenu()
{
    MENU_NEW_MAIN(main);
    MENU_NEW_LIST(menu, main, F("menu"), 5);
    MENU_NEW_LIST_AT(0, menu, trucs, F("trucs"), 0);
    MENU_NEW_LIST_AT(1, menu, machins, F("machins"), 3);
    MENU_NEW_TEXT_AT(2, menu, F("temperature"), g_get_temperature);
    MENU_NEW_LIST_AT(3, menu, blabla, F("blabla"), 0);
    MENU_NEW_TEXT_AT(4, menu, F("pressure"), g_get_pressure);

    MENU_NEW_TEXT_AT(0, machins, F("pressure"), g_get_pressure);
    MENU_NEW_LIST_AT(1, machins, toto, F("toto"), 0);
    MENU_NEW_TEXT_AT(2, machins, F("temperature"), g_get_temperature);

    main->setroot(menu);
    currentPage = menu;
    currentPage->enter();

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
    const ModuleInput::Inputs* inputs = ModuleInput::getInputs();
    Menu::Page* previousPage = currentPage;

    if(inputs->pressed_up)
    {
        currentPage->previous();
    }
    if(inputs->pressed_down)
    {
        currentPage->next();
    }
    if(inputs->pressed_validate)
    {
        currentPage = currentPage->validate();
    }
    if(inputs->pressed_left)
    {
        currentPage = currentPage->back();
    }

    if(previousPage != currentPage)
    {
        currentPage->enter();
    }
}
    
void PhoneMenu::draw()
{
    ModuleDisplay::begin();
    currentPage->draw(render);
    ModuleDisplay::end();
}
