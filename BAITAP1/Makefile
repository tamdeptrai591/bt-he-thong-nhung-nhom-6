TARGET = pro

CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
SIZE = arm-none-eabi-size

CFLAGS = -mcpu=cortex-m3 \
         -mthumb \
         -O0 \
         -Wall \
         -ffreestanding \
         -Iinc

LDFLAGS = -Tstm32f103c8.ld \
          -nostdlib \
          -Wl,--gc-sections


all: build


build: pro.elf pro.bin


pro.elf: src/main.c src/startup.s
	mkdir -p build

	$(CC) $(CFLAGS) -c src/main.c -o build/main.o

	$(CC) $(CFLAGS) -c src/startup.s -o build/startup.o

	$(CC) $(CFLAGS) $(LDFLAGS) \
		build/main.o \
		build/startup.o \
		-o pro.elf

	$(SIZE) pro.elf


pro.bin: pro.elf
	$(OBJCOPY) -O binary pro.elf pro.bin


clean:
	rm -rf build
	rm -f pro.elf
	rm -f pro.bin


flash: pro.elf
	STM32_Programmer_CLI -c port=SWD -w pro.elf -rst


.PHONY: all build clean flash
