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


CompassWidget::CompassWidget(Page* parent, GETCOMPASSDATA getter)
: Widget(parent, F("compass")), get(getter)
{

}

void CompassWidget::drawInPage(Renderer* render, Rect* area)
{
    uint8_t cx = area->x + ((area->w - area->x) / 2);
    uint8_t cy = area->y + ((area->h - area->y) / 2);
    uint8_t r = ((area->h -area->y) / 2) - circle_margin;
    render->drawCircle(cx, cy, r);

    float x, y;
    get(&x, &y);
    int16_t sx = (float)x * (float)r;
    int16_t sy = (float)y * (float)r;
    render->drawLine(cx, cy, cx + sx, cy + sy);

    area->x += area->w;
    area->y += area->h;
}

bool CompassWidget::canDrawInPage(const Renderer* render, Rect* area) const
{
    area->x += area->w;
    area->y += area->h;

    return true;
}

};
