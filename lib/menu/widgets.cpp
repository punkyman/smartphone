#include "widgets.h"
#include "types.h"
#include "renderer.h"

namespace Menu
{

Widget::Widget(Page* parent, const char* name)
: Item(parent, name)
{

}

DisplayTextWidget::DisplayTextWidget(Page* parent, const char* name, GETSTR getter)
: Widget(parent, name), get(getter)
{
}

void DisplayTextWidget::update()
{

}

void DisplayTextWidget::drawInPage(Renderer* render, Rect* area)
{
    const char* str = get();
    uint8_t textw, texth;
    render->getTextSize(name, &textw, &texth);

    area->y += 1; // space
    render->drawText(area->x + 2, area->y, name);
    area->y += texth + 1; // text + space

    render->getTextSize(str, &textw, &texth);
    render->drawText(area->x + 2,area->y, str);
    area->y += texth; // text
}

};
