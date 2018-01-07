~/.platformio/packages/toolchain-atmelavr/bin/avr-nm -Crtd --size-sort .pioenvs/sparkfun_promicro16/firmware.elf | grep -i ' [dbv] ' > memory.usage
#~/.platformio/packages/toolchain-atmelavr/bin/avr-nm -Crtd --size-sort .pioenvs/sparkfun_promicro16/firmware.elf > memory.usage
