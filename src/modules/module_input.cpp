#include "module_input.h"
#include "hardware_config.h"

#if defined(HARDWARE_USE_JOYSTICK)
#include <joystick.h>
#endif

#if defined(HARDWARE_USE_ENCODER)
#include <encoder.h>
#endif

namespace ModuleInput
{

Inputs::Inputs()
: scrolls(0), up(false), down(false), left(false), right(false), validate(false)
, pressed_up(false), pressed_down(false), pressed_left(false), pressed_right(false), pressed_validate(false)
, released_up(false), released_down(false), released_left(false), released_right(false), released_validate(false)
{
}

Inputs inputs;

const Inputs* getInputs()
{
    return &inputs;
}

void setup()
{
#if defined(HARDWARE_USE_JOYSTICK)
joystick_init(JOYSTICK_ANALOG_X, JOYSTICK_ANALOG_Y, JOYSTICK_DIGITAL_SWITCH);
#endif

#if defined(HARDWARE_USE_ENCODER)
encoder_init(ENCODER_DIGITAL_CLOCK, ENCODER_DIGITAL_DATA, ENCODER_DIGITAL_SWITCH);
#endif
}

void update()
{
    bool previous_down = inputs.down;
    bool previous_up = inputs.up;
    bool previous_left = inputs.left;
    bool previous_right = inputs.right;
    bool previous_validate = inputs.validate;

    inputs.down = false;
    inputs.up = false;
    inputs.left = false;
    inputs.right = false;
    inputs.validate = false;
    inputs.scrolls = 0;

#if defined(HARDWARE_USE_JOYSTICK)
    joystick_read_values();
    inputs.down |= joystick_analog_Y < (ANALOG_CENTER - analog_treshold);
    inputs.up |= joystick_analog_Y > (ANALOG_CENTER + analog_treshold);
    inputs.left |= joystick_analog_X < (ANALOG_CENTER -analog_treshold);
    inputs.right |= joystick_analog_X > (ANALOG_CENTER + analog_treshold);
    inputs.validate |= joystick_switch;
    inputs.scrolls += inputs.down ? 1 : 0;
    inputs.scrolls += inputs.up ? -1 : 0;
#endif
#if defined(HARDWARE_USE_ENCODER)
    encoder_read_values();
    inputs.down |= (encoder_scrolls < 0);
    inputs.up |= (encoder_scrolls > 0);
    inputs.validate |= encoder_switch;
    inputs.scrolls += encoder_scrolls;
    encoder_clear_readings();
#endif
    
    inputs.pressed_down = (!previous_down && inputs.down);
    inputs.pressed_up = (!previous_up && inputs.up);
    inputs.pressed_left = (!previous_left && inputs.left);
    inputs.pressed_right = (!previous_right && inputs.right);
    inputs.pressed_validate = (!previous_validate && inputs.validate);

    inputs.released_down = (!inputs.down && previous_down);
    inputs.released_up = (!inputs.up && previous_up);
    inputs.released_left = (!inputs.left && previous_left);
    inputs.released_right = (!inputs.right && previous_right);
    inputs.released_validate = (!inputs.validate && previous_validate);
}

}; //namespace ModuleInput