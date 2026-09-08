extern int main(void);

// RAM của STM32F103C8T6 bắt đầu ở 0x20000000, dài 20KB (0x5000)
// Đỉnh Stack sẽ nằm ở cuối RAM
#define STACK_TOP 0x20005000

// Hàm này chạy đầu tiên khi chip khởi động
void Reset_Handler(void) {
    main(); // Gọi hàm main của bạn
    while(1);
}

// Bảng vector ngắt tối giản đặt ở đầu bộ nhớ Flash
__attribute__((section(".isr_vector")))
void (*const vector_table[])(void) = {
    (void (*)(void))STACK_TOP,
    Reset_Handler
};
