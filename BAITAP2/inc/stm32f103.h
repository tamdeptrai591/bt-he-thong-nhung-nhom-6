#ifndef STM32F103_H
#define STM32F103_H

#include <stdint.h>

/* =====================================================
   RCC
   ===================================================== */

#define RCC_BASE        0x40021000UL

#define RCC_APB2ENR     (*(volatile uint32_t *)(RCC_BASE + 0x18))

/* GPIOA clock enable */
#define RCC_IOPAEN      (1U << 2)

/* GPIOC clock enable */
#define RCC_IOPCEN      (1U << 4)


/* =====================================================
   GPIOA
   ===================================================== */

#define GPIOA_BASE      0x40010800UL

#define GPIOA_CRL       (*(volatile uint32_t *)(GPIOA_BASE + 0x00))
#define GPIOA_CRH       (*(volatile uint32_t *)(GPIOA_BASE + 0x04))
#define GPIOA_IDR       (*(volatile uint32_t *)(GPIOA_BASE + 0x08))
#define GPIOA_ODR       (*(volatile uint32_t *)(GPIOA_BASE + 0x0C))


/* =====================================================
   GPIOC
   ===================================================== */

#define GPIOC_BASE      0x40011000UL

#define GPIOC_CRL       (*(volatile uint32_t *)(GPIOC_BASE + 0x00))
#define GPIOC_CRH       (*(volatile uint32_t *)(GPIOC_BASE + 0x04))
#define GPIOC_IDR       (*(volatile uint32_t *)(GPIOC_BASE + 0x08))
#define GPIOC_ODR       (*(volatile uint32_t *)(GPIOC_BASE + 0x0C))


/* =====================================================
   CPU NOP
   ===================================================== */

static inline void __NOP(void)
{
    __asm volatile ("nop");
}

#endif
