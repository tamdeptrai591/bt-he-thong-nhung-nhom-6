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

    RCC_APB2ENR |= RCC_IOPCEN;

    GPIOC_CRH &= ~(0xFU << 20);
    GPIOC_CRH |= (0x2U << 20);
    GPIOC_ODR |= (1U << 1);
    while (1)
    {
   
        GPIOC_ODR &= ~(1U << 13);

        delay_ms(1000);

        GPIOC_ODR |= (1U << 13);
        delay_ms(1000);
    }
}
