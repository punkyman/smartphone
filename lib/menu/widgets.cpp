#include "widgets.h"
#include "types.h"
#include "renderer.h"

namespace Menu
{

Widget::Widget(Page* parent, const char* name)
: Item(parent, name)
{

}

DisplayFloatWidget::DisplayFloatWidget(Page* parent, const char* name, GETFLOAT getter)
: Widget(parent, name), get(getter)
{
}

void DisplayFloatWidget::update()
{
    value = get();
    Serial.print(value);
    Serial.print('\n');
}

void DisplayFloatWidget::drawInPage(Renderer* render, Rect* area)
{
    uint8_t textw, texth;
    render->getTextSize(name, &textw, &texth);

    area->y += 1; // space
    render->drawText(area->x + 2, area->y, name);
    area->y += texth + 1; // text + space

    String valuestr((value) + String(" C"));
    render->getTextSize(valuestr.c_str(), &textw, &texth);
    render->drawText(area->x + 2,area->y, valuestr.c_str());
    area->y += texth; // text
}

DisplayIntWidget::DisplayIntWidget(Page* parent, const char* name, GETINT getter)
: Widget(parent, name), get(getter)
{
}

void DisplayIntWidget::update()
{
    value = get();
}

void DisplayIntWidget::drawInPage(Renderer* render, Rect* area)
{
    uint8_t textw, texth;
    render->getTextSize(name, &textw, &texth);

    area->y += 1; // space
    render->drawText(area->x + 2, area->y, name);
    area->y += texth + 1; // text + space

    String valuestr((value) + String(" Pa"));
    render->getTextSize(valuestr.c_str(), &textw, &texth);
    render->drawText(area->x + 2,area->y, valuestr.c_str());
    area->y += texth; // text
}

};
