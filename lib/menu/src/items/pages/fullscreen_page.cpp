#include "fullscreen_page.h"
#include "types.h"
#include "../widgets/widget.h"
#include "renderer.h"

namespace Menu
{

FullscreenPage::FullscreenPage(Page* parent, const __FlashStringHelper * name)
: Page(parent, name, 1)
{
}

void FullscreenPage::draw(Renderer* render)
{
    Rect area(0,0, render->screenWidth, render->screenHeight);

    content[0]->drawInPage(render, &area);
}

Page* FullscreenPage::update(const Inputs& inputs)
{
    Menu::Widget* widget = (Menu::Widget*) content[0]; // better be a widget !
    if(widget->update(inputs))
        return this;

    if(inputs.Navigation & INPUT_BACK)
    {
        return parent ? parent : this;
    }

    return this;
}

};
