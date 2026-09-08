#ifndef STM32F103_H
#define STM32F103_H

#include <stdint.h>

/* =====================================================
   RCC
   ===================================================== */

#define RCC_BASE        0x40021000UL

#define RCC_APB2ENR     (*(volatile uint32_t *)(RCC_BASE + 0x18))

/* GPIOC clock enable - bit 4 */
#define RCC_IOPCEN      (1U << 4)


/* =====================================================
   GPIOC
   ===================================================== */

#define GPIOC_BASE      0x40011000UL

/* Control Register Low */
#define GPIOC_CRL       (*(volatile uint32_t *)(GPIOC_BASE + 0x00))

/* Control Register High */
#define GPIOC_CRH       (*(volatile uint32_t *)(GPIOC_BASE + 0x04))

/* Input Data Register */
#define GPIOC_IDR       (*(volatile uint32_t *)(GPIOC_BASE + 0x08))

/* Output Data Register */
#define GPIOC_ODR       (*(volatile uint32_t *)(GPIOC_BASE + 0x0C))


/* =====================================================
   CPU NOP
   ===================================================== */

static inline void __NOP(void)
{
    __asm volatile ("nop");
}

#endif
