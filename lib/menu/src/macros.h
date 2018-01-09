#pragma once

/*******************  Pages  ***********************/

#define MENU_NEW_MESS(page, parent, text, nb) \
    Menu::MessPage* page = new Menu::MessPage(parent, text, nb)

#define MENU_NEW_FULLSCREEN_AT(idx, parent, page, text) \
    Menu::FullscreenPage* page = new Menu::FullscreenPage(parent, text);\
    parent->setitem(idx,page)

#define MENU_NEW_LIST(page, parent, text, nb) \
    STATIC_ASSERT_MESSAGE(nb > 0, need_at_least_one_item_in_the_list); \
    Menu::Page* page = new Menu::ListPage(parent, text, nb)

#define MENU_NEW_LIST_AT(idx, parent, page, text, nb) \
    STATIC_ASSERT_MESSAGE(nb > 0, need_at_least_one_item_in_the_list); \
    Menu::Page* page = new Menu::ListPage(parent, text, nb);\
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

#define MENU_NEW_MODIFYINT_AT(idx, page, text, getter, setter, minimum, maximum) \
    page->setitem(idx, new Menu::ModifyIntWidget(page, text, getter, setter, minimum, maximum))
