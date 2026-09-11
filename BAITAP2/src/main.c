#include <stdint.h>

#define RCC_APB2ENR   (*(volatile uint32_t *)0x40021018)
#define GPIOA_CRH     (*(volatile uint32_t *)0x40010804)
#define GPIOA_ODR     (*(volatile uint32_t *)0x4001080C)


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
    /* Bật clock cho GPIOA */
    RCC_APB2ENR |= (1U << 2);

    
    GPIOA_CRH = 0x22222222;

    while (1)
    {
        
        for (int i = 8; i <= 15; i++)
        {
            
            GPIOA_ODR &= ~(0xFFU << 8);
            GPIOA_ODR |= (1U << i);
            delay_ms(50);
        }

        for (int i = 14; i >= 8; i--)
        {
            GPIOA_ODR &= ~(0xFFU << 8);
            GPIOA_ODR |= (1U << i);
            delay_ms(50);
        }
    }
}
