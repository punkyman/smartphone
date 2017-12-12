#include "widgets.h"

namespace Menu
{

DisplayFloatWidget::DisplayFloatWidget(Item* parent, const char* name, GETFLOAT getter)
: parent(parent), name(name), get(getter)
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
