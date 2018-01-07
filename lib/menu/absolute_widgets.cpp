#include "absolute_widgets.h"
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

const uint8_t PROGMEM signal_bitmap[SignalWidget::bw * SignalWidget::bh] = 
{
    0x92,
    0x54,
    0x38,
    0x10,
    0x10,
    0x10,
    0x10,
    0x10,
};

BatteryWidget::BatteryWidget(Page* parent, GETU8 getter)
: AbsoluteWidget(parent), get(getter)
{
}

void BatteryWidget::drawInPage(Renderer* render, Rect* area)
{
    uint8_t sx = area->x1 - w;
    render->drawBitmap(sx , area->y0, w, h, battery_bitmap);

    uint8_t level = get();
    uint8_t space = bar_w + bar_s;

    if(level >= BATTERY_BAR1)
    {
        render->fillRect(sx + 1 + bar_s, area->y0 + 1 + bar_s, bar_w, bar_h);
    }

    if(level >= BATTERY_BAR2)
    {
        render->fillRect(sx + 1 + bar_s + space, area->y0 + 1 + bar_s, bar_w, bar_h);
    }

    if(level >= BATTERY_BAR3)
    {
        render->fillRect(sx + 1 + bar_s + (space * 2), area->y0 + 1 + bar_s, bar_w, bar_h);
    }

    if(level >= BATTERY_BAR4)
    {
        render->fillRect(sx + 1 + bar_s + (space * 3), area->y0 + 1 + bar_s, bar_w, bar_h);
    }
}

SignalWidget::SignalWidget(Page* parent, GETU8 getter)
: AbsoluteWidget(parent), get(getter)
{
}

void SignalWidget::drawInPage(Renderer* render, Rect* area)
{
    render->drawBitmap(area->x0, area->y0, bw, bh, signal_bitmap);

    uint8_t level = get();
    uint8_t space = bar_w + bar_s;
    
    if(level >= SIGNAL_BAR1)
    {
        render->fillRect(area->x0 + 4 + bar_s, area->y0 + h - bar_h, bar_w, bar_h);
    }
    if(level >= SIGNAL_BAR2)
    {
        render->fillRect(area->x0 + 4 + bar_s + space, area->y0 + h - 2 * bar_h, bar_w, 2 * bar_h);
    }
    if(level >= SIGNAL_BAR3)
    {
        render->fillRect(area->x0 + 4 + bar_s +  2* space, area->y0 + h - 3 * bar_h, bar_w, 3 * bar_h);
    }
    if(level >= SIGNAL_BAR4)
    {
        render->fillRect(area->x0 + 4 + bar_s +  3* space, area->y0 + h - 4 * bar_h, bar_w, 4 * bar_h);
    }
}

ClockWidget::ClockWidget(Page* parent, GETSTR getclock, GETSTR getdate)
: AbsoluteWidget(parent), getclock(getclock), getdate(getdate)
{
}

void ClockWidget::drawInPage(Renderer* render, Rect* area)
{
    uint8_t textw, texth;
    const char* str = getclock();
    render->getTextSize(str, false, &textw, &texth, BIG);
    uint8_t x = area->x0 + ((area->x1 - area->x0) / 2) - (textw / 2);
    uint8_t y = area->y0 + ((area->y1 - area->y0) / 2) - (texth / 2);
    render->drawText(x, y, str, false, BIG);
    
    y += texth + space;
    str = getdate();
    render->getTextSize(str, false, &textw, &texth, NORMAL);
    x = area->x0 + ((area->x1 - area->x0) / 2) - (textw / 2);
    render->drawText(x, y, str, false, NORMAL);
}

CompassWidget::CompassWidget(Page* parent, GETCOMPASSDATA getter)
: AbsoluteWidget(parent), get(getter)
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

}; // namespace Menu