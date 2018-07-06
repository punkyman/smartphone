#include "modal.h"
#include <hal.h>
#include "renderer.h"
#include "types.h"
#include <messaging.h>
#include "messages.h"

namespace Menu
{

Modal::Modal()
: active(false), style((Style)0)
{
    Messaging::Register(this, Messages::Channel);
}

bool Modal::listener(uint8_t msg)
{
    switch(msg)
    {
        case Messages::MSG_MODAL_SHOW_FAILURE:
            style = STYLE_FAILURE;
            active = true;
            return true;
        case Messages::MSG_MODAL_SHOW_IN_PROGRESS:
            style = STYLE_IN_PROGRESS;
            active = true;
            return true;
        case Messages::MSG_MODAL_SHOW_SUCCESS:
            style = STYLE_SUCCESS;
            active = true;
            return true;
    }

    return false;
}

bool Modal::update(const Inputs& inputs)
{
    if(!active)
        return false;
    else
    {
        if(style != STYLE_IN_PROGRESS)
            if(inputs.Navigation & INPUT_VALIDATE)
                active = false;

        return true;
    }
}

void Modal::draw(Renderer* render)
{
    if(active)
    {
        Rect frame(screen_margin, screen_margin, render->screenWidth - screen_margin, render->screenHeight - screen_margin);
        render->eraseRect(frame.x0, frame.y0, frame.x1 - frame.x0, frame.y1 - frame.y0);
        render->drawRect(frame.x0, frame.y0, frame.x1 - frame.x0, frame.y1 - frame.y0);

        const char* text = nullptr;
        bool ok_button = false;
        switch(style)
        {
            case STYLE_SUCCESS :
                text = PSTR("Operation\n    complete !");
                ok_button = true;
                break;
            case STYLE_IN_PROGRESS :
                text = PSTR("Operation\n in progress");
                break;
            case STYLE_FAILURE :
                text = PSTR("Operation\n    failed");
                ok_button = true;
                break;
        }

        uint8_t textw, texth;
        render->getTextSize(text, true, &textw, &texth, NORMAL);
        uint8_t x = frame.x0 + ((frame.x1 - frame.x0) / 2) - (textw / 2);
        uint8_t y = frame.y0 + ((frame.y1 - frame.y0) / 2) - (texth / 2);
        render->drawText(x, y, text, true, NORMAL);

        if(ok_button)
        {
            text = PSTR("OK");
            render->getTextSize(text, true, &textw, &texth, NORMAL);
            x = frame.x0 + ((frame.x1 - frame.x0) / 2) - (textw / 2);
            y = frame.y1 - texth - box_margin;
            render->fillRect(x - box_margin, y - box_margin, textw + 2*box_margin, texth + 2*box_margin);
            render->drawText(x, y, text, true, NORMAL);
        }
    }
}
}