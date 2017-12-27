#include "mainpage_widgets.h"
#include "types.h"
#include "renderer.h"

namespace Menu
{

const uint8_t PROGMEM battery_bitmap[BatteryWidget::w * BatteryWidget::h] = 
{
    0xFF, 0xFE,
    0x80, 0x02,
    0x80, 0x03,
    0x80, 0x01,
    0x80, 0x01,
    0x80, 0x03,
    0x80, 0x02,
    0xFF, 0xFE,
};

BatteryWidget::BatteryWidget(Page* parent, GETU8 getter)
: Widget(parent, F("battery")), get(getter)
{
}

void BatteryWidget::drawInPage(Renderer* render, Rect* area)
{
    uint8_t sx = area->x1 - w;
    render->drawBitmap(sx , area->y0, w, h, battery_bitmap);

    uint8_t level = get();
    uint8_t space = bar_w + bar_s;

    if(level > BATTERY_BAR1)
    {
        render->fillRect(sx + 1 + bar_s, area->y0 + 1 + bar_s, bar_w, bar_h);
    }

    if(level > BATTERY_BAR2)
    {
        render->fillRect(sx + 1 + bar_s + space, area->y0 + 1 + bar_s, bar_w, bar_h);
    }

    if(level > BATTERY_BAR3)
    {
        render->fillRect(sx + 1 + bar_s + (space * 2), area->y0 + 1 + bar_s, bar_w, bar_h);
    }

    if(level > BATTERY_BAR4)
    {
        render->fillRect(sx + 1 + bar_s + (space * 3), area->y0 + 1 + bar_s, bar_w, bar_h);
    }
}

bool BatteryWidget::canDrawInPage(const Renderer* render, Rect* area) const
{
    return true; // widgets are absolute, no space computation
}

}; // namespace Menu