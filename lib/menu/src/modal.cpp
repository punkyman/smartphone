#include "modal.h"
#include "renderer.h"
#include "types.h"
#include <messaging.h>
#include "messages.h"

namespace Menu
{

Modal::Modal()
: active(false)
{
    Messaging::Register(this);
}

bool Modal::listener(uint8_t msg)
{
    switch(msg)
    {
        case Messages::MSG_OPERATION_FAILURE:
        case Messages::MSG_OPERATION_IN_PROGRESS:
        case Messages::MSG_OPERATION_SUCCESS:
            active = true;
    }
}

bool Modal::update(Inputs inputs)
{
    if(!active)
        return false;
    else
    {
        if(inputs & INPUT_VALIDATE)
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
    }
}
}