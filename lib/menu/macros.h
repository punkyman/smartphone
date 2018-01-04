#pragma once

/*******************  Pages  ***********************/

#define MENU_NEW_FULLSCREEN(page, parent, text, nb) \
    Menu::FullscreenPage* page = new Menu::FullscreenPage(parent, text, nb)

#define MENU_NEW_FULLSCREEN_AT(idx, parent, page, text, nb) \
    Menu::FullscreenPage* page = new Menu::FullscreenPage(parent, text, nb);\
    parent->setitem(idx,page)

#define MENU_NEW_LIST(page, parent, text, nb) \
    Menu::Page* page = new Menu::VerticalListPage(parent, text, nb)

#define MENU_NEW_LIST_AT(idx, parent, page, text, nb) \
    Menu::Page* page = new Menu::VerticalListPage(parent, text, nb);\
    parent->setitem(idx,page)

/*******************  Widgets  ***********************/

#define MENU_NEW_BATTERY_AT(idx, page, getter) \
    page->setitem(idx, new Menu::BatteryWidget(page, getter))

#define MENU_NEW_CLOCK_AT(idx, page, getclock, getdate) \
    page->setitem(idx, new Menu::ClockWidget(page, getclock, getdate))

#define MENU_NEW_SIGNAL_AT(idx, page, getter) \
    page->setitem(idx, new Menu::SignalWidget(page, getter))

#define MENU_NEW_TEXT_AT(idx, page, text, getter) \
    page->setitem(idx, new Menu::DisplayTextWidget(page, text, getter))

#define MENU_NEW_COMPASS_AT(idx, page, getter) \
    page->setitem(idx, new Menu::CompassWidget(page, getter))
