#include "phone_menu.h"
#include <Arduino.h>
#include "assert.h"

#include <menu.h>
#include "modules/module_display.h"
#include "modules/module_input.h"
#include "globals/text.h"
#include "globals/accessors.h"


PhoneMenu::PhoneMenu()
{
    modal = new Menu::Modal();

    MENU_NEW_MESS(main, nullptr, nullptr, 3);
    MENU_NEW_BATTERY_AT(0, main, g_get_battery_level);
    MENU_NEW_CLOCK_AT(1, main, g_get_clock, g_get_date);
    MENU_NEW_SIGNAL_AT(2, main, g_get_signal_level);

    MENU_NEW_LIST(menu, main, F("menu"), 4);

    MENU_NEW_LIST_AT(0, menu, climate, F("climate"), 2);
    MENU_NEW_TEXT_AT(0, climate, F("temperature"), g_get_temperature);
    MENU_NEW_TEXT_AT(1, climate, F("pressure"), g_get_pressure);

    MENU_NEW_FULLSCREEN_AT(1, menu, compass, F("compass"));
    MENU_NEW_COMPASS_AT(0, compass, g_get_compass_data);

    MENU_NEW_LIST_AT(2, menu, gps, F("GPS"), 4);
    MENU_NEW_TEXT_AT(0, gps, F("location"), g_get_location);
    MENU_NEW_TEXT_AT(1, gps, F("altitude"), g_get_altitude);
    MENU_NEW_TEXT_AT(2, gps, F("speed"), g_get_speed);
    MENU_NEW_TEXT_AT(3, gps, F("satellites"), g_get_satellites);

    MENU_NEW_LIST_AT(3, menu, setup, F("setup"), 5);
    MENU_NEW_MODIFYINT_AT(0, setup, F("hour"), g_get_hour, g_set_hour, 0, 24);    
    MENU_NEW_MODIFYINT_AT(1, setup, F("minutes"), g_get_minutes, g_set_minutes, 0, 59);
    MENU_NEW_MODIFYINT_AT(2, setup, F("day"), g_get_day, g_set_day, 1, 31);
    MENU_NEW_MODIFYINT_AT(3, setup, F("month"), g_get_month, g_set_month, 1, 12);
    MENU_NEW_MODIFYINT_AT(4, setup, F("year"), g_get_year, g_set_year, 1910, 2110);

    main->setmenu(menu);
    currentPage = main;
    currentPage->enter();

    render = new Menu::Renderer(ModuleDisplay::getScreenWidth(), ModuleDisplay::getScreenHeight());
    render->getTextSize = ModuleDisplay::getTextSize;
    render->drawText = ModuleDisplay::drawText;
    render->drawLine = ModuleDisplay::drawLine;
    render->drawRect = ModuleDisplay::drawRect;
    render->fillRect = ModuleDisplay::fillRect;
    render->eraseRect = ModuleDisplay::eraseRect;
    render->drawCircle = ModuleDisplay::drawCircle;
    render->drawBitmap = ModuleDisplay::drawBitmap;
}

void PhoneMenu::update()
{
    const ModuleInput::Inputs* inputs = ModuleInput::getInputs();
    Menu::Inputs input_values = 0;

    if(inputs->pressed_up)
    {
        input_values |= Menu::INPUT_PREVIOUS;
    }
    if(inputs->pressed_down)
    {
        input_values |= Menu::INPUT_NEXT;
    }
    if(inputs->pressed_left)
    {
        input_values |= Menu::INPUT_BACK;
    }
    if(inputs->pressed_right)
    {
        input_values |= Menu::INPUT_FORWARD;
    }
    if(inputs->pressed_validate)
    {
        input_values |= Menu::INPUT_VALIDATE;
    }

    if(modal->update(input_values))
    {
        return; // modal intercepts all inputs
    }

    Menu::Page* previousPage = currentPage;
    currentPage = currentPage->update(input_values);

    if(previousPage != currentPage)
    {
        currentPage->enter();
    }
}
    
void PhoneMenu::draw()
{
    ModuleDisplay::begin();
    currentPage->draw(render);
    modal->draw(render);
    ModuleDisplay::end();
}
