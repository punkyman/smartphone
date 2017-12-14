#include "widgets.h"
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

void DisplayFloatWidget::drawInPage(Renderer* render)
{
    render->drawText(0,0, name);
    render->drawText(0,10, String(String(value) + String(" °C")).c_str());
}

};
