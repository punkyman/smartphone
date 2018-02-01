#include "modal.h"
#include "renderer.h"
#include "types.h"
#include "channel/channel.h"

namespace Menu
{

Modal::Modal()
: active(false)
{
    Channel::Register(this);
}

bool Modal::listener(Channel::Message msg)
{

}

bool Modal::update(Inputs inputs)
{
    return false;
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