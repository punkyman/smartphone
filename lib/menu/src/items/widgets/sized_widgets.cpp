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
    render->getTextSize(name, true, &namew, &nameh, NORMAL);
    const char* str = get();
    render->getTextSize(str, false, &textw, &texth, NORMAL);

    if(focused)
        render->fillRect(area->x0, area->y0,
        (textw > namew ? textw : namew) + (text_margin * 2),
        nameh + texth + 3 * text_spacing);

    area->y0 += text_margin;
    render->drawText(area->x0 + text_margin, area->y0, name, true, NORMAL);
    area->y0 += texth + text_spacing;

    render->drawText(area->x0 + text_margin,area->y0, str, false, NORMAL);
    area->y0 += texth;
}

bool DisplayTextWidget::canDrawInPage(const Renderer* render, Rect* area) const
{
    uint8_t namew, nameh, textw, texth;
    render->getTextSize(name, true, &namew, &nameh, NORMAL);
    const char* str = get();
    render->getTextSize(str, false, &textw, &texth, NORMAL);

    area->y0 += text_margin;
    area->y0 += texth + text_spacing;
    area->y0 += texth;    

    return area->y0 <= area->y1;
}

ModifyIntWidget::ModifyIntWidget(Page* parent, const __FlashStringHelper * name, GETINT get, SETINT set, int32_t minimum, int32_t maximum)
: Widget(parent, name), get(get), set(set), value(0), minimum(minimum), maximum(maximum), interacting(false)
{
}

bool ModifyIntWidget::update(Inputs inputs)
{
    if(!interacting)
    {
        value = get();
        if(inputs & INPUT_VALIDATE)
            interacting = true;
    }
    else
    {
        if(inputs & INPUT_VALIDATE)
        {
            set(value);
            interacting = false;
        }
        if(inputs & INPUT_BACK)
        {
            if(value > minimum)
                --value;
            else
                value = maximum;
        }
        if(inputs & INPUT_FORWARD)
        {
            if(value < maximum)
                ++value;
            else
                value = minimum;
        }
    }

    return interacting;
}

bool ModifyIntWidget::canDrawInPage(const Renderer* render, Rect* area) const
{
    uint8_t namew, nameh, textw, texth;
    render->getTextSize(name, true, &namew, &nameh, NORMAL);
    char str[16];
    snprintf(str, 16, "< %d >", (int) value);
    render->getTextSize(str, false, &textw, &texth, NORMAL);

    area->y0 += text_margin;
    area->y0 += texth + text_spacing;
    area->y0 += texth;    

    return area->y0 <= area->y1;
}

void ModifyIntWidget::drawInPage(Renderer* render, Rect* area)
{
    uint8_t namew, nameh, textw, texth;
    render->getTextSize(name, true, &namew, &nameh, NORMAL);
    char str[16];
    snprintf(str, 16, "< %d >", (int) value);
    render->getTextSize(str, false, &textw, &texth, NORMAL);

    if(interacting)
        render->drawRect(area->x0, area->y0,
        (textw > namew ? textw : namew) + (text_margin * 2),
        nameh + texth + 4 * text_spacing);
    else if(focused)
        render->fillRect(area->x0, area->y0,
        (textw > namew ? textw : namew) + (text_margin * 2),
        nameh + texth + 3 * text_spacing);

    area->y0 += text_margin;
    render->drawText(area->x0 + text_margin, area->y0, name, true, NORMAL);
    area->y0 += texth + text_spacing;

    render->drawText(area->x0 + text_margin,area->y0, str, false, NORMAL);
    area->y0 += texth;
}

};
