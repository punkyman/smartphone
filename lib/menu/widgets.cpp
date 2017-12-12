#include "widgets.h"

namespace Menu
{

Widget::Widget(Page* parent, const char* name)
: Item(parent, name)
{

}

DisplayFloatWidget::DisplayFloatWidget(Page* parent, const char* nam, GETFLOAT getter)
: Widget(parent, name), get(getter)
{
}
void DisplayFloatWidget::update()
{
    value = get();
}

void DisplayFloatWidget::drawInPage()
{

}

};
