#include "vertical_widgets.h"
#include "types.h"
#include "renderer.h"

namespace Menu
{

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
        render->fillRect(area->x0, area->y0,
        (textw > namew ? textw : namew) + (text_margin * 2),
        nameh + texth + 3 * text_spacing);

    area->y0 += text_margin;
    render->drawTextFSH(area->x0 + text_margin, area->y0, name);
    area->y0 += texth + text_spacing;

    render->drawTextChar(area->x0 + text_margin,area->y0, str);
    area->y0 += texth;
}

bool DisplayTextWidget::canDrawInPage(const Renderer* render, Rect* area) const
{
    uint8_t namew, nameh, textw, texth;
    render->getTextSizeFSH(name, &namew, &nameh);
    const char* str = get();
    render->getTextSizeChar(str, &textw, &texth);

    area->y0 += text_margin;
    area->y0 += texth + text_spacing;
    area->y0 += texth;    

    return area->y0 <= area->y1;
}


CompassWidget::CompassWidget(Page* parent, GETCOMPASSDATA getter)
: Widget(parent, F("compass")), get(getter)
{

}

void CompassWidget::drawInPage(Renderer* render, Rect* area)
{
    uint8_t cx = area->x0 + ((area->x1 - area->x0) / 2);
    uint8_t cy = area->y0 + ((area->y1 - area->y0) / 2);
    uint8_t r = ((area->y1 -area->y0) / 2) - circle_margin;
    render->drawCircle(cx, cy, r);

    float x, y;
    get(&x, &y);
    int16_t sx = (float)x * (float)r;
    int16_t sy = (float)y * (float)r;
    render->drawLine(cx, cy, cx + sx, cy + sy);

    area->x0 = area->x1;
    area->y0 += area->y1;
}

bool CompassWidget::canDrawInPage(const Renderer* render, Rect* area) const
{
    area->x0 = area->x1;
    area->y0 += area->y1;

    return true;
}

};
