#include "phone_menu.h"
#include <Arduino.h>

#include <menu.h>
#include "modules/module_display.h"
#include "modules/module_input.h"
#include "globals.h"

PhoneMenu::PhoneMenu()
{
    MENU_NEW_FULLSCREEN(main, nullptr, nullptr, 3);
    MENU_NEW_BATTERY_AT(0, main, g_get_battery_level);
    MENU_NEW_CLOCK_AT(1, main, g_get_clock, g_get_date);
    MENU_NEW_SIGNAL_AT(2, main, g_get_rssi);

    MENU_NEW_LIST(menu, main, F("menu"), 3);

    MENU_NEW_LIST_AT(0, menu, climate, F("climate"), 2);
    MENU_NEW_TEXT_AT(0, climate, F("temperature"), g_get_temperature);
    MENU_NEW_TEXT_AT(1, climate, F("pressure"), g_get_pressure);

    MENU_NEW_FULLSCREEN_AT(1, menu, compass, F("compass"), 1);
    MENU_NEW_COMPASS_AT(0, compass, g_get_compass_data);

    MENU_NEW_LIST_AT(2, menu, gps, F("GPS"), 4);
    MENU_NEW_TEXT_AT(0, gps, F("location"), g_get_location);
    MENU_NEW_TEXT_AT(1, gps, F("altitude"), g_get_altitude);
    MENU_NEW_TEXT_AT(2, gps, F("speed"), g_get_speed);
    MENU_NEW_TEXT_AT(3, gps, F("satellites"), g_get_satellites);

    main->setmenu(menu);
    currentPage = main;
    currentPage->enter();

    render = new Menu::Renderer(ModuleDisplay::getScreenWidth(), ModuleDisplay::getScreenHeight());
    render->getTextSizeChar = ModuleDisplay::getTextSizeChar;
    render->getTextSizeFSH = ModuleDisplay::getTextSizeFSH;
    render->drawTextChar = ModuleDisplay::drawTextChar;
    render->drawTextFSH = ModuleDisplay::drawTextFSH;
    render->drawLine = ModuleDisplay::drawLine;
    render->drawRect = ModuleDisplay::drawRect;
    render->fillRect = ModuleDisplay::fillRect;
    render->drawCircle = ModuleDisplay::drawCircle;
    render->drawBitmap = ModuleDisplay::drawBitmap;
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
