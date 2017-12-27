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
    render->drawBitmap(area->x1 - w, area->y0, w, h, battery_bitmap);
}

bool BatteryWidget::canDrawInPage(const Renderer* render, Rect* area) const
{
    return true; // widgets are absolute, no space computation
}

}; // namespace Menu