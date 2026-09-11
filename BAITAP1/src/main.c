#include <stdint.h>


#define RCC_APB2ENR (*(volatile uint32_t *)0x40021018)

#define GPIOC_CRH   (*(volatile uint32_t *)0x40011004)
#define GPIOC_ODR   (*(volatile uint32_t *)0x4001100C)


static void delay_ms(uint32_t ms)
{
    for (uint32_t i = 0; i < ms; i++)
    {
        for (volatile uint32_t j = 0; j < 8000; j++)
        {
            __asm volatile ("nop");
        }
    }
}


int main(void)
{
    /* 1. Bật clock cho GPIOC */
    RCC_APB2ENR |= (1U << 4);
    GPIOC_CRH &= ~(0xFU << 20);
    GPIOC_CRH |= (0x2U << 20);


    /* 3. PC13 = HIGH */
    GPIOC_ODR |= (1U << 13);


    while (1)
    {

        GPIOC_ODR &= ~(1U << 13);

        delay_ms(100);

    
        GPIOC_ODR |= (1U << 13);

        delay_ms(100);
    }
}
