#include "phone_menu.h"
#include <Arduino.h>

#include <menu.h>
#include "modules/module_display.h"
#include "modules/module_input.h"
#include "globals.h"

PhoneMenu::PhoneMenu()
{
    Menu::MainPage* main  = new Menu::MainPage(0);
    currentPage = new Menu::VerticalListPage(currentPage, F("menu"), 4);
    currentPage->setitem(0, new Menu::VerticalListPage(currentPage, F("trucs"), 0));
    currentPage->setitem(1, new Menu::VerticalListPage(currentPage, F("machins"), 0));
    currentPage->setitem(2, new Menu::DisplayTextWidget(currentPage, F("temperature"), g_get_temperature));
    currentPage->setitem(3, new Menu::DisplayTextWidget(currentPage, F("pressure"), g_get_pressure));

    main->setroot(currentPage);

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
