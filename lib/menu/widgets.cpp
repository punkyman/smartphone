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
        (textw > namew ? textw : namew) + (text_margin * 2),
        nameh + texth + 3 * text_spacing);

    area->y += text_margin;
    render->drawTextFSH(area->x + text_margin, area->y, name);
    area->y += texth + text_spacing;

    render->drawTextChar(area->x + text_margin,area->y, str);
    area->y += texth;
}

bool DisplayTextWidget::canDrawInPage(const Renderer* render, Rect* area) const
{
    uint8_t namew, nameh, textw, texth;
    render->getTextSizeFSH(name, &namew, &nameh);
    const char* str = get();
    render->getTextSizeChar(str, &textw, &texth);

    area->y += text_margin;
    area->y += texth + text_spacing;
    area->y += texth;    

    return area->y < render->screenHeight;
}





};
