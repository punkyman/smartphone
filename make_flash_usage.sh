~/.platformio/packages/toolchain-atmelavr/bin/avr-nm -Crtd --size-sort .pioenvs/smartphone/firmware.elf | grep -iv ' [b] ' > flash.usage
