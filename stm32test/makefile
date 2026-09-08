# Tên project (sẽ tạo ra file firmware.bin)
TARGET = firmware

# Cấu hình công cụ biên dịch
CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
SZ = arm-none-eabi-size

# Kiến trúc chip
CPU = -mcpu=cortex-m3 -mthumb

# Tự động quét TẤT CẢ các file .c trong thư mục hiện tại
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

# Cờ biên dịch (-Wall để hiện mọi cảnh báo lỗi cú pháp)
CFLAGS = $(CPU) -Wall -O2 -c
LDFLAGS = $(CPU) -T stm32.ld -nostdlib -Wl,-Map=$(TARGET).map

# Lệnh mặc định chạy khi gõ 'make'
all: $(TARGET).bin size

# Quy tắc tạo file .bin
$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@

# Quy tắc tạo file .elf
$(TARGET).elf: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS)

# Quy tắc biên dịch mọi file .c thành .o
%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

# Hiển thị dung lượng RAM/Flash đã sử dụng
size: $(TARGET).elf
	$(SZ) $<

# Tự động nạp code vào mạch
flash: all
	st-flash write $(TARGET).bin 0x8000000

# Dọn dẹp project
clean:
	rm -f *.o *.elf *.bin *.map

.PHONY: all clean flash size
