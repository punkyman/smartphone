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

void DisplayTextWidget::drawInPage(Renderer* render, Rect* area)
{
    uint8_t namew, nameh, textw, texth;
    render->getTextSizeFSH(name, &namew, &nameh);
    const char* str = get();
    render->getTextSizeChar(str, &textw, &texth);

    if(focused)
        render->fillRect(area->x, area->y,
        (textw > namew ? textw : namew) + 2, nameh + texth + 3);

    area->y += 1; // space
    render->drawTextFSH(area->x + 2, area->y, name);
    area->y += texth + 1; // text + space

    render->drawTextChar(area->x + 2,area->y, str);
    area->y += texth; // text
}

};
