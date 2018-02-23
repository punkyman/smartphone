~/.platformio/packages/toolchain-atmelavr/bin/avr-nm -Crtd --size-sort .pioenvs/smartphone/firmware.elf | grep -i ' [dbv] ' > memory.usage
#~/.platformio/packages/toolchain-atmelavr/bin/avr-nm -Crtd --size-sort .pioenvs/smartphone/firmware.elf > memory.usage
