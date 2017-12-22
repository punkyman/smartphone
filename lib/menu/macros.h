#pragma once

#define MENU_NEW_MAIN(page) \
    Menu::MainPage* page = new Menu::MainPage()

#define MENU_NEW_LIST(page, parent, text, nb) \
    Menu::Page* page = new Menu::VerticalListPage(parent, text, nb)

#define MENU_NEW_LIST(page, parent, text, nb) \
    Menu::Page* page = new Menu::VerticalListPage(parent, text, nb)   

#define MENU_NEW_LIST_AT(idx, parent, page, text, nb) \
    Menu::Page* page = new Menu::VerticalListPage(parent, text, nb);\
    parent->setitem(idx,page)

#define MENU_NEW_TEXT_AT(idx, page, text, getter) \
    page->setitem(idx, new Menu::DisplayTextWidget(page, text, getter))
