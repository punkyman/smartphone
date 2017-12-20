#include "mainpage.h"

namespace Menu
{

MainPage::MainPage(uint8_t nbitems)
: Page(nullptr, F("main"), nbitems)
{
}

void MainPage::next()
{
}

void MainPage::previous()
{
}

Page* MainPage::back()
{
    return this;
}
Page* MainPage::validate()
{
    return root;
}

void MainPage::setroot(Page* page)
{
    root = page;
}

};
