~/.platformio/packages/toolchain-atmelavr/bin/avr-nm -Crtd --size-sort .pioenvs/sparkfun_promicro16/firmware.elf | grep -iv ' [b] ' > flash.usage
