#include "widgets.h"
#include "types.h"
#include "renderer.h"

namespace Menu
{

Widget::Widget(Page* parent, const __FlashStringHelper* name)
: Item(parent, name)
{

}

DisplayTextWidget::DisplayTextWidget(Page* parent, const __FlashStringHelper* name, GETSTR getter)
: Widget(parent, name), get(getter)
{
}

void DisplayTextWidget::update()
{

}

void DisplayTextWidget::drawInPage(Renderer* render, Rect* area)
{
    uint8_t textw, texth;
    render->getTextSizeFSH(name, &textw, &texth);

    area->y += 1; // space
    render->drawTextFSH(area->x + 2, area->y, name);
    area->y += texth + 1; // text + space

    const char* str = get();
    render->getTextSizeChar(str, &textw, &texth);
    render->drawTextChar(area->x + 2,area->y, str);
    area->y += texth; // text
}

};
