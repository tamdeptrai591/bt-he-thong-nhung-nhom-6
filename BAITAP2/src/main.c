#include "stm32f103.h"

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

int main(void)
{

    GPIOA_CRH = 0x22222222;
    while (1)
    {
        
        for (int i = 8; i <= 15; i++)
        {
            GPIOA_ODR &= ~(0xFF << 8);
            GPIOA_ODR |= (1U << i);
            delay_ms(50);
        }

        for (int i = 14; i >= 8; i--)
        {
            GPIOA_ODR &= ~(0xFF << 8);
            GPIOA_ODR |= (1U << i);
            delay_ms(50);
        }
    }
}
