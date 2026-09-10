#include "stm32f103.h"

/* =====================================================
   Delay
   ===================================================== */

static void delay_ms(uint32_t ms)
{
    for (uint32_t i = 0; i < ms; i++)
    {
        for (volatile uint32_t j = 0; j < 8000; j++)
        {
            __NOP();
        }
    }
}


/* =====================================================
   MAIN
   ===================================================== */

int main(void)
{
    /* Enable clock GPIOA */
    RCC_APB2ENR |= RCC_IOPAEN;

    /*
       PA8 -> PA15:
       Output Push-Pull
       Maximum speed 2 MHz

       MODE = 10
       CNF  = 00

       => 0010 = 0x2
    */

    GPIOA_CRH = 0x22222222;

    /* Tắt tất cả LED PA8 -> PA15 */
    GPIOA_ODR &= ~(0xFF << 8);

    while (1)
    {
        /* =============================================
           Chạy từ trái sang phải
           PA8 -> PA15
           ============================================= */

        for (int i = 8; i <= 15; i++)
        {
            /* Tắt tất cả LED */
            GPIOA_ODR &= ~(0xFF << 8);

            /* Bật LED thứ i */
            GPIOA_ODR |= (1U << i);

            delay_ms(50);
        }


        /* =============================================
           Chạy từ phải sang trái
           PA14 -> PA8

           Không bật PA15 lần nữa vì PA15 vừa được bật
           ở vòng trên.
           ============================================= */

        for (int i = 14; i >= 8; i--)
        {
            /* Tắt tất cả LED */
            GPIOA_ODR &= ~(0xFF << 8);

            /* Bật LED thứ i */
            GPIOA_ODR |= (1U << i);

            delay_ms(50);
        }
    }
}