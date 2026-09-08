#include <stdint.h>

// Định nghĩa địa chỉ các thanh ghi phần cứng của STM32F103C8T6
#define RCC_APB2ENR   (*((volatile uint32_t *)0x40021018)) // Thanh ghi cấp xung nhịp
#define GPIOC_CRH     (*((volatile uint32_t *)0x40011004)) // Thanh ghi cấu hình Port C (Chân 8-15)
#define GPIOC_ODR     (*((volatile uint32_t *)0x4001100C)) // Thanh ghi xuất dữ liệu Port C

// Hàm tạo thời gian trễ đơn giản
void delay(volatile uint32_t count) {
    while (count--) {
        // Trình biên dịch sẽ chạy vòng lặp này để làm chậm chip
    }
}

int main(void) {
    // 1. Bật xung nhịp cho Port C (Set bit thứ 4)
    RCC_APB2ENR |= (1 << 4);

    // 2. Cấu hình chân PC13 là Output, tốc độ 2MHz, chế độ Push-Pull
    // Xóa sạch 4 bit cấu hình của chân 13 (bit 20 đến 23)
    GPIOC_CRH &= ~(0xF << 20); 
    // Ghi giá trị 0x2 (0010) vào để thiết lập mode Output
    GPIOC_CRH |= (0x2 << 20);  

    // 3. Vòng lặp nháy LED
    while (1) {
        // Đảo ngược trạng thái của chân PC13 (Dùng phép XOR)
        // Lưu ý: LED trên mạch Blue Pill sáng khi chân PC13 ở mức THẤP (0)
        GPIOC_ODR ^= (1 << 13);
        
        // Gọi hàm trễ (Tăng giảm số này để thay đổi tốc độ nháy)
        delay(1000000); 
    }
}
