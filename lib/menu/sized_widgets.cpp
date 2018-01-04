#include "sized_widgets.h"
#include "types.h"
#include "renderer.h"

namespace Menu
{

DisplayTextWidget::DisplayTextWidget(Page* parent, const __FlashStringHelper* name, GETSTR getter)
: DisplayWidget(parent, name), get(getter)
{
}

void DisplayTextWidget::drawInPage(Renderer* render, Rect* area)
{
    uint8_t namew, nameh, textw, texth;
    render->getTextSizeFSH(name, &namew, &nameh, NORMAL);
    const char* str = get();
    render->getTextSizeChar(str, &textw, &texth, NORMAL);

    if(focused)
        render->fillRect(area->x0, area->y0,
        (textw > namew ? textw : namew) + (text_margin * 2),
        nameh + texth + 3 * text_spacing);

    area->y0 += text_margin;
    render->drawTextFSH(area->x0 + text_margin, area->y0, name, NORMAL);
    area->y0 += texth + text_spacing;

    render->drawTextChar(area->x0 + text_margin,area->y0, str, NORMAL);
    area->y0 += texth;
}

bool DisplayTextWidget::canDrawInPage(const Renderer* render, Rect* area) const
{
    uint8_t namew, nameh, textw, texth;
    render->getTextSizeFSH(name, &namew, &nameh, NORMAL);
    const char* str = get();
    render->getTextSizeChar(str, &textw, &texth, NORMAL);

    area->y0 += text_margin;
    area->y0 += texth + text_spacing;
    area->y0 += texth;    

    return area->y0 <= area->y1;
}

};
