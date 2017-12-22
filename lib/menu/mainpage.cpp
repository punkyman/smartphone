#include "mainpage.h"
#include "types.h"
#include "renderer.h"

namespace Menu
{

MainPage::MainPage()
: Page(nullptr, F("main"), 0)
{
}

void MainPage::draw(Renderer* render)
{
    Rect area(0,0, render->screenWidth, render->screenHeight);

    for(uint8_t i = 0; i < nb; ++i)
    {
        content[i]->drawInPage(render, &area);
    }
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
